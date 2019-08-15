#pragma once

#include "ScriptBinderTemplate.h"

#include <memory>

namespace ScriptApi {
class ScriptObjectHandle;
}

class ScriptBinderQueryTemplate : public ScriptBinderTemplate {
public:
  virtual ~ScriptBinderQueryTemplate() override;
  virtual std::string const &getTemplateIdentifier() const override;
  virtual void applyTemplate(ScriptObjectBinder &) const override;

  static std::unique_ptr<ScriptObjectBinder> build(unsigned int);
};