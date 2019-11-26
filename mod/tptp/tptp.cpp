#include<cstdio>
#include<list>
#include<forward_list>
#include<string>
#include<unordered_map>
#include"../cmdhelper.h"
#include<vector>
#include<Loader.h>
#include<MC.h>
#include"seral.hpp"
#include <sys/stat.h>
#include<unistd.h>
#include <sys/stat.h>
#include"base.h"
#include<cmath>
#include<cstdlib>
#include<ctime>
#include"../gui/gui.h"

using std::string;
using std::unordered_map;
using std::forward_list;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
//#define dbg_printf(...) {}
#define dbg_printf printf
extern "C" {
   BDL_EXPORT void tp_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
struct Vpos {
    int x,y,z,dim;
    string name;
    Vpos() {}
    Vpos(int a,int b,int c,int d,string e) {
        x=a,y=b,z=c,dim=d,name=e;
    }
    static string tostr(const Vpos& a) {
        char buf[32768];
        int ptr=0;
        putint(buf,ptr,a.x);
        putint(buf,ptr,a.y);
        putint(buf,ptr,a.z);
        putint(buf,ptr,a.dim);
        putstr(buf,ptr,a.name);
        return string(buf,ptr);
    }
    static void fromstr(const string& a,Vpos& b) {
        const char* buf=a.c_str();
        int ptr=0;
        getint(buf,ptr,b.x);
        getint(buf,ptr,b.y);
        getint(buf,ptr,b.z);
        getint(buf,ptr,b.dim);
        b.name=getstr(buf,ptr);
    }
    void tele(Actor& ply) const {
        TeleportA(ply, {x,y,z}, {dim});
    }
};
struct home {
    int cnt=0;
    Vpos vals[5];
    static string tostr(const home& a) {
        char buf[65535];
        int ptr=0;
        putint(buf,ptr,a.cnt);
        for(int i=0; i<a.cnt; ++i) {
            putstr(buf,ptr,Vpos::tostr(a.vals[i]));
        }
        return string(buf,ptr);
    }
    static void fromstr(const string& a,home& b) {
        const char* buf=a.c_str();
        int ptr=0;
        getint(buf,ptr,b.cnt);
        for(int i=0; i<b.cnt; ++i) {
            string tmp;
            tmp=getstr(buf,ptr);
            Vpos::fromstr(tmp,b.vals[i]);
        }
    }
};
static unordered_map<string,home> homes;
static forward_list<Vpos> wps;
static void save() {
    char* bf;
    int sz=maptomem(homes,&bf,h_str2str,home::tostr);
    mem2file("data/tp/tp.db",bf,sz);
    sz=settomem(wps,&bf,Vpos::tostr);
    mem2file("data/tp/wps.db",bf,sz);
}
static void load() {
    //register_shutdown(fp(save));
    mkdir("data",S_IRWXU);
    mkdir("data/tp",S_IRWXU);
    char* buf;
    int sz;
    struct stat tmp;
    if(stat("data/tp/tp.db",&tmp)==-1) {
        save();
    }
    file2mem("data/tp/tp.db",&buf,sz);
    memtomap(homes,buf,h_str2str_load,home::fromstr);
    file2mem("data/tp/wps.db",&buf,sz);
    memtoset(wps,buf,Vpos::fromstr);
}
struct tpreq {
    int dir; //0=f
    string name;
};
static unordered_map<string,tpreq> tpmap;
static unordered_map<string,int> wild_limit;
static void oncmd_suic(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    KillActor(b.getEntity());
    outp.success("§e你死了");
}
void sendTPForm(const string& from,int type,ServerPlayer* sp){
    string cont="§e"+from+(type?"想传送你到对方":"想传送到你")+"\n";
    string name=sp->getName();
    auto lis=new list<pair<string,std::function<void()> > >();
    lis->push_back({
        "同意",[name]{
            auto x=getMC()->getLevel()->getPlayer(name);
            if(x)
                runcmdAs("tpa ac",x);
        }
    });
    lis->push_back({
        "拒绝",[name]{
            auto x=getMC()->getLevel()->getPlayer(name);
            if(x)
                runcmdAs("tpa de",x);
        }
    });
    gui_Buttons(sp,cont,"TP 请求",lis);
}
void sendTPChoose(ServerPlayer* sp,const string& type){
    string name=sp->getName();
    gui_ChoosePlayer(sp,"§e选择目标玩家","TP Req",[name,type](const string& dest){
        auto xx=getMC()->getLevel()->getPlayer(name);
            if(xx)
            runcmdAs("tpa "+type+" "+SafeStr(dest),xx);
    });
}
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    int pl=(int)b.getPermissionsLevel();
    string name=b.getName();
    string dnm=a.size()==2?a[1]:"";
    Player* dst=NULL;
    if(dnm!="")
        dst=getplayer_byname2(dnm);
    if(dst) dnm=dst->getName();
    ARGSZ(1)
    if(a[0]=="f") {
        //from
        if(dst==NULL) {
            outp.error("§e[Teleport] 玩家不在线");
            return;
        }
        if(tpmap.count(dnm)) {
            outp.error("§e[Teleport] 请求中");
            return;
        }
        tpmap[dnm]= {0,name};
        outp.success("§e[Teleport] 你向对方发送了传送请求");
        sendText(dst,"§e[Teleport] "+name+" 想让你传送到他/她所在的位置\n§e输入“/tpa ac” 接受 或 “/tpa de” 拒绝");
        sendTPForm(name,1,(ServerPlayer*)dst);
    }
    if(a[0]=="t") {
        //to
        if(dst==NULL) {
            outp.error("§e[Teleport] 玩家不在线");
            return;
        }
        if(tpmap.count(dnm)) {
            outp.error("§e[Teleport] 请求中");
            return;
        }
        tpmap[dnm]= {1,name};
        outp.success("§e[Teleport] 你向对方发送了传送请求");
        sendText(dst,"§e[Teleport] "+name+" 想传送到你所在位置\n§e输入“/tpa ac” 接受 或 “/tpa de” 拒绝");
        sendTPForm(name,0,(ServerPlayer*)dst);
    }
    if(a[0]=="gui"){
        auto lis=new list<pair<string,std::function<void()> > >();
        lis->push_back({
            "传送到玩家",[name]{
                auto x=getMC()->getLevel()->getPlayer(name);
                if(x)
                {
                    sendTPChoose((ServerPlayer*)x,"t");
                }
            }
        });
        lis->push_back({
            "传送玩家到你",[name]{
                auto x=getMC()->getLevel()->getPlayer(name);
                if(x)
                {
                    sendTPChoose((ServerPlayer*)x,"f");
                }
            }
        });
        gui_Buttons((ServerPlayer*)b.getEntity(),"发送传送请求","发送传送请求",lis);
    }
    if(a[0]=="ac") {
        //accept
        if(tpmap.count(name)==0) return;
        tpreq req=tpmap[name];
        tpmap.erase(name);
        outp.success("§e[Teleport] 你已接受对方的传送请求");
        dst=getplayer_byname(req.name);
        if(dst) {
            sendText(dst,"§e[Teleport] "+name+" 接受了请求");
            if(req.dir==0) {
                //f
                TeleportA(*getplayer_byname(name),dst->getPos(), {dst->getDimensionId()});
            } else {
                TeleportA(*dst,b.getWorldPosition(), {b.getEntity()->getDimensionId()});
            }
        }
    }
    if(a[0]=="de") {
        //deny
        if(tpmap.count(name)==0) return;
        tpreq req=tpmap[name];
        tpmap.erase(name);
        outp.success("§e[Teleport] 你已拒绝对方的传送请求");
        dst=getplayer_byname(req.name);
        if(dst)
            sendText(dst,"§c[Teleport] "+name+" 已拒绝传送请求");
    }
    if(a[0]=="help") {
        outp.error("传送系统指令列表:\n/tpa gui gui传送\n/tpa f 玩家名 ——让玩家传送到你\n/tpa t 玩家名 ——传送你到玩家\n/tpa ac ——同意\n/tpa de ——拒绝");
    }
}

