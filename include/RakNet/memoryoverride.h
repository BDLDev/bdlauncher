#pragma once

#include <alloca.h>
#include <malloc.h>
#include <new>

// These pointers are statically and globally defined in RakMemoryOverride.cpp
// Change them to point to your own allocators if you want.
// Use the functions for a DLL, or just reassign the variable if using source
extern void *(*rakMalloc)(size_t size);
extern void *(*rakRealloc)(void *p, size_t size);
extern void (*rakFree)(void *p);
extern void *(*rakMalloc_Ex)(size_t size, const char *file, unsigned int line);
extern void *(*rakRealloc_Ex)(void *p, size_t size, const char *file, unsigned int line);
extern void (*rakFree_Ex)(void *p, const char *file, unsigned int line);
extern void (*notifyOutOfMemory)(const char *file, const long line);
extern void *(*dlMallocMMap)(size_t size);
extern void *(*dlMallocDirectMMap)(size_t size);
extern int (*dlMallocMUnmap)(void *ptr, size_t size);

// Change to a user defined allocation function
void SetMalloc(void *(*userFunction)(size_t size));
void SetRealloc(void *(*userFunction)(void *p, size_t size));
void SetFree(void (*userFunction)(void *p));
void SetMalloc_Ex(void *(*userFunction)(size_t size, const char *file, unsigned int line));
void SetRealloc_Ex(void *(*userFunction)(void *p, size_t size, const char *file, unsigned int line));
void SetFree_Ex(void (*userFunction)(void *p, const char *file, unsigned int line));
// Change to a user defined out of memory function
void SetNotifyOutOfMemory(void (*userFunction)(const char *file, const long line));
void SetDLMallocMMap(void *(*userFunction)(size_t size));
void SetDLMallocDirectMMap(void *(*userFunction)(size_t size));
void SetDLMallocMUnmap(int (*userFunction)(void *ptr, size_t size));

extern void *(*GetMalloc())(size_t size);
extern void *(*GetRealloc())(void *p, size_t size);
extern void (*GetFree())(void *p);
extern void *(*GetMalloc_Ex())(size_t size, const char *file, unsigned int line);
extern void *(*GetRealloc_Ex())(void *p, size_t size, const char *file, unsigned int line);
extern void (*GetFree_Ex())(void *p, const char *file, unsigned int line);
extern void *(*GetDLMallocMMap())(size_t size);
extern void *(*GetDLMallocDirectMMap())(size_t size);
extern int (*GetDLMallocMUnmap())(void *ptr, size_t size);

namespace RakNet {
template <class Type> Type *OP_NEW(const char *file, unsigned int line);
template <class Type> Type *OP_NEW_ARRAY(int count, const char *file, unsigned int line);
template <class Type> void OP_DELETE(Type *buff, const char *file, unsigned int line);
template <class Type> void OP_DELETE_ARRAY(Type *buff, const char *file, unsigned int line);

void *_RakMalloc(size_t size);
void *_RakRealloc(void *p, size_t size);
void _RakFree(void *p);
void *_RakMalloc_Ex(size_t size, const char *file, unsigned int line);
void *_RakRealloc_Ex(void *p, size_t size, const char *file, unsigned int line);
void _RakFree_Ex(void *p, const char *file, unsigned int line);
void *_DLMallocMMap(size_t size);
void *_DLMallocDirectMMap(size_t size);
int _DLMallocMUnmap(void *p, size_t size);
} // namespace RakNet

// Call to make RakNet allocate a large block of memory, and do all subsequent allocations in that memory block
// Initial and reallocations will be done through whatever function is pointed to by yourMMapFunction, and yourDirectMMapFunction (default is malloc)
// Allocations will be freed through whatever function is pointed to by yourMUnmapFunction (default free)
void UseRaknetFixedHeap(size_t initialCapacity, void *(*yourMMapFunction)(size_t size) = RakNet::_DLMallocMMap, void *(*yourDirectMMapFunction)(size_t size) = RakNet::_DLMallocDirectMMap,
                        int (*yourMUnmapFunction)(void *p, size_t size) = RakNet::_DLMallocMUnmap);

// Free memory allocated from UseRaknetFixedHeap
void FreeRakNetFixedHeap(void);