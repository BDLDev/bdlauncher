#pragma once
#include <string>
#include "CommandRegistry.h"
class CommandOrigin;
class CommandOutput;
class PermissionsFile;
struct Minecraft;
template <typename T>
class CommandSelectorResults;

class Command {
  char filler[32];

public:
  Command();
  virtual ~Command();
  virtual void execute(CommandOrigin const &, CommandOutput &) = 0;

  template<typename T>
  static bool checkHasTargets(CommandSelectorResults<T> const&, CommandOutput &);
};

class ServerCommands {
public:
  void setupStandardServer(
      Minecraft &, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &,
      std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &, PermissionsFile *);
};

class SayCommand {
public:
  void setup(CommandRegistry &);
};
