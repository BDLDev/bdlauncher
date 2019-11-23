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
   BDL_EXPORT void cdk_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);


static int logfd;
static int logsz;
static void initlog() {
    logfd=open("cdk.log",O_WRONLY|O_APPEND|O_CREAT,S_IRWXU);
    logsz=lseek(logfd,0,SEEK_END);
}
static void async_log(const char* fmt,...) {
    char buf[10240];
    auto x=time(0);
    va_list vl;
    va_start(vl,fmt);
    auto tim=strftime(buf,128,"[%Y-%m-%d %H:%M:%S] ",localtime(&x));
    int s=vsprintf(buf+tim,fmt,vl)+tim;
    write(1,buf,s);
    write(logfd,buf,s);
    va_end(vl);
}
static void save();
unordered_map<string,string> cdks;
static void oncmd(std::vector<string>& a,CommandOrigin const & b,CommandOutput &outp) {
    ARGSZ(1)
    if(!cdks.count(a[0])) {outp.error("wrong cdk");return;}
    auto run=cdks[a[0]];
    cdks.erase(a[0]);
    async_log("[CDK] %s uses CDK %s\n",b.getName().c_str(),a[0].c_str());
    execute_cmdchain(run,b.getName(),false);
    save();
    outp.success("success");
}
using namespace rapidjson;
char buf[1024*1024*4];
static void load(){
    cdks.clear();
    Document dc;
    ifstream ff;
    ff.open("config/cdk.json",ios::in);
    buf[ff.readsome(buf,1024*1024*4)]=0;
    ff.close();
    if(dc.ParseInsitu(buf).HasParseError()){
        printf("[CDK] Config JSON ERROR!\n");
        exit(1);
    }
    for(auto& i:dc.GetObject()){
        cdks.insert({i.name.GetString(),i.value.GetString()});
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
void cdk_init(std::list<string>& modlist){
    initlog();
    load();
    register_cmd("cdk",fp(oncmd),"use a cdk");
    register_cmd("reload_cdk",fp(load),"reload cdks",1);
    printf("[CDK] loaded! V2019-11-23\n");
    load_helper(modlist);
}
