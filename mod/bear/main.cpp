
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <global.h>
#include <cstdio>
#include <list>
#include <forward_list>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "cmdhelper.h"
#include <vector>
#include <Loader.h>
#include <MC.h>
#include <unistd.h>
#include <cstdarg>
#include <fstream>
#include <minecraft/json.h>
#include "base.h"
#include "../gui/gui.h"
#include "bear.command.h"
#include <ctime>
#include <cmath>
#include <deque>
#include <dlfcn.h>
#include <string>
#include <aio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "lang.h"
using std::string;
using std::unordered_map;
using std::unordered_set;

const char meta[] __attribute__((used, section("meta"))) =
    "name:bear\n"
    "version:20200121\n"
    "author:sysca11\n"
    "depend:base@20200121,command@20200121,gui@20200121\n";

#define dbg_printf(...)                                                                                                \
  {}
//#define dbg_printf printf
extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);
LDBImpl ban_data("data_v2/bear");
bool isBanned(const string &name) {
  string val;
  auto succ = ban_data.Get(name, val);
  if (succ) {
    int &tim = *((int *) val.data());
    if (tim != 0 && time(0) > tim) {
      ban_data.Del(name);
      return 0;
    } else {
      return 1;
    }
  } else {
    return 0;
  }
}
#include "log.hpp"
#include "network.hpp"
THook(
    void *, _ZN20ServerNetworkHandler22_onClientAuthenticatedERK17NetworkIdentifierRK11Certificate,
    ServerNetworkHandler *snh, NetworkIdentifier &a, Certificate &b) {
  string pn   = ExtendedCertificate::getIdentityName(b);
  string xuid = ExtendedCertificate::getXuid(b);
  async_log("[JOIN] %s joined game with xuid <%s>\n", pn.c_str(), xuid.c_str());
  string val;
  auto succ = ban_data.Get(xuid, val);
  if (!succ) { ban_data.Put(xuid, pn); }
  if (isBanned(pn) || (succ && isBanned(val))) {
    snh->disconnectClient(a, YOU_R_BANNED, false);
    return nullptr;
  }
  return original(snh, a, b);
}

size_t MAX_CHAT_SIZE;
static_deque<string, 128> banword;
template <const int size, const int delta> struct timeq {
  pair<ServerPlayer *, clock_t> pool[size];
  int ptr = 0;
  bool push(ServerPlayer *sp) {
    auto now    = clock();
    pool[ptr++] = {sp, now};
    if (ptr == size) ptr = 0;
    int cnt       = 0;
    clock_t first = LONG_MAX;
    for (auto &[p, clk] : pool) {
      if (p == sp) {
        if (clk < first) first = clk;
        cnt++;
      }
    }
    if (cnt <= 1) return true;
    if ((cnt - 1) * delta > now - first) return false;
    return true;
  }
};

#include "ChatSan.hpp"

unordered_map<string, time_t> mute_time;
static bool is_muted(const string &name) {
  auto it = mute_time.find(name);
  if (it != mute_time.end()) {
    if (it->second != 0 && time(0) > it->second) {
      mute_time.erase(it);
    } else {
      return true;
    }
  }
  return false;
}
static bool hkc(ServerPlayer *b, string &c) {
  if (c.size() > MAX_CHAT_SIZE) {
    sendText(b, "too long chat");
    return 0;
  }
  for (auto &i : banword) {
    if (c.find(i) != string::npos) {
      SPBuf<512> sb;
      sb.write("Banned word: ");
      sb.write(i);
      sendText(b, sb.get());
      return 0;
    }
  }
  auto &name = b->getName();
  if (is_muted(name)) {
    sendText(b, "You're muted");
    return 0;
  }
  async_log("[CHAT] %s: %s\n", name.c_str(), c.c_str());
  return 1;
}

