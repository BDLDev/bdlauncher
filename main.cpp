#include<bits/stdc++.h>
#include<dlfcn.h>
#include<sys/prctl.h>
#include<PFishHook.h>
#include "mods.h"
static void* handle;
void* main_real; 
void* MCHandle(){
  return handle;
}
int entry_real(int a,char** b);
__attribute__((constructor)) void entry(){
  prctl(PR_MPX_DISABLE_MANAGEMENT,0,0,0,0,0);
  prctl(PR_TASK_PERF_EVENTS_DISABLE,0,0,0,0,0);
  prctl(PR_SET_TIMERSLACK,10000,0,0,0,0);
  handle=dlopen(NULL, RTLD_LAZY);
  printf("HOOK DONE... Injecting to main\n");
  HookIt(dlsym(handle,"main"),&main_real,(void*)entry_real);
}
int entry_real(int a,char** b){
  printf("Server Started\n");
  handle=dlopen(NULL, RTLD_LAZY);
  MOD_loadall();
  return ((int(*)(int,char**))main_real)(a,b);
}
