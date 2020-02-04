
static ServerPlayer *last_hide_sp;
THook(void *, _ZN5Actor9addEffectERK17MobEffectInstance, Actor &ac, MobEffectInstance *mi) {
  if (mi->getId() == 14) {
    auto sp = getSP(ac);
    if (sp) {
      if (sp->getPlayerPermissionLevel() <= 1) {
        if (sp != last_hide_sp) {
          async_log("[EFFECT] %s used self-hiding effect\n", sp->getNameTag().c_str());
          last_hide_sp = sp;
        }
      }
    }
  }
  return original(ac, mi);
}