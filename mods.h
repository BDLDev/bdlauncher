#ifndef MODS_H
#define MODS_H
#include<cstdint>
void* MCHandle();
void MOD_loadall();
void* MCHook(std::string&& name,void* func);
#define MCHok(a,b,c) c=(typeof(c))MCHook(a,(void*)b)
typedef uint64_t u64;
typedef uint32_t u32;
typedef int64_t s64;
typedef int32_t s32;
typedef u64(*fn_6)(void*) ;
typedef u64(*fn_)(void) ;
typedef u64(*fn_66)(void*,void*) ;
#endif
