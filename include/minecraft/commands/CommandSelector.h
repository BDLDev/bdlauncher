#pragma once

#include <memory>
#include <type_traits>
#include <vector>

class Actor;
class Player;
class CommandOrigin;

class CommandSelectorBase {
  char filler[168];
public:
  CommandSelectorBase(bool);
  ~CommandSelectorBase();
};

template <typename T> class CommandSelector : public CommandSelectorBase {
public:
  CommandSelector() : CommandSelectorBase(!std::is_same_v<T, Actor>) {}
  std::shared_ptr<std::vector<Actor *>> results(CommandOrigin const &) const;
};
