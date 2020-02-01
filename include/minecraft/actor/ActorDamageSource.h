#pragma once

class ActorUniqueID;

class ActorDamageSource {
public:
  virtual void destruct1()                 = 0;
  virtual void destruct2()                 = 0;
  virtual bool isEntitySource() const      = 0;
  virtual bool isChildEntitySource() const = 0;

private:
  virtual void* unk1() = 0;
  virtual void* unk2() = 0;
  virtual void* unk3() = 0;
  virtual void* unk4() = 0;

public:
  virtual ActorUniqueID getEntityUniqueID() const = 0;
  virtual int getEntityType() const               = 0;
  virtual int getEntityCategories() const         = 0;
};