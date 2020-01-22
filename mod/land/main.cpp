#include <cstdio>
#include <list>
#include <forward_list>
#include <string>
#include <unordered_map>
#include "cmdhelper.h"
#include <vector>
#include <Loader.h>
#include <MC.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../money/money.h"
#include "base.h"
#include <cmath>
#include <deque>
#include <dlfcn.h>
#include <tuple>
#include <minecraft/json.h>
#include <fstream>
#include "../gui/gui.h"
#include "data.hpp"
#include "land.command.h"
const char meta[] __attribute__((used, section("meta"))) =
    "name:land\n"
    "version:20200121\n"
    "author:sysca11\n"
    "depend:base@20200121,command@20200121,gui@20200121,money@20200121\n"
    "prio:1";

using std::deque;
using std::string;
#define dbg_printf(...)                                                                                                \
  {}
//#define dbg_printf printf

extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);
struct LPOS {
  int x, z;
};
static std::unordered_map<string, LPOS> startpos, endpos;
static unordered_map<string, int> choose_state;

int LAND_PRICE, LAND_PRICE2;
static bool land_tip = true;
static void loadcfg() {
  std::ifstream ifs{"config/land.json"};
  Json::Value value;
  Json::Reader reader;
  if (!reader.parse(ifs, value)) {
    auto msg = reader.getFormattedErrorMessages();
    do_log("%s", msg.c_str());
    exit(1);
  }
  LAND_PRICE  = value["buy_price"].asInt(0);
  LAND_PRICE2 = value["sell_price"].asInt(0);
  land_tip    = value["land_tip"].asBool(land_tip);
  if (getenv("NO_LTIP")) land_tip = false;
}
void LDCommand::exit(mandatory<Exit> mode) {
  auto sp = getSP(getOrigin().getEntity());
  if (!sp) return;
  choose_state.erase(sp->getNameTag());
  getOutput().success("§bExit selection mode, please input /land buy");
}
void LDCommand::AB_(mandatory<AB> mode) {
  auto sp = getSP(getOrigin().getEntity());
  if (!sp) return;
  choose_state[sp->getNameTag()] = (mode==AB::b)+1;
  getOutput().success("§bEnter selection mode, please click on the ground to select point");
}
void LDCommand::query(mandatory<Query> mode) {
  auto sp = getSP(getOrigin().getEntity());
  if (!sp) return;
  auto &pos = sp->getPos();
  int dim   = sp->getDimensionId();
  auto lp   = getFastLand(pos.x, pos.z, dim);
  if (lp) {
    char buf[1000];
    snprintf(buf, 1000, "§bThis is %s's land", lp->owner);
    getOutput().success(buf);
  } else {
    getOutput().error("No land here");
    return;
  }
}
void LDCommand::buy(mandatory<Buy> mode) {
  auto sp = getSP(getOrigin().getEntity());
  if (!sp) return;
  SPBuf sb;
  auto op    = sp->getPlayerPermissionLevel() > 1;
  auto &nm   = sp->getName();
  auto &hash = nm;
  int x, z, dx, dz;
  int dim = sp->getDimensionId();
  if (startpos.count(hash) + endpos.count(hash) != 2) {
    getOutput().error("Choose 2 points please.");
    return;
  }
  choose_state.erase(hash);
  x  = std::min(startpos[hash].x, endpos[hash].x);
  z  = std::min(startpos[hash].z, endpos[hash].z);
  dx = std::max(startpos[hash].x, endpos[hash].x);
  dz = std::max(startpos[hash].z, endpos[hash].z);
  // step 1 check money
  int deltax = dx - x + 1, deltaz = dz - z + 1;
  uint siz = deltax * deltaz;
  if (deltax >= 4096 || deltaz >= 4096 || siz >= 5000000) {
    getOutput().error("Too big land");
    return;
  }
  int price = siz * LAND_PRICE;
  if (price <= 0 || price >= 500000000) {
    getOutput().error("Too big land");
    return;
  }
  auto mon = get_money(nm);
  if (mon < price) {
    getOutput().error("Money not enough");
    return;
  }
  // step 2 check coll
  for (int i = x; i <= dx; ++i)
    for (int j = z; j <= dz; ++j) {
      auto lp = getFastLand(i, j, dim);
      if (lp) {
        sb.write("Land collision detected! hint: "sv);
        sb.write(lp->getOwner());
        sb.write("'s land"sv);
        getOutput().error(sb.getstr());
        return;
      }
    }
  // step 3 add land
  set_money(nm, mon - price);
  addLand((x) ^ 0x80000000, (dx) ^ 0x80000000, (z) ^ 0x80000000, (dz) ^ 0x80000000, dim, nm);
  getOutput().success("§bSuccessful land purchase");
}
void LDCommand::sell(mandatory<Sell> mode) {
  auto sp = getSP(getOrigin().getEntity());
  if (!sp) return;
  auto op   = sp->getPlayerPermissionLevel() > 1;
  auto &nm  = sp->getName();
  auto &pos = sp->getPos();
  int dim   = sp->getDimensionId();
  auto lp   = getFastLand(pos.x, pos.z, dim);
  if (lp && (lp->chkOwner(nm) == 2 || op)) {
    int siz = (lp->dx - lp->x) * (lp->dz - lp->z);
    add_money(nm, siz * LAND_PRICE2);
    removeLand(lp);
    getOutput().success("§bYour land has been sold");
  } else {
    getOutput().error("No land here or not your land");
    return;
  }
}

