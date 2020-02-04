#pragma once

#include "Mob.h"
#include "minecraft/net/Connection.h"
#include <string>

class Packet;
class ItemStack;
class ActorDamageSource;
struct Certificate;
struct ExtendedCertificate;
class Block;
class FillingContainer;
class InventoryTransactionManager;
enum class AbilitiesIndex;

class Player : public Mob {
public:
  virtual ~Player() override;

  //  MakeAccessor(getName, std::string, 7224);
  /*std::string const& getName(){
        u64* ptr=*(u64**)((*(char**)this)+416);
        std::string const&(*fn)(Player*)=(typeof(fn))(ptr);
        return fn(this);
  }*/
  void stopSleepInBed(bool, bool);
  bool isPlayerInitialized() const;
  std::string getRealNameTag() const { return ExtendedCertificate::getIdentityName(getCertificate()); }
  unsigned char getClientSubId() const;
  FillingContainer *getEnderChestContainer();
  InventoryTransactionManager *getTransactionManager();
  void updateInventoryTransactions();
  
  std::string getName() { return ExtendedCertificate::getIdentityName(getCertificate()); }
  bool canUseAbility(AbilitiesIndex) const;
  // TODO fix
  /*PlayerInventoryProxy *getSupplies() const;*/
  PlayerInventoryProxy &getSupplies() const;
  ItemStack &getCarriedItem() const;
  void setCarriedItem(ItemStack const &);
  void add(ItemStack &);
  uint64_t attack(Actor &);
  void die(ActorDamageSource const &);
  void setBedRespawnPosition(BlockPos const &);
  void setName(std::string const &);
  bool startCrafting(BlockPos const &, bool); //_ZN6Player13startCraftingERK8BlockPosb //broken!
  // TODO fix
  /*int getCommandPermissionLevel() const;*/
  unsigned char getPlayerPermissionLevel() const;
  unsigned char getCommandPermissionLevel() const;
  float getDestroySpeed(Block const &) const;
  bool isCreative(void) const;
  Certificate &getCertificate() const;
  std::string getXUID() const { return ExtendedCertificate::getXuid(getCertificate()); }
};

class ServerPlayer : public Player {
public:
  void stopSleepInBed(bool, bool);
  void sendNetworkPacket(Packet &) const;
  void sendInventory(bool);
  void disconnect();
};
