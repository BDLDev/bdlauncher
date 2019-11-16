#pragma once

#include "../core/types.h"

#include <functional>
#include <memory>

class CommandContext;
class CommandOutputSender;
class CommandOrigin;
class CommandRegistry;
class CommandOutput;
class Packet;
/*
class MinecraftCommands {
public:
  MCRESULT executeCommand(std::shared_ptr<CommandContext>, bool) const;
  CommandPermissionLevel getOpPermissionLevel() const;
  CommandOutputSender *getOutputSender() const;
  CommandOutputType getOutputType(CommandOrigin const &);
  CommandRegistry const *getRegistry() const;
  CommandRegistry *getRegistry();
  void handleOutput(CommandOrigin const &, CommandOutput const &) const;
  void initCoreEnums(bool);
  void registerChatPermissionsCallback(std::function<bool()>);
  MCRESULT requestCommandExecution(std::unique_ptr<CommandOrigin>, std::string const &, int, bool) const;
  void setOpPermissionLevel(CommandPermissionLevel);
  void setOutputSender(std::unique_ptr<CommandOutputSender>);
  void setRegistryNetworkUpdateCallback(std::function<void(Packet const &)>) const;
};*/