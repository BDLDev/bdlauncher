#include<cstdio>
#include<list>
#include<string>
#include<unordered_map>
#include"../cmdhelper.h"
#include"base.h"
#include<vector>
#include"minecraft/level/Level.h"
#include"minecraft/actor/Player.h"
#include"seral.hpp"
#include <sys/stat.h>
#include<unistd.h>
#include <sys/stat.h>
#include<memory>
#include<dlfcn.h>
#include<cstdlib>

#include"map.h"

using std::string;
extern "C" {
    void map_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
static unsigned int getrgb(unsigned char r,unsigned char g,unsigned char b){
    return 0xff000000|(r<<16)|(g<<8)|b;
}
static unsigned int datam[128*128];
static void loaddata(const char* fn){
    FILE* a=fopen(fn,"rb");
    if(!a) return;
    fread(datam,sizeof(datam),1,a);
    fclose(a);
    for(int i=0;i<128*128;++i){
        datam[i]|=0xff000000;
    }
}
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
    if((int)b.getPermissionsLevel()<1) return;
    string datname=a[0];
    Player& pl=*(Player*)b.getEntity();
    MapItemSavedData& data=getMC()->getLevel()->getMapSavedData(pl.getCarriedItem());
    loaddata(datname.c_str());
    for(int y=0;y<128;++y)
    for(int x=0;x<128;++x)
        data.setPixel(datam[y*128+x],x,y);
    data.setLocked();
}
void map_init(std::list<string>& modlist) {
    printf("[CustomMap] loaded!\n");
    register_cmd("map",(void*)oncmd,"CustomMap");
    load_helper(modlist);
}
