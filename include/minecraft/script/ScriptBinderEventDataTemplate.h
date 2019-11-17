#pragma once

#include "ScriptBinderTemplate.h"

#include <memory>

namespace ScriptApi {
class ScriptObjectHandle;
}

class ScriptBinderEventDataTemplate : public ScriptBinderTemplate {
public:
  virtual ~ScriptBinderEventDataTemplate() override;
  virtual std::string const &getTemplateIdentifier() const override;
  virtual void applyTemplate(ScriptObjectBinder &) const override;

  static std::unique_ptr<ScriptObjectBinder> build(std::string const &, ScriptApi::ScriptObjectHandle &&);
};