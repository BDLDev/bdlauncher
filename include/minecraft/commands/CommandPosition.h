#pragma once

#include "../core/types.h"

#include "CommandOrigin.h"

class CommandPosition {
  Vec3 vec;
  bool mx, my, mz;
  bool op;

public:
  BlockPos getBlockPos(CommandOrigin const &) const;
  Vec3 getPosition(CommandOrigin const &) const;
};