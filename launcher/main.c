#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "shared.h"
#include "exec_server.h"
#include "termwrap.h"

char const *bedrock_server = "./bedrock_server";

int main(int argc, char *argv[]) {
  if (argc >= 2) bedrock_server = (char const *) argv[1];
  char pathbuf[256];
  readlink("/proc/self/exe", pathbuf, sizeof pathbuf);
  *strrchr(pathbuf, '/') = 0;
  chdir(pathbuf);

  if (isatty(0)) return termwrap();
  return exec_server();
}