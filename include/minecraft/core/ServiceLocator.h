#pragma once

template <typename T> class ServiceLocator {
public:
  static T *get();
};