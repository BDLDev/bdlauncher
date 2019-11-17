#pragma once

#include "../core/types.h"

#include <unordered_map>
#include <functional>

class Player;

class Dimension {
public:
  std::unordered_map<ActorUniqueID, Actor *> &getEntityIdMap() const;
  void forEachPlayer(std::function<bool (Player &)>);
};