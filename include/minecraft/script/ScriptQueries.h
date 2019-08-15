#pragma once

#include "entt.h"

#include <vector>

namespace ScriptApi {
struct ScriptVersionInfo;
class ScriptObjectHandle;
} // namespace ScriptApi

class ScriptEngine;

#ifndef PATCHABLE
#define PATCHABLE
#endif

class ScriptQueries {
  entt::Registry<unsigned int> queries;
public:
  bool getEntitiesFromQuery(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, entt::Registry<unsigned int> &, unsigned int,
                            std::vector<ScriptApi::ScriptObjectHandle> &) PATCHABLE;
  bool getEntitiesFromQuery(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, entt::Registry<unsigned int> &, unsigned int, double, double,
                            double, double, double, double, std::vector<ScriptApi::ScriptObjectHandle> &) PATCHABLE;
};