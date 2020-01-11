#include<Loader.h>
#include<MC.h>
#include"../cmdhelper.h"
#include "rapidjson/document.h"
#include "../base/base.h"
#include "../money/money.h"
#include<fstream>
using namespace rapidjson;
extern "C" {
    BDL_EXPORT void mod_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
unordered_map<int,std::pair<int,int> > bonus_mp;
void load(){
    Document dc;
    std::ifstream ff;
    FileBuffer fb("config/killbonus.json");
    if(dc.ParseInsitu(fb.data).HasParseError()){
        printf("[KillBonus] JSON ERROR pos: %d type: %s!\n",dc.GetErrorOffset(),GetParseErrorFunc(dc.GetParseError()));
        exit(1);
    }
    for(auto& i:dc.GetArray()){
        auto bMin=i["MinMoney"].GetInt();
        auto bMax=i["MaxMoney"].GetInt();
        auto eid=i["eid"].GetInt();
        bonus_mp[eid]={bMin,bMax};
    }
}
static int dbg_die;
static void toggle_dbg(){
    dbg_die=!dbg_die;
}
static void handle_die(Mob& a,ActorDamageSource const& b){
    if(b.isChildEntitySource() || b.isEntitySource()){
        auto ent=getSrvLevel()->fetchEntity(b.getEntityUniqueID(),false);
        ServerPlayer* sp=getSP(ent);
        if(sp){
            auto vid=a.getEntityTypeId();
            if(dbg_die){
                sendText(sp,"you killed"+std::to_string(vid));
            }
            auto it=bonus_mp.find(vid);
            if(it!=bonus_mp.end()){
                auto mi=it->second.first,mx=it->second.second;
                auto addm=rand()%(mx+1-mi)+mi;
                add_money(sp->getName(),addm);
                sendText(sp,"you get $"+std::to_string(addm)+" by killing");
            }
        }
    }
}
void mod_init(std::list<string>& modlist) {
    load();
    register_cmd("reload_kbonus",load,"reload kill bonus",1);
    register_cmd("dbg_kbonus",toggle_dbg,"debug kill bonus",1);
    reg_mobdie(handle_die);
    printf("[KillBonus] Loaded " BDL_TAG "\n");
    load_helper(modlist);
}