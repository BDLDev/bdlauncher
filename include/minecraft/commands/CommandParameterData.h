#pragma once

#include "../core/typeid.h"
#include "../core/types.h"
#include "CommandRegistry.h"

#include <string>
#include <vector>

class CommandOrigin;
enum class CommandParameterDataType { NORMAL, ENUM, SOFT_ENUM };
struct CommandParameterData {
  using ParseFn = bool (CommandRegistry::*)(void *, CommandRegistry::ParseToken const &, CommandOrigin const &, int, std::string &,
                                            std::vector<std::string> &) const;
  typeid_t<CommandRegistry> tid;
  ParseFn parser;
  std::string name;
  char const *desc;
  int unk64;
  CommandParameterDataType type;
  int unk72;
  int offset;
  bool optional;
  CommandParameterData(typeid_t<CommandRegistry> tid, ParseFn parser, char const *name, CommandParameterDataType type, char const *desc, int offset,
                       bool mand, int flag_offset);
};