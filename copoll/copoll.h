#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __GNUC__
#  define COPOLL_EXPORT __attribute__((visibility("default")))
#else
#  define COPOLL_EXPORT
#endif

typedef struct {
  uint32_t evt;
} copoll_evt_t, *copoll_evt_ptr_t;

#ifndef COPOLL_IMPL
typedef struct {
} * copoll_ctx_ref_t;

typedef struct {
  copoll_ctx_ref_t ctx;
} * copoll_co_ref_t;
#endif

typedef void (*copoll_func_t)(copoll_co_ref_t co, void *priv);

#ifdef __cplusplus
extern "C" {
#endif

COPOLL_EXPORT copoll_ctx_ref_t copoll_init();
COPOLL_EXPORT void copoll_fini(copoll_ctx_ref_t ref);

COPOLL_EXPORT bool copoll_fork(copoll_co_ref_t ref, int fd, copoll_evt_ptr_t pevt);
COPOLL_EXPORT void copoll_kill(copoll_co_ref_t ref);
COPOLL_EXPORT void copoll_start(copoll_ctx_ref_t ref, copoll_func_t func, void *priv, size_t stacksize);

#ifdef __cplusplus
}
#endif