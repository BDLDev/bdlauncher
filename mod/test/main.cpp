#include <logger.h>
#include <Loader.h>
#include "main.command.h"

extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}

extern void load_helper(std::list<string> &modlist);

void mod_init(std::list<string> &modlist) {
  register_commands();
  load_helper(modlist);
}