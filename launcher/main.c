#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char const *bedrock_server = "./bedrock_server";
  if (argc >= 2) bedrock_server = argv[1];
  char pathbuf[256], ldbuf[1024] = ".";
  readlink("/proc/self/exe", pathbuf, sizeof pathbuf);
  *strrchr(pathbuf, '/') = 0;
  chdir(pathbuf);
  if (getenv("LD_LIBRARY_PATH")) {
    strcat(ldbuf, ":");
    strcat(ldbuf, getenv("LD_LIBRARY_PATH"));
  }
  setenv("LD_LIBRARY_PATH", ldbuf, 1);
  setenv("LD_PRELOAD", "preload.so", 1);
  return execv(bedrock_server, argv);
}