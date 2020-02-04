#pragma once
class Player;
class ItemStack;
class InventoryTransactionManager {
public:
  char filler[40];
Player *getPlayer() const {
return *(Player **) this; 
}
  void _createServerSideAction(ItemStack const &, ItemStack const &);
};