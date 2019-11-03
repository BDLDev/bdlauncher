#include"../myhook.h"
#include<Loader.h>
#include<MC.h>
typedef uint64_t u64;
typedef uint32_t u32;
typedef int64_t s64;
typedef int32_t s32;
//NOTE: No longer maintaining. Use https://github.com/Sysca11/Rocket instead

extern "C" {
    void opti_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
static void dummy() {

}
extern "C" {void _ZN14NetworkHandler16enableAsyncFlushERK17NetworkIdentifier(long a1,long a2);}
THook(void**,_ZN14NetworkHandler23getEncryptedPeerForUserERK17NetworkIdentifier,void **a1, long a2, long a3){
	a1[0]=a1[1]=nullptr;
	_ZN14NetworkHandler16enableAsyncFlushERK17NetworkIdentifier(a2,a3);
	return a1;
}
void opti_init(std::list<string>& modlist) {
    printf("[OPTI] loaded!\n");
    load_helper(modlist);
}
