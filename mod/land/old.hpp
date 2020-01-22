#include "seral.hpp"
static void CONVERT(char *b, int s) {
  DataStream ds;
  ds.dat = string(b, s);
  int cnt;
  ds >> cnt;
  do_log("%d lands found", cnt);
  for (int i = 0; i < cnt; ++i) {
    DataStream ds2;
    ds >> ds2.dat;
    int x, y, dx, dy, dim;
    string owner;
    ds2 >> dim >> x >> y >> dx >> dy >> owner;
    dx = x + dx - 1;
    dy = y + dy - 1;
    dim >>= 4;
    do_log("land %d %d %d %d %d %s", x, y, dx, dy, dim, owner.c_str());
    if (x < -200000 || y < -200000 || dx < -200000 || dy < -200000) {
      do_log("refuse to add land %s", owner.c_str());
      continue;
    }
    addLand((x) ^ 0x80000000, (dx) ^ 0x80000000, (y) ^ 0x80000000, (dy) ^ 0x80000000, dim, owner);
  }
}
static void load() {
  //   char *buf;
  //   int sz;

  struct stat tmp;
  if (stat("data/land/land.db", &tmp) != -1) {
    FileBuffer fb("data/land/land.db");
    do_log("CONVERTING LANDS");
    CONVERT(fb.data, fb.size);
    link("data/land/land.db", "data/land/land.db.old");
    unlink("data/land/land.db");
  }
}
