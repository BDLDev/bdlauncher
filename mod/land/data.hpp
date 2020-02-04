#include <list>
#include <unordered_map>
#include "base.h"
#include <sys/cdefs.h>
#include <minecraft/core/access.h>

using std::list;
using std::swap;
using std::unordered_map;
static LDBImpl db("data_v2/land", true, 1048576 * 8);
enum LandPerm : char {
  PERM_NULL           = 0,
  PERM_OWNER          = 1,
  PERM_USE            = 2,
  PERM_ATK            = 4,
  PERM_BUILD          = 8,
  PERM_POPITEM        = 16,
  PERM_INTERWITHACTOR = 32,
  PERM_ADMIN_FLY      = 64
};
typedef unsigned int lpos_t;
struct FastLand {
  lpos_t x, z, dx, dz;
  uint lid;
  short refcount;
  char dim;
  LandPerm perm;
  int owner_sz;
  char owner[0];
  int chkOwner(string_view x) {
    // x="|"+x+"|";
    int sz   = x.size();
    auto dat = x.data();
    // do_log("owner sz %d",owner_sz);
    for (int i = 1; i < owner_sz - sz; ++i) {
      if (memcmp(dat, owner + i, sz) == 0 && owner[i - 1] == '|' && owner[i + sz] == '|') { return i == 1 ? 2 : 1; }
    }
    return 0;
  }
  inline bool hasPerm(string_view x, LandPerm PERM) {
    if (PERM == PERM_OWNER) { return chkOwner(x) == 2; }
    return chkOwner(x) ? true : (perm & PERM);
  }
  int memsz() { return sizeof(FastLand) + owner_sz + 1; }
  inline string_view getOwner() { return {owner, (size_t) owner_sz}; }
};
static_assert(sizeof(FastLand) == 28);
static_assert(offsetof(FastLand, dim) == 22);
static_assert(offsetof(FastLand, refcount) == 20);
struct DataLand {
  lpos_t x, z, dx, dz;
  uint lid;
  short ver;
  char dim;
  LandPerm perm;
  string owner;
  DataLand() {}
  DataLand(FastLand &fastland) {
    x     = fastland.x;
    z     = fastland.z;
    dx    = fastland.dx;
    dz    = fastland.dz;
    lid   = fastland.lid;
    ver   = fastland.refcount;
    dim   = fastland.dim;
    perm  = fastland.perm;
    owner = fastland.getOwner();
  }
  void addOwner(string_view x, bool SuperOwner = false) {
    SPBuf sb;
    if (SuperOwner) {
      sb.write("|");
      sb.write(x);
      sb.write("|%s", owner.c_str());
    } else {
      sb.write("%s|", owner.c_str());
      sb.write(x);
      sb.write("|");
    }
    owner = sb.get();
  }
  void delOwner(string_view x) {
    SPBuf sb;
    sb.write("|");
    sb.write(x);
    sb.write("|");
    auto sv  = sb.get();
    auto pos = owner.find(sv);
    if (pos != string::npos) owner.erase(pos, sv.size());
  }
  void packto(DataStream &ds) const {
    ds << x << z << dx << dz << lid << ver << dim << perm << owner; // version
  }
  void unpack(DataStream &ds) {
    ds >> x >> z >> dx >> dz >> lid >> ver >> dim >> perm >> owner; // refcount=version
  }
};
static_assert(sizeof(DataLand) == 24 + sizeof(string));
static_assert(offsetof(DataLand, dim) == 22);
static struct LandCacheManager {
  unordered_map<int, FastLand *> cache;
  void noticeFree(FastLand *fl) {
    fl->refcount--;
    if (fl->refcount <= 0) {
      cache.erase(fl->lid);
      delete fl;
    }
  }
  FastLand *requestLand(int id) {
    // do_log("req %d",id);
    auto it = cache.find(id);
    FastLand *res;
    if (it == cache.end()) {
      string landstr;
      char buf[6];
      buf[0] = 'l';
      buf[1] = '_';
      memcpy(buf + 2, &id, 4);
      db.Get(string_view(buf, 6), landstr);
      res = (FastLand *) malloc(landstr.size() + 1);
      memcpy(res, landstr.data(), landstr.size());
      res->owner[res->owner_sz] = 0;
      res->refcount             = 0;
      cache[id]                 = res;
    } else {
      res = it->second;
    }
    res->refcount++;
    // do_log("req %d rcnt %d lp %p",id,res->refcount,res);
    return res;
  }
} LCMan;
struct ChunkLandManager {
  lpos_t xx, zz;
  char dim;
  FastLand *lands[16][16];
  static_deque<FastLand *, 256> managed_lands;
  void reset() {
    if (managed_lands.size() != 0) memset(lands, 0, sizeof(lands));
    for (decltype(managed_lands.tail) i = managed_lands.head; i != managed_lands.tail; ++i) {
      LCMan.noticeFree(managed_lands[i]);
    }
    managed_lands.clear();
  }
  void init(int *landlist, int siz) {
    for (int I = 0; I < siz; ++I) {
      auto fl = LCMan.requestLand(landlist[I]);
      managed_lands.push_back(fl);
      lpos_t sx, dx, sz, dz;
      if ((fl->x >> 4) == xx)
        sx = fl->x & 15;
      else
        sx = 0;
      if ((fl->z >> 4) == zz)
        sz = fl->z & 15;
      else
        sz = 0;
      if ((fl->dx >> 4) == xx)
        dx = fl->dx & 15;
      else
        dx = 15;
      if ((fl->dz >> 4) == zz)
        dz = fl->dz & 15;
      else
        dz = 15;
      for (lpos_t i = sx; i <= dx; ++i) {
        for (lpos_t j = sz; j <= dz; ++j) { lands[i][j] = fl; }
      }
    }
  }
  void load(lpos_t x, lpos_t z, int di) {
    string val;
    char buf[9];
    xx  = x;
    zz  = z;
    dim = di;
    memcpy(buf, &x, 4);
    memcpy(buf + 4, &z, 4);
    buf[8] = dim;
    db.Get(string_view(buf, 9), val);
    init((int *) val.data(), val.size() / 4);
  }
};
template <int CACHE_SZ> struct CLCache {
  struct Data {
    short prev;
    short next;
    short idx;
    unsigned long hash;
  };
  ChunkLandManager cm[CACHE_SZ];
  Data pool[CACHE_SZ + 1];
  CLCache() {
    for (int i = 0; i <= CACHE_SZ; ++i) {
      pool[i].prev = i - 1;
      pool[i].next = i + 1;
      pool[i].idx  = i - 1;
      pool[i].hash = 0xfffffffffffffffful;
    }
    pool[0].prev        = CACHE_SZ;
    pool[CACHE_SZ].next = 0;
    for (int i = 0; i < CACHE_SZ; ++i) { cm[i].reset(); }
  }
  inline void detach(int idx) {
    auto &now           = pool[idx];
    pool[now.prev].next = now.next;
    pool[now.next].prev = now.prev;
  }
  inline void insert_after(int pos, int idx) {
    auto &now           = pool[idx];
    now.prev            = pos;
    now.next            = pool[pos].next;
    pool[now.next].prev = idx;
    pool[pos].next      = idx;
  }
  inline ChunkLandManager *get_or_build(lpos_t x, lpos_t z, char dim) {
    int nowidx;
    unsigned long hash = (((unsigned long) x) << 32) | (((unsigned long) dim) << 29) | z;
    for (nowidx = pool[0].next; nowidx != 0; nowidx = pool[nowidx].next) {
      auto &now = pool[nowidx];
      if (now.hash == hash) {
        // found
        detach(nowidx);
        insert_after(0, nowidx);
        return cm + now.idx;
      }
    }
    // not found;
    int tailidx = pool[0].prev;
    detach(tailidx);
    insert_after(0, tailidx);
    auto &now = pool[tailidx];
    now.hash  = hash;
    cm[now.idx].reset();
    cm[now.idx].load(x, z, dim);
    return cm + now.idx;
  }
  inline void purge() {
    for (int i = 1; i <= CACHE_SZ; ++i) {
      cm[pool[i].idx].reset();
      pool[i].hash = 0xfffffffffffffffful;
    }
  }
};
static CLCache<160> CLMan;
static inline void purge_cache() { CLMan.purge(); }
static inline ChunkLandManager *getChunkMan(lpos_t x, lpos_t z, int dim) { return CLMan.get_or_build(x, z, dim); }
static inline FastLand *getFastLand(int x, int z, int dim) {
  lpos_t xx, zz;
  xx      = (x) ^ 0x80000000;
  zz      = (z) ^ 0x80000000;
  auto cm = getChunkMan(xx >> 4, zz >> 4, dim);
  return cm->lands[xx & 15][zz & 15];
}
static inline bool generic_perm(int x, int z, int dim, LandPerm perm, const string &name) {
  auto ld = getFastLand(x, z, dim);
  if (unlikely(ld)) { return ld->hasPerm(name, perm); }
  return true;
}
static uint getLandUniqid() {
  string val;
  uint id = 0;
  if (!db.Get("land_id", val)) {
    db.Put("land_id", string((char *) &id, 4));
    return 0;
  } else {
    id = access(val.data(), uint, 0);
    id++;
    db.Put("land_id", string((char *) &id, 4));
    return id;
  }
}
static void proc_chunk_add(lpos_t x, lpos_t dx, lpos_t z, lpos_t dz, int dim, uint lid) {
  char buf[9];
  x >>= 4;
  dx >>= 4;
  z >>= 4;
  dz >>= 4;
  buf[8] = dim;
  string_view key(buf, 9);
  for (auto i = x; i <= dx; ++i) {
    for (auto j = z; j <= dz; ++j) {
      memcpy(buf, &i, 4);
      memcpy(buf + 4, &j, 4);
      string val;
      db.Get(key, val);
      val.append((char *) &lid, 4);
      db.Put(key, val);
    }
  }
}
static void proc_chunk_del(lpos_t x, lpos_t dx, lpos_t z, lpos_t dz, int dim, uint lid) {
  char buf[9];
  x >>= 4;
  dx >>= 4;
  z >>= 4;
  dz >>= 4;
  buf[8] = dim;
  string_view key(buf, 9);
  string val;
  for (decltype(dx) i = x; i <= dx; ++i) {
    for (decltype(dz) j = z; j <= dz; ++j) {
      memcpy(buf, &i, 4);
      memcpy(buf + 4, &j, 4);
      // do_log("proc del %d %d %d",i,j,dim);
      db.Get(key, val);
      // do_log("size %d access %u",val.size(),access(val.data(),uint,0));
      for (decltype(val.size()) i = 0; i < val.size(); i += 4) {
        if (access(val.data(), uint, i) == lid) {
          // do_log("erase %d",i);
          val.erase(i, 4);
          break;
        }
      }
      db.Put(key, val);
    }
  }
}
static void addLand(lpos_t x, lpos_t dx, lpos_t z, lpos_t dz, int dim, const string &owner, LandPerm perm = PERM_NULL) {
  DataLand ld;
  ld.x = x, ld.z = z, ld.dx = dx, ld.dz = dz, ld.dim = dim;
  ld.owner = owner[0] == '|' ? owner : ('|' + owner + '|');
  ld.perm  = perm;
  auto lid = getLandUniqid();
  ld.lid   = lid;
  // string key="l_"+string((char*)&lid,4);
  char buf[6];
  buf[0] = 'l';
  buf[1] = '_';
  memcpy(buf + 2, &lid, 4);
  string_view key(buf, 6);
  DataStream ds;
  ds << ld;
  // do_log("sss %d",ds.dat.size());
  db.Put(key, ds.dat);
  proc_chunk_add(x, dx, z, dz, dim, lid);
  purge_cache();
}
static void updLand(DataLand &ld) {
  auto lid = ld.lid;
  ld.ver   = 1; // NEW
  DataStream ds;
  char buf[6];
  buf[0] = 'l';
  buf[1] = '_';
  memcpy(buf + 2, &lid, 4);
  string_view key(buf, 6);
  ds << ld;
  db.Put(key, ds.dat);
  purge_cache();
}
static void removeLand(FastLand *land) {
  char buf[6];
  buf[0] = 'l';
  buf[1] = '_';
  memcpy(buf + 2, &land->lid, 4);
  string_view key(buf, 6);
  db.Del(key);
  proc_chunk_del(land->x, land->dx, land->z, land->dz, land->dim, land->lid); // BUG HERE
  purge_cache();
}
void iterLands(function<void(DataLand &)> cb) {
  vector<pair<string, string>> newdata;
  db.Iter([&](string_view k, string_view v) {
    if (k.size() == 6 && k[0] == 'l' && k[1] == '_') {
      DataLand dl;
      DataStream ds;
      ds.dat = v;
      ds >> dl;
      cb(dl);
      ds.reset();
      ds << dl;
      newdata.emplace_back(k, ds.dat);
    }
  });
  for (auto &i : newdata) { db.Put(i.first, i.second); }
  purge_cache();
}
void iterLands_const(function<void(const DataLand &)> cb) {
  db.Iter([&](string_view k, string_view v) {
    if (k.size() == 6 && k[0] == 'l' && k[1] == '_') {
      DataLand dl;
      DataStream ds;
      ds.dat = v;
      ds >> dl;
      cb(dl);
    }
  });
}

