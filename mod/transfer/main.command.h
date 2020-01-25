#include "../command/command.h"
#include "../command/parameter.h"

using namespace BDL::CustomCommand;

class TransferCommand : public CustomCommandContext {
public:
  static constexpr auto cmd_name    = "transfer";
  static constexpr auto description = "Transfer you to server";
  static constexpr auto permission  = CommandPermissionLevel::NORMAL;

  TransferCommand(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void invoke(mandatory<std::string> server, mandatory<int> port);
};

command_register_function register_commands();
