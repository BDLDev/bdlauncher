class ItemStack;
struct FillingContainer {
  int getContainerSize() const;
  ItemStack &getItem(int) const;
};