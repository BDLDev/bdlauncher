#pragma once

#include "../ScriptTemplateFactory.h"

#include <string>

#ifndef PATCHABLE
#define PATCHABLE
#endif

#define COMMON_COMMONENT(name)                                                                                                                       \
  class name : public ScriptTemplateFactory<ScriptServerContext>::Component {                                                                        \
  public:                                                                                                                                            \
    static std::string getName();                                                                                                                    \
                                                                                                                                                     \
    name();                                                                                                                                          \
    virtual ~name();                                                                                                                                 \
    virtual bool applyComponentTo(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, Actor &,                              \
                                  ScriptApi::ScriptObjectHandle const &) const override PATCHABLE;                                                   \
    virtual bool retrieveComponentFrom(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, Actor &,                         \
                                       ScriptApi::ScriptObjectHandle &) const override PATCHABLE;                                                    \
    virtual bool hasComponent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, Actor &, bool &) const override;          \
  }

COMMON_COMMONENT(ScriptArmorContainerComponent);
COMMON_COMMONENT(ScriptAttackComponent);
COMMON_COMMONENT(ScriptCollisionBoxComponent);
COMMON_COMMONENT(ScriptDamageSensorComponent);
COMMON_COMMONENT(ScriptEquipmentComponent);
COMMON_COMMONENT(ScriptExplodeComponent);
COMMON_COMMONENT(ScriptHandContainerComponent);
COMMON_COMMONENT(ScriptHealableComponent);
COMMON_COMMONENT(ScriptHealthComponent);
COMMON_COMMONENT(ScriptHotbarContainerComponent);
COMMON_COMMONENT(ScriptInventoryComponent);
COMMON_COMMONENT(ScriptInventoryContainerComponent);
COMMON_COMMONENT(ScriptLookAtComponent);
COMMON_COMMONENT(ScriptNameableComponent);
COMMON_COMMONENT(ScriptPositionComponent);
COMMON_COMMONENT(ScriptRotationComponent);
COMMON_COMMONENT(ScriptShooterComponent);
COMMON_COMMONENT(ScriptSpawnActorComponent);
COMMON_COMMONENT(ScriptTeleportComponent);
COMMON_COMMONENT(ScriptTickWorldComponent);

#undef COMMON_COMMONENT