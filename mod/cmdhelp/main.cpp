#include<Loader.h>
#include<MC.h>
#include"../base/base.h"
#include"rapidjson/document.h"
#include"rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include<fstream>
#include<cstdarg>
#include"../gui/gui.h"
using namespace std;

extern "C" {
   BDL_EXPORT void cmdhelp_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
struct CMD{
    string cond,run;
    bool execute(const string& name,bool chained=true){
        if(execute_cmdchain(cond,name,chained)) {execute_cmdchain(run,name,false);return true;}
        return false;
    }
};
struct Timer{
    int tim,sft;
    CMD run;
    bool chk(int tk){
        return tk%tim==sft;
    }
};
unordered_map<string,CMD> defcmds;
list<Timer> timers;
CMD joinHook;
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    auto nm=b.getName();
    if(a.size()==0){
        //show gui
        Form* x=new Form([nm](const string& s)->void{
            if(defcmds.count(s))
                defcmds[s].execute(nm);
        });
        x->setTitle("Commands-命令列表");
        x->setContent("选择一个命令来执行\n");
        for(auto& i:defcmds){
            x->addButton(i.first,i.first);
        }
        sendForm(*((ServerPlayer*)b.getEntity()),x);
        return;
    }
    if(defcmds.count(a[0])){
        if(defcmds[a[0]].execute(nm)){
            outp.success("success");
        }else{
            outp.error("error");
        }
    }else{
        outp.error("cant find");
    }
}
void join(ServerPlayer* sp){
    joinHook.execute(sp->getName(),false);
}
void tick(int tk){
    for(auto& i:timers){
        if(i.chk(tk)) i.run.execute("",false);
    }
}
int tkl;
THook(void*,_ZN5Level4tickEv,Level& a){
    tkl++;
    if(tkl%20==0) tick(tkl/20);
    return original(a);
}
char buf[8*1024*1024];
using namespace rapidjson;
void load(){
    timers.clear();
    defcmds.clear();
    Document dc;
    ifstream ff;
    ff.open("config/cmd.json",ios::in);
    buf[ff.readsome(buf,1024*1024*8)]=0;
    ff.close();
    if(dc.ParseInsitu(buf).HasParseError()){
        printf("[CMDHelper] Config JSON ERROR!\n");
        exit(1);
    }
    for(auto& i:dc.GetArray()){
        auto&& x=i.GetObject();
        auto typ=string(x["type"].GetString());
        if(typ=="join"){
            joinHook={"",string(x["cmd"].GetString())};
            continue;
        }
        if(typ=="define"){
            defcmds.insert({string(x["name"].GetString()),(CMD){string(x["cond"].GetString()),string(x["cmd"].GetString())}});
            continue;
        }
        if(typ=="timer"){
            timers.push_back({x["time"].GetInt(),x["shift"].GetInt(),{"",x["cmd"].GetString()}});
        }
    }
}
void cmdhelp_init(std::list<string>& modlist){
    load();
    register_cmd("c",fp(oncmd),"显示CMD GUI或运行CMD");
    register_cmd("reload_cmd",fp(load),"reload cmds",1);
    reg_player_join(join);
    printf("[CMDHelp] loaded!\n");
    load_helper(modlist);
}