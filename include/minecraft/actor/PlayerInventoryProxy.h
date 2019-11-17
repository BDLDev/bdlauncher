#pragma once

#include <vector>

class ItemStack;
enum class ContainerID;

class PlayerInventoryProxy {
public:
  bool add(ItemStack &, bool);
  bool canAdd(ItemStack const &);
  void clearInventory(int);
  void clearInventoryWithDefault(bool);
  int getHotbarSize();
  std::vector<ItemStack const *> getSlots() const;
  void setItem(int, ItemStack const &, ContainerID);
  bool removeResource(ItemStack const&);
};