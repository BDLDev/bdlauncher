#pragma once

#include "Mob.h"

class Packet;
class ItemStack;
class ActorDamageSource;

class Player : public Mob {
public:
  virtual ~Player() override;

//  MakeAccessor(getName, std::string, 7224);
  std::string const& getName(){
	u64* ptr=*(u64**)((*(char**)this)+416);
	std::string const&(*fn)(Player*)=(typeof(fn))(ptr);
	return fn(this);
  }
  bool canUseAbility(AbilitiesIndex) const;
  PlayerInventoryProxy* getSupplies() const;
  ItemStack &getCarriedItem() const;
  void setCarriedItem(ItemStack const &);
  void add(ItemStack &);
  uint64_t attack(Actor &);	
  void die(ActorDamageSource const&);	
  void setBedRespawnPosition(BlockPos const&);	
  void setName(std::string const&);
  bool startCrafting(BlockPos const&, bool); //_ZN6Player13startCraftingERK8BlockPosb //broken!
  unsigned char getPlayerPermissionLevel() const;
  unsigned char getCommandPermissionLevel() const;
  float getDestroySpeed(Block const&) const;
  bool isCreative(void)const;
};

class ServerPlayer : public Player {
public:
  void sendNetworkPacket(Packet &) const;
  void disconnect(void);
  void sendInventory(bool);
};
