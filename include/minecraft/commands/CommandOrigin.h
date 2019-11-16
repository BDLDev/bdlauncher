#pragma once

#include "../core/UUID.h"
#include "../core/types.h"
#include "../json.h"
#include "../net/NetworkIdentifier.h"

#include <memory>
#include <string>

class Level;
class Dimension;
enum struct AbilitiesIndex : int;
enum class OriginType : char {
  Player           = 0,
  Block            = 1,
  MinecartBlock    = 2,
  DevConsole       = 3,
  Test             = 4,
  AutomationPlayer = 5,
  ClientAutomation = 6,
  DedicatedServer  = 7,
  Actor            = 8,
  Virtual          = 9,
  GameArgument     = 10,
  ActorServer      = 11
};

class CommandOriginData;

class CommandOrigin {
  mce::UUID uuid;

public:
  virtual ~CommandOrigin();
  virtual std::string getRequestId() const                   = 0;
  virtual std::string getName() const                        = 0;
  virtual BlockPos getBlockPosition() const                  = 0;
  virtual Vec3 getWorldPosition() const                      = 0;
  virtual Level *getLevel() const                            = 0;
  virtual Dimension *getDimension() const                    = 0;
  virtual Actor *getEntity() const                           = 0;
  virtual CommandPermissionLevel getPermissionsLevel() const = 0;
  virtual std::unique_ptr<CommandOrigin> clone() const       = 0;
  virtual bool canCallHiddenCommands() const;
  virtual bool hasChatPerms() const;
  virtual bool hasTellPerms() const;
  virtual bool canUseAbility(AbilitiesIndex) const;
  virtual bool isWorldBuilder() const;
  virtual bool canUseCommandsWithoutCheatsEnabled() const;
  virtual bool isSelectorExpansionAllowed() const;
  virtual NetworkIdentifier getSourceId() const;
  virtual char getSourceSubId() const;
  virtual CommandOrigin *getOutputReceiver() const;
  virtual OriginType getOriginType() const = 0;
  virtual mce::UUID const &getUUID() const;
  virtual CommandOriginData toCommandOriginData() const;
  virtual void handleCommandOutputCallback(Json::Value &&);
  virtual void _setUUID(mce::UUID const &);
};

class ServerLevel;
class ScriptEngine;
class ServerCommandOrigin : public CommandOrigin {
	char filler[72];
	public:
	ServerCommandOrigin(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, ServerLevel&, CommandPermissionLevel);
	virtual ~ServerCommandOrigin();
  virtual std::string getRequestId() const;
  virtual std::string getName() const;
  virtual BlockPos getBlockPosition() const;
  virtual Vec3 getWorldPosition() const;
  virtual Level *getLevel() const;
  virtual Dimension *getDimension() const;
  virtual Actor *getEntity() const;
  virtual CommandPermissionLevel getPermissionsLevel() const;
  virtual std::unique_ptr<CommandOrigin> clone() const;
  virtual bool canUseCommandsWithoutCheatsEnabled() const;
  virtual bool isSelectorExpansionAllowed() const;
  virtual OriginType getOriginType() const;
  virtual void handleCommandOutputCallback(Json::Value &&);

};

class ScriptCommandOrigin : public CommandOrigin {
  ServerLevel *level;
  bool flag;
  unsigned int requestId;
  ScriptEngine *engine;

public:
  ScriptCommandOrigin(ServerLevel &, ScriptEngine &);
  ScriptCommandOrigin(ServerLevel &, ScriptEngine &, unsigned int);
  virtual ~ScriptCommandOrigin();
  virtual std::string getRequestId() const;
  virtual std::string getName() const;
  virtual BlockPos getBlockPosition() const;
  virtual Vec3 getWorldPosition() const;
  virtual Level *getLevel() const;
  virtual Dimension *getDimension() const;
  virtual Actor *getEntity() const;
  virtual CommandPermissionLevel getPermissionsLevel() const;
  virtual std::unique_ptr<CommandOrigin> clone() const;
  virtual bool canUseCommandsWithoutCheatsEnabled() const;
  virtual bool isSelectorExpansionAllowed() const;
  virtual OriginType getOriginType() const;
  virtual void handleCommandOutputCallback(Json::Value &&);
};
