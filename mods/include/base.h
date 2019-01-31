#pragma once

#include <exception>

#include <polyfill.h>

#include <minecraft/net/NetworkIdentifier.h>
#include <minecraft/net/UUID.h>

#include <log.h>
#include <memory>
#include <unordered_map>

struct Item;

struct ItemRegistry {
  static std::unordered_map<std::string, std::unique_ptr<Item>> mItemLookupMap;
  static Item *getItem(short id);
  static Item *lookupByName(std::string const &str, bool);
};

struct Item {
  unsigned short filler[0x1000];
  Item(Item const &) = delete;
  Item &operator=(Item const &) = delete;
  short getId() const;
  bool operator==(Item const &rhs) const { return this == &rhs; }
};

struct EntityUniqueID {
  long long high, low;
};

struct EntityRuntimeID {
  long long eid = 0;
};

struct Vec3;

struct BlockPos {
  int x, y, z;
  BlockPos();
  BlockPos(int x, int y, int z)
      : x(x)
      , y(y)
      , z(z) {}
  BlockPos(Vec3 const &);
  BlockPos(BlockPos const &p)
      : x(p.x)
      , y(p.y)
      , z(p.z) {}
  BlockPos const &operator=(BlockPos const &);
  bool operator==(BlockPos const &);
  bool operator!=(BlockPos const &);
};

struct Vec3 {
  float x, y, z;
  Vec3(float x, float y, float z)
      : x(x)
      , y(y)
      , z(z) {}
  Vec3(BlockPos const &);
  Vec3()             = default;
  Vec3(Vec3 const &) = default;

  static Vec3 ZERO;
};

struct Vec2 {
  static Vec2 ZERO;
  float x, y;
};

template <typename Type, typename Store> struct AutomaticID {
  Store v;
  template <typename X>
  AutomaticID(X v)
      : v(v) {}
  Store value() const;
  bool operator!=(AutomaticID const &) const;
  bool operator==(AutomaticID const &) const;
  operator Store() const { return v; }
  static Store _makeRuntimeID();
};

struct Dimension;
struct Biome;
using DimensionId = AutomaticID<Dimension, int>;
using BiomeId     = AutomaticID<Biome, int>;

struct BinaryStream;
struct NetEventCallback;

struct Packet {
  int unk_4 = 2, unk_8 = 1;
  unsigned char playerSubIndex = 0;

  Packet(unsigned char playerSubIndex)
      : playerSubIndex(playerSubIndex) {}
  Packet(){}
/*
  virtual ~Packet();
  virtual void *getId() const                                               = 0;
  virtual void *getName() const                                             = 0;
  virtual void *write(BinaryStream &) const                                 = 0;
  virtual void *read(BinaryStream &)                                        = 0;
  virtual void *handle(NetworkIdentifier const &, NetEventCallback &) const = 0;
  virtual bool disallowBatching() const;*/
};

struct BlockEntity {
  void setData(int val);
  int getData() const;
  void setChanged();
};

struct Biome;
struct Block;
struct BlockSource;
struct ItemInstance;

struct BlockLegacy {
  Block *getBlockStateFromLegacyData(unsigned char) const;
  std::string getFullName() const;
};

struct Block {
  BlockLegacy *getLegacyBlock() const;
  ItemInstance *asItemInstance(BlockSource &, BlockPos const &) const;
};

struct ActorBlockSyncMessage;

struct BlockSource {
  BlockEntity *getBlockEntity(BlockPos const &);
  Biome *getBiome(BlockPos const &);
  Block *getBlock(BlockPos const &) const;
  Block *getExtraBlock(BlockPos const &) const;

  void setBlock(BlockPos const &, Block const &, int, ActorBlockSyncMessage const *);
};

struct ItemInstance;
struct CompoundTag;

struct Actor {
  const std::string &getNameTag() const;
  EntityRuntimeID getRuntimeID() const;
  Vec2 const &getRotation() const;
  Vec3 const &getPos() const;
  struct Level &getLevel() const;
  int getDimensionId() const;
  void changeDimension(DimensionId, bool);
  void getDebugText(std::vector<std::string> &);
  BlockSource &getRegion() const;
  void setOffhandSlot(ItemInstance const &);
  bool save(CompoundTag &);
  struct Player* getPlayerOwner() const;
  int getEntityTypeId()	const;
  virtual ~Actor();
};

struct Mob : Actor {
  float getYHeadRot() const;
};

struct Certificate {};

struct ExtendedCertificate {
  static std::string getXuid(Certificate const &);
};

static auto const uuidoffset = 5704;
//struct Player;
//mce::UUID &Player::getUUID() { return *(mce::UUID *)((char *)this + uuidoffset); }

