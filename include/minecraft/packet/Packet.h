#pragma once

#include <string>

class BinaryStream{
public:
void writeFloat(float);
void writeString();
void writeVarInt(int);
void writeVarInt64(long);
void writeSignedInt(int);
};
class ReadOnlyBinaryStream;

class Packet {
  char *filler[24];

public:
  Packet();
  virtual ~Packet();
  virtual int getId() const = 0;
  virtual std::string getName() const = 0;
  virtual void write(BinaryStream &) const = 0;
  virtual void read(ReadOnlyBinaryStream &) = 0;
  virtual bool disallowBatching(void) const = 0;
};
