#include "../command/command.h"
#include "../command/parameter.h"
#include <vector>

using namespace BDL::CustomCommand;

class TestCommand : public CustomCommandContext {
public:
  static constexpr auto name        = "test";
  static constexpr auto description = "test command";
  static constexpr auto permission  = (CommandPermissionLevel) 0;

  TestCommand(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void impl(mandatory<int> num, mandatory<float> flo, mandatory<bool> flag) { do_log("test %d %f %d", num, flo, flag); }
};

class Test2Command : public CustomCommandContext {
public:
  static constexpr auto name        = "test2";
  static constexpr auto description = "test command2";
  static constexpr auto permission  = (CommandPermissionLevel) 0;

  Test2Command(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void impl(mandatory<AutomaticID<Dimension, int>> did) { do_log("test -%d", did.value()); }
  void impl(mandatory<std::string> str) { do_log("test %s", str.c_str()); }
};

enum class TestEnum : int { A, B, C };

class TestDynEnum : public CustomDynEnum<TestDynEnum> {
public:
  static constexpr auto name                     = "TestDynEnum";
  inline static std::vector<std::string> initial = {"x", "y", "z"};
  TestDynEnum() : CustomDynEnum("") {}
  TestDynEnum(std::string const &value) : CustomDynEnum(value) {}
};

class Test3Command : public CustomCommandContext {
public:
  static constexpr auto name        = "test3";
  static constexpr auto description = "test command3";
  static constexpr auto permission  = (CommandPermissionLevel) 0;

  Test3Command(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void impl(mandatory<TestEnum> en) { do_log("%d", (int) en); }
  void impl(mandatory<int> v, mandatory<TestDynEnum> en) { do_log("> %d [%s]", v, en.c_str()); }
};

command_register_function register_commands();