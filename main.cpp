#include "mods.h"
#include "myhook.h"
#include "cmdhelper.h"
#include <unistd.h>
#include <stdlib.h>
extern "C"{
    int main(int ac,char** av);
}
void* old_main;
void call_sht(int);
int mc_entry(int ac,char** av){
    printf("[MOD] main,start loading mods\n");
    mod_loadall();
    cmdhelper_init();
    int fk= ((typeof(&main))old_main)(ac,av);
    call_sht(0);
   return fk;
}
std::unordered_map<void*,char*> my_hooks; /* important */
std::unordered_map<std::string,void*> cmd_map;

struct init_d{
    init_d(){
        printf("[MOD] inject to %p pid %d\n",main,getpid());
	//sleep(5);
        old_main=MyHook(fp(main),fp(mc_entry));
    }
}_dummy;
