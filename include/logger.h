#pragma once

#include "bdlexport.h"

#ifdef __INTELLISENSE__
#  define MOD_NAME "intelisense"
#  define BDL_TAG "intelisense"
#endif

#ifndef MOD_NAME
#  error Please define mod name before include logger.h
#endif

#ifdef DEBUG
#  define do_log_debug(...) do_log_impl(MOD_NAME, __FILE__, __LINE__, 0, __VA_ARGS__)
#else
#  define do_log_debug(...)
#endif
#define do_log(...) do_log_impl(MOD_NAME, __FILE__, __LINE__, 1, __VA_ARGS__)

BDL_EXPORT void do_log_impl(char const *mod_name, char const *filename, int line, int level, char const *format, ...)
    __attribute__((format(printf, 5, 6)));