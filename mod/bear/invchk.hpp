static string dumpSP(ServerPlayer &sp) {
  string ret;
  auto &x = sp.getSupplies();
  int sz  = x.getContainerSize((ContainerID) 0ul);
  for (int i = 0; i < sz; ++i) {
    auto &item = x.getItem(i, (ContainerID) 0ul);
    ret += item.toString() + " | ";
  }
  return ret;
}
static string dumpSP_Ender(ServerPlayer &sp) {
  string ret;
  auto *x = sp.getEnderChestContainer();
  if (!x) {
    do_log("no ender found");
    return "";
  }
  int sz = x->getContainerSize();
  for (int i = 0; i < sz; ++i) {
    auto &item = x->getItem(i);
    ret += item.toString() + " | ";
  }
  return ret;
}
static string dumpall(ServerPlayer *sp) {
  string ret;
  ret = dumpSP(*sp);
  ret += "\n-----starting ender chest dump-----\n";
  ret += dumpSP_Ender(*sp) + "\n";
  return ret;
}
void ACCommand::invchk(mandatory<Invchk>, mandatory<CommandSelector<Player>> target) {
  auto results = target.results(getOrigin());
  if (!Command::checkHasTargets(results, getOutput())) return;
  for (auto &player : results) {
    auto sp = getSP(player);
    if (!sp) continue;
    auto dmp = dumpall(sp);
    getOutput().addMessage("---dump for " + sp->getNameTag() + "---\n" + dmp);
  }
  getOutput().success();
}