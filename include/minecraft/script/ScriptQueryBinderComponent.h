#pragma once

#include "ScriptBinderComponent.h"

class ScriptQueryBinderComponent : public ScriptBinderComponent {
  unsigned identifier;

public:
  ScriptQueryBinderComponent(unsigned identifier);
  ScriptQueryBinderComponent();
  virtual ~ScriptQueryBinderComponent();
  virtual bool serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &) const;
  virtual bool deserialize(ScriptEngine &, ScriptApi::ScriptObjectHandle const &);

  unsigned getIdentifier() const;
};