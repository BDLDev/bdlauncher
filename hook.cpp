#include "myhook.h"
#include "hook.h"
static char* jmpbed;
//extern std::unordered_map<void*,char*> my_hooks;
char* wr_jmp(void* addr) {
    if(jmpbed==nullptr)
        jmpbed=(char*)mmap(0,65536,7,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    char* ret=jmpbed;
    memcpy(jmpbed,"\xff\x25\x00\x00\x00\x00",6);
    memcpy(jmpbed+6,&addr,8);
    jmpbed+=14;
    return ret;
}
char* wr_regcmd(void* call,void* arg) {
    if(jmpbed==nullptr)
        jmpbed=(char*)mmap(0,65536,7,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    char* ret=jmpbed;
    /*
       0x0000000000001190 <+0>:	57	push   rdi
   0x0000000000001191 <+1>:	48 b8 77 77 77 77 ff ff ff ff	movabs rax,0xffffffff77777777
   0x000000000000119b <+11>:	48 bf 77 77 77 77 ff ff ff ff	movabs rdi,0xffffffff77777777
   0x00000000000011a5 <+21>:	ff d0	call   rax
   0x00000000000011a7 <+23>:	5f	pop    rdi
   0x00000000000011a8 <+24>:	48 89 07	mov    QWORD PTR [rdi],rax
   0x00000000000011ab <+27>:	48 89 f8	mov    rax,rdi
   0x00000000000011ae <+30>:	c3	ret   
   */
  memcpy(jmpbed,"\x57\x48\xb8",3);
  jmpbed+=3;
  memcpy(jmpbed,&call,8);
  jmpbed+=8;
  memcpy(jmpbed,"\x48\xbf",2);
  jmpbed+=2;
  memcpy(jmpbed,&arg,8);
  jmpbed+=8;
  memcpy(jmpbed,"\xff\xd0\x5f\x48\x89\x07\x48\x89\xf8\xc3",10);
  jmpbed+=10;
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
    void* ret;
    int res=HookIt(oldfunc,&ret,newfunc);
    if(res!=0) {
        printf("error hooking %p\n",oldfunc);
    }
    return ret;

}
