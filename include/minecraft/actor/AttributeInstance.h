#pragma once

#include "Attribute.h"

#include <memory>
#include <vector>

class AttributeModifier;
class AttributeBuff;
class TemporalAttributeBuff;
class AttributeInstanceHandle;
class AttributeInstanceDelegate;

class AttributeInstance {
public:
  void addModifier(AttributeModifier const &);
  void addModifier(std::shared_ptr<AttributeModifier> const &);
  void addModifiers(std::vector<std::shared_ptr<AttributeModifier>> *);
  void addBuff(AttributeBuff const &);
  void addBuff(std::shared_ptr<AttributeBuff>);

  void removeModifier(AttributeModifier const &);
  void removeModifier(std::shared_ptr<AttributeModifier> const &);
  void removeModifiers(std::string const &);
  void removeModifiers();
  void removeBuff(AttributeBuff const &);
  void removeBuff(std::shared_ptr<AttributeBuff>);

  Attribute const &getAttribute() const;
  std::vector<TemporalAttributeBuff> const &getBuffs() const;
  AttributeInstanceHandle getHandle() const;
  std::vector<AttributeInstanceHandle> const &getListeners() const;
  float getMinValue() const;
  float getMaxValue() const;
  float getCurrentValue() const;
  float getDefaultValue(int) const;
  AttributeModifier getModifier(mce::UUID const &) const;
  std::vector<AttributeModifier> getModifiers(int) const;
  std::vector<AttributeModifier> getModifiers(std::vector<std::string> const &) const;
  std::vector<AttributeModifier> getModifiers() const;

  void setMinValue(float);
  void setMaxValue(float);
  void setRange(float, float, float);
  void setDelegate(std::shared_ptr<AttributeInstanceDelegate>);

  bool hasModifier(AttributeModifier const &) const;
  bool hasModifier(std::vector<AttributeModifier> const &) const;
  bool hasTemporalBuffs() const;

  bool isValid() const;

  void notify();
  void recalculateModifiers();
  void registerListener(AttributeInstance const &);
  void resetToDefaultValue();
  void resetToMaxValue();
  void resetToMinValue();

  void serializationSetRange(float, float, float);
  void serializationSetValue(float, int, float);
  void setDefaultValue(float, int);
  void setDefaultValueOnly(float);
};