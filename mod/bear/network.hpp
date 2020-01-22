
#include <sys/socket.h>
#include <arpa/inet.h>
ssize_t (*rori)(int socket, void *buffer, size_t length, int flags, struct sockaddr *address, socklen_t *address_len);
static ssize_t
recvfrom_hook(int socket, void *buffer, size_t length, int flags, struct sockaddr *address, socklen_t *address_len) {
  int rt = rori(socket, buffer, length, flags, address, address_len);
  if (rt && ((char *) buffer)[0] == 0x5) {
    char buf[1024];
    inet_ntop(AF_INET, &(((sockaddr_in *) address)->sin_addr), buf, *address_len);
    async_log("[NETWORK] %s send conn\n", buf);
  }
  return rt;
}