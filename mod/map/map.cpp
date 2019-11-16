#include<cstdio>
#include<list>
#include<string>
#include<unordered_map>
#include"../cmdhelper.h"
#include"base.h"
#include<vector>
#include<Loader.h>
#include<MC.h>
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
    BDL_EXPORT void map_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
static unsigned int getrgb(unsigned char r,unsigned char g,unsigned char b){
    return 0xff000000|(r<<16)|(g<<8)|b;
}
static unsigned int datam[128*128];
static void loaddata(const char* fn){
    FILE* a=fopen(fn,"r");
    if(!a) return;
    fread(datam,sizeof(datam),1,a);
    fclose(a);
    for(int i=0;i<128*128;++i){
        datam[i]|=0xff000000;
    }
}
extern "C"{
    Packet* _ZNK16MapItemSavedData17getFullDataPacketEv(MapItemSavedData*,char*);
};
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
    string datname=a[0];
    Player& pl=*(Player*)b.getEntity();
    auto xx=pl.getCarriedItem().getUserData();
    MapItemSavedData& data=getMC()->getLevel()->getMapSavedData(unique_ptr<CompoundTag>(*xx));
    loaddata(datname.c_str());
    for(int y=0;y<128;++y)
    for(int x=0;x<128;++x)
        data.setPixel(datam[y*128+x],x,y);
    data.setLocked();
    data.save(*getMC()->getLevel()->getLevelStorage());
    /*
    char filler[16384]={0};
    auto x=_ZNK16MapItemSavedData17getFullDataPacketEv(&data,filler);
    printf("%s\n",filler);
    b.getDimension()->forEachPlayer([&](Player& p)->bool{
        ((ServerPlayer*)&p)->sendNetworkPacket(*(Packet*)filler);
        return true;
    });*/
}
void map_init(std::list<string>& modlist) {
    printf("[CustomMap] loaded!\n");
    register_cmd("map",(void*)oncmd,"CustomMap",1);
    load_helper(modlist);
}
