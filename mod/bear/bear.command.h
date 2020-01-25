#include "../command/command.h"
#include "../command/parameter.h"

using namespace BDL::CustomCommand;

command_register_function register_commands();

enum class Ban { ban };
enum class Unban { unban };
enum class Invchk { invchk };
enum class Reload { reload };
enum class Kick { kick };
enum class Mute { mute };
enum class Bangui { bangui };

struct ACCommand : CustomCommandContext {
public:
  inline static alias_list aliases  = {"bear"};
  static constexpr auto cmd_name        = "ac";
  static constexpr auto description = "AntiCheat functions";
  static constexpr auto permission  = CommandPermissionLevel::OP;

  ACCommand(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void ban(mandatory<Ban> mode, mandatory<std::string> target, optional<int> time);
  void unban(mandatory<Unban> mode, mandatory<std::string> target);
  void invchk(mandatory<Invchk> mode, mandatory<CommandSelector<Player>> target);
  void reload(mandatory<Reload> mode);
  void kick(mandatory<Kick> mode, mandatory<std::string> target);
  void mute(mandatory<Mute> mode, mandatory<CommandSelector<Player>> target, mandatory<int> time);
  void bangui(mandatory<Bangui> mode);
};