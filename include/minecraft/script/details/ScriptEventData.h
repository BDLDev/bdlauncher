#pragma once

#include "../../core/types.h"
#include "../../item/ItemInstance.h"
#include "../../json.h"
#include "../ScriptEventData.h"

#ifndef PATCHABLE
#define PATCHABLE
#endif

class CustomScriptEventData : public ScriptEventData {
  Json::Value value;

public:
  CustomScriptEventData(std::string const &);
  virtual ~CustomScriptEventData();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setData(Json::Value const &);
  void setData(std::string const &);
  void setData(ScriptEngine &, ScriptApi::ScriptObjectHandle const &);
};

class ScriptServerActorAcquiredItemEvent : public ScriptEventData {
  ActorUniqueID entity, secondary_entity;
  ItemInstance item;
  unsigned amount;
  ItemAcquisitionMethod method;

public:
  ScriptServerActorAcquiredItemEvent();
  virtual ~ScriptServerActorAcquiredItemEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setAcquiredAmount(unsigned int);
  void setAcquisitionMethod(ItemAcquisitionMethod);
  void setActorId(ActorUniqueID const &);
  void setItemStack(ItemInstance const &);
  void setSecondaryActorId(ActorUniqueID const &);
};

class ScriptServerActorCarriedItemChangedEvent : public ScriptEventData {
  ActorUniqueID entity;
  ItemInstance previous_carried_item, carried_item;

public:
  ScriptServerActorCarriedItemChangedEvent();
  virtual ~ScriptServerActorCarriedItemChangedEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
  void setItems(ItemInstance const &, ItemInstance const &);
};

class ScriptServerActorCreatedEvent : public ScriptEventData {
  ActorUniqueID entity;

public:
  ScriptServerActorCreatedEvent();
  virtual ~ScriptServerActorCreatedEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
};

class ScriptServerActorDeathEvent : public ScriptEventData {
  ActorUniqueID entity;

public:
  ScriptServerActorDeathEvent();
  virtual ~ScriptServerActorDeathEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
};

class ScriptServerActorDroppedItemEvent : public ScriptEventData {
  ActorUniqueID entity;
  ItemInstance item;

public:
  ScriptServerActorDroppedItemEvent();
  virtual ~ScriptServerActorDroppedItemEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
  void setItemStack(ItemInstance const &);
};

class ScriptServerActorEquippedArmorEvent : public ScriptEventData {
  ActorUniqueID entity;
  ItemInstance item;

public:
  ScriptServerActorEquippedArmorEvent();
  virtual ~ScriptServerActorEquippedArmorEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
  void setItemStack(ItemInstance const &);
};

class ScriptServerActorStartRidingEvent : public ScriptEventData {
  ActorUniqueID entity, ride;

public:
  ScriptServerActorStartRidingEvent();
  virtual ~ScriptServerActorStartRidingEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
  void setRideEntityId(ActorUniqueID const &);
};

class ScriptServerActorStopRidingEvent : public ScriptEventData {
  ActorUniqueID entity;

  bool exit_from_rider;
  bool entity_is_being_destroyed;
  bool switching_rides;

public:
  ScriptServerActorStopRidingEvent();
  virtual ~ScriptServerActorStopRidingEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
  void setExitFromRider(bool);
  void setEntityIsBeingDestroyed(bool);
  void setSwitchingRides(bool);
};

class ScriptServerActorTickEvent : public ScriptEventData {
  ActorUniqueID entity;

public:
  ScriptServerActorTickEvent();
  virtual ~ScriptServerActorTickEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
};

class ScriptServerActorUseItemEvent : public ScriptEventData {
  ActorUniqueID entity;
  ItemInstance item;
  ItemUseMethod use_method;

public:
  ScriptServerActorUseItemEvent();
  virtual ~ScriptServerActorUseItemEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
  void setItemStack(ItemInstance const &);
  void setUseMethod(ItemUseMethod);
};

class ScriptServerBlockDestructionStartedEvent : public ScriptEventData {
  ActorUniqueID entity;
  BlockPos pos;

public:
  ScriptServerBlockDestructionStartedEvent();
  virtual ~ScriptServerBlockDestructionStartedEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
  void setBlockPos(BlockPos const &);
};

class ScriptServerBlockDestructionStoppedEvent : public ScriptEventData {
  ActorUniqueID entity;
  BlockPos pos;
  float progress;

public:
  ScriptServerBlockDestructionStoppedEvent();
  virtual ~ScriptServerBlockDestructionStoppedEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
  void setBlockPos(BlockPos const &);
  void setProgress(float);
};

class ScriptServerBlockInteractedWithEvent : public ScriptEventData {
  ActorUniqueID entity;
  BlockPos pos;

public:
  ScriptServerBlockInteractedWithEvent();
  virtual ~ScriptServerBlockInteractedWithEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
  void setBlockPos(BlockPos const &);
};

class ScriptServerBlockMovedByPistonEvent : public ScriptEventData {
  BlockPos piston, block;
  std::string action;

public:
  ScriptServerBlockMovedByPistonEvent();
  virtual ~ScriptServerBlockMovedByPistonEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setBlockPos(BlockPos const &);
  void setPistonPos(BlockPos const &);
  void setPistonAction(std::string);
};

class ScriptServerPlayerDestroyedBlockEvent : public ScriptEventData {
  ActorUniqueID entity;
  BlockPos block;
  std::string identifier;

public:
  ScriptServerPlayerDestroyedBlockEvent();
  virtual ~ScriptServerPlayerDestroyedBlockEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
  void setBlockPos(BlockPos const &);
  void setBlockIdentifier(std::string);
};

class ScriptServerPlayerPlacedBlockEvent : public ScriptEventData {
  ActorUniqueID entity;
  BlockPos block;

public:
  ScriptServerPlayerPlacedBlockEvent();
  virtual ~ScriptServerPlayerPlacedBlockEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setActorId(ActorUniqueID const &);
  void setBlockPos(BlockPos const &);
};

class ScriptPlayerAttackedActorEvent : public ScriptEventData {
  ActorUniqueID player, entity;

public:
  ScriptPlayerAttackedActorEvent();
  virtual ~ScriptPlayerAttackedActorEvent();
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const PATCHABLE;

  void setPlayerId(ActorUniqueID const&);
  void setAttackedActorId(ActorUniqueID const&);
};