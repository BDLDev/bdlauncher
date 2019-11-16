#pragma once

#include <cstdint>

namespace RakNet {

class LocklessUint32_t {
public:
  LocklessUint32_t();
  explicit LocklessUint32_t(uint32_t initial);
  // Returns variable value after changing it
  uint32_t Increment(void);
  // Returns variable value after changing it
  uint32_t Decrement(void);
  uint32_t GetValue(void) const { return value; }

protected:
  volatile uint32_t value;
};
} // namespace RakNet