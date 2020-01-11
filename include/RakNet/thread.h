#pragma once

namespace RakNet {
/// To define a thread, use RAK_THREAD_DECLARATION(functionName);
#define RAK_THREAD_DECLARATION(functionName) void *functionName(void *arguments)

class RakThread {
public:
  /// Create a thread, simplified to be cross platform without all the extra junk
  /// To then start that thread, call RakCreateThread(functionName, arguments);
  /// \param[in] start_address Function you want to call
  /// \param[in] arglist Arguments to pass to the function
  /// \return 0=success. >0 = error code

  /*
  nice value 	Win32 Priority
  -20 to -16 	THREAD_PRIORITY_HIGHEST
  -15 to -6 	THREAD_PRIORITY_ABOVE_NORMAL
  -5 to +4 	THREAD_PRIORITY_NORMAL
  +5 to +14 	THREAD_PRIORITY_BELOW_NORMAL
  +15 to +19 	THREAD_PRIORITY_LOWEST
  */
  static int Create(void *start_address(void *), void *arglist, int priority = 0);
};

} // namespace RakNet