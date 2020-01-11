#pragma once

#include "../core/types.h"

#include <memory>
#include <unordered_map>

class CompoundTag;
class StructureBlockPalette;

class StructureTemplateData {
  char filler[200];

public:
  StructureTemplateData();
  virtual ~StructureTemplateData();

  void setStructureWorldOrigin(BlockPos const &);
  void setSize(BlockPos const &);
  StructureBlockPalette *getPalette(std::string const &) const;

  std::unique_ptr<CompoundTag> save() const;
  bool load(CompoundTag const &);
};