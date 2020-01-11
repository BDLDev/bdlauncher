#pragma once
#include "../../util.h"
class Actor;
class ItemStack;
class BlockPos;
class Block;
class Vec3;
class GameMode {
public:
  MakeAccessor(getPlayer, Player *, 8);
  u64 attack(Actor&);
  u64 buildBlock(BlockPos const&,unsigned char);
  u64 destroyBlock(BlockPos const&,unsigned char);	
  u64 useItem(ItemStack &);
  u64 useItemOn(ItemStack &,BlockPos const&,unsigned char,Vec3 const&,Block const*);	
};
