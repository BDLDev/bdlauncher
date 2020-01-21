#include <Loader.h>
#include <MC.h>
#include "base.h"
#include <fstream>
#include <cstdarg>

const char meta[] __attribute__((used,section(".meta")))="name:cdk\n"\
"version:20200121\n"\
"author:sysca11\n"\
"depend:base@20200121,command@20200121\n"\
;

using namespace std;

extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);

static int logfd;
static int logsz;
static void initlog() {
  logfd = open("cdk.log", O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
  logsz = lseek(logfd, 0, SEEK_END);
}
static void async_log(const char *fmt, ...) {
  char buf[1024];
  auto x = time(0);
  va_list vl;
  va_start(vl, fmt);
  auto tim = strftime(buf, 128, "[%Y-%m-%d %H:%M:%S] ", localtime(&x));
  int s    = vsnprintf(buf + tim, 900, fmt, vl) + tim;
  write(1, buf, s);
  write(logfd, buf, s);
  va_end(vl);
}
static void save();
unordered_map<string, string> cdks;
static void oncmd(argVec &a, CommandOrigin const &b, CommandOutput &outp) {
  ARGSZ(1)
  string cdk = string(a[0]);
  if (!cdks.count(cdk)) {
    outp.error("Invalid cdk");
    return;
  }
  auto run = cdks[cdk];
  cdks.erase(cdk);
  async_log("[CDK] %s uses CDK %s\n", b.getName().c_str(), cdk.c_str());
  execute_cmdchain(run, b.getName(), false);
  save();
  outp.success("§bYou used cdk: " + cdk);
}
static void load() {
  cdks.clear();
  std::ifstream ifs{"config/cdk.json"};
  Json::Value value;
  Json::Reader reader;
  if (!reader.parse(ifs, value)) {
    auto msg = reader.getFormattedErrorMessages();
    do_log("%s", msg.c_str());
    exit(1);
  }
  for (auto it = value.begin(); it != value.end(); it++) cdks.emplace(it.key().asString(""), it->asString(""));
}
static void save() {
  Json::Value value{Json::ValueType::objectValue};
  for (auto &i : cdks) value[i.first] = {i.second};
  Json::FastWriter writer;
  std::ofstream ofs{"config/cdk.json", ios::trunc | ios::out};
  ofs << writer.write(value);
}
void mod_init(std::list<string> &modlist) {
  initlog();
  load();
  register_cmd("cdk", oncmd, "use a cdk");
  register_cmd("reload_cdk", load, "reload cdks", 1);
  do_log("loaded! V2019-12-11");
  load_helper(modlist);
}
