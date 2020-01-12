#pragma once

#include <unistd.h>

#ifdef __GNUC__
#  define CTX_EXPORT __attribute__((visibility("hidden")))
#else
#  define CTX_EXPORT
#endif

#ifndef CTX_PRIV
#  define CTX_PRIV void *
#endif

typedef struct {
} * ctx_ref_t;

typedef struct _ctx_from_t {
  ctx_ref_t coctx;
  CTX_PRIV priv;
} ctx_from_t;

typedef void (*ctx_func_t)(ctx_from_t from);

#ifdef __cplusplus
extern "C" {
#endif

CTX_EXPORT ctx_ref_t getctx(char *stackdata, size_t stacksize, ctx_func_t func);
CTX_EXPORT ctx_from_t setctx(ctx_ref_t context, void *priv);

#ifdef __cplusplus
}
#endif