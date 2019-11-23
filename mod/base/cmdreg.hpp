static string sname("Server");
BDL_EXPORT MCRESULT runcmd(const string& a) {
    //printf("runcmd %s\n",a.c_str());
    return getMC()->getCommands()->requestCommandExecution(std::unique_ptr<CommandOrigin>((CommandOrigin*)new ServerCommandOrigin(sname,*(ServerLevel*)getMC()->getLevel(),(CommandPermissionLevel)5)),a,4,1);
}
struct PlayerCommandOrigin{
    char filler[512];
    PlayerCommandOrigin(Player&);
};
BDL_EXPORT MCRESULT runcmdAs(const string& a,Player* sp) {
    return getMC()->getCommands()->requestCommandExecution(std::unique_ptr<CommandOrigin>((CommandOrigin*)new PlayerCommandOrigin(*sp)),a,4,1);
}

static void (*dummy)(std::vector<std::string>&,CommandOrigin const &,CommandOutput &outp);
static void mylex(std::string& oper,std::vector<std::string>& out) {
    //simple lexer
    oper=oper+"  ";
    int sz=oper.size();
    const char* c=oper.c_str();
    int t=0;
    int st=0,ed;
#define W c[i]
    for(int i=0; i<sz; ++i) {
        switch(t) {
        case 0:
            if(W=='"') t=1;
            else t=2;
            st=i;
            break;
        case 1:
            if(W=='"') t=3,ed=i;
            break;
        case 2:
            if(W==' ') t=4,ed=i;
            break;
        case 3:
            out.push_back(std::string(c+st+1,ed-st-1));
            t=0;
            break;
        case 4:
            out.push_back(std::string(c+st,ed-st));
            t=0;
            i--;
            break;
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
        std::vector<std::string> args;
        mylex(oper,args);
        ((typeof(dummy))callee)(args,origin,outp);
    }
};
using std::string;
struct req {
    string name,desc;
    int permlevel;
    void* fn;
};
static std::deque<req> reqs;
BDL_EXPORT void register_cmd(const std::string& name,void* fn,const std::string& desc,int perm) {
    reqs.push_back({name,desc,perm,fn});
}
static ACmd* chelper(void* fn) {
    ACmd* fk=new ACmd();
    fk->callee=fn;
    return fk;
}

static void handle_regcmd(CommandRegistry& t) {
    for(auto const& i:reqs) {
        t.registerCommand(i.name,i.desc.c_str(),(CommandPermissionLevel)i.permlevel,(CommandFlag)0,(CommandFlag)0x40);
        t.registerOverload2(i.name.c_str(),wr_regcmd(fp(chelper),fp(i.fn)),CommandParameterData(type_id<CommandRegistry, CommandMessage>(), &CommandRegistry::parse<CommandMessage>, "operation", (CommandParameterDataType)0, nullptr, offsetof(ACmd, msg), false, -1));
    }
    reqs.clear();
}

