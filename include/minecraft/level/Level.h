#pragma once

#include "global.h"
#include "minecraft/core/types.h"

#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <vector>

namespace mce {
struct UUID;
};

class LevelStorage;
class LevelData;
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
class ServerPlayer;
class CompoundTag;
class Random;

class BlockSourceListener {
public:
  virtual ~BlockSourceListener();
  virtual void onSourceCreated(BlockSource &);
  virtual void onSourceDestroyed(BlockSource &);
  virtual void onAreaChanged(BlockSource &, BlockPos const &, BlockPos const &);
  virtual void onBlockChanged(
      BlockSource &, BlockPos const &, unsigned int, Block const &, Block const &, int, ActorBlockSyncMessage const *);
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
  LevelStorage *getLevelStorage();
  MapItemSavedData& getMapSavedData(ActorUniqueID);
  MapItemSavedData& getMapSavedData(std::unique_ptr<CompoundTag, std::default_delete<CompoundTag> > const&);
  // ~ level-helper ~ //
  std::vector<std::unique_ptr<Actor>> &getActorVector() const ABITAG(level_helper);
  void forEachActor(std::function<bool(Dimension &, ActorUniqueID, Actor *)>) ABITAG(level_helper);
  void setTime(int);
  int getTime() const;
  void* getPacketSender() const;
  std::vector<std::unique_ptr<ServerPlayer>> *getUsers();

  void* save();
  ServerPlayer *getPlayer(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &) const;
  int getUserCount() const;
  int getTickedMobCountPrevious() const;
  Random* getRandom() const;
  LevelData* getLevelData();
  void broadcastLevelEvent(LevelEvent, CompoundTag const&, Player*);
  void broadcastLevelEvent(LevelEvent, Vec3 const&, int, Player*);
};

class ServerLevel : public Level {
  bool allPlayersSleeping() const;
  void stopWeather();
};
