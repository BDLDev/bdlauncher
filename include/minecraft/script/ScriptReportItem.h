#pragma once

#include "ScriptReportItemType.h"
#include <memory>
#include <string>

namespace ScriptApi {

class JavaScriptErrorHandler;
class ScriptReportItem {
  std::string msg;
  ScriptReportItemType type;
  std::unique_ptr<JavaScriptErrorHandler> handler;

public:
  ScriptReportItem();
  ScriptReportItem(ScriptReportItemType type);
  ScriptReportItem(ScriptReportItemType type, std::string const &msg);
  ScriptReportItem(std::unique_ptr<JavaScriptErrorHandler> &&handler);
  ~ScriptReportItem();

  JavaScriptErrorHandler *getErrorHandler() const;
  ScriptReportItemType getType() const;
  void setType(ScriptReportItemType);
  std::string const &getMessage() const;
};

} // namespace ScriptApi