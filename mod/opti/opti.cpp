#include"../myhook.h"
#include<Loader.h>
#include<MC.h>
#include"rapidjson/document.h"
#include<fstream>
typedef uint64_t u64;
typedef uint32_t u32;
typedef int64_t s64;
typedef int32_t s32;
using namespace std;
extern "C" {
    BDL_EXPORT void opti_init(std::list<string>& modlist);
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
#define PAGE_SIZE 0x1000
#define ROUND_PAGE_DOWN(num) ((num) & ~(PAGE_SIZE - 1))
#define ROUND_PAGE_UP(num) (((num) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))
int RedStoneMUL;
int Rtick;
THook(void*,_ZN13CircuitSystem8evaluateEP11BlockSource,void* a,void* b){
    if(!RedStoneMUL){
        return original(a,b);
    }
    Rtick++;
    if(Rtick%RedStoneMUL==0){
        return original(a,b);
    }
    return nullptr;
}
void load(){
    using namespace rapidjson;
    Document dc;
    ifstream ff;
    ff.open("config/opti.json",ios::in);
    char buf[4096];
    buf[ff.readsome(buf,4096)]=0;
    ff.close();
    if(dc.ParseInsitu(buf).HasParseError()){
        printf("[OPTI] Config JSON ERROR!\n");
        exit(1);
    }
    //1.13.1 26581604 1.13.2 26587812
    RedStoneMUL=dc["RedStoneMUL"].GetInt();
    /*
    float* patch=(float*)(dc["pAddr"].GetUint64());
    if(patch!=nullptr){
        void* pp=dlsym(NULL,"_ZN10LevelChunk4tickER11BlockSourceRK4Tick");
        patch=(float*)((ulong)pp+(ulong)patch);
        printf("%p\n",patch);
        if(*patch!=9216){
            printf("[OPTI] Warning!!!Broken patch dected.Wont Patch it!\n");
        }else{
            mprotect((void*)ROUND_PAGE_DOWN((ulong)patch),(ROUND_PAGE_UP((ulong)patch)-ROUND_PAGE_DOWN((ulong)patch)),PROT_WRITE|PROT_READ|PROT_EXEC);
            *patch=dc["pVal"].GetInt();
        }
    }*/
    float* pp=(float*)(((uintptr_t)dlsym(NULL,"_ZN10LevelChunk4tickER11BlockSourceRK4Tick"))+26580000);
    //to +10000 bytes 26590000
    int newSpawnDist=dc["pVal"].GetInt();
    int hit=-1;
    for(int i=0;i<2500;++i){
        if(pp[i]==9216){
            printf("found %d\n",i);
            if(hit!=-1){
                printf("[OPTI] Warning!!!Broken patch dected.Wont Patch it!\n");
                hit=-1;
                break;
            }
            hit=i;
        }
    }
    if(hit==-1){
        printf("[OPTI] Warning!!!Broken patch dected.Wont Patch it!\n");
        return;
    }
    float* patch=pp+hit;
    mprotect((void*)ROUND_PAGE_DOWN((ulong)patch),(ROUND_PAGE_UP((ulong)patch)-ROUND_PAGE_DOWN((ulong)patch)),PROT_WRITE|PROT_READ|PROT_EXEC);
    pp[hit]=newSpawnDist;
}
void opti_init(std::list<string>& modlist) {
    load();
    printf("[OPTI] loaded!\n");
    load_helper(modlist);
}
