#include<Loader.h>
#include<MC.h>
#include"../base/base.h"
#include"rapidjson/document.h"
#include"rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include"../money/money.h"
#include<fstream>
#include<list>

using namespace std;
using namespace rapidjson;

extern "C" {
   BDL_EXPORT void mod_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
struct Slot{
    string owner;
    int price; //0 means no owner
    Slot(){price=0;}
    Slot(string a,int b){
        owner=a,price=b;
    }
};
static void save();
struct Chest{
    Slot slots[27];
    int x,y,z;
    int get_price(int slot){
        return slots[slot].price;
    }
    bool do_buy(const string& ply,int slot){
        if(slot>=27) return false;
        if(slots[slot].price==0) return false;
        int price=slots[slot].price;
        if(red_money(ply,price)){
            add_money(slots[slot].owner,price);
            slots[slot].price=0;
            slots[slot].owner=ply;
            save();
            return true;
        }else{
            return false;
        }
    }
    bool do_add(const string& ply,int price,int slot){
        if(slot>=27) return false;
        if(get_price(slot)) return false;
        slots[slot].owner=ply;
        slots[slot].price=price;
        save();
        return true;
    }
};
list<Chest> lc;
static int DIRTY;
static void r_save();
static void save(){
    DIRTY++;
    //if(DIRTY==3){
        r_save();
    //}
}
static void r_save(){
    if(!DIRTY) return;
    DIRTY=0;
    Document dc;
    dc.SetArray();
    for(auto& i:lc){
        Value vv(kObjectType);
        vv.AddMember("x",i.x,dc.GetAllocator());
        vv.AddMember("y",i.y,dc.GetAllocator());
        vv.AddMember("z",i.z,dc.GetAllocator());
        Value va(kArrayType);
        for(int j=0;j<27;++j){
            Value vs(kArrayType);
            Value vss(kStringType);
            vss.SetString(i.slots[j].owner.c_str(),dc.GetAllocator());
            vs.PushBack(vss,dc.GetAllocator());
            vs.PushBack(i.slots[j].price,dc.GetAllocator());
            va.PushBack(vs,dc.GetAllocator());
        }
        vv.AddMember("slots",va,dc.GetAllocator());
        dc.PushBack(vv,dc.GetAllocator());
    }
    StringBuffer buf;
    Writer<StringBuffer> writer(buf);
    dc.Accept(writer);
    ofstream ff;
    ff.open("data/chestshop.json",ios::trunc|ios::out);
    ff.write(buf.GetString(),buf.GetSize());
    ff.close();
}
char buf[1024*1024*16];
static void load(){
    Document dc;
    ifstream ff;
    ff.open("data/chestshop.json",ios::in);
    buf[ff.readsome(buf,1024*1024*16)]=0;
    ff.close();
    if(strlen(buf)==0){
        strcpy(buf,"[]");
    }
    if(dc.ParseInsitu(buf).HasParseError()){
        printf("[ChestShop] JSON ERROR pos: %d type: %s!\n",dc.GetErrorOffset(),GetParseErrorFunc(dc.GetParseError()));
        exit(1);
    }
    if(dc.IsArray()){
        for(auto& i:dc.GetArray()){
            Chest ch;
            ch.x=i["x"].GetInt();
            ch.y=i["y"].GetInt();
            ch.z=i["z"].GetInt();
            int ct=0;
            for(auto& j:i["slots"].GetArray()){
                ch.slots[ct++]=Slot(string(j.GetArray()[0].GetString()),j.GetArray()[1].GetInt());
            }
            lc.emplace_back(ch);
        }
    }
}

unordered_map<string,int> ply_select; 
unordered_map<string,int> ply_price;
unordered_map<string,Chest*> sessions;
unordered_map<string,Chest*> last_sess;

Chest* fetchChest(int x,int y,int z){
    for(auto& i:lc){
        if(i.x==x && i.y==y && i.z==z) return &i;
    }
    return nullptr;
}
THook(void*,_ZN15ChestBlockActor8stopOpenER6Player,BlockActor& ac,Player& pl){
    auto& pos=ac.getPosition();
    Chest* gch=fetchChest(pos.x,pos.y,pos.z);
    if(gch){
        sessions.erase(pl.getName());
        last_sess.emplace(pl.getName(),gch);
    }
    return original(ac,pl);
}
THook(void*,_ZN15ChestBlockActor9startOpenER6Player,BlockActor& ac,Player& pl){
    auto& pos=ac.getPosition();
    //printf("start pos %d %d %d\n",pos.x,pos.y,pos.z);
    Chest* gch=fetchChest(pos.x,pos.y,pos.z);
    if(gch){
        sessions.emplace(pl.getName(),gch);
    }
    return original(ac,pl);
}
THook(unsigned long,_ZNK20InventoryTransaction11executeFullER6Playerb,void* _thi,Player &player, bool b){
    const string& name=player.getName();
    auto it=sessions.find(name);
    if(it==sessions.end()) return original(_thi,player,b);
    auto chest=it->second;
    auto& a=*((unordered_map<InventorySource,vector<InventoryAction> >*)_thi);
    int IIDs=-1;
    int pushcnt=0,pullcnt=0;
    int lastslot;
    string pullstr;
    for(auto& i:a){
    for(auto& j:i.second){
        auto cid=j.getSource().getContainerId();
        if(cid!=0){
            if(IIDs==-1){
                IIDs=cid;
            }else{
                if(IIDs!=cid){
                    sendText(&player,"invlaid operation");
                    return 6;
                }
            }
        }
        auto fit=j.getFromItem();
        auto tit=j.getToItem();
        auto slot=j.getSlot();
        if(cid!=0){
            //chest oper
            if(fit->isNull() && !tit->isNull()){
                //push item
                pushcnt++;
                lastslot=slot;
            }else{
                if(!fit->isNull() && tit->isNull()){
                    //pull item
                    pullcnt++;
                    lastslot=slot;
                    pullstr=fit->toString();
                }else{
                    //invlaid
                    sendText(&player,"invlaid operation");
                    return 6;
                }
            }
        }
        //printf("cid %d flg %d src %d slot %u get %d %s %s\n",j.getSource().getContainerId(),j.getSource().getFlags(),j.getSource().getType(),j.getSlot(),i.first.getContainerId(),j.getFromItem()->toString().c_str(),j.getToItem()->toString().c_str());
    }
    }
    if((pushcnt+pullcnt)!=1 || lastslot<0 || lastslot>26){
        sendText(&player,"invlaid operation");
        return 6;
    }
    if(pushcnt){
        auto it=ply_price.find(name);
        if(it==ply_price.end()){
            sendText(&player,"invlaid operation");
            return 6;
        }
        int price=it->second;
        ply_price.erase(it);
        if(price<=0) return 6;  
        if(chest->slots[lastslot].owner!=""){
            sendText(&player,"this slot owned by "+name);
            return 6;
        }
        chest->slots[lastslot]=Slot(name,price);
        save();
        return original(_thi,player,b);
    }
    if(pullcnt){
        auto& x=chest->slots[lastslot];
        if(x.price==0){
            //no owner bought slot
            if(x.owner!=name){
                sendText(&player,"not your slot");
                return 6;
            }else{
                x.owner=""; //release slot
                save();
                return original(_thi,player,b);
            }
        }
        char buf[1000];
        sprintf(buf,"item %s by %s price %d,use /cshop buy to buy it",pullstr.c_str(),x.owner.c_str(),x.price);
        sendText(&player,buf);
        ply_select[name]=lastslot; //buy
        return 6;
    }
    return original(_thi,player,b);
    /*
    cid 5 flg 0 src 0 slot 0 get 5 64 x Chest(54)@0 0 x (0)@0
cid 0 flg 0 src 0 slot 8 get 0 0 x (0)@0 64 x Chest(54)@0
cid 0 flg 0 src 0 slot 8 get 0 64 x Chest(54)@0 0 x (0)@0
cid 5 flg 0 src 0 slot 26 get 5 0 x (0)@0 64 x Chest(54)@0
cid 5 flg 0 src 0 slot 26 get 5 64 x Chest(54)@0 0 x (0)@0
cid 5 flg 0 src 0 slot 14 get 5 0 x (0)@0 64 x Chest(54)@0
cid 5 flg 0 src 0 slot 14 get 5 64 x Chest(54)@0 0 x (0)@0
cid 0 flg 0 src 0 slot 2 get 0 0 x (0)@0 64 x Chest(54)@0
*/
}

static void oncmd(argVec& a,CommandOrigin const & b,CommandOutput &outp){
    ARGSZ(1)
    auto name=b.getName();
    if(a[0]=="buy"){
        if(!ply_select.count(name) || sessions.count(name) || !last_sess.count(name)){
            outp.error("not selected");
            return;
        }
        if(last_sess[name]->do_buy(name,ply_select[name])){
            outp.success("ok");
            ply_select.erase(name);
            return;
        }else{
            outp.error("failed");
            ply_select.erase(name);
            return;
        }
    }
    if(a[0]=="sell"){
        ARGSZ(2)
        int price=atoi(a[1]);
        if(price<=0){
            outp.error("money must >0");
            return;
        }
        ply_price.emplace(b.getName(),price);
        outp.success();
    }
    if(a[0]=="set"){
        if((int)b.getPermissionsLevel()<1) return;
        ply_price.emplace(b.getName(),-114514); //flag for select chest
    }
}
static bool handle_u(GameMode* a0,ItemStack * a1,BlockPos const* a2,BlockPos const* dstPos,Block const* a5){
    auto nm=a0->getPlayer()->getName();
    auto it=ply_price.find(nm);
    ServerPlayer* sp=a0->getPlayer();
    if(it==ply_price.end()) return 1;
    int state=it->second;
    if(state==-114514){
        Chest ch;
        ch.x=a2->x;
        ch.y=a2->y;
        ch.z=a2->z;
        lc.emplace_back(ch);
        save();
        sendText(sp,"okay!add shop chest");
        ply_price.erase(it);
        return 0;
    }
    return 1;
}
void mod_init(std::list<string>& modlist){
    load();
    reg_useitemon(handle_u);
    register_shutdown(fp(r_save));
    printf("[ChestShop] Loaded\n");
    register_cmd("cshop",oncmd);
    load_helper(modlist);
}