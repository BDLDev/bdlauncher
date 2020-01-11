#pragma once

#include "../core/UUID.h"
#include "../core/types.h"

struct PlayerListEntry {
  ActorUniqueID id;             // 0
  mce::UUID uuid;               // 8
  std::string name;             // 24
  std::string skin;             // 56
  std::vector<char> skin_image; // 88
  std::vector<char> cape_image; // 112
  std::string skin_geo_name;    // 136
  std::string skin_geo_data;    // 168
  std::string xuid;             // 232
};