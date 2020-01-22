#include "seral.hpp"
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