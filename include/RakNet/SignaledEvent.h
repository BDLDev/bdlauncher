#pragma once

#include "SimpleMutex.h"
#include "macros.h"
#include <pthread.h>
#include <sys/types.h>

namespace RakNet {

class SignaledEvent {
public:
  SignaledEvent();
  ~SignaledEvent();

  void InitEvent(void);
  void CloseEvent(void);
  void SetEvent(void);
  void WaitOnEvent(int timeoutMs);

protected:
  SimpleMutex isSignaledMutex;
  bool isSignaled;
  pthread_condattr_t condAttr;
};
} // namespace RakNet