static void oncmd_home(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    int pl=(int)b.getPermissionsLevel();
    string name=b.getName();
    string homen=a.size()==2?a[1]:"hape";
    Vec3 pos=b.getWorldPosition();
    //printf("%f %f %f\n",pos.x,pos.y,pos.z);
    ARGSZ(1)
    if(a[0]=="add") {
        if(homes.count(name)==0) homes[name]= {};
        home& myh=homes[name];
        if(myh.cnt==5) {
            outp.error("[Teleport] 无法再添加更多的家");
            return;
        }
        myh.vals[myh.cnt]=Vpos(pos.x,pos.y,pos.z,b.getEntity()->getDimensionId(),homen);
        myh.cnt++;
        save();
        outp.success("§e[Teleport] 已添加家");
    }
    if(a[0]=="del") {
        if(homes.count(name)==0) homes[name]= {};
        home& myh=homes[name];
        home tmpn;
        tmpn=myh;
        tmpn.cnt=0;
        for(int i=0; i<myh.cnt; ++i) {
            if(myh.vals[i].name!=homen) {
                tmpn.vals[tmpn.cnt++]=myh.vals[i];
            }
        }
        myh=tmpn;
        save();
        outp.success("§e[Teleport] 已删除家");
    }
    if(a[0]=="go") {
        if(homes.count(name)==0) homes[name]= {};
        home& myh=homes[name];
        for(int i=0; i<myh.cnt; ++i) {
            if(myh.vals[i].name==homen) {
                myh.vals[i].tele(*b.getEntity());
                outp.success("§e[Teleport] 已传送到家");
            }
        }
    }
    if(a[0]=="ls") {
        if(homes.count(name)==0) homes[name]= {};
        home& myh=homes[name];
        sendText((Player*)b.getEntity(),"§e家列表:");
        for(int i=0; i<myh.cnt; ++i) {
            sendText((Player*)b.getEntity(),myh.vals[i].name);
        }
        outp.success("§e============");
    }
    if(a[0]=="gui"){
        if(homes.count(name)==0) homes[name]= {};
        home& myh=homes[name];
        auto lis=new list<pair<string,std::function<void()> > >();
        for(int i=0; i<myh.cnt; ++i) {
            string warpname=myh.vals[i].name;
            lis->push_back({
                "到 "+warpname,
                [warpname,name]()->void{
                    auto x=getMC()->getLevel()->getPlayer(name);
                    if(x)
                        runcmdAs("home go "+SafeStr(warpname),x);
                }
            });
        }
        gui_Buttons((ServerPlayer*)b.getEntity(),"回家\n","家",lis);
    }
    if(a[0]=="help") {
        outp.error("家指令列表:\n/home gui gui回家\n/home add 名字 ——添加一个家\n/home ls ——查看你的所有家\n/home go 名字 ——回家");
    }
}
static void oncmd_warp(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    int pl=(int)b.getPermissionsLevel();
    // printf("pl %d\n",pl);
    string name=b.getName();
    Vec3 pos=b.getWorldPosition();
    ARGSZ(1)
    if(a[0]=="add") {
        if(pl<1) return;
        ARGSZ(2)
        wps.push_front(Vpos(pos.x,pos.y,pos.z,b.getEntity()->getDimensionId(),a[1]));
        save();
        outp.success("§e§e[Teleport] 已添加Warp");
        return;
    }
    if(a[0]=="del") {
        if(pl<1) return;
        ARGSZ(2)
        wps.remove_if([a](const Vpos& b)->bool{return b.name==a[1];});
        save();
        outp.success("§e§e[Teleport] 已删除Warp");
        return;
    }
    if(a[0]=="ls") {
        outp.addMessage("§eWarp列表:");
        for(auto const& i:wps) {
            outp.addMessage(i.name);
        }
        outp.success("§e===========");
        return;
    }
    if(a[0]=="help") {
        outp.error("Warp指令列表:\n/warp ls ——查看地标列表\n/warp 地标名 ——前往一个地标");
    }
    if(a[0]=="gui"){
        auto lis=new list<pair<string,std::function<void()> > >();
        string nam=b.getName();
        for(auto const& i:wps) {
            string warpname=i.name;
            lis->push_back({
                "前往 "+warpname,
                [warpname,nam]()->void{
                    auto x=getMC()->getLevel()->getPlayer(nam);
                    if(x)
                        runcmdAs("warp "+SafeStr(warpname),x);
                }
            });
        }
        gui_Buttons((ServerPlayer*)b.getEntity(),"前往地标\n","warp",lis);
    }
    //go
    for(auto const& i:wps) {
        if(i.name==a[0]) {
            i.tele(*b.getEntity());
            outp.success("§e[Teleport] 已传送到Warp");
            return;
        }
    }
}
bool CanBack=true;
static unordered_map<string,pair<Vec3,int> > deathpoint;
static void oncmd_back(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    if(!CanBack) {outp.error("not enabled on this server"); return;}
    auto it=deathpoint.find(b.getName());
    if(it==deathpoint.end()){
        outp.error("cant find deathpoint");
        return;
    }
    ServerPlayer* sp=(ServerPlayer*)b.getEntity();
    TeleportA(*sp,it->second.first,{it->second.second});
    deathpoint.erase(it);
    outp.success("okay!back to deathpoint");
}
static void handle_mobdie(Mob& mb,const ActorDamageSource&){
    if(!CanBack) return;
    auto sp=getSP(mb);
    if(sp){
        ServerPlayer* sp=(ServerPlayer*)&mb;
        sendText(sp,"use /back to return last deathpoint");
        deathpoint[sp->getName()]={sp->getPos(),sp->getDimensionId()};
    }
}
void tp_init(std::list<string>& modlist) {
    if(getenv("NO_BACK")) CanBack=0;
    printf("[TPs] loaded! V2019-11-26\n");
    load();
    register_cmd("suicide",(void*)oncmd_suic,"自杀");
    register_cmd("tpa",(void*)oncmd,"传送系统");
    register_cmd("home",(void*)oncmd_home,"家");
    register_cmd("warp",(void*)oncmd_warp,"地标");
    register_cmd("back",(void*)oncmd_back,"back to deathpoint");
    reg_mobdie(handle_mobdie);
    srand(time(0));
    load_helper(modlist);
}
