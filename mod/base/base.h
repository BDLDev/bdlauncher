#pragma once
#include "../cmdhelper.h"
#include <string>
#include <unordered_map>
#include <MC.h>
#include <functional>
#include <vector>
//#include "db.hpp"
#include "stl.hpp"
#include"stkbuf.hpp"
#include<string_view>
using namespace std::literals;
using std::string_view;
using std::function;
using std::string;
using std::vector;

class Player;
class Actor;
class Vec3;
//class AutomaticID<Dimension,int>;
class Dimension;
struct MCRESULT;

enum TextType : char
{
    RAW = 0,
    POPUP = 3,
    JUKEBOX_POPUP = 4,
    TIP = 5
};
typedef static_deque<string_view,64> argVec;

BDL_EXPORT void sendText(Player *a, string_view ct, TextType type = RAW);
BDL_EXPORT void broadcastText(string_view ct,TextType type = RAW);
#define sendText2(a, b) sendText(a, b, JUKEBOX_POPUP)
BDL_EXPORT void TeleportA(Actor &a, Vec3 b, AutomaticID<Dimension, int> c);
BDL_EXPORT ServerPlayer *getplayer_byname2(string_view name);
BDL_EXPORT void get_player_names(vector<string> &a);
BDL_EXPORT MCRESULT runcmd(string_view a);
BDL_EXPORT MCRESULT runcmdAs(string_view a, Player *sp);

BDL_EXPORT void split_string(string_view s, std::vector<std::string_view> &v, string_view c);
BDL_EXPORT void split_string(string_view s, static_deque<std::string_view> &v, string_view c);
BDL_EXPORT bool execute_cmdchain(string_view chain_, string_view sp, bool chained = true);
BDL_EXPORT void register_cmd(const std::string &name, void (*fn)(argVec&,CommandOrigin const &,CommandOutput &outp,string_view args), const std::string &desc = "mod command", int permlevel = 0);
BDL_EXPORT void register_cmd(const std::string &name, void (*fn)(argVec&,CommandOrigin const &,CommandOutput &outp), const std::string &desc = "mod command", int permlevel = 0);
BDL_EXPORT void register_cmd(const std::string &name,void (*fn)(void), const std::string &desc = "mod command", int permlevel = 0);
BDL_EXPORT void reg_useitemon(bool(*)(GameMode *a0, ItemStack *a1, BlockPos const *a2, BlockPos const *dstPos, Block const *a5));
BDL_EXPORT void reg_destroy(bool(*)(GameMode *a0, BlockPos const *));
BDL_EXPORT void reg_attack(bool(*)(ServerPlayer *a0, Actor *a1));
BDL_EXPORT void reg_chat(bool(*)(ServerPlayer *a0, string &payload));
BDL_EXPORT void reg_player_join(void(*)(ServerPlayer *));
BDL_EXPORT void reg_player_left(void(*)(ServerPlayer *));
BDL_EXPORT void reg_pickup(bool(*)(Actor *a0, ItemActor *a1));
BDL_EXPORT void reg_popItem(bool(*)(ServerPlayer &, BlockPos &));
BDL_EXPORT void reg_mobhurt(bool(*)(Mob &, ActorDamageSource const &, int &));
BDL_EXPORT void reg_mobdie(void(*)(Mob &, ActorDamageSource const &));
BDL_EXPORT void reg_actorhurt(bool(*)(Actor &, ActorDamageSource const &, int &));
BDL_EXPORT void reg_interact(bool(*)(GameMode *, Actor &));

BDL_EXPORT int getPlayerCount();
BDL_EXPORT int getMobCount();

BDL_EXPORT NetworkIdentifier *getPlayerNeti(ServerPlayer &sp);
BDL_EXPORT ServerPlayer *getuser_byname(string_view a);
BDL_EXPORT void base_sendPkt(ServerPlayer* sp,Packet& pk);

BDL_EXPORT ItemStack* createItemStack_static(short id,short aux,unsigned char amo,ItemStack* stk);
BDL_EXPORT ItemStack* createItemStack(short id,short aux,unsigned char amo);
BDL_EXPORT ItemStack* createItemStack_static(string const& name,unsigned char amo,ItemStack* stk);
BDL_EXPORT ItemStack* createItemStack(string const& name,unsigned char amo);

BDL_EXPORT void giveItem(ServerPlayer& sp,ItemStack* is);
BDL_EXPORT ActorUniqueID summon(BlockSource& bs,Vec3 const& vc,string const& name);
BDL_EXPORT bool takeItem_unsafe(ServerPlayer& sp,ItemStack* is);
BDL_EXPORT bool takeItem(ServerPlayer& sp,ItemStack* is);

#define getplayer_byname(x) (getuser_byname(x))

BDL_EXPORT void forceKickPlayer(ServerPlayer &sp);

#define ARGSZ(b)      \
    if (a.size() < b) \
    { \
char buf[256]; \
sprintf(buf,"check your arg.%d required ,%d found\n", b, a.size()); \
outp.error(buf); \
return; \
}

#ifndef BASE
extern "C"{
    void MC(); //dummy
    void ServLevel();
}
#endif
#define getMC() (*(Minecraft**)MC)
#define getSrvLevel() (*(Level**)ServLevel)
static inline bool isOp(ServerPlayer const *sp)
{
    return (int)sp->getPlayerPermissionLevel() > 1;
}
static inline bool isOp(CommandOrigin const &sp)
{
    return (int)sp.getPermissionsLevel() > 0;
}

#include <leveldb/db.h>
struct LDBImpl
{
    leveldb::DB *db;
    leveldb::ReadOptions rdopt;
    leveldb::WriteOptions wropt;
    leveldb::Options options;
    void load(const char *name, bool read_cache=true,int lru_cache_sz=0);
    LDBImpl(const char *name, bool read_cache=true,int lru_cache_sz=0);
    void close();
    ~LDBImpl();
    bool Get(string_view key, string &val) const;
    void Put(string_view key, string_view val);
    bool Del(string_view key);
    void Iter(function<void(string_view, string_view)> fn) const;
    void CompactAll();
};

using std::pair;
#define BDL_TAG "V2020-1-11"
