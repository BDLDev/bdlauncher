#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "shared.h"
#include "exec_server.h"
#include "termwrap.h"
#include <getopt.h>

char const *bedrock_server = "./bedrock_server";

int main(int argc, char *argv[]) {
  if (argc >= 2) bedrock_server = (char const *) argv[1];
  char pathbuf[256];
  ssize_t len            = readlink("/proc/self/exe", pathbuf, sizeof pathbuf);
  pathbuf[len]           = 0;
  *strrchr(pathbuf, '/') = 0;
  assert(chdir(pathbuf) == 0);

  if (access(bedrock_server, R_OK | X_OK) == -1) {
    printf("The executable `%s` does not exists...\nPlease download it manually\n", bedrock_server);
    return 1;
  }

  if (isatty(0) && getenv("FANCY")) return termwrap(argc >= 3 ? argv[2] : NULL);
  return exec_server();
}
