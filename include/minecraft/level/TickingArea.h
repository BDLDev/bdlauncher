#pragma once

#include "ITickingArea.h"

class BlockSource;

class TickingArea : public ITickingArea {
public:
  BlockSource *getBlockSource();
};