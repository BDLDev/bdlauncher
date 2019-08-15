#pragma once

#include <memory>
#include <string>
#include <vector>

class CommandOrigin;
template <typename> class CommandSelector;
class Actor;

class CommandMessage {
 char filler[24];

public:
  std::string getMessage(CommandOrigin const &) const;
};