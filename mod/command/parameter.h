#pragma once

#include "command.h"
#include <global.h>

namespace BDL::CustomCommand {

template <typename T> typeid_t<CommandRegistry> &tid;

#define GENTYPE_ID(type, symbol)                                                                                       \
  extern "C" {                                                                                                         \
  extern typeid_t<CommandRegistry> symbol;                                                                             \
  }                                                                                                                    \
  template <> typeid_t<CommandRegistry> &tid<type> = symbol;

GENTYPE_ID(bool, _ZZ7type_idI15CommandRegistrybE8typeid_tIT_EvE2id);
GENTYPE_ID(int, _ZZ7type_idI15CommandRegistryiE8typeid_tIT_EvE2id);
GENTYPE_ID(float, _ZZ7type_idI15CommandRegistryfE8typeid_tIT_EvE2id);

#undef GENTYPE_ID

#define MakeCommonProxy(real)                                                                                          \
  template <> class CommandParameterProxy<real> {                                                                      \
    real value;                                                                                                        \
                                                                                                                       \
  public:                                                                                                              \
    inline static typeid_t<CommandRegistry> fetch_tid() { return tid<real>; }                                          \
    inline static constexpr CommandParameterData::ParseFn parser = &CommandRegistry::parse<real>;                      \
    inline static constexpr CommandParameterDataType type        = CommandParameterDataType::NORMAL;                   \
                                                                                                                       \
    operator real() const noexcept { return value; }                                                                   \
  }

MakeCommonProxy(bool);
MakeCommonProxy(int);
MakeCommonProxy(float);

} // namespace BDL::CustomCommand