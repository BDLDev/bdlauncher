#pragma once

#include <sys/socket.h>
#include <string>

class NetworkIdentifier {

public:
    char filler[0x10];
    sockaddr_storage sa; // 90
    int family;

    bool equalsTypeData(NetworkIdentifier const&) const;
    int getHash() const;
    std::string toString() const;

    bool operator==(NetworkIdentifier const& addr) const { return equalsTypeData(addr); }

};

namespace std  {
template<>
struct hash<NetworkIdentifier> {
    std::size_t operator()(NetworkIdentifier const& s) const noexcept {
        return s.getHash();
    }
};
}