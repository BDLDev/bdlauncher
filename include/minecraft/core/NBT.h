#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>

#ifndef PATCHABLE
#define PATCHABLE
#endif

struct IDataInput;
struct IDataOutput;
struct PrintStream;

struct alignas(8) Tag {
  // ! NO FIELD ! //
  virtual ~Tag();
  virtual void deleteChildren();
  virtual void write(IDataOutput &) const = 0;
  virtual void load(IDataInput &)         = 0;
  virtual std::string toString() const    = 0;
  virtual int getId() const               = 0;
  virtual bool equals(Tag const &) const;
  virtual void print(PrintStream &) const;
  virtual void print(std::string const &, PrintStream &) const;
  virtual void setName(std::string const &);
  virtual std::string getName() const;
  virtual std::unique_ptr<Tag> copy() const;
};

struct EndTag : Tag {
  virtual ~EndTag();
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual std::string toString() const PATCHABLE;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

struct DoubleTag : Tag {
  double value;
  virtual ~DoubleTag();
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual std::string toString() const PATCHABLE;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

static_assert(sizeof(DoubleTag) == 16);

struct TagMemoryChunk {
  size_t m_cap, m_size;
  std::unique_ptr<unsigned char[]> m_data;

  template <typename T> T *alloc(unsigned long);
  TagMemoryChunk copy() const;
  unsigned char *data() const;
  bool operator==(TagMemoryChunk const &) const;
  size_t size() const;
};

static_assert(sizeof(TagMemoryChunk) == 24);

struct ByteArrayTag : Tag {
  TagMemoryChunk value;
  virtual ~ByteArrayTag();
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual std::string toString() const PATCHABLE;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

static_assert(sizeof(ByteArrayTag) == 32);

struct CompoundTag : Tag {
  std::map<std::string, std::unique_ptr<Tag>> value;
  virtual ~CompoundTag();
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual std::string toString() const PATCHABLE;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual void print(std::string const &, PrintStream &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

static_assert(sizeof(CompoundTag) == 56);

struct ListTag : Tag {
  std::vector<std::unique_ptr<Tag>> value;
  size_t unk;
  void add(std::unique_ptr<Tag>);
  virtual ~ListTag();
  virtual void deleteChildren();
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual std::string toString() const PATCHABLE;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual void print(std::string const &, PrintStream &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

static_assert(sizeof(ListTag) == 40);

struct FloatTag : Tag {
  float value;
  virtual ~FloatTag();
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual std::string toString() const PATCHABLE;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

static_assert(sizeof(FloatTag) == 16);

struct ByteTag : Tag {
  unsigned char value;
  virtual ~ByteTag();
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual std::string toString() const PATCHABLE;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

static_assert(sizeof(ByteTag) == 16);

struct ShortTag : Tag {
  short value;
  virtual ~ShortTag();
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual std::string toString() const PATCHABLE;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

static_assert(sizeof(ShortTag) == 16);

struct Int64Tag : Tag {
  int64_t value;
  virtual ~Int64Tag();
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual std::string toString() const PATCHABLE;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

static_assert(sizeof(Int64Tag) == 16);

struct IntArrayTag : Tag {
  TagMemoryChunk value;
  virtual ~IntArrayTag();
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual std::string toString() const PATCHABLE;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

static_assert(sizeof(IntArrayTag) == 32);

struct IntTag : Tag {
  int32_t value;
  virtual ~IntTag();
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual std::string toString() const PATCHABLE;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

static_assert(sizeof(IntTag) == 16);

struct StringTag : Tag {
  std::string value;
  virtual ~StringTag();
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual std::string toString() const PATCHABLE;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

static_assert(sizeof(StringTag) == 40);