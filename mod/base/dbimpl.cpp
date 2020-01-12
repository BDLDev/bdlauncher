#include "dbimpl.h"
#include "stkbuf.hpp"
#include <leveldb/cache.h>
#include <leveldb/db.h>
#include <cstdio>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <logger.h>

using leveldb::Slice;
using std::function;
using std::string;
using std::string_view;

void LDBImpl::load(const char *name, bool read_cache, int lru_cache_sz) {
  rdopt                  = leveldb::ReadOptions();
  wropt                  = leveldb::WriteOptions();
  rdopt.fill_cache       = read_cache;
  rdopt.verify_checksums = false;
  wropt.sync             = false;
  if (lru_cache_sz) { options.block_cache = leveldb::NewLRUCache(lru_cache_sz); }
  options.create_if_missing = true;
  leveldb::Status status    = leveldb::DB::Open(options, name, &db);
  if (!status.ok()) { do_log("cannot load %s reason: %s", name, status.ToString().c_str()); }
  assert(status.ok());
}

LDBImpl::LDBImpl(const char *name, bool read_cache, int lru_cache_sz) { load(name, read_cache, lru_cache_sz); }

void LDBImpl::close() { delete db; }

LDBImpl::~LDBImpl() { close(); }

bool LDBImpl::Get(string_view key, string &val) const {
  auto s = db->Get(rdopt, Slice(key.data(), key.size()), &val);
  return s.ok();
}

void LDBImpl::Put(string_view key, string_view val) {
  auto s = db->Put(wropt, Slice(key.data(), key.size()), Slice(val.data(), val.size()));
  if (!s.ok()) { do_log("%s", s.ToString().c_str()); }
}

bool LDBImpl::Del(string_view key) {
  auto s = db->Delete(wropt, Slice(key.data(), key.size()));
  return s.ok();
}

void LDBImpl::Iter(function<void(string_view, string_view)> fn) const {
  leveldb::Iterator *it = db->NewIterator(rdopt);
  for (it->SeekToFirst(); it->Valid(); it->Next()) {
    auto k = it->key();
    auto v = it->value();
    fn({k.data(), k.size()}, {v.data(), v.size()});
  }
  delete it;
}

void LDBImpl::CompactAll() { db->CompactRange(nullptr, nullptr); }