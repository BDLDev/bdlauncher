#include "myhook.h"
#include "hook.h"
static char* jmpbed;
//extern std::unordered_map<void*,char*> my_hooks;
char* wr_jmp(void* addr) {
    char* ret=jmpbed;
    memcpy(jmpbed,"\xff\x25\x00\x00\x00\x00",6);
    memcpy(jmpbed+6,&addr,8);
    jmpbed+=14;
    return ret;
}
char* wr_ret_uni(u64 a,char* b) {
    if(jmpbed==nullptr)
        jmpbed=(char*)mmap(0,65536,7,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    char* ret=jmpbed;
    const char* pay="H\270\335\335\335\335\335\335\335\335ATI\211\374H\277wwww\377\377\377\377\377\320I\211\004$L\211\340A\\\xc3";
    memcpy(jmpbed,pay,37);
    memcpy(jmpbed+2,&b,8);
    memcpy(jmpbed+17,&a,8);
    jmpbed+=37;
    return ret;
}
void MyPatch(void* oldfunc, void* newfunc,size_t size) {
#define PAGE_SIZE 0x1000
#define ROUND_PAGE_DOWN(num) ((num) & ~(PAGE_SIZE - 1))
#define ROUND_PAGE_UP(num) (((num) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))
    auto start = ROUND_PAGE_DOWN((size_t)oldfunc);
    auto end   = ROUND_PAGE_UP((size_t)oldfunc + size);
    mprotect((void*)start, end - start, PROT_READ | PROT_WRITE | PROT_EXEC);
    memcpy(oldfunc,newfunc,size);
    mprotect((void*)start, end - start, PROT_READ | PROT_EXEC);
}
void* MyHook(void* oldfunc, void* newfunc) {
    //if(jmpbed==nullptr)
    //    jmpbed=(char*)mmap(0,65536<<1,7,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
//thanks to PFishHook,now can use duplicate hooks!
    void* ret;
    int res=HookIt(oldfunc,&ret,newfunc);
    if(res!=0) {
        printf("error hooking %p\n",oldfunc);
    }
    return ret;
    /*
        if(my_hooks.count(oldfunc)){
    //        printf("already hook %p  %p->%p\n",oldfunc,*(u64*)(my_hooks[oldfunc]+6),newfunc);
            void* ret;
            memcpy(&ret,my_hooks[oldfunc]+6,8);
            memcpy(my_hooks[oldfunc]+6,&newfunc,8);
            return ret;
        }else{
            void* ret;
            char* dumm=wr_jmp(newfunc);
            my_hooks[oldfunc]=dumm;
            int res=HookIt(oldfunc,&ret,dumm);
            if(res!=0){
                printf("error hooking %p\n",oldfunc);
            }
            return ret;
        }*/
}
