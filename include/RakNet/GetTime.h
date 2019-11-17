#pragma once

#include "time.h"

namespace RakNet {

/// Same as GetTimeMS
/// Holds the time in either a 32 or 64 bit variable, depending on __GET_TIME_64BIT
Time GetTime(void);

/// Return the time as 32 bit
/// \note The maximum delta between returned calls is 1 second - however, RakNet calls this constantly anyway. See NormalizeTime() in the cpp.
TimeMS GetTimeMS(void);

/// Return the time as 64 bit
/// \note The maximum delta between returned calls is 1 second - however, RakNet calls this constantly anyway. See NormalizeTime() in the cpp.
TimeUS GetTimeUS(void);

/// a > b?
extern bool GreaterThan(Time a, Time b);
/// a < b?
extern bool LessThan(Time a, Time b);
} // namespace RakNet