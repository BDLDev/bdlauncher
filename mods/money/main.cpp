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
using std::string;
extern "C"{
	__attribute__((visibility ("default"))) void mod_init();
  __attribute__((visibility ("default"))) bool reduceMoney(string const&,int);
  __attribute__((visibility ("default"))) void addMoney(string const&,int);
  __attribute__((visibility ("default"))) int getMoney(string const&);
  __attribute__((visibility ("default"))) void setMoney(string const&,int);
};
std::unordered_map<string,int> data;
int strtoint(string& ok){
  int rv;
  sscanf(ok.c_str(),"%d",&rv);
  return rv;
}
void load(){
  int fd=open("money/money.txt",O_CREAT,S_IRWXU);
  close(fd);
  std::ifstream banf("money/money.txt");
  filetomap<std::unordered_map<string,int>,string,int >(data,banf,std::to_string,strtoint);
}
void save(){
  std::ofstream fk("money/money.txt");
  maptofile<std::unordered_map<string,int>>(data,fk);
}
int getMoney(string const& nm){
  if(!data.count(nm)){
    data[nm]=500;
    save();
    return 500;
  }
  return data[nm];
}
void setMoney(string const& nm,int v){
  data[nm]=v;
  save();
}
void addMoney(string const& nm,int v){
  setMoney(nm,getMoney(nm)+v);
}
bool reduceMoney(string const& nm,int v){
  int vv=getMoney(nm);
  if(vv<v) return false;
  vv-=v;
  setMoney(nm,vv);
  return true;
}

struct MCmd : Command
{
  CommandMessage name;
    ~MCmd() override = default;
    static void setup(CommandRegistry &registry)
    {
        registry.registerCommand("money", "Money Command", (CommandPermissionLevel)0, (CommandFlag)0, (CommandFlag)32);
        registry.registerOverload<MCmd>("money", CommandVersion(1, INT_MAX),CommandParameterData(CommandMessage::type_id(), &CommandRegistry::parse<CommandMessage>, "oper", (CommandParameterDataType)0, nullptr, offsetof(MCmd, name), false, -1));
    }
    void execute(CommandOrigin const &origin, CommandOutput &outp) override
    {
        std::string oper=name.getMessage(origin);
        outp.addMessage(oper.c_str());
        #define swith(a,b) (memcmp(a.c_str(),b,strlen(b))==0)
        if(swith(oper,"query")){
          std::string nd;
          if(oper.size()==5){
            if(origin.getOriginType()==0)
            nd=*((Player*)origin.getEntity())->getPlayerName();
            else nd="fku";
          }else{
            if(oper.size()>6){
              nd=oper.substr(6);
            }else{
              nd="fku";
            }
          }
          char buf[512];
          sprintf(buf,"%s's money is %d",nd.c_str(),getMoney(nd));
          outp.addMessage(buf);
          outp.success();
          return;
        }
        //op needed
        if(origin.getOriginType()==0 && ((Player*)origin.getEntity())->getCommandPermissionLevel()<1) return;
        if(swith(oper,"set")){
          if(oper.size()>4){
            char buf[512];
            int nm;
            sscanf(oper.c_str()+4,"%s %d",buf,&nm);
            setMoney(string(buf),nm);
            outp.addMessage("ok!");
            outp.success();
          }
        }
	if(origin.getOriginType()==0 && ((Player*)origin.getEntity())->getCommandPermissionLevel()<1) return;
        if(swith(oper,"add")){
          if(oper.size()>4){
            char buf[512];
            int nm;
            sscanf(oper.c_str()+4,"%s %d",buf,&nm);
			addMoney(string(buf),nm);
            outp.addMessage("add ok!");
            outp.success();
          }
        }
    }
};
fn_6 addCmd;
void cmdSetup(CommandRegistry* a){
  printf("[Money] loaded\n");
  MCmd::setup(*a);
}
void mod_init(){
  addCmd=getFuncEx("addCmdhook");
  addCmd(cmdSetup);
  mkdir("money",S_IRWXU);
  load();
}
