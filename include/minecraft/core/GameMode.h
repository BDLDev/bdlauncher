#pragma once
#include <global.h>
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
  
  ServerPlayer *getPlayer() { return player; }
  u64 attack(Actor &);
  u64 buildBlock(BlockPos const &, unsigned char);
  u64 destroyBlock(BlockPos const &, unsigned char);
  u64 useItem(ItemStack &);
  u64 useItemOn(ItemStack &, BlockPos const &, unsigned char, Vec3 const &, Block const *);

  //MakeAccessor(getPlayer, Player *, 8);
  uint64_t attack(Actor &);
  uint64_t buildBlock(BlockPos const &, unsigned char);
  uint64_t destroyBlock(BlockPos const &, unsigned char);
  uint64_t useItem(ItemStack &);
  uint64_t useItemOn(ItemStack &, BlockPos const &, unsigned char, Vec3 const &, Block const *);
};
