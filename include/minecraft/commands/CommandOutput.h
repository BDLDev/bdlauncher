#pragma once

#include <string>
#include <vector>

class CommandOutputParameter {

private:
    std::string str;
    int type;

public:
    CommandOutputParameter(std::string const&);
    CommandOutputParameter(int);

};

enum class CommandOutputMessageType {
    DEFAULT, ERROR
};
class CommandOutput {
public:
  void success();
  void success(std::string const &, std::vector<CommandOutputParameter> const &params = {});
  void error(std::string const &, std::vector<CommandOutputParameter> const &params = {});
  void addMessage(std::string const&, std::vector<CommandOutputParameter> const& = {}, CommandOutputMessageType = CommandOutputMessageType::DEFAULT);
  template <typename T> void set(char const *, T);
};