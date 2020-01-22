static int logfd;
static int logsz;
static void initlog() {
  logfd = open("player.log", O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
  logsz = lseek(logfd, 0, SEEK_END);
}
static void async_log(const char *fmt, ...) {
  char buf[1024];
  auto x = time(0);
  va_list vl;
  va_start(vl, fmt);
  auto tim = strftime(buf, 128, "[%Y-%m-%d %H:%M:%S] ", localtime(&x));
  int s    = vsnprintf(buf + tim, 1024, fmt, vl) + tim;
  write(1, buf, s);
  write(logfd, buf, s);
  va_end(vl);
}