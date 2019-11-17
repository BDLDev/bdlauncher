#pragma once

#include <functional>
#include <thread>
#include <vector>

class EventResult;

template <typename L> class EventCoordinator {
  std::vector<L *> listeners;
  std::vector<std::function<EventResult(L *)>> handlers;
  std::thread::id tid;

public:
  EventCoordinator();
  ~EventCoordinator();
  void _checkThreadId();
  void processEvent(std::function<EventResult(L *)>);
  void registerListener(L&);
  void unregisterListener(L&);
};