void LDCommand::trust(mandatory<Trust> mode, mandatory<std::string> target) {
  auto sp = getSP(getOrigin().getEntity());
  if (!sp) return;
  auto op   = sp->getPlayerPermissionLevel() > 1;
  auto &nm  = sp->getName();
  auto &pos = sp->getPos();
  int dim   = sp->getDimensionId();
  auto lp   = getFastLand(pos.x, pos.z, dim);
  if (lp && (lp->chkOwner(nm) == 2 || op)) {
    SPBuf sb;
    DataLand dl{*lp};
    dl.addOwner(target);
    updLand(dl);
    sb.write("§bMake ");
    sb.write(target);
    sb.write(" a trusted player");
    getOutput().success(sb.getstr());
  } else {
    getOutput().error("No land here or not your land");
    return;
  }
}
void LDCommand::untrust(mandatory<Untrust> mode, mandatory<std::string> target) {
  auto sp = getSP(getOrigin().getEntity());
  if (!sp) return;
  auto op   = sp->getPlayerPermissionLevel() > 1;
  auto &nm  = sp->getName();
  auto &pos = sp->getPos();
  int dim   = sp->getDimensionId();
  auto lp   = getFastLand(pos.x, pos.z, dim);
  if (lp && (lp->chkOwner(nm) == 2 || op)) {
    SPBuf sb;
    DataLand dl{*lp};
    dl.delOwner(target);
    updLand(dl);
    sb.write("§bMake ");
    sb.write(target);
    sb.write(" a untrusted player");
    getOutput().success(sb.getstr());
  } else {
    getOutput().error("No land here or not your land");
    return;
  }
}
void LDCommand::perm(mandatory<Perm> mode, mandatory<int> perm) {
  auto sp = getSP(getOrigin().getEntity());
  if (!sp) return;
  auto op   = sp->getPlayerPermissionLevel() > 1;
  auto &nm  = sp->getName();
  auto &pos = sp->getPos();
  int dim   = sp->getDimensionId();
  auto lp   = getFastLand(pos.x, pos.z, dim);
  if (lp && (lp->chkOwner(nm) == 2 || op)) {
    DataLand dl{*lp};
    auto pm = (LandPerm) perm;
    if ((pm & PERM_ADMIN_FLY) && !op) {
      getOutput().error("Permission denied");
      return;
    }
    dl.perm = pm;
    updLand(dl);
    getOutput().success("§bChange permissions successfully");
  } else {
    getOutput().error("No land here or not your land");
    return;
  }
}
void LDCommand::give(mandatory<Give>, mandatory<CommandSelector<Player>> target) {
  auto results = target.results(getOrigin());
  if (!Command::checkHasTargets(results, getOutput())) return;
  auto dst = getSP(*results.get());
  auto sp  = getSP(getOrigin().getEntity());
  if (sp && dst) {
    auto &pos = sp->getPos();
    int dim   = sp->getDimensionId();
    auto lp   = getFastLand(pos.x, pos.z, dim);
    if (lp && (lp->chkOwner(sp->getName()) == 2 || sp->getPlayerPermissionLevel() > 1)) {
      DataLand dl{*lp};
      dl.addOwner(dst->getName(), true);
      dl.delOwner(sp->getName());
      updLand(dl);
      sendText(dst, "You get a land from " + sp->getName());
      getOutput().success("§bSuccessfully give your territory to " + dst->getName());
    } else {
      getOutput().error("No land here or not your land");
      return;
    }
  }
}
void LDCommand::trustgui(mandatory<Trustgui>) {
  auto sp = getSP(getOrigin().getEntity());
  if (sp) {
    gui_ChoosePlayer(sp, "Choose players to trust", "Trust", [](ServerPlayer *xx, string_view dest) {
      SPBuf sb;
      sb.write("land trust \"");
      sb.write(dest);
      sb.write("\"");
      runcmdAs(sb.get(), xx);
    });
    getOutput().success();
  } else {
    getOutput().error("Error");
  }
}
void LDCommand::untrustgui(mandatory<Untrustgui>) {
  auto sp = getSP(getOrigin().getEntity());
  if (sp) {
    auto &pos = sp->getPos();
    int dim   = sp->getDimensionId();
    auto lp   = getFastLand(pos.x, pos.z, dim);
    if (lp && (lp->chkOwner(sp->getName()) == 2 || sp->getPlayerPermissionLevel() > 1)) {
      SharedForm *sf = getForm("Untrust a player", "Untrust a player");
      DataLand dl{*lp};
      static_deque<string_view> owners;
      split_string(dl.owner, owners, "||");
      for (auto &i : owners) {
        string_view x;
        if (i[0] == '|') {
          x = i.substr(1);
        } else {
          if (i[i.size() - 1] == '|') {
            x = i.substr(0, i.size() - 1);
          } else {
            x = i;
          }
        }
        sf->addButton(x);
      }
      sf->cb = [](ServerPlayer *sp, string_view c, int idx) {
        SPBuf<512> buf;
        buf.write("land untrust \"");
        buf.write(c);
        buf.write("\"");
        runcmdAs(buf.get(), sp);
      };
      sendForm(*sp, sf);
      getOutput().success();
    } else {
      getOutput().error("Error");
    }
  }
}
void LDOCommand::dumpall(mandatory<Dumpall> mode) {
  iterLands_const([&](const DataLand &dl) {
    char buf[1000];
    snprintf(
        buf, 1000, "owner %s pos %d %d -> %d %d dim %d perm %d", dl.owner.c_str(), dl.x ^ 0x80000000, dl.z ^ 0x80000000,
        dl.dx ^ 0x80000000, dl.dz ^ 0x80000000, dl.dim, dl.perm);
    getOutput().addMessage(buf);
  });
  getOutput().success("okay");
}
void LDOCommand::forceperm(mandatory<Forceperm>, mandatory<int> newperm) {
  iterLands([newperm](DataLand &dl) { dl.perm = (LandPerm) newperm; });
  getOutput().success("okay");
}
void LDOCommand::fix(mandatory<Fix>) {
  db.Del("land_fixed_v3");
  getOutput().success("scheduled data fix at next server start");
}
void LDOCommand::reload(mandatory<Reload>) {
  loadcfg();
  getOutput().success();
}

