#pragma once

#include "../core/types.h"

class Block;
class BlockActor;
class ActorBlockSyncMessage;

class BlockSource {
public:
  bool hasBlock(BlockPos const &) const;
  Block &getBlock(BlockPos const &) const;
  Block &getExtraBlock(BlockPos const &) const;

  BlockActor *getBlockEntity(BlockPos const &);

  void setBlock(BlockPos const &, Block const &, int, ActorBlockSyncMessage const *);
  void setBlockNoUpdate(BlockPos const &, Block const &);
  bool setExtraBlock(BlockPos const &, Block const &, int flag);
};
