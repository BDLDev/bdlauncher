#include "../command/command.h"
#include "../command/parameter.h"

using namespace BDL::CustomCommand;

class TestCommand : public CustomCommandContext {
public:
  static constexpr auto cmd_name    = "test";
  static constexpr auto description = "test command";
  static constexpr auto permission  = CommandPermissionLevel::NORMAL;

  TestCommand(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void impl(mandatory<int> num, mandatory<float> flo, mandatory<bool> flag) { do_log("test %d %f %d", num, flo, flag); }
};

class Test2Command : public CustomCommandContext {
public:
  static constexpr auto cmd_name    = "test2";
  static constexpr auto description = "test command2";
  static constexpr auto permission  = CommandPermissionLevel::NORMAL;

  Test2Command(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void impl(mandatory<AutomaticID<Dimension, int>> did) { do_log("test -%d", did.value()); }
  void impl(mandatory<std::string> str) { do_log("test %s", str.c_str()); }
};

enum class TestEnum : int { A, B, C };

class TestDynEnum : public CustomDynEnum<TestDynEnum> {
public:
  static constexpr auto name              = "TestDynEnum";
  inline static enum_initial_list initial = {"x", "y", "z"};
  TestDynEnum() : CustomDynEnum("") {}
  TestDynEnum(std::string const &value) : CustomDynEnum(value) {}
};

class Test3Command : public CustomCommandContext {
public:
  static constexpr auto cmd_name    = "test3";
  static constexpr auto description = "test command3";
  static constexpr auto permission  = CommandPermissionLevel::NORMAL;

  Test3Command(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void impl(mandatory<TestEnum> en) { do_log("%d", (int) en); }
  void impl(mandatory<int> v, mandatory<TestDynEnum> en) { do_log("> %d [%s]", v, en.c_str()); }
};

class TestSelectorCommand : public CustomCommandContext {
public:
  static constexpr auto cmd_name    = "test-select";
  static constexpr auto description = "Test selector";
  static constexpr auto permission  = CommandPermissionLevel::NORMAL;

  TestSelectorCommand(CommandOrigin const &origin, CommandOutput &output) noexcept
      : CustomCommandContext(origin, output) {}

  void impl(mandatory<CommandSelector<Actor>> selector) {
    auto result = selector.results(getOrigin());
    for (auto &pact : result) do_log("%p %p", &pact, getSP(pact));
    do_log("done");
  }
};

class TestJsonCommand : public CustomCommandContext {
public:
  inline static alias_list aliases  = {"json"};
  static constexpr auto cmd_name    = "test-json";
  static constexpr auto description = "Test json";
  static constexpr auto permission  = CommandPermissionLevel::NORMAL;

  TestJsonCommand(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void impl(mandatory<Json::Value> value, mandatory<RelativeFloat> rf) {
    Json::FastWriter writer;
    auto data = writer.write(value);
    do_log("json: %s", data.c_str());
    do_log("rf: %f", rf.getValue(30.f));
  }
};

command_register_function register_commands();