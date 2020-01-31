#include <utility>

 template <const int size, const int delta> struct timeq {
  std::pair<ServerPlayer *, clock_t> pool[size];
  int ptr = 0;
  bool push(ServerPlayer *sp) {
    auto now    = clock();
    pool[ptr++] = {sp, now};
    if (ptr == size) ptr = 0;
    int cnt       = 0;
    clock_t first = LONG_MAX;
    for (auto &[p, clk] : pool) {
      if (p == sp) {
        if (clk < first) first = clk;
        cnt++;
      }
    }
    if (cnt <= 1) return true;
    if ((cnt - 1) * delta > now - first) return false;
    return true;
  }
};