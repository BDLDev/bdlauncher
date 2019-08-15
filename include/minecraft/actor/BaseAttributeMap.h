#pragma once

#include "AttributeInstance.h"

#include <memory>
#include <unordered_map>
#include <vector>

class AttributeInstanceHandle;
class AttributeModifier;

class BaseAttributeMap {
public:
  std::unordered_map<std::string, AttributeInstance> att_map; // 0
  std::vector<AttributeInstanceHandle> dirtyAttributes;       // 56

  static AttributeInstance mInvalidInstance;

  AttributeInstance &registerAttribute(Attribute const &);

  void addAttributeModifier(std::string const &, std::shared_ptr<AttributeModifier>);
  void removeAttributeModifier(std::string const &, std::shared_ptr<AttributeModifier>);

  void clearDirtyAttributes();
  std::vector<AttributeInstanceHandle> &getDirtyAttributes();
  AttributeInstance const &getInstance(Attribute const &) const;
  AttributeInstance const &getInstance(std::string const &) const;
  AttributeInstance &getMutableInstance(Attribute const &);
  AttributeInstance &getMutableInstance(std::string const &);
  std::vector<AttributeInstanceHandle> getSyncableAttributes() const;
  void onAttributeModified(AttributeInstance const &);

  std::unordered_map<std::string, AttributeInstance>::iterator begin();
  std::unordered_map<std::string, AttributeInstance>::const_iterator begin() const;
  std::unordered_map<std::string, AttributeInstance>::iterator end();
  std::unordered_map<std::string, AttributeInstance>::const_iterator end() const;
};