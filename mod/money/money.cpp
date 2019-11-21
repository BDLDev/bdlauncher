#include<cstdio>
#include<list>
#include<string>
#include<unordered_map>
#include"../cmdhelper.h"
#include"base.h"
#include<vector>
#include<Loader.h>
#include<MC.h>
#include"seral.hpp"
#include <sys/stat.h>
#include<unistd.h>
#include <sys/stat.h>
#include<memory>
#include"money.h"
#include<dlfcn.h>
#include"rapidjson/document.h"
#include<fstream>
#include"../gui/gui.h"

using std::string;
using std::to_string;
extern "C" {
    BDL_EXPORT void money_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
static std::unordered_map<string,int> moneys;
static void save() {
    char* bf;
    int sz=maptomem(moneys,&bf,h_str2str,h_int2str);
    mem2file("data/money/money.db",bf,sz);
}
static void load() {
    register_shutdown(fp(save));
    mkdir("data",S_IRWXU);
    mkdir("data/money",S_IRWXU);
    char* buf;
    int sz;
    struct stat tmp;
    if(stat("data/money/money.db",&tmp)==-1) {
        save();
    }
    file2mem("data/money/money.db",&buf,sz);
    memtomap(moneys,buf,h_str2str_load,h_str2int);
}
int INIT_MONEY;
using namespace rapidjson;
void loadcfg(){
    Document dc;
    std::ifstream ff;
    ff.open("config/money.json",std::ios::in);
    char buf[1024*8];
    buf[ff.readsome(buf,1024*8)]=0;
    ff.close();
    if(dc.ParseInsitu(buf).HasParseError()){
        printf("[MONEY] Config JSON ERROR!\n");
        exit(1);
    }
    INIT_MONEY=dc["init_money"].GetInt();
}
int get_money(const string& pn) {
    //lazy init
    return moneys.count(pn)==0?INIT_MONEY:moneys[pn];
}
void set_money(const string& pn,int am) {
    moneys[pn]=am;
    //save();
}
bool red_money(const string& pn,int am) {
    int mo=get_money(pn);
    if(mo>=am) {
        set_money(pn,mo-am);
        return true;
    } else
    {
        return false;
    }

}
void add_money(const string& pn,int am) {
    red_money(pn,-am);
}
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
    if(a[0]=="query") {
        string dst;
        if(a.size()==2) {
            dst=a[1];
        } else {
            dst=b.getName();
        }
        char buf[1024];
        sprintf(buf,"§e[Money system] %s 的余额为 %d",dst.c_str(),get_money(dst));
        outp.addMessage(string(buf));
        outp.success();
        return;
    }
    if(a[0]=="set") {
        if((int)b.getPermissionsLevel()<1) return;
        ARGSZ(2)
        string dst;
        int amo;
        if(a.size()==3) {
            dst=a[1];
            amo=atoi(a[2].c_str());
        } else {
            dst=b.getName();
            amo=atoi(a[1].c_str());
        }
        set_money(dst,amo);
        char buf[1024];
        sprintf(buf,"§e[Money system] 成功将 %s 的余额设置为 %d",dst.c_str(),get_money(dst));
        outp.success(string(buf));
    }
    if(a[0]=="add") {
        if((int)b.getPermissionsLevel()<1) return;
        ARGSZ(2)
        string dst;
        int amo;
        if(a.size()==3) {
            dst=a[1];
            amo=atoi(a[2].c_str());
        } else {
            dst=b.getName();
            amo=atoi(a[1].c_str());
        }
        add_money(dst,amo);
        char buf[1024];
        sprintf(buf,"§e[Money system] 往 %s 的账户上添加了 %d",dst.c_str(),amo);
        outp.success(string(buf));
                auto dstp=getplayer_byname(dst);
                if(dstp)
                    sendText(dstp,"you get "+std::to_string(amo)+" money");
    }
    if(a[0]=="reduce" || a[0]=="rd") {
        if((int)b.getPermissionsLevel()<1) return;
        ARGSZ(2)
        string dst;
        int amo;
        if(a.size()==3) {
            dst=a[1];
            amo=atoi(a[2].c_str());
        } else {
            dst=b.getName();
            amo=atoi(a[1].c_str());
        }
        if(red_money(dst,amo)) {
            outp.success("§e[Money system] 扣除完毕");
                auto dstp=getplayer_byname(dst);
                if(dstp)
                    sendText(dstp,"you used "+std::to_string(amo)+" money");
        }
        else {
            outp.error("[Money system] 对方余额不足");
        }
    }
    if(a[0]=="pay") {
        ARGSZ(3)
        string pl;
        string pl2;
        int mon;
        pl=b.getName();
        pl2=a[1];
        mon=atoi(a[2].c_str());
        if(mon<=0||mon>50000) {
            outp.error("[Money system] 输入数值过大或过小(最大转账数50000，更大请分次转)");
        } else {
            if(red_money(pl,mon)) {
                add_money(pl2,mon);
                char msg[1000];
                sprintf(msg,"§e[Money system] 你给了 %s %d 余额",pl2.c_str(),mon);
                outp.success(string(msg));
                auto dstp=getplayer_byname(pl2);
                if(dstp)
                    sendText(dstp,"you get "+std::to_string(mon)+" money");
            } else {
                outp.error("[Money system] Sorry，转账失败，请检查你的余额是否足够。");
            }
        }
    }
    if(a[0]=="paygui"){
        string nm=b.getName();
        gui_ChoosePlayer((ServerPlayer*)b.getEntity(),"Choose a player to pay","Money System",[nm](const string& chosen){
            auto p=getplayer_byname(nm);
            if(p){
                gui_GetInput((ServerPlayer*)p,"How much to pay to "+chosen+"?","Money System",[chosen,nm](const string& mon){
                    auto p=getplayer_byname(nm);
                    if(p)
                        runcmdAs("money pay \""+chosen+"\" "+mon,p);
                });
            }
        });
    }
     if(a[0]=="help") {
        outp.error("经济系统命令列表:\n/money query ——查询自己余额\n/money pay 玩家ID 余额 ——给玩家打钱");
    }
}

void money_init(std::list<string>& modlist) {
    printf("[MONEY] loaded! V2019-11-21\n");
    load();
    loadcfg();
    register_cmd("money",(void*)oncmd,"经济系统");
    register_cmd("reload_money",(void*)loadcfg,"reload money cfg",1);
    load_helper(modlist);
}
