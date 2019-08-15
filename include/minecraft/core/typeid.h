#pragma once

template <typename T> struct typeid_t {
  struct NewIDType {};
  short value;
  static short count __attribute__((weak));

  typeid_t(NewIDType) : value(count++) {}
  typeid_t(typeid_t const &id) : value(id.value) {}

  typeid_t &operator=(typeid_t const &id);
  bool operator==(typeid_t const &);
  bool operator!=(typeid_t const &);
  bool operator<(typeid_t const &);
};

template <typename T, typename U> typeid_t<T> type_id() __attribute__((weak));
template <typename T, typename U> typeid_t<T> type_id() {
  static typeid_t<T> id{typename typeid_t<T>::NewIDType()};
  return id;
}