static void mylex(string_view oper,argVec& out) {
    //simple lexer
    size_t sz=oper.size();
    const char* c=oper.data();
    size_t tot=0;
    while(tot<sz){
        if(out.full()) return;
        char now=c[tot];
        if(now=='"'){
            size_t next=oper.find('"',tot+1);
            out.emplace_back(oper.substr(tot+1,next-tot-1));
            if(next==string_view::npos) return;
            tot=next+2; //" x
        }else{
            size_t next=oper.find(' ',tot);
            out.emplace_back(oper.substr(tot,next-tot));
            if(next==string_view::npos) return;
            tot=next+1;
        }
    }
}
struct ACmd : Command {
    CommandMessage msg;
    void* callee;
    ~ACmd() override = default;
    void execute(CommandOrigin const &origin, CommandOutput &outp) override
    {
        std::string oper=msg.getMessage(origin);
        argVec args;
        mylex(oper,args);
        typedef void(*dummy)(argVec&,CommandOrigin const &,CommandOutput &outp,string_view);
        ((dummy)callee)(args,origin,outp,oper);
    }
};
using std::string;
struct req {
    string name,desc;
    int permlevel;
    void* fn;
};
static std::deque<req> reqs;
BDL_EXPORT void register_cmd(const std::string& name,void (*fn)(argVec&,CommandOrigin const &,CommandOutput &outp,string_view),const std::string& desc,int perm) {
    reqs.push_back({name,desc,perm,fp(fn)});
}
BDL_EXPORT void register_cmd(const std::string& name,void (*fn)(argVec&,CommandOrigin const &,CommandOutput &outp),const std::string& desc,int perm) {
    reqs.push_back({name,desc,perm,fp(fn)});
}
BDL_EXPORT void register_cmd(const std::string& name,void (*fn)(void),const std::string& desc,int perm) {
    reqs.push_back({name,desc,perm,fp(fn)});
}
static ACmd* chelper(void* fn) {
    ACmd* fk=new ACmd();
    fk->callee=fn;
    return fk;
}

static void handle_regcmd(CommandRegistry& t) {
    for(auto const& i:reqs) {
        //printf("reg %s %p\n",i.name.c_str(),i.fn);
        t.registerCommand(i.name,i.desc.c_str(),(CommandPermissionLevel)i.permlevel,(CommandFlag)0,(CommandFlag)0x40);
        t.registerOverload2(i.name.c_str(),wr_regcmd(fp(chelper),fp(i.fn)),CommandParameterData(type_id<CommandRegistry, CommandMessage>(), &CommandRegistry::parse<CommandMessage>, "operation", (CommandParameterDataType)0, nullptr, offsetof(ACmd, msg), false, -1));
    }
    reqs.clear();
}

