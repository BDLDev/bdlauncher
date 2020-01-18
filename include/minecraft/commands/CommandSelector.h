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

template <typename T> class SelectorIterator {
  std::shared_ptr<std::vector<Actor *>> ref;
  std::vector<Actor *>::iterator pos;

public:
  T &operator*() const;
  SelectorIterator operator++(int);
  SelectorIterator &operator++();

  SelectorIterator &operator=(SelectorIterator const &);
  bool operator==(SelectorIterator const &) const;
  bool operator!=(SelectorIterator const &) const;
};

template <typename T> class CommandSelectorResults {
  std::shared_ptr<std::vector<Actor *>> data;

public:
  SelectorIterator<T> begin() const;
  SelectorIterator<T> end() const;
  bool empty() const;
  std::size_t size() const;
  Actor **const get() const;
};

template <typename T> class CommandSelector : public CommandSelectorBase {
public:
  CommandSelector();
  CommandSelectorResults<T> results(CommandOrigin const &) const;
};

template <typename T> class WildcardCommandSelector : public CommandSelectorBase {
public:
  WildcardCommandSelector();
  CommandSelectorResults<T> results(CommandOrigin const &) const;
};
