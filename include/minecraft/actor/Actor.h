#pragma once
#include <cstdint>
#include <cstring>
#include <memory>
#include <vector>
#include "../core/types.h"
#include "../core/access.h"
#include "global.h"

class EntityContext;
class SimpleContainer;
class ActorDefinitionDescriptor;
class Attribute;
class BaseAttributeMap;
class AttributeInstance;
class PlayerInventoryProxy;
class BlockSource;
class TickingArea;
class CompoundTag;
class Dimension;
class ItemActor;
class ItemStack;
class MobEffect;
class Mob;
class ServerPlayer;
enum class ArmorSlot;

class Actor {
public:
  MakeAccessor(getActorDefinitionDescriptor, std::unique_ptr<ActorDefinitionDescriptor>, 192);
  MakeAccessor(getBlockSource, std::unique_ptr<BlockSource>, 5952);
  bool hasTickingArea() const;
  bool hasCategory(ActorCategory) const;
  EntityContext &getEntity();
  ActorUniqueID const &getUniqueID() const;
  SimpleContainer &getArmorContainer();
  SimpleContainer &getHandContainer();
  BaseAttributeMap *getAttributes();
  AttributeInstance const &getAttribute(Attribute const &) const;
  TickingArea *getTickingArea();
  bool save(CompoundTag &);
  int getEntityTypeId() const;
  uint64_t pickUpItem(ItemActor &);
  void kill();
  void changeDimension(AutomaticID<Dimension, int>, bool);
  int getDimensionId() const;
  bool isRiding() const;
  ItemStack &getOffhandSlot() const;
  template <typename T> T *tryGetComponent();
  void setPos(Vec3 const &);
  virtual ~Actor();

  const std::string &getNameTag() const;
  uint64_t getNameTagAsHash() const; // fix it
  Vec3 const &getPos() const;
  std::vector<MobEffect> &getAllEffects() const;
  BlockSource &getRegion() const;
  Dimension &getDimension() const;
  long getRuntimeID() const;
  void setNameTag(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &);
  void setScoreTag(std::string const &);
  Mob *getOwner() const;
  ServerPlayer *getPlayerOwner() const;
  int getOwnerEntityType();
  ActorUniqueID getOwnerId() const;
  void setNameTagVisible(bool);
  inline void setNameTagAlwaysVisible() { getDATA()->set(80, (signed char) 1); }
  inline void setSize(float scale, float bbox) {
    getDATA()->set(38, scale);
    getDATA()->set(53, bbox);
    getDATA()->set(54, bbox);
  }
  void setArmor(ArmorSlot, ItemStack const &);
  void setCarriedItem(ItemStack const &);
  void setAutonomous(bool);
  inline SynchedActorData *getDATA() { return (SynchedActorData *) (((uintptr_t) this) + 0x130); }
};
