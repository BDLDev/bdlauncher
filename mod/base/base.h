#pragma once
#include<string>
#include<unordered_map>
#include<MC.h>
class Player;
class Actor;
class Vec3;
//class AutomaticID<Dimension,int>;
class Dimension;
struct MCRESULT;
void reg_attack(void* a);
void reg_pickup(void* a);
void reg_useitem(void* a);
void reg_useitemon(void* a);
void reg_build(void* a);
void reg_destroy(void* a);
void reg_player_join(void* a);
void reg_player_left(void* a);

void sendText(Player* a,string ct);
void TeleportA(Actor& a,Vec3 b,AutomaticID<Dimension,int> c);
void sendTransfer(Player* a,const string& ip,short port);
Player* getplayer_byname(const string& name);
Player* getplayer_byname2(const string& name);
void KillActor(Actor* a);
void sendText2(Player* a,string ct);
MCRESULT runcmd(const string& a);

#define ARGSZ(b) if(a.size()<b){outp.error("check your arg");return;}

