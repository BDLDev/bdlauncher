#pragma once

class EntityContextBase {
public:
  template <typename> bool hasComponent();
  template <typename T> T &getComponent();
  template <typename T> T &tryGetComponent();
  template <typename T> T &addComponent();
  template <typename T> T &getOrAddComponent();
};