#include <cstdio>
#include <string>
#include <unordered_map>
#include "cmdhelper.h"
#include <vector>
#include <Loader.h>
#include <MC.h>
#include <unistd.h>
#include <cstdarg>

#include "base.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using std::string;
using std::unordered_map;

extern "C"
{
    BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);
LDBImpl db("data_v2/bossbar");
struct VEntBase{
    unsigned long eid;
    virtual void packto(DataStream &ds) const=0;
    virtual void unpack(DataStream &ds)=0;
    virtual void sendTo(ServerPlayer* sp)=0;
    virtual void onClick(ServerPlayer* sp)=0;
};
struct FText:VEntBase
{
    int x, y, z;
    int dim;
    string text;
    MyPkt pk=MyPkt(12, [this](void *, BinaryStream &bs) {
        bs.writeUnsignedInt64(eid);
        bs.writeUnsignedInt64(114514); //uuid
        bs.writeStr(text);           //username
        bs.writeUnsignedVarInt64(114514);
        bs.writeUnsignedVarInt64(114514);
        bs.writeStr("wtfwtf"); //platid
        bs.writeVec3({x,y,z});
        bs.writeVec3({0, 0, 0});
        bs.writeVec3({0, 0, 0});
        bs.writeUnsignedVarInt(0); //item
        bs.writeUnsignedInt(4);
        bs.writeUnsignedVarInt(4);
        bs.writeUnsignedVarInt(4);
        bs.writeStr(text);
        bs.writeUnsignedVarInt(38);
        bs.writeUnsignedVarInt(3);
        bs.writeFloat(0.001);
        bs.writeUnsignedVarInt(53);
        bs.writeUnsignedVarInt(3);
        bs.writeFloat(0.001);
        bs.writeUnsignedVarInt(54);
        bs.writeUnsignedVarInt(3);
        bs.writeFloat(0.001);
        for (int i = 0; i < 5; ++i)
            bs.writeUnsignedVarInt(0);
        bs.writeSignedInt64(114514);
        bs.writeUnsignedVarInt(0);
        bs.writeStr("114514");
        bs.writeSignedInt(114514);
    });

    void packto(DataStream &ds) const
    {
        ds << x << y << z << eid << text << dim;
    }
    void unpack(DataStream &ds)
    {
        ds >> x >> y >> z >> eid >> text >> dim;
    }
    void sendTo(ServerPlayer* sp){
        sp->sendNetworkPacket(pk);
    }
    void onClick(ServerPlayer* sp){
    }
};
unordered_map<unsigned long,vector<std::unique_ptr<VEntBase> > > ents;
THook(void*,_ZN5Level13onNewChunkForER6PlayerR10LevelChunk,ServerLevel* sv,ServerPlayer* sp,LevelChunk* lc){
    return original(sv,sp,lc);
}
const unsigned long bbid=1145141919ull;
void MoveBB(ServerPlayer* sp){
    MyPkt pk(0x12,[&](void*,BinaryStream& bs){
        bs.writeUnsignedVarInt64(bbid);
        bs.writeByte(3);
        auto& pos=sp->getPos();
        bs.writeVec3({pos.x,-10,pos.z});
        bs.writeUnsignedInt(0); //3*bytes
    });
    sp->sendNetworkPacket(pk);
}
void SendBB(ServerPlayer* sp,string_view bbar,bool show=true){
    MyPkt pk(0x4a,[&](void*,BinaryStream& bs){
        bs.writeUnsignedVarInt64(bbid);
        bs.writeUnsignedVarInt(show?0:2);
        bs.writeStr(bbar);
        bs.writeFloat(0.5);
    });
    sp->sendNetworkPacket(pk);
}
void CreateEntBB(ServerPlayer* sp){
    MyPkt pk(0x0d,[&](void*,BinaryStream& bs){
        bs.writeUnsignedVarInt64(bbid);
        bs.writeUnsignedVarInt64(bbid);
        bs.writeStr("minecraft:pig");
        auto& pos=sp->getPos();
        bs.writeVec3({pos.x,-10,pos.z});
         bs.writeVec3({0,0,0});
         bs.writeVec3({0,0,0});
         bs.writeUnsignedVarInt(0); //attr
         bs.writeUnsignedVarInt(0); //meta
         bs.writeUnsignedVarInt(0); //link
    });
    sp->sendNetworkPacket(pk);
}
static void cm(argVec &a, CommandOrigin const &b, CommandOutput &c)
{
    FText ft;
    auto sp=getSP(b.getEntity());
    auto pos=sp->getPos();
    /*ft.x=pos.x;ft.y=pos.y;ft.z=pos.z;
    ft.eid=1919810;
    ft.text="weddwedew";
    ft.sendTo(sp);*/
    if(a[0]=="all"){
        auto* x=getSrvLevel()->getUsers();
        for(auto& i:*x){
            auto sp=i.get();
            SendBB(sp,"",false);
            CreateEntBB(sp);
            SendBB(sp,a[1],true);
        }
        c.success();
        return;
    }
    sp=getuser_byname(a[0]);
    if(sp){
        SendBB(sp,"",false);
        CreateEntBB(sp);
        SendBB(sp,a[1],true);
        c.success();
    }
}
static void cm2(argVec &a, CommandOrigin const &b, CommandOutput &c)
{
    if(a[0]=="all"){
        auto* x=getSrvLevel()->getUsers();
        for(auto& i:*x){
            auto sp=i.get();
            SendBB(sp,"",false);
        }
        c.success();
        return;
    }
    auto sp=getuser_byname(a[0]);//getSP(b.getEntity());
    if(sp){
        SendBB(sp,"",false);
        c.success();
    }
}
static string PinnedBBar;
static void cm_pin(argVec &a, CommandOrigin const &b, CommandOutput &c)
{  
    if(a[0]=="unpin") {
        PinnedBBar.clear(); 
        db.Del("pinned");
        runcmd("hidebb all");
    }else{
        SPBuf<1024> sb;
        sb.write("sendbb all \"");
        sb.write(a[0]);
        sb.write("\"");
        runcmd(sb.get());
        PinnedBBar=a[0];
        db.Put("pinned",a[0]);
    }
    c.success();
}
static void onJoin(ServerPlayer* sp){
    if(PinnedBBar.size()){
        CreateEntBB(sp);
        SendBB(sp,PinnedBBar,true);
    }
}
void mod_init(std::list<string> &modlist)
{
db.Get("pinned",PinnedBBar);
    printf("[BossBar] Loaded " BDL_TAG "\n");
    register_cmd("sendbb", cm, "send bb", 1);
    register_cmd("hidebb", cm2, "hide bb", 1);
    register_cmd("pinbb", cm_pin, "pin bb", 1);
    reg_player_join(onJoin);
    load_helper(modlist);
}
