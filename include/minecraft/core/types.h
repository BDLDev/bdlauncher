#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <string>
/*
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
*/
enum class CommandPermissionLevel : unsigned char {};
enum class CommandOutputType : char {};

struct Vec3;

struct BlockPos;
class Actor;

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
