#pragma once

#include "../../util.h"
#include "Packet.h"
#include<string>
#include<dlfcn.h>
using std::string;
struct ObjectiveSortOrder{
  unsigned char x;
  ObjectiveSortOrder(unsigned char y){
    x=y;
  }
};
class SetDisplayObjectivePacket {
  char filler[200];

public:
  SetDisplayObjectivePacket(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const& displaySlot, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const& objectiveName, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const& displayName, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const& criteriaName,char sortOrder)
  {
    void(*pp)(char*)=(typeof(pp))dlsym(NULL,"_ZN6PacketC2Ev");
    u64 vt=(u64)dlsym(NULL,"_ZTV25SetDisplayObjectivePacket");
    pp(filler);
    *((u64*)filler)=vt+16;
    new (filler+32) string(displaySlot);
    new (filler+64) string(objectiveName);
    new (filler+96) string(displayName);
    new (filler+128) string(criteriaName);
    filler[160]=sortOrder;

  }
  //{asm("call _ZN25SetDisplayObjectivePacketC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_S7_S7_18ObjectiveSortOrder;");}

  ~SetDisplayObjectivePacket(){
    //((string*)(filler+32))->~string();
    //((string*)(filler+64))->~string();
    //((string*)(filler+96))->~string();
    //((string*)(filler+128))->~string();
  } //{asm("call _ZN25SetDisplayObjectivePacketD2Ev;");}

};
class TransferPacket {
  char filler[100];

public:
  inline TransferPacket(string ip,short port)
  {
    void(*pp)(char*)=(typeof(pp))dlsym(NULL,"_ZN6PacketC2Ev");
    u64 vt=(u64)dlsym(NULL,"_ZTV14TransferPacket");
    printf("get %p\n",vt);
    pp(filler);
    *((u64*)filler)=vt+16;
    new (filler+32) string(ip);
    *((short*)(filler+16))=port;

  }

  inline ~TransferPacket(){
    ((string*)(filler+32))->~string();
  } 

};
