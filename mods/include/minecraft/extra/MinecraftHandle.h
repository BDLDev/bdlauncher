#pragma once

#include <dlfcn.h>

namespace {
void* MinecraftHandle() {
    static void* handle = dlopen(NULL, RTLD_LAZY);
    return handle;
}
}