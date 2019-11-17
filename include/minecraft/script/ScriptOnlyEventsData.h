#pragma once

#include "../json.h"

#include <map>
#include <string>

class ScriptServerContext;
class ScriptEngine;

namespace ScriptApi {
struct ScriptVersionInfo;
class ScriptObjectHandle;
} // namespace ScriptApi

template <typename T = ScriptServerContext> class ScriptOnlyEventsData;
template <> class ScriptOnlyEventsData<ScriptServerContext> {
  std::map<std::string, Json::Value> data;

public:
  bool createEventData(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                       ScriptApi::ScriptObjectHandle &);
  bool isDefined(std::string const &) const;
};