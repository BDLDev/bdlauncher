#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "shared.h"
#include "exec_server.h"

int exec_server() {
  char ldbuf[256];
  if (getenv("LD_LIBRARY_PATH")) {
    strcat(ldbuf, ":");
    strcat(ldbuf, getenv("LD_LIBRARY_PATH"));
  }
  setenv("LD_LIBRARY_PATH", ldbuf, 1);
  setenv("LD_PRELOAD", "preload.so", 1);
  char *fake_argv[] = {"[BDS]", NULL};
  execv(bedrock_server, fake_argv);
  perror("execv");
  return -1;
}