#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <pty.h>
#include <sys/socket.h>
#include <sys/prctl.h>
#include <sys/epoll.h>
#include <sys/signalfd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <copoll.h>

#include "termwrap.h"
#include "exec_server.h"

static int pid;
static char *prompt = "> ";
static int ptyfd    = 0;
static FILE *ptyfile;
static copoll_co_ref_t readline_co = NULL, output_co = NULL;

void handle_line(char *line) {
  if (line) {
    add_history(line);
    fprintf(ptyfile, "%s\n", line);
  } else
    printf("\r");
}

void wrap_output(char *data, ssize_t length) {
  char *saved_line;
  int saved_point;
  saved_point = rl_point;
  saved_line  = rl_copy_text(0, rl_end);
  rl_set_prompt("");
  rl_replace_line("", 0);
  rl_redisplay();
  while (length--) {
    char unsigned ch = (char unsigned) *data++;
    switch (ch) {
    case '\n': puts("\e[0m"); break;
    case 0xc2: {
      if (!length-- || !length--) continue;
      ++data;
      switch (*data++) {
#define PUTCOL(c, color, code)                                                                                         \
  case c: fputs("\e[" code "m", stdout); break
        PUTCOL('0', #000000, "30;107");
        PUTCOL('1', #0000AA, "38;2;0;0;170");
        PUTCOL('2', #00AA00, "38;2;0;170;0");
        PUTCOL('3', #00AAAA, "38;2;0;170;170");
        PUTCOL('4', #AA0000, "38;2;170;0;0");
        PUTCOL('5', #AA00AA, "38;2;170;0;170");
        PUTCOL('6', #FFAA00, "38;2;255;170;0");
        PUTCOL('7', #AAAAAA, "38;2;170;170;170");
        PUTCOL('8', #555555, "38;2;85;85;85");
        PUTCOL('9', #5555FF, "38;2;85;85;255");
        PUTCOL('a', #55FF55, "38;2;85;255;85");
        PUTCOL('b', #55FFFF, "38;2;85;255;255");
        PUTCOL('c', #FF5555, "38;2;255;85;85");
        PUTCOL('d', #FF55FF, "38;2;255;85;255");
        PUTCOL('e', #FFFF55, "38;2;255;255;85");
        PUTCOL('f', #FFFFFF, "97;40");
        PUTCOL('g', #DDD605, "38;2;221;214;5");
        // Special effect
        PUTCOL('k', Obfuscated, "5");
        PUTCOL('l', Bold, "1");
        PUTCOL('m', Strikethrough, "9");
        PUTCOL('n', Underline, "4");
        PUTCOL('o', Italic, "3");
        PUTCOL('r', Reset, "0");
#undef PUTCOL
      default: break;
      }
    } break;
    default: putc(ch, stdout);
    }
  }
  rl_set_prompt(prompt);
  rl_replace_line(saved_line, 0);
  rl_point = saved_point;
  rl_redisplay();
  free(saved_line);
}

void get_input(copoll_co_ref_t co, void *priv) {
  readline_co      = co;
  copoll_evt_t evt = {EPOLLIN | EPOLLERR | EPOLLHUP};
  while (copoll_fork(co, 0, &evt)) {
    if (evt.evt == EPOLLIN) { rl_callback_read_char(); }
  }
  readline_co = 0;
}

void get_output(copoll_co_ref_t co, void *priv) {
  static char output_buffer[16384];
  output_co        = co;
  copoll_evt_t evt = {EPOLLIN | EPOLLERR | EPOLLHUP};
  while (copoll_fork(co, ptyfd, &evt)) {
    if (evt.evt == EPOLLIN) {
      ssize_t size = read(ptyfd, output_buffer, sizeof output_buffer);
      wrap_output(output_buffer, size);
    }
  }
  output_co = 0;
}

void sig_handler(copoll_co_ref_t co, void *priv) {
  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask, SIGINT);
  sigaddset(&mask, SIGQUIT);
  sigaddset(&mask, SIGTERM);
  sigaddset(&mask, SIGCHLD);
  sigprocmask(SIG_BLOCK, &mask, NULL);

  int sfd = signalfd(-1, &mask, 0);
  if (sfd == -1) {
    perror("signalfd");
    return;
  }
  copoll_evt_t evt = {EPOLLIN | EPOLLERR | EPOLLHUP};
  while (copoll_fork(co, sfd, &evt)) {
    struct signalfd_siginfo fdsi;
    if (evt.evt == EPOLLIN) {
      assert(read(sfd, &fdsi, sizeof fdsi) == sizeof fdsi);
      if (fdsi.ssi_signo == SIGCHLD) {
        int status;
        wait(&status);
        if (!WIFEXITED(status)) continue;
        if (readline_co) copoll_kill(readline_co);
        if (output_co) copoll_kill(output_co);
        copoll_kill(co);
        break;
      } else {
        kill(pid, SIGINT);
        if (readline_co) copoll_kill(readline_co);
      }
    }
  }
}

int termwrap() {
  pid = forkpty(&ptyfd, NULL, NULL, NULL);
  if (pid == -1) {
    perror("fork");
    return -errno;
  } else if (pid == 0) {
    prctl(PR_SET_PDEATHSIG, SIGTERM);
    setsid();
    return exec_server();
  } else {
    struct termios t;
    tcgetattr(ptyfd, &t);
    t.c_lflag &= ~((tcflag_t) ECHO);
    tcsetattr(ptyfd, TCSANOW, &t);
    ptyfile = fdopen(ptyfd, "w");
    rl_callback_handler_install(prompt, handle_line);
    rl_bind_key('\t', rl_insert);
    read_history(".bdlauncher_history");

    copoll_ctx_ref_t ctx = copoll_init();
    copoll_start(ctx, get_input, NULL, 1024 * 8);
    copoll_start(ctx, get_output, NULL, 1024 * 8);
    copoll_start(ctx, sig_handler, NULL, 1024 * 8);
    copoll_fini(ctx);
    printf("\rdone!\n");
    write_history(".bdlauncher_history");
    rl_callback_handler_remove();
    return 0;
  }
}