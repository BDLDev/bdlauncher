#pragma once
#include <climits>
#include "myhook.h"
#include <unordered_map>
#include "minecraft/commands/Command.h"
#include "minecraft/commands/CommandRegistry.h"
#include "minecraft/commands/CommandMessage.h"
#include "minecraft/commands/CommandParameterData.h"
#include "minecraft/commands/MinecraftCommands.h"
#include "minecraft/commands/CommandOutput.h"
#include "minecraft/commands/CommandOrigin.h"

//void cmdhelper_init();
Minecraft* getMC();
void register_shutdown(void*);
