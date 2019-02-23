#include<bits/stdc++.h>
#include<unistd.h>
#include "../../bdlaunch/launch/mods.h"
#include "../../BedrockMod/include/base.h"
#include "../fklib/lib.hpp"
       #include <sys/stat.h>
       #include <sys/types.h>
#include <minecraft/command/Command.h>
#include <minecraft/command/CommandMessage.h>
#include <minecraft/command/CommandOutput.h>
#include <minecraft/command/CommandParameterData.h>
#include <minecraft/command/CommandRegistry.h>
#include <minecraft/command/CommandVersion.h>
#include<fcntl.h>
using std::min,std::swap,std::max;
using std::string;
extern "C"{
	 __attribute__((visibility ("default"))) void mod_init();
};
struct land{
  int x,y,lx,ly;
  std::string owner;
  bool checkOwn(std::string name){
    return owner.find("["+name+"]")!=std::string::npos;
  }
  operator==(const land& b) const{
    return x==b.x && y==b.y && lx==b.lx && ly==b.ly;
  }
  void addOwn(std::string name){
    owner+="["+name+"]";
  }
  int size(){
    return abs(lx*ly);
  }
};
std::string land_string(land& a){
  char buf[512];
  sprintf(buf,"%d:%d:%d:%d:%s",a.x,a.y,a.lx,a.ly,a.owner.c_str());
  return std::string(buf);
}
land to_land(std::string& dat){
  char buf[512];
  land a;
  sscanf(dat.c_str(),"%d:%d:%d:%d:%[^\n]",&a.x,&a.y,&a.lx,&a.ly,buf);
  a.owner=std::string(buf);
  return a;
}
static std::forward_list<land> list;
bool checkland(land& a,int x,int z){
  int t1=x-a.x;
  int t2=z-a.y;
  if(t1<0 || t2<0) return false;
  if(t1<a.lx && t2<a.ly) return true;
  return false;
}
std::pair<bool,std::string> checkperm(int x,int z,std::string& name){
  for(auto a:list){
    if(checkland(a,x,z) && !a.checkOwn(name)){
      return std::make_pair(false,a.owner);
    }
  }
  return std::make_pair(true,"");
}
land nullland;
land tmpland;
land* getland(int x,int z){
for(auto a:list){
if(checkland(a,x,z)) {tmpland=a;return &tmpland;}
}
return &nullland;
}
void load(){
  int fd=open("land/land.txt",O_CREAT,S_IRWXU);
  close(fd);
  std::ifstream banf("land/land.txt");
  filetolist<std::forward_list<land>,land >(list,banf,to_land);
}
void save(){
  std::ofstream fk("land/land.txt");
  listtofile<std::forward_list<land>,land >(list,fk,land_string);
}
Player* (*FindPlayer)(std::string* pp);
void (*sendMessage)(Player* player, std::string* msg);
std::set<std::string> g_start,g_end;
struct Vc2{
  int x,z;
};
std::unordered_map<std::string,Vc2> pStart,pEnd;
land* checkColl(Vc2& st,Vc2& ed){
  for(auto a:list){
    int xa1=a.x;
    int ya1=a.y;
    int xa2=a.x+a.lx-1;
    int ya2=a.y+a.ly-1;
    int xb1=st.x;
    int xb2=ed.x;
    int yb1=st.z;
    int yb2=ed.z;
    #define sswap(a,b) if(a>b) swap(a,b)
    sswap(xa1,xa2);
    sswap(ya1,ya2);
    sswap(yb1,yb2);
    sswap(xb1,xb2);
    if(min(xa1,xb1)<=min(xa2,xb2) && min(xa1,xb1)<=min(xa2,xb2)){
      tmpland=a;
      return &tmpland;
    }
  }
  return NULL;
}
bool checkColl2(Vc2& st,Vc2& ed,string name){
  for(auto a:list){
    int xa1=a.x;
    int ya1=a.y;
    int xa2=a.x+a.lx-1;
    int ya2=a.y+a.ly-1;
    int xb1=st.x;
    int xb2=ed.x;
    int yb1=st.z;
    int yb2=ed.z;
    #define sswap(a,b) if(a>b) swap(a,b)
    sswap(xa1,xa2);
    sswap(ya1,ya2);
    sswap(yb1,yb2);
    sswap(xb1,xb2);
	int t1x=max(xa1,xb1);
	int t1y=max(ya1,yb1);
	int t2x=min(xa2,xb2);
	int t2y=min(ya2,yb2);
	if(t2x>=t1x && t2y>=t1y && !a.checkOwn(name)) return false;
    //if(max(xa1,xb1)<=(xa2,xb2) && min(xa1,xb1)<=min(xa2,xb2) && !a.checkOwn(name)){
    //  return false;
    //}
  }
  return true;
}
bool (*reduceMoney)(string const&,int);
void (*addMoney)(string const&,int);
bool buyLand(Player* pp,Vc2 st,Vc2 ed){
  land tmp;
  //tmp.owner=*pp->getPlayerName();
  sswap(st.x,ed.x);
  sswap(st.z,ed.z);
  if(!checkColl2(st,ed,*pp->getPlayerName())) return false;
  tmp.addOwn(*pp->getPlayerName());
  tmp.x=st.x;
  tmp.y=st.z;
  tmp.lx=ed.x-st.x+1;
  tmp.ly=ed.z-st.z+1;
  if(!reduceMoney(*pp->getPlayerName(),tmp.size()*10)) return false;
  list.push_front(tmp);
  save();
  return true;
}
void sellLand(Player* pp,land& ld){
  addMoney(*pp->getPlayerName(),ld.size()*10);
  list.remove(ld);
  save();
}
struct LandCmd : Command
{
  CommandMessage op;
    ~LandCmd() override = default;
    static void setup(CommandRegistry &registry)
    {
        registry.registerCommand("land", "land Command", (CommandPermissionLevel)0, (CommandFlag)0, (CommandFlag)32);
        registry.registerOverload<LandCmd>("land", CommandVersion(1, INT_MAX),CommandParameterData(CommandMessage::type_id(), &CommandRegistry::parse<CommandMessage>, "oper", (CommandParameterDataType)0, nullptr, offsetof(LandCmd, op), false, -1));
    }
    void execute(CommandOrigin const &origin, CommandOutput &outp) override
    {
        if(origin.getOriginType()==0){
          std::string sb=op.getMessage(origin);
          Player* pp=(Player*)origin.getEntity();
            if(sb=="start"){
              g_start.insert(*pp->getPlayerName());
            }
            if(sb=="end"){
              g_start.erase(*pp->getPlayerName());
              g_end.insert(*pp->getPlayerName());
            }
            if(sb=="buy"){
              g_end.erase(*pp->getPlayerName());
              if(pStart.count(*pp->getPlayerName())==0 || pEnd.count(*pp->getPlayerName())==0 ){
                outp.addMessage("Failed buying land,Select start and end plz.");
                return;
              }
              if(!buyLand(pp,pStart[*pp->getPlayerName()],pEnd[*pp->getPlayerName()])){
                outp.addMessage("Failed buying land,check overlap or money");
              }else{
                outp.addMessage("Successed buying land");
              }
            }
            if(sb=="sell"){
              land* fk=getland((int)pp->getPos().x,(int)pp->getPos().z);
              if(pp->getCommandPermissionLevel()<1 && !fk->checkOwn(*pp->getPlayerName())){
                outp.addMessage("Failed selling land,not your land!");
                return;
              }
              sellLand(pp,*fk);
            }
            if(sb.length()>7 && memcmp(sb.c_str(),"invite",6)==0){
              std::string tmp=sb.substr(7);
              land* fk=getland((int)pp->getPos().x,(int)pp->getPos().z);
              if(!fk->checkOwn(*pp->getPlayerName())){
                outp.addMessage("Failed sharing land,not your land!");
                return;
              }
              list.remove(*fk);
              fk->addOwn(tmp);
              list.push_front(*fk);
              save();
            }
          outp.addMessage(op.getMessage(origin));
          outp.success();
        }
    }
};

