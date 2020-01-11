#include<Loader.h>
#include<MC.h>
#include"../cmdhelper.h"
#include "rapidjson/document.h"
#include "../base/base.h"
#include<fstream>
#include"seral.hpp"
#include"../serial/seral.hpp"
using namespace std;
using namespace rapidjson;
extern "C" {
    BDL_EXPORT void mod_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
pair<int,int> WEATHER,RSTONE,ENTITY;
void load(){
    Document dc;
    char* buf;
    int siz;
    file2mem("config/tps.json",&buf,siz);
    if(dc.ParseInsitu(buf).HasParseError()){
        printf("[TPSInfo] Config JSON ERROR!\n");
        exit(1);
    }
    WEATHER={dc["WEATHER_START"].GetInt(),dc["WEATHER_STOP"].GetInt()};
    RSTONE={dc["RSTONE_START"].GetInt(),dc["RSTONE_STOP"].GetInt()};
    ENTITY={dc["ENTITY_START"].GetInt(),dc["ENTITY_STOP"].GetInt()};
    free(buf);
}
int tkl;
clock_t lastc=clock();
int tps=0;
THook(void*,_ZN5Level4tickEv,Level& a){
    tkl++;
    if(tkl==8){
        auto delt=clock()-lastc;
        float second=
        CLOCKS_PER_SEC
    }
}
void mod_init(std::list<string>& modlist) {
    load();
    printf("[TPSInfo] Loaded " BDL_TAG "\n");
    load_helper(modlist);
}