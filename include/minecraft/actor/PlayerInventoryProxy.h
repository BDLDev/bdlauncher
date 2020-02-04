#pragma once

#include <vector>

class ItemStack;
enum class ContainerID : unsigned long { DEFAULT = 0 };

class PlayerInventoryProxy {
public:
  bool add(ItemStack &, bool);
  bool canAdd(ItemStack const &);
  void clearInventory(int);
  void clearInventoryWithDefault(bool);
  int getHotbarSize();
  std::vector<ItemStack const *> getSlots() const;
  void setItem(int, ItemStack const &, ContainerID);
  bool removeResource(ItemStack const &);
  
  ItemStack &getItem(int, ContainerID) const;
  int getContainerSize(ContainerID) const;
  void clearSlot(int, ContainerID);
};