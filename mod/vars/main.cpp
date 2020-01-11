#include<Loader.h>
#include<MC.h>
#include"../base/base.h"
#include"../cmdhelper.h"
#include"../base/base.h"

extern "C" {
   BDL_EXPORT void mod_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
LDBImpl db("data_v2/vars");
static void oncmd(argVec& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
    if(a[0]=="ls"){
        if(a.size()==1) a.push_back(b.getName());
        string name(a[1]);
        string val;
        DataStream ds;
        unordered_map<string,int> list;
        if(db.Get(a[1],ds.dat)){
            ds>>list;
            for(auto& i:list){
                outp.addMessage(i.first+":"+std::to_string(i.second));
            }
            outp.success();
            return;
        }
        outp.error("no tags");
    }
    if(!isOp(b)) return;
    if(a[0]=="set"){
        ARGSZ(4)
        string name(a[1]);
        string key(a[2]);
        string op(a[3]);
        int vv=0;
        string val;
        unordered_map<string,int> list;
        DataStream ds;
        if(db.Get(name,ds.dat)) ds>>list;
        vv=list[key];
        if(!isdigit(op[0])){
            vv+=atoi(op.c_str());
        }else{
            vv=atoi(op.c_str());
        }
        list[key]=vv;
        ds.reset();
        ds<<list;
        db.Put(name,ds.dat);
    }
    if(a[0]=="test"){
        ARGSZ(5)
        string name(a[1]);
        string key(a[2]);
        string op(a[3]);
        int op2=atoi(a[4]);
        int vv=0;
        string val;
        DataStream ds;
        unordered_map<string,int> list;
        if(db.Get(name,ds.dat)) ds>>list;
        vv=list[key];
        if(op=="="){
            if(vv==op2){
                outp.success();
            }else{
                outp.error("failed");
            }
            return;
        }
        if(op=="!="){
            if(vv!=op2){
                outp.success();
            }else{
                outp.error("failed");
            }
            return;
        }
        if(op==">="){
            if(vv>=op2){
                outp.success();
            }else{
             outp.error("failed");
            }
            return;
        }
        if(op=="<="){
            if(vv<=op2){
                outp.success();
            }else{
                outp.error("failed");
            }
            return;
        }
        if(op==">"){
            if(vv>op2){
                outp.success();
            }else{
                outp.error("failed");
            }
            return;
        }
        if(op=="<"){
            if(vv<op2){
                outp.success();
            }else{
                outp.error("failed");
            }
            return;
        }
    }
}
void mod_init(std::list<string>& modlist){
    register_cmd("var",oncmd,"manage player vars");
    printf("[Vars] loaded! V2019-12-14\n");
    load_helper(modlist);
}
