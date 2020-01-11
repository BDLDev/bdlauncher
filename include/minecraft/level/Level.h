#pragma once

#include "../../util.h"
#include "../core/types.h"

#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <vector>

class LevelStorage;
class BlockSource;
class Block;
class ActorBlockSyncMessage;
class BlockActor;
class Dimension;
class PlayerListEntry;
class Player;
class BlockPalette;
class MapItemSavedData;
class ItemStack;
class BlockSourceListener {
public:
  virtual ~BlockSourceListener();
  virtual void onSourceCreated(BlockSource &);
  virtual void onSourceDestroyed(BlockSource &);
  virtual void onAreaChanged(BlockSource &, BlockPos const &, BlockPos const &);
  virtual void onBlockChanged(BlockSource &, BlockPos const &, unsigned int, Block const &, Block const &, int, ActorBlockSyncMessage const *);
  virtual void onBrightnessChanged(BlockSource &, BlockPos const &);
  virtual void onBlockEntityChanged(BlockSource &, BlockActor &);
  virtual void onBlockEntityAboutToBeRemoved(BlockSource &, std::shared_ptr<BlockActor>);
  virtual void onEntityChanged(BlockSource &, Actor &);
  virtual void onBlockEvent(BlockSource &, int, int, int, int, int);
};

class Level : public BlockSourceListener {
public:
  void spawnParticleEffect(std::string const &, Actor const &, Vec3 const &);
  void forEachDimension(std::function<bool(Dimension &)>);
  float getChunkTickRange() const;
  Actor *fetchEntity(ActorUniqueID, bool) const;
  std::unordered_map<mce::UUID, PlayerListEntry> &getPlayerList();
  static bool isUsableLevel(Level *);
  void forEachPlayer(std::function<bool(Player &)>);
  BlockPalette *getGlobalBlockPalette() const;
  LevelStorage* getLevelStorage();
  MapItemSavedData& getMapSavedData(ItemStack const&);
  // ~ level-helper ~ //
  std::vector<std::unique_ptr<Actor>> &getActorVector() const ABITAG(level_helper);
  void forEachActor(std::function<bool(Dimension &, ActorUniqueID, Actor *)>) ABITAG(level_helper);
};

class ServerLevel : public Level {};
