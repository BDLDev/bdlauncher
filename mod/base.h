#pragma once
#include<string>

class Player;
class Actor;
class Vec3;
//class AutomaticID<Dimension,int>;
class Dimension;
#include"minecraft/core/types.h"
using std::string;
void reg_attack(void* a);
void reg_pickup(void* a);
void reg_useitem(void* a);
void reg_useitemon(void* a);
void reg_build(void* a);
void reg_destroy(void* a);
void sendText(Player* a,string ct);
void TeleportA(Actor& a,Vec3 b,AutomaticID<Dimension,int> c);
Player* getplayer_byname(const string& name);
bool give_item(Player* a,const string& name,short spec,int amo);
bool red_item(Player* a,const string& name,short spec,int amo);
void KillActor(Actor* a);
void sendText2(Player* a,string ct);
MCRESULT runcmd(const string& a);

