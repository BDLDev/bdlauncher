#include <cstdio>
#include <list>
#include <forward_list>
#include <string>
#include <unordered_map>
#include "cmdhelper.h"
#include <vector>
#include <Loader.h>
//#include <MC.h>
#include <unistd.h>
#include <cstdarg>

#include "base.h"
#include <cmath>
#include <deque>
#include <dlfcn.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "gui.h"
#include <minecraft/core/types.h>
#include <minecraft/core/getSP.h>
#include <minecraft/core/Minecraft.h>
#include <minecraft/level/Level.h>
#include <minecraft/item/ItemStack.h>
#include <minecraft/net/NetworkIdentifier.h>
#include <minecraft/packet/MyPkt.h>
#include <minecraft/packet/BinaryStream.h>
#include "PlayerMap.h"
using std::string;
using std::unordered_map;

const char meta[] __attribute__((used, section("meta"))) =
    "name:gui\n"
    "version:20200204\n"
    "author:sysca11\n"
    "depend:base@20200121,command@20200121\n";

#define dbg_printf(...)                                                                                                \
  {}
//#define dbg_printf printf
extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);

using std::unordered_map;
using std::vector;
//unordered_map<int, SharedForm *> id_forms;
// AllocPool<SharedForm> FormMem;
SharedForm *getForm(string_view title, string_view cont, bool isInp) {
  return new SharedForm(title, cont, true, isInp); // need free
}
static void relForm(SharedForm *sf) {
  if (sf->needfree) { delete sf; /*FormMem.release(sf);*/ }
}
struct FormWrap{
  SharedForm* sf;
  ~FormWrap(){
    //printf("def\n");
    relForm(sf);
  }
};
PlayerMap<FormWrap> player_mp;
struct GUIPK {
  MyPkt *pk;
  string_view fm;
  int id;
  GUIPK() {
    pk = new MyPkt(100, [this](void *x, BinaryStream &b) -> void {
      b.writeUnsignedVarInt(id);
      b.writeUnsignedVarInt(fm.size());
      b.write(fm.data(), fm.size());
    });
  }
  void send(ServerPlayer &sp, string_view st, int i) {
    fm = st, id = i;
    sp.sendNetworkPacket(*pk);
  }
} gGUIPK;
static inline void sendStr(ServerPlayer &sp, string_view fm, int id) { gGUIPK.send(sp, fm, id); }
static int autoid;
BDL_EXPORT void sendForm(ServerPlayer &sp, SharedForm *fm) {
  auto x           = fm->serial();
  fm->fid          = ++autoid;
  if(player_mp.dat.count(&sp)){
    player_mp.defe(&sp);
  }
  player_mp[sp].sf=fm;
  //printf("%s\n",string(x).c_str());
  sendStr(sp, x, autoid);
}
THook(
    void *, _ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK23ModalFormResponsePacket, ServerNetworkHandler *sh,
    NetworkIdentifier const &iden, Packet *pk) {
  ServerPlayer *p = sh->_getServerPlayer(iden, pk->getClientSubId());
  if (p) {
    int id  = access(pk, int, 36);
    auto it = player_mp.dat.find(p);
    if (it != player_mp.dat.end()) {
      auto form=it->second.sf;
      if(id==form->fid){
        auto oldfre=form->needfree;
        form->needfree=false;
        player_mp.dat.erase(p); //WHY USE THIS SHIT HACK? A FORM CAN BE OPENED IN ANOTHER ONE
        //printf("recv %d %d\n",id,form->fid);
        form->process(p, access(pk, string, 40));
        form->needfree=oldfre;
        relForm(form);
      }
    }
  }
  return nullptr;
}

void gui_ChoosePlayer(
    ServerPlayer *sp, string_view text, string_view title, std::function<void(ServerPlayer *, string_view)> const &cb) {
  auto fm = getForm(title, text, false);
  fm->cb  = [cb](ServerPlayer *sp, string_view sv, int x) { cb(sp, sv); };
  auto vc = getSrvLevel()->getUsers();
  for (auto &i : *vc) { fm->addButton(i->getNameTag()); }
  sendForm(*sp, fm);
}
void cm(argVec &a, CommandOrigin const &b, CommandOutput &c) {
  auto sp = getSP(b.getEntity());
  ItemStack is;
  auto pis = createItemStack_static(3, 0, 10, &is);
  pis->setCustomLore({"kksk"});
  giveItem(*sp, pis);
  do_log("res %d", takeItem(*sp, &sp->getCarriedItem()));
  auto eid   = summon(sp->getRegion(), sp->getPos(), "zombie");
  Actor *act = getSrvLevel()->fetchEntity(eid, false);
  if (act) {
    do_log("get act");
    act->setNameTag("kksk");
    act->setScoreTag("kksk");
    act->setNameTagVisible(true);
    // act->setSize(10,10);
    act->setNameTagAlwaysVisible();
    is.~ItemStack();
    pis = createItemStack_static("diamond_sword", 1, &is);
    act->setCarriedItem(*pis);
    is.~ItemStack();
    pis = createItemStack_static("diamond_chestplate", 1, &is);
    pis->setCustomName("kksk");
    act->setArmor((ArmorSlot) 1, *pis);
  }
  return;
  /*
  auto& pos=sp->getPos();
  MyPkt pk(12,[&](void*,BinaryStream&bs){
  bs.writeUnsignedInt64(114514);
  bs.writeUnsignedInt64(114514); //uuid
  bs.writeStr("nmsl"); //username
      bs.writeUnsignedVarInt64(114514);
      bs.writeUnsignedVarInt64(114514);
      bs.writeStr("minecraft:player"); //platid
      bs.writeVec3(pos);
      bs.writeVec3({0,0,0});
      bs.writeVec3({0,0,0});
      bs.writeUnsignedVarInt(0); //item
      bs.writeUnsignedInt(4);
bs.writeUnsignedVarInt(4);bs.writeUnsignedVarInt(4);bs.writeStr("nmsl");
bs.writeUnsignedVarInt(38);bs.writeUnsignedVarInt(3);bs.writeFloat(5);
bs.writeUnsignedVarInt(53);bs.writeUnsignedVarInt(3);bs.writeFloat(5);
bs.writeUnsignedVarInt(54);bs.writeUnsignedVarInt(3);bs.writeFloat(5);
      for(int i=0;i<5;++i) bs.writeUnsignedVarInt(0);
      bs.writeSignedInt64(114514);
      bs.writeUnsignedVarInt(0);
      bs.writeStr("114514");
      bs.writeSignedInt(114514);
  });*/
  /*
  MyPkt pk(0x4a,[&](void*,BinaryStream&bs){
      bs.writeUnsignedVarInt64(sp->getUniqueID().id);
      bs.writeUnsignedVarInt(0);
      bs.writeStr("kksk");
      bs.writeFloat(0.5);
  });
  sp->sendNetworkPacket(pk);*/
}
void mod_init(std::list<string> &modlist) {
  do_log("Loaded " BDL_TAG "");
  load_helper(modlist);
  register_cmd("g", cm, "debug", 1);
}
