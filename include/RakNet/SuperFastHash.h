#pragma once

#include <cstdint>
#include <cstdlib>

struct _IO_FILE;

uint32_t SuperFastHash(const char *data, int length);
uint32_t SuperFastHashIncremental(const char *data, int len, unsigned int lastHash);
uint32_t SuperFastHashFile(const char *filename);
uint32_t SuperFastHashFilePtr(_IO_FILE *fp);