#include "cmdreg.h"
#include <cmdhelper.h>
#include <Loader.h>

// PRIVATE

using std::string;

struct req {
  string name, desc;
  int permlevel;
  void *fn;
};

static void mylex(string_view oper, argVec &out);

struct ACmd : Command {
  CommandMessage msg;
  void *callee;
  ~ACmd() override = default;
  void execute(CommandOrigin const &origin, CommandOutput &outp) override {
    std::string oper = msg.getMessage(origin);
    argVec args;
    mylex(oper, args);
    typedef void (*dummy)(argVec &, CommandOrigin const &, CommandOutput &outp, string_view);
    ((dummy) callee)(args, origin, outp, oper);
  }
};

static std::deque<req> reqs;

static void mylex(string_view oper, argVec &out) {
  // simple lexer
  size_t sz     = oper.size();
  const char *c = oper.data();
  size_t tot    = 0;
  while (tot < sz) {
    if (out.full()) return;
    char now = c[tot];
    if (now == '"') {
      size_t next = oper.find('"', tot + 1);
      out.emplace_back(oper.substr(tot + 1, next - tot - 1));
      if (next == string_view::npos) return;
      tot = next + 2; //" x
    } else {
      size_t next = oper.find(' ', tot);
      out.emplace_back(oper.substr(tot, next - tot));
      if (next == string_view::npos) return;
      tot = next + 1;
    }
  }
}

static ACmd *chelper(void *fn) {
  ACmd *fk   = new ACmd();
  fk->callee = fn;
  return fk;
}

static void handle_regcmd(CommandRegistry &t) {
  for (auto const &i : reqs) {
    // do_log("reg %s %p",i.name.c_str(),i.fn);
    t.registerCommand(
        i.name, i.desc.c_str(), (CommandPermissionLevel) i.permlevel, (CommandFlag) 0, (CommandFlag) 0x40);
    t.registerOverload2(
        i.name.c_str(), wr_regcmd(fp(chelper), fp(i.fn)),
        CommandParameterData(
            type_id<CommandRegistry, CommandMessage>(), &CommandRegistry::parse<CommandMessage>, "operation",
            (CommandParameterDataType) 0, nullptr, offsetof(ACmd, msg), false, -1));
  }
  reqs.clear();
}

THook(void *, _ZN10SayCommand5setupER15CommandRegistry, CommandRegistry &thi, CommandRegistry &a) {
  handle_regcmd(thi);
  return original(thi, a);
}

// IMPL

void register_cmd(
    const string &name, void (*fn)(argVec &, CommandOrigin const &, CommandOutput &outp, string_view),
    const string &desc, int perm) {
  reqs.push_back({name, desc, perm, fp(fn)});
}

void register_cmd(
    const string &name, void (*fn)(argVec &, CommandOrigin const &, CommandOutput &outp), const string &desc,
    int perm) {
  reqs.push_back({name, desc, perm, fp(fn)});
}

void register_cmd(const string &name, void (*fn)(void), const string &desc, int perm) {
  reqs.push_back({name, desc, perm, fp(fn)});
}