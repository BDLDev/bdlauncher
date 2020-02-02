#pragma once
class Vec3;

class BlockPos {
public:
  int x, y, z;
  BlockPos();
  BlockPos(int x, int y, int z) : x(x), y(y), z(z) {}
  BlockPos(Vec3 const &);
  BlockPos(BlockPos const &p) : x(p.x), y(p.y), z(p.z) {}
  bool operator==(BlockPos const &pos) const {
    if (this->x != pos.x) return false;
    if (this->y != pos.y) return false;
    if (this->z != pos.z) return false;
    return true;
  }
  bool operator!=(BlockPos const &pos) const { return !(*this == pos); }
};