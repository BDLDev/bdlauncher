#pragma once

class Level;
class Minecraft;
class PacketSender;

namespace entt {
template <typename T = unsigned int> class Registry;
}

namespace ScriptApi {
class ScriptReport;
}

class ScriptServerContext {
public:
  Level *level;
  Minecraft *minecraft;
  PacketSender *sender;
  entt::Registry<unsigned int> *registry;
  ScriptApi::ScriptReport *report;
};