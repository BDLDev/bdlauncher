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
#include"money.h"
#include"base.h"
#include<cmath>
#include<deque>
#include<dlfcn.h>
#include<tuple>
#include"rapidjson/document.h"
#include<fstream>
#include"../gui/gui.h"

using std::string;
using std::deque;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define dbg_printf(...) {}
//#define dbg_printf printf
static int dummy(){return 0;}
extern "C" {
    BDL_EXPORT void land_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
typedef float R;
#define PERMB 1
#define PERMU 2
#define PERMP 4
#define PERMA 8
struct land {
    int dim_perm;
    int x,y;
    int dx,dy;
    string owner;
    unsigned long size() {
        return dx*dy;
    }
    bool inland(int xx,int yy,int di) const {
        return di==(dim_perm>>4) && xx>=x && yy>=y && xx-x<dx && yy-y<dy;
    }
    bool checkown(const string& name) const {
        return owner.find("|"+name+"|")!=std::string::npos;
    }
    bool canpop(const string& name) const {
        return checkown(name) || ((dim_perm&PERMP)!=0);
    }
    bool canuse(const string& name) const {
        return checkown(name) || ((dim_perm&PERMU)!=0);
    }
    bool canbuild(const string& name) const {
        return checkown(name) || ((dim_perm&PERMB)!=0);
    }
    bool canatk(const string& name) const {
        return checkown(name) || ((dim_perm&PERMA)!=0);
    }
    bool coll(int xb1,int xb2,int yb1,int yb2,int dim,const string& nm) const {
        if((dim_perm>>4)==dim) {
            int xa1=this->x,ya1=this->y,xa2=this->x+dx-1,ya2=this->y+dy-1;
            int t1x=max(xa1,xb1);
            int t1y=max(ya1,yb1);
            int t2x=min(xa2,xb2);
            int t2y=min(ya2,yb2);
            return t2x>=t1x && t2y>=t1y && !checkown(nm);
        }
        return false;
    }
    void addown(const string& name) {
        owner+="|"+name+"|";
    }
    void rmown(const string& n) {
        string fk="|"+n+"|";
        auto i=owner.find(fk);
        if(i!=string::npos) owner.erase(i,i+fk.size());
    }
    static string tostr(const land& a) {
        char buf[32768];
        int ptr=0;
        putint(buf,ptr,a.dim_perm);
        putint(buf,ptr,a.x);
        putint(buf,ptr,a.y);
        putint(buf,ptr,a.dx);
        putint(buf,ptr,a.dy);
        putstr(buf,ptr,a.owner);
        return string(buf,ptr);
    }
    static void fromstr(const string& b,land& a) {
        const char* buf=b.c_str();
        int ptr=0;
        getint(buf,ptr,a.dim_perm);
        getint(buf,ptr,a.x);
        getint(buf,ptr,a.y);
        getint(buf,ptr,a.dx);
        getint(buf,ptr,a.dy);
        a.owner=getstr(buf,ptr);
    }
};

static std::forward_list<land> lands;
static std::unordered_map<string,Vec3> startpos,endpos;
static void save();
static land* getLand_r(int x,int z,int dim) {
    for(auto &i:lands) {
        if(i.inland(x,z,dim)) {
            return &i;
        }
    }
    return NULL;
}

struct key_hash:public std::unary_function<std::tuple<int,int,int>,unsigned int>{
    unsigned int operator()(const std::tuple<int,int,int>& k) const{
        return ((std::get<0>(k)<<16)|(std::get<1>(k)))^(std::get<2>(k)<<24);
    }
};
template<typename K,int cap>
struct TMCache{
    std::unordered_map<K,land*,key_hash> pools[2];
    int nowptr=0;
    void push(const K& k,land* v){
        pools[nowptr].insert({k,v});
        if(pools[nowptr].size()==cap){
            nowptr=!nowptr;
            pools[nowptr].clear();
        }
    }
    land* fetch(const K& k){
        auto it=pools[nowptr].find(k);
        if(it!=pools[nowptr].end()) return it->second;
        it=pools[!nowptr].find(k);
        if(it!=pools[!nowptr].end()) return it->second;
        return nullptr;
    }
    void clear(){
        pools[0].clear();
        pools[1].clear();
    }
};
static TMCache<std::tuple<int,int,int>,160 > tcache;
static void ccache() {
    tcache.clear();
}
land* getLand(int x,int z,int dim) {
    land* res;
    if(res=tcache.fetch({x,z,dim})) return res;
    res=getLand_r(x,z,dim);
    tcache.push({x,z,dim},res);
    return res;
}

int LAND_PRICE,LAND_PRICE2;
using namespace rapidjson;
void loadcfg(){
    Document dc;
    std::ifstream ff;
    ff.open("config/land.json",std::ios::in);
    char buf[1024*8];
    buf[ff.readsome(buf,1024*8)]=0;
    ff.close();
    if(dc.ParseInsitu(buf).HasParseError()){
        printf("[LAND] Config JSON ERROR!\n");
        exit(1);
    }
    LAND_PRICE=dc["buy_price"].GetInt();
    LAND_PRICE2=dc["sell_price"].GetInt();
}
unordered_map<string,int> choose_state;
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    int pl=(int)b.getPermissionsLevel();
    string name=b.getName();
    ARGSZ(1)
    if(a[0]=="start") {
        choose_state[name]=1;
        outp.success("§e[Land system] 点地选择点 A，输入/land end选择另一个点");
    }
    if(a[0]=="end") {
        if(!startpos.count(name)){
            outp.error("[Land system] 请选择开始");
            return;
        }
        choose_state[name]=2;
        outp.success("§e[Land system] 点地选择点 B");
    }
    if(a[0]=="exit"){
        choose_state.erase(name);
        return;
    }
    if(a[0]=="prebuy"){
        choose_state.erase(name);
        if(startpos.count(name)+endpos.count(name)!=2) {
            outp.error("[Land system] 请选择开始和结束点");
            return;
        }
        Vec3 pa=startpos[name];
        Vec3 pb=endpos[name];
        int xx(round(min(pa.x,pb.x))),yy(round(min(pa.z,pb.z))),xx2(round(max(pa.x,pb.x))),yy2(round(max(pa.z,pb.z)));
        int fg=0;
        for(auto const& i:lands) {
            if(i.coll(xx,xx2,yy,yy2,b.getEntity()->getDimensionId(),name) && pl==0) {
                fg=1;
                break;
            }
        }
        if(fg) {
            outp.error("[Land system] 领地不得重叠");
            startpos.erase(name);
            endpos.erase(name);
            return;
        }
        land tmp;
        tmp.x=xx,tmp.y=yy,tmp.dx=xx2-xx+1,tmp.dy=yy2-yy+1;
        unsigned long price=LAND_PRICE*tmp.size();
        if(price>100000000 || price<=0 || xx2-xx+1>16384 || yy2-yy+1>16384){
            outp.error("[Land system] 我不给你圈那么大一块");
            startpos.erase(name);
            endpos.erase(name);
            return;
        }
        char buf[1000];
        sprintf(buf,"§e[Land system] 选择完毕，该区域价格 %d,使用“/land buy”购买",price);
        outp.success(string(buf));
    }
    if(a[0]=="buy") {
        choose_state.erase(name);
        if(startpos.count(name)+endpos.count(name)!=2) {
            outp.error("[Land system] 请选择开始和结束点");
            return;
        }
        Vec3 pa=startpos[name];
        Vec3 pb=endpos[name];
        int xx(min(pa.x,pb.x)),yy(min(pa.z,pb.z)),xx2(max(pa.x,pb.x)),yy2(max(pa.z,pb.z)); //fix
        int fg=0;
        for(auto const& i:lands) {
            if(i.coll(xx,xx2,yy,yy2,b.getEntity()->getDimensionId(),name) && pl==0) {
                fg=1;
                break;
            }
        }
        if(fg) {
            outp.error("[Land system] 领地不得重叠");
            startpos.erase(name);
            endpos.erase(name);
            return;
        }
        land tmp;
        tmp.x=xx,tmp.y=yy,tmp.dx=xx2-xx+1,tmp.dy=yy2-yy+1;
        tmp.addown(name);
        tmp.dim_perm=(b.getEntity()->getDimensionId()<<4)|PERMP;
        unsigned long price=LAND_PRICE*tmp.size();
        if(price>100000000 || price<=0 || xx2-xx+1>16384 || yy2-yy+1>16384 ){
            outp.error("[Land system] 我不给你圈那么大");
            startpos.erase(name);
            endpos.erase(name);
            return;
        }
        if(pl>0 || red_money(name,price)) {
            lands.push_front(tmp);
            ccache();
            save();
            outp.success("§e[Land system] 购买成功");
            startpos.erase(name);
            endpos.erase(name);
        } else {
            outp.error("[Land system] 你的余额不足");
        }
    }
    if(a[0]=="query") {
        auto act=b.getEntity();
        if(act==NULL) return;
        int dim=act->getDimensionId();
        int x=round(b.getWorldPosition().x);
        int y=round(b.getWorldPosition().z); 
        land* i=getLand(x,y,dim);
        if(i && i->canpop(name)) {
            char buf[1000];
            sprintf(buf,"§e[Land system] 这里是 %s 的领地",i->owner.c_str());
            outp.success(string(buf));
            return;
        } else {
            char buf[1000];
            sprintf(buf,"[Land system] 这里没有领地");
            outp.error(string(buf));
        }
    }
    if(a[0]=="sell") {
        int dim=b.getEntity()->getDimensionId();
        int x=round(b.getWorldPosition().x);
        int y=round(b.getWorldPosition().z); //fix
        land* i=getLand(x,y,dim);
        if(i&&(i->checkown(name)||pl>0)) {
            char buf[1000];
            int price=LAND_PRICE2*i->size();
            add_money(name,price);
            sprintf(buf,"§e[Land system] 领地出售成功，出售价格 %d",price);
            outp.success(string(buf));
            i->dim_perm=114514; //remove flag
            lands.remove_if([](const land& n) {
                return n.dim_perm==114514;
            });
            ccache();
            save();
            return;
        } else {
            outp.error("[Land system] 这不是你的领地");
        }
    }
    if(a[0]=="trust") {
        ARGSZ(2)
        int dim=b.getEntity()->getDimensionId();
        int x=round(b.getWorldPosition().x);
        int y=round(b.getWorldPosition().z); //fix
        land* i=getLand(x,y,dim);
        if(i&&(i->checkown(name)||pl>0)) {
            i->addown(a[1]);
            save();
            outp.success("§e[Land system] 已信任玩家 "+a[1]);
            return;
        } else {
            outp.error("[Land system] 这不是你的领地");
        }
    }
    if(a[0]=="trustgui"){
        string name=b.getName();
        gui_ChoosePlayer((ServerPlayer*)b.getEntity(),"§e选择要信任的玩家","Land Req",[name](const string& dest){
            auto xx=getMC()->getLevel()->getPlayer(name);
                if(xx)
                runcmdAs("land trust "+SafeStr(dest),xx);
        });
    }
    if(a[0]=="untrust") {
        ARGSZ(2)
        int dim=b.getEntity()->getDimensionId();
        int x=round(b.getWorldPosition().x);
        int y=round(b.getWorldPosition().z); //fix
        land* i=getLand(x,y,dim);
        if(i&&(i->checkown(name)||pl>0)&&i->checkown(a[1])) {
            i->rmown(a[1]);
            save();
            outp.success("§e[Land system] 已取消对玩家 "+a[1]+" 的信任");
            return;
        } else {
            outp.error("[Land system] 这不是你的领地 or the player doesnt own the land");
        }
    }
    if(a[0]=="perm") {
        ARGSZ(2)
        int dim=b.getEntity()->getDimensionId();
        int x=round(b.getWorldPosition().x);
        int y=round(b.getWorldPosition().z); //fix
        land* i=getLand(x,y,dim);
        if(i&&(i->checkown(name)||pl>0)) {
            i->dim_perm-=(i->dim_perm&15);
            i->dim_perm|=atoi(a[1].c_str());
            save();
            outp.success("§e[Land system] 权限更改 "+a[1]);
        } else {
            outp.error("[Land system] 这不是你的领地");
        }
    }

    if(a[0]=="help") {
        outp.error("领地系统指令列表:\n/land start ——选择起点\n/land end ——选择终点\n/land prebuy 查看价格\n/land exit 退出选点模式\n/land buy ——选点之后买地\n/land trust 玩家ID ——添加访客\n/land trustgui trust的gui\n/land untrust 玩家ID ——删除访客\n/land sell ——卖地\n/land query ——查看当前领地主人\n/land perm 数字 ——指定具体权限(详细看github)");
    }
}

