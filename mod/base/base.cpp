#include"../cmdhelper.h"
#include"../myhook.h"
#include<Loader.h>
#include<MC.h>
#include<vector>
#include<seral.hpp>
#include<signal.h>
#include <sys/stat.h>
#include<unistd.h>
using std::list;
using std::vector;
#include"base.h"
#include"hook.hpp"
#include"cmdreg.hpp"
#include"utils.hpp"
#include<sstream>

extern "C" {
   BDL_EXPORT void base_init(list<string>& modlist);
}

//export APIS
void split_string(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}
bool execute_cmd_random(const vector<string>& chain){
    int rd=rand()%chain.size();
    return execute_cmdchain(chain[rd],"",false);
}

bool execute_cmdchain(const string& chain_,const string& sp_,bool chained){
    string chain=chain_;   
    if(sp_.size()){
        string sp=sp_;
        if(sp_[0]!='"') sp="\""+sp_+"\"";
        char buf[8192];
        const char* src=chain_.data();
        int bufsz=0;
        for(int i=0;i<chain_.size();++i){
            if(memcmp(src+i,"%name%",6)==0){
                memcpy(buf+bufsz,sp.data(),sp.size());
		        bufsz+=sp.size();
                i+=5;
            }else{
                buf[bufsz++]=src[i];
            }
        }
        chain=string(buf,bufsz);
    }
    if(chain[0]=='!'){
        vector<string> dst;
        split_string(chain.substr(1),dst,";");
        return execute_cmd_random(dst);
    }
    vector<string> dst;
    split_string(chain,dst,",");
    for(auto& i:dst){
        auto res=runcmd(i);
        if(!res.isSuccess() && chained) return false;
    }
    return true;
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

static TeleportCommand cmd_p;

extern void load_helper(list<string>& modlist);
void TeleportA(Actor& a,Vec3 b,AutomaticID<Dimension,int> c) {
    a.setPos(b);
    cmd_p.teleport(a,b,nullptr,c); 
}
void KillActor(Actor* a) {
    //!!! dirty workaround
    ((Mob*)a)->kill();
}
Player* getplayer_byname(const string& name) {
    Minecraft* mc=getMC();
    Level* lv=mc->getLevel();
    Player* rt=NULL;
    lv->forEachPlayer([&](Player& tg)->bool{
        if(tg.getRealNameTag()==name) {
            rt=&tg;
            return false;
        }
        return true;
    });
    return rt;
}
#define fcast(a,b) (*((a*)(&b)))
Player* getplayer_byname2(const string& name) {
    Minecraft* mc=getMC();
    Level* lv=mc->getLevel();
    Player* rt=NULL;
    lv->forEachPlayer([&](Player& tg)->bool{
        string bf=tg.getRealNameTag();
#define min(a,b) ((a)<(b)?(a):(b))
        int sz=min(bf.size(),name.size());
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

void get_player_names(vector<string>& a){
    getMC()->getLevel()->forEachPlayer([&](Player& tg)->bool{
        a.push_back(tg.getName());
        return true;
    });
}
static Minecraft* MC;
BDL_EXPORT Minecraft* getMC() {
    return MC;
}
THook(void*,_ZN14ServerCommands19setupStandardServerER9MinecraftRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES9_P15PermissionsFile,Minecraft& a, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const& d, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const& b, PermissionsFile* c){
    auto ret=original(a,d,b,c);
    printf("MC %p\n",&a);
    MC=&a;
    return ret;
}
THook(void*,_ZN10SayCommand5setupER15CommandRegistry,CommandRegistry& thi,CommandRegistry& a){
    handle_regcmd(thi);
    return original(thi,a);
}
struct DedicatedServer
{
    void stop();
};
DedicatedServer* dserver;
THook(void*,_ZN15DedicatedServer5startERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,DedicatedServer* t,string& b){
    printf("starting server %p\n",t);
    dserver=t;
    return original(t,b);
}
void set_int_handler(void* fn);
static void autostop(){
        if(dserver){
            printf("stoping server\n");
            dserver->stop();
        }
}
int getPlayerCount(){
    return getMC()->getLevel()->getUserCount();
}
int getMobCount(){
    return getMC()->getLevel()->getTickedMobCountPrevious();
}

NetworkIdentifier* getPlayerIden(ServerPlayer& sp){
    return access(&sp,NetworkIdentifier*,2952);
}
ServerPlayer* getuser_byname(const string& a){
    auto& vc=getMC()->getLevel()->getUsers();
    for(auto& i:vc){
        if(i->getName()==a) return i.get();
    }
    return nullptr;
}
void forceKickPlayer(ServerPlayer& sp){
    //auto iden=getPlayerIden(sp);
    //auto sub=sp.getClientSubId();
    //getMC()->getNetworkHandler()->onSubclientLogoff(*iden,sub);
    sp.disconnect();
}

void base_init(list<string>& modlist)
{
    printf("[MOD/BASE] loaded! V2019-11-23\n");  
    srand(time(0));  	
    set_int_handler(fp(autostop));		
    load_helper(modlist);
}
