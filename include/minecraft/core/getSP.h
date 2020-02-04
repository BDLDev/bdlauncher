#pragma once
#include <memory>
#include "access.h"

#pragma once
extern "C" {
void _ZTV12ServerPlayer(void); // dummy
}

// utils for runtime type detecting
static auto vtSP = ((void **) _ZTV12ServerPlayer) + 2;
class ServerPlayer;
template <class T> inline ServerPlayer *getSP(T &a) {
  return access(&a, void *, 0) == vtSP ? (ServerPlayer *) &a : nullptr;
}
template <class T> inline ServerPlayer *getSP(T *a) {
  if (!a) return nullptr;
  return access(a, void *, 0) == vtSP ? (ServerPlayer *) a : nullptr;
}
template <class T> inline ServerPlayer *getSP(std::unique_ptr<T> &a) {
  return access(a.get(), void *, 0) == vtSP ? (ServerPlayer *) a.get() : nullptr;
}