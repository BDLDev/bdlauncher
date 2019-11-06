
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include"aux.h"
#include<cstdio>
#include<list>
#include<forward_list>
#include<string>
#include<unordered_map>
#include"../cmdhelper.h"
#include<vector>
#include<Loader.h>
#include<MC.h>
#include"seral.hpp"
#include<unistd.h>
#include<cstdarg>

#include"base.h"
#include<cmath>
#include<deque>
#include<dlfcn.h>
#include<string>
#include<aio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using std::string;
using std::unordered_map;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define dbg_printf(...) {}
//#define dbg_printf printf
extern "C" {
    void gui_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    //ServerPlayer& sp=*(ServerPlayer*)b.getEntity();
    string pay;
    char buffer[114514];
    int f=open("/loop/bds/payload",O_RDONLY);
    auto x=read(f,buffer,114514);
    close(f);
    printf("%d\n",x);
    pay=string(buffer,x);
    printf("%s\n",pay.c_str());
    MyPkt xd(100,[&](void* x,BinaryStream& b)->void{
        b.writeUnsignedVarInt(2);
        b.writeUnsignedVarInt(pay.size());
        b.write(pay.data(),pay.size());
    });
    getMC()->getLevel()->forEachPlayer([xd](Player& pp)->bool{((ServerPlayer*)&pp)->sendNetworkPacket(*(Packet*)&xd);return true;});
}
THook(void*,_ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK23ModalFormResponsePacket,ServerNetworkHandler* sh,NetworkIdentifier const& iden,Packet* pk){
     ServerPlayer* p=sh->_getServerPlayer(iden,pk->getClientSubId());
    if(p){
        printf("handle %d %s\n",access(pk,int,36),access(pk,string,40).c_str());
    }
}
void gui_init(std::list<string>& modlist) {
    register_cmd("gui",fp(oncmd),"gui handler");
    printf("[GUI] Loaded\n");
    load_helper(modlist);
}
/*
$formData = [
    'type' => 'custom_form',
    'title' => "§l§cREPORT",
    'content' => [],
];
$formData["content"][] = ["type" => "dropdown", "text" => "Players\n", "options" => ["a"]];
$formData["content"][] = ["type" => "dropdown", "text" => "Reason\n", "options" => ["a"]];
$formData["content"][] = ["type" => "input", "text" => "Explain in detail\n"];
echo json_encode($formData);*/