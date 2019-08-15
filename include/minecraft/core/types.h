#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <string>

enum class MCCATEGORY : char {};
typedef uint64_t u64;
struct MCRESULT {
  bool success;        // 0
  MCCATEGORY category; // 1
  unsigned short code; // 2

  static bool isSuccess(int);

  MCRESULT(bool, MCCATEGORY, unsigned short);
  MCRESULT(int);

  bool operator==(MCRESULT const &) const;
  bool operator!=(MCRESULT const &) const;

  int getFullCode() const;
  bool isSuccess() const;
};

enum class CommandPermissionLevel : unsigned char {};
enum class CommandOutputType : char {};

struct Vec3 {
  float x, y, z;

  static Vec3 ZERO;

  float const &operator[](int idx) const;
  float &operator[](int idx);
};

struct BlockPos;
class Actor;

struct ChunkPos {
  int x, z;
  ChunkPos();
  ChunkPos(int, int);
  ChunkPos(BlockPos const &);
  ChunkPos(Vec3 const &);

  static ChunkPos INVALID;
  static ChunkPos MAX;
  static ChunkPos MIN;
  static ChunkPos const &max(ChunkPos const &, ChunkPos const &);
  static ChunkPos const &min(ChunkPos const &, ChunkPos const &);

  ChunkPos &operator=(ChunkPos const &);
  bool operator==(ChunkPos const &) const;
  bool operator!=(ChunkPos const &) const;
  ChunkPos const &operator+(ChunkPos const &) const;
  ChunkPos const &operator+(int) const;
  ChunkPos const &operator-(ChunkPos const &) const;
  ChunkPos const &operator-(int) const;

  float distanceToSqr(Actor const &);
  float distanceToSqr(ChunkPos const &);
  BlockPos getMiddleBlockPosition(int);
  int getMiddleBlockX();
  int getMiddleBlockZ();
  size_t hashCode();
};

struct Facing {
  enum Direction : char { DOWN, UP, NORTH, SOUTH, WEST, EAST };
  enum Rotation { NONE, CounterClockWise, Opposite, ClockWise };
  static char const *toString(Direction);
};

struct BlockPos {
  int x, y, z;

  static BlockPos MAX;
  static BlockPos MIN;
  static BlockPos ONE;
  static BlockPos ZERO;
  static BlockPos const &max(BlockPos const &, BlockPos const &);
  static BlockPos const &min(BlockPos const &, BlockPos const &);

  bool operator==(BlockPos const &) const;
  bool operator!=(BlockPos const &) const;
  BlockPos operator+(BlockPos const &) const;
  BlockPos operator+(int) const;
  BlockPos operator-(BlockPos const &) const;
  BlockPos operator-(int) const;
  BlockPos operator-() const;
  BlockPos operator*(int)const;
  BlockPos const &operator=(BlockPos const &);
  BlockPos const &operator+=(BlockPos const &);
  BlockPos const &operator-=(BlockPos const &);
  BlockPos const &operator*=(int);

  BlockPos above() const;
  BlockPos above(int) const;
  BlockPos below() const;
  BlockPos below(int) const;
  BlockPos east() const;
  BlockPos east(int) const;
  BlockPos south() const;
  BlockPos south(int) const;
  BlockPos west() const;
  BlockPos west(int) const;
  BlockPos north() const;
  BlockPos north(int) const;
  BlockPos neighbor(Facing::Direction);

  void set(BlockPos const &);
  void set(int, int, int);

  Vec3 center() const;
  float distSqr(BlockPos const &);
  float distSqr(float, float, float);
};

enum class AbilitiesIndex : unsigned short {
  build,
  mine,
  doorsandswitches,
  opencontainers,
  attackplayers,
  attackmobs,
  op,
  teleport,
  invulnerable,
  flying,
  mayfly,
  instabuild,
  lightning,
  flySpeed,
  walkSpeed,
  mute,
  worldbuilder,
  noclip,
};

namespace mce {
struct UUID;
}

struct ActorUniqueID {
  int64_t data;

  static ActorUniqueID fromClientId(int64_t);
  static ActorUniqueID fromUUID(mce::UUID const &);
  size_t getHash() const;
  operator bool() const;
  operator int64_t() const;

  bool operator!=(ActorUniqueID const &) const;
  bool operator==(ActorUniqueID const &) const;
  bool operator<(ActorUniqueID const &) const;
  ActorUniqueID &operator++();
};

enum class ItemAcquisitionMethod : int {
  unknown = -1,
  none = 0,
  picked_up = 1, // ~ Actor::pickUpItem
  crafted = 2,
  taken_from_chest = 3,
  taken_from_ender_chest = 4,
  bought = 5,
  anvil = 6,
  brewed = 8,
  filled = 9,
  trading = 10,
  fishing = 11,
  container = 13,
};
enum class ItemUseMethod : unsigned {};

enum class RegistrationType { SYSTEM, CUSTOM, UNKNOWN };

template <typename Type, typename Store> struct AutomaticID {
  Store v;
  AutomaticID();
  AutomaticID(Store v) : v(v) {}
  Store value() const;
  bool operator!=(AutomaticID const &) const;
  bool operator==(AutomaticID const &) const;
  operator Store() const { return v; }
  static Store _makeRuntimeID();
};

enum class ActorCategory {
  None = 0,
  Player = 1 << 0,
  Mob = 1 << 1,
  Monster = 1 << 2,
  Humandoid = 1 << 3,
  Animal = 1 << 4,
  Water = 1 << 5,
  Pathable = 1 << 6,
  Tamable = 1 << 7,
  Ridable = 1 << 8,
  //?? 1 << 9
  Item = 1 << 10,
  Ambient = 1 << 11,
  Villager = 1 << 12,
  Arthropod = 1 << 13,
  Undead = 1 << 14,
  Zombie = 1 << 15,
  Minecart = 1 << 16,
  Boat = 1 << 17,

  BoatRideable = Boat | Ridable,
  MinecartRideable = Minecart | Ridable,
  HumandoidMonster = Humandoid | Monster,
  WaterAnimal = Water | Animal,
  TamableAnimal = Tamable | Animal,
  UndeadMob = Undead | Mob,
  ZombieMonster = Zombie | Monster,
};

class HashedString {
  size_t hash;
  std::string data;

public:
  HashedString();
  HashedString(std::string const &);
  HashedString(char const *);
  std::string &getString();

  char const *c_str() const;
  void clear();
  bool empty() const;

  bool operator!=(HashedString const &) const;
  bool operator==(HashedString const &) const;
  bool operator<(HashedString const &) const;
  HashedString &operator=(HashedString const &) const;
};
