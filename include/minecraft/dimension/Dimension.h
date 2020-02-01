#pragma once

#include "../core/types.h"

#include <unordered_map>
#include <functional>

class Player;
class Weather;

class Dimension {
public:
  bool operator==(Dimension const&) const;
  Weather* getWeather() const;
  bool hasWeather() const;
  std::unordered_map<ActorUniqueID, Actor *> &getEntityIdMap() const;
  void forEachPlayer(std::function<bool(Player &)>);
};