void (*addCmdhook)(fn_6 hook);
static void cmdSetup(CommandRegistry* a){
  printf("[Land] loaded\n");
  LandCmd::setup(*a);
}

fn_666 useblock_orig;
fn_66666 destroy_orig;
fn_666666 place_orig;
bool permHelper(Player* pp,BlockPos* bp){
  if(pp->getDimensionId()!=0) return true;
  auto res=checkperm(bp->x,bp->z,*pp->getPlayerName());
  if(res.first==false){
    char buf[256];
    //printf("nmsl %s\n",res.second.c_str());
    sprintf(buf,"it's %s's land!!!",res.second.c_str());
    std::string bufx(buf);
    sendMessage(pp,&bufx);
    return false;
  }
  return true;
}
u64 useblock(u64 thi,Player* pp,BlockPos* bp){
  if(!permHelper(pp,bp)) return 0;
  if(g_start.count(*pp->getPlayerName())){
    pStart[*pp->getPlayerName()]=(Vc2){bp->x,bp->z};
    return 0;
  }
  if(g_end.count(*pp->getPlayerName())){
    pEnd[*pp->getPlayerName()]=(Vc2){bp->x,bp->z};
    return 0;
  }
  return useblock_orig(thi,pp,bp);
}
u64 destroy(u64 thi,Actor* ppa,BlockPos* bp,ItemInstance* it,u64 bl){
  if(ppa->getEntityTypeId()==1 && !permHelper((Player*)ppa,bp)){
    return 0;
  }
  else
  return destroy_orig(thi,ppa,bp,it,bl);
}
u64 place(u64 thi,Actor* ppa,BlockPos* bp,u64 unk,ItemInstance* it,u64 bl){
  if(ppa->getEntityTypeId()==1 && !permHelper((Player*)ppa,bp)){
    return 0;
  }
  else{
  return place_orig(thi,ppa,bp,unk,it,bl);
}
}
void (*getPlayersForeach)(void(*cb)(Player*));
int cnt;
Level* (*getLev)();
bool landbc(Player& pp){
  std::string dmy;
  auto res=checkperm((int)pp.getPos().x,(int)pp.getPos().z,dmy);
  if(res.first==false){
    std::string sb;
    sb="this is ";
    sb+=res.second;
    sb+="'s land";
    sendMessage(&pp,&sb);
  }
  return true;
}
fn_6 onTick_orig;
u64 onTick(Level* thi){
  u64 rv=onTick_orig(thi);
  //printf("tick\n");
  cnt++;
  if(cnt%40==0){
    //getPlayersForeach(landbc);
    getLev()->forEachPlayer(landbc);
  }
  return rv;
}
u64 (*onAttack_orig)(Player* thi,Actor* a2,double a3,float a4);
u64 onAttack(Player* thi,Actor* a2,double a3,float a4){
  std::pair<bool,std::string> res;
  if(!(res=checkperm((int)a2->getPos().x,(int)a2->getPos().z,*thi->getPlayerName())).first)
  {
    char buf[256];
    //printf("nmsl %s\n",res.second.c_str());
    sprintf(buf,"it's %s's land!!!",res.second.c_str());
    std::string bufx(buf);
    sendMessage(thi,&bufx);
    return 0;
  }else{
    return onAttack_orig(thi,a2,a3,a4);
  }
}
void mod_init(){
  addCmdhook=getFuncEx("addCmdhook");
  FindPlayer=getFuncEx("FindPlayer");
  sendMessage=getFuncEx("sendMessage");
  getPlayersForeach=getFuncEx("getPlayersForeach");
  getLev=getFuncEx("getLevel");
  reduceMoney=getFuncEx("reduceMoney");
  addMoney=getFuncEx("addMoney");
  addCmdhook(cmdSetup);
  mkdir("land",S_IRWXU);
  load();
  MCHok("_ZNK5Block3useER6PlayerRK8BlockPos",useblock,useblock_orig);
  MCHok("_ZN11BlockSource28checkBlockDestroyPermissionsER5ActorRK8BlockPosRK12ItemInstanceb",destroy,destroy_orig);
  MCHok("_ZN11BlockSource21checkBlockPermissionsER5ActorRK8BlockPosaRK12ItemInstanceb",place,place_orig);
  MCHok("_ZN5Level4tickEv",onTick,onTick_orig);
  MCHok("_ZN6Player6attackER5Actor",onAttack,onAttack_orig);
}

