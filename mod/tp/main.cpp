#include <cstdio>
#include <list>
#include <forward_list>
#include <string>
#include <unordered_map>
#include "cmdhelper.h"
#include <vector>
#include <Loader.h>
#include <MC.h>
#include "seral.hpp"
#include <sys/stat.h>
#include <unistd.h>
#include <sys/stat.h>
#include "base.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "../gui/gui.h"
#include <fstream>
#include <minecraft/json.h>

const char meta[] __attribute__((used, section("meta"))) =
    "name:tp\n"
    "version:20200121\n"
    "author:sysca11\n"
    "depend:base@20200121,command@20200121,gui@20200121\n";

using std::forward_list;
using std::string;
using std::unordered_map;
//#define dbg_printf(...) {}
#define dbg_printf printf
extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}

extern void load_helper(std::list<string> &modlist);
static bool CanBack = true, CanHome = true, CanTP = true;
int MaxHomes = 5;
struct Vpos {
  int x, y, z, dim;
  string name;
  Vpos() {}
  Vpos(int a, int b, int c, int d, string e) { x = a, y = b, z = c, dim = d, name = e; }
  void packto(DataStream &ds) const { ds << x << y << z << dim << name; }
  void unpack(DataStream &ds) { ds >> x >> y >> z >> dim >> name; }
  void tele(Actor &ply) const { TeleportA(ply, {(float) x, (float) y, (float) z}, {dim}); }
};
struct home {
  int cnt = 0;
  Vpos vals[10];
  void packto(DataStream &ds) const {
    ds << cnt;
    for (int i = 0; i < cnt; ++i) { ds << vals[i]; }
  }
  void unpack(DataStream &ds) {
    ds >> cnt;
    for (int i = 0; i < cnt; ++i) { ds >> vals[i]; }
  }
};
static list<string> warp_list;
static unordered_map<string, Vpos> warp;
static LDBImpl tp_db("data_v2/tp");
void CONVERT_WARP() {
  char *buf;
  int siz;
  FileBuffer fb("data/tp/wps.db");
  buf = fb.data;
  siz = fb.size;
  DataStream ds;
  ds.dat = string(buf, siz);
  int cnt;
  ds >> cnt;
  vector<string> warps;
  for (int i = 0; i < cnt; ++i) {
    int vposlen;
    ds >> vposlen;
    Vpos pos;
    ds >> pos;
    DataStream tmpds;
    tmpds << pos;
    tp_db.Put("warp_" + pos.name, tmpds.dat);
    do_log("warp %s found", pos.name.c_str());
    warps.emplace_back(pos.name);
  }
  DataStream tmpds;
  tmpds << warps;
  tp_db.Put("warps", tmpds.dat);
}
void CONVERT_HOME() {
  char *buf;
  int siz;
  FileBuffer fb("data/tp/tp.db");
  buf = fb.data;
  siz = fb.size;
  int cnt;
  DataStream ds;
  ds.dat = string(buf, siz);
  ds >> cnt;
  do_log("sz %d", cnt);
  for (int i = 0; i < cnt; ++i) {
    string key;
    home hom;
    int homelen;
    ds >> key;
    ds >> homelen;
    do_log("key %s len %d", key.c_str(), homelen);
    int homecnt;
    ds >> homecnt;
    hom.cnt = homecnt;
    for (int j = 0; j < homecnt; ++j) {
      ds.curpos += 4; // skip sizeof(vpos)
      ds >> hom.vals[j];
    }
    DataStream tmpds;
    tmpds << hom;
    tp_db.Put("home_" + key, tmpds.dat);
  }
}
void add_warp(int x, int y, int z, int dim, const string &name) {
  warp_list.push_back(name);
  Vpos ps;
  ps.x = x, ps.y = y, ps.z = z, ps.dim = dim, ps.name = name;
  warp[name] = ps;
  DataStream ds;
  ds << ps;
  tp_db.Put("warp_" + name, ds.dat);
  ds.reset();
  ds << warp_list;
  tp_db.Put("warps", ds.dat);
}
void del_warp(const string &name) {
  warp_list.remove(name);
  DataStream ds;
  ds << warp_list;
  tp_db.Put("warps", ds.dat);
  tp_db.Del("warp_" + name);
}
void load_warps_new() {
  DataStream ds;
  if (!tp_db.Get("warps", ds.dat)) return; // fix crash
  ds >> warp_list;
  do_log("%ld warps found", warp_list.size());
  for (auto &i : warp_list) {
    DataStream tmpds;
    tp_db.Get("warp_" + i, tmpds.dat);
    tmpds >> warp[i];
  }
}
static unordered_map<string, home> home_cache;
static home &getHome(const string &key) {
  auto it = home_cache.find(key);
  if (it != home_cache.end()) { return it->second; }
  if (home_cache.size() > 256) { home_cache.clear(); }
  DataStream ds;
  home hm;
  if (tp_db.Get("home_" + key, ds.dat)) { ds >> hm; }
  home_cache[key] = hm;
  return home_cache[key];
}
static void putHome(const string &key, home &hm) {
  DataStream ds;
  ds << hm;
  tp_db.Put("home_" + key, ds.dat);
}
static void load() {
  struct stat tmp;
  if (stat("data/tp/tp.db", &tmp) != -1) {
    do_log("CONVERTING DATA.");
    CONVERT_HOME();
    CONVERT_WARP();
    link("data/tp/tp.db", "data/tp/tp.db_old");
    unlink("data/tp/tp.db");
  }
}
struct tpreq {
  int dir; // 0=f
  string name;
  clock_t reqtime;
};
static unordered_map<string, tpreq> tpmap;
static void oncmd_suic(argVec &a, CommandOrigin const &b, CommandOutput &outp) {
  auto sp = getSP(b.getEntity());
  if (sp) {
    ((Mob *) sp)->kill();
    outp.success("You are dead");
  }
}

