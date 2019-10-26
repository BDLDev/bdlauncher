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
static unordered_map<string,int> banlist;
static unordered_map<string,string> xuid_name;
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
static void save2() {
    char* bf;
    int sz=maptomem(xuid_name,&bf,h_str2str,h_str2str);
    mem2file("banxuid.db",bf,sz);
}
static void load2() {
    char* buf;
    int sz;
    struct stat tmp;
    if(stat("banxuid.db",&tmp)==-1) {
        save2();
    }
    file2mem("banxuid.db",&buf,sz);
    memtomap(xuid_name,buf,h_str2str_load,h_str2str_load);
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
static u64(*hori)(u64 t,NetworkIdentifier& a, Certificate& b);
static u64 handleLogin(u64 t,NetworkIdentifier& a, Certificate& b) {
    string pn=ExtendedCertificate::getIdentityName(b);
    string xuid=ExtendedCertificate::getXuid(b);
    async_log("[JOIN]%s joined game with xuid <%s>\n",pn.c_str(),xuid.c_str());
    if(!xuid_name.count(xuid)){
        xuid_name[xuid]=pn;
        save2();
    }
    if(isBanned(pn) || (xuid_name.count(xuid) && isBanned(xuid_name[xuid]))) {
        string ban("§c你在当前服务器的黑名单内!");
        getMC()->getNetEventCallback()->disconnectClient(a,ban,false);
        return 0;
    }
    return hori(t,a,b);
}
static int (*cori)(void*,Player const&,string&);
static int hkc(void* a,Player & b,string& c) {
    int ret=cori(a,b,c);
    async_log("[CHAT]%s: %s\n",b.getName().c_str(),c.c_str());
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
        async_log("[NETWORK] %s send conn\n",buf);
    }
    return rt;
}
static void do_patch() {
    hori=(typeof(hori))MyHook(fp(dlsym(NULL,"_ZN20ServerNetworkHandler22_onClientAuthenticatedERK17NetworkIdentifierRK11Certificate")),fp(handleLogin));
    cori=(typeof(cori))MyHook(fp(dlsym(NULL,"_ZN20ServerNetworkHandler19_displayGameMessageERK6PlayerRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE")),fp(hkc));
}
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
    if((int)b.getPermissionsLevel()>0) {
        banlist[a[0]]=a.size()==1?0:(time(0)+atoi(a[1].c_str()));
        runcmd(string("kick \"")+a[0]+"\" §c你号没了");
        save();
        auto x=getplayer_byname(a[0]);
        if(x){
            xuid_name[x->getXUID()]=x->getName();
            save2();
        }
        outp.success("§e玩家已封禁: "+a[0]);
    }
}
static void oncmd2(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
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
        async_log("[ITEM] %s 使用高危物品(banned) %s pos: %d %d %d\n",sn.c_str(),buf,a2.x,a2.y,a2.z);
        sendText2(a0->getPlayer(),"§c无法使用违禁物品");
        return 0;
    }
    if(check("tnt") || check("lava")) {
        async_log("[ITEM] %s 使用危险物品(warn) %s pos: %d %d %d\n",sn.c_str(),buf,a2.x,a2.y,a2.z);
        return 1;
    }
    return 1;
}
static char(*wtf_o)(char*,char);
char wtf(char* x,char a){
    return wtf_o(x,1);
}
static int handle_left(ServerNetworkHandler* a0,ServerPlayer* a1,bool a2){
	async_log("[LEFT] %s left game\n",a1->getName().c_str());
	return 1;
}
enum CheatType{
    FLY,NOCLIP,INV,MOVE
};
void notifyCheat(const string& name,CheatType x){
    const char* CName[]={"FLY","NOCLIP","Creative","Teleport"};
    async_log("[%s] detected for %s\n",CName[x],name.c_str());
    string kick=string("kick \"")+name+"\" §c你号没了";
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
void bear_init(std::list<string>& modlist) {
    do_patch();
    load();
    load2();
    initlog();
    register_cmd("ban",fp(oncmd),"封禁玩家");
    register_cmd("unban",fp(oncmd2),"解除封禁");
    reg_useitemon(fp(handle_u));
    reg_player_left(fp(handle_left));
    rori=(typeof(rori))(MyHook(fp(recvfrom),fp(recvfrom_hook)));
    wtf_o=(typeof(wtf_o))MyHook(dlsym(NULL,"_ZN8GameRule17setAllowInCommandEb"),fp(wtf));
    printf("[ANTI-BEAR] Loaded\n");
    load_helper(modlist);
}

