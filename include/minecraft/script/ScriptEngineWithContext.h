#pragma once

#include "../../util.h"
#include "../core/types.h"
#include "../level/ITickingArea.h"
#include "ScriptBinderTemplateController.h"
#include "ScriptEngine.h"
#include "ScriptOnlyComponents.h"
#include "ScriptOnlyEventsData.h"
#include "ScriptQueries.h"
#include "ScriptTemplateFactory.h"

#include <string>

#ifndef PATCHABLE
#define PATCHABLE
#endif

namespace ScriptApi {
class ScriptObjectHandle;
struct ScriptVersionInfo;
class EventTracking;
} // namespace ScriptApi

class ScriptServerContext;
class ItemInstance;
class ScriptLevelAreaBinderComponent;
class ScriptActorAreaBinderComponent;

template <typename CONTEXT = ScriptServerContext> class ScriptEngineWithContext;

template <> class ScriptEngineWithContext<ScriptServerContext> : public ScriptEngine {
public:
  MakeAccessor(getScriptServerContext, ScriptServerContext, 496);
  MakeAccessor(getScriptOnlyEventsData, ScriptOnlyEventsData<ScriptServerContext>, 824);
  MakeAccessor(getScriptOnlyComponents, ScriptOnlyComponents<ScriptServerContext>, 776);
  MakeAccessor(getScriptTemplateFactory, ScriptTemplateFactory<ScriptServerContext>, 536);
  MakeAccessor(getScriptBinderTemplateController, std::unique_ptr<ScriptBinderTemplateController>, 192);
  MakeAccessor(getScriptQueries, ScriptQueries, 1008);

  bool helpDefineLevel(ScriptApi::ScriptObjectHandle &);
  bool helpDefineActor(Actor const &, ScriptApi::ScriptObjectHandle &);
  bool helpDefineActor(ActorUniqueID const &, ScriptApi::ScriptObjectHandle &);
  bool helpDefineItemStack(ItemInstance const &, ScriptApi::ScriptObjectHandle &);
  bool helpDefineTickingArea(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle &, ITickingArea const &);
  bool helpDefineTickingArea(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle &, ActorUniqueID const &);
  bool helpGetActor(ScriptApi::ScriptObjectHandle const &, Actor **);
  bool helpGetBlockSource(ScriptApi::ScriptObjectHandle const &, BlockSource **);
  bool helpGetBlock(ScriptApi::ScriptObjectHandle const &, Block const **, BlockSource const &);
  bool helpGetLevel(ScriptApi::ScriptObjectHandle const &, Level **);

  bool helpDefineItemStackWithPath(ItemInstance const &, Actor const &, std::string const &, int idx, ScriptApi::ScriptObjectHandle &) ABITAG(quickjs);
  bool helpGetItemStackFromPath(ItemInstance &, ScriptApi::ScriptObjectHandle const &) ABITAG(quickjs);
  bool helpApplyItemStackWithPath(ItemInstance const &, ScriptApi::ScriptObjectHandle const &) ABITAG(quickjs);

  bool createEntity(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle &) PATCHABLE;
  bool createEntity(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle &, std::string const &type, std::string const &identifier);
  bool destroyEntity(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle const &);
  bool isValidEntity(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle const &, bool &);

  bool registerEventData(ScriptApi::ScriptVersionInfo const &, std::string const &, ScriptApi::ScriptObjectHandle const &);
  bool createEventData(ScriptApi::ScriptVersionInfo const &, std::string const &, ScriptApi::ScriptObjectHandle &) PATCHABLE;

  bool registerComponent(ScriptApi::ScriptVersionInfo const &, std::string const &, ScriptApi::ScriptObjectHandle const &);
  bool createComponent(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle const &, std::string const &, ScriptApi::ScriptObjectHandle &) PATCHABLE;
  bool hasComponent(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle const &, std::string const &, bool &);
  bool getComponent(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle const &, std::string const &, ScriptApi::ScriptObjectHandle &) PATCHABLE;
  bool applyComponentChanges(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle const &, ScriptApi::ScriptObjectHandle const &) PATCHABLE;
  bool destroyComponent(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle const &, std::string const &);

  bool registerQuery(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle &);
  bool registerQuery(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle &, std::string const &, std::string const &, std::string const &, std::string const &);
  bool addFilter(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle const &, std::string const &);

  bool getBlock(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle &, BlockPos const &, ScriptApi::ScriptObjectHandle const &) PATCHABLE;

  bool fireEvent(ScriptEventData const &) PATCHABLE;
  bool onEventReceivedFromScriptEngine(ScriptApi::ScriptVersionInfo const &, std::string const &, ScriptApi::ScriptObjectHandle const &) PATCHABLE;

  bool __hack__viewTouch();
  static BlockSource *_helpGetBlockSourceFromBinder(Level &, ScriptLevelAreaBinderComponent const *, ScriptActorAreaBinderComponent const *);
};