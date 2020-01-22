#include "seral.hpp"
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