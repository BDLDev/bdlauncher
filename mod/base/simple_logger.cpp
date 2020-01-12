#include <stdio.h>
#include <stdarg.h>
#include <MC.h>

BDL_EXPORT void do_log_impl(char const *mod_name, char const *filename, int line, char const *format, ...) {
  va_list vas;
  va_start(vas, format);
  char *buffer;
  vasprintf(&buffer, format, vas);
  va_end(vas);
  printf("[%s:%s:%d] %s\n", mod_name, filename, line, buffer);
}