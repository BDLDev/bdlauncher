#include<Loader.h>
#include<MC.h>
#include"../base/base.h"
#include"rapidjson/document.h"
#include"rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include<fstream>
#include<cstdarg>
#include"../gui/gui.h"
#include<queue>
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
struct CMDForm{
    unordered_map<string,CMD> cmds;
    vector<string> ordered_cmds;
    string content;
    string title;
    void sendTo(ServerPlayer& sp){
        string nm=sp.getName();
        Form* x=new Form([this,nm](const string& s)->void{
            //printf("handle %s %s\n",nm.c_str(),s.c_str());
            if(cmds.count(s))
                cmds[s].execute(nm);
        });
        x->setContent(content);
        x->setTitle(title);
        for(auto& i:ordered_cmds)
            x->addButton(i,i);
        sendForm(sp,x);
    }
};
unordered_map<string,CMDForm> forms;
list<Timer> timers;
struct Oneshot{
    int time;
    string name,cmd;
    bool operator <(Oneshot const& a) const{
        return time<a.time;
    }
};
priority_queue<Oneshot> oneshot_timers;
CMD joinHook;
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    auto nm=b.getName();
    if(a.size()==0) a.push_back("root");
    if(forms.count(a[0])){
        auto& fm=forms[a[0]];
        fm.sendTo(*(ServerPlayer*)b.getEntity());
        outp.success();
        //outp.success("gui showed");
    }else{
        outp.error("cant find");
    }
}
static void join(ServerPlayer* sp){
    joinHook.execute(sp->getName(),false);
}
static void tick(int tk){
    for(auto& i:timers){
        if(i.chk(tk)) i.run.execute("",false);
    }
    while(!oneshot_timers.empty()){
        auto a=oneshot_timers.top();
        if(a.time<=tk){
            //printf("exec %s %s\n",a.cmd.c_str(),a.name.c_str());
            for(int i=0;i<a.cmd.size();++i)
                if(a.cmd[i]=='$') a.cmd[i]='%';
            execute_cmdchain(a.cmd,a.name,false);
            oneshot_timers.pop();
        }else{
            break;
        }
    }
}
static int tkl;
THook(void*,_ZN5Level4tickEv,Level& a){
    tkl++;
    if(tkl%20==0) tick(tkl/20);
    return original(a);
}
int menuitem;
char buf[8*1024*1024];
using namespace rapidjson;
static void load(){
    timers.clear();
    forms.clear();
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
        if(typ=="menuitem"){
            menuitem=x["itemid"].GetInt();
        }
        if(typ=="join"){
            joinHook={"",string(x["cmd"].GetString())};
        }
        if(typ=="form"){
            auto&& buttons=x["buttons"];
            auto&& cont=x["text"];
            auto&& title=x["title"];
	        auto&& name=x["name"];
            assert(buttons.IsArray());
            CMDForm cf;
            cf.title=title.GetString();
            cf.content=cont.GetString();
            for(auto& i:buttons.GetArray()){
                assert(i.IsArray());
                auto&& but=i.GetArray();
                cf.cmds.insert({but[0].GetString(),{but[1].GetString(),but[2].GetString()}});
                cf.ordered_cmds.push_back(but[0].GetString());
            }
	forms.insert({name.GetString(),cf});
        }
        if(typ=="timer"){
            timers.push_back({x["time"].GetInt(),x["shift"].GetInt(),{"",x["cmd"].GetString()}});
        }
    }
}

static bool handle_u(GameMode* a0,ItemStack * a1,BlockPos const* a2,BlockPos const* dstPos,Block const* a5){
    if(a1->getId()==menuitem){
        runcmdAs("c",a0->getPlayer());
        return 0;
    }
    return 1;
}
static void oncmd_sch(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    if((int)b.getPermissionsLevel()<1) return;
    ARGSZ(3)
    int dtime=atoi(a[0].c_str());
    string name=a[1];
    string chain=a[2];
    oneshot_timers.push({tkl/20+dtime,name,chain});
    outp.success();
}
void cmdhelp_init(std::list<string>& modlist){
    load();
    register_cmd("c",fp(oncmd),"显示CMD GUI");
    register_cmd("reload_cmd",fp(load),"reload cmds",1);
    register_cmd("sched",fp(oncmd_sch),"schedule a delayed cmd",1);
    reg_player_join(join);
    reg_useitemon(handle_u);
    printf("[CMDHelp] loaded! V2019-11-21\n");
    load_helper(modlist);
}