static void sendTPChoose(ServerPlayer *sp, int type) { // 0=t
  string name = sp->getName();
  gui_ChoosePlayer(sp, "Select target player", "Send teleport request", [type](ServerPlayer *xx, string_view dest) {
    SPBuf<512> sb;
    sb.write("tpa "sv);
    if (type == 0)
      sb.write("t");
    else
      sb.write("f");
    sb.write(" \""sv);
    sb.write(dest);
    sb.write("\""sv);
    runcmdAs(sb.get(), xx);
  });
}

static void sendTPForm(const string &from, int type, ServerPlayer *sp) {
  SPBuf<512> sb;
  sb.write(from);
  sb.write((type ? " wants to teleport you to his location" : "want to teleport to your location"));
  SharedForm *sf = getForm("TP Request", sb.get());
  sf->addButton("Accept");
  sf->addButton("Refuse");
  sf->cb = [](ServerPlayer *sp, string_view choice, int idx) {
    idx == 0 ? runcmdAs("tpa ac", sp) : runcmdAs("tpa de", sp);
  };
  sendForm(*sp, sf);
}
SharedForm TPGUI("Send teleport request", "Send teleport request", false);
static void SendTPGUI(ServerPlayer *sp) { sendForm(*sp, &TPGUI); }
static void initTPGUI() {
  TPGUI.addButton("Teleport to a player");
  TPGUI.addButton("Teleport a player to you");
  TPGUI.cb = [](ServerPlayer *sp, string_view sv, int idx) { sendTPChoose(sp, idx); };
}
static unordered_map<string, string> player_target;

