#pragma once
extern "C" {
void _ZTV12ServerPlayer(void); // dummy
}

// utils for runtime type detecting
static auto vtSP = ((void **) _ZTV12ServerPlayer) + 2; //((void **)dlsym(NULL, "_ZTV12ServerPlayer") + 2);