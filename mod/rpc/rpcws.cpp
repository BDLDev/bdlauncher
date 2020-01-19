#include <experimental/random>
#include <netdb.h>
#include <sstream>
#include <cassert>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include "rpcws.hpp"

namespace rpcws {

Buffer::Buffer() {}

char *Buffer::allocate(size_t size) {
  if (start) {
    if (static_cast<size_t>(allocated - head) < size) {
      auto temp       = new char[allocated - start + size];
      auto nstart     = temp;
      auto nend       = temp + (head - start);
      auto nallocated = temp + (allocated - start) + size;
      delete[] start;
      start     = nstart;
      head      = nend;
      allocated = nallocated;
    }
  } else {
    start     = new char[size];
    head      = start;
    allocated = start + size;
  }
  return head;
}

void Buffer::eat(size_t size) { head += size; }

void Buffer::drop(size_t size) {
  if (!size) return;
  if (size == static_cast<size_t>(head - start)) {
    head = start;
  } else {
    head -= size;
    memmove(start, start + size, head - start);
  }
}

void Buffer::reset() {
  delete[] start;
  start = head = allocated = nullptr;
}

char *Buffer::begin() const { return start; }

char *Buffer::end() const { return head; }

size_t Buffer::length() const { return head - start; }

std::string_view Buffer::view() const { return {start, length()}; }

Buffer::operator std::string_view() const { return view(); }

Buffer::~Buffer() { delete[] start; }

InvalidAddress::InvalidAddress() : std::runtime_error("invalid address") {}

InvalidSocketOp::InvalidSocketOp(char const *msg) : std::runtime_error(std::string(msg) + ": " + strerror(errno)) {}

CommonException::CommonException() : std::runtime_error(strerror(errno)) {}

HandshakeFailed::HandshakeFailed() : std::runtime_error("handshake failed") {}

InvalidFrame::InvalidFrame() : std::runtime_error("invalid frame") {}

void safeSend(int fd, std::string_view data) {
  while (!data.empty()) {
    auto sent = send(fd, &data[0], data.size(), MSG_NOSIGNAL);
    if (sent == -1 || sent == 0) throw SendFailed();
    data.remove_prefix(sent);
  }
}

bool starts_with(std::string_view &full, std::string_view part) {
  bool res = full.compare(0, part.length(), part) == 0;
  if (res) full.remove_prefix(part.length());
  return res;
}

std::string_view eat(std::string_view &full, std::size_t length) {
  auto ret = full.substr(0, length);
  full.remove_prefix(length);
  return ret;
}

server_wsio::server_wsio(std::string_view address, std::shared_ptr<epoll> ep) : ep(std::move(ep)) {
  if (starts_with(address, "ws://")) {
    auto end = address.find_first_of("[:/");
    if (end == std::string_view::npos) throw InvalidAddress();
    bool quoted = false;
    if (address[end] == '[') {
      quoted = true;
      end    = address.find(']');
      if (end == std::string_view::npos) throw InvalidAddress();
      end++;
    }
    auto host = eat(address, end);
    if (quoted) {
      host.remove_prefix(1);
      host.remove_suffix(1);
    }
    std::string_view port = "80";
    if (address[0] == ':') {
      address.remove_prefix(1);
      end = address.find('/');
      if (end == std::string_view::npos) throw InvalidAddress();
      port = eat(address, end);
    }
    path = eat(address, address.find_first_of("?#"));
    {
      std::string host_str{host};
      std::string port_str{port};
      addrinfo hints = {
          .ai_flags    = AI_PASSIVE,
          .ai_family   = AF_UNSPEC,
          .ai_socktype = SOCK_STREAM,
      };
      addrinfo *list;
      auto ret = getaddrinfo(host_str.c_str(), port_str.c_str(), &hints, &list);
      if (ret != 0) throw InvalidAddress();
      fd               = socket(list->ai_family, list->ai_socktype | SOCK_CLOEXEC, list->ai_protocol);
      std::string addr = {(char *) list->ai_addr, list->ai_addrlen};
      freeaddrinfo(list);
      if (fd == -1) throw InvalidSocketOp("socket");
      int yes = 1;
      ret     = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
      if (ret != 0) throw InvalidSocketOp("setsockopt");
      ret = bind(fd, (sockaddr *) &addr[0], addr.length());
      if (ret != 0) throw InvalidSocketOp("bind");
      ret = listen(fd, 0xFF);
      if (ret != 0) throw InvalidSocketOp("listen");
    }
  } else if (starts_with(address, "ws+unix://")) {
    std::string host{address};
    if (host.length() >= 108) throw InvalidAddress();
    path = "/";
    {
      sockaddr_un addr = {.sun_family = AF_UNIX};
      memcpy(addr.sun_path, &host[0], host.length());
      fd = socket(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0);
      if (fd == -1) throw InvalidSocketOp("socket");
      unlink(host.c_str());
      auto ret = bind(fd, (sockaddr *) &addr, sizeof(sockaddr_un));
      if (ret != 0) throw InvalidSocketOp("bind");
      ret = listen(fd, 0xFF);
      if (ret != 0) throw InvalidSocketOp("listen");
    }
  } else
    throw InvalidAddress();
}

server_wsio::~server_wsio() {
  shutdown();
  close(fd);
}

struct AutoClose {
  int fd;
  ~AutoClose() { close(fd); }
};

void server_wsio::accept(accept_fn process, recv_fn rcv) {
  auto client_id = ep->reg([=](epoll_event const &e) {
    if (auto it = fdmap.find(e.data.fd); it != fdmap.end()) {
      auto &[remote, client] = *it;
      try {
        if (e.events & EPOLLERR) {
          throw InvalidSocketOp("epoll");
        } else {
          switch (client->handle(rcv)) {
          case client::result::ACCEPT: process(client); break;
          case client::result::STOPPED: throw CommonException();
          case client::result::EMPTY: break;
          }
        }
      } catch (std::runtime_error &e) {
        ep->del(remote);
        fdmap.erase(it);
      }
    }
  });
  ep->add(EPOLLIN, fd, ep->reg([=](epoll_event const &e) {
    if (e.events & EPOLLERR) {
      ep->del(fd);
      return;
    }
    sockaddr_storage ad = {};
    socklen_t len       = sizeof(ad);
    auto remote         = ::accept4(fd, (sockaddr *) &ad, &len, SOCK_CLOEXEC);
    if (remote == -1) throw InvalidSocketOp("accept");
    fdmap[remote] = std::make_shared<server_wsio::client>(remote, path);
    ep->add(EPOLLIN, remote, client_id);
  }));
}

void server_wsio::shutdown() {
  ep->del(fd);
  for (auto &[fd, _] : fdmap) {
    ep->del(fd);
    ::shutdown(fd, SHUT_RDWR);
    close(fd);
  }
}

server_wsio::client::client(int fd, std::string_view path)
    : fd(fd), path(path), state(State::STATE_OPENING), type(FrameType::INCOMPLETE_FRAME) {}

server_wsio::client::~client() { shutdown(); }

void server_wsio::client::shutdown() {
  ::shutdown(fd, SHUT_WR);
  close(fd);
}

server_wsio::client::result server_wsio::client::handle(server_wsio::recv_fn const &process) {
  Handshake hs;
  Frame<Output> oframe;

  if (type != FrameType::INCOMPLETE_FRAME) return result::STOPPED;
  ssize_t readed = ::recv(fd, buffer.allocate(0xFFFF), 0xFFFF, 0);
  if (readed == 0) return result::STOPPED;
  if (readed == -1) { throw RecvFailed(); }
  buffer.eat(readed);

  if (state == State::STATE_OPENING) {
    hs   = parseHandshake(buffer);
    type = hs.type;
  } else {
  midpoint:
    oframe = parseFrame(buffer);
    type   = oframe.type;
  }

  if (type == FrameType::ERROR_FRAME) {
    if (state == State::STATE_OPENING) {
      std::ostringstream oss;
      oss << "HTTP/1.1 400 Bad Request\r\n"
          << "Sec-WebSocket-Version: 13\r\n\r\n";
      safeSend(fd, oss.str());
      return result::STOPPED;
    } else {
      auto temp = makeFrame(Frame<Input>{FrameType::CLOSING_FRAME});
      safeSend(fd, temp);
      state = State::STATE_CLOSING;
      type  = FrameType::INCOMPLETE_FRAME;
      buffer.reset();
    }
  }

  if (state == State::STATE_OPENING) {
    assert(type == FrameType::OPENING_FRAME);
    if (hs.resource != path) {
      safeSend(fd, "HTTP/1.1 404 Not Found\r\n\r\n");
      return result::STOPPED;
    }

    auto answer = makeHandshakeAnswer(hs.key);
    hs.reset();
    safeSend(fd, answer);
    state = State::STATE_NORMAL;
    type  = FrameType::INCOMPLETE_FRAME;
    buffer.drop(buffer.view().find("\r\n\r\n") + 4);
    return result::ACCEPT;
  } else {
    switch (type) {
    case FrameType::INCOMPLETE_FRAME: return result::EMPTY;
    case FrameType::CLOSING_FRAME:
      if (state != State::STATE_CLOSING) {
        auto temp = makeFrame({FrameType::CLOSING_FRAME});
        safeSend(fd, temp);
      }
      return result::STOPPED;
    case FrameType::PING_FRAME: safeSend(fd, makeFrame({FrameType::PONG_FRAME})); break;
    case FrameType::TEXT_FRAME: process(shared_from_this(), oframe.payload); break;
    default: break;
    }
    type = FrameType::INCOMPLETE_FRAME;
    buffer.drop(oframe.eaten);
    if (buffer.length()) goto midpoint;
  }
  return result::EMPTY;
}

void server_wsio::client::send(std::string_view data) { safeSend(fd, makeFrame({FrameType::TEXT_FRAME, data})); }

std::string base64(std::string_view input) {
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

client_wsio::client_wsio(std::string_view address, std::shared_ptr<epoll> ep) : ep(std::move(ep)) {
  std::string hoststr;
  if (starts_with(address, "ws://")) {
    auto end = address.find_first_of("[:/");
    if (end == std::string_view::npos) throw InvalidAddress();
    bool quoted = false;
    if (address[end] == '[') {
      quoted = true;
      end    = address.find(']');
      if (end == std::string_view::npos) throw InvalidAddress();
      end++;
    }
    auto host = eat(address, end);
    if (quoted) {
      host.remove_prefix(1);
      host.remove_suffix(1);
    }
    hoststr               = host;
    std::string_view port = "80";
    if (address[0] == ':') {
      address.remove_prefix(1);
      end = address.find('/');
      if (end == std::string_view::npos) throw InvalidAddress();
      port = eat(address, end);
    }
    path = eat(address, address.find_first_of("?#"));
    {
      std::string host_str{host};
      std::string port_str{port};
      addrinfo hints = {
          .ai_flags    = AI_PASSIVE,
          .ai_family   = AF_UNSPEC,
          .ai_socktype = SOCK_STREAM,
      };
      addrinfo *list;
      auto ret = getaddrinfo(host_str.c_str(), port_str.c_str(), &hints, &list);
      if (ret != 0) throw InvalidAddress();
      fd               = socket(list->ai_family, list->ai_socktype | SOCK_CLOEXEC, list->ai_protocol);
      std::string addr = {(char *) list->ai_addr, list->ai_addrlen};
      freeaddrinfo(list);
      if (fd == -1) throw InvalidSocketOp("socket");
      ret = connect(fd, (sockaddr *) &addr[0], addr.length());
      if (ret == -1) throw InvalidSocketOp("connect");
    }
  } else if (starts_with(address, "ws+unix://")) {
    hoststr = address;
    if (hoststr.length() >= 108) throw InvalidAddress();
    path = "/";
    {
      sockaddr_un addr = {.sun_family = AF_UNIX};
      memcpy(addr.sun_path, &hoststr[0], hoststr.length());
      fd = socket(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0);
      if (fd == -1) throw InvalidSocketOp("socket");
      auto ret = connect(fd, (sockaddr *) &addr, sizeof(sockaddr_un));
      if (ret == -1) throw InvalidSocketOp("connect");
    }
  } else
    throw InvalidAddress();

  union {
    uint64_t u2[2] = {std::experimental::randint((uint64_t) 0, UINT64_MAX),
                      std::experimental::randint((uint64_t) 0, UINT64_MAX)};
    char b16[16];
  };

  key = base64(b16);

  {
    auto handshake = makeHandshake({
        .type     = FrameType::OPENING_FRAME,
        .host     = hoststr,
        .origin   = hoststr,
        .key      = key,
        .resource = path,
    });
    safeSend(fd, handshake);
  }
}

void client_wsio::ondie(std::function<void()> ondie_cb) { ondie_cbs.emplace_back(ondie_cb); }

void client_wsio::shutdown() {
  if (alive()) {
    ep->del(fd);
    for (auto cb : ondie_cbs) cb();
  }
}

client_wsio::~client_wsio() {
  shutdown();
  close(fd);
}

void client_wsio::recv(recv_fn rcv, promise<void>::resolver resolver) {
  ep->add(EPOLLIN, fd, ep->reg([=](epoll_event const &e) {
    if (e.events & EPOLLERR) {
      shutdown();
      return resolver.reject(InvalidSocketOp("epoll_wait"));
    }

    ssize_t readed = ::recv(fd, buffer.allocate(0xFFFF), 0xFFFF, 0);
    if (readed == 0) {
      shutdown();
      return;
    }
    if (readed == -1) {
      shutdown();
      return resolver.reject(RecvFailed());
    }
    buffer.eat(readed);

    Frame<Input> oframe;
    FrameType type = FrameType::INCOMPLETE_FRAME;

    if (state == State::STATE_OPENING) {
      if (parseHandshakeAnswer(buffer, key).empty()) return resolver.reject(HandshakeFailed{});
      resolver.resolve();
      state = State::STATE_NORMAL;
      buffer.reset();
      return;
    } else {
    midpoint:
      oframe = parseServerFrame(buffer);
      type   = oframe.type;
    }

    switch (type) {
    case FrameType::ERROR_FRAME: return resolver.reject(InvalidFrame{});
    case FrameType::CLOSING_FRAME: shutdown(); return;
    case FrameType::PING_FRAME: safeSend(fd, makeFrame({FrameType::PONG_FRAME}, true)); break;
    case FrameType::TEXT_FRAME: rcv(oframe.payload); break;
    default: break;
    }
    buffer.drop(oframe.eaten);
    if (buffer.length()) goto midpoint;
  }));
}

void client_wsio::send(std::string_view data) {
  auto frame = makeFrame({FrameType::TEXT_FRAME, data}, true);
  safeSend(fd, frame);
}

bool client_wsio::alive() { return ep->has(fd); }

} // namespace rpcws