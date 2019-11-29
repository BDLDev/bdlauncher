#pragma once
#include"../cmdhelper.h"
#include<string>
#include<unordered_map>
#include<MC.h>
#include<functional>
#include<vector>
using std::vector;
using std::function;
using std::string;

class Player;
class Actor;
class Vec3;
//class AutomaticID<Dimension,int>;
class Dimension;
struct MCRESULT;

enum TextType:char{
    RAW=0,
    POPUP=3,
    JUKEBOX_POPUP=4,
    TIP=5
};
BDL_EXPORT void sendText(Player* a,const string& ct,TextType type=RAW);
#define sendText2(a,b) sendText(a,b,JUKEBOX_POPUP)
BDL_EXPORT void TeleportA(Actor& a,Vec3 b,AutomaticID<Dimension,int> c);
//BDL_EXPORT Player* getplayer_byname(const string& name);
#define getplayer_byname(x) (getSrvLevel()->getPlayer(x))
BDL_EXPORT Player* getplayer_byname2(const string& name);
BDL_EXPORT void get_player_names(vector<string>& a);
BDL_EXPORT void KillActor(Actor* a);
BDL_EXPORT MCRESULT runcmd(const string& a);
BDL_EXPORT MCRESULT runcmdAs(const string& a,Player* sp);
BDL_EXPORT Minecraft* _getMC();

BDL_EXPORT void split_string(const std::string& s, std::vector<std::string>& v, const std::string& c);
BDL_EXPORT bool execute_cmdchain(string chain_,string sp="",bool chained=true);
BDL_EXPORT void register_cmd(const std::string& name,void* fn,const std::string& desc="mod command",int permlevel=0);

BDL_EXPORT void reg_useitemon(std::function<bool(GameMode* a0,ItemStack * a1,BlockPos const* a2,BlockPos const* dstPos,Block const* a5)>);
BDL_EXPORT void reg_destroy(std::function<bool(GameMode* a0,BlockPos const*)>);
BDL_EXPORT void reg_attack(std::function<bool(ServerPlayer* a0,Actor * a1)>);
BDL_EXPORT void reg_chat(std::function<bool(ServerPlayer const* a0,string& payload)>);
BDL_EXPORT void reg_player_join(std::function<void(ServerPlayer *)>);
BDL_EXPORT void reg_player_left(std::function<void(ServerPlayer *)>);
BDL_EXPORT void reg_pickup(std::function<bool(Actor* a0,ItemActor * a1)>);
BDL_EXPORT void reg_popItem(std::function<bool(ServerPlayer&,BlockPos&)>);
BDL_EXPORT void reg_mobhurt(function<bool(Mob&,ActorDamageSource const&,int&)> x);
BDL_EXPORT void reg_mobdie(function<void(Mob&,ActorDamageSource const&)> x);
BDL_EXPORT void reg_actorhurt(function<bool(Actor&,ActorDamageSource const&,int&)> x);
BDL_EXPORT void reg_interact(function<bool(GameMode*,Actor&)> x);

BDL_EXPORT int getPlayerCount();
BDL_EXPORT int getMobCount();

BDL_EXPORT NetworkIdentifier* getPlayerIden(ServerPlayer& sp);
BDL_EXPORT ServerPlayer* getuser_byname(const string& a);
BDL_EXPORT void forceKickPlayer(ServerPlayer& sp);

#define ARGSZ(b) if(a.size()<b){outp.error("check your arg");return;}
#define SafeStr(a) ("\""+(a)+"\"")
static Minecraft* McCache;
static Level* LvCache;
static inline Minecraft* getMC(){
    return McCache?McCache:(McCache=_getMC());
}
static inline Level* getSrvLevel(){
    return LvCache?LvCache:(LvCache=_getMC()->getLevel());
}

