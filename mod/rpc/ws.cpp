#include <arpa/inet.h>
#include <cstdio>
#include <cstring>
#include <experimental/iterator>
#include <experimental/random>
#include <iostream>
#include <sstream>
#include <tuple>

#include "sha1.h"
#include "ws.hpp"

static constexpr auto rn       = "\r\n";
static constexpr char secret[] = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";

uint64_t ntohll(uint64_t val) { return (((uint64_t) ntohl(val)) << 32) + ntohl(val >> 32); }

uint64_t htonll(uint64_t val) { return (((uint64_t) htonl(val)) << 32) + htonl(val >> 32); }

std::vector<std::string_view> split(std::string_view inp) {
  std::vector<std::string_view> output;
  size_t n = std::string_view::npos;
  while (!inp.empty()) {
    n = inp.find_first_not_of(" ");
    if (n == std::string_view::npos) break;
    inp.remove_prefix(n);
    n = inp.find_first_of(",");
    if (n == std::string_view::npos) break;
    output.emplace_back(inp.substr(0, n));
    inp.remove_prefix(n);
  }
  return output;
}

namespace ws {

inline size_t base64len(size_t n) { return (n + 2) / 3 * 4; }

Data<Output> base64(Data<Input> input) {
  constexpr char t[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  std::string out;

  int val = 0, valb = -6;
  for (unsigned char c : input) {
    val = (val << 8) + c;
    valb += 8;
    while (valb >= 0) {
      out.push_back(t[(val >> valb) & 0x3F]);
      valb -= 6;
    }
  }
  if (valb > -6) out.push_back(t[((val << 8) >> (valb + 8)) & 0x3F]);
  while (out.size() % 4) out.push_back('=');
  return out;
}

std::string_view eat(std::string_view &full, std::size_t length) {
  auto ret = full.substr(0, length);
  full.remove_prefix(length);
  return ret;
}

bool starts_with(std::string_view &full, std::string_view part) {
  bool res = full.compare(0, part.length(), part) == 0;
  if (res) full.remove_prefix(part.length());
  return res;
}

Handshake parseHandshake(Data<Input> input) {
  Handshake result{FrameType::OPENING_FRAME};
  auto ending = input.rfind("\r\n\r\n");
  if (ending == std::string_view::npos) return {FrameType::INCOMPLETE_FRAME};
  input.remove_suffix(input.length() - ending - 2);
  if (!starts_with(input, "GET ") != 0) return {FrameType::ERROR_FRAME};
  auto res_end = input.find(' ');
  if (res_end == std::string_view::npos) return {FrameType::INCOMPLETE_FRAME};
  result.resource = eat(input, res_end);
  if (!starts_with(input, " HTTP/1.1\r\n")) return {FrameType::ERROR_FRAME};

  bool connectionFlag = false;
  bool upgradeFlag    = false;
  while (input.length() != 0) {
    auto end = input.find("\r\n");
    if (end == std::string_view::npos) return {FrameType::ERROR_FRAME};
    auto line = eat(input, end);
    input.remove_prefix(2);

    if (starts_with(line, "Host: ")) {
      result.host = line;
    } else if (starts_with(line, "Origin: ")) {
      result.origin = line;
    } else if (starts_with(line, "Sec-WebSocket-Protocol: ")) {
      result.protocols = split(line);
    } else if (starts_with(line, "Sec-WebSocket-Key: ")) {
      result.key = line;
    } else if (starts_with(line, "Sec-WebSocket-Version: ")) {
      auto version = line;
      if (version != "13") return {FrameType::ERROR_FRAME};
    } else if (starts_with(line, "Connection: ")) {
      if (line == "Upgrade")
        upgradeFlag = true;
      else
        return {FrameType::ERROR_FRAME};
    } else if (starts_with(line, "Upgrade: ")) {
      if (line == "websocket")
        connectionFlag = true;
      else
        return {FrameType::ERROR_FRAME};
    }
  }
  if (!connectionFlag || !upgradeFlag) return {FrameType::ERROR_FRAME};
  return result;
}

std::ostream &operator<<(std::ostream &oss, Handshake const &handshake) {
  oss << "GET " << handshake.resource << " HTTP/1.1" << rn;
  oss << "Host: " << handshake.host << rn;
  oss << "Origin: " << handshake.origin << rn;
  oss << "Connection: Upgrade" << rn;
  oss << "Upgrade: websocket" << rn;
  oss << "Sec-WebSocket-Version: 13" << rn;
  oss << "Sec-WebSocket-Key: " << handshake.key << rn;
  if (!handshake.protocols.empty()) {
    oss << "Sec-WebSocket-Protocol: ";
    std::copy(
        handshake.protocols.begin(), handshake.protocols.end(), std::experimental::make_ostream_joiner(oss, ", "));
    oss << rn;
  }
  oss << rn;
  return oss;
}

Data<Output> makeHandshakeAnswer(Data<Input> key, Data<Input> protocol) {
  std::ostringstream oss;
  byte hash[20] = {0};
  SHA1_CTX ctx;
  SHA1Init(&ctx);
  SHA1Update(&ctx, (byte const *) &key[0], key.length());
  SHA1Update(&ctx, (byte const *) secret, 36);
  SHA1Final(hash, &ctx);
  auto reskey = base64(std::string_view{(char const *) hash, 20});
  oss << "HTTP/1.1 101 Switching Protocols" << rn;
  oss << "Upgrade: websocket" << rn;
  oss << "Connection: Upgrade" << rn;
  oss << "Sec-WebSocket-Accept: " << reskey << rn;
  if (!protocol.empty()) oss << "Sec-Websocket-Protocol: " << protocol << rn;
  oss << rn;
  return oss.str();
}

Data<Input> parseHandshakeAnswer(Data<Input> input, Data<Input> key) {
  auto ending = input.rfind("\r\n\r\n");
  if (ending == std::string_view::npos) return "";
  input.remove_suffix(input.length() - ending - 2);
  byte hash[20] = {0};
  SHA1_CTX ctx;
  SHA1Init(&ctx);
  SHA1Update(&ctx, (byte const *) &key[0], key.length());
  SHA1Update(&ctx, (byte const *) secret, 36);
  SHA1Final(hash, &ctx);
  auto reskey = base64(std::string_view{(char const *) hash, 20});
  if (!starts_with(input, "HTTP/1.1 101") != 0) return "";
  input.remove_prefix(input.find(rn) + 2);

  bool upgrade              = false;
  bool connection           = false;
  std::string_view protocol = "";
  while (input.length() != 0) {
    auto end = input.find(rn);
    if (end == std::string_view::npos) return "";
    auto line = eat(input, end);
    input.remove_prefix(2);

    if (starts_with(line, "Upgrade: ")) {
      if (line != "websocket") return "";
      upgrade = true;
    } else if (starts_with(line, "Connection: ")) {
      if (line != "Upgrade") return "";
      connection = true;
    } else if (starts_with(line, "Sec-WebSocket-Accept: ")) {
      if (line != reskey) return "";
      connection = true;
    } else if (starts_with(line, "Sec-Websocket-Protocol: ")) {
      protocol = line;
    }
  }
  if (!upgrade || !connection) return "";
  if (protocol.empty()) return "websocket";
  return protocol;
}

template <typename T> network_number<T>::network_number(T value) noexcept {
  if constexpr (std::is_same_v<T, uint16_t>) {
    raw = htons(value);
  } else if constexpr (std::is_same_v<T, uint64_t>) {
    raw = htonll(value);
  } else {
    static_assert(std::is_same_v<T, uint16_t> || std::is_same_v<T, uint64_t>);
  }
}

template <typename T> network_number<T> &network_number<T>::operator=(T value) noexcept {
  if constexpr (std::is_same_v<T, uint16_t>) {
    raw = htons(value);
  } else if constexpr (std::is_same_v<T, uint64_t>) {
    raw = htonll(value);
  } else {
    static_assert(std::is_same_v<T, uint16_t> || std::is_same_v<T, uint64_t>);
  }
  return *this;
}

template <typename T> network_number<T>::operator T() const noexcept {
  if constexpr (std::is_same_v<T, uint16_t>) {
    return ntohs(raw);
  } else if constexpr (std::is_same_v<T, uint64_t>) {
    return ntohll(raw);
  } else {
    static_assert(std::is_same_v<T, uint16_t> || std::is_same_v<T, uint64_t>);
  }
}

std::ostream &operator<<(std::ostream &stream, ws_header const &header) {
  char buffer[2];
  memcpy(buffer, &header, 2);
  stream.write(buffer, 2);
  switch (header.extra()) {
  case 1: stream << header.payloadLength16b; break;
  case 2: stream << header.payloadLength64b; break;
  }
  return stream;
}

std::tuple<uint64_t, char, FrameType> getPayloadLength(Data<Input> input, ws_header &header) {
  uint64_t payloadLength = header.payloadLength;
  char extraBytes        = 0;
  if ((payloadLength == 0x7f && input.length() < 4) || (payloadLength == 0x7F && input.length() < 10))
    return {0, 0, FrameType::INCOMPLETE_FRAME};
  if (payloadLength == 0x7f && (input[3] & 0x80) != 0) { return {0, 0, FrameType::ERROR_FRAME}; }
  if (payloadLength == 0x7e) {
    network_number<uint16_t> payloadLength16b = 0;
    extraBytes                                = 2;
    memcpy(&payloadLength16b, &input[2], extraBytes);
    payloadLength = payloadLength16b.get();
  } else if (payloadLength == 0x7F) {
    network_number<uint64_t> payloadLength64b = 0;
    extraBytes                                = 8;
    memcpy(&payloadLength64b, &input[2], extraBytes);
    payloadLength = payloadLength64b.get();
  }
  return {payloadLength, extraBytes, (FrameType) header.opcode};
}

Frame<Output> parseFrame(Data<Input> input) {
  if (input.length() < 2) return {FrameType::INCOMPLETE_FRAME};
  ws_header header{};
  memcpy(&header, &input[0], 2);
  if (!header.fin || header.rsv != 0 || !header.mask) return {FrameType::ERROR_FRAME};
  auto [payloadLength, extraBytes, opcode] = getPayloadLength(input, header);
  if (opcode == FrameType::TEXT_FRAME || opcode == FrameType::BINARY_FRAME || opcode == FrameType::CLOSING_FRAME ||
      opcode == FrameType::PING_FRAME || opcode == FrameType::PONG_FRAME) {
    if (payloadLength + 6 + extraBytes > input.length()) return {FrameType::INCOMPLETE_FRAME};
    auto masking = input.substr(2 + extraBytes, 4);
    Frame<Output> frame{opcode, payloadLength + 6 + extraBytes,
                        std::string(input.substr(2 + extraBytes + 4, payloadLength))};
    for (size_t i = 0; i < payloadLength; i++) frame.payload[i] ^= masking[i % 4];
    return frame;
  }
  return {opcode};
}

Frame<Input> parseServerFrame(Data<Input> input) {
  if (input.length() < 2) return {FrameType::INCOMPLETE_FRAME};
  ws_header header{};
  memcpy(&header, &input[0], 2);
  if (!header.fin || header.rsv != 0 || header.mask) return {FrameType::ERROR_FRAME};
  auto [payloadLength, extraBytes, opcode] = getPayloadLength(input, header);
  if (opcode == FrameType::TEXT_FRAME || opcode == FrameType::BINARY_FRAME || opcode == FrameType::CLOSING_FRAME ||
      opcode == FrameType::PING_FRAME || opcode == FrameType::PONG_FRAME) {
    if (payloadLength + 2 + extraBytes > input.length()) return {FrameType::INCOMPLETE_FRAME};
    Frame<Input> frame{opcode, payloadLength + 2 + extraBytes, input.substr(2 + extraBytes, payloadLength)};
    return frame;
  }
  return {opcode};
}

ws_header makeFrameHeader(Frame<Input> frame, bool mask) {
  ws_header header{{
      .opcode = (uint8_t) frame.type,
      .rsv    = 0,
      .fin    = true,
      .mask   = mask,
  }};
  const auto dataLength = frame.payload.length();
  if (dataLength < 0x7e) {
    header.payloadLength = dataLength;
  } else if (dataLength <= 0xFFFF) {
    header.payloadLength    = 0x7e;
    header.payloadLength16b = dataLength;
  } else {
    header.payloadLength    = 0x7f;
    header.payloadLength64b = dataLength;
  }
  return header;
}

Data<Output> makeFrame(Frame<Input> frame, bool mask) {
  std::ostringstream oss;
  oss << makeFrameHeader(frame, mask);
  if (mask) {
    auto mask = std::experimental::randint(0u, UINT32_MAX);
    char maskbuf[4];
    memcpy(maskbuf, &mask, 4);
    oss.write(maskbuf, 4);
    size_t i = 0;
    for (auto ch : frame.payload) {
      char temp = ch ^ maskbuf[i++ % 4];
      oss.write(&temp, 1);
    }
  } else {
    oss << frame.payload;
  }
  return oss.str();
}

} // namespace ws
