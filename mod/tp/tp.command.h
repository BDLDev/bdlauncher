#include "../command/command.h"
#include "../command/parameter.h"

using namespace BDL::CustomCommand;

command_register_function register_commands();
enum class TPCMD{cancel,ac,de,gui,f,t};
class TPACommand : public CustomCommandContext {
public:
  //inline static alias_list aliases  = {"tpa"};
  static constexpr auto name        = "tpa";
  static constexpr auto description = "tpa";
  static constexpr auto permission  = CommandPermissionLevel::NORMAL;

  TPACommand(CommandOrigin const &origin, CommandOutput &output) noexcept
      : CustomCommandContext(origin, output) {}

  void invoke(mandatory<TPCMD> mode,optional<std::string> target);
};