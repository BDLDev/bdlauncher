#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "shared.h"
#include "exec_server.h"
#include "termwrap.h"

char const *bedrock_server = "./bedrock_server";

int main(int argc, char *argv[]) {
  if (argc >= 2) bedrock_server = (char const *) argv[1];
  char pathbuf[256];
  ssize_t len = readlink("/proc/self/exe", pathbuf, sizeof pathbuf);
  pathbuf[len] = 0;
  *strrchr(pathbuf, '/') = 0;
  assert(chdir(pathbuf) == 0);

  if (isatty(0)) return termwrap();
  return exec_server();
}