struct Player : Mob {
  void remove();
  Certificate &getCertificate() const;
  mce::UUID &getUUID() const;  // requires bridge
  std::string getXUID() const; // requires bridge
  NetworkIdentifier const &getClientId() const;
  unsigned char getClientSubId() const;
  BlockPos getSpawnPosition();
  bool setRespawnPosition(BlockPos const &, bool);
  bool setBedRespawnPosition(BlockPos const &);
  int getCommandPermissionLevel() const;
  bool isSurvival() const;
  bool isAdventure() const;
  bool isCreative() const;
  bool isWorldBuilder();
  void sendNetworkPacket(Packet &packet) const;
  void setOffhandSlot(ItemInstance const &);
  std::string* getPlayerName(){return (std::string*)((long)this+5400);};
  struct PacketSender* getPKSender(){return (PacketSender*)((long)this+6472);};
};
mce::UUID &Player::getUUID() const { return *(mce::UUID *)((char *)this + uuidoffset); }
std::string Player::getXUID() const { return ExtendedCertificate::getXuid(getCertificate()); }
struct ServerPlayer : Player {
  void disconnect();
  void changeDimension(DimensionId, bool);
  void sendNetworkPacket(Packet &packet) const;
  void openInventory();
};

struct PacketSender {
  virtual ~PacketSender();
  virtual void send(Packet&)=0;
  virtual void sendToServer(Packet&)=0;
  virtual void sendToClient(NetworkIdentifier const &, Packet const &, unsigned char) = 0;
};

struct LevelStorage {
  void save(Actor &);
};

struct Dimension;
struct Spawner;
enum ParticleType : int {};
struct TickingAreasManager{
};
struct Level {
  LevelStorage *getLevelStorage();
  ServerPlayer *getPlayer(const std::string &name) const;
  ServerPlayer *getPlayer(mce::UUID const &uuid) const;
  ServerPlayer *getPlayer(EntityUniqueID uuid) const;
  PacketSender &getPacketSender() const;
  Spawner &getSpawner() const;
  void forEachPlayer(std::function<bool(Player &)>);
  BlockPos const &getDefaultSpawn() const;
  void setDefaultSpawn(BlockPos const &);
  Dimension *getDimension(DimensionId) const;
  void addEntity(BlockSource &, std::unique_ptr<Actor>);
  void addAutonomousEntity(BlockSource &, std::unique_ptr<Actor>);
  void *addParticle(ParticleType type, Vec3 const &pos, Vec3 const &mot, int dim, CompoundTag const *, bool);

  void suspendPlayer(Player &);
  void resumePlayer(Player &);
  TickingAreasManager& getTickingAreasMgr() const;
};

struct ParticleTypeMap {
  static std::string getParticleName(ParticleType type);
  static ParticleType getParticleTypeId(std::string const &name);
};

std::string getEntityName(Actor const &);

struct ItemActor : Actor {
  ItemInstance &getItemInstance();
};

struct Spawner {
  ItemActor *spawnItem(BlockSource &, ItemInstance const &, Actor *, Vec3 const &, int);
};

struct DedicatedServer {
  void stop();
};

struct NetworkStats {
  int32_t filler, ping, avgping, maxbps;
  float packetloss, avgpacketloss;
};

struct NetworkPeer {
  virtual ~NetworkPeer();
  virtual void sendPacket();
  virtual void receivePacket();
  virtual NetworkStats getNetworkStatus(void);
};

struct NetworkHandler {
  NetworkPeer &getPeerForUser(NetworkIdentifier const &);
};

struct ServerNetworkHandler : NetworkHandler {
  void disconnectClient(NetworkIdentifier const &, std::string const &, bool);
  ServerPlayer *_getServerPlayer(NetworkIdentifier const &, unsigned char);
  void _displayGameMessage(Player const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&);
};

struct MinecraftCommands;

struct Minecraft {
  void init(bool);
  void activateWhitelist();
  Level &getLevel() const;
  ServerNetworkHandler &getNetworkHandler();
  ServerNetworkHandler &getNetEventCallback();
  MinecraftCommands &getCommands();
};

struct ServerCommand {
  static Minecraft *mGame;
};

struct ServerInstance {
  void *vt, *filler;
  DedicatedServer *server;
  void queueForServerThread(std::function<void()> p1);
};

enum struct InputMode { UNK };

struct CompoundTag;

struct ItemInstance {
  char filler[112];
  ItemInstance();
  ItemInstance(Item const &);
  ItemInstance(Item const &, int number);
  ItemInstance(Item const &, int number, int auxValue);
  ItemInstance(Item const &, int number, int auxValue, CompoundTag const *);
  bool isNull() const;
  short getId() const;
  std::string getName() const;
  std::string getCustomName() const;
  std::string toString() const;
  std::unique_ptr<CompoundTag> &getUserData();
  void getUserData(std::unique_ptr<CompoundTag> tag);

  bool isOffhandItem() const;

  static ItemInstance EMPTY_ITEM;
};
struct ItemUseCallback;
struct Blacklist
{
  struct Entry{
    std::string* getXUID(){
      return (std::string*)((char*)this+16);
    }
  };
};
enum class TextPacketType;
struct TextPacket : Packet
{
  char filler[0xff];
  TextPacket(){};
  TextPacket(TextPacketType, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&, bool, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&);
  TextPacket createJukeboxPopup(std::string const &);
  TextPacket createSystemMessage(std::string const &);
  void SendTo(Player* p) { ((ServerPlayer*)p)->sendNetworkPacket(this); }
};
