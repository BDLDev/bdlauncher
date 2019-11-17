#pragma once

#include "Actor.h"

class ItemStack;

class ItemActor : public Actor {
public:
  ItemStack &getItemStack();
};