static void NoticePerm(FastLand *fl, ServerPlayer *sp) {
  SPBuf sb;
  sb.write("§cThis is "sv);
  sb.write(fl->getOwner());
  sb.write("'s land"sv);
  sendText(sp, sb.get(), POPUP);
}
static bool handle_dest(GameMode *a0, BlockPos const *a1) {
  ServerPlayer *sp = a0->getPlayer();
  if (isOp(sp)) return 1;
  int x(a1->x), z(a1->z), dim(sp->getDimensionId());
  FastLand *fl = getFastLand(x, z, dim);
  if (!fl || fl->hasPerm(sp->getName(), PERM_BUILD)) {
    return 1;
  } else {
    NoticePerm(fl, sp);
    return 0;
  }
}
static bool handle_attack(Actor &vi, ActorDamageSource const &src, int &val) {
  if (src.isChildEntitySource() || src.isEntitySource()) {
    auto id          = src.getEntityUniqueID();
    auto ent         = getSrvLevel()->fetchEntity(id, false);
    ServerPlayer *sp = getSP(ent);
    if (!sp || isOp(sp)) return 1;
    auto &pos = vi.getPos();
    int x(pos.x), z(pos.z), dim(vi.getDimensionId());
    FastLand *fl = getFastLand(x, z, dim);
    if (!fl || fl->hasPerm(sp->getName(), PERM_ATK)) {
      return 1;
    } else {
      NoticePerm(fl, sp);
      return 0;
    }
  }
  return 1;
}
static bool handle_inter(GameMode *a0, Actor &a1) {
  ServerPlayer *sp = a0->getPlayer();
  if (isOp(sp)) return 1;
  auto &pos = a1.getPos();
  int x(pos.x), z(pos.z), dim(a1.getDimensionId());
  FastLand *fl = getFastLand(x, z, dim);
  if (!fl || fl->hasPerm(sp->getName(), PERM_INTERWITHACTOR)) {
    return 1;
  } else {
    NoticePerm(fl, sp);
    return 0;
  }
}
static bool handle_useion(GameMode *a0, ItemStack *a1, BlockPos const *a2, BlockPos const *dstPos, Block const *a5) {
  ServerPlayer *sp = a0->getPlayer();
  auto &hash       = sp->getNameTag();
  if (choose_state[hash] != 0) {
    if (choose_state[hash] == 1) {
      startpos[hash] = {a2->x, a2->z};
      sendText(sp, "§bPoint A selected");
    }
    if (choose_state[hash] == 2) {
      endpos[hash] = {a2->x, a2->z};
      char buf[1000];
      auto siz = (abs(startpos[hash].x - endpos[hash].x) + 1) * (abs(startpos[hash].z - endpos[hash].z) + 1);
      snprintf(buf, 1000, "§bPoint B selected,size: %d price: %d", siz, siz * LAND_PRICE);
      sendText(sp, buf);
    }
    return 0;
  }
  if (isOp(sp)) return 1;
  int x(a2->x), z(a2->z), dim(sp->getDimensionId());
  LandPerm pm;
  if (a1->isNull()) {
    pm = PERM_USE;
  } else {
    pm = PERM_BUILD;
  }
  FastLand *fl = getFastLand(x, z, dim), *fl2 = getFastLand(dstPos->x, dstPos->z, dim);
  auto &name = sp->getName();
  if (fl && !fl->hasPerm(name, pm)) {
    NoticePerm(fl, sp);
    return 0;
  }
  if (fl2 && !fl2->hasPerm(name, pm)) {
    NoticePerm(fl2, sp);
    return 0;
  }
  return 1;
}
static bool handle_popitem(ServerPlayer &sp, BlockPos &bpos) {
  if (isOp(&sp)) return 1;
  int x(bpos.x), z(bpos.z), dim(sp.getDimensionId());
  FastLand *fl = getFastLand(x, z, dim);
  if (!fl || fl->hasPerm(sp.getName(), PERM_POPITEM)) {
    return 1;
  } else {
    NoticePerm(fl, &sp);
    return 0;
  }
}

