#pragma once
#include <functional>

#ifndef fp
#  define fp(a) ((void *) (a))
#endif

extern "C" {
void _ZN6PacketC2Ev(void *);
}

class BinaryStream;

class Packet {
  public:
  unsigned char getClientSubId() const;
};

class MyPkt : public Packet {
  public:
  void **vtbl;
  char filler[256];
  int id;
  std::function<void(void *, BinaryStream &)> realexe;
  static int dummy() { return 0; }
  static int getId(MyPkt &th) { return th.id; }
  static void execute_wr(MyPkt &th, BinaryStream &x) { th.realexe(&th, x); }
  const void *vtbls[7] = {
      fp(MyPkt::dummy),      fp(MyPkt::dummy), fp(MyPkt::getId),
      fp(MyPkt::dummy), // ret string
      fp(MyPkt::execute_wr), fp(MyPkt::dummy),
      fp(MyPkt::dummy) // disallow batch
  };
  void ParentInit() { _ZN6PacketC2Ev(this); }
  MyPkt(int idx, std::function<void(void *, BinaryStream &)> callb) {
    ParentInit();
    id      = idx;
    vtbl    = (void **) vtbls;
    realexe = callb;
  }
  MyPkt(int idx) {
    ParentInit();
    vtbl = (void **) vtbls;
    id   = idx;
  }
};