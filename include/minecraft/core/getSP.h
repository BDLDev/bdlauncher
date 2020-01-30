#include <memory>
#define access(ptr, type, off) (*((type *) (((uintptr_t) ptr) + off)))

extern "C" {
void _ZTV12ServerPlayer(void); // dummy
}

typedef void *UNK_64;
class ServerPlayer;
// utils for runtime type detecting
static auto vtSP = ((void **) _ZTV12ServerPlayer) + 2; //((void **)dlsym(NULL, "_ZTV12ServerPlayer") + 2);
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