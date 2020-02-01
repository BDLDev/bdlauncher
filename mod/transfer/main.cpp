#include <string>

#include <Loader.h>
//#include <MC.h>
#include <minecraft/core/getSP.h>
#include <minecraft/actor/Player.h>
#include <minecraft/packet/MyPkt.h>
#include <minecraft/packet/BinaryStream.h>

#include "base.h"
#include "main.command.h"

const char meta[] __attribute__((used, section("meta"))) =
    "name:trans\n"
    "version:20200121\n"
    "author:sysca11\n"
    "depend:base@20200121,command@20200121\n";

extern "C" {
BDL_EXPORT void mod_init(std::list<std::string> &modlist);
}
extern void load_helper(std::list<std::string> &modlist);

void TransferCommand::invoke(mandatory<std::string> server, mandatory<int> port) {
  MyPkt trpk(0x55, [&](void *, BinaryStream &x) -> void {
    x.writeUnsignedVarInt(server.size());
    x.write(server.data(), server.size());
    x.writeUnsignedShort(port);
  });
  auto sp = getSP(getOrigin().getEntity());
  if (sp) {
    sp->sendNetworkPacket(trpk);
    getOutput().success();
  } else {
    getOutput().error("fucku");
  }
}

void mod_init(std::list<std::string> &modlist) {
  register_commands();
  do_log("loaded! V2019-12-14");
  load_helper(modlist);
}
