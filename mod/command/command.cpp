#include "command.h"
#include <Loader.h>
#include <list>
#include <cstring>

const char meta[] __attribute__((used, section("meta"))) =
    "name:command\n"
    "version:20200121\n"
    "author:BDLDev\n"
    "depend:base@20200121\n"
    "prio:1";

namespace BDL::CustomCommand {

BDL_EXPORT CustomCommandRegistry &CustomCommandRegistry::getInstance() {
  static CustomCommandRegistry registry;
  return registry;
}

THook(void *, _ZN9XPCommand5setupER15CommandRegistry, CommandRegistry &thi) {
  auto &instance = CustomCommandRegistry::getInstance();
  instance.startRegister(&thi);
  return original(thi);
}

} // namespace BDL::CustomCommand

extern void load_helper(std::list<std::string> &modlist);
extern "C" {
BDL_EXPORT void mod_init(std::list<std::string> &modlist) { load_helper(modlist); }
}