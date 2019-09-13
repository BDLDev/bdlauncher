#include"../myhook.h"
#include<list>
#include<string>
#include<dlfcn.h>
#include"aux.h"
using std::string;
#include<cstdint>
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
void* nfix2_o,*nfix2_cl;
void nfix2(u64 a,u64 b,u64 c) {
    ((typeof(&nfix2))nfix2_o)(a,b,c);
    ((typeof(&nfix2))nfix2_cl)(a,b,0);
}

static void patch_func(string&& name,const char* pay,int sz) {
    auto sym=dlsym(NULL,name.c_str());
    auto start = ROUND_PAGE_DOWN((size_t)sym);
    auto end   = ROUND_PAGE_UP((size_t)sym + sz);
    mprotect((void*)start, end - start, PROT_READ | PROT_WRITE | PROT_EXEC);
    memcpy(sym,pay,sz);
    mprotect((void*)start, end - start, PROT_READ | PROT_EXEC);
}
void patchall() {
    MyHook(fp(dlsym(NULL,"_ZN20EncryptedNetworkPeer16enableEncryptionERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE")),fp(dummy));
    nfix2_o=MyHook(fp(dlsym(NULL,"_ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK11LoginPacket")),fp(nfix2));
    nfix2_cl=dlsym(NULL,"_ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK29ClientToServerHandshakePacket");
    void* sym=dlsym(NULL,"_ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK11LoginPacket");
    auto start = ROUND_PAGE_DOWN((size_t)sym + 0x1f48);
    auto end   = ROUND_PAGE_UP((size_t)sym + 0x1f48 + 5);
    mprotect((void*)start, end - start, PROT_READ | PROT_WRITE | PROT_EXEC);
    memset((char*)sym+0x1f48,0x90,5);
    mprotect((void*)start, end - start, PROT_READ | PROT_EXEC);
}
void opti_init(std::list<string>& modlist) {
    printf("[OPTI] loaded!\n");
    patchall();
    load_helper(modlist);
}
