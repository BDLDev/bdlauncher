#pragma once
#include <cstring>
#include <dlfcn.h>

struct ReadOnlyBinaryStream {
  char filler[256];
  ReadOnlyBinaryStream(string *x) {
    auto fn = dlsym(NULL, "_ZN20ReadOnlyBinaryStreamC2EONSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE");
    void (*fnn)(void *, string *);
    fnn = (typeof(fnn)) fn;
    fnn(this, x);
  }
};