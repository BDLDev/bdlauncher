#pragma once

#include <string>
#include <vector>
#include "minecraft/core/types.h"

class Actor;
class Player;

template <typename T> class CommandSelectorResults;

class CommandOutputParameter {

private:
  std::string str;
  int type;

public:
  struct NoCountType {};
  CommandOutputParameter(CommandOutputParameter const &);
  CommandOutputParameter(CommandOutputParameter &&);
  CommandOutputParameter(NoCountType);

  CommandOutputParameter &operator=(CommandOutputParameter const &);
  CommandOutputParameter &operator=(CommandOutputParameter &&);

  CommandOutputParameter(std::string const &);
  CommandOutputParameter(std::string const &, int);
  CommandOutputParameter(Actor const &);
  CommandOutputParameter(Actor const *);
  CommandOutputParameter(BlockPos);
  CommandOutputParameter(Vec3);
  CommandOutputParameter(bool);
  CommandOutputParameter(int);
  CommandOutputParameter(float);
  CommandOutputParameter(char const *);
  CommandOutputParameter(CommandSelectorResults<Actor> const &);
  CommandOutputParameter(CommandSelectorResults<Player> const &);
  CommandOutputParameter(std::vector<Actor const *> const &);
  CommandOutputParameter(std::vector<Player const *> const &);

  int count() const;
  std::string const &getText() const;
};

enum class CommandOutputMessageType { DEFAULT, ERROR };
class CommandOutput {
public:
  void success();
  void success(std::string const &, std::vector<CommandOutputParameter> const &params = {});
  void error(std::string const &, std::vector<CommandOutputParameter> const &params = {});
  void addMessage(
      std::string const &, std::vector<CommandOutputParameter> const & = {},
      CommandOutputMessageType = CommandOutputMessageType::DEFAULT);
  void addToResultList(std::string const &, Actor const &);
  void addToResultList(std::string const &, std::string const &);
  bool wantsData() const;
  template <typename T> void set(char const *, T);
};