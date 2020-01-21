#include <Loader.h>
#include <MC.h>
#include "cmdhelper.h"
#include <minecraft/json.h>
#include <fstream>
#include "base.h"
#include "../money/money.h"
#include <fstream>
#include "main.command.h"

const char meta[] __attribute__((used,section(".meta")))="name:kbonus\n"\
"version:20200121\n"\
"author:sysca11\n"\
"depend:base@20200121,command@20200121,money@20200121\n"\
;

extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);
unordered_map<int, std::pair<int, int>> bonus_mp;

void load(CommandOutput *out) {
  std::ifstream ifs{"config/killbonus.json"};
  Json::Value value;
  Json::Reader reader;
  if (!reader.parse(ifs, value)) {
    auto msg = reader.getFormattedErrorMessages();
    do_log("%s", msg.c_str());
    if (out)
      out->error(msg);
    else
      exit(1);
  }
  for (auto &i : value) {
    auto bMin     = i["MinMoney"].asInt(0);
    auto bMax     = i["MaxMoney"].asInt(0);
    auto eid      = i["eid"].asInt(0);
    bonus_mp[eid] = {bMin, bMax};
  }
  if (out) out->success("Reloaded!");
}
static int dbg_die;
static void toggle_dbg(CommandOutput *out) {
  dbg_die = !dbg_die;
  if (out) out->success(std::string("Debug mode ") + (dbg_die ? "on" : "off"));
}
static void handle_die(Mob &a, ActorDamageSource const &b) {
  if (b.isChildEntitySource() || b.isEntitySource()) {
    auto ent         = getSrvLevel()->fetchEntity(b.getEntityUniqueID(), false);
    ServerPlayer *sp = getSP(ent);
    if (sp) {
      auto vid = a.getEntityTypeId();
      if (dbg_die) { sendText(sp, "you killed" + std::to_string(vid)); }
      auto it = bonus_mp.find(vid);
      if (it != bonus_mp.end()) {
        auto mi = it->second.first, mx = it->second.second;
        auto addm = rand() % (mx + 1 - mi) + mi;
        add_money(sp->getName(), addm);
        sendText(sp, "you get $" + std::to_string(addm) + " by killing");
      }
    }
  }
}

void CommandKillbonus::invoke(mandatory<KillbonusMode> mode) {
  auto out = &getOutput();
  switch (mode) {
  case KillbonusMode::Reload: load(out); break;
  case KillbonusMode::Debug: toggle_dbg(out); break;
  default: getOutput().error("Unknown mode"); return;
  }
}

void mod_init(std::list<string> &modlist) {
  load(nullptr);
  register_commands();
  reg_mobdie(handle_die);
  do_log("Loaded " BDL_TAG "");
  load_helper(modlist);
}