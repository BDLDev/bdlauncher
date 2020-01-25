#include "../command/command.h"
#include "../command/parameter.h"

using namespace BDL::CustomCommand;

command_register_function register_commands();

enum class Show { show };
enum class Hide { hide };
enum class Pin { pin };
enum class Unpin { unpin };

struct BossbarCommand : CustomCommandContext {
public:
  inline static alias_list aliases  = {"bb"};
  static constexpr auto cmd_name    = "bossbar";
  static constexpr auto description = "Bossbar operation";
  static constexpr auto permission  = CommandPermissionLevel::OP;

  BossbarCommand(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void show(mandatory<Show> mode, mandatory<CommandSelector<Player>> targets, mandatory<std::string> text);
  void hide(mandatory<Hide> mode, mandatory<CommandSelector<Player>> targets);
  void pin(mandatory<Pin> mode, mandatory<std::string> text);
  void unpin(mandatory<Unpin> mode);
};
