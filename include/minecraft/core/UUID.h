#pragma once

#include <functional>
#include <string>

namespace mce {
struct UUID {
  uint64_t most, least;

  UUID() {}

  UUID(const UUID &oth) {
    most  = oth.most;
    least = oth.least;
  }

  const std::string asString() const;

  static UUID fromStringFix(std::string const &str);

  bool operator==(UUID const &another) const;
  bool operator<(UUID const &another) const;
  bool operator!=(UUID const &another) const;
};
} // namespace mce

namespace std {
template <> struct hash<mce::UUID> {
  size_t operator()(mce::UUID const &uuid) const {
    auto seed = std::hash<unsigned long long>{}(uuid.most);
    seed ^= std::hash<unsigned long long>{}(uuid.least) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    return seed;
  }
};
} // namespace std