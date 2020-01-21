#include <cstdio>
#include <list>
#include <string>
#include <unordered_map>
#include "cmdhelper.h"
#include <vector>
#include <Loader.h>
#include <MC.h>
#include "base.h"
#include "seral.hpp"
#include <sys/stat.h>
#include <unistd.h>
#include <sys/stat.h>
#include <memory>
#include "money.h"
#include <dlfcn.h>
#include <minecraft/json.h>
#include <fstream>
#include "../gui/gui.h"
#include "lang.h"

const char meta[] __attribute__((used, section("meta"))) =
    "name:money\n"
    "version:20200121\n"
    "author:sysca11\n"
    "depend:base@20200121,command@20200121,gui@20200121\n";

using std::string;
using std::to_string;
extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);
static LDBImpl db("data_v2/money", true, 1048576 * 2); // 2MB Cache
static void DO_DATA_CONVERT(const char *buf, int sz) {
  do_log("size %d", sz);
  DataStream ds;
  ds.dat = string(buf, sz);
  int length;
  ds >> length;
  for (int i = 0; i < length; ++i) {
    string key, val;
    ds >> key >> val;
    do_log("key %s val %d", key.c_str(), access(val.data(), int, 0));
    db.Put(key, val);
  }
}
static void load() {
  //   char *buf;
  //   int sz;
  struct stat tmp;
  if (stat("data/money/money.db", &tmp) != -1) {
    FileBuffer fb("data/money/money.db");
    DO_DATA_CONVERT(fb.data, fb.size);
    do_log("DATA CONVERT DONE;old:data/money/money.db.old");
    link("data/money/money.db", "data/money/money.db.old");
    unlink("data/money/money.db");
  }
}
int INIT_MONEY;
void loadcfg() {
  std::ifstream ifs {"config/money.json"};
  Json::Value value;
  Json::Reader reader;
  if (!reader.parse(ifs, value)) {
    auto msg = reader.getFormattedErrorMessages();
    do_log("%s", msg.c_str());
    exit(1);
  }
  INIT_MONEY = value["init_money"].asInt(0);
}
int get_money(string_view pn) {
  // lazy init
  string val;
  auto succ = db.Get(pn, val);
  if (!succ) return INIT_MONEY;
  return access(val.data(), int, 0);
}
void set_money(string_view pn, int am) {
  string val((char *) &am, 4);
  db.Put(pn, val);
}
bool red_money(string_view pn, int am) {
  int mo = get_money(pn);
  if (mo >= am) {
    set_money(pn, mo - am);
    return true;
  } else {
    return false;
  }
}
void add_money(string_view pn, int am) { red_money(pn, -am); }
static void oncmd(argVec &a, CommandOrigin const &b, CommandOutput &outp) {
  ARGSZ(1)
  if (a[0] == "query") {
    string dst;
    if (a.size() == 2) {
      dst = a[1];
    } else {
      dst = b.getName();
    }
    char buf[1024];
    snprintf(buf, 1024, "§b%s's money: %d", dst.c_str(), get_money(dst));
    outp.addMessage(string(buf));
    outp.success();
    return;
  }
  if (a[0] == "set") {
    if ((int) b.getPermissionsLevel() < 1) return;
    ARGSZ(2)
    string dst;
    int amo;
    if (a.size() == 3) {
      dst = a[1];
      amo = atoi(a[2]);
    } else {
      dst = b.getName();
      amo = atoi(a[1]);
    }
    set_money(dst, amo);
    char buf[1024];
    snprintf(buf, 1024, "§bSucceed to set %s 's money to %d", dst.c_str(), get_money(dst));
    outp.success(string(buf));
  }
  if (a[0] == "add") {
    if ((int) b.getPermissionsLevel() < 1) return;
    ARGSZ(2)
    // int amo;
    SPBuf buf;
    if (a.size() == 3) {
      add_money(a[1], atoi(a[2]));
      buf.write("§bAdded ");
      buf.write(a[2]);
      buf.write("money for ");
      buf.write(a[1]);
    } else {
      add_money(b.getName(), atoi(a[1]));
      buf.write("§bAdded ");
      buf.write(a[1]);
      buf.write("money for ");
      buf.write(b.getName());
    }
    outp.success(buf.getstr());
    if (a.size() == 3) {
      auto dstp = getplayer_byname(a[1]);
      if (dstp) sendText(dstp, buf.get());
    }
    outp.success();
  }
  if (a[0] == "reduce" || a[0] == "rd") {
    if ((int) b.getPermissionsLevel() < 1) return;
    ARGSZ(2)
    string_view dst = a[1];
    int amo         = atoi(a[2]);
    if (red_money(dst, amo)) {
      outp.success("§bDeducted successfully");
      auto dstp = getplayer_byname(dst);
      if (dstp) sendText(dstp, "§bYou used " + std::to_string(amo) + " money");
    } else {
      outp.error("§bTarget player does not have enough money");
    }
  }
  if (a[0] == "pay") {
    ARGSZ(3)
    string pl;
    string pl2;
    int mon;
    pl  = b.getName();
    pl2 = a[1];
    mon = atoi(a[2]);
    if (mon <= 0 || mon > 50000) {
      outp.error(M_PAY_STR);
    } else {
      if (red_money(pl, mon)) {
        add_money(pl2, mon);
        char msg[1000];
        // sprintf(msg,"§bYou gave %s %d money",pl2.c_str(),mon);
        snprintf(msg, 1000, "§bYou gave %s %d money", pl2.c_str(), mon);
        outp.success(string(msg));
        auto dstp = getplayer_byname(pl2);
        if (dstp) sendText(dstp, "§bYou get " + std::to_string(mon) + " money from " + pl);
      } else {
        outp.error("You don't have enough money");
      }
    }
  }
  if (a[0] == "paygui") {
    string nm = b.getName();
    gui_ChoosePlayer(
        (ServerPlayer *) b.getEntity(), "Choose a player to pay", "Pay", [](ServerPlayer *p, string_view chosen) {
          SPBuf sb;
          sb.write("How much do you pay to ");
          sb.write(chosen);
          sb.write("?");
          SharedForm *sf = getForm("Pay", "", true);
          sf->addInput(sb.get());
          string chosen_c(chosen);
          sf->cb = [chosen_c](ServerPlayer *p, string_view mon, int idx) {
            SPBuf sb;
            sb.write("money pay \"");
            sb.write(chosen_c);
            sb.write("\" ");
            sb.write(mon);
            runcmdAs(sb.get(), p);
          };
          sendForm(*p, sf);
        });
    outp.success();
  }
}
#include <iostream>
void mod_init(std::list<string> &modlist) {
  do_log("loaded! " BDL_TAG "");
  load();
  loadcfg();
  register_cmd("money", oncmd, "money command");
  register_cmd("reload_money", loadcfg, "reload money cfg", 1);
  load_helper(modlist);
}
