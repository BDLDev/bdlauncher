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
u32* Rnd_init(u32* a,u32 b) {
    *(a+1)=b;
    return a;
}
u32 Rnd_int32(u32* a) {
    u32& last=*(a+1);
    last=(last*1103515245+12345);
    return last;
}
u32 Rnd_int(u32* t,u32 a) {
    return a?Rnd_int32(t)%a:0;
}

double R_R(u32* a) {
    u32& l=*(a+1);
    l=(l*1103515245+12345);
    return (2.3283064365386963e-10)*l;
}
u64 L_init(u64* a,u64 b,u64 c) {
    u64 hash=*(a+1);
    hash=(hash*1103515245+12345)*b+c;
    return hash;
}
s32 L_next(u64* a,u32 b,u64 c) {
    u64& x=*a;
    s32 rt=x%b;
    if(rt<0) rt+=b;
    x*=1103515245;
    x+=c;
    return rt;
}
void patch_func(string&& name,const char* pay,int sz) {
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
#define fixr(a,b) MyHook(fp(dlsym(NULL,a)),fp(b))
    fixr("_ZNK12LayerDetails9LayerBase10initRandomEll",L_init);
    //fixr("_ZN12LayerDetails9LayerBase4initEl",L_init2);
    fixr("_ZN12LayerDetails9LayerBase11_nextRandomERljl",L_next);
    fixr("_ZN6Random13_genRandInt32Ev",Rnd_int32);
    fixr("_ZN6Random16_initGenRandFastEj",Rnd_init);
    fixr("_ZN6Random7nextIntEi",Rnd_int);
    sym=dlsym(NULL,"_ZN6Random13_genRandReal2Ev");
    start = ROUND_PAGE_DOWN((size_t)sym);
    end   = ROUND_PAGE_UP((size_t)sym + 14);
    mprotect((void*)start, end - start, PROT_READ | PROT_WRITE | PROT_EXEC);
#define jmpbed sym
    memcpy(jmpbed,"\xff\x25\x00\x00\x00\x00",6);
    auto pr=(void*)R_R;
    memcpy(((char*)jmpbed)+6,&pr,8);
    mprotect((void*)start, end - start, PROT_READ | PROT_EXEC);
    patch_func("_ZNKSt8__detail10_Hash_nodeISt4pairIK8ChunkPosSt8weak_ptrI10LevelChunkEELb1EE7_M_nextEv","\x48\x8b\x07\xc3",4);
    patch_func("_ZNK7WeakPtrI11BlockLegacyEdeEv","\x48\x8b\x07\x48\x8b\x00\xc3",7);
    patch_func("_ZNK7WeakPtrI11BlockLegacyEptEv","\x48\x8b\x07\x48\x8b\x00\xc3",7);
    patch_func("_ZSt3maxIiERKT_S2_S2_","\x48\x89\xf0\x8b\x0f\x3b\x0e\x48\x0f\x4f\xc7\xc3",12);
    patch_func("_ZNK11BlockLegacyeqERKS_","\x31\xc0\x48\x39\xf7\x0f\x94\xc0\xc3",9);
    patch_func("_ZNK8ChunkPoseqERKS_","H\213\aH;\006\017\224\300\xc3",10);
    patch_func("_ZNK11BlockLegacyneERKS_","\x31\xc0\x48\x39\xf7\x0f\x95\xc0\xc3",9);
    patch_func("_ZN7NewTypeIhEC2ERKh","\x8a\x06\x88\x07\xc3",5);
    patch_func("_ZN7NewTypeIhEC2ERKS0_","\x8a\x06\x88\x07\xc3",5);
    patch_func("_ZNK4Vec33dotERKS_","\363\017\020\016\363\017Y\017\362\017\020W\004\362\017\020F\004\017Y\302\363\017X\310\017\306\300\345\363\017X\301\xc3",34);
    patch_func("_ZNKSt10unique_ptrI25SubChunkBrightnessStorageSt14default_deleteIS0_EE3getEv","\x48\x8b\x07\xc3",4);
    patch_func("_ZN4Vec3C2Efff","\363\017\021\a\363\017\021O\004\363\017\021W\b\xc3",15);

    //spec
    patch_func("_ZNK5Block14getLegacyBlockEv","\x48\x8b\x47\x10\x48\x8b\x00\xc3",8);
    patch_func("_ZNK8SubChunk8getBlockEt","\x48\x8b\x7f\x20\x48\x8b\x07\xff\x60\x18",10);
    patch_func("_ZNKSt6atomicI10ChunkStateEcvS0_Ev","\x0f\xbe\x07\xc3",4);
    patch_func("_ZNKSt6atomicI10ChunkStateE4loadESt12memory_order","\x0f\xbe\x07\xc3",4);
    patch_func("_ZNSt6atomicI10ChunkStateE5storeES0_St12memory_order","\x40\x88\x37\xc3",4);
}
/*
_ZNKSt8__detail10_Hash_nodeISt4pairIK8ChunkPosSt8weak_ptrI10LevelChunkEELb1EE7_M_nextEv
mov (%rdi),%rax
retn
48 8b 07 c3
*/
/*
_ZNK7WeakPtrI11BlockLegacyEdeEv
_ZNK7WeakPtrI11BlockLegacyEptEv
mov (%rdi),%rax
mov (%rax),%rax
retn
48 8b 07
48 8b 00
c3
*/
/*
_ZNK8SubChunk8getBlockEt
return (*(__int64 (__fastcall **)(_QWORD, _QWORD))(**((_QWORD **)this + 4) + 24LL))(*((_QWORD *)this + 4), a2);
48 8b 7f 20 48 8b 07 ff 60 18
   0x0000000000001150 <+0>:	48 8b 7f 20	mov    0x20(%rdi),%rdi
   0x0000000000001154 <+4>:	48 8b 07	mov    (%rdi),%rax
   0x0000000000001157 <+7>:	ff 60 18	jmpq   *0x18(%rax)
*/
/*
_ZSt3maxIiERKT_S2_S2_
   0x0000000000001150 <+0>:	48 89 f0	mov    %rsi,%rax
   0x0000000000001153 <+3>:	8b 0f	mov    (%rdi),%ecx
   0x0000000000001155 <+5>:	3b 0e	cmp    (%rsi),%ecx
   0x0000000000001157 <+7>:	48 0f 4f c7	cmovg  %rdi,%rax
   0x000000000000115b <+11>:	c3	retq
\x48\x89\xf0\x8b\x0f\x3b\x0e\x48\x0f\x4f\xc7\xc3
*/
/*
_ZNK11BlockLegacyeqERKS_
   0x0000000000001160 <+0>:	31 c0	xor    %eax,%eax
   0x0000000000001162 <+2>:	48 39 f7	cmp    %rsi,%rdi
   0x0000000000001165 <+5>:	0f 94 c0	sete   %al
   0x0000000000001168 <+8>:	c3	retq
\x31\xc0\x48\x39\xf7\x0f\x94\xc0\xc3
_ZNK11BlockLegacyneERKS_
\x31\xc0\x48\x39\xf7\x0f\x95\xc0\xc3
*/
/*
_ZN7NewTypeIhEC2ERKh
_ZN7NewTypeIhEC2ERKS0_
   0x0000000000001170 <+0>:	8a 06	mov    (%rsi),%al
   0x0000000000001172 <+2>:	88 07	mov    %al,(%rdi)
   0x0000000000001174 <+4>:	c3	retq
*/
/*
_ZNK4Vec33dotERKS_
   0x0000000000001180 <+0>:	f3 0f 10 0e	movss  (%rsi),%xmm1
   0x0000000000001184 <+4>:	f3 0f 59 0f	mulss  (%rdi),%xmm1
   0x0000000000001188 <+8>:	f2 0f 10 57 04	movsd  0x4(%rdi),%xmm2
   0x000000000000118d <+13>:	f2 0f 10 46 04	movsd  0x4(%rsi),%xmm0
   0x0000000000001192 <+18>:	0f 59 c2	mulps  %xmm2,%xmm0
   0x0000000000001195 <+21>:	f3 0f 58 c8	addss  %xmm0,%xmm1
   0x0000000000001199 <+25>:	0f c6 c0 e5	shufps $0xe5,%xmm0,%xmm0
   0x000000000000119d <+29>:	f3 0f 58 c1	addss  %xmm1,%xmm0
   0x00000000000011a1 <+33>:	c3	retq
"\363\017\020\016\363\017Y\017\362\017\020W\004\362\017\020F\004\017Y\302\363\017X\310\017\306\300\345\363\017X\301\xc3"
*/
/*
_ZNKSt10unique_ptrI25SubChunkBrightnessStorageSt14default_deleteIS0_EE3getEv
   0x00000000000011b0 <+0>:	48 8b 07	mov    (%rdi),%rax
   0x00000000000011b3 <+3>:	c3	retq


_ZN4Vec3C2Efff
   0x00000000000011c0 <+0>:	f3 0f 11 07	movss  %xmm0,(%rdi)
   0x00000000000011c4 <+4>:	f3 0f 11 4f 04	movss  %xmm1,0x4(%rdi)
   0x00000000000011c9 <+9>:	f3 0f 11 57 08	movss  %xmm2,0x8(%rdi)
   0x00000000000011ce <+14>:	c3	retq

_ZNK5Block14getLegacyBlockEv
   0x00000000000011f0 <+0>:	48 8b 47 10	mov    0x10(%rdi),%rax
   0x00000000000011f4 <+4>:	c3	retq

*/
void opti_init(std::list<string>& modlist) {
    printf("[OPTI] loaded!\n");
    patchall();
    load_helper(modlist);
}
