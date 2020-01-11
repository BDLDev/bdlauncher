#pragma once

#include "../core/types.h"

enum class RedefinitionMode : char {};

class Attribute {
  RedefinitionMode mode;
  bool syncable;
  unsigned id;
  HashedString name;

public:
  static Attribute *getByName(HashedString const &);
  unsigned getIDValue() const;
  HashedString const &getName() const;
  RedefinitionMode getRedefinitionMode() const;
  bool isClientSyncable() const;
};