void CHECK_AND_FIX_ALL() {
  do_log("start data fix&optimize");
  vector<pair<string, DataLand>> lands;
  string val;
  uint lids;
  if (!db.Get("land_id", val))
    lids = 0;
  else
    lids = access(val.data(), uint, 0);
  db.Iter([&](string_view k, string_view v) {
    if (k.size() == 6 && k[0] == 'l' && k[1] == '_') {
      DataLand dl;
      DataStream ds;
      ds.dat = v;
      ds >> dl;
      lands.emplace_back(k, dl);
    }
  });
  db.close();
  setenv("LD_PRELOAD", "", 1);
  system("rm -r data_v2/land_old;mv data_v2/land data_v2/land_old");
  db.load("data_v2/land", true, 1048576 * 8); // 8MB Cache
  db.Put("land_id", string_view((char *) &lids, 4));
  do_log("%ld lands found!", lands.size());
  for (auto &nowLand : lands) {
    DataStream ds;
    auto &Land = nowLand.second;
    if (Land.ver == 0) {
      do_log("upgrade land %d", Land.lid);
      Land.ver = 1;
      int xx   = Land.x - 200000;
      int zz   = Land.z - 200000;
      Land.x   = xx ^ (0x80000000);
      Land.z   = zz ^ (0x80000000);
      xx       = Land.dx - 200000;
      zz       = Land.dz - 200000;
      Land.dx  = xx ^ (0x80000000);
      Land.dz  = zz ^ (0x80000000);
    }
    ds << Land;
    db.Put(nowLand.first, ds.dat);
    proc_chunk_add(Land.x, Land.dx, Land.z, Land.dz, Land.dim, Land.lid);
  }
  db.CompactAll();
  do_log("Done land data fix: %ld!", lands.size());
}