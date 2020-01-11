#pragma once

#include <string>

template <typename> class WeakPtr;

class BlockLegacy;

class BlockTypeRegistry {
public:
  static WeakPtr<BlockLegacy> lookupByName(std::string const &);
};