#pragma once

#define PAGE_SIZE 0x1000
#define ROUND_PAGE_DOWN(num) ((num) & ~(PAGE_SIZE - 1))
#define ROUND_PAGE_UP(num) (((num) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))
#define countof(expr) (sizeof(expr) / sizeof((expr)[0]))
#define ABITAG(tag) __attribute__((abi_tag(#tag)))
#define ALIAS(name) __attribute__((weakref, alias(#name)))
#define CLEANUP(func) __attribute__((__cleanup__(func)))
#define INLINE __attribute__((always_inline)) inline
#define USED __attribute__((used))

#define MakeAccessor(name, R, offset)                                                                                                                                                                  \
  INLINE R &name() ABITAG(custom) { return *reinterpret_cast<R *>(reinterpret_cast<char *>(this) + offset); }                                                                                          \
  INLINE R const &name() const ABITAG(custom) { return *reinterpret_cast<R const *>(reinterpret_cast<char const *>(this) + offset); }
