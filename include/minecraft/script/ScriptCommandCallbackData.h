#pragma once

#include <string>

#include "../json.h"

struct ScriptCommandCallbackData {
  std::string result;
  bool success;
  Json::Value extra;
};