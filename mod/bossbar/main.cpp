#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
#include <Loader.h>
#include <MC.h>
#include <unistd.h>
#include <cstdarg>
#include "bossbar.command.h"

#include "base.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using std::string;
using std::unordered_map;

const char meta[] __attribute__((used,section(".meta")))="name:bossbar\n"\
"version:20200121\n"\
"author:sysca11\n"\
"depend:base@20200121,command@20200121\n"\
;
extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);
LDBImpl db("data_v2/bossbar");
struct VEntBase {
  unsigned long eid;
  virtual void packto(DataStream &ds) const = 0;
  virtual void unpack(DataStream &ds)       = 0;
  virtual void sendTo(ServerPlayer *sp)     = 0;
  virtual void onClick(ServerPlayer *sp)    = 0;
};
struct FText : VEntBase {
  int x, y, z;
  int dim;
  string text;
  MyPkt pk = MyPkt(12, [this](void *, BinaryStream &bs) {
    bs.writeUnsignedInt64(eid);
    bs.writeUnsignedInt64(114514); // uuid
    bs.writeStr(text);             // username
    bs.writeUnsignedVarInt64(114514);
    bs.writeUnsignedVarInt64(114514);
    bs.writeStr("wtfwtf"); // platid
    bs.writeVec3({static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)});
    bs.writeVec3({0, 0, 0});
    bs.writeVec3({0, 0, 0});
    bs.writeUnsignedVarInt(0); // item
    bs.writeUnsignedInt(4);
    bs.writeUnsignedVarInt(4);
    bs.writeUnsignedVarInt(4);
    bs.writeStr(text);
    bs.writeUnsignedVarInt(38);
    bs.writeUnsignedVarInt(3);
    bs.writeFloat(0.001);
    bs.writeUnsignedVarInt(53);
    bs.writeUnsignedVarInt(3);
    bs.writeFloat(0.001);
    bs.writeUnsignedVarInt(54);
    bs.writeUnsignedVarInt(3);
    bs.writeFloat(0.001);
    for (int i = 0; i < 5; ++i) bs.writeUnsignedVarInt(0);
    bs.writeSignedInt64(114514);
    bs.writeUnsignedVarInt(0);
    bs.writeStr("114514");
    bs.writeSignedInt(114514);
  });

  void packto(DataStream &ds) const { ds << x << y << z << eid << text << dim; }
  void unpack(DataStream &ds) { ds >> x >> y >> z >> eid >> text >> dim; }
  void sendTo(ServerPlayer *sp) { sp->sendNetworkPacket(pk); }
  void onClick(ServerPlayer *sp) {}
};
unordered_map<unsigned long, vector<std::unique_ptr<VEntBase>>> ents;
THook(void *, _ZN5Level13onNewChunkForER6PlayerR10LevelChunk, ServerLevel *sv, ServerPlayer *sp, LevelChunk *lc) {
  return original(sv, sp, lc);
}
const unsigned long bbid = 1145141919ull;
void MoveBB(ServerPlayer *sp) {
  MyPkt pk(0x12, [&](void *, BinaryStream &bs) {
    bs.writeUnsignedVarInt64(bbid);
    bs.writeByte(3);
    auto &pos = sp->getPos();
    bs.writeVec3({pos.x, -10, pos.z});
    bs.writeUnsignedInt(0); // 3*bytes
  });
  sp->sendNetworkPacket(pk);
}
void SendBB(ServerPlayer *sp, string_view bbar, bool show = true) {
  MyPkt pk(0x4a, [&](void *, BinaryStream &bs) {
    bs.writeUnsignedVarInt64(bbid);
    bs.writeUnsignedVarInt(show ? 0 : 2);
    bs.writeStr(bbar);
    bs.writeFloat(0.5);
  });
  sp->sendNetworkPacket(pk);
}
void CreateEntBB(ServerPlayer *sp) {
  MyPkt pk(0x0d, [&](void *, BinaryStream &bs) {
    bs.writeUnsignedVarInt64(bbid);
    bs.writeUnsignedVarInt64(bbid);
    bs.writeStr("minecraft:pig");
    auto &pos = sp->getPos();
    bs.writeVec3({pos.x, -10, pos.z});
    bs.writeVec3({0, 0, 0});
    bs.writeVec3({0, 0, 0});
    bs.writeUnsignedVarInt(0); // attr
    bs.writeUnsignedVarInt(0); // meta
    bs.writeUnsignedVarInt(0); // link
  });
  sp->sendNetworkPacket(pk);
}

void BossbarCommand::show(mandatory<Show>, mandatory<CommandSelector<Player>> targets, mandatory<std::string> text) {
  auto results = targets.results(getOrigin());
  if (!Command::checkHasTargets(results, getOutput())) return;
  for (auto &player : results) {
    auto sp = getSP(player);
    if (!sp) continue;
    SendBB(sp, "", false);
    CreateEntBB(sp);
    SendBB(sp, text, true);
    if (getOutput().wantsData()) getOutput().addToResultList("target", *sp);
  }
  if (getOutput().wantsData()) getOutput().set("text", text);
  getOutput().success();
}

void BossbarCommand::hide(mandatory<Hide>, mandatory<CommandSelector<Player>> targets) {
  auto results = targets.results(getOrigin());
  if (!Command::checkHasTargets(results, getOutput())) return;
  for (auto &player : results) {
    auto sp = getSP(player);
    if (!sp) continue;
    SendBB(sp, "", false);
    if (getOutput().wantsData()) getOutput().addToResultList("target", *sp);
  }
  getOutput().success();
}

static string PinnedBBar;

void BossbarCommand::pin(mandatory<Pin>, mandatory<std::string> text) {
  PinnedBBar = text;
  for (auto &player : *getSrvLevel()->getUsers()) {
    auto sp = getSP(player);
    SendBB(sp, "", false);
    CreateEntBB(sp);
    SendBB(sp, text, true);
    if (getOutput().wantsData()) getOutput().addToResultList("target", *sp);
  }
  if (getOutput().wantsData()) getOutput().set("text", text);
  getOutput().success();
}

void BossbarCommand::unpin(mandatory<Unpin>) {
  PinnedBBar.clear();
  for (auto &player : *getSrvLevel()->getUsers()) {
    auto sp = getSP(player);
    SendBB(sp, "", false);
    if (getOutput().wantsData()) getOutput().addToResultList("target", *sp);
  }
  getOutput().success();
}

static void onJoin(ServerPlayer *sp) {
  if (PinnedBBar.size()) {
    CreateEntBB(sp);
    SendBB(sp, PinnedBBar, true);
  }
}

void mod_init(std::list<string> &modlist) {
  db.Get("pinned", PinnedBBar);
  register_commands();
  do_log("Loaded " BDL_TAG "");
  reg_player_join(onJoin);
  load_helper(modlist);
}
