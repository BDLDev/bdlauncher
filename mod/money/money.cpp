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
using std::string;
using std::to_string;
extern "C" {
    void money_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
static std::unordered_map<string,int> moneys;
struct shop {
    int mon;
    string ite;
    int amo;
    static string tostr(const shop& a) {
        char buf[32768];
        int ptr=0;
        putint(buf,ptr,a.mon);
        putint(buf,ptr,a.amo);
        putstr(buf,ptr,a.ite);
        return string(buf,ptr);
    }
    static void fromstr(const string& b,shop& a) {
        const char* buf=b.c_str();
        int ptr=0;
        getint(buf,ptr,a.mon);
        getint(buf,ptr,a.amo);
        a.ite=getstr(buf,ptr);
    }
};
static std::unordered_map<string,shop> shops;
static int shopmod=0;
static void save() {
    char* bf;
    int sz=maptomem(moneys,&bf,h_str2str,h_int2str);
    mem2file("data/money/money.db",bf,sz);
    if(shopmod) {
        sz=maptomem(shops,&bf,h_str2str,shop::tostr);
        mem2file("data/money/shop.db",bf,sz);
    }
}
static void load() {
    register_shutdown(fp(save));
    mkdir("data",S_IRWXU);
    mkdir("data/money",S_IRWXU);
    char* buf;
    int sz;
    struct stat tmp;
    if(stat("data/money/money.db",&tmp)==-1) {
        shopmod=1;
        save();
    }
    file2mem("data/money/money.db",&buf,sz);
    memtomap(moneys,buf,h_str2str_load,h_str2int);
    file2mem("data/money/shop.db",&buf,sz);
    memtomap(shops,buf,h_str2str_load,shop::fromstr);
}

int get_money(const string& pn) {
    /*if(moneys.count(pn)==0) moneys[pn]=50; //TODO:init money
    return moneys[pn];*/
    //lazy init
    return moneys.count(pn)==0?50:moneys[pn];
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
        outp.addMessage(string(buf));
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
        outp.addMessage(string(buf));
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
            outp.addMessage("§e[Money system] 扣除完毕");
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
        if(mon<=0||mon>10000) {
            outp.error("[Money system] 输入数值过大或过小(最大转账数10000，更大请分次转)");
        } else {
            if(red_money(pl,mon)) {
                add_money(pl2,mon);
                char msg[1000];
                sprintf(msg,"§e[Money system] 你给了 %s %d 余额",pl2.c_str(),mon);
                outp.addMessage(string(msg));
            } else {
                outp.error("[Money system] Sorry，转账失败，请检查你的余额是否足够。");
            }
        }
    }
     if(a[0]=="help") {
        outp.error("经济系统命令列表:\n/money query ——查询自己余额\n/money pay 玩家ID 余额 ——给玩家打钱");
    }
}

static void oncmd2(std::vector<string>& a,CommandOrigin & b,CommandOutput &outp) {
    ARGSZ(1)
    if(a[0]=="add" && (int)b.getPermissionsLevel()>0) {
        ARGSZ(5)
        shop sk;
        sk.ite=a[2]; //物品英文名
        sk.amo=atoi(a[3].c_str()); //数量
        sk.mon=atoi(a[4].c_str()); //价格
        if(sk.amo==0) {
            outp.error("[Shop] 你开心就好");
            return;
        }
        shops[a[1]]=sk;
        shopmod=1;
        //save();
        outp.success("§e[Shop] 添加项目: 项目名: "+a[1]+"  物品英文名: "+a[2]+ "  数量: "+a[3]+"  价格: "+a[4]);
    }
    if(a[0]=="del" && (int)b.getPermissionsLevel()>0) {
        ARGSZ(2)
        shops.erase(a[1]);
        shopmod=1;
        // save();
        outp.success("§e[Shop] 删除了物品: "+a[1]);
    }
    if(a[0]=="ls") {
        outp.success("§e商店项目列表:");
        for(auto i:shops) {
            shop& sk=i.second;
            char buf[11451];
            sprintf(buf,"§e项目名: %s  物品英文名: %s  数量: %d  价格: %d",i.first.c_str(),sk.ite.c_str(),sk.amo,sk.mon);
            outp.addMessage(string(buf));
        }
        outp.success("§eTip: 数量为负数的是回收商店");
    }
    if(a[0]=="buy") { //购买商店
        ARGSZ(2)
        if(!shops.count(a[1])) { //如果商店不存在物品
            outp.error("§e[Shop] 商店不存在此项目");
            return;
        }
        const shop& sp=shops[a[1]];
        if(sp.amo>0) { //判断物品数量是否大于0，否则发送提示
            if(red_money(b.getName(),sp.mon)) { //扣除金钱，如果失败则返回金币不足
                runcmd(("give "+b.getName()+" "+sp.ite+" "+to_string(sp.amo)));
                outp.success("§e[Shop] 成功购买了 "+to_string(sp.amo)+" 个 "+sp.ite);   
            } else {
                outp.error("[Shop] 金币不足");
            }
        } else {
            outp.error("[Shop] 你应该使用/shop sell");
        }
        return;
    }
    if(a[0]=="sell") { //出售商店
        ARGSZ(2)
        if(!shops.count(a[1])) { //如果商店不存在物品
            outp.error("§e[Shop] 商店不存在此项目");
            return;
        }
        const shop& sp=shops[a[1]];
        if(sp.amo<0) { //判断物品数量是否小于0，否则发送提示
            auto res=runcmd((string("clear ")+b.getName()+string(" ")+sp.ite+string(" 0 ")+to_string(sp.amo*-1)));
            if(res.isSuccess()) {
                add_money(b.getName(),sp.mon);
                outp.success("§e[Shop] 成功出售了 "+to_string(sp.amo*-1)+" 个 "+sp.ite);
                return;
            } else {
                outp.error("[Shop] 物品不足");
            }
        } else {
            outp.error("[Shop] 你应该使用/shop buy");
        }
        return;
    }
    if(a[0]=="help") {
        outp.error("§e商店指令列表:\n/shop buy 项目名 ——购买指定项目中的物品\n/shop sell 项目名 ——将指定项目中的物品出售\n/shop ls ——查看项目列表");
    }
}

void money_init(std::list<string>& modlist) {
    printf("[MONEY&SHOP] loaded!\n");
    load();
    register_cmd("money",(void*)oncmd,"经济系统");
    register_cmd("shop",(void*)oncmd2,"商店");
    load_helper(modlist);
}
