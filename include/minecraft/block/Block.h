#pragma once

#include "global.h"
#include "../core/NBT.h"
#include <memory>
#include <string>

class Block;
class BlockProperty {
public:
  unsigned long x;
};

class BlockLegacy {
public:
  void addBlockProperty(BlockProperty);
  std::string const &getRawNameId() const;
  Block const *getDefaultState() const;
  short getBlockItemId() const;
};

class Block {
public:
  CompoundTag const &getSerializationId() const;
  std::string const &getDescriptionId() const;
  std::string getFullName() const;
  BlockLegacy *getLegacyBlock() const;
  MakeAccessor(getTag, CompoundTag, 80);
  MakeAccessor(getLegacy, BlockLegacy *, 16);
  bool isContainerBlock() const;
};
