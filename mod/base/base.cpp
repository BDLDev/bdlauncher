#include<cstdio>
#include<list>
#include<forward_list>
#include<string>
#include<unordered_map>
#include"../cmdhelper.h"
#include"../myhook.h"
#include<vector>
#include"minecraft/level/Level.h"
#include"minecraft/actor/Player.h"
#include"minecraft/actor/ItemActor.h"
#include"minecraft/core/GameMode.h"
#include"minecraft/packet/TextPacket.h"
#include"minecraft/packet/SetDisplayObjectivePacket.h"
#include"minecraft/item/ItemStack.h"
#include"minecraft/actor/PlayerInventoryProxy.h"
#include"minecraft/item/Item.h"
#include "minecraft/core/typeid.h"
#include"seral.hpp"
#include<signal.h>
#include <sys/stat.h>
#include<unistd.h>
#include <sys/stat.h>
#include<dlfcn.h>
using std::string;
using std::list;
#include"base.h"

extern "C" {
    void base_init(list<string>& modlist);
}

struct TeleportCommand {
    char filler[1024];
    TeleportCommand();
    void teleport(Actor &,Vec3,Vec3*,AutomaticID<Dimension,int>) const;
};
void sendText(Player* a,string ct) {
    TextPacket pk=TextPacket::createRaw(ct);
    ((ServerPlayer*)a)->sendNetworkPacket(pk);
}
void sendText2(Player* a,string ct) {
    TextPacket pk=TextPacket::createJukeboxPopup(ct);
    ((ServerPlayer*)a)->sendNetworkPacket(pk);
}

static void*(*tcmd)(void*);
static TeleportCommand cmd_p;

extern void load_helper(list<string>& modlist);
void TeleportA(Actor& a,Vec3 b,AutomaticID<Dimension,int> c) {
    cmd_p.teleport(a,b,nullptr,c);
    cmd_p.teleport(a,b,nullptr,c);
}
void KillActor(Actor* a) {
    (*((void(**)(Actor*))((*(char**)a)+0x708)))(a);
}
Player* getplayer_byname(const string& name) {
    Minecraft* mc=getMC();
    Level* lv=mc->getLevel();
    Player* rt=NULL;
    lv->forEachPlayer([&](Player& tg)->bool{
        if(tg.getName()==name) {
            rt=&tg;
            return false;
        }
        return true;
    });
    return rt;
}
#define fcast(a,b) (*((a*)(&b)))
void sendTransfer(Player* a,const string& ip,short port){
    TransferPacket pk(ip,port);
    ((ServerPlayer*)a)->sendNetworkPacket(fcast(Packet,pk));
}
void sendPacket(Player* a,void(*cb)(void*),void* arg){
	char pk[1024];
	void(*pp)(char*)=(typeof(pp))dlsym(NULL,"_ZN6PacketC2Ev");
	pp(pk);
	cb(arg,pk);
	((ServerPlayer*)a)->sendNetworkPacket(fcast(Packet,pk));
}
void readcfg(const string& fname,unordered_map<string,string>& out){    
    FILE* a=fopen(fname.c_str(),"r");
    char buf[1024];
    if(a){
        while(fgets(buf,1024,a)){
            int l=strlen(buf);
            int i;
            for(i=0;buf[i];++i){
                if(buf[i]=='=') break;
            }
            if(i==l) continue;
            out[string(buf,i)]=string(buf+i+1,l-i-1);
        }
    }
}

