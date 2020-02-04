//_ZNK19PlayerCommandOrigin26isSelectorExpansionAllowedEv
static timeq<6, (int) (CLOCKS_PER_SEC * 0.35)> chatq;
static int FChatLimit;
static bool ChatLimit(ServerPlayer *p) {
  if (!FChatLimit || p->getPlayerPermissionLevel() > 1) return true;
  return chatq.push(p);
}

THook(
    void *, _ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK10TextPacket, ServerNetworkHandler *sh,
    NetworkIdentifier const &iden, Packet *pk) {
  ServerPlayer *p = sh->_getServerPlayer(iden, pk->getClientSubId());
  if (p) {
    if (ChatLimit(p)) return original(sh, iden, pk);
  }
  return nullptr;
}
THook(
    void *, _ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK20CommandRequestPacket, ServerNetworkHandler *sh,
    NetworkIdentifier const &iden, Packet *pk) {
  ServerPlayer *p = sh->_getServerPlayer(iden, pk->getClientSubId());
  if (p) {
    // 0x28

    if (ChatLimit(p)) {
      string &sv = access(pk, string, 0x28);
      async_log("[CMD] %s:%s\n", p->getNameTag().c_str(), sv.c_str());
      return original(sh, iden, pk);
    }
  }
  return nullptr;
}
THook(bool, _ZNK19PlayerCommandOrigin26isSelectorExpansionAllowedEv, CommandOrigin *_thi) { return isOp(*_thi); }