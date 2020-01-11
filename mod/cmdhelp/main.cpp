#include <Loader.h>
#include <MC.h>
#include "../base/base.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <fstream>
#include <cstdarg>
#include "../gui/gui.h"
#include <queue>

using namespace std;
LDBImpl db("data_v2/joinhook");
extern "C"
{
    BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);
struct CMD
{
    string cond, run;
    bool execute(const string &name, bool chained = true)
    {
        if (execute_cmdchain(cond, name, chained))
        {
            execute_cmdchain(run, name, false);
            return true;
        }
        return false;
    }
    CMD(const string &a, const string &b)
    {
        cond = a, run = b;
    }
    CMD() {}
};
struct Timer
{
    int tim, sft;
    CMD run;
    bool chk(int tk)
    {
        return tk % tim == sft;
    }
    Timer(int a, int b, const CMD &c)
    {
        tim = a, sft = b, run = c;
    }
    Timer() {}
};

struct CMDForm
{
    vector<std::pair<string, CMD>> ordered_cmds;
    SharedForm *sf;
    void sendTo(ServerPlayer &sp)
    {
        sendForm(sp, sf);
    }
    ~CMDForm()
    {
        delete sf;
    }
    void init(string_view content, string_view title)
    {
        sf = new SharedForm(title, content, false);
        for (auto &i : ordered_cmds)
        {
            sf->addButton(i.first);
        }
        sf->cb = [this](ServerPlayer *sp, string_view, int idx) {
            ordered_cmds[idx].second.execute(sp->getName());
        };
    }
};
static unordered_map<STRING_HASH, CMDForm> forms;
static list<Timer> timers;
struct Oneshot
{
    int time;
    string name, cmd;
    bool operator<(Oneshot const &a) const
    {
        return time < a.time;
    }
    Oneshot(int a, const string &b, const string &c)
    {
        time = a, name = b;
        cmd = c;
    }
};
static priority_queue<Oneshot> oneshot_timers;
static CMD joinHook;
static void oncmd(argVec &a, CommandOrigin const &b, CommandOutput &outp)
{
    if (a.size() == 0)
        a.emplace_back("root");
    auto hs = do_hash(a[0]);
    if (forms.count(hs))
    {
        auto &fm = forms[hs];
        ServerPlayer *sp = getSP(b.getEntity());
        if (sp)
        {
            fm.sendTo(*sp);
            outp.success();
        }
        else
        {
            outp.error("fucku");
        }
    }
    else
    {
        outp.error("cant find");
    }
}
static void join(ServerPlayer *sp)
{
    string val;
    if (db.Get(sp->getName(), val))
    {
        broadcastText(val);
    }
    joinHook.execute(sp->getNameTag(), false);
}
static void tick(int tk)
{
    for (auto &i : timers)
    {
        if (i.chk(tk))
            i.run.execute("", false);
    }
    while (!oneshot_timers.empty())
    {
        auto a = oneshot_timers.top();
        if (a.time <= tk)
        {
            for (int i = 0; i < a.cmd.size(); ++i)
                if (a.cmd[i] == '$')
                    a.cmd[i] = '%';
            execute_cmdchain(a.cmd, a.name, false);
            oneshot_timers.pop();
        }
        else
        {
            break;
        }
    }
}
static int tkl;
THook(void *, _ZN5Level4tickEv, Level &a)
{
    tkl++;
    if (tkl % 20 == 0)
        tick(tkl / 20);
    return original(a);
}
static int menuitem;
using namespace rapidjson;
static void load()
{
    timers.clear();
    forms.clear();
    Document dc;
    FileBuffer fb("config/cmd.json");
    if (dc.ParseInsitu(fb.data).HasParseError())
    {
        printf("[CMDHelper] JSON ERROR pos: %d type: %s !\n", dc.GetErrorOffset(), GetParseErrorFunc(dc.GetParseError()));
        printf("--Hint--\n");
        auto off = dc.GetErrorOffset();
        FileBuffer fb2("config/cmd.json");
        auto hint = fb2.getsv().substr(max(0ul, off - 12), 24);
        printf("%s\n", string(hint).c_str());
        exit(1);
    }
    for (auto &i : dc.GetArray())
    {
        auto &&x = i.GetObject();
        auto typ = string(x["type"].GetString());
        if (typ == "menuitem")
        {
            menuitem = x["itemid"].GetInt();
        }
        if (typ == "join")
        {
            joinHook = {"", string(x["cmd"].GetString())};
        }
        if (typ == "form")
        {
            auto &&buttons = x["buttons"];
            auto &&cont = x["text"].GetString();
            auto &&title = x["title"].GetString();
            auto &&name = x["name"];
            assert(buttons.IsArray());
            auto &cf = forms[do_hash(name.GetString())];
            for (auto &i : buttons.GetArray())
            {
                assert(i.IsArray());
                auto &&but = i.GetArray();
                if (but.Size() != 3)
                {
                    printf("[CMD] wtf!cmdchain size mismatch.3 required,%d found\n", but.Size());
                    printf("[CMD] Hint:\n");
                    for (auto &j : but)
                    {
                        printf("[CMD] %s\n", j.GetString());
                    }
                    exit(0);
                }
                cf.ordered_cmds.emplace_back(make_pair(string(but[0].GetString()), CMD(but[1].GetString(), but[2].GetString())));
            }
            cf.init(cont, title);
        }
        if (typ == "timer")
        {
            timers.emplace_back(x["time"].GetInt(), x["shift"].GetInt(), CMD("", x["cmd"].GetString()));
        }
    }
}
static clock_t lastclk;
static ServerPlayer *lastp;
constexpr auto root_hash = do_hash("root");
static bool handle_u(GameMode *a0, ItemStack *a1, BlockPos const *a2, BlockPos const *dstPos, Block const *a5)
{
    if (menuitem != 0 && a1->getId() == menuitem)
    {
        auto sp = a0->getPlayer();
        if (lastp == sp)
        {
            if (clock() - lastclk < CLOCKS_PER_SEC / 10)
            {
                return 0;
            }
            else
            {
                lastclk = clock();
                if (forms.count(root_hash))
                {
                    auto &fm = forms[root_hash];
                    fm.sendTo(*sp);
                }
            }
        }
        else
        {
            lastclk = clock();
            lastp = sp;
            if (forms.count(root_hash))
            {
                auto &fm = forms[root_hash];
                fm.sendTo(*sp);
            }
        }

        return 0;
    }
    return 1;
}
static void oncmd_sch(argVec &a, CommandOrigin const &b, CommandOutput &outp)
{
    if ((int)b.getPermissionsLevel() < 1)
        return;
    ARGSZ(3)
    int dtime = atoi(a[0]);
    string name = string(a[1]);
    string chain = string(a[2]);
    oneshot_timers.emplace(tkl / 20 + dtime, name, chain);
    outp.success();
}
static void oncmd_runas(argVec &a, CommandOrigin const &b, CommandOutput &outp)
{
    if ((int)b.getPermissionsLevel() < 1)
        return;
    ARGSZ(1)
    auto sp = getplayer_byname(a[0]);
    if (sp)
    {
        int vsz = a.size();
        char buf[1000];
        int ptr = 0;
        for (int i = 1; i < vsz; ++i)
        {
            memcpy(buf + ptr, a[i].data(), a[i].size());
            ptr += a[i].size();
            buf[ptr++] = ' ';
        }
        runcmdAs({buf, ptr}, sp).isSuccess() ? outp.success() : outp.error("error");
    }
    else
    {
        outp.error("Can't find player");
    }
}
static void oncmd_bc(argVec &a, CommandOrigin const &b, CommandOutput &outp)
{
    broadcastText(a[0]);
    outp.success();
}
static void oncmd_jmsg(argVec &a, CommandOrigin const &b, CommandOutput &outp)
{
    ARGSZ(2)
    if (a[1] != "del")
        db.Put(a[0], a[1]);
    else
    {
        db.Del(a[0]);
    }
    outp.success();
}
void mod_init(std::list<string> &modlist)
{
    load();
    register_cmd("c", oncmd, "open gui");
    register_cmd("joinmsg", oncmd_jmsg, "joinmsg", 1);
    register_cmd("bc", oncmd_bc, "broadcast", 1);
    register_cmd("reload_cmd", load, "reload cmds", 1);
    register_cmd("sched", oncmd_sch, "schedule a delayed cmd", 1);
    register_cmd("runas", oncmd_runas, "run cmd as", 1);
    reg_player_join(join);
    reg_useitemon(handle_u);
    printf("[CMDHelp] loaded! " BDL_TAG "\n");
    load_helper(modlist);
}
