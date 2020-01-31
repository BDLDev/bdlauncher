#include <stdio.h>
#include <stdarg.h>
//#include <MC.h>
#include <global.h>
#include <bdlexport.h>
#include <cstdlib>

static INLINE char get_log_level(int level) {
  switch (level) {
  case 0: return 'D';
  case 1: return 'I';
  default: return 'U';
  }
}

BDL_EXPORT void do_log_impl(char const *mod_name, char const *filename, int line, int level, char const *format, ...) {
  va_list vas;
  va_start(vas, format);
  char *buffer;
  vasprintf(&buffer, format, vas);
  defer_(buffer, free);
  va_end(vas);
  printf("%c [%s:%s:%d] %s\n", get_log_level(level), mod_name, filename, line, buffer);
}