static void oncmd(argVec &a, CommandOrigin const &b, CommandOutput &outp) {
  if (!CanTP) {
    outp.error("Teleport not enabled on this server!");
    return;
  }
  //   int pl      = (int) b.getPermissionsLevel();
  string name = b.getName();
  ARGSZ(1)
  if (a[0] == "f") {
    string dnm  = a.size() == 2 ? string(a[1]) : "";
    Player *dst = NULL;
    if (dnm != "") dst = getplayer_byname2(dnm);
    if (dst) dnm = dst->getName();
    // from
    if (dst == NULL) {
      outp.error("Player is offline");
      return;
    }
    if (tpmap.count(dnm)) {
      outp.error("A request of your target is pending.");
      return;
    }
    if (player_target.count(dnm)) {
      outp.error("You have already initiated the request");
      return;
    }
    player_target[name] = dnm;
    tpmap[dnm]          = {0, name, clock()};
    outp.success("§bYou sent a teleport request to the target player");
    SPBuf sb;
    sb.write("§b ");
    sb.write(name);
    sb.write("wants you to teleport to his location,you can enter \"/tpa ac\" to accept or \"/tpa de\" to reject");
    sendText(dst, sb.get());
    sendTPForm(name, 1, (ServerPlayer *) dst);
  }
  if (a[0] == "t") {
    string dnm  = a.size() == 2 ? string(a[1]) : "";
    Player *dst = NULL;
    if (dnm != "") dst = getplayer_byname2(dnm);
    if (dst) dnm = dst->getName();
    // to
    if (dst == NULL) {
      outp.error("Player is offline");
      return;
    }
    if (tpmap.count(dnm)) {
      outp.error("A request of your target is pending.");
      return;
    }
    if (player_target.count(dnm)) {
      outp.error("You have already initiated the request");
      return;
    }
    player_target[name] = dnm;
    tpmap[dnm]          = {1, name, clock()};
    outp.success("§bYou sent a teleport request to the target player");
    SPBuf sb;
    sb.write("§b ");
    sb.write(name);
    sb.write("wants to teleport to your location,you can enter \"/tpa ac\" to accept or \"/tpa de\" to reject");
    sendText(dst, sb.get());
    sendTPForm(name, 0, (ServerPlayer *) dst);
  }
  if (a[0] == "cancel") {
    // cancel req
    if (player_target.count(name)) {
      auto &nm = player_target[name];
      if (tpmap.count(nm) && tpmap[nm].name == name) {
        tpmap.erase(nm);
        outp.success("cancelled");
      }
    }
  }
  if (a[0] == "gui") {
    auto sp = getSP(b.getEntity());
    if (sp) {
      SendTPGUI(sp);
      outp.success();
    }
  }
  if (a[0] == "ac") {
    // accept
    if (tpmap.count(name) == 0) return;
    tpreq req = tpmap[name];
    tpmap.erase(name);
    outp.success("§bYou have accepted the send request from the other party");
    player_target.erase(req.name);
    auto dst = getplayer_byname(req.name);
    if (dst) {
      SPBuf sb;
      sb.write("§b ");
      sb.write(name);
      sb.write(" accepted the transmission request");
      sendText(dst, sb.get());
      if (req.dir == 0) {
        // f
        TeleportA(*getplayer_byname(name), dst->getPos(), {dst->getDimensionId()});
      } else {
        TeleportA(*dst, b.getWorldPosition(), {b.getEntity()->getDimensionId()});
      }
    }
  }
  if (a[0] == "de") {
    // deny
    if (tpmap.count(name) == 0) return;
    tpreq req = tpmap[name];
    tpmap.erase(name);
    outp.success("§bYou have rejected the send request");
    player_target.erase(req.name);
    auto dst = getplayer_byname(req.name);
    if (dst) {
      SPBuf sb;
      sb.write("§b ");
      sb.write(name);
      sb.write(" rejected the transmission request");
      sendText(dst, sb.get());
    }
  }
}

static void oncmd_home(argVec &a, CommandOrigin const &b, CommandOutput &outp) {
  if (!CanHome) {
    outp.error("Home not enabled on this server!");
    return;
  }
  //   int pl            = (int) b.getPermissionsLevel();
  string name       = b.getName();
  string_view homen = a.size() == 2 ? string(a[1]) : "hape";
  Vec3 pos          = b.getWorldPosition();
  ARGSZ(1)
  if (a[0] == "add") {
    home &myh = getHome(name);
    if (myh.cnt >= MaxHomes) {
      outp.error("Can't add more homes");
      return;
    }
    myh.vals[myh.cnt] = Vpos(pos.x, pos.y, pos.z, b.getEntity()->getDimensionId(), string(homen));
    myh.cnt++;
    putHome(name, myh);
    outp.success("§bSuccessfully added a home");
  }
  if (a[0] == "del") {
    home &myh = getHome(name);
    home tmpn;
    tmpn     = myh;
    tmpn.cnt = 0;
    for (int i = 0; i < myh.cnt; ++i) {
      if (myh.vals[i].name != homen) { tmpn.vals[tmpn.cnt++] = myh.vals[i]; }
    }
    myh = tmpn;
    putHome(name, myh);
    outp.success("§bHome has been deleted");
  }
  if (a[0] == "go") {
    home &myh = getHome(name);
    for (int i = 0; i < myh.cnt; ++i) {
      if (myh.vals[i].name == homen) {
        myh.vals[i].tele(*b.getEntity());
        outp.success("§bTeleported you to home");
      }
    }
  }
  if (a[0] == "ls") {
    home &myh = getHome(name);
    sendText((Player *) b.getEntity(), "§b====Home list====");
    for (int i = 0; i < myh.cnt; ++i) { sendText((Player *) b.getEntity(), myh.vals[i].name); }
    outp.success("§b============");
  }
  if (a[0] == "gui") {
    home &myh = getHome(name);
    auto sf   = getForm("Home", "Please choose a home");
    for (int i = 0; i < myh.cnt; ++i) {
      auto &hname = myh.vals[i].name;
      sf->addButton(hname);
    }
    sf->cb = [](ServerPlayer *sp, string_view sv, int idx) {
      SPBuf<512> sb;
      sb.write("home go \"");
      sb.write(sv);
      sb.write("\"");
      runcmdAs(sb.get(), sp);
    };
    sendForm(*(ServerPlayer *) b.getEntity(), sf);
    outp.success();
  }
}
static void oncmd_warp(argVec &a, CommandOrigin const &b, CommandOutput &outp) {
  int pl = (int) b.getPermissionsLevel();
  // do_log("pl %d",pl);
  string name = b.getName();
  Vec3 pos    = b.getWorldPosition();
  ARGSZ(1)
  if (a[0] == "add") {
    if (pl < 1) return;
    ARGSZ(2)
    add_warp(pos.x, pos.y, pos.z, b.getEntity()->getDimensionId(), string(a[1]));
    outp.success("§bSuccessfully added a warp");
    return;
  }
  if (a[0] == "del") {
    if (pl < 1) return;
    ARGSZ(2)
    del_warp(string(a[1]));
    outp.success("§bSuccessfully deleted a Warp");
    return;
  }
  if (a[0] == "ls") {
    outp.addMessage("§b====Warp list====");
    for (auto const &i : warp_list) { outp.addMessage(i); }
    outp.success("§b===========");
    return;
  }
  if (a[0] == "gui") {
    auto sf = getForm("Home", "Please choose a home");
    for (auto const &i : warp_list) {
      auto &hname = i;
      sf->addButton(hname);
    }
    sf->cb = [](ServerPlayer *sp, string_view sv, int idx) {
      SPBuf<512> sb;
      sb.write("warp \"");
      sb.write(sv);
      sb.write("\"");
      runcmdAs(sb.get(), sp);
    };
    sendForm(*(ServerPlayer *) b.getEntity(), sf);
    outp.success();
  }
  // go
  auto it = warp.find(string(a[0]));
  if (it != warp.end()) {
    it->second.tele(*b.getEntity());
    outp.success("§bTeleported you to warp");
    return;
  }
}

