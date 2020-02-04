#include "myhook.h"
#include <list>
#include <Loader.h>
//#include <MC.h>
#include <fstream>
#include <global.h>
#include <logger.h>
#include <minecraft/json.h>
#include <bdlexport.h>

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
  RedStoneMUL = value["RedStoneMUL"].asInt(0);
  /*float *pp   = (float *) (((uintptr_t) dlsym(NULL, "_ZN10LevelChunk4tickER11BlockSourceRK4Tick")) + 0x19b1698);
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

void mod_init(std::list<string> &modlist) {
  load();
  do_log("loaded! V2020-02-04");
  load_helper(modlist);
}
