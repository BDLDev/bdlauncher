#pragma once

#include "../core/types.h"

#include <string>
#include <vector>
#include <functional>

class CommandOrigin;
class CommandOutput;
class AutomationCmdOutput;

class CommandOutputSender {
  void sendToAdmins(CommandOrigin const &, CommandOutput const &, CommandPermissionLevel);
  std::vector<std::string> translate(std::vector<std::string> const &);

  virtual ~CommandOutputSender();
  virtual void send(CommandOrigin const &, CommandOutput const &);
  virtual void registerOutputCallback(std::function<void(AutomationCmdOutput &)> const &);
};