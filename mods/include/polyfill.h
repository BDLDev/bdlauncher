#pragma once
#include <string>
#include <sstream>
#include <cstdlib>

//Make vscode's C++ extension happy
#ifdef DIAG

template <typename T>
void *operator new(unsigned long, T *) {
    return nullptr;
}

#endif

namespace std
{
template <typename T>
std::string to_string(T val)
{
  std::stringstream ss;
  ss << val;
  return ss.str();
}

#define STRING_TO_INT_CONVERTER(name,type,func)	\
inline type name (const string& str, size_t* idx = nullptr, int base = 10) \
{					\
    const char* sp = str.c_str();	\
    char* endp = nullptr;		\
    type r = func (sp, idx ? &endp : nullptr, base);\
    if (idx)				\
	*idx = endp - sp;		\
    return r;				\
}
STRING_TO_INT_CONVERTER(stoi,int,strtol)
STRING_TO_INT_CONVERTER(stol,long,strtol)
STRING_TO_INT_CONVERTER(stoul,unsigned long,strtoul)
STRING_TO_INT_CONVERTER(stoll,long long,strtoll)
STRING_TO_INT_CONVERTER(stoull,unsigned long long,strtoull)
#undef STRING_TO_INT_CONVERTER

#define STRING_TO_FLOAT_CONVERTER(name,type,func) \
inline type name (const string& str, size_t* idx = nullptr) \
{					\
    const char* sp = str.c_str();	\
    char* endp = nullptr;		\
    type r = func (sp, idx ? &endp : nullptr);\
    if (idx)				\
	*idx = endp - sp;		\
    return r;				\
}
STRING_TO_FLOAT_CONVERTER(stof,float,strtof)
STRING_TO_FLOAT_CONVERTER(stod,double,strtod)
STRING_TO_FLOAT_CONVERTER(stold,long double,strtold)
#undef STRING_TO_FLOAT_CONVERTER

} // namespace std