#pragma once

#include <string>
#include <vector>

class Item;

class ItemStack;

class ItemInstance {
  char filler[136];

public:
  ItemInstance();
  ItemInstance(ItemStack const &);

  ItemInstance &operator=(ItemInstance const &);

  std::vector<std::string> getCustomLore() const;
  bool isNull() const;
  void setCustomLore(std::vector<std::string> const &);
  inline ~ItemInstance() { asm("call _ZN12ItemInstanceD2Ev"); }
};