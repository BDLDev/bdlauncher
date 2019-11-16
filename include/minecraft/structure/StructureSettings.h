#pragma once

#include "../core/types.h"
#include <string>
enum class Rotation : char {};
enum class Mirror : char {};

struct StructureSettings {
  std::string palette_name;      // 0
  bool ignore_entities;          // 32
  bool ignore_blocks;            // 33
  BlockPos size, offset;         // 36, 48
  ActorUniqueID last_touched_id; // 64
  Rotation rotation;             // 72
  Mirror mirror;                 // 73
  float integrity;               // 76
  unsigned integrity_seed;       // 80

  StructureSettings();
  inline ~StructureSettings() { asm("call _ZN17StructureSettingsD2Ev"); }
};