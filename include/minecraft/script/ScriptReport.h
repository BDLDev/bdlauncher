#pragma once

#include "ScriptReportItem.h"
#include <memory>
#include <string>
#include <vector>

namespace ScriptApi {
class ScriptReport {
  std::vector<std::shared_ptr<ScriptReportItem>> errs;

public:
  ScriptReport();
  ~ScriptReport();

  void addError(std::string const &msg);
  void addError(std::unique_ptr<JavaScriptErrorHandler> &&handler);
  void addError();
  void addWarning(std::string const &msg);
  void addWarning();
  void clear();
  std::vector<std::shared_ptr<ScriptReportItem>> const &getReportItems() const;
  bool hasErrors() const;
  bool hasWarnings() const;
  void merge(ScriptReport &&);
};
} // namespace ScriptApi