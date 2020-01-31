#pragma once
#include "global.h"
#include <cstdint>
class Actor;
class ItemStack;
class BlockPos;
class Block;
class Vec3;
class GameMode {
public:
  void* vtbl;
  ServerPlayer *player;

  inline ServerPlayer *getPlayer() { return player; }
  //MakeAccessor(getPlayer, Player *, 8);
  uint64_t attack(Actor &);
  uint64_t buildBlock(BlockPos const &, unsigned char);
  uint64_t destroyBlock(BlockPos const &, unsigned char);
  uint64_t useItem(ItemStack &);
  uint64_t useItemOn(ItemStack &, BlockPos const &, unsigned char, Vec3 const &, Block const *);
};
