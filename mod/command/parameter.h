#pragma once

#include "command.h"
#include <global.h>

#include <minecraft/core/GameType.h>
#include <minecraft/commands/CommandSelector.h>
#include <minecraft/commands/CommandPosition.h>
#include <minecraft/json.h>
//#include <minecraft/block/Block.h>
class Block;

namespace BDL::CustomCommand {

#define GENTYPE_ID(symbol)                                                                                             \
  extern "C" {                                                                                                         \
  extern typeid_t<CommandRegistry> symbol;                                                                             \
  }

#define MakeCommonProxy(real, symbol)                                                                                  \
  template <> class CommandParameterProxy<real> {                                                                      \
  protected:                                                                                                           \
    real value;                                                                                                        \
                                                                                                                       \
  public:                                                                                                              \
    inline static typeid_t<CommandRegistry> fetch_tid() { return symbol; }                                             \
    inline static constexpr CommandParameterData::ParseFn parser = &CommandRegistry::parse<real>;                      \
    inline static constexpr CommandParameterDataType type        = CommandParameterDataType::NORMAL;                   \
                                                                                                                       \
    operator real const &() const noexcept { return value; }                                                           \
  }

#define GENALL(real, symbol)                                                                                           \
  GENTYPE_ID(symbol);                                                                                                  \
  MakeCommonProxy(real, symbol)

using DimensionID = AutomaticID<Dimension, int>;

GENALL(bool, _ZZ7type_idI15CommandRegistrybE8typeid_tIT_EvE2id);
GENALL(int, _ZZ7type_idI15CommandRegistryiE8typeid_tIT_EvE2id);
GENALL(float, _ZZ7type_idI15CommandRegistryfE8typeid_tIT_EvE2id);
GENALL(DimensionID, _ZZ7type_idI15CommandRegistry11AutomaticIDI9DimensioniEE8typeid_tIT_EvE2id);
GENALL(Block const *, _ZZ7type_idI15CommandRegistryPK5BlockE8typeid_tIT_EvE2id);
GENALL(GameType, _ZZ7type_idI15CommandRegistry8GameTypeE8typeid_tIT_EvE2id);
GENALL(std::string, _ZZ7type_idI15CommandRegistryNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE8typeid_tIT_EvE2id);
GENALL(CommandSelector<Actor>, _ZZ7type_idI15CommandRegistry15CommandSelectorI5ActorEE8typeid_tIT_EvE2id);
GENALL(CommandSelector<Player>, _ZZ7type_idI15CommandRegistry15CommandSelectorI6PlayerEE8typeid_tIT_EvE2id);
GENALL(WildcardCommandSelector<Actor>, _ZZ7type_idI15CommandRegistry23WildcardCommandSelectorI5ActorEE8typeid_tIT_EvE2id);
GENALL(RelativeFloat, _ZZ7type_idI15CommandRegistry13RelativeFloatE8typeid_tIT_EvE2id);
GENALL(CommandPosition, _ZZ7type_idI15CommandRegistry15CommandPositionE8typeid_tIT_EvE2id);
GENALL(CommandPositionFloat, _ZZ7type_idI15CommandRegistry20CommandPositionFloatE8typeid_tIT_EvE2id);
GENALL(Json::Value, _ZZ7type_idI15CommandRegistryN4Json5ValueEE8typeid_tIT_EvE2id);

#undef GENTYPE_ID

} // namespace BDL::CustomCommand