#include<cstdio>
#include<list>
#include<forward_list>
#include<string>
#include<unordered_map>
#include"../cmdhelper.h"
#include<vector>
#include"minecraft/level/Level.h"
#include"minecraft/actor/Player.h"
#include"minecraft/actor/ItemActor.h"
#include"minecraft/core/GameMode.h"
#include"seral.hpp"
#include <sys/stat.h>
#include<unistd.h>
#include <sys/stat.h>
#include"money.h"
#include"base.h"
#include<cmath>
#include<cstdlib>
#include<ctime>

using std::string;
using std::unordered_map;
using std::forward_list;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
//#define dbg_printf(...) {}
#define dbg_printf printf
extern "C"{
    void tp_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
struct Vpos{
    int x,y,z,dim;
    string name;
    Vpos(){}
    Vpos(int a,int b,int c,int d,string e){
        x=a,y=b,z=c,dim=d,name=e;
        //printf("new vpos %d %d %d\n",a,b,c);
    }
    static string tostr(const Vpos& a){
        char buf[32768];
        int ptr=0;
        putint(buf,ptr,a.x);
        putint(buf,ptr,a.y);
        putint(buf,ptr,a.z);
        putint(buf,ptr,a.dim);
        putstr(buf,ptr,a.name);
        return string(buf,ptr);
    }
    static void fromstr(const string& a,Vpos& b){
        const char* buf=a.c_str();
        int ptr=0;
        getint(buf,ptr,b.x);
        getint(buf,ptr,b.y);
        getint(buf,ptr,b.z);
        getint(buf,ptr,b.dim);
        b.name=getstr(buf,ptr);
    }
    void tele(Actor& ply) const{
        TeleportA(ply,{x,y,z},{dim});
    }
};
struct home{
    int cnt=0;
    Vpos vals[5];
    static string tostr(const home& a){
        char buf[65535];
        int ptr=0;
        putint(buf,ptr,a.cnt);
        for(int i=0;i<a.cnt;++i){
            putstr(buf,ptr,Vpos::tostr(a.vals[i]));
        }
        return string(buf,ptr);
    }
    static void fromstr(const string& a,home& b){
        const char* buf=a.c_str();
        int ptr=0;
        getint(buf,ptr,b.cnt);
        for(int i=0;i<b.cnt;++i){
            string tmp;
            tmp=getstr(buf,ptr);
            Vpos::fromstr(tmp,b.vals[i]);
        }
    }
};
static unordered_map<string,home> homes;
static forward_list<Vpos> wps;
static void save(){
    char* bf;
    int sz=maptomem(homes,&bf,h_str2str,home::tostr);
    mem2file("data/tp/tp.db",bf,sz);
    sz=settomem(wps,&bf,Vpos::tostr);
    mem2file("data/tp/wps.db",bf,sz);
}
static void load(){
register_shutdown(fp(save));
    mkdir("data",S_IRWXU);
    mkdir("data/tp",S_IRWXU);
    char* buf;int sz;
    struct stat tmp;
    if(stat("data/tp/tp.db",&tmp)==-1){
        save();
    }
    file2mem("data/tp/tp.db",&buf,sz);
    memtomap(homes,buf,h_str2str_load,home::fromstr);
    file2mem("data/tp/wps.db",&buf,sz);
    memtoset(wps,buf,Vpos::fromstr);
}
struct tpreq{
    int dir; //0=f
    string name;
};
static unordered_map<string,tpreq> tpmap;
static unordered_map<string,int> wild_limit;
static void oncmd_suic(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp){
//b.getEntity()->kill();
KillActor(b.getEntity());
outp.success("killed");
}
static void oncmd_dim(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp){
    int pl=(int)b.getPermissionsLevel();
    string name=b.getName();
    Player* dst=NULL;
    dst=getplayer_byname(name);
    if(pl<1) return;
    TeleportA(*dst,b.getWorldPosition(),{atoi(a[0].c_str())});
    outp.success("okay");
}
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp){
    int pl=(int)b.getPermissionsLevel();
    string name=b.getName();
    string dnm=a.size()==2?a[1]:"";
    Player* dst=NULL;
    if(dnm!="")
        dst=getplayer_byname(dnm);
    if(a[0]=="f"){
        //from
        if(dst==NULL){
            outp.error("请求不存在");
            return;
        }
        if(tpmap.count(dnm)){
            outp.error("请求中");
            return;
        }
        tpmap[dnm]={0,name};
        //printf("%p\n",dst);
        sendText(dst,name+"想tp您到他那");
        outp.success("okay");
    }
    if(a[0]=="t"){
        //to
        if(dst==NULL){
            outp.error("请求不存在");
            return;
        }
        if(tpmap.count(dnm)){
            outp.error("请求中");
            return;
        }
        tpmap[dnm]={1,name};
        sendText(dst,name+"想tp到您这");
        outp.success("okay");
    }
    if(a[0]=="ac"){
        //accept
        if(tpmap.count(name)==0) return;
        tpreq req=tpmap[name];
        tpmap.erase(name);
        outp.success("okay");
        dst=getplayer_byname(req.name);
        if(dst){
            sendText(dst,name+"接受了请求");
            if(req.dir==0){
                //f
                TeleportA(*getplayer_byname(name),dst->getPos(),{dst->getDimensionId()});
            }else{
                TeleportA(*dst,b.getWorldPosition(),{b.getEntity()->getDimensionId()});
            }
        }
    }
    if(a[0]=="de"){
        //deny
        if(tpmap.count(name)==0) return;
        tpreq req=tpmap[name];
        tpmap.erase(name);
        outp.success("okay");
        dst=getplayer_byname(req.name);
        if(dst)
        sendText(dst,name+"对方已拒绝");
    }
    if(a[0]=="rand"){
        if(pl>0){
            if(a[1]!="")
                name=a[1];
        }else{
            int s=wild_limit[name];
            if(s==3){
                outp.error("limit!\n");
                return;
            }
            s++;
            wild_limit[name]=s;
        }
        //* random *
        int y=72+rand()%10;
        int x=rand()%80000-40000;
        int z=rand()%80000-40000;
        Player* py=getplayer_byname(name);
        if(py) TeleportA(*py,{x,y,z},{b.getEntity()->getDimensionId()});
        outp.success("okay");
    }
}