void ACCommand::mute(mandatory<Mute>, mandatory<CommandSelector<Player>> target, mandatory<int> time_) {
  int to       = time_ == -1 ? 0 : (time(0) + to);
  auto results = target.results(getOrigin());
  if (!Command::checkHasTargets(results, getOutput())) return;
  for (auto &player : results) {
    mute_time[player.getName()] = to;
    getOutput().addMessage(player.getName() + " has been muted");
  }
  getOutput().success();
}
void ACCommand::ban(mandatory<Ban>, mandatory<string> target, optional<int> time_) {
  do_log("ban time: %d", time_);
  auto tim = time_ == 0 ? 0 : (time(0) + time_);
  ban_data.Put(target, string((char *) &tim, 4));
  auto x = getuser_byname(target);
  if (x) {
    ban_data.Put(x->getXUID(), x->getName());
    forceKickPlayer(*x);
  }
  getOutput().success("§b" + target + " has been banned");
}
void ACCommand::unban(mandatory<Unban>, mandatory<string> target) {
  ban_data.Del(target);
  getOutput().success();
}
using std::unordered_set;
static static_deque<short, 64> banitems, warnitems;
static int LOG_CHEST;
THook(void *, _ZN15ChestBlockActor9startOpenER6Player, BlockActor &ac, Player &pl) {
  if (LOG_CHEST) {
    auto &pos = ac.getPosition();
    async_log("[CHEST] %s open chest pos: %d %d %d\n", pl.getName().c_str(), pos.x, pos.y, pos.z);
  }
  return original(ac, pl);
}
static bool handle_u(GameMode *a0, ItemStack *a1, BlockPos const *a2, BlockPos const *dstPos, Block const *a5) {
  if (a0->getPlayer()->getPlayerPermissionLevel() > 1) return 1;
  auto &sn = a0->getPlayer()->getName();
  if (banitems.has(a1->getId())) {
    async_log(
        "[ITEM] %s tries to use prohibited items(banned) %s pos: %d %d %d\n", sn.c_str(), a1->toString().c_str(), a2->x,
        a2->y, a2->z);
    sendText(a0->getPlayer(), "§cUnable to use prohibited items", JUKEBOX_POPUP);
    return 0;
  }
  if (warnitems.has(a1->getId())) {
    async_log(
        "[ITEM] %s tries to use dangerous items(warn) %s pos: %d %d %d\n", sn.c_str(), a1->toString().c_str(), a2->x,
        a2->y, a2->z);
    return 1;
  }
  return 1;
}
static void handle_left(ServerPlayer *a1) { async_log("[LEFT] %s left game\n", a1->getName().c_str()); }

static int FPushBlock, FExpOrb, FDest;
enum CheatType { FLY, NOCLIP, INV, MOVE };
static void notifyCheat(const string &name, CheatType x) {
  const char *CName[] = {"FLY", "NOCLIP", "Creative", "Teleport"};
  async_log("[%s] detected for %s\n", CName[x], name.c_str());
  string kick = string("ac kick \"") + name + "\" §cYou are banned";
  switch (x) {
  case FLY: runcmd(kick); break;
  case NOCLIP: runcmd(kick); break;
  case INV: runcmd(kick); break;
  case MOVE: runcmd(kick); break;
  }
}

THook(void *, _ZN5BlockC2EtR7WeakPtrI11BlockLegacyE, Block *a, unsigned short x, void *c) {
  auto ret = original(a, x, c);
  if (FPushBlock) {
    auto *leg = a->getLegacyBlock();
    if (a->isContainerBlock()) leg->addBlockProperty({0x1000000LL});
  }
  return ret;
}

THook(
    void *, _ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK24SpawnExperienceOrbPacket,
    ServerNetworkHandler *sh, NetworkIdentifier const &iden, Packet *pk) {
  if (FExpOrb) { return nullptr; }
  return original(sh, iden, pk);
}

THook(void *, _ZNK15StartGamePacket5writeER12BinaryStream, void *this_, void *a) {
  // dirty patch to hide seed
  access(this_, uint, 40) = 114514;
  return original(this_, a);
}

static int limitLevel(int input, int max) {
  if (input < 0)
    return 0;
  else if (input > max)
    return 0;
  return input;
}
struct Enchant {
  enum Type : int {};
  static std::vector<std::unique_ptr<Enchant>> mEnchants;
  virtual ~Enchant();
  virtual bool isCompatibleWith(Enchant::Type type);
  virtual int getMinCost(int);
  virtual int getMaxCost(int);
  virtual int getMinLevel();
  virtual int getMaxLevel();
  virtual bool canEnchant(int) const;
};

