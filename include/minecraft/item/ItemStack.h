#pragma once

#include <string>
#include <vector>
#include "ItemStackBase.h"

class Item;
class ItemInstance;

extern "C" {
void _ZN9ItemStackD0Ev(void *);
void _ZN9ItemStackD2Ev(void *);
}

class ItemStack : public ItemStackBase{
  char filler[136];

public:
  ItemStack();
  ItemStack(ItemStack const &);
  ItemStack(ItemInstance const &);
  ItemStack(const Item &, int amo);
  ItemStack &operator=(ItemStack const &);
  // void clone(ItemStack const &);
  std::vector<std::string> getCustomLore() const;
  bool isNull() const;
  void setCustomLore(std::vector<std::string> const &);
  //  operator bool(void) const;
  //~ItemStack();
  inline ~ItemStack() { asm("call _ZN9ItemStackD2Ev"); };
  short getId() const;
  float getDestroySpeed(Block const &) const;
  std::string toString() const;
  bool operator!=(ItemStack const &) const;
  bool isOffhandItem() const;

  ItemStack(ItemStack const &);
  inline void defunct_cfree() { _ZN9ItemStackD0Ev(this); }
  inline ~ItemStack() { _ZN9ItemStackD2Ev(this); }
};
