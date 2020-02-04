#pragma once

class Packet;
class NetworkIdentifier;

class LoopbackPacketSender {
public:
  void sendBroadcast(Packet const &);
  void sendToClient(NetworkIdentifier const &, Packet const &, unsigned char);
};