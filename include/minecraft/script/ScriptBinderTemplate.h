#pragma once

#include <string>

class ScriptObjectBinder;

class ScriptBinderTemplate {
public:
  virtual ~ScriptBinderTemplate();
  virtual std::string const & getTemplateIdentifier() const = 0;
  virtual void applyTemplate(ScriptObjectBinder &) const = 0;
};