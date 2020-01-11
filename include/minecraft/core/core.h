#pragma once

namespace Core {

struct PathPart {
  char const *data;
  unsigned long len;
};

struct Path {
  PathPart part;
};

} // namespace Core