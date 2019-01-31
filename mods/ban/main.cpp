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
extern "C"{
	void mod_init();
};
std::forward_list<std::string> list;
bool check(std::string* a){
  for(auto c:list){
    char buf[512];
    strcpy(buf,c.c_str());
    for(int i=0;i<512;++i){
      if(buf[i]==0) break;
      if(buf[i]=='#') {buf[i]=0;break;}
    }
    if(strcmp(a->c_str(),buf)==0) return 1;
  }
  return 0;
}
fn_66 Blacklist9isBlocked;
u64 test(Blacklist* a,Blacklist::Entry* b){
 // printf("gg %s\n",b->getXUID()->c_str());
  return check(b->getXUID());
}
std::string strtostr(std::string& fk){
  return fk;
}
void load(){
  int fd=open("ban/blacklist.txt",O_CREAT,S_IRWXU);
  close(fd);
  std::ifstream banf("ban/blacklist.txt");
  filetolist<std::forward_list<std::string>,std::string >(list,banf,strtostr);
}
void save(){
  std::ofstream fk("ban/blacklist.txt");
  listtofile<std::forward_list<std::string> >(list,fk);
}
void BAN(std::string* a,std::string* b){
  char buf[512];
  sprintf(buf,"%s#%s",a->c_str(),b->c_str());
  list.push_front(std::string(buf));
  save();
}
Player* (*FindPlayer)(std::string* pp);
void (*KickPlayerByPlayer)(void* player,std::string&& reason);
struct BanCmd : Command
{
  CommandMessage name;
    ~BanCmd() override = default;
    static void setup(CommandRegistry &registry)
    {
        registry.registerCommand("ban", "Ban Command", (CommandPermissionLevel)2, (CommandFlag)0, (CommandFlag)0);
        registry.registerOverload<BanCmd>("ban", CommandVersion(1, INT_MAX),CommandParameterData(CommandMessage::type_id(), &CommandRegistry::parse<CommandMessage>, "name", (CommandParameterDataType)0, nullptr, offsetof(BanCmd, name), false, -1));
    }
    void execute(CommandOrigin const &origin, CommandOutput &outp) override
    {
        char outbuf[512];
        sprintf(outbuf,"okay banned %s",name.getMessage(origin).c_str());
        Player* sb=FindPlayer(&name.getMessage(origin));
        if(sb==NULL){
          outp.addMessage("cant find player");
          return;
        }
        printf("found\n");
        BAN(&sb->getXUID(),sb->getPlayerName());
        printf("banned\n");
        outp.addMessage(outbuf);
        KickPlayerByPlayer(sb,"nm$l");
        printf("kicked\n");
        outp.success();
    }
};

fn_6 addCmd;
void cmdSetup(CommandRegistry* a){
  printf("[Ban] loaded\n");
  BanCmd::setup(*a);
}
void mod_init(){
  addCmd=getFuncEx("addCmdhook");
  FindPlayer=getFuncEx("FindPlayer");
  KickPlayerByPlayer=getFuncEx("KickPlayerByPlayer");
  addCmd(cmdSetup);
  mkdir("ban",S_IRWXU);
  load();
  MCHok("_ZNK9Blacklist9isBlockedERKNS_5EntryE",test,Blacklist9isBlocked);
}

