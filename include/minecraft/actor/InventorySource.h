#pragma once
#include <string>

class InventorySource {
public:
  char filler[12];
  int getType() const;
  int getFlags() const;
  int getContainerId() const;
  string toStr() const {
    return std::to_string(getType()) + ":" + std::to_string(getFlags()) + ":" + std::to_string(getContainerId());
  }
};