static unordered_map<string, pair<Vec3, int>> deathpoint;
static void oncmd_back(argVec &a, CommandOrigin const &b, CommandOutput &outp) {
  if (!CanBack) {
    outp.error("Back not enabled on this server");
    return;
  }
  ServerPlayer *sp = (ServerPlayer *) b.getEntity();
  if (!sp) return;
  auto it = deathpoint.find(sp->getName());
  if (it == deathpoint.end()) {
    outp.error("Can't find deathpoint");
    return;
  }
  TeleportA(*sp, it->second.first, {it->second.second});
  deathpoint.erase(it);
  outp.success("§bBack to deathpoint");
}
static void handle_mobdie(Mob &mb, const ActorDamageSource &) {
  if (!CanBack) return;
  auto sp = getSP(mb);
  if (sp) {
    ServerPlayer *sp = (ServerPlayer *) &mb;
    sendText(sp, "§bYou can use /back to return last deathpoint");
    deathpoint[sp->getName()] = {sp->getPos(), sp->getDimensionId()};
  }
}
static int TP_TIMEOUT = 30;
THook(void *, _ZN12ServerPlayer9tickWorldERK4Tick, ServerPlayer *sp, unsigned long const *tk) {
  auto res = original(sp, tk);
  if (*tk % 20 == 0) {
    auto &name = sp->getName();
    auto it    = tpmap.find(name);
    if (it != tpmap.end()) {
      if (it->second.reqtime + CLOCKS_PER_SEC * TP_TIMEOUT <= clock()) {
        player_target.erase(it->second.name);
        sendText(sp, "You rejected the TP request(Timeout)");
        auto sp2 = getuser_byname(it->second.name);
        sendText(sp2, "Target rejected the TP request(Timeout)");
        tpmap.erase(it);
      }
    }
  }
  return res;
}

static void load_cfg() {
  std::ifstream ifs{"config/tp.json"};
  Json::Value value;
  Json::Reader reader;
  if (!reader.parse(ifs, value)){
    auto msg = reader.getFormattedErrorMessages();
    do_log("%s", msg.c_str());
    exit(1);
  }
  CanBack  = value["can_back"].asBool(false);
  CanHome  = value["can_home"].asBool(false);
  CanTP    = value["can_tp"].asBool(false);
  MaxHomes = value["max_homes"].asBool(false);
  auto &timeout = value["TP_TIMEOUT"];
  if (timeout.isInt()) {
    TP_TIMEOUT = timeout.asInt(0);
  } else {
    do_log("NO TP_TIMEOUT FOUND!USE 30s AS DEFAULT!!!");
  }
}

void mod_init(std::list<string> &modlist) {
  do_log("loaded! " BDL_TAG "");
  load();
  load_warps_new();
  load_cfg();
  initTPGUI();
  register_cmd("suicide", oncmd_suic, "kill yourself");
  register_cmd("tpa", oncmd, "teleport command");
  register_cmd("home", oncmd_home, "home command");
  register_cmd("warp", oncmd_warp, "warp command");
  register_cmd("back", oncmd_back, "back to deathpoint");
  reg_mobdie(handle_mobdie);
  load_helper(modlist);
}
