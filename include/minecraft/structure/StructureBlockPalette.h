#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

class CompoundTag;

class StructureBlockPalette {
  std::vector<std::unique_ptr<CompoundTag>> data;
  std::unordered_map<unsigned long, std::unique_ptr<CompoundTag>> inde;
};