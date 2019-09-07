#include "mods.h"
#include "myhook.h"
#include<list>
#include <unistd.h>
#include <stdlib.h>
#include<signal.h>
extern "C" {
    int main(int ac,char** av);
}
static void* old_main;
static std::list<void*> onsht;
void register_shutdown(void* fn) {
    onsht.push_back(fn);
}
void call_sht(int d) {
    for(auto i:onsht) {
        ((void(*)())i)();
    }
    if(d==SIGINT) {
        int pipefd[2];
        pipe2(pipefd,0);
        close(0);
        dup2(pipefd[0],0);
        write(pipefd[1],"stop\nstop\n",10);
        close(pipefd[1]);
        printf("\nshuting down... press enter,use stop instead at next time!\n");
    }
}
static void shthelper_reg() {
#define sh(a) signal(a,call_sht);
    sh(SIGHUP)
    sh(SIGINT)
    sh(SIGILL)
    sh(SIGABRT)
    sh(SIGFPE)
    sh(SIGSEGV)
}

static int mc_entry(int ac,char** av) {
    printf("[MOD] main,start loading mods\n");
    mod_loadall();
    shthelper_reg();
    int fk= ((typeof(&main))old_main)(ac,av);
    call_sht(0);
    return fk;
}

struct init_d {
    init_d() {
        printf("[MOD] inject to %p pid %d\n",main,getpid());
        old_main=MyHook(fp(main),fp(mc_entry));
    }
} _dummy;
