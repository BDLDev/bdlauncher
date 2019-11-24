#include<Loader.h>
#include<MC.h>
#include"../cmdhelper.h"
#include "rapidjson/document.h"
#include "../base/base.h"
#include "../money/money.h"
#include<fstream>
using namespace rapidjson;
extern "C" {
    BDL_EXPORT void protect_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
int NoEnderPick,NoExplodeBreak,NoFarm;
void load(){
    char buf[256*1024];
    Document dc;
    std::ifstream ff;
    ff.open("config/protect.json",std::ios::in);
    buf[ff.readsome(buf,256*1024)]=0;
    ff.close();
    if(dc.ParseInsitu(buf).HasParseError()){
        printf("[WorldProtect] Config JSON ERROR!\n");
        exit(1);
    }
    NoEnderPick=dc["NoEnderPick"].GetBool();
    NoExplodeBreak=dc["NoExplodeBreak"].GetBool();
    NoFarm=dc["NoFarm"].GetBool();
}
void* dummy(){
    return nullptr;
}
struct Explosion{
    void setFire(bool);
    void setBreaking(bool);
};
THook(void*,_ZN9Explosion7explodeEv,Explosion* thi){
    if(NoExplodeBreak){
        thi->setBreaking(false);
        thi->setFire(false);
    }
    return original(thi);
}
void protect_init(std::list<string>& modlist) {
    load();
    #define getfn(x) fp(dlsym(NULL,x))
    if(NoEnderPick){
        MyHook(getfn("_ZN21EndermanTakeBlockGoal6canUseEv"),fp(dummy));
    }
    if(NoFarm){
        MyHook(getfn("_ZNK9FarmBlock15transformOnFallER11BlockSourceRK8BlockPosP5Actorf"),fp(dummy));
    }
    printf("[WorldProtect] Loaded V2019-11-24\n");
    load_helper(modlist);
}