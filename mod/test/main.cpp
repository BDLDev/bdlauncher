#include <logger.h>
#include <Loader.h>
#include "../command/command.h"
#include "../command/parameter.h"

extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}

extern void load_helper(std::list<string> &modlist);

class TestCommand : public BDL::CustomCommand::CustomCommandContext {
public:
  static constexpr auto name        = "test";
  static constexpr auto description = "test command";
  static constexpr auto permission  = (CommandPermissionLevel) 0;

  TestCommand(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void impl(int num, float flo, bool flag) { do_log("test %d %f %d", num, flo, flag); }
};

class Test2Command : public BDL::CustomCommand::CustomCommandContext {
public:
  static constexpr auto name        = "test2";
  static constexpr auto description = "test command2";
  static constexpr auto permission  = (CommandPermissionLevel) 0;

  Test2Command(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void impl(AutomaticID<Dimension, int> did) { do_log("test -%d", did.value()); }
  void impl(std::string const &str) { do_log("test %s", str.c_str()); }
};

enum class TestEnum : int { A, B, C };

class Test3Command : public BDL::CustomCommand::CustomCommandContext {
public:
  static constexpr auto name        = "test3";
  static constexpr auto description = "test command3";
  static constexpr auto permission  = (CommandPermissionLevel) 0;

  Test3Command(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void impl(TestEnum en) { do_log("%d", (int) en); }
};

template <> class BDL::CustomCommand::CommandParameterProxy<TestEnum> {
  TestEnum value;

public:
  inline static typeid_t<CommandRegistry> fetch_tid() { return type_id<CommandRegistry, TestEnum>(); }
  inline static constexpr CommandParameterData::ParseFn parser = &CommandRegistry::fake_parse;
  inline static constexpr CommandParameterDataType type        = CommandParameterDataType::NORMAL;
  inline static constexpr char const *enum_name                = "TestEnum";
  operator TestEnum() const { return value; }
};

struct TestImpl : Command {
  BDL::CustomCommand::CommandParameterProxy<int> num;
  BDL::CustomCommand::CommandParameterProxy<float> flo;
  BDL::CustomCommand::CommandParameterProxy<bool> flag;
  virtual void execute(CommandOrigin const &origin, CommandOutput &output) {
    TestCommand ctx{origin, output};
    ctx.impl(num, flo, flag);
  }
};

struct Test2Impl : Command {
  BDL::CustomCommand::CommandParameterProxy<AutomaticID<Dimension, int>> did;
  virtual void execute(CommandOrigin const &origin, CommandOutput &output) {
    Test2Command ctx{origin, output};
    ctx.impl(did);
  }
};
struct Test2ImplStr : Command {
  BDL::CustomCommand::CommandParameterProxy<std::string> str;
  virtual void execute(CommandOrigin const &origin, CommandOutput &output) {
    Test2Command ctx{origin, output};
    ctx.impl(str);
  }
};

struct Test3Impl : Command {
  BDL::CustomCommand::CommandParameterProxy<TestEnum> en;
  virtual void execute(CommandOrigin const &origin, CommandOutput &output) {
    Test3Command ctx{origin, output};
    ctx.impl(en);
  }
};

void mod_init(std::list<string> &modlist) {
  auto &instance = BDL::CustomCommand::CustomCommandRegistry::getInstance();
  {
    auto &cmd    = instance.registerCommand<TestCommand>();
    auto &cmdovl = cmd.registerOverload<TestImpl>();
    cmdovl.addParameter<int>("num", false, offsetof(TestImpl, num));
    cmdovl.addParameter<float>("float", false, offsetof(TestImpl, flo));
    cmdovl.addParameter<bool>("flag", false, offsetof(TestImpl, flag));
  }
  {
    auto &cmd = instance.registerCommand<Test2Command>();
    {
      auto &cmdovl = cmd.registerOverload<Test2ImplStr>();
      cmdovl.addParameter<std::string>("str", false, offsetof(Test2ImplStr, str));
    }
    {
      auto &cmdovl = cmd.registerOverload<Test2Impl>();
      cmdovl.addParameter<AutomaticID<Dimension, int>>("dim", false, offsetof(Test2Impl, did));
    }
  }
  {
    auto &enu = instance.registerEnum<TestEnum>();
    enu.addValue("a", TestEnum::A);
    enu.addValue("b", TestEnum::B);
    enu.addValue("c", TestEnum::C);
  }
  {
    auto &cmd    = instance.registerCommand<Test3Command>();
    auto &cmdovl = cmd.registerOverload<Test3Impl>();
    cmdovl.addParameter<TestEnum>("en", false, offsetof(Test3Impl, en));
  }
  load_helper(modlist);
}