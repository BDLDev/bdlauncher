
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include"util.h"
#include<cstdio>
#include<list>
#include<forward_list>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include"../cmdhelper.h"
#include<vector>
#include<Loader.h>
#include<MC.h>
#include<unistd.h>
#include<cstdarg>
#include"../base/base.h"
#include"../gui/gui.h"

#include<cmath>
#include<deque>
#include<dlfcn.h>
#include<string>
#include<aio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include"lang.h"
using std::string;
using std::unordered_map;
using std::unordered_set;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define dbg_printf(...) {}
//#define dbg_printf printf
extern "C" {
    BDL_EXPORT void mod_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
LDBImpl ban_data("data_v2/bear");
bool isBanned(const string& name) {
    string val;
    auto succ=ban_data.Get(name,val);
    if(succ){
        int& tim=*((int*)val.data());
        if(tim!=0 && time(0)>tim){
            ban_data.Del(name);
            return 0;
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}
int MAX_CHAT_SIZE;
static_deque<string,128> banword;
static int logfd;
static int logsz;
static void initlog() {
    logfd=open("player.log",O_WRONLY|O_APPEND|O_CREAT,S_IRWXU);
    logsz=lseek(logfd,0,SEEK_END);
}
static void async_log(const char* fmt,...) {
    char buf[1024];
    auto x=time(0);
    va_list vl;
    va_start(vl,fmt);
    auto tim=strftime(buf,128,"[%Y-%m-%d %H:%M:%S] ",localtime(&x));
    int s=vsnprintf(buf+tim,1024,fmt,vl)+tim;
    write(1,buf,s);
    write(logfd,buf,s);
    va_end(vl);
}


#include <sys/socket.h>
#include <arpa/inet.h>
ssize_t (*rori)(int socket, void * buffer, size_t length,
                int flags, struct sockaddr * address,
                socklen_t * address_len);
static ssize_t recvfrom_hook(int socket, void * buffer, size_t length,
                                 int flags, struct sockaddr * address,
                                 socklen_t * address_len) {
    int rt=rori(socket,buffer,length,flags,address,address_len);
    if(rt && ((char*)buffer)[0]==0x5) {
        char buf[1024];
        inet_ntop(AF_INET,&(((sockaddr_in*)address)->sin_addr),buf,*address_len);
        async_log("[NETWORK] %s send conn\n",buf);
    }
    return rt;
}
THook(void*,_ZN20ServerNetworkHandler22_onClientAuthenticatedERK17NetworkIdentifierRK11Certificate,ServerNetworkHandler* snh,NetworkIdentifier& a, Certificate& b){
    string pn=ExtendedCertificate::getIdentityName(b);
    string xuid=ExtendedCertificate::getXuid(b);
    async_log("[JOIN]%s joined game with xuid <%s>\n",pn.c_str(),xuid.c_str());
    string val;
    auto succ=ban_data.Get(xuid,val);
    if(!succ){
        ban_data.Put(xuid,pn);
    }
    //printf("%p\n",getMC());
    //printf("%p\n",getMC()->getNetworkHandler());
    //printf("%p %p\n",snh,getMC()->getNetEventCallback());
    if(isBanned(pn) || (succ && isBanned(val))) {
        snh->disconnectClient(a,YOU_R_BANNED,false);
        return nullptr;
    }
    return original(snh,a,b);
}
unordered_map<string,time_t> mute_time;
static bool hkc(ServerPlayer * b,string& c) {
    if(c.size()>MAX_CHAT_SIZE) 
    {
        sendText(b,"too long chat");
        return 0;
    }
    for(auto& i:banword){
        if(c.find(i)!=string::npos) {
            SPBuf<512> sb;
            sb.write("Banned word: ");
            sb.write(i);
            sendText(b,sb.get());
            return 0;
        }
    }
    auto it=mute_time.find(b->getName());
    if(it!=mute_time.end()){
        if(it->second!=0 && time(0)>it->second){
            mute_time.erase(it);
        }else{
            sendText(b,"You're muted!");
            return 0;
        }
    }
    async_log("[CHAT]%s: %s\n",b->getName().c_str(),c.c_str());
    return 1;
}
static void oncmd_mute(argVec& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(2)
    int to=atoi(a[1]);
    if(to==-1)
        mute_time[string(a[0])]=0; //always
    else
        mute_time[string(a[0])]=time(0)+to;
}
static void oncmd(argVec& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
    if((int)b.getPermissionsLevel()>0) {
        auto tim=a.size()==1?0:(time(0)+atoi(a[1]));
        ban_data.Put(a[0],string((char*)&tim,4));
        auto x=getuser_byname(string(a[0]));
        if(x){
            ban_data.Put(x->getXUID(),x->getName());
        }
        runcmd(string("skick \"")+string(a[0])+"\" §cYou are banned");
        outp.success("§b"+string(a[0])+" has been banned");
    }
}
static void oncmd2(argVec& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
    if((int)b.getPermissionsLevel()>0) {
        ban_data.Del(a[0]);
        outp.success("§b"+string(a[0])+" has been unbanned");
    }
}
//add custom
using std::unordered_set;
//static unordered_set<short> banitems,warnitems;
static static_deque<short,64> banitems,warnitems;
static bool dbg_player;
static int LOG_CHEST;
THook(void*,_ZN15ChestBlockActor9startOpenER6Player,BlockActor& ac,Player& pl){
    if(LOG_CHEST){
        auto& pos=ac.getPosition();
        async_log("[CHEST] %s open chest pos: %d %d %d\n",pl.getName().c_str(),pos.x,pos.y,pos.z);
    }
    return original(ac,pl);
}
static bool handle_u(GameMode* a0,ItemStack * a1,BlockPos const* a2,BlockPos const* dstPos,Block const* a5) {
    if(dbg_player){
        sendText(a0->getPlayer(),"you use id "+std::to_string(a1->getId()));
    }
    /*if(LOG_CHEST && a5->getLegacyBlock()->getBlockItemId()==54){
        async_log("[CHEST] %s open chest pos: %d %d %d\n",a0->getPlayer()->getName().c_str(),a2->x,a2->y,a2->z);
    }*/
    //printf("dbg use %s\n",a0->getPlayer()->getCarriedItem().toString().c_str());
    if(a0->getPlayer()->getPlayerPermissionLevel()>1) return 1;
    auto& sn=a0->getPlayer()->getName();
    if(banitems.has(a1->getId())){
        async_log("[ITEM] %s tries to use prohibited items(banned) %s pos: %d %d %d\n",sn.c_str(),a1->toString().c_str(),a2->x,a2->y,a2->z);
        sendText(a0->getPlayer(),"§cUnable to use prohibited items",JUKEBOX_POPUP);
        return 0;
    }
    if(warnitems.has(a1->getId())){
        async_log("[ITEM] %s tries to use dangerous items(warn) %s pos: %d %d %d\n",sn.c_str(),a1->toString().c_str(),a2->x,a2->y,a2->z);
        return 1;
    }
    return 1;
}
static void handle_left(ServerPlayer* a1){
	async_log("[LEFT] %s left game\n",a1->getName().c_str());
}
#include"rapidjson/document.h"

static int FPushBlock,FExpOrb,FDest;
enum CheatType{
    FLY,NOCLIP,INV,MOVE
};
static void notifyCheat(const string& name,CheatType x){
    const char* CName[]={"FLY","NOCLIP","Creative","Teleport"};
    async_log("[%s] detected for %s\n",CName[x],name.c_str());
    string kick=string("skick \"")+name+"\" §cYou are banned";
    switch(x){
        case FLY:
            runcmd(kick);
        break;
        case NOCLIP:
            runcmd(kick);
        break;
        case INV:
            runcmd(kick);
        break;
        case MOVE:
            runcmd(kick);
        break;
    }
}

THook(void*,_ZN5BlockC2EtR7WeakPtrI11BlockLegacyE,Block* a,unsigned short x,void* c){
	auto ret=original(a,x,c);
    if(FPushBlock){
	    auto* leg=a->getLegacyBlock();
	    if(a->isContainerBlock()) leg->addBlockProperty({0x1000000LL});
    }
    return ret;
}

static unordered_map<STRING_HASH,clock_t> lastchat;
static int FChatLimit;
static ServerPlayer* lastchat_fast;
static clock_t lastchat_fast_c;
static bool ChatLimit(ServerPlayer* p){
    if(!FChatLimit || p->getPlayerPermissionLevel()>1) return true;
    if(lastchat_fast==p){
        auto delta=clock()-lastchat_fast_c;
        if(delta<=CLOCKS_PER_SEC/10) return false;
    }
    lastchat_fast=p;
    lastchat_fast_c=clock();
    auto hash=do_hash(p->getName());
    auto last=lastchat.find(hash);
    if(last!=lastchat.end()){
    auto old=last->second;
    auto now=clock();
    last->second=now;
    if(now-old<CLOCKS_PER_SEC/10) return false;
    return true;
    }else{
        lastchat.insert({hash,clock()});
        return true;
    }
}

THook(void*,_ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK10TextPacket,ServerNetworkHandler* sh,NetworkIdentifier const& iden,Packet* pk){
    ServerPlayer* p=sh->_getServerPlayer(iden,pk->getClientSubId());
    if(p){
        if(ChatLimit(p))
        return original(sh,iden,pk);
    }
    return nullptr;
}
THook(void*,_ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK20CommandRequestPacket,ServerNetworkHandler* sh,NetworkIdentifier const& iden,Packet* pk){
    ServerPlayer* p=sh->_getServerPlayer(iden,pk->getClientSubId());
    if(p){
        if(ChatLimit(p))
        return original(sh,iden,pk);
    }
    return nullptr;
}


THook(void*,_ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK24SpawnExperienceOrbPacket,ServerNetworkHandler* sh,NetworkIdentifier const& iden,Packet* pk){
    if(FExpOrb){
	    return nullptr;
    }
    return original(sh,iden,pk);
}

THook(void*,_ZNK15StartGamePacket5writeER12BinaryStream,void* this_,void* a){
    //dirty patch to hide seed
    access(this_,uint,40)=114514;
    return original(this_,a);
}

static int limitLevel(int input, int max) {
  if (input < 0)
    return 0;
  else if (input > max)
    return 0;
  return input;
}
struct Enchant {
  enum Type : int {};
  static std::vector<std::unique_ptr<Enchant>> mEnchants;
  virtual ~Enchant();
  virtual bool isCompatibleWith(Enchant::Type type);
  virtual int getMinCost(int);
  virtual int getMaxCost(int);
  virtual int getMinLevel();
  virtual int getMaxLevel();
  virtual bool canEnchant(int) const;
};

struct EnchantmentInstance {
  enum Enchant::Type type;
  int level;
  int getEnchantType() const;
  int getEnchantLevel() const;
  void setEnchantLevel(int);
};
//将外挂附魔无效
THook(int, _ZNK19EnchantmentInstance15getEnchantLevelEv, EnchantmentInstance* thi) {
  int level2 =  thi->level;
  auto &enchant = Enchant::mEnchants[thi->type];
  auto max      = enchant->getMaxLevel();
  auto result   = limitLevel(level2, max);
  if (result != level2) thi->level = result;
  return result;
}
/*
typedef unsigned long IHash;
static IHash MAKE_IHASH(ItemStack* a){
    IHash res= a->getIdAuxEnchanted();
    if(*a->getUserData()){
        res^=(*(a->getUserData()))->hash()<<28;
    }
    return res;
}
struct VirtInv{
    unordered_map<IHash,int> items;
    bool bad;
    VirtInv(Player& p){
        bad=0;
    }
    void setBad(){
        bad=1;
    }
    void addItem(IHash item,int count){
        if(item==0) return;
        int prev=items[item];
        items[item]=prev+count;
    }
    void takeItem(IHash item,int count){
        addItem(item,-count);
    }
    bool checkup(){
        if(bad) return 1;
        for(auto &i:items){
            if(i.second<0){
                return false;
            }
        }
        return true;
    }
    void clear(){
        items.clear();
        bad=false;
    }
};*/
//unordered_map<string,IHash> lastitem;
THook(unsigned long,_ZNK20InventoryTransaction11executeFullER6Playerb,void* _thi,Player &player, bool b){
    if(player.getPlayerPermissionLevel()>1) return original(_thi,player,b);
    const string& name=player.getName();
    auto& a=*((unordered_map<InventorySource,vector<InventoryAction> >*)_thi);
    for(auto& i:a){
    for(auto& j:i.second){
        if(i.first.getContainerId()==119){
            //offhand chk
            if((!j.getToItem()->isNull() && !j.getToItem()->isOffhandItem()) || (!j.getFromItem()->isNull() && !j.getFromItem()->isOffhandItem())){
                notifyCheat(name,INV);
                return 6;
            }
        }
        if(banitems.has(j.getFromItem()->getId()) || banitems.has(j.getToItem()->getId())){
            async_log("[ITEM] %s tries to use dangerous items(banned) %s %s\n",name.c_str(),j.getFromItem()->toString().c_str(),j.getToItem()->toString().c_str());
            sendText(&player,BANNED_ITEM,POPUP);
            return 6;
        }
        /*
        if(j.getSlot()==50 && i.first.getContainerId()==124){
            //track this
            auto hashf=MAKE_IHASH(j.getFromItem()),hasht=MAKE_IHASH(j.getToItem());
            auto it=lastitem.find(name);
            if(it==lastitem.end()){
                lastitem[name]=hasht;
                continue;
            }else{
                if(it->second!=hashf){
                    async_log("[ITEM] crafting hack detected for %s , %s\n",name.c_str(),j.getFromItem()->toString().c_str());
                    notifyCheat(name,INV);
                    return 6;
                }
                it->second=hasht;
            }
        }*/
        //printf("cid %d flg %d src %d slot %u get %d %s %s hash %ld %ld\n",j.getSource().getContainerId(),j.getSource().getFlags(),j.getSource().getType(),j.getSlot(),i.first.getContainerId(),j.getFromItem()->toString().c_str(),j.getToItem()->toString().c_str(),MAKE_IHASH(j.getFromItem()),MAKE_IHASH(j.getToItem()));
    }
    }
    return original(_thi,player,b);
}
using namespace rapidjson;

static void _load_config(){
    banitems.clear();warnitems.clear();banword.clear();
    Document d;
    FileBuffer fb("config/bear.json");
    if(d.ParseInsitu(fb.data).HasParseError()){
        printf("[ANTIBEAR] JSON ERROR pos: %d type: %s!\n",d.GetErrorOffset(),GetParseErrorFunc(d.GetParseError()));
        exit(1);
    }
    FPushBlock=d["FPushChest"].GetBool();
    FExpOrb=d["FSpwanExp"].GetBool();
    FDest=d["FDestroyCheck"].GetBool();
    FChatLimit=d["FChatLimit"].GetBool();
    LOG_CHEST=d.HasMember("LogChest")?d["LogChest"].GetBool():false;
    auto&& x=d["banitems"].GetArray();
    for(auto& i:x){
        if(!banitems.full())
        banitems.push_back((short)i.GetInt());
    }
    auto&& y=d["warnitems"].GetArray();
    for(auto& i:y){
        if(!warnitems.full())
        warnitems.push_back((short)i.GetInt());
    }
    auto&& z=d["banwords"].GetArray();
    for(auto& i:z){
        if(!banword.full())
        banword.push_back(i.GetString());
    }
    MAX_CHAT_SIZE=d.HasMember("MAX_CHAT_LEN")?d["MAX_CHAT_LEN"].GetInt():1000;
}
static void load_config(argVec& a,CommandOrigin const & b,CommandOutput &outp){
    _load_config();
}
static Shash_t lastn;
static clock_t lastcl;
static int fd_count;
#include<ctime>
static int handle_dest(GameMode* a0,BlockPos const& a1,unsigned char a2) {
    if(!FDest) return 1;
    auto sp=a0->getPlayer();
    int pl=sp->getPlayerPermissionLevel();
    if(pl>1 || sp->isCreative()) {
        return 1;
    }
    auto hash=sp->getNameTagAsHash();
    int x(a1.x),y(a1.y),z(a1.z); 
    Block& bk=*sp->getBlockSource()->getBlock(a1);
    int id=bk.getLegacyBlock()->getBlockItemId();
    if(id==7 || id==416){
        notifyCheat(sp->getName(),CheatType::INV);
        return 0;
    }
    if(hash==lastn && clock()-lastcl<CLOCKS_PER_SEC*(10.0/1000)/*10ms*/) {
        lastcl=clock();
        fd_count++; 
        if(fd_count>=5){
            fd_count=3;
            return 0;
        }
    }else{
        lastn=hash;
        lastcl=clock();
        fd_count=0;
    }
    const Vec3& fk=a0->getPlayer()->getPos();
    #define abs(x) ((x)<0?-(x):(x))
    int dx=fk.x-x;
    int dy=fk.y-y;
    int dz=fk.z-z;
    int d2=dx*dx+dy*dy+dz*dz;
    if(d2>45) {
        return 0;
    }
    return 1;
}
static void toggle_dbg(argVec& a,CommandOrigin const & b,CommandOutput &outp){
    dbg_player=!dbg_player;
}
static void kick_cmd(argVec& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
    if((int)b.getPermissionsLevel()>0) {
        auto x=getuser_byname(a[0]);
        if(x){
            forceKickPlayer(*x);
            outp.success("§bKicked player");
        }else{
            outp.error("Player not found!");
        }
    }
}
static void bangui_cmd(argVec& a,CommandOrigin const & b,CommandOutput &outp) {
    gui_ChoosePlayer((ServerPlayer*)b.getEntity(),"ban","ban",[](ServerPlayer* sp,string_view dst){
            SPBuf sb;
            sb.write("ban \""sv);
            sb.write(dst);
            sb.write("\""sv);
            runcmdAs(sb.get(),sp);
    });
}
THook(void*,_ZN5Actor9addEffectERK17MobEffectInstance,Actor& ac,MobEffectInstance* mi){
    if(mi->getId()==14){
        auto sp=getSP(ac);
        if(sp){
            if(sp->getPlayerPermissionLevel()<=1){
                async_log("[EFFECT] %s used self-hiding effect\n",sp->getName().c_str());
            }
        }
    }
    return original(ac,mi);
}
static string dumpSP(ServerPlayer& sp){
    string ret;
    auto& x=sp.getSupplies();
    int sz=x.getContainerSize((ContainerID)0ul);
    for(int i=0;i<sz;++i){
        auto& item=x.getItem(i,(ContainerID)0ul);
        //printf("%s\n",item.toString().c_str());
        ret+=item.toString()+" | ";
    }
    return ret;
}
static string dumpSP_Ender(ServerPlayer& sp){
    string ret;
    auto* x=sp.getEnderChestContainer();
    if(!x){
        printf("no ender found\n");
        return "";
    }
    int sz=x->getContainerSize();
    for(int i=0;i<sz;++i){
        auto& item=x->getItem(i);
        //printf("%s\n",item.toString().c_str());
        ret+=item.toString()+" | ";
    }
    return ret;
}
static string dumpall(ServerPlayer* sp){
    string ret;
    ret=dumpSP(*sp);
    ret+="\n-----starting ender chest dump-----\n";
    ret+=dumpSP_Ender(*sp)+"\n";
    return ret;
}
static void oncmd_invcheck(argVec& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
    auto sp=getSP(getplayer_byname2(a[0]));
    if(!sp){
        outp.error("cant find user");
        return;
    }
    outp.addMessage(dumpall(sp));
}
static void onJoin(ServerPlayer* sp){
    auto inv=dumpall(sp);
    int fd=open(("invdump/"+sp->getName()).c_str(),O_WRONLY|O_TRUNC|O_CREAT,S_IRUSR);
    write(fd,inv.data(),inv.size());
    close(fd);
}
void mod_init(std::list<string>& modlist) {
    initlog();
    register_cmd("ban",oncmd,"ban player",1);
    register_cmd("unban",oncmd2,"unban player",1);
    register_cmd("reload_bear",load_config,"reload Configs for antibear",1);
    register_cmd("bear_dbg",toggle_dbg,"toggle item id debug",1);
    register_cmd("skick",kick_cmd,"force kick",1);
    register_cmd("bangui",bangui_cmd,"gui for ban",1);
    register_cmd("invcheck",oncmd_invcheck,"inspect player's inventory",1);
    register_cmd("mute",oncmd_mute,"mute player",1);
    mkdir("invdump",S_IRWXU);
    reg_player_join(onJoin);
    reg_useitemon(handle_u);
    reg_player_left(handle_left);
    reg_chat(hkc);
    _load_config();
    if(getenv("LOGNET")) rori=(typeof(rori))(MyHook(fp(recvfrom),fp(recvfrom_hook)));
    printf("[ANTI-BEAR] Loaded " BDL_TAG "\n");
    load_helper(modlist);
}