Player* getplayer_byname2(const string& name) {
    Minecraft* mc=getMC();
    Level* lv=mc->getLevel();
    Player* rt=NULL;
    lv->forEachPlayer([&](Player& tg)->bool{
        string bf=tg.getName();
#define min(a,b) ((a)<(b)?(a):(b))
        int sz=min(tg.getName().size(),name.size());
        int eq=1;
        for(int i=0; i<sz; ++i) {
            if(tolower(bf[i])!=tolower(name[i])) {
                eq=0;
                break;
            }
        }
        if(eq) {
            rt=&tg;
            return false;
        }
        return true;
    });
    return rt;
}
static string sname("Server");
MCRESULT runcmd(const string& a) {
    return getMC()->getCommands()->requestCommandExecution(std::unique_ptr<CommandOrigin>((CommandOrigin*)new ServerCommandOrigin(sname,*(ServerLevel*)getMC()->getLevel(),(CommandPermissionLevel)5)),a,4,1);
}
typedef unsigned int u32;
static u32(*tick_o)(Level*);
static int tkl;
void call_sht(int d);
static u32 onTick(Level* a) {
    int rt=tick_o(a);
    tkl++;
    if(tkl%(15*60*20)==0) //15min
        call_sht(SIGABRT);
    return rt;
}

static void (*dummy)(std::vector<std::string>&,CommandOrigin const &,CommandOutput &outp);
static void mylex(std::string& oper,std::vector<std::string>& out) {
    oper=oper+"  ";
    int sz=oper.size();
    const char* c=oper.c_str();
    int t=0;
    int st=0,ed;
#define W c[i]
    for(int i=0; i<sz; ++i) {
        switch(t) {
        case 0:
            if(W=='"') t=1;
            else t=2;
            st=i;
            break;
        case 1:
            if(W=='"') t=3,ed=i;
            break;
        case 2:
            if(W==' ') t=4,ed=i;
            break;
        case 3:
            out.push_back(std::string(c+st+1,ed-st-1));
            t=0;
            break;
        case 4:
            out.push_back(std::string(c+st,ed-st));
            t=0;
            i--;
            break;
        }
    }
}
struct ACmd : Command {
    CommandMessage msg;
    void* callee;
    ~ACmd() override = default;
    void execute(CommandOrigin const &origin, CommandOutput &outp) override
    {
        std::string oper=msg.getMessage(origin);
        std::vector<std::string> args;
        mylex(oper,args);
        ((typeof(dummy))callee)(args,origin,outp);
    }
};
using std::string;
struct req {
    string name,desc;
    void* fn;
};
static std::deque<req> reqs;
void register_cmd(const std::string& name,void* fn,const std::string& desc) {
    reqs.push_back({name,desc,fn});
}
static ACmd* chelper(void* fn) {
    ACmd* fk=new ACmd();
    fk->callee=fn;
    return fk;
}

static void handle_regcmd(CommandRegistry& t) {
    for(auto const& i:reqs) {
        t.registerCommand(i.name,i.desc.c_str(),(CommandPermissionLevel)0,(CommandFlag)0,(CommandFlag)32);
        t.registerOverload2(i.name.c_str(),wr_ret_uni((u64)i.fn,(char*)chelper),CommandParameterData(type_id<CommandRegistry, CommandMessage>(), &CommandRegistry::parse<CommandMessage>, "operation", (CommandParameterDataType)0, nullptr, offsetof(ACmd, msg), false, -1));
    }
    reqs.clear();
}
static Minecraft* MC;
Minecraft* getMC() {
    return MC;
}
static void* sss,*ss;
static void sss_new(Minecraft& a, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const& d, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const& b, PermissionsFile* c) {
    printf("MC %p\n",&a);
    ((typeof(&sss_new))sss)(a,d,b,c);
    MC=&a;
    return;
}
static void ss_new(CommandRegistry& thi,CommandRegistry& a) {
    handle_regcmd(thi);
    ((typeof(&ss_new))ss)(thi,a);
    return;
}
void base_init(list<string>& modlist)
{
    printf("[MOD/BASE] loaded!\n");
    tick_o=(typeof(tick_o))MyHook(dlsym(NULL,"_ZN5Level4tickEv"),fp(onTick));    			sss=MyHook(fp(dlsym(NULL,"_ZN14ServerCommands19setupStandardServerER9MinecraftRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES9_P15PermissionsFile")),fp(sss_new));
    ss=MyHook(fp(dlsym(NULL,"_ZN10SayCommand5setupER15CommandRegistry")),fp(ss_new));
    load_helper(modlist);
}
