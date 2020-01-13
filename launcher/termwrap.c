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
  printf("%.*s", (int) length, data);
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
      read(sfd, &fdsi, sizeof fdsi);
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

    copoll_ctx_ref_t ctx = copoll_init();
    copoll_start(ctx, get_input, NULL, 1024 * 8);
    copoll_start(ctx, get_output, NULL, 1024 * 8);
    copoll_start(ctx, sig_handler, NULL, 1024 * 8);
    copoll_fini(ctx);
    printf("done!\n");
    rl_callback_handler_remove();
  }
  return -1;
}