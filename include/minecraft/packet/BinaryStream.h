#pragma once
#include <string>
#include <string_view>
#include "minecraft/core/types.h"
#include "gsl/string_span"

class BinaryStream {
public:

  char filler[312];

  BinaryStream();
  BinaryStream(std::string &, bool);
  void writeFloat(float);
  void writeDouble(double);
  void writeStream(BinaryStream &);
  void writeVarInt(int);
  void writeVarInt64(long);
  void writeSignedInt(int);
  void writeFixedFloat(float, double);
  void writeSignedInt64(long);
  void writeSignedShort(short);
  void writeUnsignedInt(unsigned int);
  std::string getAndReleaseData();
  void writeUnsignedChar(unsigned char);
  void writeUnsignedInt64(unsigned long);
  void writeUnsignedShort(unsigned short);
  void writeUnsignedVarInt(unsigned int);
  void writeNormalizedFloat(float);
  void writeUnsignedVarInt64(unsigned long);
  void writeSignedBigEndianInt(int);
  void reset();
  void write(void const *, unsigned long);
  void reserve(unsigned long);
  void writeBool(bool);
  void writeByte(unsigned char);
  void writeStr(std::string_view sv) {
    writeUnsignedVarInt(sv.size());
    write(sv.data(), sv.size());
  }
  void writeVec3(const Vec3 &vc) {
    writeFloat(vc.x);
    writeFloat(vc.y);
    writeFloat(vc.z);
  }
  void writeString(gsl::basic_string_span<char const, -1l>);
};