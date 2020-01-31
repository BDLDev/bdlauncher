#include <memory>
#include "vtSP.h"
#define access(ptr, type, off) (*((type *) (((uintptr_t) ptr) + off)))

//typedef void *UNK_64;
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