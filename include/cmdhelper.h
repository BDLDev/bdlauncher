#pragma once
#include "myhook.h"
#include "minecraft/commands/Command.h"
#include "minecraft/commands/CommandRegistry.h"
#include "minecraft/commands/CommandMessage.h"
#include "minecraft/commands/CommandParameterData.h"
#include "minecraft/commands/MinecraftCommands.h"
#include "minecraft/commands/CommandOutput.h"
#include "minecraft/commands/CommandOrigin.h"
// void cmdhelper_init();
void register_shutdown(void *);
