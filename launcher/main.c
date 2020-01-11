#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char const *bedrock_server = "./bedrock_server";
    if (argc >= 2) bedrock_server = argv[1];
    char buf[256];
    readlink("/proc/self/exe", buf, sizeof buf);
    *strrchr(buf, '/') = 0;
    chdir(buf);
    setenv("LD_LIBRARY_PATH", ".", 1);
    setenv("LD_PRELOAD", "preload.so", 1);
    return execv(bedrock_server, argv);

}