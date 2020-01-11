#include<Loader.h>
#include<MC.h>
#include"../base/base.h"
#include"rapidjson/document.h"
#include"rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include<fstream>
#include<cstdarg>

using namespace std;

extern "C" {
   BDL_EXPORT void mod_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);


static int logfd;
static int logsz;
static void initlog() {
    logfd=open("cdk.log",O_WRONLY|O_APPEND|O_CREAT,S_IRWXU);
    logsz=lseek(logfd,0,SEEK_END);
}
static void async_log(const char* fmt,...) {
    char buf[1024];
    auto x=time(0);
    va_list vl;
    va_start(vl,fmt);
    auto tim=strftime(buf,128,"[%Y-%m-%d %H:%M:%S] ",localtime(&x));
    int s=vsnprintf(buf+tim,900,fmt,vl)+tim;
    write(1,buf,s);
    write(logfd,buf,s);
    va_end(vl);
}
static void save();
unordered_map<string,string> cdks;
static void oncmd(argVec& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
    string cdk=string(a[0]);
    if(!cdks.count(cdk)) {outp.error("Invalid cdk");return;}
    auto run=cdks[cdk];
    cdks.erase(cdk);
    async_log("[CDK] %s uses CDK %s\n",b.getName().c_str(),cdk.c_str());
    execute_cmdchain(run,b.getName(),false);
    save();
    outp.success("§bYou used cdk: "+cdk+"\n");
}
using namespace rapidjson;
static void load(){
    cdks.clear();
    Document dc;
    FileBuffer fb("config/cdk.json");
    if(dc.ParseInsitu(fb.data).HasParseError()){
        printf("[CDK] JSON ERROR pos: %d type: %s!\n",dc.GetErrorOffset(),GetParseErrorFunc(dc.GetParseError()));
        exit(1);
    }
    for(auto& i:dc.GetObject()){
        cdks.emplace(i.name.GetString(),i.value.GetString());
    }
}
static void save(){
    Document dc;
    dc.SetObject();
    Value v(kStringType),vv(kStringType);
    for(auto& i:cdks){
        v.SetString(i.second.c_str(),dc.GetAllocator());
        vv.SetString(i.first.c_str(),dc.GetAllocator());
        dc.AddMember(vv,v,dc.GetAllocator());
    }
    StringBuffer buf;
    Writer<StringBuffer> writer(buf);
    dc.Accept(writer);
    ofstream ff;
    ff.open("config/cdk.json",ios::trunc|ios::out);
    ff.write(buf.GetString(),buf.GetSize());
    ff.close();
}
void mod_init(std::list<string>& modlist){
    initlog();
    load();
    register_cmd("cdk",oncmd,"use a cdk");
    register_cmd("reload_cdk",load,"reload cdks",1);
    printf("[CDK] loaded! V2019-12-11\n");
    load_helper(modlist);
}
