#pragma once

#include <memory>
#include <string>
#include <unordered_map>

class ScriptBinderTemplate;
class ScriptEngine;
class ScriptObjectBinder;

namespace ScriptApi {
class ScriptObjectHandle;
}

class ScriptBinderTemplateController {
  std::unordered_map<std::string, std::unique_ptr<ScriptBinderTemplate>> map;

public:
  std::unique_ptr<ScriptObjectBinder> deserialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &) const;
  template <typename T> void registerBinderTemplate();
  bool serialize(ScriptEngine &, ScriptObjectBinder const &, ScriptApi::ScriptObjectHandle &);
};