#pragma once

#include "../core/types.h"

#include <functional>
#include <string>
#include <vector>

class ContainerContentChangeListener;
class ItemStack;
class BlockSource;
class Player;
class CompoundTag;
class ItemStack;

class Container {
public:
  virtual ~Container();
  virtual void init();
  virtual void addContentChangeListener(ContainerContentChangeListener *);
  virtual void removeContentChangeListener(ContainerContentChangeListener *);
  virtual ItemStack const &getItem(int) const = 0;
  virtual bool hasRoomForItem(ItemStack &);
  virtual bool addItem(ItemStack &);
  virtual bool addItemToFirstEmptySlot(ItemStack &);
  virtual void setItem(int, ItemStack const &) = 0;
  virtual void removeItem(int, int);
  virtual void removeAllItems();
  virtual void dropContents(BlockSource &, Vec3 const &, bool);
  virtual int getContainerSize() const = 0;
  virtual int getMaxStackSize() const  = 0;
  virtual void startOpen(Player &)     = 0;
  virtual void stopOpen(Player &)      = 0;
  virtual std::vector<ItemStack> getSlotCopies() const;
  virtual std::vector<ItemStack const *> getSlots() const;
  virtual int getItemCount();
  virtual int getItemCount(ItemStack const &);
  virtual int findFirstSlotForItem(ItemStack const&);
  virtual bool canPushInItem(BlockSource &, int, int, ItemStack const &) const;
  virtual bool canPullOutItem(BlockSource &, int, int, ItemStack const &) const;
  virtual void setContainerChanged(int);
  virtual void setContainerMoved();
  virtual void setCustomName(std::string const &);
  virtual bool hasCustomName() const;
  virtual void readAdditionalSaveData(CompoundTag const &);
  virtual void addAdditionalSaveData(CompoundTag &);
  virtual void createTransactionContext(std::function<void(Container &, int, ItemStack const &, ItemStack const &)>, std::function<void()>);
  virtual void triggerTransactionChange(int, ItemStack const &, ItemStack const &);
};