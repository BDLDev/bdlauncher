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
void(*deuniqct)(u64);
void(*deweak)(u64);
class ISlots {
public:
    char filler[136*10];
    ISlots(Player* x) {
        for(int i=0; i<9; ++i) {
            new (filler+i*136) ItemStack();
        }
	new (filler+9*136) ItemStack(x->getOffhandSlot());
    }
    ~ISlots() {
        for(int i=0; i<10; ++i) {
        	deuniqct((u64)(filler+i*136+8));
        	deweak((u64)(filler+i*136));
        }
    }
    bool onChg(int id,ItemStack* from,ItemStack* to) {
        if(id>9 || id<0) return false;
        int fg=1;
        if(!from->isNull() && *from!=*((ItemStack*)(filler+id*136))) fg=0;
        deuniqct((u64)(filler+id*136+8));
        deweak((u64)(filler+id*136));
        new (filler+id*136) ItemStack(*to);
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

static int(*ori)(Block *, BlockSource *, const BlockPos *);
static int hk(Block * a0, BlockSource * a1, const BlockPos *a2) {
    if(a0->isContainerBlock()) {
        char buf[6666];
        sprintf(buf,"fill %d %d %d %d %d %d air",a2->x,a2->y,a2->z,a2->x,a2->y,a2->z);
        runcmd(string(buf));
        sprintf(buf,"kill @e[type=item,x=%d,y=%d,z=%d,r=5]",a2->x,a2->y,a2->z);
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
static void initlog() {
    logfd=open("player.log",O_WRONLY|O_APPEND|O_CREAT,S_IRWXU);
    logsz=lseek(logfd,0,SEEK_END);
}
static void async_log(const char* fmt,...) {
    char buf[10240];
    auto x=time(0);
    va_list vl;
    va_start(vl,fmt);
    auto tim=strftime(buf,128,"[%Y-%m-%d %H:%M:%S] ",localtime(&x));
    int s=vsprintf(buf+tim,fmt,vl)+tim;
    write(1,buf,s);
    write(logfd,buf,s);
    va_end(vl);
}

static u64 handleLogin(u64 t,NetworkIdentifier& a, Certificate& b) {
    string pn=ExtendedCertificate::getIdentityName(b);
    async_log("[JOIN]%s joined game\n",pn.c_str());
    if(isBanned(pn)) {
        string ban("§c你在当前服务器的黑名单内!");
        getMC()->getNetEventCallback()->disconnectClient(a,ban,false);
        return 0;
    }
    return hori(t,a,b);
}

static int(*iori)(const InventoryTransactionManager*,InventoryAction const&);
int hki(InventoryTransactionManager const* thi,InventoryAction const& b) {
    //printf("player %s sid %d src %s from %s to %s\n",thi->getPlayer()->getName().c_str(),b.getSid(),b.getSource().toStr().c_str(),b.getFromItem()->toString().c_str(),b.getToItem()->toString().c_str());
    auto& x=b.getSource();
    auto id1=x.getType();
    auto id2=x.getFlags();
    auto id3=x.getContainerId();
    const string& name=thi->getPlayer()->getName();
    if((id1==0 /*&& id2==0*/ && id3==119) && b.getToItem()->getId()!=0){
        if(!b.getToItem()->isOffhandItem()){
            async_log("检测到作弊玩家： %s offhand %s\n",thi->getPlayer()->getName().c_str(),b.getToItem()->toString().c_str());
            runcmd(string("say §c检测到玩家 "+name+" 疑似使用外挂刷物品"));
            runcmd(string("ban \"")+name+"\" 120");
            return iori(thi,b);
        }
    }
    if((id1==100 && id2==0 && id3!=23) || (id1==0 && id3==119)) {
        if(!PSlot.count(name)) PSlot[name]=new ISlots(thi->getPlayer());
        ISlots* is=PSlot[name];
        if(!is->onChg(id3==119?9:b.getSid(),b.getFromItem(),b.getToItem())) {
            async_log("检测到作弊玩家： %s sid %d src %s from %s to %s\n",thi->getPlayer()->getName().c_str(),b.getSid(),b.getSource().toStr().c_str(),b.getFromItem()->toString().c_str(),b.getToItem()->toString().c_str());
            runcmd(string("say §c检测到玩家 "+name+" 疑似使用外挂刷物品 "+b.getFromItem()->toString()+"请管理员手动检察该玩家的行为"));
            runcmd(string("ban \"")+name+"\" 25");
        }
    }
    return iori(thi,b);
}
static int (*cori)(void*,Player const&,string&);
static int hkc(void* a,Player & b,string& c) {
    int ret=cori(a,b,c);
    async_log("*[CHAT]%s:%s\n",b.getName().c_str(),c.c_str());
    return ret;
}

#include <sys/socket.h>
#include <arpa/inet.h>
ssize_t (*rori)(int socket, void * buffer, size_t length,
                int flags, struct sockaddr * address,
                socklen_t * address_len);
extern "C" ssize_t recvfrom_hook(int socket, void * buffer, size_t length,
                                 int flags, struct sockaddr * address,
                                 socklen_t * address_len) {
    int rt=rori(socket,buffer,length,flags,address,address_len);
    if(rt && ((char*)buffer)[0]==0x5) {
        char buf[1024];
        inet_ntop(AF_INET,&(((sockaddr_in*)address)->sin_addr),buf,*address_len);
        async_log("%s send conn\n",buf);
    }
    return rt;
}
static void do_patch() {
    ori=(typeof(ori))MyHook(fp(dlsym(NULL,"_ZNK5Block13movedByPistonER11BlockSourceRK8BlockPos")),fp(hk));
    hori=(typeof(hori))MyHook(fp(dlsym(NULL,"_ZN20ServerNetworkHandler22_onClientAuthenticatedERK17NetworkIdentifierRK11Certificate")),fp(handleLogin));
    iori=(typeof(iori))MyHook(fp(dlsym(NULL,"_ZN27InventoryTransactionManager17addExpectedActionERK15InventoryAction")),fp(hki));
    cori=(typeof(cori))MyHook(fp(dlsym(NULL,"_ZN20ServerNetworkHandler19_displayGameMessageERK6PlayerRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE")),fp(hkc));
}
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
    auto x=getplayer_byname(b.getName());
    if((int)b.getPermissionsLevel()>0) {
        banlist[a[0]]=a.size()==1?0:(time(0)+atoi(a[1].c_str()));
        runcmd(string("kick \"")+a[0]+"\" §c你号没了");
        save();
        outp.success("§e玩家已封禁: "+a[0]);
    }
}
static void oncmd2(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
    auto x=getplayer_byname(b.getName());
    if((int)b.getPermissionsLevel()>0) {
        banlist.erase(a[0]);
        save();
        outp.success("§e玩家已解封: "+a[0]);
    }
}
static int handle_u(GameMode* a0,ItemStack * a1,BlockPos const& a2,unsigned char a3,Vec3 const& a4,Block const* a5) {
    if(a0->getPlayer()->getPlayerPermissionLevel()>1) return 1;
    string sn=a0->getPlayer()->getName();
    char buf[1024];
    strcpy(buf,a1->toString().c_str());
    for(int i=0; buf[i]; ++i)
        buf[i]=tolower(buf[i]);
#define check(a) strstr(buf,a)!=NULL
    //mob_spawner与spawn_egg因无法检测而修改为spawn
    if(check("barrier") || check("bedrock") || check("spawn")) {
        async_log("[ITEM]%s 使用高危物品(banned) %s pos: %d %d %d\n",sn.c_str(),buf,a2.x,a2.y,a2.z);
        sendText2(a0->getPlayer(),"§c无法使用违禁物品");
        return 0;
    }
    if(check("tnt") || check("lava")) {
        async_log("[ITEM]%s 使用危险物品(warn) %s pos: %d %d %d\n",sn.c_str(),buf,a2.x,a2.y,a2.z);
        return 1;
    }
    return 1;
}
static clock_t lastcl;
static string lastn;
static int handle_dest(GameMode* a0,BlockPos const& a1,unsigned char a2) {
    int pl=a0->getPlayer()->getPlayerPermissionLevel();
    if(pl>1 || a0->getPlayer()->isCreative()) {
        //op
        //printf("op\n");
        return 1;
    }
    const string& name=a0->getPlayer()->getName();
    int x(a1.x),y(a1.y),z(a1.z); //fixed
    Block& bk=a0->getPlayer()->getBlockSource()->getBlock(a1);
    int id=bk.getLegacyBlock()->getBlockItemId();
    if(name==lastn && clock()-lastcl<1000000*0.08) {
        lastcl=clock();
        // async_log("%d [FD]%s fast dest %d delta %f\n",time(0),name.c_str(),id,((float)(clock()-lastcl))/1000000);
        return 0;
    }
    lastn=name;
    lastcl=clock();
    const Vec3& fk=a0->getPlayer()->getPos();
#define abs(x) ((x)<0?-(x):(x))
    int dx=fk.x-x;
    int dy=fk.y-y;
    int dz=fk.z-z;
    int d2=dx*dx+dy*dy+dz*dz;
    if(d2>36) {
        //    async_log("%d [FD]%s far dest %d\n",time(0),name.c_str(),d2);
        return 0;
    }
    return 1;
}
struct Mc3 {
    float y;
    int airt;
};
static unordered_map<string,Mc3> mp;
static inline bool isinAir(Player& tg,Vec3& fk) {
    int x=(fk.x);
    int y=(fk.y);
    int z=(fk.z);
    if(y<=5) return 0;
    auto& bs=tg.getBlockSource();
    int fg=1;
    for(int i=1; i<=3; ++i) {
        if(bs->getBlock({x,y-i,z}).getLegacyBlock()->getBlockItemId()!=0) {
            fg=0;
            break;
        }
    }
    return fg;
}
static void flych(Level* lv) {
    lv->forEachPlayer([&](Player& tg)->bool{
        const string& nm=tg.getName();
        auto x=tg.getPos();
        if(mp.count(nm)==0) {
            mp[nm]= {x.y,0};
            return true;
        }
        auto& y=mp[nm];
        int isfl=0;
        if(!tg.isRiding() && !tg.isGliding() && !tg.isCreative() && isinAir(tg,x)) { //(!tg.isRiding() && !tg.isGliding() && !tg.isCreative() &&)
            if(x.y-y.y>=0) {
                //is not falling
                isfl=1;
            }
        }
        if(isfl) {
            y.airt++;
            if(y.airt>=3) {
                async_log("[FLY]%s is flying!\n",tg.getName().c_str());
                //runcmd("kick \""+tg.getName()+"\" anti-flying");
                 runcmd("kill \""+tg.getName()+"\"");
                y.airt=0;
            }
        } else {
            y.airt=0;
        }
        y.y=x.y;
        return true;
    });
}
static int(*tick_o)(Level*);

static int tkl;
static int onTick(Level* a) {
    int rt=tick_o(a);
    tkl++;
    if(tkl%(1*20)==0) //1s
        flych(a);
    return rt;
}
struct EnchantmentInstance {
  int getEnchantType() const;
  void setEnchantLevel(int);
};

struct Enchant {
  enum Type : int {};
  static std::vector<std::unique_ptr<Enchant>> mEnchants;
  virtual ~Enchant();
  virtual bool isCompatibleWith(Enchant::Type type);
  virtual int getMinCost(int);
  virtual int getMaxCost(int);
  virtual int getMinLevel();
  virtual int getMaxLevel();
};
static int(*enc_o)(EnchantmentInstance*);
static int limitLevel(int input, int max) {
  if (input < 0)
    return 0;
  else if (input > max)
    return 0;
  return input;
}
static int getEntlvl(EnchantmentInstance* a){
  auto level=enc_o(a);
  auto &enchant = Enchant::mEnchants[a->getEnchantType()];
  auto max      = enchant->getMaxLevel();
  auto result   = limitLevel(level, max);
  if (result != level) a->setEnchantLevel(level);
  return result;
} 
static char(*wtf_o)(char*,char);
char wtf(char* x,char a){
    return wtf_o(x,1);
}
static int handle_left(ServerNetworkHandler* a0,ServerPlayer* a1,bool a2){
	async_log("[LEFT] %s left game\n",a1->getName().c_str());
	PSlot.erase(a1->getName());
	return 1;
}
void bear_init(std::list<string>& modlist) {
    deuniqct=(typeof(deuniqct))dlsym(NULL,"_ZNSt10unique_ptrI11CompoundTagSt14default_deleteIS0_EED2Ev");
    deweak=(typeof(deweak))dlsym(NULL,"_ZN7WeakPtrI4ItemED2Ev");
    do_patch();
    load();
    initlog();
    register_cmd("ban",fp(oncmd),"封禁玩家");
    register_cmd("unban",fp(oncmd2),"解除封禁");
    reg_useitemon(fp(handle_u));
    reg_destroy(fp(handle_dest));
    reg_player_left(fp(handle_left));
    rori=(typeof(rori))(MyHook(fp(recvfrom),fp(recvfrom_hook)));
    //tick_o=(typeof(tick_o))MyHook(dlsym(NULL,"_ZN5Level4tickEv"),fp(onTick));
    enc_o=(typeof(enc_o))MyHook(dlsym(NULL,"_ZNK19EnchantmentInstance15getEnchantLevelEv"),fp(getEntlvl));
    wtf_o=(typeof(wtf_o))MyHook(dlsym(NULL,"_ZN8GameRule17setAllowInCommandEb"),fp(wtf));
    printf("[ANTI-BEAR] Loaded %p\n",(void*)tick_o);
    load_helper(modlist);
}

