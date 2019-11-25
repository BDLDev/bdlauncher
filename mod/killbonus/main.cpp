#include<Loader.h>
#include<MC.h>
#include"../cmdhelper.h"
#include "rapidjson/document.h"
#include "../base/base.h"
#include "../money/money.h"
#include<fstream>
using namespace rapidjson;
extern "C" {
    BDL_EXPORT void killbonus_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
unordered_map<int,std::pair<int,int> > bonus_mp;
void load(){
    char buf[256*1024];
    Document dc;
    std::ifstream ff;
    ff.open("config/killbonus.json",std::ios::in);
    buf[ff.readsome(buf,256*1024)]=0;
    ff.close();
    if(dc.ParseInsitu(buf).HasParseError()){
        printf("[KillBonus] Config JSON ERROR!\n");
        exit(1);
    }
    for(auto& i:dc.GetArray()){
        auto bMin=i["MinMoney"].GetInt();
        auto bMax=i["MaxMoney"].GetInt();
        auto eid=i["eid"].GetInt();
        bonus_mp[eid]={bMin,bMax};
    }
}
int dbg_die;
static void toggle_dbg(){
    dbg_die=!dbg_die;
}
void handle_die(Mob& a,ActorDamageSource const& b){
    if(b.isChildEntitySource() || b.isEntitySource()){
        auto ent=getMC()->getLevel()->fetchEntity(b.getEntityUniqueID(),false);
        if(ent && ent->isPlayer()){
            auto vid=a.getEntityTypeId();
            ServerPlayer* sp=(ServerPlayer*)ent;
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
void killbonus_init(std::list<string>& modlist) {
    load();
    register_cmd("reload_kbonus",fp(load),"reload kill bonus",1);
    register_cmd("dbg_kbonus",fp(toggle_dbg),"debug kill bonus",1);
    reg_mobdie(handle_die);
    printf("[KillBonus] Loaded V2019-11-25\n");
    load_helper(modlist);
}