#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/queue.h>
#include <unistd.h>

struct copoll_ctx_t;
struct copoll_co_t;

typedef struct copoll_ctx_t copoll_ctx_t, *copoll_ctx_ref_t;
typedef struct copoll_co_t copoll_co_t, *copoll_co_ref_t;

#define CTX_PRIV copoll_co_ref_t
#include "ctx.h"

typedef void (*copoll_func_t)(copoll_co_ref_t co, void *priv);

struct copoll_co_t {
  copoll_ctx_ref_t ctx;
  ctx_ref_t coctx;
  copoll_func_t func;
  union {
    void *priv;
    uint32_t events;
  };
  int fd;
  bool forked;
  STAILQ_ENTRY(copoll_co_t) entry;
  char stack[0];
};

struct copoll_ctx_t {
  int epfd;
  int count;
  copoll_co_t main;
  copoll_co_ref_t running;
  STAILQ_HEAD(, copoll_co_t);
  STAILQ_HEAD(, copoll_co_t) dead;
};

#define COPOLL_IMPL
#include "copoll.h"

#define ASSERT_AND_RET(exp)                                                                                            \
  ({                                                                                                                   \
    typeof(exp) _tmp = exp;                                                                                            \
    assert(exp);                                                                                                       \
    _tmp;                                                                                                              \
  })

copoll_ctx_ref_t copoll_init() {
  copoll_ctx_ref_t ret = ASSERT_AND_RET(malloc(sizeof *ret));
  memset(ret, 0, sizeof *ret);
  ret->main.ctx = ret;
  ret->running  = &ret->main;
  ret->epfd     = ASSERT_AND_RET(epoll_create1(EPOLL_CLOEXEC));
  STAILQ_INIT(ret);
  STAILQ_INIT(&ret->dead);
  return ret;
}

inline static void copoll_switch(copoll_co_ref_t target) {
  copoll_ctx_ref_t ctx  = target->ctx;
  copoll_co_ref_t curco = ctx->running;
  ctx->running          = target;
  ctx_from_t from       = setctx(target->coctx, curco);
  from.priv->coctx      = from.coctx;
}

inline static void copoll_switch_next(copoll_ctx_ref_t ctx) {
  copoll_co_ref_t next = STAILQ_FIRST(ctx);
  if (next) {
    copoll_switch(next);
  } else {
    copoll_switch(&ctx->main);
  }
}

void copoll_fini(copoll_ctx_ref_t ctx) {
  // loop
  copoll_co_ref_t co;
  for (;;) {
    while ((co = STAILQ_FIRST(ctx))) { copoll_switch(co); }
    if (!ctx->count) break;
    struct epoll_event evt[8];
    int ret = epoll_wait(ctx->epfd, evt, 8, -1);
    for (int i = 0; i < ret; i++) {
      co         = (copoll_co_ref_t) evt[i].data.ptr;
      co->events = evt[i].events;
      STAILQ_INSERT_TAIL(ctx, co, entry);
    }
  };
  // todo cleanup dead

  // done!
  close(ctx->epfd);
  free(ctx);
}

bool copoll_fork(copoll_co_ref_t co, int fd, copoll_evt_ptr_t pevt) {
  copoll_ctx_ref_t ctx = co->ctx;
start:
  if (!co->forked) {
    struct epoll_event ev = {};
    ev.data.ptr           = co;
    ev.events             = pevt->evt;
    int ret               = epoll_ctl(ctx->epfd, EPOLL_CTL_ADD, fd, &ev);
    if (ret != 0) return false;
    co->fd = fd;
    ctx->count++;
    co->forked = true;
  } else if (co->fd != fd) {
    copoll_kill(co);
    goto start;
  }
  STAILQ_REMOVE(ctx, co, copoll_co_t, entry);
  copoll_switch_next(ctx);
  if (!co->forked) return false;
  pevt->evt = co->events;
  return true;
}

void copoll_kill(copoll_co_ref_t co) {
  if (!co->forked) return;
  copoll_ctx_ref_t ctx = co->ctx;
  co->forked           = false;
  ctx->count--;
  epoll_ctl(ctx->epfd, EPOLL_CTL_DEL, co->fd, NULL);
  if (ctx->running != co) copoll_switch(co);
}

static void trampoline(ctx_from_t from) {
  copoll_ctx_ref_t ctx = from.priv->ctx;
  from.priv->coctx     = from.coctx;
  copoll_co_ref_t self = ctx->running;
  self->func(self, self->priv);
  if (self->forked) copoll_kill(self);
  STAILQ_REMOVE(ctx, self, copoll_co_t, entry);
  STAILQ_INSERT_TAIL(&ctx->dead, self, entry);
  copoll_switch_next(ctx);
}

void copoll_start(copoll_ctx_ref_t ref, copoll_func_t func, void *priv, size_t stacksize) {
  copoll_co_ref_t co = ASSERT_AND_RET(malloc(sizeof *co + stacksize));
  memset(co, 0, sizeof *co);
  co->ctx   = ref;
  co->func  = func;
  co->priv  = priv;
  co->coctx = ASSERT_AND_RET(getctx(co->stack, stacksize, trampoline));
  STAILQ_INSERT_HEAD(ref, co, entry);
}