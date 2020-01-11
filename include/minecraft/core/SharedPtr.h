#pragma once

template <typename T> class SharedPtr {
  T **value;

public:
  SharedPtr(T *value);
  ~SharedPtr();
  template <typename... RS> static SharedPtr<T> make(RS &&...);
  void reset();
  T *const operator*() const;
  T *const operator->() const;
};