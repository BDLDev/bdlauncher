#pragma once
#include<cstring>
#include<unordered_map>
#include<sys/mman.h>
#include<cstdint>
#define fp(a) ((void*)(a))
#define fpm(a) fp(&a)
void* MyHook(void* oldunc, void* newfunc);
char* wr_jmp(void* addr);
typedef uint64_t u64;
char* wr_ret_uni(u64 ret,char* b);


