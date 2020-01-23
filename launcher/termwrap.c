#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/prctl.h>
#include <sys/epoll.h>
#include <sys/signalfd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <pty.h>
#include <sys/poll.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "termwrap.h"
#include "exec_server.h"

static int pid;
static char *prompt = "> ";
static int logfd;
static int ptyfd = 0;
static FILE *ptyfile;
void handle_line(char *line) {
  if (line) {
    add_history(line);
    fprintf(ptyfile, "%s\n", line);
  } else
    printf("\r");
}
void write_log(char *data, ssize_t length) {
  if (logfd) {
    ssize_t sz=write(logfd, data, length);
    if(sz<0) return; //MUST USE RETVAL
  }
}
void init_log(const char *logname) {
  logfd = open(logname, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
  if (logfd == -1) {
    perror("open log");
    exit(1);
  }
  write_log("---starting server---\n", strlen("---starting server---\n"));
}

void wrap_output(char *data, ssize_t length) {
  char *saved_line;
  int saved_point;
  saved_point = rl_point;
  saved_line  = rl_copy_text(0, rl_end);
  rl_set_prompt("");
  rl_replace_line("", 0);
  rl_redisplay();
  write_log(data, length);
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
  rl_free(saved_line);
}

int make_sig_handler() {
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
    exit(1);
  }
  return sfd;
}

int termwrap(const char *logfile) {
  pid = forkpty(&ptyfd, NULL, NULL, NULL);
  if (pid == -1) {
    perror("vfork");
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
    if (logfile) { init_log(logfile); }
    rl_callback_handler_install(prompt, handle_line);
    rl_bind_key('\t', rl_insert);
    read_history(".bdlauncher_history");
    struct pollfd pollfds[3];
    pollfds[0].fd     = STDIN_FILENO;
    pollfds[0].events = POLLIN;
    pollfds[1].fd     = ptyfd;
    pollfds[1].events = POLLIN | POLLERR;
    pollfds[2].fd     = make_sig_handler();
    pollfds[2].events = POLLIN;
    int DO_POLL       = 1;
    while (DO_POLL) {
      switch (poll(pollfds, 3, 1200000)) {
      case -1: perror("poll"); break;
      case 0: break;
      default: {
        if (pollfds[0].revents & POLLIN) { rl_callback_read_char(); }
        if (pollfds[1].revents & POLLIN) {
          char l_buf[4096];
          ssize_t sz = read(ptyfd, l_buf, 4096);
          if (sz > 0) wrap_output(l_buf, sz);
        }
        if (pollfds[1].revents & POLLERR) {
          printf("err\n");
          DO_POLL = 0;
        }
        if (pollfds[2].revents & POLLIN) {
          struct signalfd_siginfo fdsi;
          assert(read(pollfds[2].fd, &fdsi, sizeof fdsi) == sizeof fdsi);
          if (fdsi.ssi_signo == SIGCHLD) {
            int status;
            wait(&status);
            if (WIFEXITED(status)) {
              char buf[512];
              wrap_output(buf, snprintf(buf, 512, "---server stopped and returned %d---\n", WEXITSTATUS(status)));
              DO_POLL = 0;
            }
            if (WIFSIGNALED(status)) {
              char buf[512];
              wrap_output(buf, snprintf(buf, 512, "---server stopped by signal %d---\n", WTERMSIG(status)));
              DO_POLL = 0;
            }
            if (WIFSTOPPED(status)) { printf("---server stopped by signal,attached by a debugger?? ---\n"); }
            break;
          } else {
            kill(pid, SIGINT);
          }
        }
      } break;
      }
    }
    printf("\rdone!\n");
    write_history(".bdlauncher_history");
    rl_callback_handler_remove();
    return 0;
  }
}