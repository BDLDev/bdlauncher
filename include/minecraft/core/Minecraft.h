#pragma once
#include<string>
#include"../../RakNet/PluginInterface2.h"
#include"../../RakNet/peerinterface.h"
#include"../../RakNet/types.h"
#include"../../RakNet/peer.h"
;
class EntityRegistry;

class IEntityRegistryOwner {
public:
  virtual ~IEntityRegistryOwner();
  virtual EntityRegistry &getEntityRegistry() = 0;
};

class MinecraftCommands;
class IMinecraftEventing;
using RakNet::RakPeer;
class NetworkIdentifier;
class NetworkHandler{
	public:
	RakPeer& getPeerForUser(NetworkIdentifier const&);
};
class NetworkStatistics;
class RakNetServerLocator;
class StructureManager;
class Timer;
class Level;
class NetworkIdentifier;
class ServerPlayer;
class ServerNetworkHandler{
public:
void disconnectClient(NetworkIdentifier const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, bool); //def false?
NetworkHandler* getNH() const{
	return *((NetworkHandler **)this+8);
}
void _onPlayerLeft(ServerPlayer*, bool);
void _sendAdditionalLevelData(ServerPlayer&, NetworkIdentifier const&);
};
class Minecraft : public IEntityRegistryOwner {
public:
  MinecraftCommands *getCommands();
  IMinecraftEventing *getEventing() const;
  NetworkHandler *getNetworkHandler();
  NetworkHandler *getNetworkHandler() const;
  NetworkStatistics *getNetworkStatistics();
  RakNetServerLocator *getServerLocator();
  RakNetServerLocator *getServerLocator() const;
  NetworkHandler *getServerNetworkHandler();
  StructureManager *getStructureManager();
  Timer *getTimer();
  Level *getLevel() const;
  ServerNetworkHandler *getNetEventCallback();
  virtual ~Minecraft();
  virtual EntityRegistry &getEntityRegistry();
};
