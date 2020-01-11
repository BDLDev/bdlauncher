#pragma once

#include "../core/UUID.h"
#include "../core/types.h"

#include <string>

class ScriptEngine;

namespace ScriptApi {
class ScriptObjectHandle;
}

class ScriptBinderComponent {
public:
  virtual ~ScriptBinderComponent();
  virtual bool serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &) const;
  virtual bool deserialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &);
};

class Actor;
class Block;
class ItemActor;
class ItemInstance;

class ScriptIdentifierBinderComponent : public ScriptBinderComponent {
  std::string identifier;

public:
  ScriptIdentifierBinderComponent();
  ScriptIdentifierBinderComponent(Actor const &);
  ScriptIdentifierBinderComponent(Block const &);
  ScriptIdentifierBinderComponent(ItemActor const &);
  ScriptIdentifierBinderComponent(std::string const &);

  virtual ~ScriptIdentifierBinderComponent();
  virtual bool serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &) const;
  virtual bool deserialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &);

  static std::string TAG;
  std::string const &getIdentifier() const;
};

class ITickingArea;

class ScriptLevelAreaBinderComponent : public ScriptBinderComponent {
  mce::UUID uuid;

public:
  ScriptLevelAreaBinderComponent();
  ScriptLevelAreaBinderComponent(mce::UUID const &);
  ScriptLevelAreaBinderComponent(ITickingArea const &);

  virtual ~ScriptLevelAreaBinderComponent();
  virtual bool serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &) const;
  virtual bool deserialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &);

  static std::string TAG;
  mce::UUID const &getIdentifier() const;
};

class ScriptActorAreaBinderComponent : public ScriptBinderComponent {
  ActorUniqueID id;

public:
  ScriptActorAreaBinderComponent();
  ScriptActorAreaBinderComponent(ActorUniqueID);
  ScriptActorAreaBinderComponent(ITickingArea const &);

  virtual ~ScriptActorAreaBinderComponent();
  virtual bool serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &) const;
  virtual bool deserialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &);

  static std::string TAG;
  ActorUniqueID getIdentifier() const;
};

class ScriptActorUniqueIdBinderComponent : public ScriptBinderComponent {
  ActorUniqueID id;

public:
  ScriptActorUniqueIdBinderComponent();
  ScriptActorUniqueIdBinderComponent(ActorUniqueID);
  ScriptActorUniqueIdBinderComponent(ITickingArea const &);

  virtual ~ScriptActorUniqueIdBinderComponent();
  virtual bool serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &) const;
  virtual bool deserialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &);

  static std::string TAG;
  ActorUniqueID getIdentifier() const;
};

class ScriptLevelBinderComponent : public ScriptBinderComponent {
  unsigned id;

public:
  ScriptLevelBinderComponent();
  ScriptLevelBinderComponent(unsigned);

  virtual ~ScriptLevelBinderComponent();
  virtual bool serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &) const;
  virtual bool deserialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &);

  static std::string TAG;
  unsigned getIdentifier() const;
};


class ScriptItemStackBinderComponent : public ScriptBinderComponent {
  unsigned count, stacksize;
  std::string name;

public:
  ScriptItemStackBinderComponent();

  virtual ~ScriptItemStackBinderComponent();
  virtual bool serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &) const;
  virtual bool deserialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &);

  static std::string TAG;
  unsigned getIdentifier() const;
};