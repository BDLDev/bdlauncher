#pragma once

#include <cstring>
#include <functional>
#include <map>
#include <stdexcept>
#include <string>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <unistd.h>
#include <vector>

struct epoll_exception : public std::runtime_error {
  epoll_exception(char const *msg) : std::runtime_error(std::string(msg) + ": " + strerror(errno)) {}
};

class epoll {
  int ep, ev;
  std::map<int, size_t> type_map;
  std::vector<std::function<void(epoll_event const &)>> callbacks;
  bool stop = false;

public:
  inline epoll() {
    ep = epoll_create1(EPOLL_CLOEXEC);
    if (ep == -1) throw epoll_exception("epoll_create");
    ev = eventfd(0, EFD_CLOEXEC);
    if (ev == -1) throw epoll_exception("eventfd");
    add(EPOLLIN, ev, reg([this](auto) {
          uint64_t count;
          read(ev, &count, sizeof(count));
          stop = true;
        }));
  }

  epoll(epoll const &) = delete;
  epoll &operator=(epoll const &) = delete;

  inline ~epoll() {
    close(ev);
    close(ep);
  }

  inline void add(uint32_t events, int fd, int type) {
    epoll_event event = {.events = events, .data = {.fd = fd}};
    if (epoll_ctl(ep, EPOLL_CTL_ADD, fd, &event) != 0) throw epoll_exception("epoll_ctl");
    type_map[fd] = type;
  }

  inline void del(int fd) {
    epoll_ctl(ep, EPOLL_CTL_DEL, fd, nullptr);
    type_map.erase(fd);
  }

  inline size_t reg(std::function<void(epoll_event const &)> callback) {
    callbacks.emplace_back(callback);
    return callbacks.size() - 1;
  }

  inline void wait() {
    while (!stop) {
      epoll_event event = {};
      auto ret          = epoll_wait(ep, &event, 1, -1);
      if (ret > 0) callbacks[type_map[event.data.fd]](event);
    }
  }

  inline bool has(int fd) { return type_map.find(fd) != type_map.end(); }

  inline void shutdown() {
    uint64_t count = 1;
    write(ev, &count, 8);
  }
};