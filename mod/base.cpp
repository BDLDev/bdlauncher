#include<cstdio>
#include<list>
#include<forward_list>
#include<string>
#include<unordered_map>
#include"../cmdhelper.h"
#include"../myhook.h"
#include<vector>
#include"minecraft/level/Level.h"
#include"minecraft/actor/Player.h"
#include"minecraft/actor/ItemActor.h"
#include"minecraft/core/GameMode.h"
#include"minecraft/packet/TextPacket.h"
#include"minecraft/item/ItemStack.h"
#include"minecraft/actor/PlayerInventoryProxy.h"
#include"minecraft/item/Item.h"
#include"seral.hpp"
#include <sys/stat.h>
#include<unistd.h>
#include <sys/stat.h>
#include"money.h"
#include<dlfcn.h>
using std::string;
using std::list;
#include"base.h"

typedef int(*hook_1_fn)(Player* a0,Actor & a1);
static list<void*> ev_attack;
void reg_attack(void* a) {
    ev_attack.push_back(a);
}
static int onEvent_attack(Player* a0,Actor & a1) {
    for(auto i:ev_attack) {
        int res=((hook_1_fn)i)(a0,a1);
        if(res==0) return 0;
    }
    return 1;
}
static struct hook_1 {
    hook_1_fn orig;
    static uint64_t onuse(Player* a0,Actor & a1);
    hook_1() {
        orig=(hook_1_fn)MyHook(fpm(Player::attack),fp(hook_1::onuse));
    }
} __hook_1;
uint64_t hook_1::onuse(Player* a0,Actor & a1) {
    int res=onEvent_attack(a0,a1);
    if(!res) {
        return 0;
    } else {
        return __hook_1.orig(a0,a1);
    }
}


typedef int(*hook_2_fn)(Actor* a0,ItemActor & a1);
static list<void*> ev_pickup;
void reg_pickup(void* a) {
    ev_pickup.push_back(a);
}
static int onEvent_pickup(Actor* a0,ItemActor & a1) {
    for(auto i:ev_pickup) {
        int res=((hook_2_fn)i)(a0,a1);
        if(res==0) return 0;
    }
    return 1;
}
static struct hook_2 {
    hook_2_fn orig;
    static uint64_t onuse(Actor* a0,ItemActor & a1);
    hook_2() {
        orig=(hook_2_fn)MyHook(fpm(Actor::pickUpItem),fp(hook_2::onuse));
    }
} __hook_2;
uint64_t hook_2::onuse(Actor* a0,ItemActor & a1) {
    int res=onEvent_pickup(a0,a1);
    if(!res) {
        return 0;
    } else {
        return __hook_2.orig(a0,a1);
    }
}


typedef int(*hook_3_fn)(GameMode* a0,ItemStack & a1);
static list<void*> ev_useitem;
void reg_useitem(void* a) {
    ev_useitem.push_back(a);
}
static int onEvent_useitem(GameMode* a0,ItemStack & a1) {
    for(auto i:ev_useitem) {
        int res=((hook_3_fn)i)(a0,a1);
        if(res==0) return 0;
    }
    return 1;
}
static struct hook_3 {
    hook_3_fn orig;
    static uint64_t onuse(GameMode* a0,ItemStack & a1);
    hook_3() {
        orig=(hook_3_fn)MyHook(fpm(GameMode::useItem),fp(hook_3::onuse));
    }
} __hook_3;
uint64_t hook_3::onuse(GameMode* a0,ItemStack & a1) {
    int res=onEvent_useitem(a0,a1);
    if(!res) {
        return 0;
    } else {
        return __hook_3.orig(a0,a1);
    }
}


typedef int(*hook_4_fn)(GameMode* a0,ItemStack & a1,BlockPos const& a2,unsigned char a3,Vec3 const& a4,Block const* a5);
static list<void*> ev_useitemon;
void reg_useitemon(void* a) {
    ev_useitemon.push_back(a);
}
static int onEvent_useitemon(GameMode* a0,ItemStack & a1,BlockPos const& a2,unsigned char a3,Vec3 const& a4,Block const* a5) {
    for(auto i:ev_useitemon) {
        int res=((hook_4_fn)i)(a0,a1,a2,a3,a4,a5);
        if(res==0) return 0;
    }
    return 1;
}
static struct hook_4 {
    hook_4_fn orig;
    static uint64_t onuse(GameMode* a0,ItemStack & a1,BlockPos const& a2,unsigned char a3,Vec3 const& a4,Block const* a5);
    hook_4() {
        orig=(hook_4_fn)MyHook(fpm(GameMode::useItemOn),fp(hook_4::onuse));
    }
} __hook_4;
uint64_t hook_4::onuse(GameMode* a0,ItemStack & a1,BlockPos const& a2,unsigned char a3,Vec3 const& a4,Block const* a5) {
    int res=onEvent_useitemon(a0,a1,a2,a3,a4,a5);
    if(!res) {
        return 0;
    } else {
        return __hook_4.orig(a0,a1,a2,a3,a4,a5);
    }
}


