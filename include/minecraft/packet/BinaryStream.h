class BinaryStream {
public:
  void writeFloat(float);
  void writeString();
  void writeVarInt(int);
  void writeVarInt64(long);
  void writeSignedInt(int);
};