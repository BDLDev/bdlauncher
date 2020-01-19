#pragma once

#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

namespace ws {

using byte = unsigned char;

enum class FrameType : byte {
  EMPTY_FRAME      = 0xF0,
  ERROR_FRAME      = 0xF1,
  INCOMPLETE_FRAME = 0xF2,
  TEXT_FRAME       = 0x01,
  BINARY_FRAME     = 0x02,
  PING_FRAME       = 0x09,
  PONG_FRAME       = 0x0A,
  OPENING_FRAME    = 0xF3,
  CLOSING_FRAME    = 0x08,
};

enum class State {
  STATE_OPENING,
  STATE_NORMAL,
  STATE_CLOSING,
};

struct Input;
struct Output;

template <typename io> using Data = std::conditional_t<std::is_same_v<io, Input>, std::string_view, std::string>;

struct Handshake {
  FrameType type;
  Data<Input> host;
  Data<Input> origin;
  Data<Input> key;
  Data<Input> resource;
  std::vector<Data<Input>> protocols;

  inline void reset() {
    host = origin = key = resource = {};
    std::vector<Data<Input>> empty;
    protocols.swap(empty);
  }
};

template <typename io = Output> struct Frame {
  FrameType type;
  uint64_t eaten;
  Data<io> payload;

  inline Frame() = default;

  inline Frame(FrameType type) : type(type) {}

  inline Frame(FrameType type, Data<io> const &payload) : type(type), payload(payload) {}
  inline Frame(FrameType type, uint64_t eaten, Data<io> const &payload) : type(type), eaten(eaten), payload(payload) {}
};

template <typename T> struct network_number {
  T raw;
  network_number() noexcept : raw(0) {}
  network_number(T value) noexcept;
  network_number &operator=(T value) noexcept;
  bool operator==(T rhs) const noexcept { return static_cast<T>(*this) == rhs; }
  bool operator==(network_number rhs) const noexcept { return raw == rhs.raw; }
  bool operator!=(T rhs) const noexcept { return static_cast<T>(*this) != rhs; }
  bool operator!=(network_number rhs) const noexcept { return raw != rhs.raw; }
  operator bool() const noexcept { return raw != 0; }
  operator T() const noexcept;
  T get() const noexcept { return *this; }
};

template <typename T> std::ostream &operator<<(std::ostream &stream, network_number<T> const &t) {
  char buffer[sizeof(T)];
  memcpy(buffer, &t, sizeof(T));
  stream.write(buffer, sizeof(T));
  return stream;
}

struct ws_pack {
  uint8_t opcode : 4;
  uint8_t rsv : 3;
  bool fin : 1;
  uint8_t payloadLength : 7;
  bool mask : 1;
} __attribute__((packed));

struct ws_header : ws_pack {
  union {
    network_number<uint16_t> payloadLength16b;
    network_number<uint64_t> payloadLength64b;
  };

  unsigned char extra() const {
    switch (payloadLength) {
    case 126: return 1;
    case 127: return 2;
    default: return 0;
    }
  }
};

std::ostream &operator<<(std::ostream &stream, ws_header const &);

std::ostream &operator<<(std::ostream &stream, Handshake const &frame);

Handshake parseHandshake(Data<Input> input);

inline Data<Output> makeHandshake(Handshake handshake) {
  std::ostringstream oss;
  oss << handshake;
  return oss.str();
}

Data<Output> makeHandshakeAnswer(Data<Input> key, Data<Input> protocol = {});
Data<Input> parseHandshakeAnswer(Data<Input> input, Data<Input> key);

Frame<Output> parseFrame(Data<Input>);
Frame<Input> parseServerFrame(Data<Input>);
Data<Output> makeFrame(Frame<Input> frame, bool mask = false);

} // namespace ws