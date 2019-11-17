#pragma once

#include "SharedPtr.h"

template <typename T> class WeakPtr {
  T **ptr;

public:
  WeakPtr(SharedPtr<T> const &);
  void reset();
  inline ~WeakPtr() { reset(); }
  bool isNull() const;
  operator T *() const;
  T *const operator*() const;
  T *const operator->() const;
};