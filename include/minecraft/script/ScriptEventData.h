#pragma once

#include <string>

namespace ScriptApi {
class ScriptObjectHandle;
}

class EventInfo;
class ScriptEngine;

class ScriptEventData {
  std::string name;

public:
  std::string getName() const;
  bool serialize(ScriptEngine &, EventInfo &, ScriptApi::ScriptObjectHandle &) const;
  virtual ~ScriptEventData();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const = 0;
};