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
  CommandSelectorBase(CommandSelectorBase const &) = delete;
  ~CommandSelectorBase();
};

template <typename T> class CommandSelector : public CommandSelectorBase {
public:
  CommandSelector();
  std::shared_ptr<std::vector<T *>> results(CommandOrigin const &) const;
};

template <typename T> class WildcardCommandSelector : public CommandSelectorBase {
public:
  WildcardCommandSelector();
  std::shared_ptr<std::vector<T *>> results(CommandOrigin const &) const;
};
