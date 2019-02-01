#include<bits/stdc++.h>
#include<unistd.h>
#include "../bdlaunch/launch/mods.h"
#include "../BedrockMod/include/base.h"
#include "fklib/lib.hpp"
extern "C"{
	__attribute__((visibility ("default"))) void mod_init();
  __attribute__((visibility ("default"))) void addCmdhook(fn_6 hook);
  __attribute__((visibility ("default"))) Player* FindPlayer(std::string* pp);
  __attribute__((visibility ("default"))) void KickPlayerByPlayer(void* player,std::string&& reason);
  __attribute__((visibility ("default"))) void sendMessage(Player* player, std::string *msg);
  __attribute__((visibility ("default"))) void getPlayersForeach(void(*cb)(Player*));
  __attribute__((visibility ("default"))) void* getLevel();
};
static fn_6 Minecraft12initCommands;
static fn_66 SayCommand5setup;
static fn_6 updateServerAnnouncement;
static fn_66 Blacklist9isBlocked;
static fn_6 ZNK9Minecraft8getLevelEv;
static fn_6666 MC_kick;
static std::list<fn_6> hooks;
static Minecraft *MC;
static ServerNetworkHandler *pSNH;
#define pstr(a) (*(std::string*)(a))
Minecraft* getMC(){
  return MC;
}
ServerNetworkHandler* getSNH(){
  return pSNH;
}
void* getLevel(){
  return ZNK9Minecraft8getLevelEv(MC);
}
void KickPlayerByPlayer(void* player,std::string&& reason){
  printf("call kick %p %p\n",MC_kick,(void*)((u64)player+5584));
	MC_kick(pSNH,(void*)((u64)player+5584),&reason,NULL);
}
void KickPlayerByNetI(void* neti,std::string&& reason){
	MC_kick(pSNH,neti,&reason,NULL);
}
void addCmdhook(fn_6 hook){
  hooks.push_back(hook);
}

u64 getMinecraft(void* a){
  MC=a;
  return Minecraft12initCommands(a);
}
u64 hookReg(void* a,void* b){
  for(fn_6 fn:hooks){
    fn(a);
  }
  return SayCommand5setup(a,b);
}
u64 SNH(void* a){
  pSNH=a;
  return updateServerAnnouncement(a);
}
static fn_66 longm;
void sendMessage(Player* player, std::string *msg)
{
  char buf[65535];
 void(*nmsl)(void*,void*);
 nmsl=getFunc("_ZN10TextPacket18createJukeboxPopupERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE");
 nmsl(buf,msg);
  longm(player,buf);
}
std::vector<std::unique_ptr<Player> >* getPlayers(){
  std::vector<std::unique_ptr<Player> >*(*getUsers)(void*);
  void* lev=ZNK9Minecraft8getLevelEv(MC);
  getUsers=(typeof(getUsers))getFunc("_ZN5Level8getUsersEv");
  auto fkvec=getUsers(lev);
  return fkvec;
}
Player* FindPlayer(std::string* pp){
  std::vector<std::unique_ptr<Player> >*(*getUsers)(void*);
  void* lev=ZNK9Minecraft8getLevelEv(MC);
  getUsers=(typeof(getUsers))getFunc("_ZN5Level8getUsersEv");
  auto fkvec=getUsers(lev);
  auto beg=fkvec->begin();
  auto end=fkvec->end();
  for(;beg!=end;++beg){
    Player* sb=beg->get();
    if(*sb->getPlayerName()==*pp) return sb;
  }
  return NULL;
}
void getPlayersForeach(void(*cb)(Player*)){
  /*void*(*getLevel)(u64,char*);
  getLevel=(typeof(getLevel))(*(u64*)((*(u64*)a)+48));
  printf("call %p\n",getLevel);
  void* lev=getLevel(a,"");*/
  std::vector<std::unique_ptr<Player> >*(*getUsers)(void*);
  void* lev=ZNK9Minecraft8getLevelEv(MC);
  getUsers=(typeof(getUsers))getFunc("_ZN5Level8getUsersEv");
  auto fkvec=getUsers(lev);
  auto beg=fkvec->begin();
  auto end=fkvec->end();
  for(;beg!=end;++beg){
    Player* sb=beg->get();
    cb(sb);
  }
}
fn_6 onTick_orig;
u64 onTick(Level* thi){
  u64 rv=onTick_orig(thi);
  printf("tick\n");
  return rv;
}
void mod_init(){
	printf("[ModsCore] Core loaded\n");
  MC_kick=(fn_6666)getFunc("_ZN20ServerNetworkHandler16disconnectClientERK17NetworkIdentifierRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEb");
  ZNK9Minecraft8getLevelEv=(fn_6)getFunc("_ZNK9Minecraft8getLevelEv");
  longm=getFunc("_ZNK12ServerPlayer17sendNetworkPacketER6Packet");
  MCHok("_ZN9Minecraft12initCommandsEv",getMinecraft,Minecraft12initCommands);
  MCHok("_ZN10SayCommand5setupER15CommandRegistry",hookReg,SayCommand5setup);
  MCHok("_ZN20ServerNetworkHandler24updateServerAnnouncementEv",SNH,updateServerAnnouncement);
  //MCHok("_ZN5Level4tickEv",onTick,onTick_orig);
}
