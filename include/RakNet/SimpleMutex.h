#pragma once

#include <pthread.h>
#include <sys/types.h>

namespace RakNet {
class SimpleMutex {
public:
  // Constructor
  SimpleMutex();

  // Destructor
  ~SimpleMutex();

  // Locks the mutex.  Slow!
  void Lock(void);

  // Unlocks the mutex.
  void Unlock(void);

private:
  void Init(void);
  pthread_mutex_t hMutex;
};
} // namespace RakNet