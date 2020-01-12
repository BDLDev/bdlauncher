#pragma once

#include "DataStructures.h"
#include "LocklessTypes.h"
#include "MTUSize.h"
#include "macros.h"
#include "thread.h"
#include "types.h"
#include "time.h"

namespace RakNet {

class RakNetSocket2;
struct RNS2_BerkleyBindParameters;
struct RNS2_SendParameters;
typedef int RNS2Socket;

enum RNS2BindResult {
  BR_SUCCESS,
  BR_REQUIRES_RAKNET_SUPPORT_IPV6_DEFINE,
  BR_FAILED_TO_BIND_SOCKET,
  BR_FAILED_SEND_TEST,
};

typedef int RNS2SendResult;

enum RNS2Type { RNS2T_WINDOWS_STORE_8, RNS2T_PS3, RNS2T_PS4, RNS2T_CHROME, RNS2T_VITA, RNS2T_XBOX_360, RNS2T_XBOX_720, RNS2T_WINDOWS, RNS2T_LINUX };

struct RNS2_SendParameters {
  RNS2_SendParameters() { ttl = 0; }
  char *data;
  int length;
  SystemAddress systemAddress;
  int ttl;
};

struct RNS2RecvStruct {

  char data[MAXIMUM_MTU_SIZE];

  int bytesRead;
  SystemAddress systemAddress;
  TimeUS timeRead;
  RakNetSocket2 *socket;
};

class RakNetSocket2Allocator {
public:
  static RakNetSocket2 *AllocRNS2(void);
  static void DeallocRNS2(RakNetSocket2 *s);
};

class RNS2EventHandler {
public:
  RNS2EventHandler() {}
  virtual ~RNS2EventHandler() {}

  //		bufferedPackets.Push(recvFromStruct);
  //		quitAndDataEvents.SetEvent();
  virtual void OnRNS2Recv(RNS2RecvStruct *recvStruct)                                        = 0;
  virtual void DeallocRNS2RecvStruct(RNS2RecvStruct *s, const char *file, unsigned int line) = 0;
  virtual RNS2RecvStruct *AllocRNS2RecvStruct(const char *file, unsigned int line)           = 0;

  // recvFromStruct=bufferedPackets.Allocate( _FILE_AND_LINE_ );
  // 	DataStructures::ThreadsafeAllocatingQueue<RNS2RecvStruct> bufferedPackets;
};

class RakNetSocket2 {
public:
  RakNetSocket2();
  virtual ~RakNetSocket2();

  // In order for the handler to trigger, some platforms must call PollRecvFrom, some platforms this create an internal thread.
  void SetRecvEventHandler(RNS2EventHandler *_eventHandler);
  virtual RNS2SendResult Send(RNS2_SendParameters *sendParameters, const char *file, unsigned int line) = 0;
  RNS2Type GetSocketType(void) const;
  void SetSocketType(RNS2Type t);
  bool IsBerkleySocket(void) const;
  SystemAddress GetBoundAddress(void) const;
  unsigned int GetUserConnectionSocketIndex(void) const;
  void SetUserConnectionSocketIndex(unsigned int i);
  RNS2EventHandler *GetEventHandler(void) const;

  // ----------- STATICS ------------
  static void GetMyIP(SystemAddress addresses[256]);
  static void DomainNameToIP(const char *domainName, char ip[65]);

protected:
  RNS2EventHandler *eventHandler;
  RNS2Type socketType;
  SystemAddress boundAddress;
  unsigned int userConnectionSocketIndex;
};

} // namespace RakNet