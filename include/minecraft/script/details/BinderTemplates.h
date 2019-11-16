#pragma once

#include "../../core/types.h"
#include "../ScriptBinderTemplate.h"
#include "../entt.h"

#include <memory>

namespace ScriptApi {
class ScriptObjectHandle;
}

class ScriptBinderComponentTemplate : public ScriptBinderTemplate {
public:
  virtual ~ScriptBinderComponentTemplate() override;
  virtual std::string const &getTemplateIdentifier() const override;
  virtual void applyTemplate(ScriptObjectBinder &) const override;

  static std::unique_ptr<ScriptObjectBinder> build(std::string const &, ScriptApi::ScriptObjectHandle &&);
};

class Block;

class ScriptBinderBlockTemplate : public ScriptBinderTemplate {
public:
  virtual ~ScriptBinderBlockTemplate() override;
  virtual std::string const &getTemplateIdentifier() const override;
  virtual void applyTemplate(ScriptObjectBinder &) const override;

  static std::unique_ptr<ScriptObjectBinder> build(Block const &, BlockPos const &, ScriptApi::ScriptObjectHandle &&);
};

class ScriptBinderPureEcsTemplate : public ScriptBinderTemplate {
public:
  virtual ~ScriptBinderPureEcsTemplate() override;
  virtual std::string const &getTemplateIdentifier() const override;
  virtual void applyTemplate(ScriptObjectBinder &) const override;

  static std::unique_ptr<ScriptObjectBinder> build(entt::Registry<unsigned int> &, unsigned int);
};