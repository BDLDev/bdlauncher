#pragma once

#define closesocket close
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

typedef int __UDPSOCKET__;
typedef int __TCPSOCKET__;