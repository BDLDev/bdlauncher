#pragma once

#include <cstdint>

class Packet {
  uint32_t unk1, unk2;
  bool unk3;
  uint64_t unk4;

public:
  virtual ~Packet();
};

static_assert(offsetof(Packet, unk4) == 24);