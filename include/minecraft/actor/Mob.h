#pragma once

#include "Actor.h"

class Mob : public Actor {
public:
  bool isGliding() const;
  virtual ~Mob() override;
  
};