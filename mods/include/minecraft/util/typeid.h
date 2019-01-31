#pragma once

#include "../extra/MinecraftHandle.h"

template <typename T>
struct typeid_t {
    static short count;

    short id;

    typeid_t() {
        id = count++;
    }
    typeid_t(typeid_t const& t) {
        id = t.id;
    }
};

template <typename T, typename T2>
typeid_t<T> type_id() {
    static typeid_t<T> id;
    return id;
};

template <typename T>
typeid_t<T> type_id_minecraft_symbol(const char* sym) {
    typeid_t<T>* id = (typeid_t<T>*) dlsym(MinecraftHandle(), sym);
    void* guard = (typeid_t<T>*) dlsym(MinecraftHandle(), std::string(sym).replace(0, 2, "_ZGV").c_str());
    static int (*guardAcquire)(void*) = (int (*)(void*)) dlsym(MinecraftHandle(), "__cxa_guard_acquire");
    static void (*guardRelease)(void*) = (void (*)(void*)) dlsym(MinecraftHandle(), "__cxa_guard_release");
    if (*((char*) guard) == 0 && guardAcquire(guard)) {
        new (id)typeid_t<T>();
        guardRelease(guard);
    }
    return *id;
};