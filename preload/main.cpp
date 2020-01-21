#include "mods.h"
#include "myhook.h"
#include <list>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/prctl.h>
extern "C" {
int main(int ac, char **av);
}
static void *old_main;

static int mc_entry(int ac, char **av) {
  printf("[MOD] main,start loading mods\n");
  mod_loadall();
  int fk = ((typeof(&main)) old_main)(ac, av);
  return fk;
}

struct init_d {
  init_d() {
    prctl(PR_SET_TIMERSLACK, 5000000);
    printf("[MOD] inject to %p pid %d\n", main, getpid());
    old_main = MyHook(fp(main), fp(mc_entry));
    setenv("LD_PRELOAD", "", 1);
  }
} _dummy;
