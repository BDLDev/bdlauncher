#pragma once

#include "../core/typeid.h"

#include <memory>
#include <string>
#include <vector>

#ifndef PATCHABLE
#define PATCHABLE
#endif

class ScriptBinderComponent;
class ScriptEngine;

namespace ScriptApi {
class ScriptObjectHandle;
}

class ScriptObjectBinder {
  bool _hasComponent(ushort) const;

public:
  static std::string TYPE_TAG;
  std::string type;
  int id;
  std::vector<std::unique_ptr<ScriptBinderComponent>> components;
  bool serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;
  bool deserialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &);

  static std::unique_ptr<ScriptObjectBinder> extract(ScriptEngine &, ScriptApi::ScriptObjectHandle const &);

  template <typename T> T const *getComponent() const;
  template <typename T> bool hasComponent() const {
    auto id = type_id<ScriptBinderComponent, T>();
    return _hasComponent(id.value);
  }
  template <typename T, typename... RS> void addComponent(RS...);
};