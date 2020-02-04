#include <logger.h>
#include <Loader.h>
#include "main.command.h"
#include <list>
#include <string>

const char meta[] __attribute__((used, section("meta"))) =
    "name:test\n"
    "version:20200121\n"
    "author:BDLDev\n"
    "depend:base@20200121,command@20200121\n";

extern "C" {
BDL_EXPORT void mod_init(std::list<std::string> &modlist);
}

extern void load_helper(std::list<std::string> &modlist);

void mod_init(std::list<std::string> &modlist) {
  register_commands();
  load_helper(modlist);
}