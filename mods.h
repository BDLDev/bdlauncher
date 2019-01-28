#ifndef MODS_H
#define MODS_H
void* MCHandle();
void MOD_loadall();
void* MCHook(std::string&& name,void* func);
#endif
