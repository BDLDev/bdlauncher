#pragma once

#include <string>
#include <vector>
#include "ItemStackBase.h"

class Item;
class ItemInstance;
class BlockLegacy;
class RecipeIngredient;

extern "C" {
void _ZN9ItemStackD0Ev(void *);
void _ZN9ItemStackD2Ev(void *);
};

class ItemStack : public ItemStackBase{
public:
  char filler[136];


  ItemStack();
  ItemStack(BlockLegacy const&, int);
  ItemStack(RecipeIngredient const&);
  ItemStack(ItemStack const &);
  ItemStack(ItemInstance const &);
  ItemStack(Item const &);
  ItemStack(Item const&, int);
  ItemStack operator=(ItemStack const&);
  // void clone(ItemStack const &);
  //  operator bool(void) const;
  //~ItemStack();
  inline ~ItemStack() { _ZN9ItemStackD2Ev(this); }
  float getDestroySpeed(Block const &) const;

  inline void defunct_cfree() { _ZN9ItemStackD0Ev(this); }
};
