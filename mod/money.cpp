#include<cstdio>
#include<list>
#include<string>
#include<unordered_map>
#include"../cmdhelper.h"
#include"base.h"
#include<vector>
#include"minecraft/level/Level.h"
#include"seral.hpp"
#include <sys/stat.h>
#include<unistd.h>
#include <sys/stat.h>
#include<memory>
#include"money.h"
#include<dlfcn.h>
using std::string;
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
static void save() {
    char* bf;
    int sz=maptomem(moneys,&bf,h_str2str,h_int2str);
    mem2file("data/money/money.db",bf,sz);
    sz=maptomem(shops,&bf,h_str2str,shop::tostr);
    mem2file("data/money/shop.db",bf,sz);
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
    file2mem("data/money/shop.db",&buf,sz);
    memtomap(shops,buf,h_str2str_load,shop::fromstr);
}

int get_money(const string& pn) {
    if(moneys.count(pn)==0) moneys[pn]=50; //TODO:init money
    return moneys[pn];
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
        sk.ite=a[2];
        sk.amo=atoi(a[3].c_str());
        sk.mon=atoi(a[4].c_str());
        shops[a[1]]=sk;
        //save();
        outp.success("添加成功");
    }
    if(a[0]=="del" && (int)b.getPermissionsLevel()>0) {
        ARGSZ(2)
        shops.erase(a[1]);
        // save();
        outp.success("删除成功");
    }
    if(a[0]=="ls") {
        for(auto i:shops) {
            shop& sk=i.second;
            char buf[11451];
            sprintf(buf,"买家 %s · 物品 %s · 库存 %d · 价格 %d",i.first.c_str(),sk.ite.c_str(),sk.amo,sk.mon);
            outp.addMessage(string(buf));
        }
        outp.success("done");
    }
    if(a[0]=="buy") {
        ARGSZ(2)
        if(!shops.count(a[1])) outp.error("不存在的商店");
        const shop& sp=shops[a[1]];
        if(sp.amo<0) {
            //sell
            int mam=-sp.amo;
            auto res=runcmd((string("clear ")+b.getName()+string(" ")+sp.ite+string(" 0 ")+std::to_string(sp.amo-1)));
            if(!res.isSuccess()) {
                outp.error("不足");
                return;
            }
            res=runcmd((string("clear ")+b.getName()+string(" ")+sp.ite+string(" 0 1")));
            if(!res.isSuccess()) {
                outp.error("不足");
                return;
            }
            add_money(b.getName(),mam);
        } else {
            if(!red_money(b.getName(),sp.amo)) {
                outp.error("金币不足");
                return;
            }
            runcmd(("give "+b.getName()+" "+sp.ite+" "+std::to_string(sp.amo)));
        }
    }
}
void money_init(std::list<string>& modlist) {
    printf("[MONEY&SHOP] loaded!\n");
    load();
    register_cmd("money",(void*)oncmd,"经济");
    register_cmd("shop",(void*)oncmd2,"商店");
    load_helper(modlist);
}
