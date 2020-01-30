#include <leveldb/db.h>
//#include <MC.h>
#include <string>
#include <string_view>
#include "stl.hpp"

struct LDBImpl {
  leveldb::DB *db;
  leveldb::ReadOptions rdopt;
  leveldb::WriteOptions wropt;
  leveldb::Options options;
  BDL_EXPORT void load(const char *name, bool read_cache = true, int lru_cache_sz = 0);
  BDL_EXPORT LDBImpl(const char *name, bool read_cache = true, int lru_cache_sz = 0);
  BDL_EXPORT void close();
  BDL_EXPORT ~LDBImpl();
  BDL_EXPORT bool Get(std::string_view key, std::string &val) const;
  BDL_EXPORT void Put(std::string_view key, std::string_view val);
  BDL_EXPORT bool Del(std::string_view key);
  BDL_EXPORT void Iter(std::function<void(std::string_view, std::string_view)> fn) const;
  BDL_EXPORT void CompactAll();
};