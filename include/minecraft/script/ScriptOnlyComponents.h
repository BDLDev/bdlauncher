#pragma once

#include "../json.h"

#include <map>
#include <string>

class ScriptEngine;

namespace ScriptApi {
class ScriptObjectHandle;
struct ScriptVersionInfo;
} // namespace ScriptApi

class ScriptServerContext;

template <typename C> class ScriptOnlyComponents;

template <> class ScriptOnlyComponents<ScriptServerContext> {
  std::map<std::string, Json::Value> data;
  bool _extractEcsIdentifier(ScriptEngine &, ScriptApi::ScriptObjectHandle const &, uint &);

public:
  class ScriptOnly {
    std::map<std::string, Json::Value> data;
  };
  bool applyComponentTo(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, ScriptApi::ScriptObjectHandle const &,
                        std::string const &, ScriptApi::ScriptObjectHandle const &);
  void clearComponents();
  bool createComponent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, ScriptApi::ScriptObjectHandle const &,
                       std::string const &, ScriptApi::ScriptObjectHandle &);
  bool hasComponent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, ScriptApi::ScriptObjectHandle const &,
                    std::string const &, bool &);
  bool isDefined(std::string const &) const;
  bool registerComponent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, std::string const &, ScriptApi::ScriptObjectHandle const &);
  bool removeComponent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, ScriptApi::ScriptObjectHandle const &,
                       std::string const &);
  bool retrieveComponentFrom(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, ScriptApi::ScriptObjectHandle const &,
                             std::string const &, ScriptApi::ScriptObjectHandle &);
};