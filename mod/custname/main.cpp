#include<Loader.h>
#include<MC.h>
#include"../base/base.h"
extern "C" {
   BDL_EXPORT void mod_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
LDBImpl names("data_v2/CustName");
unordered_map<string,string> name_map;
THook(void*,_ZN10TextPacket10createChatERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_S7_S7_,void* a1,string* s1,string* s2,string* s3,string* s4){
    auto it=name_map.find(*s1);
    if(it!=name_map.end()){
        return original(a1,&it->second,s2,s3,s4);
    }else{
        return original(a1,s1,s2,s3,s4);
    }
}
static void load(){
    names.Iter([](string_view k,string_view v){
       name_map.emplace(k,v); 
    });
}
static void oncmd(argVec& av,CommandOrigin const& co,CommandOutput& outp){
    if(av.size()!=2) {
        outp.error("arg");
        return;
    }
    SPBuf<1024> buf;
    for(int i=0;i<av[1].size();++i){
        if(av[1][i]!='"');
            buf.buf[buf.ptr++]=av[1][i];
    }
    name_map[string(av[0])]=buf.getstr();
    names.Put(av[0],buf.get());
    outp.success("okay");
}
void mod_init(std::list<string>& modlist){
    printf("[CUSTNAME] Loaded " BDL_TAG "!\n");
    load();
    register_cmd("cname",oncmd,"custom name",1);
    load_helper(modlist);
}