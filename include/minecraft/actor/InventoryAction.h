#pragma once

class ItemStack;
class InventorySource;
class InventoryAction {
public:
  char filler[288];
  InventorySource &getSource(void) const;
  ItemStack *getToItem(void) const;
  ItemStack *getFromItem(void) const;
  unsigned int getSlot(void) const;
};