static void oncmd_home(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp){
    int pl=(int)b.getPermissionsLevel();
    string name=b.getName();
    string homen=a.size()==2?a[1]:"";
    Vec3 pos=b.getWorldPosition();
    //printf("%f %f %f\n",pos.x,pos.y,pos.z);
    if(a.size()==0) return;
    if(a[0]=="add"){
        if(homes.count(name)==0) homes[name]={};
        home& myh=homes[name];
        if(myh.cnt==5){
            outp.error("cnt>5");
            return;
        }
        myh.vals[myh.cnt]=Vpos(pos.x,pos.y,pos.z,b.getEntity()->getDimensionId(),homen);
        myh.cnt++;
        //save();
        outp.success("已添加");
    }
    if(a[0]=="del"){
        if(homes.count(name)==0) homes[name]={};
        home& myh=homes[name];
        home tmpn;
        tmpn=myh;
        tmpn.cnt=0;
        for(int i=0;i<myh.cnt;++i){
            if(myh.vals[i].name!=homen){
                tmpn.vals[tmpn.cnt++]=myh.vals[i];
            }
        }
        myh=tmpn;
        //save();
        outp.success("已删除");
    }
    if(a[0]=="go"){
        if(homes.count(name)==0) homes[name]={};
        home& myh=homes[name];
        for(int i=0;i<myh.cnt;++i){
            if(myh.vals[i].name==homen){
                myh.vals[i].tele(*b.getEntity());
                outp.success("");
            }
        }
        outp.success("已传送");
    }
    if(a[0]=="ls"){
        if(homes.count(name)==0) homes[name]={};
        home& myh=homes[name];
        for(int i=0;i<myh.cnt;++i){
            sendText((Player*)b.getEntity(),myh.vals[i].name);
        }
        outp.success("============");
    }
}
static void oncmd_warp(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp){
    int pl=(int)b.getPermissionsLevel();
   // printf("pl %d\n",pl);
    string name=b.getName();
    Vec3 pos=b.getWorldPosition();
    if(a.size()==0) return;
    if(a[0]=="add"){
        if(pl<1) return;
        wps.push_front(Vpos(pos.x,pos.y,pos.z,b.getEntity()->getDimensionId(),a[1]));
        //save();
        outp.success("已添加");
        return;
    }
    if(a[0]=="del"){
        if(pl<1) return;
        wps.remove_if([a](const Vpos& b)->bool{return b.name==a[1];});
        //save();
        outp.success("已删除");
        return;
    }
    if(a[0]=="ls"){
        for(auto const& i:wps){
            outp.addMessage(i.name);
        }
        outp.success("===========");
        return;
    }
    //go
    for(auto const& i:wps){
        if(i.name==a[0]){
            i.tele(*b.getEntity());
            outp.success("已传送");
            return;
        }
    }
}

void tp_init(std::list<string>& modlist){
    printf("[TPs] loaded!\n");
    load();
    register_cmd("suicide",(void*)oncmd_suic);
    register_cmd("tpa",(void*)oncmd);
    register_cmd("home",(void*)oncmd_home);
    register_cmd("warp",(void*)oncmd_warp);
    register_cmd("chdim",(void*)oncmd_dim);
    srand(time(0));
    load_helper(modlist);
}
