#pragma once

#include "../core/types.h"

#include "CommandOrigin.h"

class CommandPosition {
  Vec3 vec;
  bool mx, my, mz;
  bool op;

public:
  BlockPos getBlockPos(CommandOrigin const &, Vec3 const &) const;
  BlockPos getBlockPos(Vec3 const &, Vec3 const &) const;
  Vec3 getPosition(CommandOrigin const &, Vec3 const &) const;
  Vec3 getPosition(Vec3 const &, Vec3 const &) const;
};

class CommandPositionFloat : public CommandPosition {};