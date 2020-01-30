#include "myhook.h"
#include <Loader.h>
#include <MC.h>
#include <fstream>
#include <global.h>
#include <logger.h>
#include <minecraft/json.h>

const char meta[] __attribute__((used, section("meta"))) =
    "name:opti\n"
    "version:20200121\n"
    "author:sysca11\n"
    "depend:base@20200121";

typedef uint64_t u64;
typedef uint32_t u32;
typedef int64_t s64;
typedef int32_t s32;
using namespace std;
extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);
USED static void dummy() {}
extern "C" {
void _ZN14NetworkHandler16enableAsyncFlushERK17NetworkIdentifier(long a1, long a2);
}
THook(void **, _ZN14NetworkHandler23getEncryptedPeerForUserERK17NetworkIdentifier, void **a1, long a2, long a3) {
  a1[0] = a1[1] = nullptr;
  //_ZN14NetworkHandler16enableAsyncFlushERK17NetworkIdentifier(a2,a3);
  return a1;
}
#define PAGE_SIZE 0x1000
#define ROUND_PAGE_DOWN(num) ((num) & ~(PAGE_SIZE - 1))
#define ROUND_PAGE_UP(num) (((num) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))
int RedStoneMUL;
int Rtick;
THook(void *, _ZN13CircuitSystem8evaluateEP11BlockSource, void *a, void *b) {
  if (!RedStoneMUL) { return original(a, b); }
  Rtick++;
  if (Rtick % RedStoneMUL == 0) { return original(a, b); }
  return nullptr;
}
void fast_math() { asm("stmxcsr -0x4(%rsp)\norl $0x8040,-0x4(%rsp)\nldmxcsr -0x4(%rsp)"); }
void load() {
  ifstream ifs{"config/opti.json"};
  Json::Value value;
  Json::Reader reader;
  if (!reader.parse(ifs, value)) {
    auto msg = reader.getFormattedErrorMessages();
    do_log("%s", msg.c_str());
    exit(1);
  }
  if (value["FastMath"].asBool(false)) {
    fast_math();
    do_log("FastMath enabled");
  }
  // 1.13.1 26581604 1.13.2 26587812 1.14 0x9287ed8 0x78d6840
  /*RedStoneMUL = value["RedStoneMUL"].asInt(0);
  float *pp   = (float *) (((uintptr_t) dlsym(NULL, "_ZN10LevelChunk4tickER11BlockSourceRK4Tick")) + 0x19b1698);
  int newSpawnDist = value["pVal"].asInt(0);
  int hit          = -114514;
  for (int i = -5000; i < 10000; ++i) {
    if (pp[i] == 9216) {
      do_log("found %d", i);
      if (hit != -114514) {
        do_log("Warning!!!Broken patch dected.Wont Patch it!");
        hit = -114514;
        break;
      }
      hit = i;
    }
  }
  if (hit == -114514) {
    do_log("Warning!!!Broken patch dected.Wont Patch it!");
    return;
  }
  float *patch = pp + hit;
  mprotect(
      (void *) ROUND_PAGE_DOWN((ulong) patch), (ROUND_PAGE_UP((ulong) patch) - ROUND_PAGE_DOWN((ulong) patch)),
      PROT_WRITE | PROT_READ | PROT_EXEC);
  *pp = newSpawnDist;*/
}
/*
typedef unsigned long __int64;
typedef unsigned long _QWORD;
typedef unsigned int _DWORD;
typedef unsigned char _BYTE;
THook(__int64,_ZN12LayerDetails9LayerBase11_nextRandomERljl,void *thi, unsigned int a2, __int64 a3)
{
  unsigned int v4; // [rsp+0h] [rbp-2Ch]
  signed int v5; // [rsp+10h] [rbp-1Ch]

  v5 = (*(_QWORD *)thi >> 24) % (__int64)(unsigned int)a2;
  *(_QWORD *)thi *= 6364136223846793005LL * *(_QWORD *)thi + 1442695040888963407LL;
  *(_QWORD *)thi += a3;
  if ( v5 >= 0 )
    v4 = v5;
  else
    v4 = (_DWORD)a2 + v5;
  return v4;
}

THook(void *,_ZN4Core6Random16_initGenRandFastEj,void *thi, unsigned int a2)
{
  void *result; // rax
  int i; // [rsp+10h] [rbp-18h]
  unsigned int v4; // [rsp+18h] [rbp-10h]

  *((_DWORD *)thi + 1) = a2;
  v4 = a2;
  for ( i = 1; i < 398; ++i )
  {
    *((_DWORD *)thi + i + 1) = i + 1812433253 * ((v4 >> 30) ^ v4);
    v4 = i + 1812433253 * ((v4 >> 30) ^ v4);
  }
  result = thi;
  *((_DWORD *)thi + 625) = 624;
  *((_DWORD *)thi + 628) = 398;
  return result;
}

THook(void *,_ZN4Core6Random12_initGenRandEj,void *thi, int a2)
{
  void *result; // rax

  *((_DWORD *)thi + 1) = a2;
  for ( *((_DWORD *)thi + 625) = 1; *((_DWORD *)thi + 625) < 624; ++*((_DWORD *)thi + 625) )
    *((_DWORD *)thi + *((int *)thi + 625) + 1) = *((_DWORD *)thi + 625)
                                                 + 1812433253
                                                 * ((*((_DWORD *)thi + *((_DWORD *)thi + 625)) >> 30) ^ *((_DWORD *)thi
+ *((_DWORD *)thi + 625))); result = thi;
  *((_DWORD *)thi + 628) = 624;
  return result;
}
void * _ZN4Core6Random12_initGenRandEj(void *thi, int a2)
{
  void *result; // rax

  *((_DWORD *)thi + 1) = a2;
  for ( *((_DWORD *)thi + 625) = 1; *((_DWORD *)thi + 625) < 624; ++*((_DWORD *)thi + 625) )
    *((_DWORD *)thi + *((int *)thi + 625) + 1) = *((_DWORD *)thi + 625)
                                                 + 1812433253
                                                 * ((*((_DWORD *)thi + *((_DWORD *)thi + 625)) >> 30) ^ *((_DWORD *)thi
+ *((_DWORD *)thi + 625))); result = thi;
  *((_DWORD *)thi + 628) = 624;
  return result;
}
unsigned int dword_9056508[]={0, 0x9908B0DF};
THook(__int64,_ZN4Core6Random13_genRandInt32Ev,void *thi)
{
  int v1; // eax
  unsigned int v3; // [rsp+14h] [rbp-Ch]
  unsigned int v4; // [rsp+14h] [rbp-Ch]

  if ( *((_DWORD *)thi + 625) < 625 )
  {
    if ( *((_DWORD *)thi + 625) == 624 )
      *((_DWORD *)thi + 625) = 0;
  }
  else
  {
    _ZN4Core6Random12_initGenRandEj(thi, 5489);
    *((_DWORD *)thi + 625) = 0;
  }
  if ( *((_DWORD *)thi + 625) >= 227 )
  {
    if ( *((_DWORD *)thi + 625) >= 623 )
      *((_DWORD *)thi + 624) = dword_9056508[*((_BYTE *)thi + 4) & 1] ^ ((*((_DWORD *)thi + 1) & 0x7FFFFFFF | *((_DWORD
*)thi + 624) & 0x80000000) >> 1) ^ *((_DWORD *)thi + 397); else
      *((_DWORD *)thi + *((int *)thi + 625) + 1) = dword_9056508[*((_BYTE *)thi + 4 * *((_DWORD *)thi + 625) + 8) & 1] ^
((*((_DWORD *)thi + *((_DWORD *)thi + 625) + 2) & 0x7FFFFFFF | *((_DWORD *)thi + *((int *)thi + 625) + 1) & 0x80000000)
>> 1) ^ *((_DWORD *)thi + *((_DWORD *)thi + 625) - 226);
  }
  else
  {
    *((_DWORD *)thi + *((int *)thi + 625) + 1) = dword_9056508[*((_BYTE *)thi + 4 * *((_DWORD *)thi + 625) + 8) & 1] ^
((*((_DWORD *)thi + *((_DWORD *)thi + 625) + 2) & 0x7FFFFFFF | *((_DWORD *)thi + *((int *)thi + 625) + 1) & 0x80000000)
>> 1) ^ *((_DWORD *)thi + *((_DWORD *)thi + 625) + 398); if ( *((_DWORD *)thi + 628) < 624 )
    {
      *((_DWORD *)thi + *((int *)thi + 628) + 1) = *((_DWORD *)thi + 628)
                                                   + 1812433253
                                                   * ((*((_DWORD *)thi + *((_DWORD *)thi + 628)) >> 30) ^ *((_DWORD
*)thi + *((_DWORD *)thi + 628)));
      ++*((_DWORD *)thi + 628);
    }
  }
  v1 = (*((_DWORD *)thi + 625))++;
  v3 = *((_DWORD *)thi + v1 + 1);
  v4 = ((v3 ^ (v3 >> 11)) << 7) & 0x9D2C5680 ^ v3 ^ (v3 >> 11);
  return (v4 << 15) & 0xEFC60000 ^ v4 ^ (((v4 << 15) & 0xEFC60000 ^ v4) >> 18);
}
*/

void mod_init(std::list<string> &modlist) {
  load();
  do_log("loaded! V2019-12-19");
  load_helper(modlist);
}
