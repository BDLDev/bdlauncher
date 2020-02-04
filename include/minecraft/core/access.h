#pragma once

#include <unistd.h>
// fix 
#ifndef access
#define access(ptr, type, off) (*((type *) (((uintptr_t) ptr) + off)))
#endif