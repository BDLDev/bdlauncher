#pragma once
#include <cstring>
#include <memory>
#include <vector>
class BlockLegacy;

class ItemStackBase {
public:
  char filler[312]; // unk
  
  short getAuxValue() const;
  void setAuxValue(short);
  short getId() const;
  BlockLegacy const &getLegacyBlock() const;
  unsigned char getStackSize() const;
  bool isBlock() const;
  const std::string toString() const;
  bool isEnchanted() const;
  bool isOffhandItem() const;
  unsigned int getIdAuxEnchanted() const;
  bool isNull() const;
  std::unique_ptr<CompoundTag, std::default_delete<CompoundTag>> &getUserData() const;
  void setStackSize(unsigned char);
  void setCustomLore(std::vector<std::string> const&);
  std::vector<std::string>& getCustomLore() const;
  void setCustomName(std::string const &);
  bool operator!=(ItemStackBase const&) const;
  bool operator==(ItemStackBase const&) const;
};