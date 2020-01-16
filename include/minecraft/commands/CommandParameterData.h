#pragma once

#include "../core/typeid.h"
#include "../core/types.h"
#include "CommandRegistry.h"

#include <string>
#include <vector>

class CommandOrigin;
enum class CommandParameterDataType { NORMAL, ENUM, SOFT_ENUM };
struct CommandParameterData {
  using ParseFn = bool (CommandRegistry::*)(
      void *, CommandRegistry::ParseToken const &, CommandOrigin const &, int, std::string &,
      std::vector<std::string> &) const;
  typeid_t<CommandRegistry> tid; // 0-8
  ParseFn parser;                // 8-24
  std::string name;              // 24-56
  char const *desc;              // 56-64
  int unk64;                     // 64-68
  CommandParameterDataType type; // 68-72
  int unk72;                     // 72-76
  int offset;                    // 76-80
  bool optional;                 // 80-81
  bool unk81;                    // 81-82
  char padding[88 - 82];
  CommandParameterData(
      typeid_t<CommandRegistry> tid, ParseFn parser, char const *name, CommandParameterDataType type, char const *desc,
      int offset, bool mand, int flag_offset);
};

static_assert(sizeof(CommandParameterData) == 88);