typedef int(*hook_5_fn)(GameMode* a0,BlockPos const& a1,unsigned char a2);
static list<void*> ev_build;
void reg_build(void* a) {
    ev_build.push_back(a);
}
static int onEvent_build(GameMode* a0,BlockPos const& a1,unsigned char a2) {
    for(auto i:ev_build) {
        int res=((hook_5_fn)i)(a0,a1,a2);
        if(res==0) return 0;
    }
    return 1;
}
static struct hook_5 {
    hook_5_fn orig;
    static uint64_t onuse(GameMode* a0,BlockPos const& a1,unsigned char a2);
    hook_5() {
        orig=(hook_5_fn)MyHook(fpm(GameMode::buildBlock),fp(hook_5::onuse));
    }
} __hook_5;
uint64_t hook_5::onuse(GameMode* a0,BlockPos const& a1,unsigned char a2) {
    int res=onEvent_build(a0,a1,a2);
    if(!res) {
        return 0;
    } else {
        return __hook_5.orig(a0,a1,a2);
    }
}


typedef int(*hook_6_fn)(GameMode* a0,BlockPos const& a1,unsigned char a2);
static list<void*> ev_destroy;
void reg_destroy(void* a) {
    ev_destroy.push_back(a);
}
static int onEvent_destroy(GameMode* a0,BlockPos const& a1,unsigned char a2) {
    for(auto i:ev_destroy) {
        int res=((hook_6_fn)i)(a0,a1,a2);
        if(res==0) return 0;
    }
    return 1;
}
static struct hook_6 {
    hook_6_fn orig;
    static uint64_t onuse(GameMode* a0,BlockPos const& a1,unsigned char a2);
    hook_6() {
        orig=(hook_6_fn)MyHook(fpm(GameMode::destroyBlock),fp(hook_6::onuse));
    }
} __hook_6;
uint64_t hook_6::onuse(GameMode* a0,BlockPos const& a1,unsigned char a2) {
    int res=onEvent_destroy(a0,a1,a2);
    if(!res) {
        return 0;
    } else {
        return __hook_6.orig(a0,a1,a2);
    }
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

static void*(*tcmd)(void*);
static TeleportCommand cmd_p;
extern "C" {
    void base_init(list<string>& modlist);
}
extern void load_helper(list<string>& modlist);
/* void* hktp(void* thi){
    printf("[DBG] hook tp\n");
    void* res=tcmd(thi);
    cmd_p=(typeof(cmd_p))res;
    return res;
}*/
void TeleportA(Actor& a,Vec3 b,AutomaticID<Dimension,int> c) {
    /* cmd_p.teleport(a,b,nullptr,c);
    cmd_p.teleport(a,b,nullptr,c);*/
    if(a.getDimensionId()!=c) {
        a.changeDimension(c,false);
    }
    cmd_p.teleport(a,b,nullptr,c);
    cmd_p.teleport(a,b,nullptr,c);
}
void KillActor(Actor* a) {
    (*((void(**)(Actor*))((*(char**)a)+0x708)))(a);
}
Player* getplayer_byname(const string& name) {
    Minecraft* mc=getMC();
    Level* lv=mc->getLevel();
    Player* rt=NULL;
    lv->forEachPlayer([&](Player& tg)->bool{
        //printf("name %s\n",tg.getName().c_str());
        if(tg.getName()==name) {
            rt=&tg;
            return false;
        }
        return true;
    });
    return rt;
}
Player* getplayer_byname2(const string& name) {
    Minecraft* mc=getMC();
    Level* lv=mc->getLevel();
    Player* rt=NULL;
    lv->forEachPlayer([&](Player& tg)->bool{
        string bf=tg.getName();
#define min(a,b) ((a)<(b)?(a):(b))
        int sz=min(tg.getName().size(),name.size());
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
static string sname("Server");
MCRESULT runcmd(const string& a) {
    ServerCommandOrigin* b=new ServerCommandOrigin(sname,*(ServerLevel*)getMC()->getLevel(),(CommandPermissionLevel)5);
    return getMC()->getCommands()->requestCommandExecution(std::unique_ptr<CommandOrigin>((CommandOrigin*)b),a,4,1);
}
void base_init(list<string>& modlist)
{
    printf("[MOD/BASE] loaded!\n");
    load_helper(modlist);
}
