#pragma once

#include "../../RakNet/types.h"
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

struct NetworkIdentifier {
  enum class Type {
    GUID  = 0,
    IPv4  = 1,
    IPv6  = 2,
    Empty = 3,
  };
  RakNet::RakNetGUID guid; // 0
  char filler[0x76];       // 16
  unsigned long unk;       // 136
  Type type;               // 144
  NetworkIdentifier(RakNet::AddressOrGUID const &);
  NetworkIdentifier(RakNet::RakNetGUID const &);
  NetworkIdentifier(RakNet::SystemAddress const &);
  NetworkIdentifier(sockaddr_in const &);
  NetworkIdentifier(sockaddr_in6 const &);
  NetworkIdentifier(std::string const &, unsigned short);
  NetworkIdentifier();
  bool equalsTypeData(NetworkIdentifier const &) const;
  size_t getHash() const;
  unsigned short getPort() const;
  RakNet::RakNetGUID getRakNetGUID() const;
  sockaddr_in *getSocketAddress() const;
  sockaddr_in6 *getSocketAddress6() const;
  bool isUnassigned() const;
  std::string getAddress() const;
  std::string toString() const;

  bool operator!=(NetworkIdentifier const &addr) const;
  bool operator==(NetworkIdentifier const &addr) const;
  NetworkIdentifier &operator=(NetworkIdentifier const &addr);
  NetworkIdentifier &operator=(NetworkIdentifier &&addr) const;
};

static_assert(offsetof(NetworkIdentifier, type) == 144);
static_assert(sizeof(NetworkIdentifier)==0x98);

namespace std {
template <> struct hash<NetworkIdentifier> {
  std::size_t operator()(NetworkIdentifier const &s) const noexcept { return s.getHash(); }
};
} // namespace std
