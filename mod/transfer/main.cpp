#include<Loader.h>
#include<MC.h>
#include"../base/base.h"
#include"../cmdhelper.h"

extern "C" {
   BDL_EXPORT void transfer_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(2)
    MyPkt trpk(0x55,[&](void*,BinaryStream& x)->void{
        x.writeUnsignedVarInt(a[0].size());
        x.write(a[0].data(),a[0].size());
        x.writeUnsignedShort(atoi(a[1].c_str()));
    });
    ((ServerPlayer*)b.getEntity())->sendNetworkPacket(trpk);
    outp.success();
}
void transfer_init(std::list<string>& modlist){
    register_cmd("transfer",fp(oncmd),"transfer to server");
    printf("[Trans] loaded! V2019-11-21\n");
    load_helper(modlist);
}
