#pragma once

#include <memory>

class ITickingArea;

class TickWorldComponent {
  unsigned radius;
  float distance_to_players;
  bool never_despawn;
  bool loaded;
  std::weak_ptr<ITickingArea> tickingArea;

public:
  unsigned getChunkRadius() const;
  float getMaxDistToPlayers() const;
  void setTickingArea(std::shared_ptr<ITickingArea>);
  void updateArea();
  std::shared_ptr<ITickingArea> getTickingArea();
  bool hasTickingArea() const;
  bool isAlwaysActive() const;
  void removeArea();
};