struct EnchantmentInstance {
  enum Enchant::Type type;
  int level;
  int getEnchantType() const;
  int getEnchantLevel() const;
  void setEnchantLevel(int);
};
//将外挂附魔无效
THook(int, _ZNK19EnchantmentInstance15getEnchantLevelEv, EnchantmentInstance *thi) {
  int level2    = thi->level;
  auto &enchant = Enchant::mEnchants[thi->type];
  auto max      = enchant->getMaxLevel();
  auto result   = limitLevel(level2, max);
  if (result != level2) thi->level = result;
  return result;
}
/*
typedef unsigned long IHash;
static IHash MAKE_IHASH(ItemStack* a){
    IHash res= a->getIdAuxEnchanted();
    if(*a->getUserData()){
        res^=(*(a->getUserData()))->hash()<<28;
    }
    return res;
}
struct VirtInv{
    unordered_map<IHash,int> items;
    bool bad;
    VirtInv(Player& p){
        bad=0;
    }
    void setBad(){
        bad=1;
    }
    void addItem(IHash item,int count){
        if(item==0) return;
        int prev=items[item];
        items[item]=prev+count;
    }
    void takeItem(IHash item,int count){
        addItem(item,-count);
    }
    bool checkup(){
        if(bad) return 1;
        for(auto &i:items){
            if(i.second<0){
                return false;
            }
        }
        return true;
    }
    void clear(){
        items.clear();
        bad=false;
    }
};*/
// unordered_map<string,IHash> lastitem;
THook(unsigned long, _ZNK20InventoryTransaction11executeFullER6Playerb, void *_thi, Player &player, bool b) {
  if (player.getPlayerPermissionLevel() > 1) return original(_thi, player, b);
  const string &name = player.getName();
  auto &a            = *((unordered_map<InventorySource, vector<InventoryAction>> *) _thi);
  for (auto &i : a) {
    for (auto &j : i.second) {
      if (i.first.getContainerId() == 119) {
        // offhand chk
        if ((!j.getToItem()->isNull() && !j.getToItem()->isOffhandItem()) ||
            (!j.getFromItem()->isNull() && !j.getFromItem()->isOffhandItem())) {
          notifyCheat(name, INV);
          return 6;
        }
      }
      if (banitems.has(j.getFromItem()->getId()) || banitems.has(j.getToItem()->getId())) {
        async_log(
            "[ITEM] %s tries to use dangerous items(banned) %s %s\n", name.c_str(), j.getFromItem()->toString().c_str(),
            j.getToItem()->toString().c_str());
        sendText(&player, BANNED_ITEM, POPUP);
        return 6;
      }
      /*
      if(j.getSlot()==50 && i.first.getContainerId()==124){
          //track this
          auto hashf=MAKE_IHASH(j.getFromItem()),hasht=MAKE_IHASH(j.getToItem());
          auto it=lastitem.find(name);
          if(it==lastitem.end()){
              lastitem[name]=hasht;
              continue;
          }else{
              if(it->second!=hashf){
                  async_log("[ITEM] crafting hack detected for %s ,
      %s\n",name.c_str(),j.getFromItem()->toString().c_str()); notifyCheat(name,INV); return 6;
              }
              it->second=hasht;
          }
      }*/
      // printf("cid %d flg %d src %d slot %u get %d %s %s hash %ld
      // %ld\n",j.getSource().getContainerId(),j.getSource().getFlags(),j.getSource().getType(),j.getSlot(),i.first.getContainerId(),j.getFromItem()->toString().c_str(),j.getToItem()->toString().c_str(),MAKE_IHASH(j.getFromItem()),MAKE_IHASH(j.getToItem()));
    }
  }
  return original(_thi, player, b);
}

