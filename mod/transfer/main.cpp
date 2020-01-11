#include<Loader.h>
#include<MC.h>
#include"../base/base.h"
#include"../cmdhelper.h"

extern "C" {
   BDL_EXPORT void mod_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
static void oncmd(argVec& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(2)
    MyPkt trpk(0x55,[&](void*,BinaryStream& x)->void{
        x.writeUnsignedVarInt(a[0].size());
        x.write(a[0].data(),a[0].size());
        x.writeUnsignedShort(atoi(a[1]));
    });
    auto sp=getSP(b.getEntity());
    if(sp){
    ((ServerPlayer*)b.getEntity())->sendNetworkPacket(trpk);
        outp.success();
    }else{
        outp.error("fucku");
    }
}
void mod_init(std::list<string>& modlist){
    register_cmd("transfer",oncmd,"transfer to server");
    printf("[Trans] loaded! V2019-12-14\n");
    load_helper(modlist);
}
