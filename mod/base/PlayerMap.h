#pragma once
#include <unordered_map>
#include <type_traits>
#include "myhook.h"
using std::unordered_map, std::pair;
class ServerPlayer;
void regSPD2EvHooks(pair<void (*)(void *, ServerPlayer *), void *> x);
template <typename T> class PlayerMap {
public:
  unordered_map<ServerPlayer *, T> dat;
  static void _defe(PlayerMap<T> *thi, ServerPlayer *sp) { thi->dat.erase(sp); }
  void defe(ServerPlayer *sp) { dat.erase(sp); }
  PlayerMap() { regSPD2EvHooks(std::make_pair((void (*)(void *, ServerPlayer *)) _defe, this)); }

private:
  inline T &get(ServerPlayer *sp) {
    auto it = dat.find(sp);
    if (it == dat.end()) {
      if constexpr (std::is_constructible<T, ServerPlayer &>()) {
        dat.emplace(sp, *sp);
      } else {
        dat.operator[](sp);
      }
      return get(sp);
    } else {
      return it->second;
    }
  }

public:
  T &operator[](ServerPlayer *sp) { return get(sp); }
  T &operator[](ServerPlayer &sp) { return get(&sp); }
};