static unordered_map<string, string> lastland;
static unordered_set<string> flying;
THook(void *, _ZN12ServerPlayer9tickWorldERK4Tick, ServerPlayer *sp, unsigned long const *tk) {
  if (!land_tip) return original(sp, tk);
  if (*tk % 16 == 0) {
    auto &plyname = sp->getName();
    auto &oldname = lastland[plyname];
    auto &pos     = sp->getPos();
    int dim       = sp->getDimensionId();
    FastLand *fl  = getFastLand(round(pos.x), round(pos.z), dim);
    string_view newname;
    if (fl) {
      newname = string_view(fl->owner, fl->owner_sz);
      /*if((fl->perm&PERM_ADMIN_FLY) && fl->chkOwner(plyname)){
          if(!flying.count(plyname)){
              flying.insert(plyname);
          }
      }*/
    }
    if (oldname != newname) {
      SPBuf sb;
      if (newname == "") {
        sb.write("You lefted "sv);
        sb.write(string_view(oldname));
        sb.write("'s land!"sv);
      } else {
        sb.write("You entered "sv);
        sb.write(newname);
        sb.write("'s land!"sv);
      }
      sendText(sp, sb.get(), TextType::TIP);
      oldname = newname;
    }
  }
  return original(sp, tk);
}

void mod_init(std::list<string> &modlist) {
  do_log("loaded! " BDL_TAG "");
  loadcfg();
  string dummy;
  if (!db.Get("land_fixed_v3", dummy)) {
    CHECK_AND_FIX_ALL();
    db.Put("land_fixed_v3", dummy);
  }
  register_commands();
  reg_destroy(handle_dest);
  reg_useitemon(handle_useion);
  reg_actorhurt(handle_attack);
  reg_popItem(handle_popitem);
  reg_interact(handle_inter);
  load_helper(modlist);
}
