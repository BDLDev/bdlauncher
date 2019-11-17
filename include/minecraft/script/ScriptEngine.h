#pragma once

#include "ScriptCallbackInterface.h"
#include "ScriptFramework.h"

#include <memory>
#include <unordered_map>

#ifndef PATCHABLE
#define PATCHABLE
#endif

namespace Json {
class Value;
}
namespace ScriptApi {
class EventTracking;
} // namespace ScriptApi

struct Vec3;
struct BlockPos;
class Actor;
class ScriptEventCoordinator;
class EventInfo;
class ScriptEventData;
class ScriptObjectBinder;

class ScriptEngine : public ScriptApi::ScriptFramework {
public:
  ScriptApi::ScriptCallbackInterface interface;
  bool initialize() PATCHABLE;

  std::unique_ptr<ScriptObjectBinder> helpDeserialize(ScriptApi::ScriptObjectHandle const &);
  bool helpDefineVec3(ScriptApi::ScriptObjectHandle &target, std::string const &key, Vec3 const &value) PATCHABLE;
  bool helpGetVec3(ScriptApi::ScriptObjectHandle const &source, std::string const &key, Vec3 &value) PATCHABLE;
  bool helpDefinePosition(BlockPos const &, ScriptApi::ScriptObjectHandle &);
  bool helpDefinePosition(Vec3 const &, ScriptApi::ScriptObjectHandle &);
  bool helpGetPosition(ScriptApi::ScriptObjectHandle const &, BlockPos &);
  bool helpSetPosition(BlockPos const &, ScriptApi::ScriptObjectHandle const &);

  bool serializeJsonToScriptObjectHandle(ScriptApi::ScriptObjectHandle &, Json::Value const &) PATCHABLE;
  bool deserializeScriptObjectHandleToJson(ScriptApi::ScriptObjectHandle const &, Json::Value &) PATCHABLE;

  bool fireEventToScript(EventInfo const &, ScriptApi::ScriptObjectHandle &&) PATCHABLE;

  bool _validateObjectIdentifier(bool, std::string const &) const;

  ScriptEventCoordinator &getScriptEventCoordinator();
  std::unordered_map<std::string, EventInfo> &getEventInfoMap();
  std::unordered_map<std::string, std::vector<ScriptApi::EventTracking>> &getEventTrackings();
};