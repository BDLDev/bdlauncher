#pragma once
template<typename T>
static void* void_cast(T f)
{
    union
    {
        T pf;
        void* p;
    };
    pf = f;
    return p;
}
void* MyHook(void* oldfunc, void* newfunc);
#define CONS(a, b) a##b
#define HOOK(type, method) MyHook(void_cast(& type :: method ), void_cast(& type :: CONS($$, method)), (void**) & type :: CONS($, method)())
#define IMPL(type, ret, name, suffix, ...)                       \
    using CONS(name, _t) = ret (*)(type suffix*, ##__VA_ARGS__); \
    ret name(__VA_ARGS__) suffix;                                \
    static CONS(name, _t) & CONS($, name)() {                    \
        static CONS(name, _t) fn;                                \
        return fn;                                               \
    }                                                            \
    ret CONS($$, name)(__VA_ARGS__) suffix
#define IMPL_STATIC(ret, name, ...) \
    using CONS(name, _t) = ret ( * ) ( __VA_ARGS__ );\
    static ret name ( __VA_ARGS__ ) ; \
    static CONS(name, _t) & CONS($, name) () { static CONS(name, _t) fn; return fn; } \
    static ret CONS($$, name) ( __VA_ARGS__ )

#include <dlfcn.h>
#include <cstdio>

struct RegisterStaticHook {
  RegisterStaticHook(const char *sym, void *hook, void **org) {
    auto r = dlsym(NULL, sym);
    if (r == nullptr) { printf("Symbol not found: %s", sym); }
    *org=MyHook(r, hook);
  }
  RegisterStaticHook(void* r, void *hook, void **org) {
    *org=MyHook(r, hook);
  }
  // workaround for a warning
  template <typename T> RegisterStaticHook(const char *sym, T hook, void **org) {
    union {
      T a;
      void *b;
    } hookUnion;
    hookUnion.a = hook;
    RegisterStaticHook(sym, hookUnion.b, org);
  }
  template <typename T> RegisterStaticHook(void *sym, T hook, void **org) {
    union {
      T a;
      void *b;
    } hookUnion;
    hookUnion.a = hook;
    RegisterStaticHook(sym, hookUnion.b, org);
  }
};

#define _TStaticHook(pclass, iname, sym, ret, args...)                                                                                               \
  struct _TStaticHook_##iname pclass {                                                                                                               \
    static ret (*_original)(args);                                                                                                                   \
    template <typename... Params> static ret original(Params &&... params) { return (*_original)(std::forward<Params>(params)...); }                 \
    static ret _hook(args);                                                                                                                          \
  };                                                                                                                                                 \
  static RegisterStaticHook _TRStaticHook_##iname(#sym, &_TStaticHook_##iname::_hook, (void **)&_TStaticHook_##iname::_original);                    \
  ret (*_TStaticHook_##iname::_original)(args);                                                                                                      \
  ret _TStaticHook_##iname::_hook(args)
#define _TStaticDefHook(iname, sym, ret, type, args...) _TStaticHook( : public type, iname, sym, ret, args)
#define _TStaticNoDefHook(iname, sym, ret, args...) _TStaticHook(, iname, sym, ret, args)

#define THook2(iname, ret, sym, args...) _TStaticNoDefHook(iname, sym, ret, args)
#define THook(ret, sym, args...) THook2(sym, ret, sym, args)
#define TStaticHook2(iname, ret, sym, type, args...) _TStaticDefHook(iname, sym, ret, type, args)
#define TStaticHook(ret, sym, type, args...) TStaticHook2(sym, ret, sym, type, args)
