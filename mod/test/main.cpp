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

struct TestImpl : Command {
  BDL::CustomCommand::CommandParameterProxy<int> num;
  BDL::CustomCommand::CommandParameterProxy<float> flo;
  BDL::CustomCommand::CommandParameterProxy<bool> flag;
  virtual void execute(CommandOrigin const &origin, CommandOutput &output) {
    TestCommand ctx{origin, output};
    ctx.impl(num, flo, flag);
  }
};

void mod_init(std::list<string> &modlist) {
  auto &instance = BDL::CustomCommand::CustomCommandRegistry::getInstance();
  auto &cmd      = instance.registerCommand<TestCommand>();
  auto &cmdovl   = cmd.registerOverload<TestImpl>();
  cmdovl.addParameter<int>("num", false, offsetof(TestImpl, num));
  cmdovl.addParameter<float>("float", false, offsetof(TestImpl, flo));
  cmdovl.addParameter<bool>("flag", false, offsetof(TestImpl, flag));
  load_helper(modlist);
}