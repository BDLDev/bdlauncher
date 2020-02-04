#define BASE
#include <cmdhelper.h>
#include <myhook.h>
#include <Loader.h>
//#include <MC.h>
#include <vector>
#include <seral.hpp>
#include <signal.h>
#include <sys/stat.h>
#include <unistd.h>
#include <tuple>
#include <list>
#include <vector>
using std::list;
using std::tuple;
using std::vector;
#include <sstream>
#include <logger.h>
#include <string>
#include<minecraft/core/getSP.h>
#include <minecraft/actor/Actor.h>
#include <minecraft/actor/Mob.h>
#include <minecraft/actor/ItemActor.h>
#include <minecraft/actor/Player.h>
#include <minecraft/actor/ActorDamageSource.h>
#include <minecraft/core/GameMode.h>
#include <minecraft/block/BlockPos.h>
#include <minecraft/item/ItemStack.h>
#include <minecraft/block/Block.h>
#include <minecraft/core/types.h>
#include <minecraft/core/Minecraft.h>
#include <minecraft/net/NetworkIdentifier.h>
#include <minecraft/net/LoopbackPacketSender.h>
#include <minecraft/packet/MyPkt.h>
#include <minecraft/packet/BinaryStream.h>
#include <minecraft/level/Level.h>

#include "base.h"
#include "hook.h"

const char meta[] __attribute__((used, section("meta"))) =
    "name:base\n"
    "version:20200121\n"
    "author:sysca11\n"
    "prio:1";

extern void load_helper(list<string> &modlist);

extern "C" {
BDL_EXPORT void mod_init(list<string> &modlist);
BDL_EXPORT Minecraft *MC;
BDL_EXPORT Level *ServLevel;
}

THook(void*,_ZN14ServerInstance14onLevelCorruptEv,void* x){
    printf("LEVEL CORRUPT DETECTED!!!\n");
    string payload;
    auto vc          = ServLevel->getUsers();
    for (auto &p : *vc) {
        auto sp=getSP(p.get());
        if(sp){
          payload+=sp->getNameTag()+" ->("+std::to_string(sp->getPos().x)+" , "+std::to_string(sp->getPos().z)+") dim "+std::to_string(sp->getDimensionId())+"\n";
        }
    }
    printf("%s\n",payload.c_str());
    char buf[1024];
    auto TIM = time(0);
    strftime(buf, 1024, "Crash-%Y-%m-%d_%H_%M_%S.txt", localtime(&TIM));
    FILE* fp=fopen(buf,"w");
    fwrite(payload.data(),payload.size(),1,fp);
    fclose(fp);
    return original(x);
}


