#pragma once

#include "StructureTemplateData.h"

class BlockSource;
class BlockPalette;
struct StructureSettings;

class StructureTemplate {
  std::string name;

public:
  StructureTemplateData data;
  inline StructureTemplate(std::string const &name = "default") : name(name) {}

  bool isLoaded() const;

  std::unique_ptr<CompoundTag> save() const;
  bool load(CompoundTag const &);

  bool placeInWorld(BlockSource &, BlockPalette const &, BlockPos, StructureSettings const &) const;
  void fillFromWorld(BlockSource &, BlockPos const &, StructureSettings const &);
};