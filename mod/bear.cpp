/*_ZNK5Block13movedByPistonER11BlockSourceRK8BlockPos
movedByPiston(Block *this, BlockSource *a2, const BlockPos *a3)
_ZNK9Blacklist9isBlockedERKNS_5EntryE
Blacklist::isBlocked(Blacklist *this, const Blacklist::Entry *a2)
filler [84+32]
mce::UUID //16
string name?//32
string emp?//32
int dur; //4
*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include"aux.h"
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
#include"minecraft/item/ItemStack.h"
#include"minecraft/block/BlockSource.h"
#include"minecraft/block/Block.h"
#include"minecraft/net/Connection.h"
#include"minecraft/net/NetworkIdentifier.h"
#include"seral.hpp"
#include<unistd.h>
#include<cstdarg>

#include"base.h"
#include<cmath>
#include<deque>
#include<dlfcn.h>
#include<string>
#include<aio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using std::string;
using std::unordered_map;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define dbg_printf(...) {}
//#define dbg_printf printf
extern "C" {
    void bear_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
static std::unordered_map<string,int> des_tim;
class ISlots {
public:
    ItemStack* v[9];
    //string v[9];
    ISlots() {
        for(int i=0; i<9; ++i) {
//			v[i]="0 x (0)@0";
            v[i]=new ItemStack();
        }
    }
    ~ISlots() {
        for(int i=0; i<9; ++i) {
//			delete (v[i]);
        }
    }
    bool onChg(int id,ItemStack* from,ItemStack* to) {
        if(id>8 || id<0) return false;
        int fg=1;
        if(*from!=*v[id]) fg=0;
//delete(v[id]);
        v[id]=new ItemStack(*to);
        return fg;
    }
};
static std::unordered_map<string,ISlots*> PSlot;
struct InventorySource;
struct InventoryAction {
    char filler[288];
    InventorySource& getSource(void) const;
    ItemStack* getToItem(void) const;
    ItemStack* getFromItem(void) const;
    unsigned int getSid() const {
        return *(unsigned int*)((char*)this+12);
    };
};
struct InventoryTransactionManager {
    char filler[40];
    Player* getPlayer() const {
        return *(Player**)this;
    }
//InventoryTransactionManager::addExpectedAction(InventoryAction const&) _ZN27InventoryTransactionManager17addExpectedActionERK15InventoryAction
};
struct InventorySource {
    char filler[12];
    int getType() const;
    int getFlags() const;
    int getContainerId() const;
    string toStr() const {
        return std::to_string(getType())+":"+std::to_string(getFlags())+":"+std::to_string(getContainerId());
    }
};
static int handle_dest2(GameMode* a0,BlockPos const& a1,unsigned char a2) {
    int pl=a0->getPlayer()->getPlayerPermissionLevel();
    if(pl>1) {
        return 1;
    }
    float sp=a0->getPlayer()->getCarriedItem().getDestroySpeed(a0->getPlayer()->getBlockSource()->getBlock(a1));
    printf("sp %f\n",sp);
    return 1;
}
static int(*ori)(Block *, BlockSource *, const BlockPos *);
static int hk(Block * a0, BlockSource * a1, const BlockPos *a2) {
    if(a0->isContainerBlock()) {
        char buf[6666];
        sprintf(buf,"fill %d %d %d %d %d %d air",a2->x,a2->y,a2->z,a2->x,a2->y,a2->z);
        runcmd(string(buf));
    }
    return ori(a0,a1,a2);
}
static unordered_map<string,int> banlist;
static void save() {
    char* bf;
    int sz=maptomem(banlist,&bf,h_str2str,h_int2str);
    mem2file("ban.db",bf,sz);
}
static void load() {
    char* buf;
    int sz;
    struct stat tmp;
    if(stat("ban.db",&tmp)==-1) {
        save();
    }
    file2mem("ban.db",&buf,sz);
    memtomap(banlist,buf,h_str2str_load,h_str2int);
}
bool isBanned(const string& name) {
    if(banlist.count(name)) {
        int tm=banlist[name];
        if(tm==0) return 1;
        if(time(0)>tm) {
            banlist.erase(name);
            save();
            return 0;
        }
        return 1;
    }
    return 0;
}
static u64(*hori)(u64 t,NetworkIdentifier& a, Certificate& b);
static int logfd;
static int logsz;
static void initlog(){
    logfd=open("player.log",O_WRONLY|O_APPEND|O_CREAT,S_IRWXU);
    logsz=lseek(logfd,0,SEEK_END);
}
static void async_log(const char* fmt,...){
    char buf[65535];
    /*struct aiocb ac;
    memset(&ac,0,sizeof(ac));
    ac.aio_fildes=logfd;
    ac.aio_buf=buf;*/
    va_list vl;
    va_start(vl,fmt);/*
    ac.aio_nbytes=vsprintf(buf,fmt,vl);
    va_end(vl);
    ac.aio_offset=logsz;
    logsz+=ac.aio_nbytes;*/
	int s=vsprintf(buf,fmt,vl);
    write(1,buf,s);
write(logfd,buf,s);
va_end(vl);
    //aio_write(&ac);
}

static u64 handleLogin(u64 t,NetworkIdentifier& a, Certificate& b) {
    string pn=ExtendedCertificate::getIdentityName(b);
    async_log("%d [JOIN]%s joined game\n",time(0),pn.c_str());
    if(isBanned(pn)) {
        string ban("你在黑名单内!");
        getMC()->getNetEventCallback()->disconnectClient(a,ban,false);
        return 0;
    }
    return hori(t,a,b);
}

