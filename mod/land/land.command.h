#include "../command/command.h"
#include "../command/parameter.h"

using namespace BDL::CustomCommand;

command_register_function register_commands();

enum class Exit { exit };
enum class AB { a, b };
enum class Query { query };
enum class Buy { buy };
enum class Sell { sell };
enum class Trust { trust };
enum class Untrust { untrust };
enum class Trustgui { trustgui };
enum class Untrustgui { untrustgui };
enum class Perm { perm };
enum class Give { give };

struct LDCommand : CustomCommandContext {
public:
  inline static alias_list aliases  = {"ld"};
  static constexpr auto name        = "land";
  static constexpr auto description = "Land functions";
  static constexpr auto permission  = CommandPermissionLevel::NORMAL;

  LDCommand(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void exit(mandatory<Exit> mode);
  void AB_(mandatory<AB> mode);
  void query(mandatory<Query> mode);
  void buy(mandatory<Buy> mode);
  void sell(mandatory<Sell> mode);
  void trust(mandatory<Trust> mode, mandatory<std::string> target);
  void untrust(mandatory<Untrust> mode, mandatory<std::string> target);
  void trustgui(mandatory<Trustgui> mode);
  void untrustgui(mandatory<Untrustgui> mode);
  void perm(mandatory<Perm> mode, mandatory<int> perm);
  void give(mandatory<Give> mode, mandatory<CommandSelector<Player>> target);
};

// op
enum class Forceperm { forceperm };
enum class Dumpall { dumpall };
enum class Fix { fix };
enum class Reload { reload };
struct LDOCommand : CustomCommandContext {
public:
  // inline static alias_list aliases  = {"ld"};
  static constexpr auto name        = "land_op";
  static constexpr auto description = "Land functions";
  static constexpr auto permission  = CommandPermissionLevel::OP;

  LDOCommand(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void fix(mandatory<Fix> mode);
  void forceperm(mandatory<Forceperm> mode, mandatory<int> perm);
  void dumpall(mandatory<Dumpall> mode);
  void reload(mandatory<Reload> mode);
};