#pragma once

#include <memory>
#include <string>
#include <vector>

class BlockPalette;
class CompoundTag;
class DataLoadHelper;
class BlockSource;
class Packet;
struct BlockPos{
	int x,int y,int z;
};
class Actor;
class UIProfanityContext;
class Container;

class BlockActor {
public:
  virtual ~BlockActor();
  virtual void load(BlockPalette const &, CompoundTag const &, DataLoadHelper &);
  virtual bool save(CompoundTag &) const;
  virtual bool saveItemInstanceData(CompoundTag &);
  virtual bool saveBlockData(CompoundTag &, BlockSource &) const;
  virtual void loadBlockData(CompoundTag const &, BlockSource &, DataLoadHelper &);
  virtual void onCustomTagLoadDone(BlockSource &);
  virtual void tick(BlockSource &);
  virtual bool isFinished();
  virtual void onChanged(BlockSource &);
  virtual bool isMovable(BlockSource &);
  virtual bool isCustomNameSaved();
  virtual std::unique_ptr<Packet> getUpdatePacket(BlockSource &);
  virtual void onPlace(BlockSource &);
  virtual void onUpdatePacket(CompoundTag const &, BlockSource &);
  virtual void onMove();
  virtual void onRemoved(BlockSource &);
  virtual void triggerEvent(int, int);
  virtual void clearCache();
  virtual void onNeighborChanged(BlockSource &, BlockPos const &);
  virtual float getShadowRadius(BlockSource &) const;
  virtual bool hasAlphaLayer() const;
  virtual Actor *getCrackEntity(BlockSource &, BlockPos const &);
  virtual void getDebugText(std::vector<std::string> &, BlockPos const &);
  virtual std::string const &getCustomName() const;
  virtual std::string getFilteredCustomName(UIProfanityContext const &);
  virtual std::string getName() const;
  virtual unsigned getRepairCost() const;
  virtual bool getOwningPiston(BlockSource &);
  virtual Container *getContainer();
  virtual void getDeletionDelayTimeSeconds();
};
