#pragma once

#include "MC.h"

#ifndef MOD_NAME
#  error Please define mod name before include logger.h
#endif

#define do_log(...) do_log_impl(MOD_NAME, __FILE__, __LINE__, __VA_ARGS__)

BDL_EXPORT void do_log_impl(char const *mod_name, char const *filename, int line, char const *format, ...)
    __attribute__((format(printf, 4, 5)));