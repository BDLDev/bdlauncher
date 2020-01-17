#include <Loader.h>
#include <MC.h>
#include "cmdhelper.h"
#include "rapidjson/document.h"
#include "base.h"
#include "../money/money.h"
#include <fstream>
#include "main.command.h"

using namespace rapidjson;
extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);
unordered_map<int, std::pair<int, int>> bonus_mp;

void load(CommandOutput *out) {
  Document dc;
  std::ifstream ff;
  FileBuffer fb("config/killbonus.json");
  if (dc.ParseInsitu(fb.data).HasParseError()) {
    do_log("JSON ERROR pos: %ld type: %s!", dc.GetErrorOffset(), GetParseErrorFunc(dc.GetParseError()));
    if (out)
      out->error("Failed to parse json");
    else
      exit(1);
    return;
  }
  for (auto &i : dc.GetArray()) {
    auto bMin     = i["MinMoney"].GetInt();
    auto bMax     = i["MaxMoney"].GetInt();
    auto eid      = i["eid"].GetInt();
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