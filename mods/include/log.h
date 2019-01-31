#pragma once

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <vector>

extern "C" void mcpelauncher_log(int level, const char *tag, const char *data);

#define LogFuncDef(name, logLevel)                                                                                                                   \
  static void name(const char *tag, const char *text, ...) __attribute__((format(printf, 2, 3))) {                                                   \
    va_list args;                                                                                                                                    \
    va_start(args, text);                                                                                                                            \
    vlog(logLevel, tag, text, args);                                                                                                                 \
    va_end(args);                                                                                                                                    \
  }

enum class LogLevel {
  LOG_LEVEL_TRACE  = 0,
  LOG_LEVEL_DEBUG  = 1,
  LOG_LEVEL_INFO   = 2,
  LOG_LEVEL_NOTICE = 3,
  LOG_LEVEL_WARN   = 4,
  LOG_LEVEL_ERROR  = 5,
  LOG_LEVEL_FATAL  = 6,
};

class Log {

public:
  static inline const char *getLogLevelString(LogLevel lvl) {
    if (lvl == LogLevel::LOG_LEVEL_TRACE) return "Trace";
    if (lvl == LogLevel::LOG_LEVEL_DEBUG) return "Debug";
    if (lvl == LogLevel::LOG_LEVEL_INFO) return "Info";
    if (lvl == LogLevel::LOG_LEVEL_WARN) return "Warn";
    if (lvl == LogLevel::LOG_LEVEL_ERROR) return "Error";
    return "?";
  }

  static void vlog(LogLevel level, const char *tag, const char *text, va_list args) {
    char buffer[4096];
    char buffer2[4096];
    vsnprintf(buffer, sizeof(buffer), text, args);
    mcpelauncher_log((int)level, tag, buffer);
  }

  static void log(LogLevel level, const char *tag, const char *text, ...) {
    va_list args;
    va_start(args, text);
    vlog(level, tag, text, args);
    va_end(args);
  }

  LogFuncDef(trace, LogLevel::LOG_LEVEL_TRACE) LogFuncDef(debug, LogLevel::LOG_LEVEL_DEBUG) LogFuncDef(info, LogLevel::LOG_LEVEL_INFO)
      LogFuncDef(notice, LogLevel::LOG_LEVEL_NOTICE) LogFuncDef(warn, LogLevel::LOG_LEVEL_WARN) LogFuncDef(error, LogLevel::LOG_LEVEL_ERROR)
          LogFuncDef(fatal, LogLevel::LOG_LEVEL_FATAL)
};

#undef LogFuncDef