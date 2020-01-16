#pragma once

#include "command.h"
#include <global.h>

#include <minecraft/core/GameType.h>

namespace BDL::CustomCommand {

template <typename T> typeid_t<CommandRegistry> &tid;

#define GENTYPE_ID(real, symbol)                                                                                       \
  extern "C" {                                                                                                         \
  extern typeid_t<CommandRegistry> symbol;                                                                             \
  }                                                                                                                    \
  template <> typeid_t<CommandRegistry> &tid<real> = symbol;

#define MakeCommonProxy(real)                                                                                          \
  template <> class CommandParameterProxy<real> {                                                                      \
  protected:                                                                                                           \
    real value;                                                                                                        \
                                                                                                                       \
  public:                                                                                                              \
    inline static typeid_t<CommandRegistry> fetch_tid() { return tid<real>; }                                          \
    inline static constexpr CommandParameterData::ParseFn parser = &CommandRegistry::parse<real>;                      \
    inline static constexpr CommandParameterDataType type        = CommandParameterDataType::NORMAL;                   \
    inline static constexpr char const *subtype                  = nullptr;                                            \
                                                                                                                       \
    operator real() const noexcept { return value; }                                                                   \
  }

#define GENALL(real, symbol)                                                                                           \
  GENTYPE_ID(real, symbol);                                                                                            \
  MakeCommonProxy(real)

using DimensionID = AutomaticID<Dimension, int>;

GENALL(bool, _ZZ7type_idI15CommandRegistrybE8typeid_tIT_EvE2id);
GENALL(int, _ZZ7type_idI15CommandRegistryiE8typeid_tIT_EvE2id);
GENALL(float, _ZZ7type_idI15CommandRegistryfE8typeid_tIT_EvE2id);
GENALL(DimensionID, _ZZ7type_idI15CommandRegistry11AutomaticIDI9DimensioniEE8typeid_tIT_EvE2id);
GENALL(Block const *, _ZZ7type_idI15CommandRegistryPK5BlockE8typeid_tIT_EvE2id);
GENALL(GameType, _ZZ7type_idI15CommandRegistry8GameTypeE8typeid_tIT_EvE2id);
GENALL(
    std::string, _ZZ7type_idI15CommandRegistryNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE8typeid_tIT_EvE2id);

#undef GENTYPE_ID

} // namespace BDL::CustomCommand