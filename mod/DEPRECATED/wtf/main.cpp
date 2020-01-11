#include<Loader.h>
#include<MC.h>
#include"../base/base.h"
#include"../cmdhelper.h"
extern "C" {
   BDL_EXPORT void mod_init(std::list<string>& modlist);
}
extern void load_helper(std::list<string>& modlist);
typedef signed long __int64;
typedef unsigned long _QWORD;
typedef unsigned int _DWORD;
typedef unsigned char _BYTE;
THook(__int64,_ZN12LayerDetails9LayerBase11_nextRandomERljl,void *thi, unsigned int a2, __int64 a3)
{
  unsigned int v4; // [rsp+0h] [rbp-2Ch]
  signed int v5; // [rsp+10h] [rbp-1Ch]

  v5 = (*(_QWORD *)thi >> 24) % (__int64)(unsigned int)a2;
  *(_QWORD *)thi *= 6364136223846793005LL * *(_QWORD *)thi + 1442695040888963407LL;
  *(_QWORD *)thi += a3;
  if ( v5 >= 0 )
    v4 = v5;
  else
    v4 = (_DWORD)a2 + v5;
  return v4;
}

THook(void *,_ZN4Core6Random16_initGenRandFastEj,void *thi, unsigned int a2)
{
  void *result; // rax
  int i; // [rsp+10h] [rbp-18h]
  unsigned int v4; // [rsp+18h] [rbp-10h]

  *((_DWORD *)thi + 1) = a2;
  v4 = a2;
  for ( i = 1; i < 398; ++i )
  {
    *((_DWORD *)thi + i + 1) = i + 1812433253 * ((v4 >> 30) ^ v4);
    v4 = i + 1812433253 * ((v4 >> 30) ^ v4);
  }
  result = thi;
  *((_DWORD *)thi + 625) = 624;
  *((_DWORD *)thi + 628) = 398;
  return result;
}

THook(void *,_ZN4Core6Random12_initGenRandEj,void *thi, int a2)
{
  void *result; // rax

  *((_DWORD *)thi + 1) = a2;
  for ( *((_DWORD *)thi + 625) = 1; *((_DWORD *)thi + 625) < 624; ++*((_DWORD *)thi + 625) )
    *((_DWORD *)thi + *((int *)thi + 625) + 1) = *((_DWORD *)thi + 625)
                                                 + 1812433253
                                                 * ((*((_DWORD *)thi + *((_DWORD *)thi + 625)) >> 30) ^ *((_DWORD *)thi + *((_DWORD *)thi + 625)));
  result = thi;
  *((_DWORD *)thi + 628) = 624;
  return result;
}
void * _ZN4Core6Random12_initGenRandEj(void *thi, int a2)
{
  void *result; // rax

  *((_DWORD *)thi + 1) = a2;
  for ( *((_DWORD *)thi + 625) = 1; *((_DWORD *)thi + 625) < 624; ++*((_DWORD *)thi + 625) )
    *((_DWORD *)thi + *((int *)thi + 625) + 1) = *((_DWORD *)thi + 625)
                                                 + 1812433253
                                                 * ((*((_DWORD *)thi + *((_DWORD *)thi + 625)) >> 30) ^ *((_DWORD *)thi + *((_DWORD *)thi + 625)));
  result = thi;
  *((_DWORD *)thi + 628) = 624;
  return result;
}
unsigned int dword_9056508[]={0, 0x9908B0DF};
THook(__int64,_ZN4Core6Random13_genRandInt32Ev,void *thi)
{
  int v1; // eax
  unsigned int v3; // [rsp+14h] [rbp-Ch]
  unsigned int v4; // [rsp+14h] [rbp-Ch]

  if ( *((_DWORD *)thi + 625) < 625 )
  {
    if ( *((_DWORD *)thi + 625) == 624 )
      *((_DWORD *)thi + 625) = 0;
  }
  else
  {
    _ZN4Core6Random12_initGenRandEj(thi, 5489);
    *((_DWORD *)thi + 625) = 0;
  }
  if ( *((_DWORD *)thi + 625) >= 227 )
  {
    if ( *((_DWORD *)thi + 625) >= 623 )
      *((_DWORD *)thi + 624) = dword_9056508[*((_BYTE *)thi + 4) & 1] ^ ((*((_DWORD *)thi + 1) & 0x7FFFFFFF | *((_DWORD *)thi + 624) & 0x80000000) >> 1) ^ *((_DWORD *)thi + 397);
    else
      *((_DWORD *)thi + *((int *)thi + 625) + 1) = dword_9056508[*((_BYTE *)thi + 4 * *((_DWORD *)thi + 625) + 8) & 1] ^ ((*((_DWORD *)thi + *((_DWORD *)thi + 625) + 2) & 0x7FFFFFFF | *((_DWORD *)thi + *((int *)thi + 625) + 1) & 0x80000000) >> 1) ^ *((_DWORD *)thi + *((_DWORD *)thi + 625) - 226);
  }
  else
  {
    *((_DWORD *)thi + *((int *)thi + 625) + 1) = dword_9056508[*((_BYTE *)thi + 4 * *((_DWORD *)thi + 625) + 8) & 1] ^ ((*((_DWORD *)thi + *((_DWORD *)thi + 625) + 2) & 0x7FFFFFFF | *((_DWORD *)thi + *((int *)thi + 625) + 1) & 0x80000000) >> 1) ^ *((_DWORD *)thi + *((_DWORD *)thi + 625) + 398);
    if ( *((_DWORD *)thi + 628) < 624 )
    {
      *((_DWORD *)thi + *((int *)thi + 628) + 1) = *((_DWORD *)thi + 628)
                                                   + 1812433253
                                                   * ((*((_DWORD *)thi + *((_DWORD *)thi + 628)) >> 30) ^ *((_DWORD *)thi + *((_DWORD *)thi + 628)));
      ++*((_DWORD *)thi + 628);
    }
  }
  v1 = (*((_DWORD *)thi + 625))++;
  v3 = *((_DWORD *)thi + v1 + 1);
  v4 = ((v3 ^ (v3 >> 11)) << 7) & 0x9D2C5680 ^ v3 ^ (v3 >> 11);
  return (v4 << 15) & 0xEFC60000 ^ v4 ^ (((v4 << 15) & 0xEFC60000 ^ v4) >> 18);
}
void mod_init(std::list<string>& modlist){
    printf("[wtf] loaded! V2019-12-14\n");
    load_helper(modlist);
}
