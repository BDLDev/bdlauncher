
class ItemStack;
class InventorySource;
class InventoryAction {
  char filler[288];
  InventorySource &getSource(void) const;
  ItemStack *getToItem(void) const;
  ItemStack *getFromItem(void) const;
  unsigned int getSlot(void) const;
};