static void _load_config() {
  banitems.clear();
  warnitems.clear();
  banword.clear();
  std::ifstream ifs{"config/bear.json"};
  Json::Value value;
  Json::Reader reader;
  if (!reader.parse(ifs, value)) {
    auto msg = reader.getFormattedErrorMessages();
    do_log("%s", msg.c_str());
    exit(1);
  }
  FPushBlock = value["FPushChest"].asBool(false);
  FExpOrb    = value["FSpwanExp"].asBool(false);
  FDest      = value["FDestroyCheck"].asBool(false);
  FChatLimit = value["FChatLimit"].asBool(false);
  LOG_CHEST  = value["LogChest"].asBool(false);
  for (auto &i : value["banitems"]) 
    if (!banitems.full()) banitems.push_back((short) i.asInt(0));
  for (auto &i : value["warnitems"]) 
    if (!warnitems.full()) warnitems.push_back((short) i.asInt(0));
  for (auto &i : value["banwords"])
    if (!banword.full()) banword.push_back(i.asString(""));
  MAX_CHAT_SIZE = value["MAX_CHAT_LEN"].asInt(1000);
}
void ACCommand::reload(mandatory<Reload>) {
  _load_config();
  getOutput().success();
}

timeq<6, (int) (CLOCKS_PER_SEC * 0.1)> fastdq;
static bool handle_dest(GameMode *a0, BlockPos const *a1) {
  if (!FDest) return 1;
  auto sp = a0->getPlayer();
  int pl  = sp->getPlayerPermissionLevel();
  if (pl > 1 || sp->isCreative()) { return 1; }
  int x(a1->x), y(a1->y), z(a1->z);
  const Vec3 &fk = a0->getPlayer()->getPos();
#define abs(x) ((x) < 0 ? -(x) : (x))
  int dx = fk.x - x;
  int dy = fk.y - y;
  int dz = fk.z - z;
  int d2 = dx * dx + dy * dy + dz * dz;
  if (d2 > 45) { return 0; }
  if (!fastdq.push(sp)) { return 0; }
  /*Block &bk = *sp->getBlockSource()->getBlock(*a1);
  int id    = bk.getLegacyBlock()->getBlockItemId();
  if (id == 7 || id == 416) {
    notifyCheat(sp->getName(), CheatType::INV);
    return 0;
  }*/
  return 1;
}
void ACCommand::kick(mandatory<Kick>, mandatory<string> target) {
  auto sp = getplayer_byname2(target);
  if (!sp) {
    getOutput().error("cant found");
    return;
  }
  forceKickPlayer(*sp);
  getOutput().addMessage("Kicked " + sp->getName());
  getOutput().success();
}
void ACCommand::bangui(mandatory<Bangui>) {
  auto sp = getSP(getOrigin().getEntity());
  if (sp) {
    gui_ChoosePlayer(sp, "ban", "ban", [](ServerPlayer *sp, string_view dst) {
      SPBuf sb;
      sb.write("ban \""sv);
      sb.write(dst);
      sb.write("\""sv);
      runcmdAs(sb.get(), sp);
    });
    getOutput().success();
  }
}
#include "hidechk.hpp"
#include "invchk.hpp"
static void onJoin(ServerPlayer *sp) {
  auto &pn  = sp->getName();
  auto xuid = sp->getXUID();
  string val;
  auto succ = ban_data.Get(xuid, val);
  if (!succ) { ban_data.Put(xuid, pn); }
  if (isBanned(pn) || (succ && isBanned(val))) {
    forceKickPlayer(*sp);
    async_log("[BAN] anti-blacklist detected for %s \n", sp->getName().c_str());
    return;
  }
  auto inv = dumpall(sp);
  int fd   = open(("invdump/" + sp->getName()).c_str(), O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR);
  write(fd, inv.data(), inv.size());
  close(fd);
}

void mod_init(std::list<string> &modlist) {
  initlog();
  register_commands();
  mkdir("invdump", S_IRWXU);
  reg_player_join(onJoin);
  reg_useitemon(handle_u);
  reg_player_left(handle_left);
  reg_chat(hkc);
  reg_destroy(handle_dest);
  _load_config();
  if (getenv("LOGNET")) rori = (typeof(rori))(MyHook(fp(recvfrom), fp(recvfrom_hook)));
  do_log("Loaded " BDL_TAG);
  load_helper(modlist);
}
