#pragma once

#include <string>
#include <vector>

class CommandOutputParameter;

enum class CommandOutputMessageType {
    DEFAULT, ERROR
};

class CommandOutput {

public:

    void success();
    void addMessage(std::string const&, std::vector<CommandOutputParameter> const& = {}, CommandOutputMessageType = CommandOutputMessageType::DEFAULT);
    void error(std::string const&, std::vector<CommandOutputParameter> const& = {});

};

class CommandOutputParameter {

private:
    std::string str;
    int type;

public:
    CommandOutputParameter(std::string const&);
    CommandOutputParameter(int);

};