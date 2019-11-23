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
struct CMDForm{
    unordered_map<string,CMD> cmds;
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
        for(auto& i:cmds)
            x->addButton(i.first,i.first);
        sendForm(sp,x);
    }
};
unordered_map<string,CMDForm> forms;
list<Timer> timers;
CMD joinHook;
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    auto nm=b.getName();
    if(a.size()==0) a.push_back("root");
    if(forms.count(a[0])){
        auto& fm=forms[a[0]];
        fm.sendTo(*(ServerPlayer*)b.getEntity());
        outp.success("gui showed");
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
}
int tkl;
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
void cmdhelp_init(std::list<string>& modlist){
    load();
    register_cmd("c",fp(oncmd),"显示CMD GUI");
    register_cmd("reload_cmd",fp(load),"reload cmds",1);
    reg_player_join(join);
    reg_useitemon(handle_u);
    printf("[CMDHelp] loaded! V2019-11-21\n");
    load_helper(modlist);
}
