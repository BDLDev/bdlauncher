#pragma once

#include <memory>
#include <vector>

class Container;
class Actor;
class BlockSource;
class ItemStack;
class ItemActor;
class Player;
struct Vec3;
enum class ContainerType;

class ContainerComponent {
  std::unique_ptr<Container> pContainer;
  Actor *act;
  bool can_be_siphoned_from;
  bool mPrivate;
  bool restrict_to_owner;
  std::string loot_table;
  int loot;

public:
  std::vector<ItemStack const *> getSlots() const;
  void addItem(BlockSource &, ItemStack &, int, int);
  void addItem(ItemActor &);
  bool canBeSiphonedFrom() const;
  bool isPrivate() const;
  bool canOpenContainer(Player &) const;
  bool openContainer(Player &);
  int countItemsOfType(ItemStack const &);
  void removeItemsOfType(ItemStack const &);
  void setItem(int, ItemStack const &);
  void dropContents(BlockSource &, Vec3 const &, bool);
  bool hasRoomForItem(ItemActor &);
  void rebuildContainer(ContainerType, int, bool, int, bool);
  void setLootTable(std::string, int);
};