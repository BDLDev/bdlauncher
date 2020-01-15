#include "command.h"
#include <Loader.h>

namespace BDL::CustomCommand {

BDL_EXPORT CustomCommandRegistry &CustomCommandRegistry::getInstance() {
  static CustomCommandRegistry registry;
  return registry;
}

THook(void *, _ZN11ListCommand5setupER15CommandRegistry, CommandRegistry &thi) {
  auto &instance = BDL::CustomCommand::CustomCommandRegistry::getInstance();
  instance.startRegister(&thi);
  return original(thi);
}

} // namespace BDL::CustomCommand

extern void load_helper(std::list<string> &modlist);
extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist) { load_helper(modlist); }
}