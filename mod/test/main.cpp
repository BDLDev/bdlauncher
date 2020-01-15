#include <logger.h>
#include <Loader.h>
#include "../command/command.h"


extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}

extern void load_helper(std::list<string> &modlist);

class TestCommand : public BDL::CustomCommand::CustomCommandContext {
public:
  static constexpr auto name = "test";
  static constexpr auto description = "test command";
  static constexpr auto permission = (CommandPermissionLevel) 0;

  TestCommand(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void impl() {
    do_log("test");
  }
};

class TestImpl : public Command {
public:
  virtual void execute(CommandOrigin const &origin, CommandOutput &output) {
    TestCommand ctx {origin, output};
    ctx.impl();
  }
};

void mod_init(std::list<string> &modlist) {
  auto &instance = BDL::CustomCommand::CustomCommandRegistry::getInstance();
  auto &cmd = instance.registerCommand<TestCommand>();
  cmd.registerOverload<TestImpl>();
  load_helper(modlist);
}