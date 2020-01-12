#pragma once

#include <MC.h>

BDL_EXPORT ItemStack *createItemStack_static(short id, short aux, unsigned char amo, ItemStack *stk);
BDL_EXPORT ItemStack *createItemStack(short id, short aux, unsigned char amo);
BDL_EXPORT ItemStack *createItemStack_static(string const &name, unsigned char amo, ItemStack *stk);
BDL_EXPORT ItemStack *createItemStack(string const &name, unsigned char amo);

BDL_EXPORT void giveItem(ServerPlayer &sp, ItemStack *is);
BDL_EXPORT ActorUniqueID summon(BlockSource &bs, Vec3 const &vc, string const &name);
BDL_EXPORT bool takeItem_unsafe(ServerPlayer &sp, ItemStack *is);
BDL_EXPORT bool takeItem(ServerPlayer &sp, ItemStack *is);