static int(*iori)(const InventoryTransactionManager*,InventoryAction const&);
int hki(InventoryTransactionManager const* thi,InventoryAction const& b) {
    //printf("player %s sid %d src %s from %s to %s\n",thi->getPlayer()->getName().c_str(),b.getSid(),b.getSource().toStr().c_str(),b.getFromItem().toString().c_str(),b.getToItem().toString().c_str());
    auto& x=b.getSource();
    if(x.getType()==100 && x.getFlags()==0 && (x.getContainerId()==-100 || x.getContainerId()==-2)) {
        string name=thi->getPlayer()->getName();
        //printf("early\n");
        if(!PSlot.count(name)) PSlot[name]=new ISlots();
        ISlots* is=PSlot[name];
        // printf("check\n");
        if(!is->onChg(b.getSid(),b.getFromItem(),b.getToItem())) {
            async_log("%d player %s sid %d src %s from %s to %s\n",time(0),thi->getPlayer()->getName().c_str(),b.getSid(),b.getSource().toStr().c_str(),b.getFromItem()->toString().c_str(),b.getToItem()->toString().c_str());
            async_log("%d 检测到toolbox玩家： %s\n",time(0),name.c_str());
            //sendText(thi->getPlayer(),"toolbox detected");
            //return 0;
        }
        //printf("done\n");
    }
    return iori(thi,b);
}
static int (*cori)(void*,Player const&,string&);
static int hkc(void* a,Player & b,string& c){
    int ret=cori(a,b,c);
    async_log("%d *[CHAT]%s:%s",time(0),b.getName().c_str(),c.c_str());
    return ret;
}
/*
#include <sys/socket.h>
#include <arpa/inet.h>
ssize_t (*rori)(int socket, void * buffer, size_t length,
           int flags, struct sockaddr * address,
           socklen_t * address_len);
extern "C" ssize_t recvfrom(int socket, void * buffer, size_t length,
           int flags, struct sockaddr * address,
           socklen_t * address_len){
               printf("hook\n");
               int rt=rori(socket,buffer,length,flags,address,address_len);
               if(rt && ((char*)buffer)[0]==0x5){
                   char buf[1024];
                   inet_ntop(AF_INET,&(((sockaddr_in*)address)->sin_addr),buf,*address_len);
                   async_log("%d %s send conn\n",time(0),buf);
               }
               return rt;
           }
extern "C" char* GetELFAddr();
*/
static void do_patch() {
    ori=(typeof(ori))MyHook(fp(dlsym(NULL,"_ZNK5Block13movedByPistonER11BlockSourceRK8BlockPos")),fp(hk));
    hori=(typeof(hori))MyHook(fp(dlsym(NULL,"_ZN20ServerNetworkHandler22_onClientAuthenticatedERK17NetworkIdentifierRK11Certificate")),fp(handleLogin));
    iori=(typeof(iori))MyHook(fp(dlsym(NULL,"_ZN27InventoryTransactionManager17addExpectedActionERK15InventoryAction")),fp(hki));
    cori=(typeof(cori))MyHook(fp(dlsym(NULL,"_ZN20ServerNetworkHandler19_displayGameMessageERK6PlayerRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE")),fp(hkc));
}
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    if((int)b.getPermissionsLevel()>0) {
        Player* pp=getplayer_byname(a[0]);
        if(pp){
            ((ServerPlayer*)pp)->disconnect();
        }
        banlist[a[0]]=a.size()==1?0:(time(0)+atoi(a[1].c_str()));
        save();
        outp.success("banned "+a[0]);
    }
}
static void oncmd2(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    if((int)b.getPermissionsLevel()>0) {
        banlist.erase(a[0]);
        save();
        outp.success("okay");
    }
}
static int handle_u(GameMode* a0,ItemStack * a1,BlockPos const& a2,unsigned char a3,Vec3 const& a4,Block const* a5){
    if(a0->getPlayer()->getPlayerPermissionLevel()>1) return 1;
    string sn=a0->getPlayer()->getName();
    char buf[1024];
    strcpy(buf,a1->toString().c_str());
    for(int i=0;buf[i];++i)
    buf[i]=tolower(buf[i]);
    #define check(a) strstr(buf,a)!=NULL
    if(check("spawn_egg") || check("barrier") || check("bedrock") || check("command_block") || check("mob_spawner") ){
        async_log("%d [ITEM]%s 使用高危物品(banned) %s pos: %d %d %d\n",time(0),sn.c_str(),buf,a2.x,a2.y,a2.z);
        return 0;
    }
    if(check("tnt") || check("lava")){
        async_log("%d [ITEM]%s 使用危险物品(warn) %s pos: %d %d %d\n",time(0),sn.c_str(),buf,a2.x,a2.y,a2.z);
        return 1;
    }
    return 1;
}
void bear_init(std::list<string>& modlist) {
    //0x0000555559d377a0 _ZNK27ComplexInventoryTransaction6handleER6Playerb +681 e8 d2 bc 00 00	callq  0x555559d43720 <_ZN27InventoryTransactionManager17addExpectedActionERK15InventoryAction>
//0x0000555559d43760 _ZN27InventoryTransactionManager9addActionERK15InventoryAction
//patch _ZNK27ComplexInventoryTransaction6handleER6Playerb+682 0x0000bcd2+0x40
    do_patch();
    load();
    initlog();
    register_cmd("ban",fp(oncmd),"ban");
    register_cmd("unban",fp(oncmd2),"unban");
    reg_useitemon(fp(handle_u));
    printf("[ANTI-BEAR] Loaded\n");
    //reg_destroy(fp(handle_dest2));
    load_helper(modlist);
}

