#include "mods.h"
#include "depsolve.h"
void load_helper(std::list<std::string> &modlist) {
  if (modlist.size() == 0) return;
  std::string fplug;
  while (fplug.size() == 0 && !modlist.empty()) {
    const std::string &item = modlist.front();
    fplug                   = (item[item.size() - 1] == '\r') ? item.substr(0, item.size() - 1) : item;
    modlist.pop_front();
  }
  if (fplug.size() == 0) return;
  void *handle = dlopen(fplug.c_str(), RTLD_NOW | RTLD_GLOBAL | RTLD_DEEPBIND);
  if (handle == nullptr) {
    printf("[MOD] err loading %s handle %p %s\n", fplug.c_str(), handle, dlerror());
    exit(1);
  }
  printf("enabling %s\n", fplug.c_str());
  void *init = dlsym(handle, "mod_init");
  if (init == nullptr) {
    printf("[MOD] err loading %s handle %p %s\n", fplug.c_str(), handle, dlerror());
    exit(1);
  }
  ((typeof(&load_helper)) init)(modlist);
}
void mod_loadall() {
  std::list<std::string> modlist;
  modlist=solveAll();
  printf("[MOD] start loading\n");
  for(auto& i:modlist){
    printf("%s\n",i.c_str());
  }
  load_helper(modlist);
}
