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
/*
BDL_EXPORT void reg_attack(void* a);
BDL_EXPORT void reg_pickup(void* a);
BDL_EXPORT void reg_useitem(void* a);
BDL_EXPORT void reg_useitemon(void* a);
BDL_EXPORT void reg_build(void* a);
BDL_EXPORT void reg_destroy(void* a);
BDL_EXPORT void reg_player_join(void* a);
BDL_EXPORT void reg_player_left(void* a);
*/

BDL_EXPORT void sendText(Player* a,string ct);
BDL_EXPORT void TeleportA(Actor& a,Vec3 b,AutomaticID<Dimension,int> c);
BDL_EXPORT Player* getplayer_byname(const string& name);
BDL_EXPORT Player* getplayer_byname2(const string& name);
BDL_EXPORT void get_player_names(vector<string>& a);
BDL_EXPORT void KillActor(Actor* a);
BDL_EXPORT void sendText2(Player* a,string ct);
BDL_EXPORT MCRESULT runcmd(const string& a);
BDL_EXPORT MCRESULT runcmdAs(const string& a,Player* sp);
BDL_EXPORT Minecraft* getMC();

BDL_EXPORT void split_string(const std::string& s, std::vector<std::string>& v, const std::string& c);
BDL_EXPORT bool execute_cmdchain(const string& chain_,const string& sp="",bool chained=true);
BDL_EXPORT void register_cmd(const std::string& name,void* fn,const std::string& desc="mod command",int permlevel=0);

BDL_EXPORT void reg_useitemon(std::function<bool(GameMode* a0,ItemStack * a1,BlockPos const* a2,BlockPos const* dstPos,Block const* a5)>);
BDL_EXPORT void reg_destroy(std::function<bool(GameMode* a0,BlockPos const*)>);
BDL_EXPORT void reg_attack(std::function<bool(ServerPlayer* a0,Actor * a1)>);
BDL_EXPORT void reg_chat(std::function<bool(ServerPlayer const* a0,string& payload)>);
BDL_EXPORT void reg_player_join(std::function<void(ServerPlayer *)>);
BDL_EXPORT void reg_player_left(std::function<void(ServerPlayer *)>);
BDL_EXPORT void reg_pickup(std::function<bool(Actor* a0,ItemActor * a1)>);

BDL_EXPORT int getPlayerCount();
BDL_EXPORT int getMobCount();

#define ARGSZ(b) if(a.size()<b){outp.error("check your arg");return;}
#define SafeStr(a) ("\""+(a)+"\"")

