#include<Loader.h>
#include<MC.h>
#include"../cmdhelper.h"
#include "rapidjson/document.h"
#include "../base/base.h"
#include<fstream>
#include"seral.hpp"

using namespace rapidjson;
extern "C" {
    BDL_EXPORT void mod_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
int NoEnderPick,NoExplodeBreak,NoFarm;
void load(){
    Document dc;
    FileBuffer fb("config/protect.json");
    if(dc.ParseInsitu(fb.data).HasParseError()){
        printf("[WorldProtect] JSON ERROR pos: %d type: %s!\n",dc.GetErrorOffset(),GetParseErrorFunc(dc.GetParseError()));
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
void mod_init(std::list<string>& modlist) {
    load();
    #define getfn(x) fp(dlsym(NULL,x))
    if(NoEnderPick){
        MyHook(getfn("_ZN21EndermanTakeBlockGoal6canUseEv"),fp(dummy));
    }
    if(NoFarm){
        MyHook(getfn("_ZNK9FarmBlock15transformOnFallER11BlockSourceRK8BlockPosP5Actorf"),fp(dummy));
    }
    printf("[WorldProtect] Loaded " BDL_TAG "\n");
    load_helper(modlist);
}