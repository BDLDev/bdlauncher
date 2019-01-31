#include<bits/stdc++.h>
#include<dlfcn.h>
#include<sys/prctl.h>
#include<PFishHook.h>
#include <sys/mman.h>
#include "mods.h"
static void* handle;
static void* main_real; 
void* MCHandle(){
  return handle;
}
static int entry_real(int a,char** b);
__attribute__((constructor)) void entry(){
  prctl(PR_MPX_DISABLE_MANAGEMENT,0,0,0,0,0);
  prctl(PR_TASK_PERF_EVENTS_DISABLE,0,0,0,0,0);
  prctl(PR_SET_TIMERSLACK,10000,0,0,0,0);
  mprotect((void*)0x555555554000,0x555558910000-0x555555554000,7);
  handle=dlopen(NULL, RTLD_LAZY);
  printf("HOOK DONE... Injecting to main\n");
  HookIt(dlsym(handle,"main"),&main_real,(void*)entry_real);
}
static int entry_real(int a,char** b){
  printf("Server Started\n");
  mprotect((void*)0x555555554000,0x555558910000-0x555555554000,7);
  handle=dlopen(NULL, RTLD_LAZY);
  MOD_loadall();
  return ((int(*)(int,char**))main_real)(a,b);
}