static ServerNetworkHandler *MCSNH;
static LoopbackPacketSender *MCPKTSEND;
static MinecraftCommands *MCCMD;
static unordered_map<ServerPlayer *, unsigned char> sp_net;
static uintptr_t SPEC_NETI_OFFSET;
THook(
    void *,
    _ZN12ServerPlayerC1ER5LevelR12PacketSenderR14NetworkHandlerRN15ClientBlobCache6Server22ActiveTransfersManagerE8GameTypeRK17NetworkIdentifierhSt8functionIFvRS_EEN3mce4UUIDERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt10unique_ptrI11CertificateSt14default_deleteIST_EEi,
    ServerPlayer *a1, Level *a2, void *a3, void *a4, void *a5, void *a6, NetworkIdentifier *a7, unsigned char a8,
    void *a9, void *a10, void *a10_1, string *a11, Certificate *a12, void *a13) {
  auto ret = original(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a10_1, a11, a12, a13);
  if (SPEC_NETI_OFFSET == 0) {
    // seek for neti offset
    for (int i = 2000; i < 4000; ++i) {
      if (memcmp(((char *) a1) + i, a7, 0x98) == 0) {
        if (SPEC_NETI_OFFSET) { do_log("wtf!duplicate network iden??? first:%ld next %d", SPEC_NETI_OFFSET, i); }
        SPEC_NETI_OFFSET = i;
      }
    }
    do_log("get offset %ld", SPEC_NETI_OFFSET);
  }
  sp_net[a1] = a8;
  return ret;
}
THook(void *, _ZN12ServerPlayerD0Ev, ServerPlayer *sp) {
  sp_net.erase(sp);
  return original(sp);
}
void base_sendPkt(ServerPlayer *sp, Packet &pk) {
  auto i = sp_net[sp];
  MCPKTSEND->sendToClient(*getPlayerNeti(*sp), pk, i);
}
// export APIS
void split_string(string_view s, std::vector<std::string_view> &v, string_view c) {
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while (std::string::npos != pos2) {
    v.emplace_back(s.data() + pos1, pos2 - pos1); // s.substr(pos1, pos2-pos1)
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if (pos1 != s.length()) v.emplace_back(s.data() + pos1, s.size() - pos1);
}
void split_string(string_view s, static_deque<std::string_view> &v, string_view c) {
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while (std::string::npos != pos2) {
    v.push_back(s.substr(pos1, pos2 - pos1)); //
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
    if (v.full()) return;
  }
  if (pos1 != s.length() && !v.full()) v.push_back(string_view(s.data() + pos1, s.size() - pos1));
}
bool execute_cmd_random(const static_deque<string_view> &chain) {
  auto rd = rand() % chain.size();
  return execute_cmdchain(chain[rd], "", false);
}

bool execute_cmdchain(string_view chain, string_view sp, bool chained) {
  auto fg = false;
  if (sp[0] != '"') fg = 1;
  char buf[8192];
  const char *src = chain.data();
  int bufsz       = 0;
  for (decltype(chain.size()) i = 0; i < chain.size(); ++i) {
    if (memcmp(src + i, "%name%", 6) == 0) {
      if (fg) buf[bufsz++] = '"';
      memcpy(buf + bufsz, sp.data(), sp.size());
      bufsz += sp.size();
      if (fg) buf[bufsz++] = '"';
      i += 5;
    } else {
      buf[bufsz++] = src[i];
    }
  }
  auto chainxx = string_view(buf, bufsz);
  if (chainxx[0] == '!') {
    static_deque<string_view> dst;
    split_string(chainxx.substr(1), dst, ";");
    return execute_cmd_random(dst);
  }
  static_deque<string_view> dst;
  split_string(chainxx, dst, ",");
  for (auto &i : dst) {
    char buf[1024];
    memcpy(buf, i.data(), i.size());
    auto sz = i.size();
    for (decltype(sz) j = 0; j < sz; ++j)
      if (buf[j] == '$') buf[j] = ',';
    auto res = runcmd({buf, sz});
    if (!res.isSuccess() && chained) return false;
  }
  return true;
}
struct TeleportCommand {
  char filler[1024];
  TeleportCommand();
  void teleport(Actor &, Vec3, Vec3 *, AutomaticID<Dimension, int>) const;
};
// https://github.com/PetteriM1/NukkitPetteriM1Edition/blob/master/src/main/java/cn/nukkit/network/protocol/TextPacket.java
/* this.putByte(this.type);
        this.putBoolean(this.isLocalized || type == TYPE_TRANSLATION);
        switch (this.type) {
            case TYPE_RAW:
            case TYPE_TIP:
            case TYPE_SYSTEM:
            case TYPE_JSON:
                this.putString(this.message);
                break;
            case TYPE_TRANSLATION:
            case TYPE_POPUP:
            case TYPE_JUKEBOX_POPUP:
                this.putString(this.message);
                this.putUnsignedVarInt(this.parameters.length);
                for (String parameter : this.parameters) {
                    this.putString(parameter);
                }
        }
                this.putString(this.xboxUserId);
            this.putString(this.platformChatId);
    }*/
struct MyTxtPk {
  string_view str;
  TextType type;
  MyPkt *pk;
  void setText(string_view ct, TextType typ) {
    str  = ct;
    type = typ;
  }
  MyTxtPk() {
    pk = new MyPkt(0x9, [this](void *, BinaryStream &bs) {
      bs.writeByte(this->type);
      bs.writeBool(false);
      bs.writeStr(this->str);
    });
  }
  void send(Player *p) { ((ServerPlayer *) p)->sendNetworkPacket(*pk); }
};
MyTxtPk gTextPkt;
void sendText(Player *a, string_view ct, TextType type) {
  gTextPkt.setText(ct, type);
  gTextPkt.send(a);
}
void broadcastText(string_view ct, TextType type) {
  gTextPkt.setText(ct, type);
  MCPKTSEND->sendBroadcast(*gTextPkt.pk);
}
static TeleportCommand cmd_p;

void TeleportA(Actor &a, Vec3 b, AutomaticID<Dimension, int> c) {
  if (a.getDimensionId() != c) {
    cmd_p.teleport(a, b, nullptr, c);
    cmd_p.teleport(a, b, nullptr, c);
  } else {
    cmd_p.teleport(a, b, nullptr, c);
  }
}

ServerPlayer *getplayer_byname2(string_view name) {
  ServerPlayer *rt = NULL;
  auto vc          = ServLevel->getUsers();
  for (auto &tg : *vc) {
    string bf = tg->getNameTag();
    int sz    = std::min(bf.size(), name.size());
    int eq    = 1;
    for (int i = 0; i < sz; ++i) {
      if (tolower(bf[i]) != tolower(name[i])) {
        eq = 0;
        break;
      }
    }
    if (eq) {
      rt = tg.get();
      return rt;
    }
    continue;
  }
  return rt;
}

/*void get_player_names(vector<string> &a) {
  auto vc = ServLevel->getUsers();
  for (auto &i : *vc) { a.emplace_back(i->getName()); }
}*/

THook(
    void *,
    _ZN14ServerCommands19setupStandardServerER9MinecraftRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES9_P15PermissionsFile,
    Minecraft &a, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &d,
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &b, PermissionsFile *c) {
  auto ret = original(a, d, b, c);
  do_log("MC %p", &a);
  MC        = &a;
  ServLevel = MC->getLevel();
  MCCMD     = MC->getCommands();
  MCSNH     = MC->getNetEventCallback();
  MCPKTSEND = access(MCSNH, LoopbackPacketSender *, 88);
  do_log("pkt send %p snh %p", MCPKTSEND, MCSNH);
  return ret;
}

struct DedicatedServer {
  void stop();
};

DedicatedServer *dserver;
THook(
    void *, _ZN15DedicatedServer5startERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, DedicatedServer *t,
    string &b) {
  do_log("starting server %p", t);
  dserver = t;
  return original(t, b);
}
static int ctrlc;
static void autostop() {
  ctrlc++;
  if (ctrlc >= 3) {
    do_log("killing server");
    exit(0);
  }
  if (dserver) {
    do_log("stoping server");
    dserver->stop();
  }
}
int getPlayerCount() { return ServLevel->getUserCount(); }
int getMobCount() { return ServLevel->getTickedMobCountPrevious(); }

NetworkIdentifier *getPlayerNeti(ServerPlayer &sp) { return (NetworkIdentifier *) (((char *) &sp) + SPEC_NETI_OFFSET); }
ServerPlayer *getuser_byname(string_view a) {
  auto vc = ServLevel->getUsers();
  for (auto &i : *vc) {
    if (i->getNameTag() == a) return i.get();
  }
  return nullptr;
}
void forceKickPlayer(ServerPlayer &sp) {
  // MCSNH->disconnectClient(*getPlayerNeti(sp),"Kicked",false);
  MCSNH->onSubclientLogoff(*getPlayerNeti(sp), sp_net[&sp]);
  // sp.disconnect();
}
extern "C" {
void _ZTV19ServerCommandOrigin();
void _ZN19ServerCommandOriginD2Ev();
void _ZTV19PlayerCommandOrigin();
};
void *fake_vtbl[(0x000000000ABE2610 - 0x000000000ABE2528) / 8];
void *fake_vtbl_ply[(0x000000000ABE2610 - 0x000000000ABE2528) / 8];
static ServerCommandOrigin *SCO;
static string sname("Server");
extern "C" {
MCRESULT
_ZNK17MinecraftCommands23requestCommandExecutionESt10unique_ptrI13CommandOriginSt14default_deleteIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEib(
    MinecraftCommands *, CommandOrigin **, std::string const &, int, bool);
};
BDL_EXPORT MCRESULT runcmd(string_view a) {
  // ServerOrigin is const so we can simply share it here
  // char fakeOrigin[72];
  CommandOrigin **ori_ptr = (CommandOrigin **) &SCO;
  if (!SCO) {
    SCO = new ServerCommandOrigin(sname, *(ServerLevel *) MC->getLevel(), (CommandPermissionLevel) 5);
    access(SCO, void *, 0) = fake_vtbl + 2;
  }
  // memcpy(fakeOrigin,SCO,sizeof(fakeOrigin));
  return _ZNK17MinecraftCommands23requestCommandExecutionESt10unique_ptrI13CommandOriginSt14default_deleteIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEib(
      MCCMD, ori_ptr, string(a), 4, 1);
}
BDL_EXPORT MCRESULT runcmdAs(string_view a, Player *sp) {
  // auto ori=(CommandOrigin*)new PlayerCommandOrigin(*sp);
  char origin[40];
  CommandOrigin *ori_ptr             = (CommandOrigin *) &origin;
  access(ori_ptr, void *, 0)         = fake_vtbl_ply + 2;
  access(ori_ptr, ActorUniqueID, 24) = sp->getUniqueID();
  access(ori_ptr, Level *, 32)       = ServLevel;
  return _ZNK17MinecraftCommands23requestCommandExecutionESt10unique_ptrI13CommandOriginSt14default_deleteIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEib(
      MCCMD, &ori_ptr, string(a), 4, 1);
}
static vector<pair<void(*)(void*,ServerPlayer*),void*>> SPD2EvHooks;
BDL_EXPORT void regSPD2EvHooks(pair<void(*)(void*,ServerPlayer*),void*> x){
  SPD2EvHooks.push_back(x);
}
THook(void*,_ZN12ServerPlayerD2Ev,ServerPlayer* thi){
  for(auto& i:SPD2EvHooks){
    i.first(i.second,thi);
  }
  return original(thi);
}
static void dummy__() {}
void mod_init(list<string> &modlist) {
  uintptr_t *pt = (uintptr_t *) _ZTV19ServerCommandOrigin;
  memcpy(fake_vtbl, (void *) _ZTV19ServerCommandOrigin, sizeof(fake_vtbl));
  do_log(
      "fake vtable pt %p %p %p %p", (void *) pt[0], (void *) pt[1], (void *) pt[2],
      _ZN19ServerCommandOriginD2Ev);              // pt[3]=D0ev
  fake_vtbl[2] = fake_vtbl[3] = (void *) dummy__; // fix free(ServerCommandOrigin)
  memcpy(fake_vtbl_ply, (void *) (void *) _ZTV19PlayerCommandOrigin, sizeof(fake_vtbl_ply));
  fake_vtbl_ply[2] = fake_vtbl_ply[3] = (void *) dummy__;
  mkdir("data_v2", S_IRWXU);
  do_log("loaded! " BDL_TAG);
  signal(SIGINT, (sighandler_t) autostop);
  load_helper(modlist);
}
