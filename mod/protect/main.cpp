#include <Loader.h>
//#include <MC.h>
#include "cmdhelper.h"
#include "base.h"
#include <fstream>
#include "seral.hpp"
#include <minecraft/json.h>

const char meta[] __attribute__((used, section("meta"))) =
    "name:wprotect\n"
    "version:20200121\n"
    "author:sysca11\n"
    "depend:base@20200121";

extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);
int NoEnderPick, NoExplodeBreak, NoFarm;
void load() {
  std::ifstream ifs{"config/protect.json"};
  Json::Reader reader;
  Json::Value value;
  if (!reader.parse(ifs, value)) {
    auto msg = reader.getFormattedErrorMessages();
    do_log("%s", msg.c_str());
    exit(1);
  }
  NoEnderPick    = value["NoEnderPick"].asBool(false);
  NoExplodeBreak = value["NoExplodeBreak"].asBool(false);
  NoFarm         = value["NoFarm"].asBool(false);
}
void *dummy() { return nullptr; }
struct Explosion {
  void setFire(bool);
  void setBreaking(bool);
};
THook(void *, _ZN9Explosion7explodeEv, Explosion *thi) {
  if (NoExplodeBreak) {
    thi->setBreaking(false);
    thi->setFire(false);
  }
  return original(thi);
}
void mod_init(std::list<string> &modlist) {
  load();
#define getfn(x) fp(dlsym(NULL, x))
  if (NoEnderPick) { MyHook(getfn("_ZN21EndermanTakeBlockGoal6canUseEv"), fp(dummy)); }
  if (NoFarm) { MyHook(getfn("_ZNK9FarmBlock15transformOnFallER11BlockSourceRK8BlockPosP5Actorf"), fp(dummy)); }
  do_log("Loaded " BDL_TAG "");
  load_helper(modlist);
}