static void save() {
    char* bf;
    int sz=settomem(lands,&bf,land::tostr);
    mem2file("data/land/land.db",bf,sz);
}
static void load() {
    mkdir("data",S_IRWXU);
    mkdir("data/land",S_IRWXU);
    //register_shutdown(fp(save));
    char* buf;
    int sz;
    struct stat tmp;
    if(stat("data/land/land.db",&tmp)==-1) {
        save();
    }
    file2mem("data/land/land.db",&buf,sz);
    memtoset(lands,buf,land::fromstr);
}

static int handle_dest(GameMode* a0,BlockPos const* a1) {
    int pl=a0->getPlayer()->getPlayerPermissionLevel();
    if(pl>1) {
        return 1;
    }
    const string& name=a0->getPlayer()->getName();
    int dim=a0->getPlayer()->getDimensionId();
    int x(a1->x),y(a1->z),z(a1->z); //fixed
    land* i=getLand(x,y,dim);
    if(i&&!i->checkown(name)) {
        if(!i->canbuild(name)) {
            char buf[1000];
            sprintf(buf,"§c你不能破坏 %s 的领地",i->owner.c_str());
            sendText2(a0->getPlayer(),string(buf));
            return 0;
        } else {
            return 1;
        }
    }
    return 1;
}
static bool handle_attack(Mob& vi,ActorDamageSource const& src,int& val){
    int x,y;
    if(src.isChildEntitySource() || src.isEntitySource()){
        auto id=src.getEntityUniqueID();
        auto ent=getMC()->getLevel()->fetchEntity(id,false);
        if(!ent){
            printf("[Land] wtf!!! broken euid %ld\n",id.id);
            return 1;
        }
        if(ent->getEntityTypeId()!=1) return 1; //not a player
        auto& pos=vi.getPos();
        x=pos.x,y=pos.z;
        land* i=getLand(x,y,vi.getDimensionId());
        ServerPlayer* sp=(ServerPlayer*)ent;
        if(sp->getPlayerPermissionLevel()>1) return 1;
        string name=sp->getName();
        if(i && !i->checkown(name)) {
            if(!i->canatk(name)) {
                char buf[1000];
                sprintf(buf,"§c你不可以在 %s 的领地内攻击",i->owner.c_str());
                sendText2(sp,string(buf));
                return 0;
            } else {
                return 1;
            }
        }
    } return 1;
}
static bool handle_useion(GameMode* a0,ItemStack * a1,BlockPos const* a2,BlockPos const* dstPos,Block const* a5) {
    if(choose_state[a0->getPlayer()->getName()]!=0){
        if(choose_state[a0->getPlayer()->getName()]==1){
            startpos[a0->getPlayer()->getName()]={a2->x,a2->y,a2->z};
            sendText(a0->getPlayer(),"已选择点 A /land exit 退出选点模式");
        }
        if(choose_state[a0->getPlayer()->getName()]==2){
            endpos[a0->getPlayer()->getName()]={a2->x,a2->y,a2->z};
            sendText(a0->getPlayer(),"已选择点 B /land prebuy 查看价格 /land buy 买地 /land exit 退出选点模式");
        }
        return 0;
    }
    int pl=a0->getPlayer()->getPlayerPermissionLevel();
    if(pl>1) {
        return 1;
    }
    const string& name=a0->getPlayer()->getName();
    int dim=a0->getPlayer()->getDimensionId();
    int x(dstPos->x),y(dstPos->z);  //FIX:check both blockpos
    land* i=getLand(x,y,dim);
    int prevent=0;
    if(i&&!i->checkown(name)) {
        if(!i->canuse(name)) {
            char buf[1000];
            sprintf(buf,"§c你不能在 %s 的领地与方块交互",i->owner.c_str());
            sendText2(a0->getPlayer(),string(buf));
            prevent|=1;
        } else {
             prevent|=!a1->isNull();
        }
    }
    x=a2->x;y=a2->z;
    i=getLand(x,y,dim);
    if(i&&!i->checkown(name)) {
        if(!i->canuse(name)) {
            char buf[1000];
            sprintf(buf,"§c你不能在 %s 的领地与方块交互",i->owner.c_str());
            sendText2(a0->getPlayer(),string(buf));
            prevent|=1;
        } else {
             prevent|=!a1->isNull();
        }
    }
    return !prevent;
}
static bool handle_popitem(ServerPlayer& sp,BlockPos& bpos){
    int x(bpos.x),y(bpos.z);
    land* i=getLand(x,y,sp.getDimensionId());
    auto nm=sp.getName();
    if(i&&!i->checkown(nm)&&!i->canuse(nm)) {
        char buf[1000];
        sprintf(buf,"§c你不能在 %s 的领地与方块交互",i->owner.c_str());
        sendText2(&sp,string(buf));
        return 0;
    }
    return 1;
}
void land_init(std::list<string>& modlist) {
    printf("[LAND] loaded! V2019-11-21\n");
    load();
    loadcfg();
    MyHook(fp(dlsym(NULL,"_ZNK9FarmBlock15transformOnFallER11BlockSourceRK8BlockPosP5Actorf")),fp(dummy));
    register_cmd("land",(void*)oncmd,"领地系统");
    register_cmd("reload_land",fp(loadcfg),"reload land cfg",1);
    reg_destroy(handle_dest);
    reg_useitemon(handle_useion);
    reg_mobhurt(handle_attack);
    reg_popItem(handle_popitem);
    load_helper(modlist);
}
