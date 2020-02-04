#pragma once
typedef unsigned long Shash_t;
typedef unsigned long STRING_HASH;

constexpr STRING_HASH do_hash(string_view x) {
  auto sz            = x.size();
  auto c             = x.data();
  unsigned int hash1 = 0;
  unsigned int hash2 = 0;
  for (decltype(sz) i = 0; i < sz; ++i) {
    hash1 = (hash1 * 47 + c[i]) % 1000000007;
    hash2 = (hash2 * 83 + c[i]) % 1000000009;
  }
  return (((STRING_HASH) hash1) << 32) | hash2;
}