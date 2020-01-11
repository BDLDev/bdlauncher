#pragma once

#include <memory>
#include <string>

class CommandOrigin;

class CommandContext {
  std::string command;                   // 0
  std::unique_ptr<CommandOrigin> origin; // 32
  int version;                           // 40
public:
  CommandContext(std::string const &, std::unique_ptr<CommandOrigin>, int);

  CommandOrigin const *getCommandOrigin() const;
  int getVersion() const;
};