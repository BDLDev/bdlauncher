#pragma once

#include "../util/typeid.h"
#include "CommandRegistry.h"

class CommandOutput;

class Command {

private:
    char filler[64];

public:
    Command();
    virtual ~Command();
    virtual void execute(CommandOrigin const&, CommandOutput&) = 0;

};
