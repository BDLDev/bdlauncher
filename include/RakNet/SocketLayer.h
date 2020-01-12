#pragma once

#include "SocketIncludes.h"
#include "types.h"
#include "string.h"

namespace RakNet {

struct NetworkAdpter {
  uint32_t unk0;
  uint32_t unk4;
  uint8_t unk8;
  SystemAddress address[20];
  NetworkAdpter();
  uint32_t GetNumberOfAddresses();
};

struct SocketLayer {
  static bool GetFirstBindableIP(char[128], int);
  static void SetSocketOptions(__UDPSOCKET__ listenSocket, bool blockingSocket, bool setBroadcast);
  static unsigned short GetLocalPort(__UDPSOCKET__ s);
  static void GetSystemAddress_Old(__UDPSOCKET__ s, SystemAddress *systemAddressOut);
  static void GetSystemAddress(__UDPSOCKET__ s, SystemAddress *systemAddressOut);
  static RakString GetSubNetForSocketAndIp(__UDPSOCKET__ inSock, RakString inIpString);
  static void GetMyAdapters(NetworkAdpter *);
};
} // namespace RakNet