#pragma once
//#include <MC.h>
#include <string>
#include <bdlexport.h>
class ItemStack;
class ServerPlayer;
struct ActorUniqueID;
class BlockSource;
class Vec3;

BDL_EXPORT ItemStack *createItemStack_static(short id, short aux, unsigned char amo, ItemStack *stk);
BDL_EXPORT ItemStack *createItemStack(short id, short aux, unsigned char amo);
BDL_EXPORT ItemStack *createItemStack_static(std::string const &name, unsigned char amo, ItemStack *stk);
BDL_EXPORT ItemStack *createItemStack(std::string const &name, unsigned char amo);

BDL_EXPORT void giveItem(ServerPlayer &sp, ItemStack *is);
BDL_EXPORT ActorUniqueID summon(BlockSource &bs, Vec3 const &vc, std::string const &name);
BDL_EXPORT bool takeItem_unsafe(ServerPlayer &sp, ItemStack *is);
BDL_EXPORT bool takeItem(ServerPlayer &sp, ItemStack *is);