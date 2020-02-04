#include <Loader.h>
//#include <MC.h>
#include "base.h"
#include <minecraft/json.h>
#include "../money/money.h"
#include <fstream>
#include <list>
#include <sys/stat.h>
#include <minecraft/block/BlockActor.h>
#include <minecraft/block/BlockPos.h>
#include <minecraft/core/GameMode.h>
#include <minecraft/actor/InventorySource.h>
#include <minecraft/actor/InventoryAction.h>
#include <minecraft/item/ItemStack.h>

const char meta[] __attribute__((used, section("meta"))) =
    "name:chestshop\n"
    "version:20200121\n"
    "author:sysca11\n"
    "depend:base@20200121,command@20200121,money@20200121\n";

using namespace std;

extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);
static void r_save();
struct Slot {
  string owner;
  int price; // 0 means no owner
  Slot() { price = 0; }
  Slot(string a, int b) { owner = a, price = b; }
};
struct Chest {
  Slot slots[27];
  int x, y, z;
  int get_price(int slot) { return slots[slot].price; }
  bool do_buy(const string &ply, int slot) {
    if (slot >= 27) return false;
    if (slots[slot].price == 0) return false;
    int price = slots[slot].price;
    if (red_money(ply, price)) {
      add_money(slots[slot].owner, price);
      slots[slot].price = 0;
      slots[slot].owner = ply;
      r_save();
      return true;
    } else {
      return false;
    }
  }
  bool do_add(const string &ply, int price, int slot) {
    if (slot >= 27) return false;
    if (get_price(slot)) return false;
    slots[slot].owner = ply;
    slots[slot].price = price;
    r_save();
    return true;
  }
};
list<Chest> lc;
static void r_save() {
  using namespace Json;
  Value value{ValueType::arrayValue};
  for (auto &i : lc) {
    Value vv{ValueType::objectValue};
    vv["x"] = i.x;
    vv["y"] = i.y;
    vv["z"] = i.z;
    Value va{ValueType::arrayValue};
    for (int j = 0; j < 27; ++j) {
      Value vs(ValueType::arrayValue);
      Value vss(i.slots[j].owner);
      vs.append({i.slots[j].owner});
      vs.append({i.slots[j].price});
      va.append(vs);
    }
    vv["slots"] = va;
    value.append(vv);
  }
  FastWriter writer;
  auto data = writer.write(value);
  ofstream ff{"data/chestshop.json", ios::trunc | ios::out};
  ff << data;
  ff.close();
}
char buf[1024 * 1024 * 16];
static void load() {
  struct stat buf;
  if (stat("config/chestshop.json", &buf) != 0) {
    int fd                         = open("config/chestshop.json", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    static const char empty_json[] = "[]";
    write(fd, empty_json, strlen(empty_json));
    close(fd);
  }
  std::ifstream ifs{"config/chestshop.json"};
  Json::Value value;
  Json::Reader reader;
  if (!reader.parse(ifs, value)) {
    auto msg = reader.getFormattedErrorMessages();
    do_log("%s", msg.c_str());
    exit(1);
  }
  for (auto &i : value) {
    Chest ch;
    ch.x   = i["x"].asInt(0);
    ch.y   = i["y"].asInt(0);
    ch.z   = i["z"].asInt(0);
    int ct = 0;
    for (auto &j : i["slots"]) ch.slots[ct++] = Slot(j[0].asString(""), j[1].asInt(0));
    lc.emplace_back(ch);
  }
}

unordered_map<string, int> ply_select;
unordered_map<string, int> ply_price;
unordered_map<string, Chest *> sessions;
unordered_map<string, Chest *> last_sess;

Chest *fetchChest(int x, int y, int z) {
  for (auto &i : lc) {
    if (i.x == x && i.y == y && i.z == z) return &i;
  }
  return nullptr;
}
THook(void *, _ZN15ChestBlockActor8stopOpenER6Player, BlockActor &ac, Player &pl) {
  auto &pos  = ac.getPosition();
  Chest *gch = fetchChest(pos.x, pos.y, pos.z);
  if (gch) {
    sessions.erase(pl.getNameTag());
    last_sess.emplace(pl.getNameTag(), gch);
  }
  return original(ac, pl);
}
THook(void *, _ZN15ChestBlockActor9startOpenER6Player, BlockActor &ac, Player &pl) {
  auto &pos = ac.getPosition();
  // do_log("start pos %d %d %d",pos.x,pos.y,pos.z);
  Chest *gch = fetchChest(pos.x, pos.y, pos.z);
  if (gch) { sessions.emplace(pl.getNameTag(), gch); }
  return original(ac, pl);
}
THook(unsigned long, _ZNK20InventoryTransaction11executeFullER6Playerb, void *_thi, Player &player, bool b) {
  const string &name = player.getNameTag();
  auto it            = sessions.find(name);
  if (it == sessions.end()) return original(_thi, player, b);
  auto chest  = it->second;
  auto &a     = *((unordered_map<InventorySource, vector<InventoryAction>> *) _thi);
  int IIDs    = -1;
  int pushcnt = 0, pullcnt = 0;
  int lastslot;
  string pullstr;
  for (auto &i : a) {
    for (auto &j : i.second) {
      auto cid = j.getSource().getContainerId();
      if (cid != 0) {
        if (IIDs == -1) {
          IIDs = cid;
        } else {
          if (IIDs != cid) {
            sendText(&player, "invlaid operation");
            return 6;
          }
        }
      }
      auto fit  = j.getFromItem();
      auto tit  = j.getToItem();
      auto slot = j.getSlot();
      if (cid != 0) {
        // chest oper
        if (fit->isNull() && !tit->isNull()) {
          // push item
          pushcnt++;
          lastslot = slot;
        } else {
          if (!fit->isNull() && tit->isNull()) {
            // pull item
            pullcnt++;
            lastslot = slot;
            pullstr  = fit->toString();
          } else {
            // invlaid
            sendText(&player, "invlaid operation");
            return 6;
          }
        }
      }
      // printf("cid %d flg %d src %d slot %u get %d %s
      // %s\n",j.getSource().getContainerId(),j.getSource().getFlags(),j.getSource().getType(),j.getSlot(),i.first.getContainerId(),j.getFromItem()->toString().c_str(),j.getToItem()->toString().c_str());
    }
  }
  if ((pushcnt + pullcnt) != 1 || lastslot < 0 || lastslot > 26) {
    sendText(&player, "invlaid operation");
    return 6;
  }
  if (pushcnt) {
    auto it = ply_price.find(name);
    if (it == ply_price.end()) {
      sendText(&player, "invlaid operation");
      return 6;
    }
    int price = it->second;
    ply_price.erase(it);
    if (price <= 0) return 6;
    if (chest->slots[lastslot].owner != "") {
      sendText(&player, "this slot owned by " + name);
      return 6;
    }
    chest->slots[lastslot] = Slot(name, price);
    r_save();
    return original(_thi, player, b);
  }
  if (pullcnt) {
    auto &x = chest->slots[lastslot];
    if (x.price == 0) {
      // no owner bought slot
      if (x.owner != name) {
        sendText(&player, "not your slot");
        return 6;
      } else {
        x.owner = ""; // release slot
        r_save();
        return original(_thi, player, b);
      }
    }
    char buf[1000];
    sprintf(buf, "item %s by %s price %d,use /cshop buy to buy it", pullstr.c_str(), x.owner.c_str(), x.price);
    sendText(&player, buf);
    ply_select[name] = lastslot; // buy
    return 6;
  }
  return original(_thi, player, b);
  /*
  cid 5 flg 0 src 0 slot 0 get 5 64 x Chest(54)@0 0 x (0)@0
cid 0 flg 0 src 0 slot 8 get 0 0 x (0)@0 64 x Chest(54)@0
cid 0 flg 0 src 0 slot 8 get 0 64 x Chest(54)@0 0 x (0)@0
cid 5 flg 0 src 0 slot 26 get 5 0 x (0)@0 64 x Chest(54)@0
cid 5 flg 0 src 0 slot 26 get 5 64 x Chest(54)@0 0 x (0)@0
cid 5 flg 0 src 0 slot 14 get 5 0 x (0)@0 64 x Chest(54)@0
cid 5 flg 0 src 0 slot 14 get 5 64 x Chest(54)@0 0 x (0)@0
cid 0 flg 0 src 0 slot 2 get 0 0 x (0)@0 64 x Chest(54)@0
*/
}

static void oncmd(argVec &a, CommandOrigin const &b, CommandOutput &outp) {
  ARGSZ(1)
  auto name = b.getName();
  if (a[0] == "buy") {
    if (!ply_select.count(name) || sessions.count(name) || !last_sess.count(name)) {
      outp.error("not selected");
      return;
    }
    if (last_sess[name]->do_buy(name, ply_select[name])) {
      outp.success("ok");
      ply_select.erase(name);
      return;
    } else {
      outp.error("failed");
      ply_select.erase(name);
      return;
    }
  }
  if (a[0] == "sell") {
    ARGSZ(2)
    int price = atoi(a[1]);
    if (price <= 0) {
      outp.error("money must >0");
      return;
    }
    ply_price.emplace(b.getName(), price);
    outp.success();
  }
  if (a[0] == "set") {
    if ((int) b.getPermissionsLevel() < 1) return;
    ply_price.emplace(b.getName(), -114514); // flag for select chest
  }
}
static bool handle_u(GameMode *a0, ItemStack *a1, BlockPos const *a2, BlockPos const *dstPos, Block const *a5) {
  auto nm          = a0->getPlayer()->getNameTag();
  auto it          = ply_price.find(nm);
  ServerPlayer *sp = dynamic_cast<ServerPlayer*>(a0->getPlayer());
  if (it == ply_price.end()) return 1;
  int state = it->second;
  if (state == -114514) {
    Chest ch;
    ch.x = a2->x;
    ch.y = a2->y;
    ch.z = a2->z;
    lc.emplace_back(ch);
    r_save();
    sendText(sp, "okay!add shop chest");
    ply_price.erase(it);
    return 0;
  }
  return 1;
}
void mod_init(std::list<string> &modlist) {
  load();
  reg_useitemon(handle_u);
  do_log("Loaded");
  register_cmd("cshop", oncmd);
  load_helper(modlist);
}