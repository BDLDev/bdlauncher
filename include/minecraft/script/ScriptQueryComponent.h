#pragma once

#include <string>
#include <unordered_set>

struct ScriptQueryComponent {
  enum class ViewType {};
  std::unordered_set<std::string> set;
  ViewType type;
  std::string name;
  std::string x;
  std::string y;
  std::string z;

  // ScriptQueryComponent(ViewType, std::string const &, std::string const &, std::string const &, std::string const &);
  // ScriptQueryComponent(ViewType);
  // ScriptQueryComponent(ScriptQueryComponent &&);

  // ScriptQueryComponent &operator=(ScriptQueryComponent &&);
  // ~ScriptQueryComponent();
};