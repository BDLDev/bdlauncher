#include "../command/command.h"
#include "../command/parameter.h"

using namespace BDL::CustomCommand;

command_register_function register_commands();

enum class KillbonusMode { Reload, Debug };

class CommandKillbonus : public CustomCommandContext {
public:
  inline static alias_list aliases  = {"kbonus"};
  static constexpr auto cmd_name    = "killbonus";
  static constexpr auto description = "Kill bonus operation";
  static constexpr auto permission  = CommandPermissionLevel::OP;

  CommandKillbonus(CommandOrigin const &origin, CommandOutput &output) noexcept
      : CustomCommandContext(origin, output) {}

  void invoke(mandatory<KillbonusMode> mode);
};