# 1 "cmdhelper.h"
# 1 "<built-in>"
# 1 "<命令行>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<命令行>" 2
# 1 "cmdhelper.h"
       
# 1 "myhook.h" 1
       
# 1 "/usr/include/c++/9.2.0/cstring" 1 3
# 39 "/usr/include/c++/9.2.0/cstring" 3
       
# 40 "/usr/include/c++/9.2.0/cstring" 3

# 1 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++config.h" 1 3
# 252 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++config.h" 3

# 252 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++config.h" 3
namespace std
{
  typedef long unsigned int size_t;
  typedef long int ptrdiff_t;


  typedef decltype(nullptr) nullptr_t;

}
# 274 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++config.h" 3
namespace std
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
namespace __gnu_cxx
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
# 524 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++config.h" 3
# 1 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/os_defines.h" 1 3
# 39 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/os_defines.h" 3
# 1 "/usr/include/features.h" 1 3 4
# 450 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 460 "/usr/include/sys/cdefs.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 461 "/usr/include/sys/cdefs.h" 2 3 4
# 1 "/usr/include/bits/long-double.h" 1 3 4
# 462 "/usr/include/sys/cdefs.h" 2 3 4
# 451 "/usr/include/features.h" 2 3 4
# 474 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4
# 10 "/usr/include/gnu/stubs.h" 3 4
# 1 "/usr/include/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/gnu/stubs.h" 2 3 4
# 475 "/usr/include/features.h" 2 3 4
# 40 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/os_defines.h" 2 3
# 525 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++config.h" 2 3


# 1 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/cpu_defines.h" 1 3
# 528 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++config.h" 2 3
# 42 "/usr/include/c++/9.2.0/cstring" 2 3
# 1 "/usr/include/string.h" 1 3 4
# 26 "/usr/include/string.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/string.h" 2 3 4

extern "C" {




# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 1 3 4
# 209 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 34 "/usr/include/string.h" 2 3 4
# 42 "/usr/include/string.h" 3 4
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) throw () __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));





extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));




extern void *memset (void *__s, int __c, size_t __n) throw () __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));



extern "C++"
{
extern void *memchr (void *__s, int __c, size_t __n)
      throw () __asm ("memchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern const void *memchr (const void *__s, int __c, size_t __n)
      throw () __asm ("memchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 88 "/usr/include/string.h" 3 4
}
# 98 "/usr/include/string.h" 3 4
extern "C++" void *rawmemchr (void *__s, int __c)
     throw () __asm ("rawmemchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern "C++" const void *rawmemchr (const void *__s, int __c)
     throw () __asm ("rawmemchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));







extern "C++" void *memrchr (void *__s, int __c, size_t __n)
      throw () __asm ("memrchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern "C++" const void *memrchr (const void *__s, int __c, size_t __n)
      throw () __asm ("memrchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 121 "/usr/include/string.h" 3 4
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     throw () __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     throw () __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) throw () __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (2)));



# 1 "/usr/include/bits/types/locale_t.h" 1 3 4
# 22 "/usr/include/bits/types/locale_t.h" 3 4
# 1 "/usr/include/bits/types/__locale_t.h" 1 3 4
# 28 "/usr/include/bits/types/__locale_t.h" 3 4
struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;
# 23 "/usr/include/bits/types/locale_t.h" 2 3 4

typedef __locale_t locale_t;
# 153 "/usr/include/string.h" 2 3 4


extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));


extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) throw () __attribute__ ((__nonnull__ (2, 4)));





extern char *strdup (const char *__s)
     throw () __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     throw () __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 203 "/usr/include/string.h" 3 4
extern "C++"
{
extern char *strchr (char *__s, int __c)
     throw () __asm ("strchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern const char *strchr (const char *__s, int __c)
     throw () __asm ("strchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 223 "/usr/include/string.h" 3 4
}






extern "C++"
{
extern char *strrchr (char *__s, int __c)
     throw () __asm ("strrchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern const char *strrchr (const char *__s, int __c)
     throw () __asm ("strrchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 250 "/usr/include/string.h" 3 4
}
# 260 "/usr/include/string.h" 3 4
extern "C++" char *strchrnul (char *__s, int __c)
     throw () __asm ("strchrnul") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern "C++" const char *strchrnul (const char *__s, int __c)
     throw () __asm ("strchrnul") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 272 "/usr/include/string.h" 3 4
extern size_t strcspn (const char *__s, const char *__reject)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern "C++"
{
extern char *strpbrk (char *__s, const char *__accept)
     throw () __asm ("strpbrk") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern const char *strpbrk (const char *__s, const char *__accept)
     throw () __asm ("strpbrk") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 300 "/usr/include/string.h" 3 4
}






extern "C++"
{
extern char *strstr (char *__haystack, const char *__needle)
     throw () __asm ("strstr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern const char *strstr (const char *__haystack, const char *__needle)
     throw () __asm ("strstr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 327 "/usr/include/string.h" 3 4
}







extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     throw () __attribute__ ((__nonnull__ (2)));



extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     throw () __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     throw () __attribute__ ((__nonnull__ (2, 3)));





extern "C++" char *strcasestr (char *__haystack, const char *__needle)
     throw () __asm ("strcasestr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern "C++" const char *strcasestr (const char *__haystack,
         const char *__needle)
     throw () __asm ("strcasestr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 368 "/usr/include/string.h" 3 4
extern void *memmem (const void *__haystack, size_t __haystacklen,
       const void *__needle, size_t __needlelen)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 3)));



extern void *__mempcpy (void *__restrict __dest,
   const void *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));
extern void *mempcpy (void *__restrict __dest,
        const void *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));




extern size_t strlen (const char *__s)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern size_t strnlen (const char *__string, size_t __maxlen)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern char *strerror (int __errnum) throw ();
# 420 "/usr/include/string.h" 3 4
extern char *strerror_r (int __errnum, char *__buf, size_t __buflen)
     throw () __attribute__ ((__nonnull__ (2))) ;





extern char *strerror_l (int __errnum, locale_t __l) throw ();



# 1 "/usr/include/strings.h" 1 3 4
# 23 "/usr/include/strings.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 1 3 4
# 24 "/usr/include/strings.h" 2 3 4






extern "C" {



extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bcopy (const void *__src, void *__dest, size_t __n)
  throw () __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) throw () __attribute__ ((__nonnull__ (1)));



extern "C++"
{
extern char *index (char *__s, int __c)
     throw () __asm ("index") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern const char *index (const char *__s, int __c)
     throw () __asm ("index") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 66 "/usr/include/strings.h" 3 4
}







extern "C++"
{
extern char *rindex (char *__s, int __c)
     throw () __asm ("rindex") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern const char *rindex (const char *__s, int __c)
     throw () __asm ("rindex") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 94 "/usr/include/strings.h" 3 4
}
# 104 "/usr/include/strings.h" 3 4
extern int ffs (int __i) throw () __attribute__ ((__const__));





extern int ffsl (long int __l) throw () __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     throw () __attribute__ ((__const__));



extern int strcasecmp (const char *__s1, const char *__s2)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));






extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));



extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));


}
# 432 "/usr/include/string.h" 2 3 4



extern void explicit_bzero (void *__s, size_t __n) throw () __attribute__ ((__nonnull__ (1)));



extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     throw () __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) throw ();


extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     throw () __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     throw () __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));




extern int strverscmp (const char *__s1, const char *__s2)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strfry (char *__string) throw () __attribute__ ((__nonnull__ (1)));


extern void *memfrob (void *__s, size_t __n) throw () __attribute__ ((__nonnull__ (1)));







extern "C++" char *basename (char *__filename)
     throw () __asm ("basename") __attribute__ ((__nonnull__ (1)));
extern "C++" const char *basename (const char *__filename)
     throw () __asm ("basename") __attribute__ ((__nonnull__ (1)));
# 498 "/usr/include/string.h" 3 4
}
# 43 "/usr/include/c++/9.2.0/cstring" 2 3
# 71 "/usr/include/c++/9.2.0/cstring" 3
extern "C++"
{
namespace std __attribute__ ((__visibility__ ("default")))
{


  using ::memchr;
  using ::memcmp;
  using ::memcpy;
  using ::memmove;
  using ::memset;
  using ::strcat;
  using ::strcmp;
  using ::strcoll;
  using ::strcpy;
  using ::strcspn;
  using ::strerror;
  using ::strlen;
  using ::strncat;
  using ::strncmp;
  using ::strncpy;
  using ::strspn;
  using ::strtok;
  using ::strxfrm;
  using ::strchr;
  using ::strpbrk;
  using ::strrchr;
  using ::strstr;
# 122 "/usr/include/c++/9.2.0/cstring" 3

}
}
# 3 "myhook.h" 2
# 1 "/usr/include/c++/9.2.0/unordered_map" 1 3
# 32 "/usr/include/c++/9.2.0/unordered_map" 3
       
# 33 "/usr/include/c++/9.2.0/unordered_map" 3





# 1 "/usr/include/c++/9.2.0/type_traits" 1 3
# 32 "/usr/include/c++/9.2.0/type_traits" 3
       
# 33 "/usr/include/c++/9.2.0/type_traits" 3







namespace std __attribute__ ((__visibility__ ("default")))
{

# 56 "/usr/include/c++/9.2.0/type_traits" 3
  template<typename _Tp, _Tp __v>
    struct integral_constant
    {
      static constexpr _Tp value = __v;
      typedef _Tp value_type;
      typedef integral_constant<_Tp, __v> type;
      constexpr operator value_type() const noexcept { return value; }




      constexpr value_type operator()() const noexcept { return value; }

    };

  template<typename _Tp, _Tp __v>
    constexpr _Tp integral_constant<_Tp, __v>::value;


  typedef integral_constant<bool, true> true_type;


  typedef integral_constant<bool, false> false_type;

  template<bool __v>
    using __bool_constant = integral_constant<bool, __v>;
# 91 "/usr/include/c++/9.2.0/type_traits" 3
  template<bool, typename, typename>
    struct conditional;

  template<typename...>
    struct __or_;

  template<>
    struct __or_<>
    : public false_type
    { };

  template<typename _B1>
    struct __or_<_B1>
    : public _B1
    { };

  template<typename _B1, typename _B2>
    struct __or_<_B1, _B2>
    : public conditional<_B1::value, _B1, _B2>::type
    { };

  template<typename _B1, typename _B2, typename _B3, typename... _Bn>
    struct __or_<_B1, _B2, _B3, _Bn...>
    : public conditional<_B1::value, _B1, __or_<_B2, _B3, _Bn...>>::type
    { };

  template<typename...>
    struct __and_;

  template<>
    struct __and_<>
    : public true_type
    { };

  template<typename _B1>
    struct __and_<_B1>
    : public _B1
    { };

  template<typename _B1, typename _B2>
    struct __and_<_B1, _B2>
    : public conditional<_B1::value, _B2, _B1>::type
    { };

  template<typename _B1, typename _B2, typename _B3, typename... _Bn>
    struct __and_<_B1, _B2, _B3, _Bn...>
    : public conditional<_B1::value, __and_<_B2, _B3, _Bn...>, _B1>::type
    { };

  template<typename _Pp>
    struct __not_
    : public __bool_constant<!bool(_Pp::value)>
    { };
# 185 "/usr/include/c++/9.2.0/type_traits" 3
  template<typename _Tp>
    struct __success_type
    { typedef _Tp type; };

  struct __failure_type
  { };



  template<typename>
    struct remove_cv;

  template<typename>
    struct __is_void_helper
    : public false_type { };

  template<>
    struct __is_void_helper<void>
    : public true_type { };


  template<typename _Tp>
    struct is_void
    : public __is_void_helper<typename remove_cv<_Tp>::type>::type
    { };

  template<typename>
    struct __is_integral_helper
    : public false_type { };

  template<>
    struct __is_integral_helper<bool>
    : public true_type { };

  template<>
    struct __is_integral_helper<char>
    : public true_type { };

  template<>
    struct __is_integral_helper<signed char>
    : public true_type { };

  template<>
    struct __is_integral_helper<unsigned char>
    : public true_type { };


  template<>
    struct __is_integral_helper<wchar_t>
    : public true_type { };
# 243 "/usr/include/c++/9.2.0/type_traits" 3
  template<>
    struct __is_integral_helper<char16_t>
    : public true_type { };

  template<>
    struct __is_integral_helper<char32_t>
    : public true_type { };

  template<>
    struct __is_integral_helper<short>
    : public true_type { };

  template<>
    struct __is_integral_helper<unsigned short>
    : public true_type { };

  template<>
    struct __is_integral_helper<int>
    : public true_type { };

  template<>
    struct __is_integral_helper<unsigned int>
    : public true_type { };

  template<>
    struct __is_integral_helper<long>
    : public true_type { };

  template<>
    struct __is_integral_helper<unsigned long>
    : public true_type { };

  template<>
    struct __is_integral_helper<long long>
    : public true_type { };

  template<>
    struct __is_integral_helper<unsigned long long>
    : public true_type { };




  template<>
    struct __is_integral_helper<__int128>
    : public true_type { };

  template<>
    struct __is_integral_helper<unsigned __int128>
    : public true_type { };
# 323 "/usr/include/c++/9.2.0/type_traits" 3
  template<typename _Tp>
    struct is_integral
    : public __is_integral_helper<typename remove_cv<_Tp>::type>::type
    { };

  template<typename>
    struct __is_floating_point_helper
    : public false_type { };

  template<>
    struct __is_floating_point_helper<float>
    : public true_type { };

  template<>
    struct __is_floating_point_helper<double>
    : public true_type { };

  template<>
    struct __is_floating_point_helper<long double>
    : public true_type { };


  template<>
    struct __is_floating_point_helper<__float128>
    : public true_type { };



  template<typename _Tp>
    struct is_floating_point
    : public __is_floating_point_helper<typename remove_cv<_Tp>::type>::type
    { };


  template<typename>
    struct is_array
    : public false_type { };

  template<typename _Tp, std::size_t _Size>
    struct is_array<_Tp[_Size]>
    : public true_type { };

  template<typename _Tp>
    struct is_array<_Tp[]>
    : public true_type { };

  template<typename>
    struct __is_pointer_helper
    : public false_type { };

  template<typename _Tp>
    struct __is_pointer_helper<_Tp*>
    : public true_type { };


  template<typename _Tp>
    struct is_pointer
    : public __is_pointer_helper<typename remove_cv<_Tp>::type>::type
    { };


  template<typename>
    struct is_lvalue_reference
    : public false_type { };

  template<typename _Tp>
    struct is_lvalue_reference<_Tp&>
    : public true_type { };


  template<typename>
    struct is_rvalue_reference
    : public false_type { };

  template<typename _Tp>
    struct is_rvalue_reference<_Tp&&>
    : public true_type { };

  template<typename>
    struct is_function;

  template<typename>
    struct __is_member_object_pointer_helper
    : public false_type { };

  template<typename _Tp, typename _Cp>
    struct __is_member_object_pointer_helper<_Tp _Cp::*>
    : public __not_<is_function<_Tp>>::type { };


  template<typename _Tp>
    struct is_member_object_pointer
    : public __is_member_object_pointer_helper<
    typename remove_cv<_Tp>::type>::type
    { };

  template<typename>
    struct __is_member_function_pointer_helper
    : public false_type { };

  template<typename _Tp, typename _Cp>
    struct __is_member_function_pointer_helper<_Tp _Cp::*>
    : public is_function<_Tp>::type { };


  template<typename _Tp>
    struct is_member_function_pointer
    : public __is_member_function_pointer_helper<
    typename remove_cv<_Tp>::type>::type
    { };


  template<typename _Tp>
    struct is_enum
    : public integral_constant<bool, __is_enum(_Tp)>
    { };


  template<typename _Tp>
    struct is_union
    : public integral_constant<bool, __is_union(_Tp)>
    { };


  template<typename _Tp>
    struct is_class
    : public integral_constant<bool, __is_class(_Tp)>
    { };


  template<typename>
    struct is_function
    : public false_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes...) >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes...) & >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes...) && >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes......) >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes......) & >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes......) && >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes...) const >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes...) const & >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes...) const && >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes......) const >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes......) const & >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes......) const && >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes...) volatile >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes...) volatile & >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes...) volatile && >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes......) volatile >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes......) volatile & >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes......) volatile && >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes...) const volatile >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes...) const volatile & >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes...) const volatile && >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes......) const volatile >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes......) const volatile & >
    : public true_type { };

  template<typename _Res, typename... _ArgTypes >
    struct is_function<_Res(_ArgTypes......) const volatile && >
    : public true_type { };



  template<typename>
    struct __is_null_pointer_helper
    : public false_type { };

  template<>
    struct __is_null_pointer_helper<std::nullptr_t>
    : public true_type { };


  template<typename _Tp>
    struct is_null_pointer
    : public __is_null_pointer_helper<typename remove_cv<_Tp>::type>::type
    { };


  template<typename _Tp>
    struct __is_nullptr_t
    : public is_null_pointer<_Tp>
    { };




  template<typename _Tp>
    struct is_reference
    : public __or_<is_lvalue_reference<_Tp>,
                   is_rvalue_reference<_Tp>>::type
    { };


  template<typename _Tp>
    struct is_arithmetic
    : public __or_<is_integral<_Tp>, is_floating_point<_Tp>>::type
    { };


  template<typename _Tp>
    struct is_fundamental
    : public __or_<is_arithmetic<_Tp>, is_void<_Tp>,
     is_null_pointer<_Tp>>::type
    { };


  template<typename _Tp>
    struct is_object
    : public __not_<__or_<is_function<_Tp>, is_reference<_Tp>,
                          is_void<_Tp>>>::type
    { };

  template<typename>
    struct is_member_pointer;


  template<typename _Tp>
    struct is_scalar
    : public __or_<is_arithmetic<_Tp>, is_enum<_Tp>, is_pointer<_Tp>,
                   is_member_pointer<_Tp>, is_null_pointer<_Tp>>::type
    { };


  template<typename _Tp>
    struct is_compound
    : public __not_<is_fundamental<_Tp>>::type { };

  template<typename _Tp>
    struct __is_member_pointer_helper
    : public false_type { };

  template<typename _Tp, typename _Cp>
    struct __is_member_pointer_helper<_Tp _Cp::*>
    : public true_type { };


  template<typename _Tp>
    struct is_member_pointer
    : public __is_member_pointer_helper<typename remove_cv<_Tp>::type>::type
    { };



  template<typename _Tp>
    struct __is_referenceable
    : public __or_<is_object<_Tp>, is_reference<_Tp>>::type
    { };

  template<typename _Res, typename... _Args >
    struct __is_referenceable<_Res(_Args...) >
    : public true_type
    { };

  template<typename _Res, typename... _Args >
    struct __is_referenceable<_Res(_Args......) >
    : public true_type
    { };




  template<typename>
    struct is_const
    : public false_type { };

  template<typename _Tp>
    struct is_const<_Tp const>
    : public true_type { };


  template<typename>
    struct is_volatile
    : public false_type { };

  template<typename _Tp>
    struct is_volatile<_Tp volatile>
    : public true_type { };


  template<typename _Tp>
    struct is_trivial
    : public integral_constant<bool, __is_trivial(_Tp)>
    { };


  template<typename _Tp>
    struct is_trivially_copyable
    : public integral_constant<bool, __is_trivially_copyable(_Tp)>
    { };


  template<typename _Tp>
    struct is_standard_layout
    : public integral_constant<bool, __is_standard_layout(_Tp)>
    { };



  template<typename _Tp>
    struct is_pod
    : public integral_constant<bool, __is_pod(_Tp)>
    { };


  template<typename _Tp>
    struct is_literal_type
    : public integral_constant<bool, __is_literal_type(_Tp)>
    { };


  template<typename _Tp>
    struct is_empty
    : public integral_constant<bool, __is_empty(_Tp)>
    { };


  template<typename _Tp>
    struct is_polymorphic
    : public integral_constant<bool, __is_polymorphic(_Tp)>
    { };




  template<typename _Tp>
    struct is_final
    : public integral_constant<bool, __is_final(_Tp)>
    { };



  template<typename _Tp>
    struct is_abstract
    : public integral_constant<bool, __is_abstract(_Tp)>
    { };

  template<typename _Tp,
    bool = is_arithmetic<_Tp>::value>
    struct __is_signed_helper
    : public false_type { };

  template<typename _Tp>
    struct __is_signed_helper<_Tp, true>
    : public integral_constant<bool, _Tp(-1) < _Tp(0)>
    { };


  template<typename _Tp>
    struct is_signed
    : public __is_signed_helper<_Tp>::type
    { };


  template<typename _Tp>
    struct is_unsigned
    : public __and_<is_arithmetic<_Tp>, __not_<is_signed<_Tp>>>
    { };
# 758 "/usr/include/c++/9.2.0/type_traits" 3
  template<typename _Tp, typename _Up = _Tp&&>
    _Up
    __declval(int);

  template<typename _Tp>
    _Tp
    __declval(long);

  template<typename _Tp>
    auto declval() noexcept -> decltype(__declval<_Tp>(0));

  template<typename, unsigned = 0>
    struct extent;

  template<typename>
    struct remove_all_extents;

  template<typename _Tp>
    struct __is_array_known_bounds
    : public integral_constant<bool, (extent<_Tp>::value > 0)>
    { };

  template<typename _Tp>
    struct __is_array_unknown_bounds
    : public __and_<is_array<_Tp>, __not_<extent<_Tp>>>
    { };






  struct __do_is_destructible_impl
  {
    template<typename _Tp, typename = decltype(declval<_Tp&>().~_Tp())>
      static true_type __test(int);

    template<typename>
      static false_type __test(...);
  };

  template<typename _Tp>
    struct __is_destructible_impl
    : public __do_is_destructible_impl
    {
      typedef decltype(__test<_Tp>(0)) type;
    };

  template<typename _Tp,
           bool = __or_<is_void<_Tp>,
                        __is_array_unknown_bounds<_Tp>,
                        is_function<_Tp>>::value,
           bool = __or_<is_reference<_Tp>, is_scalar<_Tp>>::value>
    struct __is_destructible_safe;

  template<typename _Tp>
    struct __is_destructible_safe<_Tp, false, false>
    : public __is_destructible_impl<typename
               remove_all_extents<_Tp>::type>::type
    { };

  template<typename _Tp>
    struct __is_destructible_safe<_Tp, true, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_destructible_safe<_Tp, false, true>
    : public true_type { };


  template<typename _Tp>
    struct is_destructible
    : public __is_destructible_safe<_Tp>::type
    { };





  struct __do_is_nt_destructible_impl
  {
    template<typename _Tp>
      static __bool_constant<noexcept(declval<_Tp&>().~_Tp())>
      __test(int);

    template<typename>
      static false_type __test(...);
  };

  template<typename _Tp>
    struct __is_nt_destructible_impl
    : public __do_is_nt_destructible_impl
    {
      typedef decltype(__test<_Tp>(0)) type;
    };

  template<typename _Tp,
           bool = __or_<is_void<_Tp>,
                        __is_array_unknown_bounds<_Tp>,
                        is_function<_Tp>>::value,
           bool = __or_<is_reference<_Tp>, is_scalar<_Tp>>::value>
    struct __is_nt_destructible_safe;

  template<typename _Tp>
    struct __is_nt_destructible_safe<_Tp, false, false>
    : public __is_nt_destructible_impl<typename
               remove_all_extents<_Tp>::type>::type
    { };

  template<typename _Tp>
    struct __is_nt_destructible_safe<_Tp, true, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_nt_destructible_safe<_Tp, false, true>
    : public true_type { };


  template<typename _Tp>
    struct is_nothrow_destructible
    : public __is_nt_destructible_safe<_Tp>::type
    { };


  template<typename _Tp, typename... _Args>
    struct is_constructible
      : public __bool_constant<__is_constructible(_Tp, _Args...)>
    { };


  template<typename _Tp>
    struct is_default_constructible
    : public is_constructible<_Tp>::type
    { };

  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __is_copy_constructible_impl;

  template<typename _Tp>
    struct __is_copy_constructible_impl<_Tp, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_copy_constructible_impl<_Tp, true>
    : public is_constructible<_Tp, const _Tp&>
    { };


  template<typename _Tp>
    struct is_copy_constructible
    : public __is_copy_constructible_impl<_Tp>
    { };

  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __is_move_constructible_impl;

  template<typename _Tp>
    struct __is_move_constructible_impl<_Tp, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_move_constructible_impl<_Tp, true>
    : public is_constructible<_Tp, _Tp&&>
    { };


  template<typename _Tp>
    struct is_move_constructible
    : public __is_move_constructible_impl<_Tp>
    { };

  template<typename _Tp>
    struct __is_nt_default_constructible_atom
    : public integral_constant<bool, noexcept(_Tp())>
    { };

  template<typename _Tp, bool = is_array<_Tp>::value>
    struct __is_nt_default_constructible_impl;

  template<typename _Tp>
    struct __is_nt_default_constructible_impl<_Tp, true>
    : public __and_<__is_array_known_bounds<_Tp>,
      __is_nt_default_constructible_atom<typename
                      remove_all_extents<_Tp>::type>>
    { };

  template<typename _Tp>
    struct __is_nt_default_constructible_impl<_Tp, false>
    : public __is_nt_default_constructible_atom<_Tp>
    { };


  template<typename _Tp>
    struct is_nothrow_default_constructible
    : public __and_<is_default_constructible<_Tp>,
                    __is_nt_default_constructible_impl<_Tp>>
    { };

  template<typename _Tp, typename... _Args>
    struct __is_nt_constructible_impl
    : public integral_constant<bool, noexcept(_Tp(declval<_Args>()...))>
    { };

  template<typename _Tp, typename _Arg>
    struct __is_nt_constructible_impl<_Tp, _Arg>
    : public integral_constant<bool,
                               noexcept(static_cast<_Tp>(declval<_Arg>()))>
    { };

  template<typename _Tp>
    struct __is_nt_constructible_impl<_Tp>
    : public is_nothrow_default_constructible<_Tp>
    { };


  template<typename _Tp, typename... _Args>
    struct is_nothrow_constructible
    : public __and_<is_constructible<_Tp, _Args...>,
      __is_nt_constructible_impl<_Tp, _Args...>>
    { };

  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __is_nothrow_copy_constructible_impl;

  template<typename _Tp>
    struct __is_nothrow_copy_constructible_impl<_Tp, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_nothrow_copy_constructible_impl<_Tp, true>
    : public is_nothrow_constructible<_Tp, const _Tp&>
    { };


  template<typename _Tp>
    struct is_nothrow_copy_constructible
    : public __is_nothrow_copy_constructible_impl<_Tp>
    { };

  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __is_nothrow_move_constructible_impl;

  template<typename _Tp>
    struct __is_nothrow_move_constructible_impl<_Tp, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_nothrow_move_constructible_impl<_Tp, true>
    : public is_nothrow_constructible<_Tp, _Tp&&>
    { };


  template<typename _Tp>
    struct is_nothrow_move_constructible
    : public __is_nothrow_move_constructible_impl<_Tp>
    { };


  template<typename _Tp, typename _Up>
    struct is_assignable
      : public __bool_constant<__is_assignable(_Tp, _Up)>
    { };

  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __is_copy_assignable_impl;

  template<typename _Tp>
    struct __is_copy_assignable_impl<_Tp, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_copy_assignable_impl<_Tp, true>
    : public is_assignable<_Tp&, const _Tp&>
    { };


  template<typename _Tp>
    struct is_copy_assignable
    : public __is_copy_assignable_impl<_Tp>
    { };

  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __is_move_assignable_impl;

  template<typename _Tp>
    struct __is_move_assignable_impl<_Tp, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_move_assignable_impl<_Tp, true>
    : public is_assignable<_Tp&, _Tp&&>
    { };


  template<typename _Tp>
    struct is_move_assignable
    : public __is_move_assignable_impl<_Tp>
    { };

  template<typename _Tp, typename _Up>
    struct __is_nt_assignable_impl
    : public integral_constant<bool, noexcept(declval<_Tp>() = declval<_Up>())>
    { };


  template<typename _Tp, typename _Up>
    struct is_nothrow_assignable
    : public __and_<is_assignable<_Tp, _Up>,
      __is_nt_assignable_impl<_Tp, _Up>>
    { };

  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __is_nt_copy_assignable_impl;

  template<typename _Tp>
    struct __is_nt_copy_assignable_impl<_Tp, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_nt_copy_assignable_impl<_Tp, true>
    : public is_nothrow_assignable<_Tp&, const _Tp&>
    { };


  template<typename _Tp>
    struct is_nothrow_copy_assignable
    : public __is_nt_copy_assignable_impl<_Tp>
    { };

  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __is_nt_move_assignable_impl;

  template<typename _Tp>
    struct __is_nt_move_assignable_impl<_Tp, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_nt_move_assignable_impl<_Tp, true>
    : public is_nothrow_assignable<_Tp&, _Tp&&>
    { };


  template<typename _Tp>
    struct is_nothrow_move_assignable
    : public __is_nt_move_assignable_impl<_Tp>
    { };


  template<typename _Tp, typename... _Args>
    struct is_trivially_constructible
    : public __bool_constant<__is_trivially_constructible(_Tp, _Args...)>
    { };


  template<typename _Tp>
    struct is_trivially_default_constructible
    : public is_trivially_constructible<_Tp>::type
    { };

  struct __do_is_implicitly_default_constructible_impl
  {
    template <typename _Tp>
    static void __helper(const _Tp&);

    template <typename _Tp>
    static true_type __test(const _Tp&,
                            decltype(__helper<const _Tp&>({}))* = 0);

    static false_type __test(...);
  };

  template<typename _Tp>
    struct __is_implicitly_default_constructible_impl
    : public __do_is_implicitly_default_constructible_impl
    {
      typedef decltype(__test(declval<_Tp>())) type;
    };

  template<typename _Tp>
    struct __is_implicitly_default_constructible_safe
    : public __is_implicitly_default_constructible_impl<_Tp>::type
    { };

  template <typename _Tp>
    struct __is_implicitly_default_constructible
    : public __and_<is_default_constructible<_Tp>,
      __is_implicitly_default_constructible_safe<_Tp>>
    { };



  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __is_trivially_copy_constructible_impl;

  template<typename _Tp>
    struct __is_trivially_copy_constructible_impl<_Tp, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_trivially_copy_constructible_impl<_Tp, true>
    : public __and_<is_copy_constructible<_Tp>,
      integral_constant<bool,
   __is_trivially_constructible(_Tp, const _Tp&)>>
    { };

  template<typename _Tp>
    struct is_trivially_copy_constructible
    : public __is_trivially_copy_constructible_impl<_Tp>
    { };



  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __is_trivially_move_constructible_impl;

  template<typename _Tp>
    struct __is_trivially_move_constructible_impl<_Tp, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_trivially_move_constructible_impl<_Tp, true>
    : public __and_<is_move_constructible<_Tp>,
      integral_constant<bool,
   __is_trivially_constructible(_Tp, _Tp&&)>>
    { };

  template<typename _Tp>
    struct is_trivially_move_constructible
    : public __is_trivially_move_constructible_impl<_Tp>
    { };


  template<typename _Tp, typename _Up>
    struct is_trivially_assignable
    : public __bool_constant<__is_trivially_assignable(_Tp, _Up)>
    { };



  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __is_trivially_copy_assignable_impl;

  template<typename _Tp>
    struct __is_trivially_copy_assignable_impl<_Tp, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_trivially_copy_assignable_impl<_Tp, true>
    : public __bool_constant<__is_trivially_assignable(_Tp&, const _Tp&)>
    { };

  template<typename _Tp>
    struct is_trivially_copy_assignable
    : public __is_trivially_copy_assignable_impl<_Tp>
    { };



  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __is_trivially_move_assignable_impl;

  template<typename _Tp>
    struct __is_trivially_move_assignable_impl<_Tp, false>
    : public false_type { };

  template<typename _Tp>
    struct __is_trivially_move_assignable_impl<_Tp, true>
    : public __bool_constant<__is_trivially_assignable(_Tp&, _Tp&&)>
    { };

  template<typename _Tp>
    struct is_trivially_move_assignable
    : public __is_trivially_move_assignable_impl<_Tp>
    { };


  template<typename _Tp>
    struct is_trivially_destructible
    : public __and_<is_destructible<_Tp>,
      __bool_constant<__has_trivial_destructor(_Tp)>>
    { };



  template<typename _Tp>
    struct has_virtual_destructor
    : public integral_constant<bool, __has_virtual_destructor(_Tp)>
    { };





  template<typename _Tp>
    struct alignment_of
    : public integral_constant<std::size_t, alignof(_Tp)> { };


  template<typename>
    struct rank
    : public integral_constant<std::size_t, 0> { };

  template<typename _Tp, std::size_t _Size>
    struct rank<_Tp[_Size]>
    : public integral_constant<std::size_t, 1 + rank<_Tp>::value> { };

  template<typename _Tp>
    struct rank<_Tp[]>
    : public integral_constant<std::size_t, 1 + rank<_Tp>::value> { };


  template<typename, unsigned _Uint>
    struct extent
    : public integral_constant<std::size_t, 0> { };

  template<typename _Tp, unsigned _Uint, std::size_t _Size>
    struct extent<_Tp[_Size], _Uint>
    : public integral_constant<std::size_t,
          _Uint == 0 ? _Size : extent<_Tp,
          _Uint - 1>::value>
    { };

  template<typename _Tp, unsigned _Uint>
    struct extent<_Tp[], _Uint>
    : public integral_constant<std::size_t,
          _Uint == 0 ? 0 : extent<_Tp,
             _Uint - 1>::value>
    { };





  template<typename, typename>
    struct is_same
    : public false_type { };

  template<typename _Tp>
    struct is_same<_Tp, _Tp>
    : public true_type { };


  template<typename _Base, typename _Derived>
    struct is_base_of
    : public integral_constant<bool, __is_base_of(_Base, _Derived)>
    { };

  template<typename _From, typename _To,
           bool = __or_<is_void<_From>, is_function<_To>,
                        is_array<_To>>::value>
    struct __is_convertible_helper
    {
      typedef typename is_void<_To>::type type;
    };

  template<typename _From, typename _To>
    class __is_convertible_helper<_From, _To, false>
    {
      template<typename _To1>
 static void __test_aux(_To1) noexcept;

      template<typename _From1, typename _To1,
        typename = decltype(__test_aux<_To1>(std::declval<_From1>()))>
 static true_type
 __test(int);

      template<typename, typename>
 static false_type
 __test(...);

    public:
      typedef decltype(__test<_From, _To>(0)) type;
    };



  template<typename _From, typename _To>
    struct is_convertible
    : public __is_convertible_helper<_From, _To>::type
    { };
# 1380 "/usr/include/c++/9.2.0/type_traits" 3
  template<typename _Tp>
    struct remove_const
    { typedef _Tp type; };

  template<typename _Tp>
    struct remove_const<_Tp const>
    { typedef _Tp type; };


  template<typename _Tp>
    struct remove_volatile
    { typedef _Tp type; };

  template<typename _Tp>
    struct remove_volatile<_Tp volatile>
    { typedef _Tp type; };


  template<typename _Tp>
    struct remove_cv
    {
      typedef typename
      remove_const<typename remove_volatile<_Tp>::type>::type type;
    };


  template<typename _Tp>
    struct add_const
    { typedef _Tp const type; };


  template<typename _Tp>
    struct add_volatile
    { typedef _Tp volatile type; };


  template<typename _Tp>
    struct add_cv
    {
      typedef typename
      add_const<typename add_volatile<_Tp>::type>::type type;
    };






  template<typename _Tp>
    using remove_const_t = typename remove_const<_Tp>::type;


  template<typename _Tp>
    using remove_volatile_t = typename remove_volatile<_Tp>::type;


  template<typename _Tp>
    using remove_cv_t = typename remove_cv<_Tp>::type;


  template<typename _Tp>
    using add_const_t = typename add_const<_Tp>::type;


  template<typename _Tp>
    using add_volatile_t = typename add_volatile<_Tp>::type;


  template<typename _Tp>
    using add_cv_t = typename add_cv<_Tp>::type;





  template<typename _Tp>
    struct remove_reference
    { typedef _Tp type; };

  template<typename _Tp>
    struct remove_reference<_Tp&>
    { typedef _Tp type; };

  template<typename _Tp>
    struct remove_reference<_Tp&&>
    { typedef _Tp type; };

  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __add_lvalue_reference_helper
    { typedef _Tp type; };

  template<typename _Tp>
    struct __add_lvalue_reference_helper<_Tp, true>
    { typedef _Tp& type; };


  template<typename _Tp>
    struct add_lvalue_reference
    : public __add_lvalue_reference_helper<_Tp>
    { };

  template<typename _Tp, bool = __is_referenceable<_Tp>::value>
    struct __add_rvalue_reference_helper
    { typedef _Tp type; };

  template<typename _Tp>
    struct __add_rvalue_reference_helper<_Tp, true>
    { typedef _Tp&& type; };


  template<typename _Tp>
    struct add_rvalue_reference
    : public __add_rvalue_reference_helper<_Tp>
    { };



  template<typename _Tp>
    using remove_reference_t = typename remove_reference<_Tp>::type;


  template<typename _Tp>
    using add_lvalue_reference_t = typename add_lvalue_reference<_Tp>::type;


  template<typename _Tp>
    using add_rvalue_reference_t = typename add_rvalue_reference<_Tp>::type;





  template<typename _Unqualified, bool _IsConst, bool _IsVol>
    struct __cv_selector;

  template<typename _Unqualified>
    struct __cv_selector<_Unqualified, false, false>
    { typedef _Unqualified __type; };

  template<typename _Unqualified>
    struct __cv_selector<_Unqualified, false, true>
    { typedef volatile _Unqualified __type; };

  template<typename _Unqualified>
    struct __cv_selector<_Unqualified, true, false>
    { typedef const _Unqualified __type; };

  template<typename _Unqualified>
    struct __cv_selector<_Unqualified, true, true>
    { typedef const volatile _Unqualified __type; };

  template<typename _Qualified, typename _Unqualified,
    bool _IsConst = is_const<_Qualified>::value,
    bool _IsVol = is_volatile<_Qualified>::value>
    class __match_cv_qualifiers
    {
      typedef __cv_selector<_Unqualified, _IsConst, _IsVol> __match;

    public:
      typedef typename __match::__type __type;
    };


  template<typename _Tp>
    struct __make_unsigned
    { typedef _Tp __type; };

  template<>
    struct __make_unsigned<char>
    { typedef unsigned char __type; };

  template<>
    struct __make_unsigned<signed char>
    { typedef unsigned char __type; };

  template<>
    struct __make_unsigned<short>
    { typedef unsigned short __type; };

  template<>
    struct __make_unsigned<int>
    { typedef unsigned int __type; };

  template<>
    struct __make_unsigned<long>
    { typedef unsigned long __type; };

  template<>
    struct __make_unsigned<long long>
    { typedef unsigned long long __type; };


  template<>
    struct __make_unsigned<__int128>
    { typedef unsigned __int128 __type; };
# 1593 "/usr/include/c++/9.2.0/type_traits" 3
  template<typename _Tp,
    bool _IsInt = is_integral<_Tp>::value,
    bool _IsEnum = is_enum<_Tp>::value>
    class __make_unsigned_selector;

  template<typename _Tp>
    class __make_unsigned_selector<_Tp, true, false>
    {
      using __unsigned_type
 = typename __make_unsigned<typename remove_cv<_Tp>::type>::__type;

    public:
      using __type
 = typename __match_cv_qualifiers<_Tp, __unsigned_type>::__type;
    };

  class __make_unsigned_selector_base
  {
  protected:
    template<typename...> struct _List { };

    template<typename _Tp, typename... _Up>
      struct _List<_Tp, _Up...> : _List<_Up...>
      { static constexpr size_t __size = sizeof(_Tp); };

    template<size_t _Sz, typename _Tp, bool = (_Sz <= _Tp::__size)>
      struct __select;

    template<size_t _Sz, typename _Uint, typename... _UInts>
      struct __select<_Sz, _List<_Uint, _UInts...>, true>
      { using __type = _Uint; };

    template<size_t _Sz, typename _Uint, typename... _UInts>
      struct __select<_Sz, _List<_Uint, _UInts...>, false>
      : __select<_Sz, _List<_UInts...>>
      { };
  };


  template<typename _Tp>
    class __make_unsigned_selector<_Tp, false, true>
    : __make_unsigned_selector_base
    {

      using _UInts = _List<unsigned char, unsigned short, unsigned int,
      unsigned long, unsigned long long>;

      using __unsigned_type = typename __select<sizeof(_Tp), _UInts>::__type;

    public:
      using __type
 = typename __match_cv_qualifiers<_Tp, __unsigned_type>::__type;
    };






  template<>
    struct __make_unsigned<wchar_t>
    {
      using __type
 = typename __make_unsigned_selector<wchar_t, false, true>::__type;
    };
# 1669 "/usr/include/c++/9.2.0/type_traits" 3
  template<>
    struct __make_unsigned<char16_t>
    {
      using __type
 = typename __make_unsigned_selector<char16_t, false, true>::__type;
    };

  template<>
    struct __make_unsigned<char32_t>
    {
      using __type
 = typename __make_unsigned_selector<char32_t, false, true>::__type;
    };





  template<typename _Tp>
    struct make_unsigned
    { typedef typename __make_unsigned_selector<_Tp>::__type type; };


  template<>
    struct make_unsigned<bool>;



  template<typename _Tp>
    struct __make_signed
    { typedef _Tp __type; };

  template<>
    struct __make_signed<char>
    { typedef signed char __type; };

  template<>
    struct __make_signed<unsigned char>
    { typedef signed char __type; };

  template<>
    struct __make_signed<unsigned short>
    { typedef signed short __type; };

  template<>
    struct __make_signed<unsigned int>
    { typedef signed int __type; };

  template<>
    struct __make_signed<unsigned long>
    { typedef signed long __type; };

  template<>
    struct __make_signed<unsigned long long>
    { typedef signed long long __type; };


  template<>
    struct __make_signed<unsigned __int128>
    { typedef __int128 __type; };
# 1747 "/usr/include/c++/9.2.0/type_traits" 3
  template<typename _Tp,
    bool _IsInt = is_integral<_Tp>::value,
    bool _IsEnum = is_enum<_Tp>::value>
    class __make_signed_selector;

  template<typename _Tp>
    class __make_signed_selector<_Tp, true, false>
    {
      using __signed_type
 = typename __make_signed<typename remove_cv<_Tp>::type>::__type;

    public:
      using __type
 = typename __match_cv_qualifiers<_Tp, __signed_type>::__type;
    };


  template<typename _Tp>
    class __make_signed_selector<_Tp, false, true>
    {
      typedef typename __make_unsigned_selector<_Tp>::__type __unsigned_type;

    public:
      typedef typename __make_signed_selector<__unsigned_type>::__type __type;
    };






  template<>
    struct __make_signed<wchar_t>
    {
      using __type
 = typename __make_signed_selector<wchar_t, false, true>::__type;
    };
# 1795 "/usr/include/c++/9.2.0/type_traits" 3
  template<>
    struct __make_signed<char16_t>
    {
      using __type
 = typename __make_signed_selector<char16_t, false, true>::__type;
    };

  template<>
    struct __make_signed<char32_t>
    {
      using __type
 = typename __make_signed_selector<char32_t, false, true>::__type;
    };





  template<typename _Tp>
    struct make_signed
    { typedef typename __make_signed_selector<_Tp>::__type type; };


  template<>
    struct make_signed<bool>;



  template<typename _Tp>
    using make_signed_t = typename make_signed<_Tp>::type;


  template<typename _Tp>
    using make_unsigned_t = typename make_unsigned<_Tp>::type;





  template<typename _Tp>
    struct remove_extent
    { typedef _Tp type; };

  template<typename _Tp, std::size_t _Size>
    struct remove_extent<_Tp[_Size]>
    { typedef _Tp type; };

  template<typename _Tp>
    struct remove_extent<_Tp[]>
    { typedef _Tp type; };


  template<typename _Tp>
    struct remove_all_extents
    { typedef _Tp type; };

  template<typename _Tp, std::size_t _Size>
    struct remove_all_extents<_Tp[_Size]>
    { typedef typename remove_all_extents<_Tp>::type type; };

  template<typename _Tp>
    struct remove_all_extents<_Tp[]>
    { typedef typename remove_all_extents<_Tp>::type type; };



  template<typename _Tp>
    using remove_extent_t = typename remove_extent<_Tp>::type;


  template<typename _Tp>
    using remove_all_extents_t = typename remove_all_extents<_Tp>::type;




  template<typename _Tp, typename>
    struct __remove_pointer_helper
    { typedef _Tp type; };

  template<typename _Tp, typename _Up>
    struct __remove_pointer_helper<_Tp, _Up*>
    { typedef _Up type; };


  template<typename _Tp>
    struct remove_pointer
    : public __remove_pointer_helper<_Tp, typename remove_cv<_Tp>::type>
    { };


  template<typename _Tp, bool = __or_<__is_referenceable<_Tp>,
          is_void<_Tp>>::value>
    struct __add_pointer_helper
    { typedef _Tp type; };

  template<typename _Tp>
    struct __add_pointer_helper<_Tp, true>
    { typedef typename remove_reference<_Tp>::type* type; };

  template<typename _Tp>
    struct add_pointer
    : public __add_pointer_helper<_Tp>
    { };



  template<typename _Tp>
    using remove_pointer_t = typename remove_pointer<_Tp>::type;


  template<typename _Tp>
    using add_pointer_t = typename add_pointer<_Tp>::type;


  template<std::size_t _Len>
    struct __aligned_storage_msa
    {
      union __type
      {
 unsigned char __data[_Len];
 struct __attribute__((__aligned__)) { } __align;
      };
    };
# 1930 "/usr/include/c++/9.2.0/type_traits" 3
  template<std::size_t _Len, std::size_t _Align =
    __alignof__(typename __aligned_storage_msa<_Len>::__type)>
    struct aligned_storage
    {
      union type
      {
 unsigned char __data[_Len];
 struct __attribute__((__aligned__((_Align)))) { } __align;
      };
    };

  template <typename... _Types>
    struct __strictest_alignment
    {
      static const size_t _S_alignment = 0;
      static const size_t _S_size = 0;
    };

  template <typename _Tp, typename... _Types>
    struct __strictest_alignment<_Tp, _Types...>
    {
      static const size_t _S_alignment =
        alignof(_Tp) > __strictest_alignment<_Types...>::_S_alignment
 ? alignof(_Tp) : __strictest_alignment<_Types...>::_S_alignment;
      static const size_t _S_size =
        sizeof(_Tp) > __strictest_alignment<_Types...>::_S_size
 ? sizeof(_Tp) : __strictest_alignment<_Types...>::_S_size;
    };
# 1969 "/usr/include/c++/9.2.0/type_traits" 3
  template <size_t _Len, typename... _Types>
    struct aligned_union
    {
    private:
      static_assert(sizeof...(_Types) != 0, "At least one type is required");

      using __strictest = __strictest_alignment<_Types...>;
      static const size_t _S_len = _Len > __strictest::_S_size
 ? _Len : __strictest::_S_size;
    public:

      static const size_t alignment_value = __strictest::_S_alignment;

      typedef typename aligned_storage<_S_len, alignment_value>::type type;
    };

  template <size_t _Len, typename... _Types>
    const size_t aligned_union<_Len, _Types...>::alignment_value;



  template<typename _Up,
    bool _IsArray = is_array<_Up>::value,
    bool _IsFunction = is_function<_Up>::value>
    struct __decay_selector;


  template<typename _Up>
    struct __decay_selector<_Up, false, false>
    { typedef typename remove_cv<_Up>::type __type; };

  template<typename _Up>
    struct __decay_selector<_Up, true, false>
    { typedef typename remove_extent<_Up>::type* __type; };

  template<typename _Up>
    struct __decay_selector<_Up, false, true>
    { typedef typename add_pointer<_Up>::type __type; };


  template<typename _Tp>
    class decay
    {
      typedef typename remove_reference<_Tp>::type __remove_type;

    public:
      typedef typename __decay_selector<__remove_type>::__type type;
    };

  template<typename _Tp>
    class reference_wrapper;


  template<typename _Tp>
    struct __strip_reference_wrapper
    {
      typedef _Tp __type;
    };

  template<typename _Tp>
    struct __strip_reference_wrapper<reference_wrapper<_Tp> >
    {
      typedef _Tp& __type;
    };

  template<typename _Tp>
    struct __decay_and_strip
    {
      typedef typename __strip_reference_wrapper<
 typename decay<_Tp>::type>::__type __type;
    };




  template<bool, typename _Tp = void>
    struct enable_if
    { };


  template<typename _Tp>
    struct enable_if<true, _Tp>
    { typedef _Tp type; };

  template<typename... _Cond>
    using _Require = typename enable_if<__and_<_Cond...>::value>::type;



  template<bool _Cond, typename _Iftrue, typename _Iffalse>
    struct conditional
    { typedef _Iftrue type; };


  template<typename _Iftrue, typename _Iffalse>
    struct conditional<false, _Iftrue, _Iffalse>
    { typedef _Iffalse type; };


  template<typename... _Tp>
    struct common_type;



  struct __do_common_type_impl
  {
    template<typename _Tp, typename _Up>
      static __success_type<typename decay<decltype
       (true ? std::declval<_Tp>()
        : std::declval<_Up>())>::type> _S_test(int);

    template<typename, typename>
      static __failure_type _S_test(...);
  };

  template<typename _Tp, typename _Up>
    struct __common_type_impl
    : private __do_common_type_impl
    {
      typedef decltype(_S_test<_Tp, _Up>(0)) type;
    };

  struct __do_member_type_wrapper
  {
    template<typename _Tp>
      static __success_type<typename _Tp::type> _S_test(int);

    template<typename>
      static __failure_type _S_test(...);
  };

  template<typename _Tp>
    struct __member_type_wrapper
    : private __do_member_type_wrapper
    {
      typedef decltype(_S_test<_Tp>(0)) type;
    };

  template<typename _CTp, typename... _Args>
    struct __expanded_common_type_wrapper
    {
      typedef common_type<typename _CTp::type, _Args...> type;
    };

  template<typename... _Args>
    struct __expanded_common_type_wrapper<__failure_type, _Args...>
    { typedef __failure_type type; };

  template<>
    struct common_type<>
    { };

  template<typename _Tp>
    struct common_type<_Tp>
    : common_type<_Tp, _Tp>
    { };

  template<typename _Tp, typename _Up>
    struct common_type<_Tp, _Up>
    : public __common_type_impl<_Tp, _Up>::type
    { };

  template<typename _Tp, typename _Up, typename... _Vp>
    struct common_type<_Tp, _Up, _Vp...>
    : public __expanded_common_type_wrapper<typename __member_type_wrapper<
               common_type<_Tp, _Up>>::type, _Vp...>::type
    { };

  template<typename _Tp, bool = is_enum<_Tp>::value>
    struct __underlying_type_impl
    {
      using type = __underlying_type(_Tp);
    };

  template<typename _Tp>
    struct __underlying_type_impl<_Tp, false>
    { };


  template<typename _Tp>
    struct underlying_type
    : public __underlying_type_impl<_Tp>
    { };

  template<typename _Tp>
    struct __declval_protector
    {
      static const bool __stop = false;
    };

  template<typename _Tp>
    auto declval() noexcept -> decltype(__declval<_Tp>(0))
    {
      static_assert(__declval_protector<_Tp>::__stop,
      "declval() must not be used!");
      return __declval<_Tp>(0);
    }


  template<typename _Tp>
    using __remove_cvref_t
     = typename remove_cv<typename remove_reference<_Tp>::type>::type;


  template<typename _Signature>
    class result_of;





  struct __invoke_memfun_ref { };
  struct __invoke_memfun_deref { };
  struct __invoke_memobj_ref { };
  struct __invoke_memobj_deref { };
  struct __invoke_other { };


  template<typename _Tp, typename _Tag>
    struct __result_of_success : __success_type<_Tp>
    { using __invoke_type = _Tag; };


  struct __result_of_memfun_ref_impl
  {
    template<typename _Fp, typename _Tp1, typename... _Args>
      static __result_of_success<decltype(
      (std::declval<_Tp1>().*std::declval<_Fp>())(std::declval<_Args>()...)
      ), __invoke_memfun_ref> _S_test(int);

    template<typename...>
      static __failure_type _S_test(...);
  };

  template<typename _MemPtr, typename _Arg, typename... _Args>
    struct __result_of_memfun_ref
    : private __result_of_memfun_ref_impl
    {
      typedef decltype(_S_test<_MemPtr, _Arg, _Args...>(0)) type;
    };


  struct __result_of_memfun_deref_impl
  {
    template<typename _Fp, typename _Tp1, typename... _Args>
      static __result_of_success<decltype(
      ((*std::declval<_Tp1>()).*std::declval<_Fp>())(std::declval<_Args>()...)
      ), __invoke_memfun_deref> _S_test(int);

    template<typename...>
      static __failure_type _S_test(...);
  };

  template<typename _MemPtr, typename _Arg, typename... _Args>
    struct __result_of_memfun_deref
    : private __result_of_memfun_deref_impl
    {
      typedef decltype(_S_test<_MemPtr, _Arg, _Args...>(0)) type;
    };


  struct __result_of_memobj_ref_impl
  {
    template<typename _Fp, typename _Tp1>
      static __result_of_success<decltype(
      std::declval<_Tp1>().*std::declval<_Fp>()
      ), __invoke_memobj_ref> _S_test(int);

    template<typename, typename>
      static __failure_type _S_test(...);
  };

  template<typename _MemPtr, typename _Arg>
    struct __result_of_memobj_ref
    : private __result_of_memobj_ref_impl
    {
      typedef decltype(_S_test<_MemPtr, _Arg>(0)) type;
    };


  struct __result_of_memobj_deref_impl
  {
    template<typename _Fp, typename _Tp1>
      static __result_of_success<decltype(
      (*std::declval<_Tp1>()).*std::declval<_Fp>()
      ), __invoke_memobj_deref> _S_test(int);

    template<typename, typename>
      static __failure_type _S_test(...);
  };

  template<typename _MemPtr, typename _Arg>
    struct __result_of_memobj_deref
    : private __result_of_memobj_deref_impl
    {
      typedef decltype(_S_test<_MemPtr, _Arg>(0)) type;
    };

  template<typename _MemPtr, typename _Arg>
    struct __result_of_memobj;

  template<typename _Res, typename _Class, typename _Arg>
    struct __result_of_memobj<_Res _Class::*, _Arg>
    {
      typedef __remove_cvref_t<_Arg> _Argval;
      typedef _Res _Class::* _MemPtr;
      typedef typename conditional<__or_<is_same<_Argval, _Class>,
        is_base_of<_Class, _Argval>>::value,
        __result_of_memobj_ref<_MemPtr, _Arg>,
        __result_of_memobj_deref<_MemPtr, _Arg>
      >::type::type type;
    };

  template<typename _MemPtr, typename _Arg, typename... _Args>
    struct __result_of_memfun;

  template<typename _Res, typename _Class, typename _Arg, typename... _Args>
    struct __result_of_memfun<_Res _Class::*, _Arg, _Args...>
    {
      typedef typename remove_reference<_Arg>::type _Argval;
      typedef _Res _Class::* _MemPtr;
      typedef typename conditional<is_base_of<_Class, _Argval>::value,
        __result_of_memfun_ref<_MemPtr, _Arg, _Args...>,
        __result_of_memfun_deref<_MemPtr, _Arg, _Args...>
      >::type::type type;
    };






  template<typename _Tp, typename _Up = __remove_cvref_t<_Tp>>
    struct __inv_unwrap
    {
      using type = _Tp;
    };

  template<typename _Tp, typename _Up>
    struct __inv_unwrap<_Tp, reference_wrapper<_Up>>
    {
      using type = _Up&;
    };

  template<bool, bool, typename _Functor, typename... _ArgTypes>
    struct __result_of_impl
    {
      typedef __failure_type type;
    };

  template<typename _MemPtr, typename _Arg>
    struct __result_of_impl<true, false, _MemPtr, _Arg>
    : public __result_of_memobj<typename decay<_MemPtr>::type,
    typename __inv_unwrap<_Arg>::type>
    { };

  template<typename _MemPtr, typename _Arg, typename... _Args>
    struct __result_of_impl<false, true, _MemPtr, _Arg, _Args...>
    : public __result_of_memfun<typename decay<_MemPtr>::type,
    typename __inv_unwrap<_Arg>::type, _Args...>
    { };


  struct __result_of_other_impl
  {
    template<typename _Fn, typename... _Args>
      static __result_of_success<decltype(
      std::declval<_Fn>()(std::declval<_Args>()...)
      ), __invoke_other> _S_test(int);

    template<typename...>
      static __failure_type _S_test(...);
  };

  template<typename _Functor, typename... _ArgTypes>
    struct __result_of_impl<false, false, _Functor, _ArgTypes...>
    : private __result_of_other_impl
    {
      typedef decltype(_S_test<_Functor, _ArgTypes...>(0)) type;
    };


  template<typename _Functor, typename... _ArgTypes>
    struct __invoke_result
    : public __result_of_impl<
        is_member_object_pointer<
          typename remove_reference<_Functor>::type
        >::value,
        is_member_function_pointer<
          typename remove_reference<_Functor>::type
        >::value,
 _Functor, _ArgTypes...
      >::type
    { };

  template<typename _Functor, typename... _ArgTypes>
    struct result_of<_Functor(_ArgTypes...)>
    : public __invoke_result<_Functor, _ArgTypes...>
    { };



  template<size_t _Len, size_t _Align =
     __alignof__(typename __aligned_storage_msa<_Len>::__type)>
    using aligned_storage_t = typename aligned_storage<_Len, _Align>::type;

  template <size_t _Len, typename... _Types>
    using aligned_union_t = typename aligned_union<_Len, _Types...>::type;


  template<typename _Tp>
    using decay_t = typename decay<_Tp>::type;


  template<bool _Cond, typename _Tp = void>
    using enable_if_t = typename enable_if<_Cond, _Tp>::type;


  template<bool _Cond, typename _Iftrue, typename _Iffalse>
    using conditional_t = typename conditional<_Cond, _Iftrue, _Iffalse>::type;


  template<typename... _Tp>
    using common_type_t = typename common_type<_Tp...>::type;


  template<typename _Tp>
    using underlying_type_t = typename underlying_type<_Tp>::type;


  template<typename _Tp>
    using result_of_t = typename result_of<_Tp>::type;



  template<bool _Cond, typename _Tp = void>
    using __enable_if_t = typename enable_if<_Cond, _Tp>::type;


  template<typename...> using __void_t = void;




  template<typename...> using void_t = void;



  template<typename _Default, typename _AlwaysVoid,
    template<typename...> class _Op, typename... _Args>
    struct __detector
    {
      using value_t = false_type;
      using type = _Default;
    };


  template<typename _Default, template<typename...> class _Op,
     typename... _Args>
    struct __detector<_Default, __void_t<_Op<_Args...>>, _Op, _Args...>
    {
      using value_t = true_type;
      using type = _Op<_Args...>;
    };


  template<typename _Default, template<typename...> class _Op,
    typename... _Args>
    using __detected_or = __detector<_Default, void, _Op, _Args...>;


  template<typename _Default, template<typename...> class _Op,
    typename... _Args>
    using __detected_or_t
      = typename __detected_or<_Default, _Op, _Args...>::type;
# 2461 "/usr/include/c++/9.2.0/type_traits" 3
  template <typename _Tp>
    struct __is_swappable;

  template <typename _Tp>
    struct __is_nothrow_swappable;

  template<typename... _Elements>
    class tuple;

  template<typename>
    struct __is_tuple_like_impl : false_type
    { };

  template<typename... _Tps>
    struct __is_tuple_like_impl<tuple<_Tps...>> : true_type
    { };


  template<typename _Tp>
    struct __is_tuple_like
    : public __is_tuple_like_impl<__remove_cvref_t<_Tp>>::type
    { };

  template<typename _Tp>
    inline
    typename enable_if<__and_<__not_<__is_tuple_like<_Tp>>,
         is_move_constructible<_Tp>,
         is_move_assignable<_Tp>>::value>::type
    swap(_Tp&, _Tp&)
    noexcept(__and_<is_nothrow_move_constructible<_Tp>,
             is_nothrow_move_assignable<_Tp>>::value);

  template<typename _Tp, size_t _Nm>
    inline
    typename enable_if<__is_swappable<_Tp>::value>::type
    swap(_Tp (&__a)[_Nm], _Tp (&__b)[_Nm])
    noexcept(__is_nothrow_swappable<_Tp>::value);

  namespace __swappable_details {
    using std::swap;

    struct __do_is_swappable_impl
    {
      template<typename _Tp, typename
               = decltype(swap(std::declval<_Tp&>(), std::declval<_Tp&>()))>
        static true_type __test(int);

      template<typename>
        static false_type __test(...);
    };

    struct __do_is_nothrow_swappable_impl
    {
      template<typename _Tp>
        static __bool_constant<
          noexcept(swap(std::declval<_Tp&>(), std::declval<_Tp&>()))
        > __test(int);

      template<typename>
        static false_type __test(...);
    };

  }

  template<typename _Tp>
    struct __is_swappable_impl
    : public __swappable_details::__do_is_swappable_impl
    {
      typedef decltype(__test<_Tp>(0)) type;
    };

  template<typename _Tp>
    struct __is_nothrow_swappable_impl
    : public __swappable_details::__do_is_nothrow_swappable_impl
    {
      typedef decltype(__test<_Tp>(0)) type;
    };

  template<typename _Tp>
    struct __is_swappable
    : public __is_swappable_impl<_Tp>::type
    { };

  template<typename _Tp>
    struct __is_nothrow_swappable
    : public __is_nothrow_swappable_impl<_Tp>::type
    { };






  template<typename _Tp>
    struct is_swappable
    : public __is_swappable_impl<_Tp>::type
    { };


  template<typename _Tp>
    struct is_nothrow_swappable
    : public __is_nothrow_swappable_impl<_Tp>::type
    { };



  template<typename _Tp>
    constexpr bool is_swappable_v =
      is_swappable<_Tp>::value;


  template<typename _Tp>
    constexpr bool is_nothrow_swappable_v =
      is_nothrow_swappable<_Tp>::value;


  namespace __swappable_with_details {
    using std::swap;

    struct __do_is_swappable_with_impl
    {
      template<typename _Tp, typename _Up, typename
               = decltype(swap(std::declval<_Tp>(), std::declval<_Up>())),
               typename
               = decltype(swap(std::declval<_Up>(), std::declval<_Tp>()))>
        static true_type __test(int);

      template<typename, typename>
        static false_type __test(...);
    };

    struct __do_is_nothrow_swappable_with_impl
    {
      template<typename _Tp, typename _Up>
        static __bool_constant<
          noexcept(swap(std::declval<_Tp>(), std::declval<_Up>()))
          &&
          noexcept(swap(std::declval<_Up>(), std::declval<_Tp>()))
        > __test(int);

      template<typename, typename>
        static false_type __test(...);
    };

  }

  template<typename _Tp, typename _Up>
    struct __is_swappable_with_impl
    : public __swappable_with_details::__do_is_swappable_with_impl
    {
      typedef decltype(__test<_Tp, _Up>(0)) type;
    };


  template<typename _Tp>
    struct __is_swappable_with_impl<_Tp&, _Tp&>
    : public __swappable_details::__do_is_swappable_impl
    {
      typedef decltype(__test<_Tp&>(0)) type;
    };

  template<typename _Tp, typename _Up>
    struct __is_nothrow_swappable_with_impl
    : public __swappable_with_details::__do_is_nothrow_swappable_with_impl
    {
      typedef decltype(__test<_Tp, _Up>(0)) type;
    };


  template<typename _Tp>
    struct __is_nothrow_swappable_with_impl<_Tp&, _Tp&>
    : public __swappable_details::__do_is_nothrow_swappable_impl
    {
      typedef decltype(__test<_Tp&>(0)) type;
    };


  template<typename _Tp, typename _Up>
    struct is_swappable_with
    : public __is_swappable_with_impl<_Tp, _Up>::type
    { };


  template<typename _Tp, typename _Up>
    struct is_nothrow_swappable_with
    : public __is_nothrow_swappable_with_impl<_Tp, _Up>::type
    { };



  template<typename _Tp, typename _Up>
    constexpr bool is_swappable_with_v =
      is_swappable_with<_Tp, _Up>::value;


  template<typename _Tp, typename _Up>
    constexpr bool is_nothrow_swappable_with_v =
      is_nothrow_swappable_with<_Tp, _Up>::value;






  template<typename _Result, typename _Ret, typename = void>
    struct __is_invocable_impl : false_type { };

  template<typename _Result, typename _Ret>
    struct __is_invocable_impl<_Result, _Ret, __void_t<typename _Result::type>>
    : __or_<is_void<_Ret>, is_convertible<typename _Result::type, _Ret>>::type
    { };

  template<typename _Fn, typename... _ArgTypes>
    struct __is_invocable
    : __is_invocable_impl<__invoke_result<_Fn, _ArgTypes...>, void>::type
    { };

  template<typename _Fn, typename _Tp, typename... _Args>
    constexpr bool __call_is_nt(__invoke_memfun_ref)
    {
      using _Up = typename __inv_unwrap<_Tp>::type;
      return noexcept((std::declval<_Up>().*std::declval<_Fn>())(
     std::declval<_Args>()...));
    }

  template<typename _Fn, typename _Tp, typename... _Args>
    constexpr bool __call_is_nt(__invoke_memfun_deref)
    {
      return noexcept(((*std::declval<_Tp>()).*std::declval<_Fn>())(
     std::declval<_Args>()...));
    }

  template<typename _Fn, typename _Tp>
    constexpr bool __call_is_nt(__invoke_memobj_ref)
    {
      using _Up = typename __inv_unwrap<_Tp>::type;
      return noexcept(std::declval<_Up>().*std::declval<_Fn>());
    }

  template<typename _Fn, typename _Tp>
    constexpr bool __call_is_nt(__invoke_memobj_deref)
    {
      return noexcept((*std::declval<_Tp>()).*std::declval<_Fn>());
    }

  template<typename _Fn, typename... _Args>
    constexpr bool __call_is_nt(__invoke_other)
    {
      return noexcept(std::declval<_Fn>()(std::declval<_Args>()...));
    }

  template<typename _Result, typename _Fn, typename... _Args>
    struct __call_is_nothrow
    : __bool_constant<
 std::__call_is_nt<_Fn, _Args...>(typename _Result::__invoke_type{})
      >
    { };

  template<typename _Fn, typename... _Args>
    using __call_is_nothrow_
      = __call_is_nothrow<__invoke_result<_Fn, _Args...>, _Fn, _Args...>;


  template<typename _Fn, typename... _Args>
    struct __is_nothrow_invocable
    : __and_<__is_invocable<_Fn, _Args...>,
             __call_is_nothrow_<_Fn, _Args...>>::type
    { };

  struct __nonesuch {
    __nonesuch() = delete;
    ~__nonesuch() = delete;
    __nonesuch(__nonesuch const&) = delete;
    void operator=(__nonesuch const&) = delete;
  };
# 3062 "/usr/include/c++/9.2.0/type_traits" 3

}
# 39 "/usr/include/c++/9.2.0/unordered_map" 2 3
# 1 "/usr/include/c++/9.2.0/initializer_list" 1 3
# 33 "/usr/include/c++/9.2.0/initializer_list" 3
       
# 34 "/usr/include/c++/9.2.0/initializer_list" 3





#pragma GCC visibility push(default)



namespace std
{

  template<class _E>
    class initializer_list
    {
    public:
      typedef _E value_type;
      typedef const _E& reference;
      typedef const _E& const_reference;
      typedef size_t size_type;
      typedef const _E* iterator;
      typedef const _E* const_iterator;

    private:
      iterator _M_array;
      size_type _M_len;


      constexpr initializer_list(const_iterator __a, size_type __l)
      : _M_array(__a), _M_len(__l) { }

    public:
      constexpr initializer_list() noexcept
      : _M_array(0), _M_len(0) { }


      constexpr size_type
      size() const noexcept { return _M_len; }


      constexpr const_iterator
      begin() const noexcept { return _M_array; }


      constexpr const_iterator
      end() const noexcept { return begin() + size(); }
    };






  template<class _Tp>
    constexpr const _Tp*
    begin(initializer_list<_Tp> __ils) noexcept
    { return __ils.begin(); }






  template<class _Tp>
    constexpr const _Tp*
    end(initializer_list<_Tp> __ils) noexcept
    { return __ils.end(); }
}

#pragma GCC visibility pop
# 40 "/usr/include/c++/9.2.0/unordered_map" 2 3
# 1 "/usr/include/c++/9.2.0/bits/allocator.h" 1 3
# 46 "/usr/include/c++/9.2.0/bits/allocator.h" 3
# 1 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++allocator.h" 1 3
# 33 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++allocator.h" 3
# 1 "/usr/include/c++/9.2.0/ext/new_allocator.h" 1 3
# 33 "/usr/include/c++/9.2.0/ext/new_allocator.h" 3
# 1 "/usr/include/c++/9.2.0/new" 1 3
# 37 "/usr/include/c++/9.2.0/new" 3
       
# 38 "/usr/include/c++/9.2.0/new" 3


# 1 "/usr/include/c++/9.2.0/exception" 1 3
# 33 "/usr/include/c++/9.2.0/exception" 3
       
# 34 "/usr/include/c++/9.2.0/exception" 3

#pragma GCC visibility push(default)


# 1 "/usr/include/c++/9.2.0/bits/exception.h" 1 3
# 34 "/usr/include/c++/9.2.0/bits/exception.h" 3
       
# 35 "/usr/include/c++/9.2.0/bits/exception.h" 3

#pragma GCC visibility push(default)



extern "C++" {

namespace std
{
# 60 "/usr/include/c++/9.2.0/bits/exception.h" 3
  class exception
  {
  public:
    exception() noexcept { }
    virtual ~exception() noexcept;

    exception(const exception&) = default;
    exception& operator=(const exception&) = default;
    exception(exception&&) = default;
    exception& operator=(exception&&) = default;




    virtual const char*
    what() const noexcept;
  };

}

}

#pragma GCC visibility pop
# 39 "/usr/include/c++/9.2.0/exception" 2 3

extern "C++" {

namespace std
{


  class bad_exception : public exception
  {
  public:
    bad_exception() noexcept { }



    virtual ~bad_exception() noexcept;


    virtual const char*
    what() const noexcept;
  };


  typedef void (*terminate_handler) ();


  typedef void (*unexpected_handler) ();


  terminate_handler set_terminate(terminate_handler) noexcept;



  terminate_handler get_terminate() noexcept;




  void terminate() noexcept __attribute__ ((__noreturn__));


  unexpected_handler set_unexpected(unexpected_handler) noexcept;



  unexpected_handler get_unexpected() noexcept;




  void unexpected() __attribute__ ((__noreturn__));
# 101 "/usr/include/c++/9.2.0/exception" 3
 
  bool uncaught_exception() noexcept __attribute__ ((__pure__));




  int uncaught_exceptions() noexcept __attribute__ ((__pure__));



}

namespace __gnu_cxx
{

# 133 "/usr/include/c++/9.2.0/exception" 3
  void __verbose_terminate_handler();


}

}

#pragma GCC visibility pop


# 1 "/usr/include/c++/9.2.0/bits/exception_ptr.h" 1 3
# 34 "/usr/include/c++/9.2.0/bits/exception_ptr.h" 3
#pragma GCC visibility push(default)


# 1 "/usr/include/c++/9.2.0/bits/exception_defines.h" 1 3
# 38 "/usr/include/c++/9.2.0/bits/exception_ptr.h" 2 3
# 1 "/usr/include/c++/9.2.0/bits/cxxabi_init_exception.h" 1 3
# 34 "/usr/include/c++/9.2.0/bits/cxxabi_init_exception.h" 3
       
# 35 "/usr/include/c++/9.2.0/bits/cxxabi_init_exception.h" 3

#pragma GCC visibility push(default)

# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 1 3 4
# 143 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 3 4
typedef long int ptrdiff_t;
# 415 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
# 426 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 3 4
} max_align_t;






  typedef decltype(nullptr) nullptr_t;
# 39 "/usr/include/c++/9.2.0/bits/cxxabi_init_exception.h" 2 3
# 50 "/usr/include/c++/9.2.0/bits/cxxabi_init_exception.h" 3
namespace std
{
  class type_info;
}

namespace __cxxabiv1
{
  struct __cxa_refcounted_exception;

  extern "C"
    {

      void*
      __cxa_allocate_exception(size_t) noexcept;

      void
      __cxa_free_exception(void*) noexcept;


      __cxa_refcounted_exception*
      __cxa_init_primary_exception(void *object, std::type_info *tinfo,
                void ( *dest) (void *)) noexcept;

    }
}



#pragma GCC visibility pop
# 39 "/usr/include/c++/9.2.0/bits/exception_ptr.h" 2 3
# 1 "/usr/include/c++/9.2.0/typeinfo" 1 3
# 32 "/usr/include/c++/9.2.0/typeinfo" 3
       
# 33 "/usr/include/c++/9.2.0/typeinfo" 3



# 1 "/usr/include/c++/9.2.0/bits/hash_bytes.h" 1 3
# 33 "/usr/include/c++/9.2.0/bits/hash_bytes.h" 3
       
# 34 "/usr/include/c++/9.2.0/bits/hash_bytes.h" 3



namespace std
{







  size_t
  _Hash_bytes(const void* __ptr, size_t __len, size_t __seed);





  size_t
  _Fnv_hash_bytes(const void* __ptr, size_t __len, size_t __seed);


}
# 37 "/usr/include/c++/9.2.0/typeinfo" 2 3


#pragma GCC visibility push(default)

extern "C++" {

namespace __cxxabiv1
{
  class __class_type_info;
}
# 80 "/usr/include/c++/9.2.0/typeinfo" 3
namespace std
{






  class type_info
  {
  public:




    virtual ~type_info();



    const char* name() const noexcept
    { return __name[0] == '*' ? __name + 1 : __name; }
# 115 "/usr/include/c++/9.2.0/typeinfo" 3
    bool before(const type_info& __arg) const noexcept
    { return (__name[0] == '*' && __arg.__name[0] == '*')
 ? __name < __arg.__name
 : __builtin_strcmp (__name, __arg.__name) < 0; }

    bool operator==(const type_info& __arg) const noexcept
    {
      return ((__name == __arg.__name)
       || (__name[0] != '*' &&
    __builtin_strcmp (__name, __arg.__name) == 0));
    }
# 136 "/usr/include/c++/9.2.0/typeinfo" 3
    bool operator!=(const type_info& __arg) const noexcept
    { return !operator==(__arg); }


    size_t hash_code() const noexcept
    {

      return _Hash_bytes(name(), __builtin_strlen(name()),
    static_cast<size_t>(0xc70f6907UL));



    }



    virtual bool __is_pointer_p() const;


    virtual bool __is_function_p() const;







    virtual bool __do_catch(const type_info *__thr_type, void **__thr_obj,
       unsigned __outer) const;


    virtual bool __do_upcast(const __cxxabiv1::__class_type_info *__target,
        void **__obj_ptr) const;

  protected:
    const char *__name;

    explicit type_info(const char *__n): __name(__n) { }

  private:

    type_info& operator=(const type_info&);
    type_info(const type_info&);
  };







  class bad_cast : public exception
  {
  public:
    bad_cast() noexcept { }



    virtual ~bad_cast() noexcept;


    virtual const char* what() const noexcept;
  };





  class bad_typeid : public exception
  {
  public:
    bad_typeid () noexcept { }



    virtual ~bad_typeid() noexcept;


    virtual const char* what() const noexcept;
  };
}

}

#pragma GCC visibility pop
# 40 "/usr/include/c++/9.2.0/bits/exception_ptr.h" 2 3
# 1 "/usr/include/c++/9.2.0/new" 1 3
# 41 "/usr/include/c++/9.2.0/bits/exception_ptr.h" 2 3

extern "C++" {

namespace std
{
  class type_info;





  namespace __exception_ptr
  {
    class exception_ptr;
  }

  using __exception_ptr::exception_ptr;





  exception_ptr current_exception() noexcept;

  template<typename _Ex>
  exception_ptr make_exception_ptr(_Ex) noexcept;


  void rethrow_exception(exception_ptr) __attribute__ ((__noreturn__));

  namespace __exception_ptr
  {
    using std::rethrow_exception;





    class exception_ptr
    {
      void* _M_exception_object;

      explicit exception_ptr(void* __e) noexcept;

      void _M_addref() noexcept;
      void _M_release() noexcept;

      void *_M_get() const noexcept __attribute__ ((__pure__));

      friend exception_ptr std::current_exception() noexcept;
      friend void std::rethrow_exception(exception_ptr);
      template<typename _Ex>
      friend exception_ptr std::make_exception_ptr(_Ex) noexcept;

    public:
      exception_ptr() noexcept;

      exception_ptr(const exception_ptr&) noexcept;


      exception_ptr(nullptr_t) noexcept
      : _M_exception_object(0)
      { }

      exception_ptr(exception_ptr&& __o) noexcept
      : _M_exception_object(__o._M_exception_object)
      { __o._M_exception_object = 0; }
# 117 "/usr/include/c++/9.2.0/bits/exception_ptr.h" 3
      exception_ptr&
      operator=(const exception_ptr&) noexcept;


      exception_ptr&
      operator=(exception_ptr&& __o) noexcept
      {
        exception_ptr(static_cast<exception_ptr&&>(__o)).swap(*this);
        return *this;
      }


      ~exception_ptr() noexcept;

      void
      swap(exception_ptr&) noexcept;
# 144 "/usr/include/c++/9.2.0/bits/exception_ptr.h" 3
      explicit operator bool() const
      { return _M_exception_object; }


      friend bool
      operator==(const exception_ptr&, const exception_ptr&)
 noexcept __attribute__ ((__pure__));

      const class std::type_info*
      __cxa_exception_type() const noexcept
 __attribute__ ((__pure__));
    };

    bool
    operator==(const exception_ptr&, const exception_ptr&)
      noexcept __attribute__ ((__pure__));

    bool
    operator!=(const exception_ptr&, const exception_ptr&)
      noexcept __attribute__ ((__pure__));

    inline void
    swap(exception_ptr& __lhs, exception_ptr& __rhs)
    { __lhs.swap(__rhs); }

    template<typename _Ex>
      inline void
      __dest_thunk(void* __x)
      { static_cast<_Ex*>(__x)->~_Ex(); }

  }


  template<typename _Ex>
    exception_ptr
    make_exception_ptr(_Ex __ex) noexcept
    {

      void* __e = __cxxabiv1::__cxa_allocate_exception(sizeof(_Ex));
      (void) __cxxabiv1::__cxa_init_primary_exception(
   __e, const_cast<std::type_info*>(&typeid(__ex)),
   __exception_ptr::__dest_thunk<_Ex>);
      try
 {
          ::new (__e) _Ex(__ex);
          return exception_ptr(__e);
 }
      catch(...)
 {
   __cxxabiv1::__cxa_free_exception(__e);
   return current_exception();
 }
# 208 "/usr/include/c++/9.2.0/bits/exception_ptr.h" 3
    }


}

}

#pragma GCC visibility pop
# 144 "/usr/include/c++/9.2.0/exception" 2 3
# 1 "/usr/include/c++/9.2.0/bits/nested_exception.h" 1 3
# 33 "/usr/include/c++/9.2.0/bits/nested_exception.h" 3
#pragma GCC visibility push(default)






# 1 "/usr/include/c++/9.2.0/bits/move.h" 1 3
# 34 "/usr/include/c++/9.2.0/bits/move.h" 3
# 1 "/usr/include/c++/9.2.0/bits/concept_check.h" 1 3
# 33 "/usr/include/c++/9.2.0/bits/concept_check.h" 3
       
# 34 "/usr/include/c++/9.2.0/bits/concept_check.h" 3
# 35 "/usr/include/c++/9.2.0/bits/move.h" 2 3

namespace std __attribute__ ((__visibility__ ("default")))
{







  template<typename _Tp>
    inline constexpr _Tp*
    __addressof(_Tp& __r) noexcept
    { return __builtin_addressof(__r); }




}



namespace std __attribute__ ((__visibility__ ("default")))
{

# 72 "/usr/include/c++/9.2.0/bits/move.h" 3
  template<typename _Tp>
    constexpr _Tp&&
    forward(typename std::remove_reference<_Tp>::type& __t) noexcept
    { return static_cast<_Tp&&>(__t); }







  template<typename _Tp>
    constexpr _Tp&&
    forward(typename std::remove_reference<_Tp>::type&& __t) noexcept
    {
      static_assert(!std::is_lvalue_reference<_Tp>::value, "template argument"
      " substituting _Tp is an lvalue reference type");
      return static_cast<_Tp&&>(__t);
    }






  template<typename _Tp>
    constexpr typename std::remove_reference<_Tp>::type&&
    move(_Tp&& __t) noexcept
    { return static_cast<typename std::remove_reference<_Tp>::type&&>(__t); }


  template<typename _Tp>
    struct __move_if_noexcept_cond
    : public __and_<__not_<is_nothrow_move_constructible<_Tp>>,
                    is_copy_constructible<_Tp>>::type { };
# 116 "/usr/include/c++/9.2.0/bits/move.h" 3
  template<typename _Tp>
    constexpr typename
    conditional<__move_if_noexcept_cond<_Tp>::value, const _Tp&, _Tp&&>::type
    move_if_noexcept(_Tp& __x) noexcept
    { return std::move(__x); }
# 136 "/usr/include/c++/9.2.0/bits/move.h" 3
  template<typename _Tp>
    inline _Tp*
    addressof(_Tp& __r) noexcept
    { return std::__addressof(__r); }



  template<typename _Tp>
    const _Tp* addressof(const _Tp&&) = delete;


  template <typename _Tp, typename _Up = _Tp>
    inline _Tp
    __exchange(_Tp& __obj, _Up&& __new_val)
    {
      _Tp __old_val = std::move(__obj);
      __obj = std::forward<_Up>(__new_val);
      return __old_val;
    }
# 176 "/usr/include/c++/9.2.0/bits/move.h" 3
  template<typename _Tp>
    inline

    typename enable_if<__and_<__not_<__is_tuple_like<_Tp>>,
         is_move_constructible<_Tp>,
         is_move_assignable<_Tp>>::value>::type
    swap(_Tp& __a, _Tp& __b)
    noexcept(__and_<is_nothrow_move_constructible<_Tp>,
             is_nothrow_move_assignable<_Tp>>::value)




    {

     

      _Tp __tmp = std::move(__a);
      __a = std::move(__b);
      __b = std::move(__tmp);
    }




  template<typename _Tp, size_t _Nm>
    inline

    typename enable_if<__is_swappable<_Tp>::value>::type
    swap(_Tp (&__a)[_Nm], _Tp (&__b)[_Nm])
    noexcept(__is_nothrow_swappable<_Tp>::value)




    {
      for (size_t __n = 0; __n < _Nm; ++__n)
 swap(__a[__n], __b[__n]);
    }



}
# 41 "/usr/include/c++/9.2.0/bits/nested_exception.h" 2 3

extern "C++" {

namespace std
{






  class nested_exception
  {
    exception_ptr _M_ptr;

  public:
    nested_exception() noexcept : _M_ptr(current_exception()) { }

    nested_exception(const nested_exception&) noexcept = default;

    nested_exception& operator=(const nested_exception&) noexcept = default;

    virtual ~nested_exception() noexcept;

    [[noreturn]]
    void
    rethrow_nested() const
    {
      if (_M_ptr)
 rethrow_exception(_M_ptr);
      std::terminate();
    }

    exception_ptr
    nested_ptr() const noexcept
    { return _M_ptr; }
  };

  template<typename _Except>
    struct _Nested_exception : public _Except, public nested_exception
    {
      explicit _Nested_exception(const _Except& __ex)
      : _Except(__ex)
      { }

      explicit _Nested_exception(_Except&& __ex)
      : _Except(static_cast<_Except&&>(__ex))
      { }
    };




  template<typename _Tp>
    [[noreturn]]
    inline void
    __throw_with_nested_impl(_Tp&& __t, true_type)
    {
      using _Up = typename remove_reference<_Tp>::type;
      throw _Nested_exception<_Up>{std::forward<_Tp>(__t)};
    }

  template<typename _Tp>
    [[noreturn]]
    inline void
    __throw_with_nested_impl(_Tp&& __t, false_type)
    { throw std::forward<_Tp>(__t); }



  template<typename _Tp>
    [[noreturn]]
    inline void
    throw_with_nested(_Tp&& __t)
    {
      using _Up = typename decay<_Tp>::type;
      using _CopyConstructible
 = __and_<is_copy_constructible<_Up>, is_move_constructible<_Up>>;
      static_assert(_CopyConstructible::value,
   "throw_with_nested argument must be CopyConstructible");
      using __nest = __and_<is_class<_Up>, __bool_constant<!__is_final(_Up)>,
       __not_<is_base_of<nested_exception, _Up>>>;
      std::__throw_with_nested_impl(std::forward<_Tp>(__t), __nest{});
    }


  template<typename _Tp>
    using __rethrow_if_nested_cond = typename enable_if<
      __and_<is_polymorphic<_Tp>,
      __or_<__not_<is_base_of<nested_exception, _Tp>>,
     is_convertible<_Tp*, nested_exception*>>>::value
    >::type;


  template<typename _Ex>
    inline __rethrow_if_nested_cond<_Ex>
    __rethrow_if_nested_impl(const _Ex* __ptr)
    {
      if (auto __ne_ptr = dynamic_cast<const nested_exception*>(__ptr))
 __ne_ptr->rethrow_nested();
    }


  inline void
  __rethrow_if_nested_impl(const void*)
  { }


  template<typename _Ex>
    inline void
    rethrow_if_nested(const _Ex& __ex)
    { std::__rethrow_if_nested_impl(std::__addressof(__ex)); }


}

}



#pragma GCC visibility pop
# 145 "/usr/include/c++/9.2.0/exception" 2 3
# 41 "/usr/include/c++/9.2.0/new" 2 3

#pragma GCC visibility push(default)

extern "C++" {

namespace std
{






  class bad_alloc : public exception
  {
  public:
    bad_alloc() throw() { }


    bad_alloc(const bad_alloc&) = default;
    bad_alloc& operator=(const bad_alloc&) = default;




    virtual ~bad_alloc() throw();


    virtual const char* what() const throw();
  };


  class bad_array_new_length : public bad_alloc
  {
  public:
    bad_array_new_length() throw() { }



    virtual ~bad_array_new_length() throw();


    virtual const char* what() const throw();
  };






  struct nothrow_t
  {

    explicit nothrow_t() = default;

  };

  extern const nothrow_t nothrow;



  typedef void (*new_handler)();



  new_handler set_new_handler(new_handler) throw();



  new_handler get_new_handler() noexcept;

}
# 125 "/usr/include/c++/9.2.0/new" 3
 void* operator new(std::size_t)
  __attribute__((__externally_visible__));
 void* operator new[](std::size_t)
  __attribute__((__externally_visible__));
void operator delete(void*) noexcept
  __attribute__((__externally_visible__));
void operator delete[](void*) noexcept
  __attribute__((__externally_visible__));

void operator delete(void*, std::size_t) noexcept
  __attribute__((__externally_visible__));
void operator delete[](void*, std::size_t) noexcept
  __attribute__((__externally_visible__));

 void* operator new(std::size_t, const std::nothrow_t&) noexcept
  __attribute__((__externally_visible__, __malloc__));
 void* operator new[](std::size_t, const std::nothrow_t&) noexcept
  __attribute__((__externally_visible__, __malloc__));
void operator delete(void*, const std::nothrow_t&) noexcept
  __attribute__((__externally_visible__));
void operator delete[](void*, const std::nothrow_t&) noexcept
  __attribute__((__externally_visible__));
# 173 "/usr/include/c++/9.2.0/new" 3
 inline void* operator new(std::size_t, void* __p) noexcept
{ return __p; }
 inline void* operator new[](std::size_t, void* __p) noexcept
{ return __p; }


inline void operator delete (void*, void*) noexcept { }
inline void operator delete[](void*, void*) noexcept { }

}
# 226 "/usr/include/c++/9.2.0/new" 3
#pragma GCC visibility pop
# 34 "/usr/include/c++/9.2.0/ext/new_allocator.h" 2 3
# 1 "/usr/include/c++/9.2.0/bits/functexcept.h" 1 3
# 42 "/usr/include/c++/9.2.0/bits/functexcept.h" 3
namespace std __attribute__ ((__visibility__ ("default")))
{



  void
  __throw_bad_exception(void) __attribute__((__noreturn__));


  void
  __throw_bad_alloc(void) __attribute__((__noreturn__));


  void
  __throw_bad_cast(void) __attribute__((__noreturn__));

  void
  __throw_bad_typeid(void) __attribute__((__noreturn__));


  void
  __throw_logic_error(const char*) __attribute__((__noreturn__));

  void
  __throw_domain_error(const char*) __attribute__((__noreturn__));

  void
  __throw_invalid_argument(const char*) __attribute__((__noreturn__));

  void
  __throw_length_error(const char*) __attribute__((__noreturn__));

  void
  __throw_out_of_range(const char*) __attribute__((__noreturn__));

  void
  __throw_out_of_range_fmt(const char*, ...) __attribute__((__noreturn__))
    __attribute__((__format__(__gnu_printf__, 1, 2)));

  void
  __throw_runtime_error(const char*) __attribute__((__noreturn__));

  void
  __throw_range_error(const char*) __attribute__((__noreturn__));

  void
  __throw_overflow_error(const char*) __attribute__((__noreturn__));

  void
  __throw_underflow_error(const char*) __attribute__((__noreturn__));


  void
  __throw_ios_failure(const char*) __attribute__((__noreturn__));

  void
  __throw_ios_failure(const char*, int) __attribute__((__noreturn__));


  void
  __throw_system_error(int) __attribute__((__noreturn__));


  void
  __throw_future_error(int) __attribute__((__noreturn__));


  void
  __throw_bad_function_call() __attribute__((__noreturn__));


}
# 35 "/usr/include/c++/9.2.0/ext/new_allocator.h" 2 3





namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{


  using std::size_t;
  using std::ptrdiff_t;
# 57 "/usr/include/c++/9.2.0/ext/new_allocator.h" 3
  template<typename _Tp>
    class new_allocator
    {
    public:
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Tp* pointer;
      typedef const _Tp* const_pointer;
      typedef _Tp& reference;
      typedef const _Tp& const_reference;
      typedef _Tp value_type;

      template<typename _Tp1>
 struct rebind
 { typedef new_allocator<_Tp1> other; };




      typedef std::true_type propagate_on_container_move_assignment;


     
      new_allocator() noexcept { }

     
      new_allocator(const new_allocator&) noexcept { }

      template<typename _Tp1>

 new_allocator(const new_allocator<_Tp1>&) noexcept { }

      ~new_allocator() noexcept { }

      pointer
      address(reference __x) const noexcept
      { return std::__addressof(__x); }

      const_pointer
      address(const_reference __x) const noexcept
      { return std::__addressof(__x); }



      pointer
      allocate(size_type __n, const void* = static_cast<const void*>(0))
      {
 if (__n > this->max_size())
   std::__throw_bad_alloc();
# 114 "/usr/include/c++/9.2.0/ext/new_allocator.h" 3
 return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
      }


      void
      deallocate(pointer __p, size_type)
      {







 ::operator delete(__p);
      }

      size_type
      max_size() const noexcept
      {

 return size_t(0x7fffffffffffffffL) / sizeof(_Tp);



      }


      template<typename _Up, typename... _Args>
 void
 construct(_Up* __p, _Args&&... __args)
 noexcept(noexcept(::new((void *)__p)
       _Up(std::forward<_Args>(__args)...)))
 { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }

      template<typename _Up>
 void
 destroy(_Up* __p)
 noexcept(noexcept( __p->~_Up()))
 { __p->~_Up(); }
# 165 "/usr/include/c++/9.2.0/ext/new_allocator.h" 3
      template<typename _Up>
 friend bool
 operator==(const new_allocator&, const new_allocator<_Up>&)
 noexcept
 { return true; }

      template<typename _Up>
 friend bool
 operator!=(const new_allocator&, const new_allocator<_Up>&)
 noexcept
 { return false; }
    };


}
# 34 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++allocator.h" 2 3


namespace std
{
# 47 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++allocator.h" 3
  template<typename _Tp>
    using __allocator_base = __gnu_cxx::new_allocator<_Tp>;
}
# 47 "/usr/include/c++/9.2.0/bits/allocator.h" 2 3
# 1 "/usr/include/c++/9.2.0/bits/memoryfwd.h" 1 3
# 46 "/usr/include/c++/9.2.0/bits/memoryfwd.h" 3
       
# 47 "/usr/include/c++/9.2.0/bits/memoryfwd.h" 3



namespace std __attribute__ ((__visibility__ ("default")))
{

# 63 "/usr/include/c++/9.2.0/bits/memoryfwd.h" 3
  template<typename>
    class allocator;

  template<>
    class allocator<void>;


  template<typename, typename>
    struct uses_allocator;




}
# 48 "/usr/include/c++/9.2.0/bits/allocator.h" 2 3
# 57 "/usr/include/c++/9.2.0/bits/allocator.h" 3
namespace std __attribute__ ((__visibility__ ("default")))
{








  template<>
    class allocator<void>
    {
    public:
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef void* pointer;
      typedef const void* const_pointer;
      typedef void value_type;

      template<typename _Tp1>
 struct rebind
 { typedef allocator<_Tp1> other; };




      typedef true_type propagate_on_container_move_assignment;

      typedef true_type is_always_equal;

      template<typename _Up, typename... _Args>
 void
 construct(_Up* __p, _Args&&... __args)
 noexcept(noexcept(::new((void *)__p)
       _Up(std::forward<_Args>(__args)...)))
 { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }

      template<typename _Up>
 void
 destroy(_Up* __p)
 noexcept(noexcept(__p->~_Up()))
 { __p->~_Up(); }

    };
# 111 "/usr/include/c++/9.2.0/bits/allocator.h" 3
  template<typename _Tp>
    class allocator : public __allocator_base<_Tp>
    {
   public:
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Tp* pointer;
      typedef const _Tp* const_pointer;
      typedef _Tp& reference;
      typedef const _Tp& const_reference;
      typedef _Tp value_type;

      template<typename _Tp1>
 struct rebind
 { typedef allocator<_Tp1> other; };




      typedef true_type propagate_on_container_move_assignment;

      typedef true_type is_always_equal;




     
      allocator() noexcept { }

     
      allocator(const allocator& __a) noexcept
      : __allocator_base<_Tp>(__a) { }



      allocator& operator=(const allocator&) = default;


      template<typename _Tp1>

 allocator(const allocator<_Tp1>&) noexcept { }

      ~allocator() noexcept { }

      friend bool
      operator==(const allocator&, const allocator&) noexcept
      { return true; }

      friend bool
      operator!=(const allocator&, const allocator&) noexcept
      { return false; }


    };

  template<typename _T1, typename _T2>
    inline bool
    operator==(const allocator<_T1>&, const allocator<_T2>&)
    noexcept
    { return true; }

  template<typename _T1, typename _T2>
    inline bool
    operator!=(const allocator<_T1>&, const allocator<_T2>&)
    noexcept
    { return false; }



  template<typename _Tp>
    class allocator<const _Tp>
    {
    public:
      typedef _Tp value_type;
      template<typename _Up> allocator(const allocator<_Up>&) { }
    };

  template<typename _Tp>
    class allocator<volatile _Tp>
    {
    public:
      typedef _Tp value_type;
      template<typename _Up> allocator(const allocator<_Up>&) { }
    };

  template<typename _Tp>
    class allocator<const volatile _Tp>
    {
    public:
      typedef _Tp value_type;
      template<typename _Up> allocator(const allocator<_Up>&) { }
    };






  extern template class allocator<char>;
  extern template class allocator<wchar_t>;






  template<typename _Alloc, bool = __is_empty(_Alloc)>
    struct __alloc_swap
    { static void _S_do_it(_Alloc&, _Alloc&) noexcept { } };

  template<typename _Alloc>
    struct __alloc_swap<_Alloc, false>
    {
      static void
      _S_do_it(_Alloc& __one, _Alloc& __two) noexcept
      {

 if (__one != __two)
   swap(__one, __two);
      }
    };


  template<typename _Alloc, bool = __is_empty(_Alloc)>
    struct __alloc_neq
    {
      static bool
      _S_do_it(const _Alloc&, const _Alloc&)
      { return false; }
    };

  template<typename _Alloc>
    struct __alloc_neq<_Alloc, false>
    {
      static bool
      _S_do_it(const _Alloc& __one, const _Alloc& __two)
      { return __one != __two; }
    };


  template<typename _Tp, bool
    = __or_<is_copy_constructible<typename _Tp::value_type>,
            is_nothrow_move_constructible<typename _Tp::value_type>>::value>
    struct __shrink_to_fit_aux
    { static bool _S_do_it(_Tp&) noexcept { return false; } };

  template<typename _Tp>
    struct __shrink_to_fit_aux<_Tp, true>
    {
      static bool
      _S_do_it(_Tp& __c) noexcept
      {

 try
   {
     _Tp(__make_move_if_noexcept_iterator(__c.begin()),
  __make_move_if_noexcept_iterator(__c.end()),
  __c.get_allocator()).swap(__c);
     return true;
   }
 catch(...)
   { return false; }



      }
    };



}
# 41 "/usr/include/c++/9.2.0/unordered_map" 2 3
# 1 "/usr/include/c++/9.2.0/ext/alloc_traits.h" 1 3
# 32 "/usr/include/c++/9.2.0/ext/alloc_traits.h" 3
       
# 33 "/usr/include/c++/9.2.0/ext/alloc_traits.h" 3



# 1 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 1 3
# 36 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 3
# 1 "/usr/include/c++/9.2.0/bits/ptr_traits.h" 1 3
# 37 "/usr/include/c++/9.2.0/bits/ptr_traits.h" 3
namespace std __attribute__ ((__visibility__ ("default")))
{


  class __undefined;


  template<typename _Tp>
    struct __get_first_arg
    { using type = __undefined; };

  template<template<typename, typename...> class _Template, typename _Tp,
           typename... _Types>
    struct __get_first_arg<_Template<_Tp, _Types...>>
    { using type = _Tp; };

  template<typename _Tp>
    using __get_first_arg_t = typename __get_first_arg<_Tp>::type;


  template<typename _Tp, typename _Up>
    struct __replace_first_arg
    { };

  template<template<typename, typename...> class _Template, typename _Up,
           typename _Tp, typename... _Types>
    struct __replace_first_arg<_Template<_Tp, _Types...>, _Up>
    { using type = _Template<_Up, _Types...>; };

  template<typename _Tp, typename _Up>
    using __replace_first_arg_t = typename __replace_first_arg<_Tp, _Up>::type;

  template<typename _Tp>
    using __make_not_void
      = typename conditional<is_void<_Tp>::value, __undefined, _Tp>::type;





  template<typename _Ptr>
    struct pointer_traits
    {
    private:
      template<typename _Tp>
 using __element_type = typename _Tp::element_type;

      template<typename _Tp>
 using __difference_type = typename _Tp::difference_type;

      template<typename _Tp, typename _Up, typename = void>
 struct __rebind : __replace_first_arg<_Tp, _Up> { };

      template<typename _Tp, typename _Up>
 struct __rebind<_Tp, _Up, __void_t<typename _Tp::template rebind<_Up>>>
 { using type = typename _Tp::template rebind<_Up>; };

    public:

      using pointer = _Ptr;


      using element_type
 = __detected_or_t<__get_first_arg_t<_Ptr>, __element_type, _Ptr>;


      using difference_type
 = __detected_or_t<ptrdiff_t, __difference_type, _Ptr>;


      template<typename _Up>
        using rebind = typename __rebind<_Ptr, _Up>::type;

      static _Ptr
      pointer_to(__make_not_void<element_type>& __e)
      { return _Ptr::pointer_to(__e); }

      static_assert(!is_same<element_type, __undefined>::value,
   "pointer type defines element_type or is like SomePointer<T, Args>");
    };





  template<typename _Tp>
    struct pointer_traits<_Tp*>
    {

      typedef _Tp* pointer;

      typedef _Tp element_type;

      typedef ptrdiff_t difference_type;

      template<typename _Up>
        using rebind = _Up*;






      static pointer
      pointer_to(__make_not_void<element_type>& __r) noexcept
      { return std::addressof(__r); }
    };


  template<typename _Ptr, typename _Tp>
    using __ptr_rebind = typename pointer_traits<_Ptr>::template rebind<_Tp>;

  template<typename _Tp>
    constexpr _Tp*
    __to_address(_Tp* __ptr) noexcept
    {
      static_assert(!std::is_function<_Tp>::value, "not a function pointer");
      return __ptr;
    }


  template<typename _Ptr>
    constexpr typename std::pointer_traits<_Ptr>::element_type*
    __to_address(const _Ptr& __ptr)
    { return std::__to_address(__ptr.operator->()); }
# 198 "/usr/include/c++/9.2.0/bits/ptr_traits.h" 3

}
# 37 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 2 3
# 1 "/usr/include/c++/9.2.0/ext/numeric_traits.h" 1 3
# 32 "/usr/include/c++/9.2.0/ext/numeric_traits.h" 3
       
# 33 "/usr/include/c++/9.2.0/ext/numeric_traits.h" 3

# 1 "/usr/include/c++/9.2.0/bits/cpp_type_traits.h" 1 3
# 35 "/usr/include/c++/9.2.0/bits/cpp_type_traits.h" 3
       
# 36 "/usr/include/c++/9.2.0/bits/cpp_type_traits.h" 3
# 67 "/usr/include/c++/9.2.0/bits/cpp_type_traits.h" 3
extern "C++" {

namespace std __attribute__ ((__visibility__ ("default")))
{


  struct __true_type { };
  struct __false_type { };

  template<bool>
    struct __truth_type
    { typedef __false_type __type; };

  template<>
    struct __truth_type<true>
    { typedef __true_type __type; };



  template<class _Sp, class _Tp>
    struct __traitor
    {
      enum { __value = bool(_Sp::__value) || bool(_Tp::__value) };
      typedef typename __truth_type<__value>::__type __type;
    };


  template<typename, typename>
    struct __are_same
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };

  template<typename _Tp>
    struct __are_same<_Tp, _Tp>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };


  template<typename _Tp>
    struct __is_void
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };

  template<>
    struct __is_void<void>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };




  template<typename _Tp>
    struct __is_integer
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };





  template<>
    struct __is_integer<bool>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_integer<char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_integer<signed char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_integer<unsigned char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };


  template<>
    struct __is_integer<wchar_t>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
# 184 "/usr/include/c++/9.2.0/bits/cpp_type_traits.h" 3
  template<>
    struct __is_integer<char16_t>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_integer<char32_t>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };


  template<>
    struct __is_integer<short>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_integer<unsigned short>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_integer<int>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_integer<unsigned int>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_integer<long>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_integer<unsigned long>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_integer<long long>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_integer<unsigned long long>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
# 270 "/usr/include/c++/9.2.0/bits/cpp_type_traits.h" 3
template<> struct __is_integer<__int128> { enum { __value = 1 }; typedef __true_type __type; }; template<> struct __is_integer<unsigned __int128> { enum { __value = 1 }; typedef __true_type __type; };
# 287 "/usr/include/c++/9.2.0/bits/cpp_type_traits.h" 3
  template<typename _Tp>
    struct __is_floating
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };


  template<>
    struct __is_floating<float>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_floating<double>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_floating<long double>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };




  template<typename _Tp>
    struct __is_pointer
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };

  template<typename _Tp>
    struct __is_pointer<_Tp*>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };




  template<typename _Tp>
    struct __is_arithmetic
    : public __traitor<__is_integer<_Tp>, __is_floating<_Tp> >
    { };




  template<typename _Tp>
    struct __is_scalar
    : public __traitor<__is_arithmetic<_Tp>, __is_pointer<_Tp> >
    { };




  template<typename _Tp>
    struct __is_char
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };

  template<>
    struct __is_char<char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };


  template<>
    struct __is_char<wchar_t>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };


  template<typename _Tp>
    struct __is_byte
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };

  template<>
    struct __is_byte<char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_byte<signed char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<>
    struct __is_byte<unsigned char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
# 417 "/usr/include/c++/9.2.0/bits/cpp_type_traits.h" 3
  template<typename _Tp>
    struct __is_move_iterator
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };



  template<typename _Iterator>
    inline _Iterator
    __miter_base(_Iterator __it)
    { return __it; }


}
}
# 35 "/usr/include/c++/9.2.0/ext/numeric_traits.h" 2 3
# 1 "/usr/include/c++/9.2.0/ext/type_traits.h" 1 3
# 32 "/usr/include/c++/9.2.0/ext/type_traits.h" 3
       
# 33 "/usr/include/c++/9.2.0/ext/type_traits.h" 3




extern "C++" {

namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{



  template<bool, typename>
    struct __enable_if
    { };

  template<typename _Tp>
    struct __enable_if<true, _Tp>
    { typedef _Tp __type; };



  template<bool _Cond, typename _Iftrue, typename _Iffalse>
    struct __conditional_type
    { typedef _Iftrue __type; };

  template<typename _Iftrue, typename _Iffalse>
    struct __conditional_type<false, _Iftrue, _Iffalse>
    { typedef _Iffalse __type; };



  template<typename _Tp>
    struct __add_unsigned
    {
    private:
      typedef __enable_if<std::__is_integer<_Tp>::__value, _Tp> __if_type;

    public:
      typedef typename __if_type::__type __type;
    };

  template<>
    struct __add_unsigned<char>
    { typedef unsigned char __type; };

  template<>
    struct __add_unsigned<signed char>
    { typedef unsigned char __type; };

  template<>
    struct __add_unsigned<short>
    { typedef unsigned short __type; };

  template<>
    struct __add_unsigned<int>
    { typedef unsigned int __type; };

  template<>
    struct __add_unsigned<long>
    { typedef unsigned long __type; };

  template<>
    struct __add_unsigned<long long>
    { typedef unsigned long long __type; };


  template<>
    struct __add_unsigned<bool>;

  template<>
    struct __add_unsigned<wchar_t>;



  template<typename _Tp>
    struct __remove_unsigned
    {
    private:
      typedef __enable_if<std::__is_integer<_Tp>::__value, _Tp> __if_type;

    public:
      typedef typename __if_type::__type __type;
    };

  template<>
    struct __remove_unsigned<char>
    { typedef signed char __type; };

  template<>
    struct __remove_unsigned<unsigned char>
    { typedef signed char __type; };

  template<>
    struct __remove_unsigned<unsigned short>
    { typedef short __type; };

  template<>
    struct __remove_unsigned<unsigned int>
    { typedef int __type; };

  template<>
    struct __remove_unsigned<unsigned long>
    { typedef long __type; };

  template<>
    struct __remove_unsigned<unsigned long long>
    { typedef long long __type; };


  template<>
    struct __remove_unsigned<bool>;

  template<>
    struct __remove_unsigned<wchar_t>;



  template<typename _Type>
    inline bool
    __is_null_pointer(_Type* __ptr)
    { return __ptr == 0; }

  template<typename _Type>
    inline bool
    __is_null_pointer(_Type)
    { return false; }


  inline bool
  __is_null_pointer(std::nullptr_t)
  { return true; }



  template<typename _Tp, bool = std::__is_integer<_Tp>::__value>
    struct __promote
    { typedef double __type; };




  template<typename _Tp>
    struct __promote<_Tp, false>
    { };

  template<>
    struct __promote<long double>
    { typedef long double __type; };

  template<>
    struct __promote<double>
    { typedef double __type; };

  template<>
    struct __promote<float>
    { typedef float __type; };

  template<typename _Tp, typename _Up,
           typename _Tp2 = typename __promote<_Tp>::__type,
           typename _Up2 = typename __promote<_Up>::__type>
    struct __promote_2
    {
      typedef __typeof__(_Tp2() + _Up2()) __type;
    };

  template<typename _Tp, typename _Up, typename _Vp,
           typename _Tp2 = typename __promote<_Tp>::__type,
           typename _Up2 = typename __promote<_Up>::__type,
           typename _Vp2 = typename __promote<_Vp>::__type>
    struct __promote_3
    {
      typedef __typeof__(_Tp2() + _Up2() + _Vp2()) __type;
    };

  template<typename _Tp, typename _Up, typename _Vp, typename _Wp,
           typename _Tp2 = typename __promote<_Tp>::__type,
           typename _Up2 = typename __promote<_Up>::__type,
           typename _Vp2 = typename __promote<_Vp>::__type,
           typename _Wp2 = typename __promote<_Wp>::__type>
    struct __promote_4
    {
      typedef __typeof__(_Tp2() + _Up2() + _Vp2() + _Wp2()) __type;
    };


}
}
# 36 "/usr/include/c++/9.2.0/ext/numeric_traits.h" 2 3

namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{

# 54 "/usr/include/c++/9.2.0/ext/numeric_traits.h" 3
  template<typename _Value>
    struct __numeric_traits_integer
    {

      static const _Value __min = (((_Value)(-1) < 0) ? (_Value)1 << (sizeof(_Value) * 8 - ((_Value)(-1) < 0)) : (_Value)0);
      static const _Value __max = (((_Value)(-1) < 0) ? (((((_Value)1 << ((sizeof(_Value) * 8 - ((_Value)(-1) < 0)) - 1)) - 1) << 1) + 1) : ~(_Value)0);



      static const bool __is_signed = ((_Value)(-1) < 0);
      static const int __digits = (sizeof(_Value) * 8 - ((_Value)(-1) < 0));
    };

  template<typename _Value>
    const _Value __numeric_traits_integer<_Value>::__min;

  template<typename _Value>
    const _Value __numeric_traits_integer<_Value>::__max;

  template<typename _Value>
    const bool __numeric_traits_integer<_Value>::__is_signed;

  template<typename _Value>
    const int __numeric_traits_integer<_Value>::__digits;
# 99 "/usr/include/c++/9.2.0/ext/numeric_traits.h" 3
  template<typename _Value>
    struct __numeric_traits_floating
    {

      static const int __max_digits10 = (2 + (std::__are_same<_Value, float>::__value ? 24 : std::__are_same<_Value, double>::__value ? 53 : 64) * 643L / 2136);


      static const bool __is_signed = true;
      static const int __digits10 = (std::__are_same<_Value, float>::__value ? 6 : std::__are_same<_Value, double>::__value ? 15 : 18);
      static const int __max_exponent10 = (std::__are_same<_Value, float>::__value ? 38 : std::__are_same<_Value, double>::__value ? 308 : 4932);
    };

  template<typename _Value>
    const int __numeric_traits_floating<_Value>::__max_digits10;

  template<typename _Value>
    const bool __numeric_traits_floating<_Value>::__is_signed;

  template<typename _Value>
    const int __numeric_traits_floating<_Value>::__digits10;

  template<typename _Value>
    const int __numeric_traits_floating<_Value>::__max_exponent10;

  template<typename _Value>
    struct __numeric_traits
    : public __conditional_type<std::__is_integer<_Value>::__value,
    __numeric_traits_integer<_Value>,
    __numeric_traits_floating<_Value> >::__type
    { };


}
# 38 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 2 3



namespace std __attribute__ ((__visibility__ ("default")))
{


  struct __allocator_traits_base
  {
    template<typename _Tp, typename _Up, typename = void>
      struct __rebind : __replace_first_arg<_Tp, _Up> { };

    template<typename _Tp, typename _Up>
      struct __rebind<_Tp, _Up,
        __void_t<typename _Tp::template rebind<_Up>::other>>
      { using type = typename _Tp::template rebind<_Up>::other; };

  protected:
    template<typename _Tp>
      using __pointer = typename _Tp::pointer;
    template<typename _Tp>
      using __c_pointer = typename _Tp::const_pointer;
    template<typename _Tp>
      using __v_pointer = typename _Tp::void_pointer;
    template<typename _Tp>
      using __cv_pointer = typename _Tp::const_void_pointer;
    template<typename _Tp>
      using __pocca = typename _Tp::propagate_on_container_copy_assignment;
    template<typename _Tp>
      using __pocma = typename _Tp::propagate_on_container_move_assignment;
    template<typename _Tp>
      using __pocs = typename _Tp::propagate_on_container_swap;
    template<typename _Tp>
      using __equal = typename _Tp::is_always_equal;
  };

  template<typename _Alloc, typename _Up>
    using __alloc_rebind
      = typename __allocator_traits_base::template __rebind<_Alloc, _Up>::type;





  template<typename _Alloc>
    struct allocator_traits : __allocator_traits_base
    {

      typedef _Alloc allocator_type;

      typedef typename _Alloc::value_type value_type;






      using pointer = __detected_or_t<value_type*, __pointer, _Alloc>;

    private:

      template<template<typename> class _Func, typename _Tp, typename = void>
 struct _Ptr
 {
   using type = typename pointer_traits<pointer>::template rebind<_Tp>;
 };

      template<template<typename> class _Func, typename _Tp>
 struct _Ptr<_Func, _Tp, __void_t<_Func<_Alloc>>>
 {
   using type = _Func<_Alloc>;
 };


      template<typename _A2, typename _PtrT, typename = void>
 struct _Diff
 { using type = typename pointer_traits<_PtrT>::difference_type; };

      template<typename _A2, typename _PtrT>
 struct _Diff<_A2, _PtrT, __void_t<typename _A2::difference_type>>
 { using type = typename _A2::difference_type; };


      template<typename _A2, typename _DiffT, typename = void>
 struct _Size : make_unsigned<_DiffT> { };

      template<typename _A2, typename _DiffT>
 struct _Size<_A2, _DiffT, __void_t<typename _A2::size_type>>
 { using type = typename _A2::size_type; };

    public:






      using const_pointer = typename _Ptr<__c_pointer, const value_type>::type;







      using void_pointer = typename _Ptr<__v_pointer, void>::type;







      using const_void_pointer = typename _Ptr<__cv_pointer, const void>::type;







      using difference_type = typename _Diff<_Alloc, pointer>::type;







      using size_type = typename _Size<_Alloc, difference_type>::type;







      using propagate_on_container_copy_assignment
 = __detected_or_t<false_type, __pocca, _Alloc>;







      using propagate_on_container_move_assignment
 = __detected_or_t<false_type, __pocma, _Alloc>;







      using propagate_on_container_swap
 = __detected_or_t<false_type, __pocs, _Alloc>;







      using is_always_equal
 = __detected_or_t<typename is_empty<_Alloc>::type, __equal, _Alloc>;

      template<typename _Tp>
 using rebind_alloc = __alloc_rebind<_Alloc, _Tp>;
      template<typename _Tp>
 using rebind_traits = allocator_traits<rebind_alloc<_Tp>>;

    private:
      template<typename _Alloc2>
 static auto
 _S_allocate(_Alloc2& __a, size_type __n, const_void_pointer __hint, int)
 -> decltype(__a.allocate(__n, __hint))
 { return __a.allocate(__n, __hint); }

      template<typename _Alloc2>
 static pointer
 _S_allocate(_Alloc2& __a, size_type __n, const_void_pointer, ...)
 { return __a.allocate(__n); }

      template<typename _Tp, typename... _Args>
 struct __construct_helper
 {
   template<typename _Alloc2,
     typename = decltype(std::declval<_Alloc2*>()->construct(
    std::declval<_Tp*>(), std::declval<_Args>()...))>
     static true_type __test(int);

   template<typename>
     static false_type __test(...);

   using type = decltype(__test<_Alloc>(0));
 };

      template<typename _Tp, typename... _Args>
 using __has_construct
   = typename __construct_helper<_Tp, _Args...>::type;

      template<typename _Tp, typename... _Args>
 static _Require<__has_construct<_Tp, _Args...>>
 _S_construct(_Alloc& __a, _Tp* __p, _Args&&... __args)
 noexcept(noexcept(__a.construct(__p, std::forward<_Args>(__args)...)))
 { __a.construct(__p, std::forward<_Args>(__args)...); }

      template<typename _Tp, typename... _Args>
 static
 _Require<__and_<__not_<__has_construct<_Tp, _Args...>>,
          is_constructible<_Tp, _Args...>>>
 _S_construct(_Alloc&, _Tp* __p, _Args&&... __args)
 noexcept(noexcept(::new((void*)__p)
     _Tp(std::forward<_Args>(__args)...)))
 { ::new((void*)__p) _Tp(std::forward<_Args>(__args)...); }

      template<typename _Alloc2, typename _Tp>
 static auto
 _S_destroy(_Alloc2& __a, _Tp* __p, int)
 noexcept(noexcept(__a.destroy(__p)))
 -> decltype(__a.destroy(__p))
 { __a.destroy(__p); }

      template<typename _Alloc2, typename _Tp>
 static void
 _S_destroy(_Alloc2&, _Tp* __p, ...)
 noexcept(noexcept(__p->~_Tp()))
 { __p->~_Tp(); }

      template<typename _Alloc2>
 static auto
 _S_max_size(_Alloc2& __a, int)
 -> decltype(__a.max_size())
 { return __a.max_size(); }

      template<typename _Alloc2>
 static size_type
 _S_max_size(_Alloc2&, ...)
 {


   return __gnu_cxx::__numeric_traits<size_type>::__max
     / sizeof(value_type);
 }

      template<typename _Alloc2>
 static auto
 _S_select(_Alloc2& __a, int)
 -> decltype(__a.select_on_container_copy_construction())
 { return __a.select_on_container_copy_construction(); }

      template<typename _Alloc2>
 static _Alloc2
 _S_select(_Alloc2& __a, ...)
 { return __a; }

    public:
# 304 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 3
      static pointer
      allocate(_Alloc& __a, size_type __n)
      { return __a.allocate(__n); }
# 319 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 3
      static pointer
      allocate(_Alloc& __a, size_type __n, const_void_pointer __hint)
      { return _S_allocate(__a, __n, __hint, 0); }
# 331 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 3
      static void
      deallocate(_Alloc& __a, pointer __p, size_type __n)
      { __a.deallocate(__p, __n); }
# 346 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 3
      template<typename _Tp, typename... _Args>
 static auto construct(_Alloc& __a, _Tp* __p, _Args&&... __args)
 noexcept(noexcept(_S_construct(__a, __p,
           std::forward<_Args>(__args)...)))
 -> decltype(_S_construct(__a, __p, std::forward<_Args>(__args)...))
 { _S_construct(__a, __p, std::forward<_Args>(__args)...); }
# 361 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 3
      template<typename _Tp>
 static void destroy(_Alloc& __a, _Tp* __p)
 noexcept(noexcept(_S_destroy(__a, __p, 0)))
 { _S_destroy(__a, __p, 0); }
# 374 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 3
      static size_type max_size(const _Alloc& __a) noexcept
      { return _S_max_size(__a, 0); }
# 385 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 3
      static _Alloc
      select_on_container_copy_construction(const _Alloc& __rhs)
      { return _S_select(__rhs, 0); }
    };


  template<typename _Tp>
    struct allocator_traits<allocator<_Tp>>
    {

      using allocator_type = allocator<_Tp>;

      using value_type = _Tp;


      using pointer = _Tp*;


      using const_pointer = const _Tp*;


      using void_pointer = void*;


      using const_void_pointer = const void*;


      using difference_type = std::ptrdiff_t;


      using size_type = std::size_t;


      using propagate_on_container_copy_assignment = false_type;


      using propagate_on_container_move_assignment = true_type;


      using propagate_on_container_swap = false_type;


      using is_always_equal = true_type;

      template<typename _Up>
 using rebind_alloc = allocator<_Up>;

      template<typename _Up>
 using rebind_traits = allocator_traits<allocator<_Up>>;
# 442 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 3
      static pointer
      allocate(allocator_type& __a, size_type __n)
      { return __a.allocate(__n); }
# 456 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 3
      static pointer
      allocate(allocator_type& __a, size_type __n, const_void_pointer __hint)
      { return __a.allocate(__n, __hint); }
# 468 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 3
      static void
      deallocate(allocator_type& __a, pointer __p, size_type __n)
      { __a.deallocate(__p, __n); }
# 480 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 3
      template<typename _Up, typename... _Args>
 static void
 construct(allocator_type& __a, _Up* __p, _Args&&... __args)
 noexcept(noexcept(__a.construct(__p, std::forward<_Args>(__args)...)))
 { __a.construct(__p, std::forward<_Args>(__args)...); }
# 493 "/usr/include/c++/9.2.0/bits/alloc_traits.h" 3
      template<typename _Up>
 static void
 destroy(allocator_type& __a, _Up* __p)
 noexcept(noexcept(__a.destroy(__p)))
 { __a.destroy(__p); }






      static size_type
      max_size(const allocator_type& __a) noexcept
      { return __a.max_size(); }






      static allocator_type
      select_on_container_copy_construction(const allocator_type& __rhs)
      { return __rhs; }
    };


  template<typename _Alloc>
    inline void
    __do_alloc_on_copy(_Alloc& __one, const _Alloc& __two, true_type)
    { __one = __two; }

  template<typename _Alloc>
    inline void
    __do_alloc_on_copy(_Alloc&, const _Alloc&, false_type)
    { }

  template<typename _Alloc>
    inline void __alloc_on_copy(_Alloc& __one, const _Alloc& __two)
    {
      typedef allocator_traits<_Alloc> __traits;
      typedef typename __traits::propagate_on_container_copy_assignment __pocca;
      __do_alloc_on_copy(__one, __two, __pocca());
    }

  template<typename _Alloc>
    inline _Alloc __alloc_on_copy(const _Alloc& __a)
    {
      typedef allocator_traits<_Alloc> __traits;
      return __traits::select_on_container_copy_construction(__a);
    }

  template<typename _Alloc>
    inline void __do_alloc_on_move(_Alloc& __one, _Alloc& __two, true_type)
    { __one = std::move(__two); }

  template<typename _Alloc>
    inline void __do_alloc_on_move(_Alloc&, _Alloc&, false_type)
    { }

  template<typename _Alloc>
    inline void __alloc_on_move(_Alloc& __one, _Alloc& __two)
    {
      typedef allocator_traits<_Alloc> __traits;
      typedef typename __traits::propagate_on_container_move_assignment __pocma;
      __do_alloc_on_move(__one, __two, __pocma());
    }

  template<typename _Alloc>
    inline void __do_alloc_on_swap(_Alloc& __one, _Alloc& __two, true_type)
    {
      using std::swap;
      swap(__one, __two);
    }

  template<typename _Alloc>
    inline void __do_alloc_on_swap(_Alloc&, _Alloc&, false_type)
    { }

  template<typename _Alloc>
    inline void __alloc_on_swap(_Alloc& __one, _Alloc& __two)
    {
      typedef allocator_traits<_Alloc> __traits;
      typedef typename __traits::propagate_on_container_swap __pocs;
      __do_alloc_on_swap(__one, __two, __pocs());
    }

  template<typename _Alloc, typename _Tp,
    typename _ValueT = __remove_cvref_t<typename _Alloc::value_type>,
    typename = void>
    struct __is_alloc_insertable_impl
    : false_type
    { };

  template<typename _Alloc, typename _Tp, typename _ValueT>
    struct __is_alloc_insertable_impl<_Alloc, _Tp, _ValueT,
      __void_t<decltype(allocator_traits<_Alloc>::construct(
     std::declval<_Alloc&>(), std::declval<_ValueT*>(),
     std::declval<_Tp>()))>>
    : true_type
    { };




  template<typename _Alloc>
    struct __is_copy_insertable
    : __is_alloc_insertable_impl<_Alloc,
     typename _Alloc::value_type const&>::type
    { };


  template<typename _Tp>
    struct __is_copy_insertable<allocator<_Tp>>
    : is_copy_constructible<_Tp>
    { };




  template<typename _Alloc>
    struct __is_move_insertable
    : __is_alloc_insertable_impl<_Alloc, typename _Alloc::value_type>::type
    { };


  template<typename _Tp>
    struct __is_move_insertable<allocator<_Tp>>
    : is_move_constructible<_Tp>
    { };


  template<typename _Alloc, typename = void>
    struct __is_allocator : false_type { };

  template<typename _Alloc>
    struct __is_allocator<_Alloc,
      __void_t<typename _Alloc::value_type,
        decltype(std::declval<_Alloc&>().allocate(size_t{}))>>
    : true_type { };

  template<typename _Alloc>
    using _RequireAllocator
      = typename enable_if<__is_allocator<_Alloc>::value, _Alloc>::type;

  template<typename _Alloc>
    using _RequireNotAllocator
      = typename enable_if<!__is_allocator<_Alloc>::value, _Alloc>::type;


}
# 37 "/usr/include/c++/9.2.0/ext/alloc_traits.h" 2 3




namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{






template<typename _Alloc, typename = typename _Alloc::value_type>
  struct __alloc_traits

  : std::allocator_traits<_Alloc>

  {
    typedef _Alloc allocator_type;

    typedef std::allocator_traits<_Alloc> _Base_type;
    typedef typename _Base_type::value_type value_type;
    typedef typename _Base_type::pointer pointer;
    typedef typename _Base_type::const_pointer const_pointer;
    typedef typename _Base_type::size_type size_type;
    typedef typename _Base_type::difference_type difference_type;

    typedef value_type& reference;
    typedef const value_type& const_reference;
    using _Base_type::allocate;
    using _Base_type::deallocate;
    using _Base_type::construct;
    using _Base_type::destroy;
    using _Base_type::max_size;

  private:
    template<typename _Ptr>
      using __is_custom_pointer
 = std::__and_<std::is_same<pointer, _Ptr>,
        std::__not_<std::is_pointer<_Ptr>>>;

  public:

    template<typename _Ptr, typename... _Args>
      static typename std::enable_if<__is_custom_pointer<_Ptr>::value>::type
      construct(_Alloc& __a, _Ptr __p, _Args&&... __args)
      noexcept(noexcept(_Base_type::construct(__a, std::__to_address(__p),
           std::forward<_Args>(__args)...)))
      {
 _Base_type::construct(__a, std::__to_address(__p),
         std::forward<_Args>(__args)...);
      }


    template<typename _Ptr>
      static typename std::enable_if<__is_custom_pointer<_Ptr>::value>::type
      destroy(_Alloc& __a, _Ptr __p)
      noexcept(noexcept(_Base_type::destroy(__a, std::__to_address(__p))))
      { _Base_type::destroy(__a, std::__to_address(__p)); }

    static _Alloc _S_select_on_copy(const _Alloc& __a)
    { return _Base_type::select_on_container_copy_construction(__a); }

    static void _S_on_swap(_Alloc& __a, _Alloc& __b)
    { std::__alloc_on_swap(__a, __b); }

    static constexpr bool _S_propagate_on_copy_assign()
    { return _Base_type::propagate_on_container_copy_assignment::value; }

    static constexpr bool _S_propagate_on_move_assign()
    { return _Base_type::propagate_on_container_move_assignment::value; }

    static constexpr bool _S_propagate_on_swap()
    { return _Base_type::propagate_on_container_swap::value; }

    static constexpr bool _S_always_equal()
    { return _Base_type::is_always_equal::value; }

    static constexpr bool _S_nothrow_move()
    { return _S_propagate_on_move_assign() || _S_always_equal(); }

    template<typename _Tp>
      struct rebind
      { typedef typename _Base_type::template rebind_alloc<_Tp> other; };
# 161 "/usr/include/c++/9.2.0/ext/alloc_traits.h" 3
  };


}
# 42 "/usr/include/c++/9.2.0/unordered_map" 2 3
# 1 "/usr/include/c++/9.2.0/ext/aligned_buffer.h" 1 3
# 32 "/usr/include/c++/9.2.0/ext/aligned_buffer.h" 3
       
# 33 "/usr/include/c++/9.2.0/ext/aligned_buffer.h" 3







namespace __gnu_cxx
{




  template<typename _Tp>
    struct __aligned_membuf
    {





      struct _Tp2 { _Tp _M_t; };

      alignas(__alignof__(_Tp2::_M_t)) unsigned char _M_storage[sizeof(_Tp)];

      __aligned_membuf() = default;


      __aligned_membuf(std::nullptr_t) { }

      void*
      _M_addr() noexcept
      { return static_cast<void*>(&_M_storage); }

      const void*
      _M_addr() const noexcept
      { return static_cast<const void*>(&_M_storage); }

      _Tp*
      _M_ptr() noexcept
      { return static_cast<_Tp*>(_M_addr()); }

      const _Tp*
      _M_ptr() const noexcept
      { return static_cast<const _Tp*>(_M_addr()); }
    };
# 89 "/usr/include/c++/9.2.0/ext/aligned_buffer.h" 3
  template<typename _Tp>
    struct __aligned_buffer
    : std::aligned_storage<sizeof(_Tp), __alignof__(_Tp)>
    {
      typename
 std::aligned_storage<sizeof(_Tp), __alignof__(_Tp)>::type _M_storage;

      __aligned_buffer() = default;


      __aligned_buffer(std::nullptr_t) { }

      void*
      _M_addr() noexcept
      {
        return static_cast<void*>(&_M_storage);
      }

      const void*
      _M_addr() const noexcept
      {
        return static_cast<const void*>(&_M_storage);
      }

      _Tp*
      _M_ptr() noexcept
      { return static_cast<_Tp*>(_M_addr()); }

      const _Tp*
      _M_ptr() const noexcept
      { return static_cast<const _Tp*>(_M_addr()); }
    };


}
# 43 "/usr/include/c++/9.2.0/unordered_map" 2 3
# 1 "/usr/include/c++/9.2.0/bits/stl_pair.h" 1 3
# 65 "/usr/include/c++/9.2.0/bits/stl_pair.h" 3
namespace std __attribute__ ((__visibility__ ("default")))
{

# 76 "/usr/include/c++/9.2.0/bits/stl_pair.h" 3
  struct piecewise_construct_t { explicit piecewise_construct_t() = default; };


  constexpr piecewise_construct_t piecewise_construct =
    piecewise_construct_t();


  template<typename...>
    class tuple;

  template<std::size_t...>
    struct _Index_tuple;






  template <bool, typename _T1, typename _T2>
    struct _PCC
    {
      template <typename _U1, typename _U2>
      static constexpr bool _ConstructiblePair()
      {
 return __and_<is_constructible<_T1, const _U1&>,
        is_constructible<_T2, const _U2&>>::value;
      }

      template <typename _U1, typename _U2>
      static constexpr bool _ImplicitlyConvertiblePair()
      {
 return __and_<is_convertible<const _U1&, _T1>,
        is_convertible<const _U2&, _T2>>::value;
      }

      template <typename _U1, typename _U2>
      static constexpr bool _MoveConstructiblePair()
      {
 return __and_<is_constructible<_T1, _U1&&>,
        is_constructible<_T2, _U2&&>>::value;
      }

      template <typename _U1, typename _U2>
      static constexpr bool _ImplicitlyMoveConvertiblePair()
      {
 return __and_<is_convertible<_U1&&, _T1>,
        is_convertible<_U2&&, _T2>>::value;
      }

      template <bool __implicit, typename _U1, typename _U2>
      static constexpr bool _CopyMovePair()
      {
 using __do_converts = __and_<is_convertible<const _U1&, _T1>,
      is_convertible<_U2&&, _T2>>;
 using __converts = typename conditional<__implicit,
           __do_converts,
           __not_<__do_converts>>::type;
 return __and_<is_constructible<_T1, const _U1&>,
        is_constructible<_T2, _U2&&>,
        __converts
        >::value;
      }

      template <bool __implicit, typename _U1, typename _U2>
      static constexpr bool _MoveCopyPair()
      {
 using __do_converts = __and_<is_convertible<_U1&&, _T1>,
      is_convertible<const _U2&, _T2>>;
 using __converts = typename conditional<__implicit,
           __do_converts,
           __not_<__do_converts>>::type;
 return __and_<is_constructible<_T1, _U1&&>,
        is_constructible<_T2, const _U2&&>,
        __converts
        >::value;
      }
  };

  template <typename _T1, typename _T2>
    struct _PCC<false, _T1, _T2>
    {
      template <typename _U1, typename _U2>
      static constexpr bool _ConstructiblePair()
      {
 return false;
      }

      template <typename _U1, typename _U2>
      static constexpr bool _ImplicitlyConvertiblePair()
      {
 return false;
      }

      template <typename _U1, typename _U2>
      static constexpr bool _MoveConstructiblePair()
      {
 return false;
      }

      template <typename _U1, typename _U2>
      static constexpr bool _ImplicitlyMoveConvertiblePair()
      {
 return false;
      }
  };




  struct __nonesuch_no_braces : std::__nonesuch {
    explicit __nonesuch_no_braces(const __nonesuch&) = delete;
  };


  template<typename _U1, typename _U2> class __pair_base
  {

    template<typename _T1, typename _T2> friend struct pair;
    __pair_base() = default;
    ~__pair_base() = default;
    __pair_base(const __pair_base&) = default;
    __pair_base& operator=(const __pair_base&) = delete;

  };







  template<typename _T1, typename _T2>
    struct pair
    : private __pair_base<_T1, _T2>
    {
      typedef _T1 first_type;
      typedef _T2 second_type;

      _T1 first;
      _T2 second;






      template <typename _U1 = _T1,
                typename _U2 = _T2,
                typename enable_if<__and_<
                                     __is_implicitly_default_constructible<_U1>,
                                     __is_implicitly_default_constructible<_U2>>
                                   ::value, bool>::type = true>

      constexpr pair()
      : first(), second() { }


      template <typename _U1 = _T1,
                typename _U2 = _T2,
                typename enable_if<__and_<
                       is_default_constructible<_U1>,
                       is_default_constructible<_U2>,
                       __not_<
                         __and_<__is_implicitly_default_constructible<_U1>,
                                __is_implicitly_default_constructible<_U2>>>>
                                   ::value, bool>::type = false>
      explicit constexpr pair()
      : first(), second() { }
# 252 "/usr/include/c++/9.2.0/bits/stl_pair.h" 3
      using _PCCP = _PCC<true, _T1, _T2>;

      template<typename _U1 = _T1, typename _U2=_T2, typename
        enable_if<_PCCP::template
      _ConstructiblePair<_U1, _U2>()
                  && _PCCP::template
      _ImplicitlyConvertiblePair<_U1, _U2>(),
                         bool>::type=true>
      constexpr pair(const _T1& __a, const _T2& __b)
      : first(__a), second(__b) { }

       template<typename _U1 = _T1, typename _U2=_T2, typename
  enable_if<_PCCP::template
       _ConstructiblePair<_U1, _U2>()
                   && !_PCCP::template
       _ImplicitlyConvertiblePair<_U1, _U2>(),
                         bool>::type=false>
      explicit constexpr pair(const _T1& __a, const _T2& __b)
      : first(__a), second(__b) { }
# 280 "/usr/include/c++/9.2.0/bits/stl_pair.h" 3
      template <typename _U1, typename _U2>
        using _PCCFP = _PCC<!is_same<_T1, _U1>::value
       || !is_same<_T2, _U2>::value,
       _T1, _T2>;

      template<typename _U1, typename _U2, typename
        enable_if<_PCCFP<_U1, _U2>::template
      _ConstructiblePair<_U1, _U2>()
                  && _PCCFP<_U1, _U2>::template
      _ImplicitlyConvertiblePair<_U1, _U2>(),
     bool>::type=true>
        constexpr pair(const pair<_U1, _U2>& __p)
        : first(__p.first), second(__p.second) { }

      template<typename _U1, typename _U2, typename
        enable_if<_PCCFP<_U1, _U2>::template
      _ConstructiblePair<_U1, _U2>()
    && !_PCCFP<_U1, _U2>::template
      _ImplicitlyConvertiblePair<_U1, _U2>(),
                         bool>::type=false>
 explicit constexpr pair(const pair<_U1, _U2>& __p)
 : first(__p.first), second(__p.second) { }

      constexpr pair(const pair&) = default;
      constexpr pair(pair&&) = default;


      template<typename _U1, typename
        enable_if<_PCCP::template
      _MoveCopyPair<true, _U1, _T2>(),
                         bool>::type=true>
       constexpr pair(_U1&& __x, const _T2& __y)
       : first(std::forward<_U1>(__x)), second(__y) { }

      template<typename _U1, typename
        enable_if<_PCCP::template
      _MoveCopyPair<false, _U1, _T2>(),
                         bool>::type=false>
       explicit constexpr pair(_U1&& __x, const _T2& __y)
       : first(std::forward<_U1>(__x)), second(__y) { }

      template<typename _U2, typename
        enable_if<_PCCP::template
      _CopyMovePair<true, _T1, _U2>(),
                         bool>::type=true>
       constexpr pair(const _T1& __x, _U2&& __y)
       : first(__x), second(std::forward<_U2>(__y)) { }

      template<typename _U2, typename
        enable_if<_PCCP::template
      _CopyMovePair<false, _T1, _U2>(),
                         bool>::type=false>
       explicit pair(const _T1& __x, _U2&& __y)
       : first(__x), second(std::forward<_U2>(__y)) { }

      template<typename _U1, typename _U2, typename
        enable_if<_PCCP::template
      _MoveConstructiblePair<_U1, _U2>()
     && _PCCP::template
      _ImplicitlyMoveConvertiblePair<_U1, _U2>(),
                         bool>::type=true>
 constexpr pair(_U1&& __x, _U2&& __y)
 : first(std::forward<_U1>(__x)), second(std::forward<_U2>(__y)) { }

      template<typename _U1, typename _U2, typename
        enable_if<_PCCP::template
      _MoveConstructiblePair<_U1, _U2>()
     && !_PCCP::template
      _ImplicitlyMoveConvertiblePair<_U1, _U2>(),
                         bool>::type=false>
 explicit constexpr pair(_U1&& __x, _U2&& __y)
 : first(std::forward<_U1>(__x)), second(std::forward<_U2>(__y)) { }


      template<typename _U1, typename _U2, typename
        enable_if<_PCCFP<_U1, _U2>::template
      _MoveConstructiblePair<_U1, _U2>()
     && _PCCFP<_U1, _U2>::template
      _ImplicitlyMoveConvertiblePair<_U1, _U2>(),
                         bool>::type=true>
 constexpr pair(pair<_U1, _U2>&& __p)
 : first(std::forward<_U1>(__p.first)),
   second(std::forward<_U2>(__p.second)) { }

      template<typename _U1, typename _U2, typename
        enable_if<_PCCFP<_U1, _U2>::template
      _MoveConstructiblePair<_U1, _U2>()
     && !_PCCFP<_U1, _U2>::template
      _ImplicitlyMoveConvertiblePair<_U1, _U2>(),
                         bool>::type=false>
 explicit constexpr pair(pair<_U1, _U2>&& __p)
 : first(std::forward<_U1>(__p.first)),
   second(std::forward<_U2>(__p.second)) { }

      template<typename... _Args1, typename... _Args2>
        pair(piecewise_construct_t, tuple<_Args1...>, tuple<_Args2...>);

      pair&
      operator=(typename conditional<
  __and_<is_copy_assignable<_T1>,
         is_copy_assignable<_T2>>::value,
  const pair&, const __nonesuch_no_braces&>::type __p)
      {
 first = __p.first;
 second = __p.second;
 return *this;
      }

      pair&
      operator=(typename conditional<
  __and_<is_move_assignable<_T1>,
         is_move_assignable<_T2>>::value,
  pair&&, __nonesuch_no_braces&&>::type __p)
      noexcept(__and_<is_nothrow_move_assignable<_T1>,
        is_nothrow_move_assignable<_T2>>::value)
      {
 first = std::forward<first_type>(__p.first);
 second = std::forward<second_type>(__p.second);
 return *this;
      }

      template<typename _U1, typename _U2>
      typename enable_if<__and_<is_assignable<_T1&, const _U1&>,
    is_assignable<_T2&, const _U2&>>::value,
    pair&>::type
 operator=(const pair<_U1, _U2>& __p)
 {
   first = __p.first;
   second = __p.second;
   return *this;
 }

      template<typename _U1, typename _U2>
      typename enable_if<__and_<is_assignable<_T1&, _U1&&>,
    is_assignable<_T2&, _U2&&>>::value,
    pair&>::type
 operator=(pair<_U1, _U2>&& __p)
 {
   first = std::forward<_U1>(__p.first);
   second = std::forward<_U2>(__p.second);
   return *this;
 }

      void
      swap(pair& __p)
      noexcept(__and_<__is_nothrow_swappable<_T1>,
                      __is_nothrow_swappable<_T2>>::value)
      {
 using std::swap;
 swap(first, __p.first);
 swap(second, __p.second);
      }

    private:
      template<typename... _Args1, std::size_t... _Indexes1,
               typename... _Args2, std::size_t... _Indexes2>
        pair(tuple<_Args1...>&, tuple<_Args2...>&,
             _Index_tuple<_Indexes1...>, _Index_tuple<_Indexes2...>);

    };






  template<typename _T1, typename _T2>
    inline constexpr bool
    operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __x.first == __y.first && __x.second == __y.second; }


  template<typename _T1, typename _T2>
    inline constexpr bool
    operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __x.first < __y.first
      || (!(__y.first < __x.first) && __x.second < __y.second); }


  template<typename _T1, typename _T2>
    inline constexpr bool
    operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return !(__x == __y); }


  template<typename _T1, typename _T2>
    inline constexpr bool
    operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __y < __x; }


  template<typename _T1, typename _T2>
    inline constexpr bool
    operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return !(__y < __x); }


  template<typename _T1, typename _T2>
    inline constexpr bool
    operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return !(__x < __y); }





  template<typename _T1, typename _T2>
    inline


    typename enable_if<__and_<__is_swappable<_T1>,
                              __is_swappable<_T2>>::value>::type



    swap(pair<_T1, _T2>& __x, pair<_T1, _T2>& __y)
    noexcept(noexcept(__x.swap(__y)))
    { __x.swap(__y); }


  template<typename _T1, typename _T2>
    typename enable_if<!__and_<__is_swappable<_T1>,
          __is_swappable<_T2>>::value>::type
    swap(pair<_T1, _T2>&, pair<_T1, _T2>&) = delete;
# 521 "/usr/include/c++/9.2.0/bits/stl_pair.h" 3
  template<typename _T1, typename _T2>
    constexpr pair<typename __decay_and_strip<_T1>::__type,
                   typename __decay_and_strip<_T2>::__type>
    make_pair(_T1&& __x, _T2&& __y)
    {
      typedef typename __decay_and_strip<_T1>::__type __ds_type1;
      typedef typename __decay_and_strip<_T2>::__type __ds_type2;
      typedef pair<__ds_type1, __ds_type2> __pair_type;
      return __pair_type(std::forward<_T1>(__x), std::forward<_T2>(__y));
    }
# 540 "/usr/include/c++/9.2.0/bits/stl_pair.h" 3

}
# 44 "/usr/include/c++/9.2.0/unordered_map" 2 3
# 1 "/usr/include/c++/9.2.0/bits/stl_function.h" 1 3
# 63 "/usr/include/c++/9.2.0/bits/stl_function.h" 3
namespace std __attribute__ ((__visibility__ ("default")))
{

# 104 "/usr/include/c++/9.2.0/bits/stl_function.h" 3
  template<typename _Arg, typename _Result>
    struct unary_function
    {

      typedef _Arg argument_type;


      typedef _Result result_type;
    };




  template<typename _Arg1, typename _Arg2, typename _Result>
    struct binary_function
    {

      typedef _Arg1 first_argument_type;


      typedef _Arg2 second_argument_type;


      typedef _Result result_type;
    };
# 144 "/usr/include/c++/9.2.0/bits/stl_function.h" 3
  struct __is_transparent;

  template<typename _Tp = void>
    struct plus;

  template<typename _Tp = void>
    struct minus;

  template<typename _Tp = void>
    struct multiplies;

  template<typename _Tp = void>
    struct divides;

  template<typename _Tp = void>
    struct modulus;

  template<typename _Tp = void>
    struct negate;



  template<typename _Tp>
    struct plus : public binary_function<_Tp, _Tp, _Tp>
    {
      constexpr
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x + __y; }
    };


  template<typename _Tp>
    struct minus : public binary_function<_Tp, _Tp, _Tp>
    {
      constexpr
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x - __y; }
    };


  template<typename _Tp>
    struct multiplies : public binary_function<_Tp, _Tp, _Tp>
    {
      constexpr
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x * __y; }
    };


  template<typename _Tp>
    struct divides : public binary_function<_Tp, _Tp, _Tp>
    {
      constexpr
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x / __y; }
    };


  template<typename _Tp>
    struct modulus : public binary_function<_Tp, _Tp, _Tp>
    {
      constexpr
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x % __y; }
    };


  template<typename _Tp>
    struct negate : public unary_function<_Tp, _Tp>
    {
      constexpr
      _Tp
      operator()(const _Tp& __x) const
      { return -__x; }
    };





  template<>
    struct plus<void>
    {
      template <typename _Tp, typename _Up>
 constexpr
 auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) + std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) + std::forward<_Up>(__u))
 { return std::forward<_Tp>(__t) + std::forward<_Up>(__u); }

      typedef __is_transparent is_transparent;
    };


  template<>
    struct minus<void>
    {
      template <typename _Tp, typename _Up>
 constexpr
 auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) - std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) - std::forward<_Up>(__u))
 { return std::forward<_Tp>(__t) - std::forward<_Up>(__u); }

      typedef __is_transparent is_transparent;
    };


  template<>
    struct multiplies<void>
    {
      template <typename _Tp, typename _Up>
 constexpr
 auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) * std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) * std::forward<_Up>(__u))
 { return std::forward<_Tp>(__t) * std::forward<_Up>(__u); }

      typedef __is_transparent is_transparent;
    };


  template<>
    struct divides<void>
    {
      template <typename _Tp, typename _Up>
 constexpr
 auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) / std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) / std::forward<_Up>(__u))
 { return std::forward<_Tp>(__t) / std::forward<_Up>(__u); }

      typedef __is_transparent is_transparent;
    };


  template<>
    struct modulus<void>
    {
      template <typename _Tp, typename _Up>
 constexpr
 auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) % std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) % std::forward<_Up>(__u))
 { return std::forward<_Tp>(__t) % std::forward<_Up>(__u); }

      typedef __is_transparent is_transparent;
    };


  template<>
    struct negate<void>
    {
      template <typename _Tp>
 constexpr
 auto
 operator()(_Tp&& __t) const
 noexcept(noexcept(-std::forward<_Tp>(__t)))
 -> decltype(-std::forward<_Tp>(__t))
 { return -std::forward<_Tp>(__t); }

      typedef __is_transparent is_transparent;
    };
# 330 "/usr/include/c++/9.2.0/bits/stl_function.h" 3
  template<typename _Tp = void>
    struct equal_to;

  template<typename _Tp = void>
    struct not_equal_to;

  template<typename _Tp = void>
    struct greater;

  template<typename _Tp = void>
    struct less;

  template<typename _Tp = void>
    struct greater_equal;

  template<typename _Tp = void>
    struct less_equal;



  template<typename _Tp>
    struct equal_to : public binary_function<_Tp, _Tp, bool>
    {
      constexpr
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x == __y; }
    };


  template<typename _Tp>
    struct not_equal_to : public binary_function<_Tp, _Tp, bool>
    {
      constexpr
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x != __y; }
    };


  template<typename _Tp>
    struct greater : public binary_function<_Tp, _Tp, bool>
    {
      constexpr
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x > __y; }
    };


  template<typename _Tp>
    struct less : public binary_function<_Tp, _Tp, bool>
    {
      constexpr
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x < __y; }
    };


  template<typename _Tp>
    struct greater_equal : public binary_function<_Tp, _Tp, bool>
    {
      constexpr
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x >= __y; }
    };


  template<typename _Tp>
    struct less_equal : public binary_function<_Tp, _Tp, bool>
    {
      constexpr
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x <= __y; }
    };


  template<typename _Tp>
    struct greater<_Tp*> : public binary_function<_Tp*, _Tp*, bool>
    {
      constexpr bool
      operator()(_Tp* __x, _Tp* __y) const noexcept
      {


 if (__builtin_is_constant_evaluated())



   return __x > __y;

 return (long unsigned int)__x > (long unsigned int)__y;
      }
    };


  template<typename _Tp>
    struct less<_Tp*> : public binary_function<_Tp*, _Tp*, bool>
    {
      constexpr bool
      operator()(_Tp* __x, _Tp* __y) const noexcept
      {


 if (__builtin_is_constant_evaluated())



   return __x < __y;

 return (long unsigned int)__x < (long unsigned int)__y;
      }
    };


  template<typename _Tp>
    struct greater_equal<_Tp*> : public binary_function<_Tp*, _Tp*, bool>
    {
      constexpr bool
      operator()(_Tp* __x, _Tp* __y) const noexcept
      {


 if (__builtin_is_constant_evaluated())



   return __x >= __y;

 return (long unsigned int)__x >= (long unsigned int)__y;
      }
    };


  template<typename _Tp>
    struct less_equal<_Tp*> : public binary_function<_Tp*, _Tp*, bool>
    {
      constexpr bool
      operator()(_Tp* __x, _Tp* __y) const noexcept
      {


 if (__builtin_is_constant_evaluated())



   return __x <= __y;

 return (long unsigned int)__x <= (long unsigned int)__y;
      }
    };



  template<>
    struct equal_to<void>
    {
      template <typename _Tp, typename _Up>
 constexpr auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) == std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) == std::forward<_Up>(__u))
 { return std::forward<_Tp>(__t) == std::forward<_Up>(__u); }

      typedef __is_transparent is_transparent;
    };


  template<>
    struct not_equal_to<void>
    {
      template <typename _Tp, typename _Up>
 constexpr auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) != std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) != std::forward<_Up>(__u))
 { return std::forward<_Tp>(__t) != std::forward<_Up>(__u); }

      typedef __is_transparent is_transparent;
    };


  template<>
    struct greater<void>
    {
      template <typename _Tp, typename _Up>
 constexpr auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) > std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) > std::forward<_Up>(__u))
 {
   return _S_cmp(std::forward<_Tp>(__t), std::forward<_Up>(__u),
   __ptr_cmp<_Tp, _Up>{});
 }

      template<typename _Tp, typename _Up>
 constexpr bool
 operator()(_Tp* __t, _Up* __u) const noexcept
 { return greater<common_type_t<_Tp*, _Up*>>{}(__t, __u); }

      typedef __is_transparent is_transparent;

    private:
      template <typename _Tp, typename _Up>
 static constexpr decltype(auto)
 _S_cmp(_Tp&& __t, _Up&& __u, false_type)
 { return std::forward<_Tp>(__t) > std::forward<_Up>(__u); }

      template <typename _Tp, typename _Up>
 static constexpr bool
 _S_cmp(_Tp&& __t, _Up&& __u, true_type) noexcept
 {
   return greater<const volatile void*>{}(
       static_cast<const volatile void*>(std::forward<_Tp>(__t)),
       static_cast<const volatile void*>(std::forward<_Up>(__u)));
 }


      template<typename _Tp, typename _Up, typename = void>
 struct __not_overloaded2 : true_type { };


      template<typename _Tp, typename _Up>
 struct __not_overloaded2<_Tp, _Up, __void_t<
   decltype(std::declval<_Tp>().operator>(std::declval<_Up>()))>>
 : false_type { };


      template<typename _Tp, typename _Up, typename = void>
 struct __not_overloaded : __not_overloaded2<_Tp, _Up> { };


      template<typename _Tp, typename _Up>
 struct __not_overloaded<_Tp, _Up, __void_t<
   decltype(operator>(std::declval<_Tp>(), std::declval<_Up>()))>>
 : false_type { };

      template<typename _Tp, typename _Up>
 using __ptr_cmp = __and_<__not_overloaded<_Tp, _Up>,
       is_convertible<_Tp, const volatile void*>,
       is_convertible<_Up, const volatile void*>>;
    };


  template<>
    struct less<void>
    {
      template <typename _Tp, typename _Up>
 constexpr auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) < std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) < std::forward<_Up>(__u))
 {
   return _S_cmp(std::forward<_Tp>(__t), std::forward<_Up>(__u),
   __ptr_cmp<_Tp, _Up>{});
 }

      template<typename _Tp, typename _Up>
 constexpr bool
 operator()(_Tp* __t, _Up* __u) const noexcept
 { return less<common_type_t<_Tp*, _Up*>>{}(__t, __u); }

      typedef __is_transparent is_transparent;

    private:
      template <typename _Tp, typename _Up>
 static constexpr decltype(auto)
 _S_cmp(_Tp&& __t, _Up&& __u, false_type)
 { return std::forward<_Tp>(__t) < std::forward<_Up>(__u); }

      template <typename _Tp, typename _Up>
 static constexpr bool
 _S_cmp(_Tp&& __t, _Up&& __u, true_type) noexcept
 {
   return less<const volatile void*>{}(
       static_cast<const volatile void*>(std::forward<_Tp>(__t)),
       static_cast<const volatile void*>(std::forward<_Up>(__u)));
 }


      template<typename _Tp, typename _Up, typename = void>
 struct __not_overloaded2 : true_type { };


      template<typename _Tp, typename _Up>
 struct __not_overloaded2<_Tp, _Up, __void_t<
   decltype(std::declval<_Tp>().operator<(std::declval<_Up>()))>>
 : false_type { };


      template<typename _Tp, typename _Up, typename = void>
 struct __not_overloaded : __not_overloaded2<_Tp, _Up> { };


      template<typename _Tp, typename _Up>
 struct __not_overloaded<_Tp, _Up, __void_t<
   decltype(operator<(std::declval<_Tp>(), std::declval<_Up>()))>>
 : false_type { };

      template<typename _Tp, typename _Up>
 using __ptr_cmp = __and_<__not_overloaded<_Tp, _Up>,
       is_convertible<_Tp, const volatile void*>,
       is_convertible<_Up, const volatile void*>>;
    };


  template<>
    struct greater_equal<void>
    {
      template <typename _Tp, typename _Up>
 constexpr auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) >= std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) >= std::forward<_Up>(__u))
 {
   return _S_cmp(std::forward<_Tp>(__t), std::forward<_Up>(__u),
   __ptr_cmp<_Tp, _Up>{});
 }

      template<typename _Tp, typename _Up>
 constexpr bool
 operator()(_Tp* __t, _Up* __u) const noexcept
 { return greater_equal<common_type_t<_Tp*, _Up*>>{}(__t, __u); }

      typedef __is_transparent is_transparent;

    private:
      template <typename _Tp, typename _Up>
 static constexpr decltype(auto)
 _S_cmp(_Tp&& __t, _Up&& __u, false_type)
 { return std::forward<_Tp>(__t) >= std::forward<_Up>(__u); }

      template <typename _Tp, typename _Up>
 static constexpr bool
 _S_cmp(_Tp&& __t, _Up&& __u, true_type) noexcept
 {
   return greater_equal<const volatile void*>{}(
       static_cast<const volatile void*>(std::forward<_Tp>(__t)),
       static_cast<const volatile void*>(std::forward<_Up>(__u)));
 }


      template<typename _Tp, typename _Up, typename = void>
 struct __not_overloaded2 : true_type { };


      template<typename _Tp, typename _Up>
 struct __not_overloaded2<_Tp, _Up, __void_t<
   decltype(std::declval<_Tp>().operator>=(std::declval<_Up>()))>>
 : false_type { };


      template<typename _Tp, typename _Up, typename = void>
 struct __not_overloaded : __not_overloaded2<_Tp, _Up> { };


      template<typename _Tp, typename _Up>
 struct __not_overloaded<_Tp, _Up, __void_t<
   decltype(operator>=(std::declval<_Tp>(), std::declval<_Up>()))>>
 : false_type { };

      template<typename _Tp, typename _Up>
 using __ptr_cmp = __and_<__not_overloaded<_Tp, _Up>,
       is_convertible<_Tp, const volatile void*>,
       is_convertible<_Up, const volatile void*>>;
    };


  template<>
    struct less_equal<void>
    {
      template <typename _Tp, typename _Up>
 constexpr auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) <= std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) <= std::forward<_Up>(__u))
 {
   return _S_cmp(std::forward<_Tp>(__t), std::forward<_Up>(__u),
   __ptr_cmp<_Tp, _Up>{});
 }

      template<typename _Tp, typename _Up>
 constexpr bool
 operator()(_Tp* __t, _Up* __u) const noexcept
 { return less_equal<common_type_t<_Tp*, _Up*>>{}(__t, __u); }

      typedef __is_transparent is_transparent;

    private:
      template <typename _Tp, typename _Up>
 static constexpr decltype(auto)
 _S_cmp(_Tp&& __t, _Up&& __u, false_type)
 { return std::forward<_Tp>(__t) <= std::forward<_Up>(__u); }

      template <typename _Tp, typename _Up>
 static constexpr bool
 _S_cmp(_Tp&& __t, _Up&& __u, true_type) noexcept
 {
   return less_equal<const volatile void*>{}(
       static_cast<const volatile void*>(std::forward<_Tp>(__t)),
       static_cast<const volatile void*>(std::forward<_Up>(__u)));
 }


      template<typename _Tp, typename _Up, typename = void>
 struct __not_overloaded2 : true_type { };


      template<typename _Tp, typename _Up>
 struct __not_overloaded2<_Tp, _Up, __void_t<
   decltype(std::declval<_Tp>().operator<=(std::declval<_Up>()))>>
 : false_type { };


      template<typename _Tp, typename _Up, typename = void>
 struct __not_overloaded : __not_overloaded2<_Tp, _Up> { };


      template<typename _Tp, typename _Up>
 struct __not_overloaded<_Tp, _Up, __void_t<
   decltype(operator<=(std::declval<_Tp>(), std::declval<_Up>()))>>
 : false_type { };

      template<typename _Tp, typename _Up>
 using __ptr_cmp = __and_<__not_overloaded<_Tp, _Up>,
       is_convertible<_Tp, const volatile void*>,
       is_convertible<_Up, const volatile void*>>;
    };
# 774 "/usr/include/c++/9.2.0/bits/stl_function.h" 3
  template<typename _Tp = void>
    struct logical_and;

  template<typename _Tp = void>
    struct logical_or;

  template<typename _Tp = void>
    struct logical_not;



  template<typename _Tp>
    struct logical_and : public binary_function<_Tp, _Tp, bool>
    {
      constexpr
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x && __y; }
    };


  template<typename _Tp>
    struct logical_or : public binary_function<_Tp, _Tp, bool>
    {
      constexpr
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x || __y; }
    };


  template<typename _Tp>
    struct logical_not : public unary_function<_Tp, bool>
    {
      constexpr
      bool
      operator()(const _Tp& __x) const
      { return !__x; }
    };



  template<>
    struct logical_and<void>
    {
      template <typename _Tp, typename _Up>
 constexpr
 auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) && std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) && std::forward<_Up>(__u))
 { return std::forward<_Tp>(__t) && std::forward<_Up>(__u); }

      typedef __is_transparent is_transparent;
    };


  template<>
    struct logical_or<void>
    {
      template <typename _Tp, typename _Up>
 constexpr
 auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) || std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) || std::forward<_Up>(__u))
 { return std::forward<_Tp>(__t) || std::forward<_Up>(__u); }

      typedef __is_transparent is_transparent;
    };


  template<>
    struct logical_not<void>
    {
      template <typename _Tp>
 constexpr
 auto
 operator()(_Tp&& __t) const
 noexcept(noexcept(!std::forward<_Tp>(__t)))
 -> decltype(!std::forward<_Tp>(__t))
 { return !std::forward<_Tp>(__t); }

      typedef __is_transparent is_transparent;
    };




  template<typename _Tp = void>
    struct bit_and;

  template<typename _Tp = void>
    struct bit_or;

  template<typename _Tp = void>
    struct bit_xor;

  template<typename _Tp = void>
    struct bit_not;




  template<typename _Tp>
    struct bit_and : public binary_function<_Tp, _Tp, _Tp>
    {
      constexpr
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x & __y; }
    };

  template<typename _Tp>
    struct bit_or : public binary_function<_Tp, _Tp, _Tp>
    {
      constexpr
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x | __y; }
    };

  template<typename _Tp>
    struct bit_xor : public binary_function<_Tp, _Tp, _Tp>
    {
      constexpr
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x ^ __y; }
    };

  template<typename _Tp>
    struct bit_not : public unary_function<_Tp, _Tp>
    {
    constexpr
      _Tp
      operator()(const _Tp& __x) const
      { return ~__x; }
    };


  template <>
    struct bit_and<void>
    {
      template <typename _Tp, typename _Up>
 constexpr
 auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) & std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) & std::forward<_Up>(__u))
 { return std::forward<_Tp>(__t) & std::forward<_Up>(__u); }

      typedef __is_transparent is_transparent;
    };

  template <>
    struct bit_or<void>
    {
      template <typename _Tp, typename _Up>
 constexpr
 auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) | std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) | std::forward<_Up>(__u))
 { return std::forward<_Tp>(__t) | std::forward<_Up>(__u); }

      typedef __is_transparent is_transparent;
    };

  template <>
    struct bit_xor<void>
    {
      template <typename _Tp, typename _Up>
 constexpr
 auto
 operator()(_Tp&& __t, _Up&& __u) const
 noexcept(noexcept(std::forward<_Tp>(__t) ^ std::forward<_Up>(__u)))
 -> decltype(std::forward<_Tp>(__t) ^ std::forward<_Up>(__u))
 { return std::forward<_Tp>(__t) ^ std::forward<_Up>(__u); }

      typedef __is_transparent is_transparent;
    };

  template <>
    struct bit_not<void>
    {
      template <typename _Tp>
 constexpr
 auto
 operator()(_Tp&& __t) const
 noexcept(noexcept(~std::forward<_Tp>(__t)))
 -> decltype(~std::forward<_Tp>(__t))
 { return ~std::forward<_Tp>(__t); }

      typedef __is_transparent is_transparent;
    };
# 1002 "/usr/include/c++/9.2.0/bits/stl_function.h" 3
  template<typename _Predicate>
    class unary_negate
    : public unary_function<typename _Predicate::argument_type, bool>
    {
    protected:
      _Predicate _M_pred;

    public:
      constexpr
      explicit
      unary_negate(const _Predicate& __x) : _M_pred(__x) { }

      constexpr
      bool
      operator()(const typename _Predicate::argument_type& __x) const
      { return !_M_pred(__x); }
    };


  template<typename _Predicate>
    constexpr
    inline unary_negate<_Predicate>
    not1(const _Predicate& __pred)
    { return unary_negate<_Predicate>(__pred); }


  template<typename _Predicate>
    class binary_negate
    : public binary_function<typename _Predicate::first_argument_type,
        typename _Predicate::second_argument_type, bool>
    {
    protected:
      _Predicate _M_pred;

    public:
      constexpr
      explicit
      binary_negate(const _Predicate& __x) : _M_pred(__x) { }

      constexpr
      bool
      operator()(const typename _Predicate::first_argument_type& __x,
   const typename _Predicate::second_argument_type& __y) const
      { return !_M_pred(__x, __y); }
    };


  template<typename _Predicate>
    constexpr
    inline binary_negate<_Predicate>
    not2(const _Predicate& __pred)
    { return binary_negate<_Predicate>(__pred); }
# 1079 "/usr/include/c++/9.2.0/bits/stl_function.h" 3
  template<typename _Arg, typename _Result>
    class pointer_to_unary_function : public unary_function<_Arg, _Result>
    {
    protected:
      _Result (*_M_ptr)(_Arg);

    public:
      pointer_to_unary_function() { }

      explicit
      pointer_to_unary_function(_Result (*__x)(_Arg))
      : _M_ptr(__x) { }

      _Result
      operator()(_Arg __x) const
      { return _M_ptr(__x); }
    };


  template<typename _Arg, typename _Result>
    inline pointer_to_unary_function<_Arg, _Result>
    ptr_fun(_Result (*__x)(_Arg))
    { return pointer_to_unary_function<_Arg, _Result>(__x); }


  template<typename _Arg1, typename _Arg2, typename _Result>
    class pointer_to_binary_function
    : public binary_function<_Arg1, _Arg2, _Result>
    {
    protected:
      _Result (*_M_ptr)(_Arg1, _Arg2);

    public:
      pointer_to_binary_function() { }

      explicit
      pointer_to_binary_function(_Result (*__x)(_Arg1, _Arg2))
      : _M_ptr(__x) { }

      _Result
      operator()(_Arg1 __x, _Arg2 __y) const
      { return _M_ptr(__x, __y); }
    };


  template<typename _Arg1, typename _Arg2, typename _Result>
    inline pointer_to_binary_function<_Arg1, _Arg2, _Result>
    ptr_fun(_Result (*__x)(_Arg1, _Arg2))
    { return pointer_to_binary_function<_Arg1, _Arg2, _Result>(__x); }


  template<typename _Tp>
    struct _Identity
    : public unary_function<_Tp, _Tp>
    {
      _Tp&
      operator()(_Tp& __x) const
      { return __x; }

      const _Tp&
      operator()(const _Tp& __x) const
      { return __x; }
    };


  template<typename _Tp> struct _Identity<const _Tp> : _Identity<_Tp> { };

  template<typename _Pair>
    struct _Select1st
    : public unary_function<_Pair, typename _Pair::first_type>
    {
      typename _Pair::first_type&
      operator()(_Pair& __x) const
      { return __x.first; }

      const typename _Pair::first_type&
      operator()(const _Pair& __x) const
      { return __x.first; }


      template<typename _Pair2>
        typename _Pair2::first_type&
        operator()(_Pair2& __x) const
        { return __x.first; }

      template<typename _Pair2>
        const typename _Pair2::first_type&
        operator()(const _Pair2& __x) const
        { return __x.first; }

    };

  template<typename _Pair>
    struct _Select2nd
    : public unary_function<_Pair, typename _Pair::second_type>
    {
      typename _Pair::second_type&
      operator()(_Pair& __x) const
      { return __x.second; }

      const typename _Pair::second_type&
      operator()(const _Pair& __x) const
      { return __x.second; }
    };
# 1202 "/usr/include/c++/9.2.0/bits/stl_function.h" 3
  template<typename _Ret, typename _Tp>
    class mem_fun_t : public unary_function<_Tp*, _Ret>
    {
    public:
      explicit
      mem_fun_t(_Ret (_Tp::*__pf)())
      : _M_f(__pf) { }

      _Ret
      operator()(_Tp* __p) const
      { return (__p->*_M_f)(); }

    private:
      _Ret (_Tp::*_M_f)();
    };



  template<typename _Ret, typename _Tp>
    class const_mem_fun_t : public unary_function<const _Tp*, _Ret>
    {
    public:
      explicit
      const_mem_fun_t(_Ret (_Tp::*__pf)() const)
      : _M_f(__pf) { }

      _Ret
      operator()(const _Tp* __p) const
      { return (__p->*_M_f)(); }

    private:
      _Ret (_Tp::*_M_f)() const;
    };



  template<typename _Ret, typename _Tp>
    class mem_fun_ref_t : public unary_function<_Tp, _Ret>
    {
    public:
      explicit
      mem_fun_ref_t(_Ret (_Tp::*__pf)())
      : _M_f(__pf) { }

      _Ret
      operator()(_Tp& __r) const
      { return (__r.*_M_f)(); }

    private:
      _Ret (_Tp::*_M_f)();
  };



  template<typename _Ret, typename _Tp>
    class const_mem_fun_ref_t : public unary_function<_Tp, _Ret>
    {
    public:
      explicit
      const_mem_fun_ref_t(_Ret (_Tp::*__pf)() const)
      : _M_f(__pf) { }

      _Ret
      operator()(const _Tp& __r) const
      { return (__r.*_M_f)(); }

    private:
      _Ret (_Tp::*_M_f)() const;
    };



  template<typename _Ret, typename _Tp, typename _Arg>
    class mem_fun1_t : public binary_function<_Tp*, _Arg, _Ret>
    {
    public:
      explicit
      mem_fun1_t(_Ret (_Tp::*__pf)(_Arg))
      : _M_f(__pf) { }

      _Ret
      operator()(_Tp* __p, _Arg __x) const
      { return (__p->*_M_f)(__x); }

    private:
      _Ret (_Tp::*_M_f)(_Arg);
    };



  template<typename _Ret, typename _Tp, typename _Arg>
    class const_mem_fun1_t : public binary_function<const _Tp*, _Arg, _Ret>
    {
    public:
      explicit
      const_mem_fun1_t(_Ret (_Tp::*__pf)(_Arg) const)
      : _M_f(__pf) { }

      _Ret
      operator()(const _Tp* __p, _Arg __x) const
      { return (__p->*_M_f)(__x); }

    private:
      _Ret (_Tp::*_M_f)(_Arg) const;
    };



  template<typename _Ret, typename _Tp, typename _Arg>
    class mem_fun1_ref_t : public binary_function<_Tp, _Arg, _Ret>
    {
    public:
      explicit
      mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg))
      : _M_f(__pf) { }

      _Ret
      operator()(_Tp& __r, _Arg __x) const
      { return (__r.*_M_f)(__x); }

    private:
      _Ret (_Tp::*_M_f)(_Arg);
    };



  template<typename _Ret, typename _Tp, typename _Arg>
    class const_mem_fun1_ref_t : public binary_function<_Tp, _Arg, _Ret>
    {
    public:
      explicit
      const_mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg) const)
      : _M_f(__pf) { }

      _Ret
      operator()(const _Tp& __r, _Arg __x) const
      { return (__r.*_M_f)(__x); }

    private:
      _Ret (_Tp::*_M_f)(_Arg) const;
    };



  template<typename _Ret, typename _Tp>
    inline mem_fun_t<_Ret, _Tp>
    mem_fun(_Ret (_Tp::*__f)())
    { return mem_fun_t<_Ret, _Tp>(__f); }

  template<typename _Ret, typename _Tp>
    inline const_mem_fun_t<_Ret, _Tp>
    mem_fun(_Ret (_Tp::*__f)() const)
    { return const_mem_fun_t<_Ret, _Tp>(__f); }

  template<typename _Ret, typename _Tp>
    inline mem_fun_ref_t<_Ret, _Tp>
    mem_fun_ref(_Ret (_Tp::*__f)())
    { return mem_fun_ref_t<_Ret, _Tp>(__f); }

  template<typename _Ret, typename _Tp>
    inline const_mem_fun_ref_t<_Ret, _Tp>
    mem_fun_ref(_Ret (_Tp::*__f)() const)
    { return const_mem_fun_ref_t<_Ret, _Tp>(__f); }

  template<typename _Ret, typename _Tp, typename _Arg>
    inline mem_fun1_t<_Ret, _Tp, _Arg>
    mem_fun(_Ret (_Tp::*__f)(_Arg))
    { return mem_fun1_t<_Ret, _Tp, _Arg>(__f); }

  template<typename _Ret, typename _Tp, typename _Arg>
    inline const_mem_fun1_t<_Ret, _Tp, _Arg>
    mem_fun(_Ret (_Tp::*__f)(_Arg) const)
    { return const_mem_fun1_t<_Ret, _Tp, _Arg>(__f); }

  template<typename _Ret, typename _Tp, typename _Arg>
    inline mem_fun1_ref_t<_Ret, _Tp, _Arg>
    mem_fun_ref(_Ret (_Tp::*__f)(_Arg))
    { return mem_fun1_ref_t<_Ret, _Tp, _Arg>(__f); }

  template<typename _Ret, typename _Tp, typename _Arg>
    inline const_mem_fun1_ref_t<_Ret, _Tp, _Arg>
    mem_fun_ref(_Ret (_Tp::*__f)(_Arg) const)
    { return const_mem_fun1_ref_t<_Ret, _Tp, _Arg>(__f); }




}


# 1 "/usr/include/c++/9.2.0/backward/binders.h" 1 3
# 60 "/usr/include/c++/9.2.0/backward/binders.h" 3
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

namespace std __attribute__ ((__visibility__ ("default")))
{

# 107 "/usr/include/c++/9.2.0/backward/binders.h" 3
  template<typename _Operation>
    class binder1st
    : public unary_function<typename _Operation::second_argument_type,
       typename _Operation::result_type>
    {
    protected:
      _Operation op;
      typename _Operation::first_argument_type value;

    public:
      binder1st(const _Operation& __x,
  const typename _Operation::first_argument_type& __y)
      : op(__x), value(__y) { }

      typename _Operation::result_type
      operator()(const typename _Operation::second_argument_type& __x) const
      { return op(value, __x); }



      typename _Operation::result_type
      operator()(typename _Operation::second_argument_type& __x) const
      { return op(value, __x); }
    } __attribute__ ((__deprecated__));


  template<typename _Operation, typename _Tp>
    inline binder1st<_Operation>
    bind1st(const _Operation& __fn, const _Tp& __x)
    {
      typedef typename _Operation::first_argument_type _Arg1_type;
      return binder1st<_Operation>(__fn, _Arg1_type(__x));
    }


  template<typename _Operation>
    class binder2nd
    : public unary_function<typename _Operation::first_argument_type,
       typename _Operation::result_type>
    {
    protected:
      _Operation op;
      typename _Operation::second_argument_type value;

    public:
      binder2nd(const _Operation& __x,
  const typename _Operation::second_argument_type& __y)
      : op(__x), value(__y) { }

      typename _Operation::result_type
      operator()(const typename _Operation::first_argument_type& __x) const
      { return op(__x, value); }



      typename _Operation::result_type
      operator()(typename _Operation::first_argument_type& __x) const
      { return op(__x, value); }
    } __attribute__ ((__deprecated__));


  template<typename _Operation, typename _Tp>
    inline binder2nd<_Operation>
    bind2nd(const _Operation& __fn, const _Tp& __x)
    {
      typedef typename _Operation::second_argument_type _Arg2_type;
      return binder2nd<_Operation>(__fn, _Arg2_type(__x));
    }



}

#pragma GCC diagnostic pop
# 1393 "/usr/include/c++/9.2.0/bits/stl_function.h" 2 3
# 45 "/usr/include/c++/9.2.0/unordered_map" 2 3
# 1 "/usr/include/c++/9.2.0/bits/functional_hash.h" 1 3
# 33 "/usr/include/c++/9.2.0/bits/functional_hash.h" 3
       
# 34 "/usr/include/c++/9.2.0/bits/functional_hash.h" 3



namespace std __attribute__ ((__visibility__ ("default")))
{

# 49 "/usr/include/c++/9.2.0/bits/functional_hash.h" 3
  template<typename _Result, typename _Arg>
    struct __hash_base
    {
      typedef _Result result_type ;
      typedef _Arg argument_type ;
    };


  template<typename _Tp>
    struct hash;

  template<typename _Tp, typename = void>
    struct __poison_hash
    {
      static constexpr bool __enable_hash_call = false;
    private:

      __poison_hash(__poison_hash&&);
      ~__poison_hash();
    };

  template<typename _Tp>
    struct __poison_hash<_Tp, __void_t<decltype(hash<_Tp>()(declval<_Tp>()))>>
    {
      static constexpr bool __enable_hash_call = true;
    };


  template<typename _Tp, bool = is_enum<_Tp>::value>
    struct __hash_enum
    {
    private:

      __hash_enum(__hash_enum&&);
      ~__hash_enum();
    };


  template<typename _Tp>
    struct __hash_enum<_Tp, true> : public __hash_base<size_t, _Tp>
    {
      size_t
      operator()(_Tp __val) const noexcept
      {
       using __type = typename underlying_type<_Tp>::type;
       return hash<__type>{}(static_cast<__type>(__val));
      }
    };



  template<typename _Tp>
    struct hash : __hash_enum<_Tp>
    { };


  template<typename _Tp>
    struct hash<_Tp*> : public __hash_base<size_t, _Tp*>
    {
      size_t
      operator()(_Tp* __p) const noexcept
      { return reinterpret_cast<size_t>(__p); }
    };
# 124 "/usr/include/c++/9.2.0/bits/functional_hash.h" 3
  template<> struct hash<bool> : public __hash_base<size_t, bool> { size_t operator()(bool __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<char> : public __hash_base<size_t, char> { size_t operator()(char __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<signed char> : public __hash_base<size_t, signed char> { size_t operator()(signed char __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<unsigned char> : public __hash_base<size_t, unsigned char> { size_t operator()(unsigned char __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<wchar_t> : public __hash_base<size_t, wchar_t> { size_t operator()(wchar_t __val) const noexcept { return static_cast<size_t>(__val); } };







  template<> struct hash<char16_t> : public __hash_base<size_t, char16_t> { size_t operator()(char16_t __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<char32_t> : public __hash_base<size_t, char32_t> { size_t operator()(char32_t __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<short> : public __hash_base<size_t, short> { size_t operator()(short __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<int> : public __hash_base<size_t, int> { size_t operator()(int __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<long> : public __hash_base<size_t, long> { size_t operator()(long __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<long long> : public __hash_base<size_t, long long> { size_t operator()(long long __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<unsigned short> : public __hash_base<size_t, unsigned short> { size_t operator()(unsigned short __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<unsigned int> : public __hash_base<size_t, unsigned int> { size_t operator()(unsigned int __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<unsigned long> : public __hash_base<size_t, unsigned long> { size_t operator()(unsigned long __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<unsigned long long> : public __hash_base<size_t, unsigned long long> { size_t operator()(unsigned long long __val) const noexcept { return static_cast<size_t>(__val); } };


  template<> struct hash<__int128> : public __hash_base<size_t, __int128> { size_t operator()(__int128 __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<__int128 unsigned> : public __hash_base<size_t, __int128 unsigned> { size_t operator()(__int128 unsigned __val) const noexcept { return static_cast<size_t>(__val); } };
# 192 "/usr/include/c++/9.2.0/bits/functional_hash.h" 3
  struct _Hash_impl
  {
    static size_t
    hash(const void* __ptr, size_t __clength,
  size_t __seed = static_cast<size_t>(0xc70f6907UL))
    { return _Hash_bytes(__ptr, __clength, __seed); }

    template<typename _Tp>
      static size_t
      hash(const _Tp& __val)
      { return hash(&__val, sizeof(__val)); }

    template<typename _Tp>
      static size_t
      __hash_combine(const _Tp& __val, size_t __hash)
      { return hash(&__val, sizeof(__val), __hash); }
  };


  struct _Fnv_hash_impl
  {
    static size_t
    hash(const void* __ptr, size_t __clength,
  size_t __seed = static_cast<size_t>(2166136261UL))
    { return _Fnv_hash_bytes(__ptr, __clength, __seed); }

    template<typename _Tp>
      static size_t
      hash(const _Tp& __val)
      { return hash(&__val, sizeof(__val)); }

    template<typename _Tp>
      static size_t
      __hash_combine(const _Tp& __val, size_t __hash)
      { return hash(&__val, sizeof(__val), __hash); }
  };


  template<>
    struct hash<float> : public __hash_base<size_t, float>
    {
      size_t
      operator()(float __val) const noexcept
      {

 return __val != 0.0f ? std::_Hash_impl::hash(__val) : 0;
      }
    };


  template<>
    struct hash<double> : public __hash_base<size_t, double>
    {
      size_t
      operator()(double __val) const noexcept
      {

 return __val != 0.0 ? std::_Hash_impl::hash(__val) : 0;
      }
    };


  template<>
    struct hash<long double>
    : public __hash_base<size_t, long double>
    {
      __attribute__ ((__pure__)) size_t
      operator()(long double __val) const noexcept;
    };
# 278 "/usr/include/c++/9.2.0/bits/functional_hash.h" 3
  template<typename _Hash>
    struct __is_fast_hash : public std::true_type
    { };

  template<>
    struct __is_fast_hash<hash<long double>> : public std::false_type
    { };


}
# 46 "/usr/include/c++/9.2.0/unordered_map" 2 3
# 1 "/usr/include/c++/9.2.0/bits/hashtable.h" 1 3
# 33 "/usr/include/c++/9.2.0/bits/hashtable.h" 3
       
# 34 "/usr/include/c++/9.2.0/bits/hashtable.h" 3

# 1 "/usr/include/c++/9.2.0/bits/hashtable_policy.h" 1 3
# 34 "/usr/include/c++/9.2.0/bits/hashtable_policy.h" 3
# 1 "/usr/include/c++/9.2.0/tuple" 1 3
# 32 "/usr/include/c++/9.2.0/tuple" 3
       
# 33 "/usr/include/c++/9.2.0/tuple" 3





# 1 "/usr/include/c++/9.2.0/utility" 1 3
# 58 "/usr/include/c++/9.2.0/utility" 3
       
# 59 "/usr/include/c++/9.2.0/utility" 3
# 69 "/usr/include/c++/9.2.0/utility" 3
# 1 "/usr/include/c++/9.2.0/bits/stl_relops.h" 1 3
# 67 "/usr/include/c++/9.2.0/bits/stl_relops.h" 3
namespace std __attribute__ ((__visibility__ ("default")))
{


  namespace rel_ops
  {
# 85 "/usr/include/c++/9.2.0/bits/stl_relops.h" 3
    template <class _Tp>
      inline bool
      operator!=(const _Tp& __x, const _Tp& __y)
      { return !(__x == __y); }
# 98 "/usr/include/c++/9.2.0/bits/stl_relops.h" 3
    template <class _Tp>
      inline bool
      operator>(const _Tp& __x, const _Tp& __y)
      { return __y < __x; }
# 111 "/usr/include/c++/9.2.0/bits/stl_relops.h" 3
    template <class _Tp>
      inline bool
      operator<=(const _Tp& __x, const _Tp& __y)
      { return !(__y < __x); }
# 124 "/usr/include/c++/9.2.0/bits/stl_relops.h" 3
    template <class _Tp>
      inline bool
      operator>=(const _Tp& __x, const _Tp& __y)
      { return !(__x < __y); }
  }


}
# 70 "/usr/include/c++/9.2.0/utility" 2 3
# 78 "/usr/include/c++/9.2.0/utility" 3
namespace std __attribute__ ((__visibility__ ("default")))
{



  template<typename _Tp>
    struct tuple_size;





  template<typename _Tp,
    typename _Up = typename remove_cv<_Tp>::type,
    typename = typename enable_if<is_same<_Tp, _Up>::value>::type,
    size_t = tuple_size<_Tp>::value>
    using __enable_if_has_tuple_size = _Tp;

  template<typename _Tp>
    struct tuple_size<const __enable_if_has_tuple_size<_Tp>>
    : public tuple_size<_Tp> { };

  template<typename _Tp>
    struct tuple_size<volatile __enable_if_has_tuple_size<_Tp>>
    : public tuple_size<_Tp> { };

  template<typename _Tp>
    struct tuple_size<const volatile __enable_if_has_tuple_size<_Tp>>
    : public tuple_size<_Tp> { };


  template<std::size_t __i, typename _Tp>
    struct tuple_element;


  template<std::size_t __i, typename _Tp>
    using __tuple_element_t = typename tuple_element<__i, _Tp>::type;

  template<std::size_t __i, typename _Tp>
    struct tuple_element<__i, const _Tp>
    {
      typedef typename add_const<__tuple_element_t<__i, _Tp>>::type type;
    };

  template<std::size_t __i, typename _Tp>
    struct tuple_element<__i, volatile _Tp>
    {
      typedef typename add_volatile<__tuple_element_t<__i, _Tp>>::type type;
    };

  template<std::size_t __i, typename _Tp>
    struct tuple_element<__i, const volatile _Tp>
    {
      typedef typename add_cv<__tuple_element_t<__i, _Tp>>::type type;
    };







  template<std::size_t __i, typename _Tp>
    using tuple_element_t = typename tuple_element<__i, _Tp>::type;





  template<typename _T1, typename _T2>
    struct __is_tuple_like_impl<std::pair<_T1, _T2>> : true_type
    { };


  template<class _Tp1, class _Tp2>
    struct tuple_size<std::pair<_Tp1, _Tp2>>
    : public integral_constant<std::size_t, 2> { };


  template<class _Tp1, class _Tp2>
    struct tuple_element<0, std::pair<_Tp1, _Tp2>>
    { typedef _Tp1 type; };


  template<class _Tp1, class _Tp2>
    struct tuple_element<1, std::pair<_Tp1, _Tp2>>
    { typedef _Tp2 type; };

  template<std::size_t _Int>
    struct __pair_get;

  template<>
    struct __pair_get<0>
    {
      template<typename _Tp1, typename _Tp2>
        static constexpr _Tp1&
        __get(std::pair<_Tp1, _Tp2>& __pair) noexcept
        { return __pair.first; }

      template<typename _Tp1, typename _Tp2>
        static constexpr _Tp1&&
        __move_get(std::pair<_Tp1, _Tp2>&& __pair) noexcept
        { return std::forward<_Tp1>(__pair.first); }

      template<typename _Tp1, typename _Tp2>
        static constexpr const _Tp1&
        __const_get(const std::pair<_Tp1, _Tp2>& __pair) noexcept
        { return __pair.first; }

      template<typename _Tp1, typename _Tp2>
        static constexpr const _Tp1&&
        __const_move_get(const std::pair<_Tp1, _Tp2>&& __pair) noexcept
        { return std::forward<const _Tp1>(__pair.first); }
    };

  template<>
    struct __pair_get<1>
    {
      template<typename _Tp1, typename _Tp2>
        static constexpr _Tp2&
        __get(std::pair<_Tp1, _Tp2>& __pair) noexcept
        { return __pair.second; }

      template<typename _Tp1, typename _Tp2>
        static constexpr _Tp2&&
        __move_get(std::pair<_Tp1, _Tp2>&& __pair) noexcept
        { return std::forward<_Tp2>(__pair.second); }

      template<typename _Tp1, typename _Tp2>
        static constexpr const _Tp2&
        __const_get(const std::pair<_Tp1, _Tp2>& __pair) noexcept
        { return __pair.second; }

      template<typename _Tp1, typename _Tp2>
        static constexpr const _Tp2&&
        __const_move_get(const std::pair<_Tp1, _Tp2>&& __pair) noexcept
        { return std::forward<const _Tp2>(__pair.second); }
    };

  template<std::size_t _Int, class _Tp1, class _Tp2>
    constexpr typename tuple_element<_Int, std::pair<_Tp1, _Tp2>>::type&
    get(std::pair<_Tp1, _Tp2>& __in) noexcept
    { return __pair_get<_Int>::__get(__in); }

  template<std::size_t _Int, class _Tp1, class _Tp2>
    constexpr typename tuple_element<_Int, std::pair<_Tp1, _Tp2>>::type&&
    get(std::pair<_Tp1, _Tp2>&& __in) noexcept
    { return __pair_get<_Int>::__move_get(std::move(__in)); }

  template<std::size_t _Int, class _Tp1, class _Tp2>
    constexpr const typename tuple_element<_Int, std::pair<_Tp1, _Tp2>>::type&
    get(const std::pair<_Tp1, _Tp2>& __in) noexcept
    { return __pair_get<_Int>::__const_get(__in); }

  template<std::size_t _Int, class _Tp1, class _Tp2>
    constexpr const typename tuple_element<_Int, std::pair<_Tp1, _Tp2>>::type&&
    get(const std::pair<_Tp1, _Tp2>&& __in) noexcept
    { return __pair_get<_Int>::__const_move_get(std::move(__in)); }





  template <typename _Tp, typename _Up>
    constexpr _Tp&
    get(pair<_Tp, _Up>& __p) noexcept
    { return __p.first; }

  template <typename _Tp, typename _Up>
    constexpr const _Tp&
    get(const pair<_Tp, _Up>& __p) noexcept
    { return __p.first; }

  template <typename _Tp, typename _Up>
    constexpr _Tp&&
    get(pair<_Tp, _Up>&& __p) noexcept
    { return std::move(__p.first); }

  template <typename _Tp, typename _Up>
    constexpr const _Tp&&
    get(const pair<_Tp, _Up>&& __p) noexcept
    { return std::move(__p.first); }

  template <typename _Tp, typename _Up>
    constexpr _Tp&
    get(pair<_Up, _Tp>& __p) noexcept
    { return __p.second; }

  template <typename _Tp, typename _Up>
    constexpr const _Tp&
    get(const pair<_Up, _Tp>& __p) noexcept
    { return __p.second; }

  template <typename _Tp, typename _Up>
    constexpr _Tp&&
    get(pair<_Up, _Tp>&& __p) noexcept
    { return std::move(__p.second); }

  template <typename _Tp, typename _Up>
    constexpr const _Tp&&
    get(const pair<_Up, _Tp>&& __p) noexcept
    { return std::move(__p.second); }




  template <typename _Tp, typename _Up = _Tp>
    inline _Tp
    exchange(_Tp& __obj, _Up&& __new_val)
    { return std::__exchange(__obj, std::forward<_Up>(__new_val)); }




  template<size_t... _Indexes> struct _Index_tuple { };
# 301 "/usr/include/c++/9.2.0/utility" 3
  template<size_t _Num>
    struct _Build_index_tuple
    {






      using __type = _Index_tuple<__integer_pack(_Num)...>;

    };






  template<typename _Tp, _Tp... _Idx>
    struct integer_sequence
    {
      typedef _Tp value_type;
      static constexpr size_t size() noexcept { return sizeof...(_Idx); }
    };


  template<typename _Tp, _Tp _Num>
    using make_integer_sequence



      = integer_sequence<_Tp, __integer_pack(_Num)...>;





  template<size_t... _Idx>
    using index_sequence = integer_sequence<size_t, _Idx...>;


  template<size_t _Num>
    using make_index_sequence = make_integer_sequence<size_t, _Num>;


  template<typename... _Types>
    using index_sequence_for = make_index_sequence<sizeof...(_Types)>;
# 396 "/usr/include/c++/9.2.0/utility" 3

}
# 39 "/usr/include/c++/9.2.0/tuple" 2 3
# 1 "/usr/include/c++/9.2.0/array" 1 3
# 32 "/usr/include/c++/9.2.0/array" 3
       
# 33 "/usr/include/c++/9.2.0/array" 3






# 1 "/usr/include/c++/9.2.0/stdexcept" 1 3
# 36 "/usr/include/c++/9.2.0/stdexcept" 3
       
# 37 "/usr/include/c++/9.2.0/stdexcept" 3


# 1 "/usr/include/c++/9.2.0/string" 1 3
# 36 "/usr/include/c++/9.2.0/string" 3
       
# 37 "/usr/include/c++/9.2.0/string" 3


# 1 "/usr/include/c++/9.2.0/bits/stringfwd.h" 1 3
# 37 "/usr/include/c++/9.2.0/bits/stringfwd.h" 3
       
# 38 "/usr/include/c++/9.2.0/bits/stringfwd.h" 3




namespace std __attribute__ ((__visibility__ ("default")))
{








  template<class _CharT>
    struct char_traits;

  template<> struct char_traits<char>;


  template<> struct char_traits<wchar_t>;







  template<> struct char_traits<char16_t>;
  template<> struct char_traits<char32_t>;


namespace __cxx11 {

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
           typename _Alloc = allocator<_CharT> >
    class basic_string;

}


  typedef basic_string<char> string;



  typedef basic_string<wchar_t> wstring;
# 93 "/usr/include/c++/9.2.0/bits/stringfwd.h" 3
  typedef basic_string<char16_t> u16string;


  typedef basic_string<char32_t> u32string;





}
# 40 "/usr/include/c++/9.2.0/string" 2 3
# 1 "/usr/include/c++/9.2.0/bits/char_traits.h" 1 3
# 37 "/usr/include/c++/9.2.0/bits/char_traits.h" 3
       
# 38 "/usr/include/c++/9.2.0/bits/char_traits.h" 3

# 1 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 1 3
# 65 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
# 1 "/usr/include/c++/9.2.0/bits/stl_iterator_base_types.h" 1 3
# 62 "/usr/include/c++/9.2.0/bits/stl_iterator_base_types.h" 3
       
# 63 "/usr/include/c++/9.2.0/bits/stl_iterator_base_types.h" 3







namespace std __attribute__ ((__visibility__ ("default")))
{

# 89 "/usr/include/c++/9.2.0/bits/stl_iterator_base_types.h" 3
  struct input_iterator_tag { };


  struct output_iterator_tag { };


  struct forward_iterator_tag : public input_iterator_tag { };



  struct bidirectional_iterator_tag : public forward_iterator_tag { };



  struct random_access_iterator_tag : public bidirectional_iterator_tag { };
# 116 "/usr/include/c++/9.2.0/bits/stl_iterator_base_types.h" 3
  template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
           typename _Pointer = _Tp*, typename _Reference = _Tp&>
    struct iterator
    {

      typedef _Category iterator_category;

      typedef _Tp value_type;

      typedef _Distance difference_type;

      typedef _Pointer pointer;

      typedef _Reference reference;
    };
# 143 "/usr/include/c++/9.2.0/bits/stl_iterator_base_types.h" 3
  template<typename _Iterator, typename = __void_t<>>
    struct __iterator_traits { };

  template<typename _Iterator>
    struct __iterator_traits<_Iterator,
        __void_t<typename _Iterator::iterator_category,
          typename _Iterator::value_type,
          typename _Iterator::difference_type,
          typename _Iterator::pointer,
          typename _Iterator::reference>>
    {
      typedef typename _Iterator::iterator_category iterator_category;
      typedef typename _Iterator::value_type value_type;
      typedef typename _Iterator::difference_type difference_type;
      typedef typename _Iterator::pointer pointer;
      typedef typename _Iterator::reference reference;
    };

  template<typename _Iterator>
    struct iterator_traits
    : public __iterator_traits<_Iterator> { };
# 177 "/usr/include/c++/9.2.0/bits/stl_iterator_base_types.h" 3
  template<typename _Tp>
    struct iterator_traits<_Tp*>
    {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef ptrdiff_t difference_type;
      typedef _Tp* pointer;
      typedef _Tp& reference;
    };


  template<typename _Tp>
    struct iterator_traits<const _Tp*>
    {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef ptrdiff_t difference_type;
      typedef const _Tp* pointer;
      typedef const _Tp& reference;
    };





  template<typename _Iter>
    inline constexpr
    typename iterator_traits<_Iter>::iterator_category
    __iterator_category(const _Iter&)
    { return typename iterator_traits<_Iter>::iterator_category(); }
# 231 "/usr/include/c++/9.2.0/bits/stl_iterator_base_types.h" 3
  template<typename _InIter>
    using _RequireInputIter = typename
      enable_if<is_convertible<typename
  iterator_traits<_InIter>::iterator_category,
          input_iterator_tag>::value>::type;



}
# 66 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 2 3
# 1 "/usr/include/c++/9.2.0/bits/stl_iterator_base_funcs.h" 1 3
# 62 "/usr/include/c++/9.2.0/bits/stl_iterator_base_funcs.h" 3
       
# 63 "/usr/include/c++/9.2.0/bits/stl_iterator_base_funcs.h" 3


# 1 "/usr/include/c++/9.2.0/debug/assertions.h" 1 3
# 66 "/usr/include/c++/9.2.0/bits/stl_iterator_base_funcs.h" 2 3

namespace std __attribute__ ((__visibility__ ("default")))
{




  template <typename> struct _List_iterator;
  template <typename> struct _List_const_iterator;


  template<typename _InputIterator>
    inline constexpr
    typename iterator_traits<_InputIterator>::difference_type
    __distance(_InputIterator __first, _InputIterator __last,
               input_iterator_tag)
    {

     

      typename iterator_traits<_InputIterator>::difference_type __n = 0;
      while (__first != __last)
 {
   ++__first;
   ++__n;
 }
      return __n;
    }

  template<typename _RandomAccessIterator>
    inline constexpr
    typename iterator_traits<_RandomAccessIterator>::difference_type
    __distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
               random_access_iterator_tag)
    {

     

      return __last - __first;
    }



  template<typename _Tp>
    ptrdiff_t
    __distance(std::_List_iterator<_Tp>,
        std::_List_iterator<_Tp>,
        input_iterator_tag);

  template<typename _Tp>
    ptrdiff_t
    __distance(std::_List_const_iterator<_Tp>,
        std::_List_const_iterator<_Tp>,
        input_iterator_tag);
# 135 "/usr/include/c++/9.2.0/bits/stl_iterator_base_funcs.h" 3
  template<typename _InputIterator>
    inline
    typename iterator_traits<_InputIterator>::difference_type
    distance(_InputIterator __first, _InputIterator __last)
    {

      return std::__distance(__first, __last,
        std::__iterator_category(__first));
    }

  template<typename _InputIterator, typename _Distance>
    inline constexpr void
    __advance(_InputIterator& __i, _Distance __n, input_iterator_tag)
    {

     
      ;
      while (__n--)
 ++__i;
    }

  template<typename _BidirectionalIterator, typename _Distance>
    inline constexpr void
    __advance(_BidirectionalIterator& __i, _Distance __n,
       bidirectional_iterator_tag)
    {

     

      if (__n > 0)
        while (__n--)
   ++__i;
      else
        while (__n++)
   --__i;
    }

  template<typename _RandomAccessIterator, typename _Distance>
    inline constexpr void
    __advance(_RandomAccessIterator& __i, _Distance __n,
              random_access_iterator_tag)
    {

     

      if (__builtin_constant_p(__n) && __n == 1)
 ++__i;
      else if (__builtin_constant_p(__n) && __n == -1)
 --__i;
      else
 __i += __n;
    }
# 200 "/usr/include/c++/9.2.0/bits/stl_iterator_base_funcs.h" 3
  template<typename _InputIterator, typename _Distance>
    inline void
    advance(_InputIterator& __i, _Distance __n)
    {

      typename iterator_traits<_InputIterator>::difference_type __d = __n;
      std::__advance(__i, __d, std::__iterator_category(__i));
    }



  template<typename _InputIterator>
    inline _InputIterator
    next(_InputIterator __x, typename
  iterator_traits<_InputIterator>::difference_type __n = 1)
    {

     
      std::advance(__x, __n);
      return __x;
    }

  template<typename _BidirectionalIterator>
    inline _BidirectionalIterator
    prev(_BidirectionalIterator __x, typename
  iterator_traits<_BidirectionalIterator>::difference_type __n = 1)
    {

     

      std::advance(__x, -__n);
      return __x;
    }




}
# 67 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 2 3
# 1 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 1 3
# 76 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
namespace std __attribute__ ((__visibility__ ("default")))
{

# 104 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
  template<typename _Iterator>
    class reverse_iterator
    : public iterator<typename iterator_traits<_Iterator>::iterator_category,
        typename iterator_traits<_Iterator>::value_type,
        typename iterator_traits<_Iterator>::difference_type,
        typename iterator_traits<_Iterator>::pointer,
                      typename iterator_traits<_Iterator>::reference>
    {
    protected:
      _Iterator current;

      typedef iterator_traits<_Iterator> __traits_type;

    public:
      typedef _Iterator iterator_type;
      typedef typename __traits_type::difference_type difference_type;
      typedef typename __traits_type::pointer pointer;
      typedef typename __traits_type::reference reference;
# 130 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
     
      reverse_iterator() : current() { }




      explicit
      reverse_iterator(iterator_type __x) : current(__x) { }




     
      reverse_iterator(const reverse_iterator& __x)
      : current(__x.current) { }


      reverse_iterator& operator=(const reverse_iterator&) = default;






      template<typename _Iter>

        reverse_iterator(const reverse_iterator<_Iter>& __x)
 : current(__x.base()) { }




      iterator_type
      base() const
      { return current; }
# 176 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
      reference
      operator*() const
      {
 _Iterator __tmp = current;
 return *--__tmp;
      }






      pointer
      operator->() const
      {


 _Iterator __tmp = current;
 --__tmp;
 return _S_to_pointer(__tmp);
      }






      reverse_iterator&
      operator++()
      {
 --current;
 return *this;
      }






      reverse_iterator
      operator++(int)
      {
 reverse_iterator __tmp = *this;
 --current;
 return __tmp;
      }






      reverse_iterator&
      operator--()
      {
 ++current;
 return *this;
      }






      reverse_iterator
      operator--(int)
      {
 reverse_iterator __tmp = *this;
 ++current;
 return __tmp;
      }






      reverse_iterator
      operator+(difference_type __n) const
      { return reverse_iterator(current - __n); }







      reverse_iterator&
      operator+=(difference_type __n)
      {
 current -= __n;
 return *this;
      }






      reverse_iterator
      operator-(difference_type __n) const
      { return reverse_iterator(current + __n); }







      reverse_iterator&
      operator-=(difference_type __n)
      {
 current += __n;
 return *this;
      }






      reference
      operator[](difference_type __n) const
      { return *(*this + __n); }

    private:
      template<typename _Tp>
 static _Tp*
 _S_to_pointer(_Tp* __p)
        { return __p; }

      template<typename _Tp>
 static pointer
 _S_to_pointer(_Tp __t)
        { return __t.operator->(); }
    };
# 323 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
  template<typename _Iterator>
    inline bool
    operator==(const reverse_iterator<_Iterator>& __x,
        const reverse_iterator<_Iterator>& __y)
    { return __x.base() == __y.base(); }

  template<typename _Iterator>
    inline bool
    operator<(const reverse_iterator<_Iterator>& __x,
       const reverse_iterator<_Iterator>& __y)
    { return __y.base() < __x.base(); }

  template<typename _Iterator>
    inline bool
    operator!=(const reverse_iterator<_Iterator>& __x,
        const reverse_iterator<_Iterator>& __y)
    { return !(__x == __y); }

  template<typename _Iterator>
    inline bool
    operator>(const reverse_iterator<_Iterator>& __x,
       const reverse_iterator<_Iterator>& __y)
    { return __y < __x; }

  template<typename _Iterator>
    inline bool
    operator<=(const reverse_iterator<_Iterator>& __x,
        const reverse_iterator<_Iterator>& __y)
    { return !(__y < __x); }

  template<typename _Iterator>
    inline bool
    operator>=(const reverse_iterator<_Iterator>& __x,
        const reverse_iterator<_Iterator>& __y)
    { return !(__x < __y); }



  template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator==(const reverse_iterator<_IteratorL>& __x,
        const reverse_iterator<_IteratorR>& __y)
    { return __x.base() == __y.base(); }

  template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator<(const reverse_iterator<_IteratorL>& __x,
       const reverse_iterator<_IteratorR>& __y)
    { return __y.base() < __x.base(); }

  template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator!=(const reverse_iterator<_IteratorL>& __x,
        const reverse_iterator<_IteratorR>& __y)
    { return !(__x == __y); }

  template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator>(const reverse_iterator<_IteratorL>& __x,
       const reverse_iterator<_IteratorR>& __y)
    { return __y < __x; }

  template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator<=(const reverse_iterator<_IteratorL>& __x,
        const reverse_iterator<_IteratorR>& __y)
    { return !(__y < __x); }

  template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator>=(const reverse_iterator<_IteratorL>& __x,
        const reverse_iterator<_IteratorR>& __y)
    { return !(__x < __y); }
# 413 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
  template<typename _IteratorL, typename _IteratorR>
    inline auto
    operator-(const reverse_iterator<_IteratorL>& __x,
       const reverse_iterator<_IteratorR>& __y)
    -> decltype(__y.base() - __x.base())
    { return __y.base() - __x.base(); }


  template<typename _Iterator>
    inline reverse_iterator<_Iterator>
    operator+(typename reverse_iterator<_Iterator>::difference_type __n,
       const reverse_iterator<_Iterator>& __x)
    { return reverse_iterator<_Iterator>(__x.base() - __n); }



  template<typename _Iterator>
    inline reverse_iterator<_Iterator>
    __make_reverse_iterator(_Iterator __i)
    { return reverse_iterator<_Iterator>(__i); }







  template<typename _Iterator>
    inline reverse_iterator<_Iterator>
    make_reverse_iterator(_Iterator __i)
    { return reverse_iterator<_Iterator>(__i); }




  template<typename _Iterator>
    auto
    __niter_base(reverse_iterator<_Iterator> __it)
    -> decltype(__make_reverse_iterator(__niter_base(__it.base())))
    { return __make_reverse_iterator(__niter_base(__it.base())); }

  template<typename _Iterator>
    struct __is_move_iterator<reverse_iterator<_Iterator> >
      : __is_move_iterator<_Iterator>
    { };

  template<typename _Iterator>
    auto
    __miter_base(reverse_iterator<_Iterator> __it)
    -> decltype(__make_reverse_iterator(__miter_base(__it.base())))
    { return __make_reverse_iterator(__miter_base(__it.base())); }
# 477 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
  template<typename _Container>
    class back_insert_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
    {
    protected:
      _Container* container;

    public:

      typedef _Container container_type;


      explicit
      back_insert_iterator(_Container& __x)
      : container(std::__addressof(__x)) { }
# 512 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
      back_insert_iterator&
      operator=(const typename _Container::value_type& __value)
      {
 container->push_back(__value);
 return *this;
      }

      back_insert_iterator&
      operator=(typename _Container::value_type&& __value)
      {
 container->push_back(std::move(__value));
 return *this;
      }



      back_insert_iterator&
      operator*()
      { return *this; }


      back_insert_iterator&
      operator++()
      { return *this; }


      back_insert_iterator
      operator++(int)
      { return *this; }
    };
# 554 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
  template<typename _Container>
    inline back_insert_iterator<_Container>
    back_inserter(_Container& __x)
    { return back_insert_iterator<_Container>(__x); }
# 569 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
  template<typename _Container>
    class front_insert_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
    {
    protected:
      _Container* container;

    public:

      typedef _Container container_type;


      explicit front_insert_iterator(_Container& __x)
      : container(std::__addressof(__x)) { }
# 603 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
      front_insert_iterator&
      operator=(const typename _Container::value_type& __value)
      {
 container->push_front(__value);
 return *this;
      }

      front_insert_iterator&
      operator=(typename _Container::value_type&& __value)
      {
 container->push_front(std::move(__value));
 return *this;
      }



      front_insert_iterator&
      operator*()
      { return *this; }


      front_insert_iterator&
      operator++()
      { return *this; }


      front_insert_iterator
      operator++(int)
      { return *this; }
    };
# 645 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
  template<typename _Container>
    inline front_insert_iterator<_Container>
    front_inserter(_Container& __x)
    { return front_insert_iterator<_Container>(__x); }
# 664 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
  template<typename _Container>
    class insert_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
    {
    protected:
      _Container* container;
      typename _Container::iterator iter;

    public:

      typedef _Container container_type;





      insert_iterator(_Container& __x, typename _Container::iterator __i)
      : container(std::__addressof(__x)), iter(__i) {}
# 715 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
      insert_iterator&
      operator=(const typename _Container::value_type& __value)
      {
 iter = container->insert(iter, __value);
 ++iter;
 return *this;
      }

      insert_iterator&
      operator=(typename _Container::value_type&& __value)
      {
 iter = container->insert(iter, std::move(__value));
 ++iter;
 return *this;
      }



      insert_iterator&
      operator*()
      { return *this; }


      insert_iterator&
      operator++()
      { return *this; }


      insert_iterator&
      operator++(int)
      { return *this; }
    };
# 760 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
  template<typename _Container, typename _Iterator>
    inline insert_iterator<_Container>
    inserter(_Container& __x, _Iterator __i)
    {
      return insert_iterator<_Container>(__x,
      typename _Container::iterator(__i));
    }




}

namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{

# 784 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
  using std::iterator_traits;
  using std::iterator;
  template<typename _Iterator, typename _Container>
    class __normal_iterator
    {
    protected:
      _Iterator _M_current;

      typedef iterator_traits<_Iterator> __traits_type;

    public:
      typedef _Iterator iterator_type;
      typedef typename __traits_type::iterator_category iterator_category;
      typedef typename __traits_type::value_type value_type;
      typedef typename __traits_type::difference_type difference_type;
      typedef typename __traits_type::reference reference;
      typedef typename __traits_type::pointer pointer;

      constexpr __normal_iterator() noexcept
      : _M_current(_Iterator()) { }

      explicit
      __normal_iterator(const _Iterator& __i) noexcept
      : _M_current(__i) { }


      template<typename _Iter>
        __normal_iterator(const __normal_iterator<_Iter,
     typename __enable_if<
              (std::__are_same<_Iter, typename _Container::pointer>::__value),
        _Container>::__type>& __i) noexcept
        : _M_current(__i.base()) { }


      reference
      operator*() const noexcept
      { return *_M_current; }

      pointer
      operator->() const noexcept
      { return _M_current; }

      __normal_iterator&
      operator++() noexcept
      {
 ++_M_current;
 return *this;
      }

      __normal_iterator
      operator++(int) noexcept
      { return __normal_iterator(_M_current++); }


      __normal_iterator&
      operator--() noexcept
      {
 --_M_current;
 return *this;
      }

      __normal_iterator
      operator--(int) noexcept
      { return __normal_iterator(_M_current--); }


      reference
      operator[](difference_type __n) const noexcept
      { return _M_current[__n]; }

      __normal_iterator&
      operator+=(difference_type __n) noexcept
      { _M_current += __n; return *this; }

      __normal_iterator
      operator+(difference_type __n) const noexcept
      { return __normal_iterator(_M_current + __n); }

      __normal_iterator&
      operator-=(difference_type __n) noexcept
      { _M_current -= __n; return *this; }

      __normal_iterator
      operator-(difference_type __n) const noexcept
      { return __normal_iterator(_M_current - __n); }

      const _Iterator&
      base() const noexcept
      { return _M_current; }
    };
# 884 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
  template<typename _IteratorL, typename _IteratorR, typename _Container>
    inline bool
    operator==(const __normal_iterator<_IteratorL, _Container>& __lhs,
        const __normal_iterator<_IteratorR, _Container>& __rhs)
    noexcept
    { return __lhs.base() == __rhs.base(); }

  template<typename _Iterator, typename _Container>
    inline bool
    operator==(const __normal_iterator<_Iterator, _Container>& __lhs,
        const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() == __rhs.base(); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
    inline bool
    operator!=(const __normal_iterator<_IteratorL, _Container>& __lhs,
        const __normal_iterator<_IteratorR, _Container>& __rhs)
    noexcept
    { return __lhs.base() != __rhs.base(); }

  template<typename _Iterator, typename _Container>
    inline bool
    operator!=(const __normal_iterator<_Iterator, _Container>& __lhs,
        const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() != __rhs.base(); }


  template<typename _IteratorL, typename _IteratorR, typename _Container>
    inline bool
    operator<(const __normal_iterator<_IteratorL, _Container>& __lhs,
       const __normal_iterator<_IteratorR, _Container>& __rhs)
    noexcept
    { return __lhs.base() < __rhs.base(); }

  template<typename _Iterator, typename _Container>
    inline bool
    operator<(const __normal_iterator<_Iterator, _Container>& __lhs,
       const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() < __rhs.base(); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
    inline bool
    operator>(const __normal_iterator<_IteratorL, _Container>& __lhs,
       const __normal_iterator<_IteratorR, _Container>& __rhs)
    noexcept
    { return __lhs.base() > __rhs.base(); }

  template<typename _Iterator, typename _Container>
    inline bool
    operator>(const __normal_iterator<_Iterator, _Container>& __lhs,
       const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() > __rhs.base(); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
    inline bool
    operator<=(const __normal_iterator<_IteratorL, _Container>& __lhs,
        const __normal_iterator<_IteratorR, _Container>& __rhs)
    noexcept
    { return __lhs.base() <= __rhs.base(); }

  template<typename _Iterator, typename _Container>
    inline bool
    operator<=(const __normal_iterator<_Iterator, _Container>& __lhs,
        const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() <= __rhs.base(); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
    inline bool
    operator>=(const __normal_iterator<_IteratorL, _Container>& __lhs,
        const __normal_iterator<_IteratorR, _Container>& __rhs)
    noexcept
    { return __lhs.base() >= __rhs.base(); }

  template<typename _Iterator, typename _Container>
    inline bool
    operator>=(const __normal_iterator<_Iterator, _Container>& __lhs,
        const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() >= __rhs.base(); }





  template<typename _IteratorL, typename _IteratorR, typename _Container>


    inline auto
    operator-(const __normal_iterator<_IteratorL, _Container>& __lhs,
       const __normal_iterator<_IteratorR, _Container>& __rhs) noexcept
    -> decltype(__lhs.base() - __rhs.base())





    { return __lhs.base() - __rhs.base(); }

  template<typename _Iterator, typename _Container>
    inline typename __normal_iterator<_Iterator, _Container>::difference_type
    operator-(const __normal_iterator<_Iterator, _Container>& __lhs,
       const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() - __rhs.base(); }

  template<typename _Iterator, typename _Container>
    inline __normal_iterator<_Iterator, _Container>
    operator+(typename __normal_iterator<_Iterator, _Container>::difference_type
       __n, const __normal_iterator<_Iterator, _Container>& __i)
    noexcept
    { return __normal_iterator<_Iterator, _Container>(__i.base() + __n); }


}

namespace std __attribute__ ((__visibility__ ("default")))
{


  template<typename _Iterator, typename _Container>
    _Iterator
    __niter_base(__gnu_cxx::__normal_iterator<_Iterator, _Container> __it)
    noexcept(std::is_nothrow_copy_constructible<_Iterator>::value)
    { return __it.base(); }
# 1030 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3
  template<typename _Iterator>
    class move_iterator
    {
    protected:
      _Iterator _M_current;

      typedef iterator_traits<_Iterator> __traits_type;
      typedef typename __traits_type::reference __base_ref;

    public:
      typedef _Iterator iterator_type;
      typedef typename __traits_type::iterator_category iterator_category;
      typedef typename __traits_type::value_type value_type;
      typedef typename __traits_type::difference_type difference_type;

      typedef _Iterator pointer;


      typedef typename conditional<is_reference<__base_ref>::value,
    typename remove_reference<__base_ref>::type&&,
    __base_ref>::type reference;

     
      move_iterator()
      : _M_current() { }

      explicit
      move_iterator(iterator_type __i)
      : _M_current(__i) { }

      template<typename _Iter>

 move_iterator(const move_iterator<_Iter>& __i)
 : _M_current(__i.base()) { }

      iterator_type
      base() const
      { return _M_current; }

      reference
      operator*() const
      { return static_cast<reference>(*_M_current); }

      pointer
      operator->() const
      { return _M_current; }

      move_iterator&
      operator++()
      {
 ++_M_current;
 return *this;
      }

      move_iterator
      operator++(int)
      {
 move_iterator __tmp = *this;
 ++_M_current;
 return __tmp;
      }

      move_iterator&
      operator--()
      {
 --_M_current;
 return *this;
      }

      move_iterator
      operator--(int)
      {
 move_iterator __tmp = *this;
 --_M_current;
 return __tmp;
      }

      move_iterator
      operator+(difference_type __n) const
      { return move_iterator(_M_current + __n); }

      move_iterator&
      operator+=(difference_type __n)
      {
 _M_current += __n;
 return *this;
      }

      move_iterator
      operator-(difference_type __n) const
      { return move_iterator(_M_current - __n); }

      move_iterator&
      operator-=(difference_type __n)
      {
 _M_current -= __n;
 return *this;
      }

      reference
      operator[](difference_type __n) const
      { return std::move(_M_current[__n]); }
    };




  template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator==(const move_iterator<_IteratorL>& __x,
        const move_iterator<_IteratorR>& __y)
    { return __x.base() == __y.base(); }

  template<typename _Iterator>
    inline bool
    operator==(const move_iterator<_Iterator>& __x,
        const move_iterator<_Iterator>& __y)
    { return __x.base() == __y.base(); }

  template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator!=(const move_iterator<_IteratorL>& __x,
        const move_iterator<_IteratorR>& __y)
    { return !(__x == __y); }

  template<typename _Iterator>
    inline bool
    operator!=(const move_iterator<_Iterator>& __x,
        const move_iterator<_Iterator>& __y)
    { return !(__x == __y); }

  template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator<(const move_iterator<_IteratorL>& __x,
       const move_iterator<_IteratorR>& __y)
    { return __x.base() < __y.base(); }

  template<typename _Iterator>
    inline bool
    operator<(const move_iterator<_Iterator>& __x,
       const move_iterator<_Iterator>& __y)
    { return __x.base() < __y.base(); }

  template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator<=(const move_iterator<_IteratorL>& __x,
        const move_iterator<_IteratorR>& __y)
    { return !(__y < __x); }

  template<typename _Iterator>
    inline bool
    operator<=(const move_iterator<_Iterator>& __x,
        const move_iterator<_Iterator>& __y)
    { return !(__y < __x); }

  template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator>(const move_iterator<_IteratorL>& __x,
       const move_iterator<_IteratorR>& __y)
    { return __y < __x; }

  template<typename _Iterator>
    inline bool
    operator>(const move_iterator<_Iterator>& __x,
       const move_iterator<_Iterator>& __y)
    { return __y < __x; }

  template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator>=(const move_iterator<_IteratorL>& __x,
        const move_iterator<_IteratorR>& __y)
    { return !(__x < __y); }

  template<typename _Iterator>
    inline bool
    operator>=(const move_iterator<_Iterator>& __x,
        const move_iterator<_Iterator>& __y)
    { return !(__x < __y); }


  template<typename _IteratorL, typename _IteratorR>
    inline auto
    operator-(const move_iterator<_IteratorL>& __x,
       const move_iterator<_IteratorR>& __y)
    -> decltype(__x.base() - __y.base())
    { return __x.base() - __y.base(); }

  template<typename _Iterator>
    inline move_iterator<_Iterator>
    operator+(typename move_iterator<_Iterator>::difference_type __n,
       const move_iterator<_Iterator>& __x)
    { return __x + __n; }

  template<typename _Iterator>
    inline move_iterator<_Iterator>
    make_move_iterator(_Iterator __i)
    { return move_iterator<_Iterator>(__i); }

  template<typename _Iterator, typename _ReturnType
    = typename conditional<__move_if_noexcept_cond
      <typename iterator_traits<_Iterator>::value_type>::value,
                _Iterator, move_iterator<_Iterator>>::type>
    inline _ReturnType
    __make_move_if_noexcept_iterator(_Iterator __i)
    { return _ReturnType(__i); }



  template<typename _Tp, typename _ReturnType
    = typename conditional<__move_if_noexcept_cond<_Tp>::value,
      const _Tp*, move_iterator<_Tp*>>::type>
    inline _ReturnType
    __make_move_if_noexcept_iterator(_Tp* __i)
    { return _ReturnType(__i); }



  template<typename _Iterator>
    auto
    __niter_base(move_iterator<_Iterator> __it)
    -> decltype(make_move_iterator(__niter_base(__it.base())))
    { return make_move_iterator(__niter_base(__it.base())); }

  template<typename _Iterator>
    struct __is_move_iterator<move_iterator<_Iterator> >
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };

  template<typename _Iterator>
    auto
    __miter_base(move_iterator<_Iterator> __it)
    -> decltype(__miter_base(__it.base()))
    { return __miter_base(__it.base()); }
# 1295 "/usr/include/c++/9.2.0/bits/stl_iterator.h" 3

}
# 68 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 2 3

# 1 "/usr/include/c++/9.2.0/debug/debug.h" 1 3
# 48 "/usr/include/c++/9.2.0/debug/debug.h" 3
namespace std
{
  namespace __debug { }
}




namespace __gnu_debug
{
  using namespace std::__debug;
}
# 70 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 2 3

# 1 "/usr/include/c++/9.2.0/bits/predefined_ops.h" 1 3
# 33 "/usr/include/c++/9.2.0/bits/predefined_ops.h" 3
namespace __gnu_cxx
{
namespace __ops
{
  struct _Iter_less_iter
  {
    template<typename _Iterator1, typename _Iterator2>
      constexpr
      bool
      operator()(_Iterator1 __it1, _Iterator2 __it2) const
      { return *__it1 < *__it2; }
  };

  constexpr
  inline _Iter_less_iter
  __iter_less_iter()
  { return _Iter_less_iter(); }

  struct _Iter_less_val
  {

    constexpr _Iter_less_val() = default;




    explicit
    _Iter_less_val(_Iter_less_iter) { }

    template<typename _Iterator, typename _Value>
      bool
      operator()(_Iterator __it, _Value& __val) const
      { return *__it < __val; }
  };

  inline _Iter_less_val
  __iter_less_val()
  { return _Iter_less_val(); }

  inline _Iter_less_val
  __iter_comp_val(_Iter_less_iter)
  { return _Iter_less_val(); }

  struct _Val_less_iter
  {

    constexpr _Val_less_iter() = default;




    explicit
    _Val_less_iter(_Iter_less_iter) { }

    template<typename _Value, typename _Iterator>
      bool
      operator()(_Value& __val, _Iterator __it) const
      { return __val < *__it; }
  };

  inline _Val_less_iter
  __val_less_iter()
  { return _Val_less_iter(); }

  inline _Val_less_iter
  __val_comp_iter(_Iter_less_iter)
  { return _Val_less_iter(); }

  struct _Iter_equal_to_iter
  {
    template<typename _Iterator1, typename _Iterator2>
      bool
      operator()(_Iterator1 __it1, _Iterator2 __it2) const
      { return *__it1 == *__it2; }
  };

  inline _Iter_equal_to_iter
  __iter_equal_to_iter()
  { return _Iter_equal_to_iter(); }

  struct _Iter_equal_to_val
  {
    template<typename _Iterator, typename _Value>
      bool
      operator()(_Iterator __it, _Value& __val) const
      { return *__it == __val; }
  };

  inline _Iter_equal_to_val
  __iter_equal_to_val()
  { return _Iter_equal_to_val(); }

  inline _Iter_equal_to_val
  __iter_comp_val(_Iter_equal_to_iter)
  { return _Iter_equal_to_val(); }

  template<typename _Compare>
    struct _Iter_comp_iter
    {
      _Compare _M_comp;

      explicit constexpr
      _Iter_comp_iter(_Compare __comp)
 : _M_comp(std::move(__comp))
      { }

      template<typename _Iterator1, typename _Iterator2>
        constexpr
        bool
        operator()(_Iterator1 __it1, _Iterator2 __it2)
        { return bool(_M_comp(*__it1, *__it2)); }
    };

  template<typename _Compare>
    constexpr
    inline _Iter_comp_iter<_Compare>
    __iter_comp_iter(_Compare __comp)
    { return _Iter_comp_iter<_Compare>(std::move(__comp)); }

  template<typename _Compare>
    struct _Iter_comp_val
    {
      _Compare _M_comp;

      explicit
      _Iter_comp_val(_Compare __comp)
 : _M_comp(std::move(__comp))
      { }

      explicit
      _Iter_comp_val(const _Iter_comp_iter<_Compare>& __comp)
 : _M_comp(__comp._M_comp)
      { }


      explicit
      _Iter_comp_val(_Iter_comp_iter<_Compare>&& __comp)
 : _M_comp(std::move(__comp._M_comp))
      { }


      template<typename _Iterator, typename _Value>
 bool
 operator()(_Iterator __it, _Value& __val)
 { return bool(_M_comp(*__it, __val)); }
    };

  template<typename _Compare>
   inline _Iter_comp_val<_Compare>
    __iter_comp_val(_Compare __comp)
    { return _Iter_comp_val<_Compare>(std::move(__comp)); }

  template<typename _Compare>
    inline _Iter_comp_val<_Compare>
    __iter_comp_val(_Iter_comp_iter<_Compare> __comp)
    { return _Iter_comp_val<_Compare>(std::move(__comp)); }

  template<typename _Compare>
    struct _Val_comp_iter
    {
      _Compare _M_comp;

      explicit
      _Val_comp_iter(_Compare __comp)
 : _M_comp(std::move(__comp))
      { }

      explicit
      _Val_comp_iter(const _Iter_comp_iter<_Compare>& __comp)
 : _M_comp(__comp._M_comp)
      { }


      explicit
      _Val_comp_iter(_Iter_comp_iter<_Compare>&& __comp)
 : _M_comp(std::move(__comp._M_comp))
      { }


      template<typename _Value, typename _Iterator>
 bool
 operator()(_Value& __val, _Iterator __it)
 { return bool(_M_comp(__val, *__it)); }
    };

  template<typename _Compare>
    inline _Val_comp_iter<_Compare>
    __val_comp_iter(_Compare __comp)
    { return _Val_comp_iter<_Compare>(std::move(__comp)); }

  template<typename _Compare>
    inline _Val_comp_iter<_Compare>
    __val_comp_iter(_Iter_comp_iter<_Compare> __comp)
    { return _Val_comp_iter<_Compare>(std::move(__comp)); }

  template<typename _Value>
    struct _Iter_equals_val
    {
      _Value& _M_value;

      explicit
      _Iter_equals_val(_Value& __value)
 : _M_value(__value)
      { }

      template<typename _Iterator>
 bool
 operator()(_Iterator __it)
 { return *__it == _M_value; }
    };

  template<typename _Value>
    inline _Iter_equals_val<_Value>
    __iter_equals_val(_Value& __val)
    { return _Iter_equals_val<_Value>(__val); }

  template<typename _Iterator1>
    struct _Iter_equals_iter
    {
      _Iterator1 _M_it1;

      explicit
      _Iter_equals_iter(_Iterator1 __it1)
 : _M_it1(__it1)
      { }

      template<typename _Iterator2>
 bool
 operator()(_Iterator2 __it2)
 { return *__it2 == *_M_it1; }
    };

  template<typename _Iterator>
    inline _Iter_equals_iter<_Iterator>
    __iter_comp_iter(_Iter_equal_to_iter, _Iterator __it)
    { return _Iter_equals_iter<_Iterator>(__it); }

  template<typename _Predicate>
    struct _Iter_pred
    {
      _Predicate _M_pred;

      explicit
      _Iter_pred(_Predicate __pred)
 : _M_pred(std::move(__pred))
      { }

      template<typename _Iterator>
 bool
 operator()(_Iterator __it)
 { return bool(_M_pred(*__it)); }
    };

  template<typename _Predicate>
    inline _Iter_pred<_Predicate>
    __pred_iter(_Predicate __pred)
    { return _Iter_pred<_Predicate>(std::move(__pred)); }

  template<typename _Compare, typename _Value>
    struct _Iter_comp_to_val
    {
      _Compare _M_comp;
      _Value& _M_value;

      _Iter_comp_to_val(_Compare __comp, _Value& __value)
 : _M_comp(std::move(__comp)), _M_value(__value)
      { }

      template<typename _Iterator>
 bool
 operator()(_Iterator __it)
 { return bool(_M_comp(*__it, _M_value)); }
    };

  template<typename _Compare, typename _Value>
    _Iter_comp_to_val<_Compare, _Value>
    __iter_comp_val(_Compare __comp, _Value &__val)
    {
      return _Iter_comp_to_val<_Compare, _Value>(std::move(__comp), __val);
    }

  template<typename _Compare, typename _Iterator1>
    struct _Iter_comp_to_iter
    {
      _Compare _M_comp;
      _Iterator1 _M_it1;

      _Iter_comp_to_iter(_Compare __comp, _Iterator1 __it1)
 : _M_comp(std::move(__comp)), _M_it1(__it1)
      { }

      template<typename _Iterator2>
 bool
 operator()(_Iterator2 __it2)
 { return bool(_M_comp(*__it2, *_M_it1)); }
    };

  template<typename _Compare, typename _Iterator>
    inline _Iter_comp_to_iter<_Compare, _Iterator>
    __iter_comp_iter(_Iter_comp_iter<_Compare> __comp, _Iterator __it)
    {
      return _Iter_comp_to_iter<_Compare, _Iterator>(
   std::move(__comp._M_comp), __it);
    }

  template<typename _Predicate>
    struct _Iter_negate
    {
      _Predicate _M_pred;

      explicit
      _Iter_negate(_Predicate __pred)
 : _M_pred(std::move(__pred))
      { }

      template<typename _Iterator>
 bool
 operator()(_Iterator __it)
 { return !bool(_M_pred(*__it)); }
    };

  template<typename _Predicate>
    inline _Iter_negate<_Predicate>
    __negate(_Iter_pred<_Predicate> __pred)
    { return _Iter_negate<_Predicate>(std::move(__pred._M_pred)); }

}
}
# 72 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 2 3




namespace std __attribute__ ((__visibility__ ("default")))
{

# 121 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _ForwardIterator1, typename _ForwardIterator2>
    inline void
    iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)
    {

     

     
# 151 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
      swap(*__a, *__b);

    }
# 167 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _ForwardIterator1, typename _ForwardIterator2>
    _ForwardIterator2
    swap_ranges(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
  _ForwardIterator2 __first2)
    {

     

     

      ;

      for (; __first1 != __last1; ++__first1, (void)++__first2)
 std::iter_swap(__first1, __first2);
      return __first2;
    }
# 195 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _Tp>
    constexpr
    inline const _Tp&
    min(const _Tp& __a, const _Tp& __b)
    {

     

      if (__b < __a)
 return __b;
      return __a;
    }
# 219 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _Tp>
    constexpr
    inline const _Tp&
    max(const _Tp& __a, const _Tp& __b)
    {

     

      if (__a < __b)
 return __b;
      return __a;
    }
# 243 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _Tp, typename _Compare>
    constexpr
    inline const _Tp&
    min(const _Tp& __a, const _Tp& __b, _Compare __comp)
    {

      if (__comp(__b, __a))
 return __b;
      return __a;
    }
# 265 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _Tp, typename _Compare>
    constexpr
    inline const _Tp&
    max(const _Tp& __a, const _Tp& __b, _Compare __comp)
    {

      if (__comp(__a, __b))
 return __b;
      return __a;
    }



  template<typename _Iterator>
    inline _Iterator
    __niter_base(_Iterator __it)
    noexcept(std::is_nothrow_copy_constructible<_Iterator>::value)
    { return __it; }




  template<typename _From, typename _To>
    inline _From
    __niter_wrap(_From __from, _To __res)
    { return __from + (__res - std::__niter_base(__from)); }


  template<typename _Iterator>
    inline _Iterator
    __niter_wrap(const _Iterator&, _Iterator __res)
    { return __res; }







  template<bool, bool, typename>
    struct __copy_move
    {
      template<typename _II, typename _OI>
 static _OI
 __copy_m(_II __first, _II __last, _OI __result)
 {
   for (; __first != __last; ++__result, (void)++__first)
     *__result = *__first;
   return __result;
 }
    };


  template<typename _Category>
    struct __copy_move<true, false, _Category>
    {
      template<typename _II, typename _OI>
 static _OI
 __copy_m(_II __first, _II __last, _OI __result)
 {
   for (; __first != __last; ++__result, (void)++__first)
     *__result = std::move(*__first);
   return __result;
 }
    };


  template<>
    struct __copy_move<false, false, random_access_iterator_tag>
    {
      template<typename _II, typename _OI>
 static _OI
 __copy_m(_II __first, _II __last, _OI __result)
 {
   typedef typename iterator_traits<_II>::difference_type _Distance;
   for(_Distance __n = __last - __first; __n > 0; --__n)
     {
       *__result = *__first;
       ++__first;
       ++__result;
     }
   return __result;
 }
    };


  template<>
    struct __copy_move<true, false, random_access_iterator_tag>
    {
      template<typename _II, typename _OI>
 static _OI
 __copy_m(_II __first, _II __last, _OI __result)
 {
   typedef typename iterator_traits<_II>::difference_type _Distance;
   for(_Distance __n = __last - __first; __n > 0; --__n)
     {
       *__result = std::move(*__first);
       ++__first;
       ++__result;
     }
   return __result;
 }
    };


  template<bool _IsMove>
    struct __copy_move<_IsMove, true, random_access_iterator_tag>
    {
      template<typename _Tp>
 static _Tp*
 __copy_m(const _Tp* __first, const _Tp* __last, _Tp* __result)
 {

   using __assignable = conditional<_IsMove,
        is_move_assignable<_Tp>,
        is_copy_assignable<_Tp>>;

   static_assert( __assignable::type::value, "type is not assignable" );

   const ptrdiff_t _Num = __last - __first;
   if (_Num)
     __builtin_memmove(__result, __first, sizeof(_Tp) * _Num);
   return __result + _Num;
 }
    };

  template<bool _IsMove, typename _II, typename _OI>
    inline _OI
    __copy_move_a(_II __first, _II __last, _OI __result)
    {
      typedef typename iterator_traits<_II>::value_type _ValueTypeI;
      typedef typename iterator_traits<_OI>::value_type _ValueTypeO;
      typedef typename iterator_traits<_II>::iterator_category _Category;
      const bool __simple = (__is_trivially_copyable(_ValueTypeI)
        && __is_pointer<_II>::__value
        && __is_pointer<_OI>::__value
        && __are_same<_ValueTypeI, _ValueTypeO>::__value);

      return std::__copy_move<_IsMove, __simple,
         _Category>::__copy_m(__first, __last, __result);
    }



  template<typename _CharT>
    struct char_traits;

  template<typename _CharT, typename _Traits>
    class istreambuf_iterator;

  template<typename _CharT, typename _Traits>
    class ostreambuf_iterator;

  template<bool _IsMove, typename _CharT>
    typename __gnu_cxx::__enable_if<__is_char<_CharT>::__value,
      ostreambuf_iterator<_CharT, char_traits<_CharT> > >::__type
    __copy_move_a2(_CharT*, _CharT*,
     ostreambuf_iterator<_CharT, char_traits<_CharT> >);

  template<bool _IsMove, typename _CharT>
    typename __gnu_cxx::__enable_if<__is_char<_CharT>::__value,
      ostreambuf_iterator<_CharT, char_traits<_CharT> > >::__type
    __copy_move_a2(const _CharT*, const _CharT*,
     ostreambuf_iterator<_CharT, char_traits<_CharT> >);

  template<bool _IsMove, typename _CharT>
    typename __gnu_cxx::__enable_if<__is_char<_CharT>::__value,
        _CharT*>::__type
    __copy_move_a2(istreambuf_iterator<_CharT, char_traits<_CharT> >,
     istreambuf_iterator<_CharT, char_traits<_CharT> >, _CharT*);

  template<bool _IsMove, typename _II, typename _OI>
    inline _OI
    __copy_move_a2(_II __first, _II __last, _OI __result)
    {
      return std::__niter_wrap(__result,
  std::__copy_move_a<_IsMove>(std::__niter_base(__first),
         std::__niter_base(__last),
         std::__niter_base(__result)));
    }
# 463 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _II, typename _OI>
    inline _OI
    copy(_II __first, _II __last, _OI __result)
    {

     
     

      ;

      return std::__copy_move_a2<__is_move_iterator<_II>::__value>
      (std::__miter_base(__first), std::__miter_base(__last), __result);
    }
# 495 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _II, typename _OI>
    inline _OI
    move(_II __first, _II __last, _OI __result)
    {

     
     

      ;

      return std::__copy_move_a2<true>(std::__miter_base(__first),
           std::__miter_base(__last), __result);
    }






  template<bool, bool, typename>
    struct __copy_move_backward
    {
      template<typename _BI1, typename _BI2>
 static _BI2
 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result)
 {
   while (__first != __last)
     *--__result = *--__last;
   return __result;
 }
    };


  template<typename _Category>
    struct __copy_move_backward<true, false, _Category>
    {
      template<typename _BI1, typename _BI2>
 static _BI2
 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result)
 {
   while (__first != __last)
     *--__result = std::move(*--__last);
   return __result;
 }
    };


  template<>
    struct __copy_move_backward<false, false, random_access_iterator_tag>
    {
      template<typename _BI1, typename _BI2>
 static _BI2
 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result)
 {
   typename iterator_traits<_BI1>::difference_type __n;
   for (__n = __last - __first; __n > 0; --__n)
     *--__result = *--__last;
   return __result;
 }
    };


  template<>
    struct __copy_move_backward<true, false, random_access_iterator_tag>
    {
      template<typename _BI1, typename _BI2>
 static _BI2
 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result)
 {
   typename iterator_traits<_BI1>::difference_type __n;
   for (__n = __last - __first; __n > 0; --__n)
     *--__result = std::move(*--__last);
   return __result;
 }
    };


  template<bool _IsMove>
    struct __copy_move_backward<_IsMove, true, random_access_iterator_tag>
    {
      template<typename _Tp>
 static _Tp*
 __copy_move_b(const _Tp* __first, const _Tp* __last, _Tp* __result)
 {

   using __assignable = conditional<_IsMove,
        is_move_assignable<_Tp>,
        is_copy_assignable<_Tp>>;

   static_assert( __assignable::type::value, "type is not assignable" );

   const ptrdiff_t _Num = __last - __first;
   if (_Num)
     __builtin_memmove(__result - _Num, __first, sizeof(_Tp) * _Num);
   return __result - _Num;
 }
    };

  template<bool _IsMove, typename _BI1, typename _BI2>
    inline _BI2
    __copy_move_backward_a(_BI1 __first, _BI1 __last, _BI2 __result)
    {
      typedef typename iterator_traits<_BI1>::value_type _ValueType1;
      typedef typename iterator_traits<_BI2>::value_type _ValueType2;
      typedef typename iterator_traits<_BI1>::iterator_category _Category;
      const bool __simple = (__is_trivially_copyable(_ValueType1)
        && __is_pointer<_BI1>::__value
        && __is_pointer<_BI2>::__value
        && __are_same<_ValueType1, _ValueType2>::__value);

      return std::__copy_move_backward<_IsMove, __simple,
           _Category>::__copy_move_b(__first,
         __last,
         __result);
    }

  template<bool _IsMove, typename _BI1, typename _BI2>
    inline _BI2
    __copy_move_backward_a2(_BI1 __first, _BI1 __last, _BI2 __result)
    {
      return std::__niter_wrap(__result,
  std::__copy_move_backward_a<_IsMove>
    (std::__niter_base(__first), std::__niter_base(__last),
     std::__niter_base(__result)));
    }
# 639 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _BI1, typename _BI2>
    inline _BI2
    copy_backward(_BI1 __first, _BI1 __last, _BI2 __result)
    {

     
     
     


      ;

      return std::__copy_move_backward_a2<__is_move_iterator<_BI1>::__value>
      (std::__miter_base(__first), std::__miter_base(__last), __result);
    }
# 674 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _BI1, typename _BI2>
    inline _BI2
    move_backward(_BI1 __first, _BI1 __last, _BI2 __result)
    {

     
     
     


      ;

      return std::__copy_move_backward_a2<true>(std::__miter_base(__first),
      std::__miter_base(__last),
      __result);
    }






  template<typename _ForwardIterator, typename _Tp>
    inline typename
    __gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, void>::__type
    __fill_a(_ForwardIterator __first, _ForwardIterator __last,
       const _Tp& __value)
    {
      for (; __first != __last; ++__first)
 *__first = __value;
    }

  template<typename _ForwardIterator, typename _Tp>
    inline typename
    __gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, void>::__type
    __fill_a(_ForwardIterator __first, _ForwardIterator __last,
      const _Tp& __value)
    {
      const _Tp __tmp = __value;
      for (; __first != __last; ++__first)
 *__first = __tmp;
    }


  template<typename _Tp>
    inline typename
    __gnu_cxx::__enable_if<__is_byte<_Tp>::__value, void>::__type
    __fill_a(_Tp* __first, _Tp* __last, const _Tp& __c)
    {
      const _Tp __tmp = __c;
      if (const size_t __len = __last - __first)
 __builtin_memset(__first, static_cast<unsigned char>(__tmp), __len);
    }
# 740 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _ForwardIterator, typename _Tp>
    inline void
    fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value)
    {

     

      ;

      std::__fill_a(std::__niter_base(__first), std::__niter_base(__last),
      __value);
    }

  template<typename _OutputIterator, typename _Size, typename _Tp>
    inline typename
    __gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, _OutputIterator>::__type
    __fill_n_a(_OutputIterator __first, _Size __n, const _Tp& __value)
    {
      for (__decltype(__n + 0) __niter = __n;
    __niter > 0; --__niter, (void) ++__first)
 *__first = __value;
      return __first;
    }

  template<typename _OutputIterator, typename _Size, typename _Tp>
    inline typename
    __gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, _OutputIterator>::__type
    __fill_n_a(_OutputIterator __first, _Size __n, const _Tp& __value)
    {
      const _Tp __tmp = __value;
      for (__decltype(__n + 0) __niter = __n;
    __niter > 0; --__niter, (void) ++__first)
 *__first = __tmp;
      return __first;
    }

  template<typename _Size, typename _Tp>
    inline typename
    __gnu_cxx::__enable_if<__is_byte<_Tp>::__value, _Tp*>::__type
    __fill_n_a(_Tp* __first, _Size __n, const _Tp& __c)
    {
      std::__fill_a(__first, __first + __n, __c);
      return __first + __n;
    }
# 800 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _OI, typename _Size, typename _Tp>
    inline _OI
    fill_n(_OI __first, _Size __n, const _Tp& __value)
    {

     
      ;

      return std::__niter_wrap(__first,
  std::__fill_n_a(std::__niter_base(__first), __n, __value));
    }

  template<bool _BoolType>
    struct __equal
    {
      template<typename _II1, typename _II2>
 static bool
 equal(_II1 __first1, _II1 __last1, _II2 __first2)
 {
   for (; __first1 != __last1; ++__first1, (void) ++__first2)
     if (!(*__first1 == *__first2))
       return false;
   return true;
 }
    };

  template<>
    struct __equal<true>
    {
      template<typename _Tp>
 static bool
 equal(const _Tp* __first1, const _Tp* __last1, const _Tp* __first2)
 {
   if (const size_t __len = (__last1 - __first1))
     return !__builtin_memcmp(__first1, __first2, sizeof(_Tp) * __len);
   return true;
 }
    };

  template<typename _II1, typename _II2>
    inline bool
    __equal_aux(_II1 __first1, _II1 __last1, _II2 __first2)
    {
      typedef typename iterator_traits<_II1>::value_type _ValueType1;
      typedef typename iterator_traits<_II2>::value_type _ValueType2;
      const bool __simple = ((__is_integer<_ValueType1>::__value
         || __is_pointer<_ValueType1>::__value)
        && __is_pointer<_II1>::__value
        && __is_pointer<_II2>::__value
        && __are_same<_ValueType1, _ValueType2>::__value);

      return std::__equal<__simple>::equal(__first1, __last1, __first2);
    }

  template<typename, typename>
    struct __lc_rai
    {
      template<typename _II1, typename _II2>
 static _II1
 __newlast1(_II1, _II1 __last1, _II2, _II2)
 { return __last1; }

      template<typename _II>
 static bool
 __cnd2(_II __first, _II __last)
 { return __first != __last; }
    };

  template<>
    struct __lc_rai<random_access_iterator_tag, random_access_iterator_tag>
    {
      template<typename _RAI1, typename _RAI2>
 static _RAI1
 __newlast1(_RAI1 __first1, _RAI1 __last1,
     _RAI2 __first2, _RAI2 __last2)
 {
   const typename iterator_traits<_RAI1>::difference_type
     __diff1 = __last1 - __first1;
   const typename iterator_traits<_RAI2>::difference_type
     __diff2 = __last2 - __first2;
   return __diff2 < __diff1 ? __first1 + __diff2 : __last1;
 }

      template<typename _RAI>
 static bool
 __cnd2(_RAI, _RAI)
 { return true; }
    };

  template<typename _II1, typename _II2, typename _Compare>
    bool
    __lexicographical_compare_impl(_II1 __first1, _II1 __last1,
       _II2 __first2, _II2 __last2,
       _Compare __comp)
    {
      typedef typename iterator_traits<_II1>::iterator_category _Category1;
      typedef typename iterator_traits<_II2>::iterator_category _Category2;
      typedef std::__lc_rai<_Category1, _Category2> __rai_type;

      __last1 = __rai_type::__newlast1(__first1, __last1, __first2, __last2);
      for (; __first1 != __last1 && __rai_type::__cnd2(__first2, __last2);
    ++__first1, (void)++__first2)
 {
   if (__comp(__first1, __first2))
     return true;
   if (__comp(__first2, __first1))
     return false;
 }
      return __first1 == __last1 && __first2 != __last2;
    }

  template<bool _BoolType>
    struct __lexicographical_compare
    {
      template<typename _II1, typename _II2>
 static bool __lc(_II1, _II1, _II2, _II2);
    };

  template<bool _BoolType>
    template<typename _II1, typename _II2>
      bool
      __lexicographical_compare<_BoolType>::
      __lc(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2)
      {
 return std::__lexicographical_compare_impl(__first1, __last1,
         __first2, __last2,
     __gnu_cxx::__ops::__iter_less_iter());
      }

  template<>
    struct __lexicographical_compare<true>
    {
      template<typename _Tp, typename _Up>
 static bool
 __lc(const _Tp* __first1, const _Tp* __last1,
      const _Up* __first2, const _Up* __last2)
 {
   const size_t __len1 = __last1 - __first1;
   const size_t __len2 = __last2 - __first2;
   if (const size_t __len = std::min(__len1, __len2))
     if (int __result = __builtin_memcmp(__first1, __first2, __len))
       return __result < 0;
   return __len1 < __len2;
 }
    };

  template<typename _II1, typename _II2>
    inline bool
    __lexicographical_compare_aux(_II1 __first1, _II1 __last1,
      _II2 __first2, _II2 __last2)
    {
      typedef typename iterator_traits<_II1>::value_type _ValueType1;
      typedef typename iterator_traits<_II2>::value_type _ValueType2;
      const bool __simple =
 (__is_byte<_ValueType1>::__value && __is_byte<_ValueType2>::__value
  && !__gnu_cxx::__numeric_traits<_ValueType1>::__is_signed
  && !__gnu_cxx::__numeric_traits<_ValueType2>::__is_signed
  && __is_pointer<_II1>::__value
  && __is_pointer<_II2>::__value);

      return std::__lexicographical_compare<__simple>::__lc(__first1, __last1,
           __first2, __last2);
    }

  template<typename _ForwardIterator, typename _Tp, typename _Compare>
    _ForwardIterator
    __lower_bound(_ForwardIterator __first, _ForwardIterator __last,
    const _Tp& __val, _Compare __comp)
    {
      typedef typename iterator_traits<_ForwardIterator>::difference_type
 _DistanceType;

      _DistanceType __len = std::distance(__first, __last);

      while (__len > 0)
 {
   _DistanceType __half = __len >> 1;
   _ForwardIterator __middle = __first;
   std::advance(__middle, __half);
   if (__comp(__middle, __val))
     {
       __first = __middle;
       ++__first;
       __len = __len - __half - 1;
     }
   else
     __len = __half;
 }
      return __first;
    }
# 1002 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _ForwardIterator, typename _Tp>
    inline _ForwardIterator
    lower_bound(_ForwardIterator __first, _ForwardIterator __last,
  const _Tp& __val)
    {

     
     

      ;

      return std::__lower_bound(__first, __last, __val,
    __gnu_cxx::__ops::__iter_less_val());
    }



  inline constexpr int
  __lg(int __n)
  { return (int)sizeof(int) * 8 - 1 - __builtin_clz(__n); }

  inline constexpr unsigned
  __lg(unsigned __n)
  { return (int)sizeof(int) * 8 - 1 - __builtin_clz(__n); }

  inline constexpr long
  __lg(long __n)
  { return (int)sizeof(long) * 8 - 1 - __builtin_clzl(__n); }

  inline constexpr unsigned long
  __lg(unsigned long __n)
  { return (int)sizeof(long) * 8 - 1 - __builtin_clzl(__n); }

  inline constexpr long long
  __lg(long long __n)
  { return (int)sizeof(long long) * 8 - 1 - __builtin_clzll(__n); }

  inline constexpr unsigned long long
  __lg(unsigned long long __n)
  { return (int)sizeof(long long) * 8 - 1 - __builtin_clzll(__n); }


# 1057 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _II1, typename _II2>
    inline bool
    equal(_II1 __first1, _II1 __last1, _II2 __first2)
    {

     
     
     


      ;

      return std::__equal_aux(std::__niter_base(__first1),
         std::__niter_base(__last1),
         std::__niter_base(__first2));
    }
# 1089 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _IIter1, typename _IIter2, typename _BinaryPredicate>
    inline bool
    equal(_IIter1 __first1, _IIter1 __last1,
   _IIter2 __first2, _BinaryPredicate __binary_pred)
    {

     
     
      ;

      for (; __first1 != __last1; ++__first1, (void)++__first2)
 if (!bool(__binary_pred(*__first1, *__first2)))
   return false;
      return true;
    }



  template<typename _II1, typename _II2>
    inline bool
    __equal4(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2)
    {
      using _RATag = random_access_iterator_tag;
      using _Cat1 = typename iterator_traits<_II1>::iterator_category;
      using _Cat2 = typename iterator_traits<_II2>::iterator_category;
      using _RAIters = __and_<is_same<_Cat1, _RATag>, is_same<_Cat2, _RATag>>;
      if (_RAIters())
 {
   auto __d1 = std::distance(__first1, __last1);
   auto __d2 = std::distance(__first2, __last2);
   if (__d1 != __d2)
     return false;
   return std::equal(__first1, __last1, __first2);
 }

      for (; __first1 != __last1 && __first2 != __last2;
   ++__first1, (void)++__first2)
 if (!(*__first1 == *__first2))
   return false;
      return __first1 == __last1 && __first2 == __last2;
    }


  template<typename _II1, typename _II2, typename _BinaryPredicate>
    inline bool
    __equal4(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2,
      _BinaryPredicate __binary_pred)
    {
      using _RATag = random_access_iterator_tag;
      using _Cat1 = typename iterator_traits<_II1>::iterator_category;
      using _Cat2 = typename iterator_traits<_II2>::iterator_category;
      using _RAIters = __and_<is_same<_Cat1, _RATag>, is_same<_Cat2, _RATag>>;
      if (_RAIters())
 {
   auto __d1 = std::distance(__first1, __last1);
   auto __d2 = std::distance(__first2, __last2);
   if (__d1 != __d2)
     return false;
   return std::equal(__first1, __last1, __first2,
           __binary_pred);
 }

      for (; __first1 != __last1 && __first2 != __last2;
   ++__first1, (void)++__first2)
 if (!bool(__binary_pred(*__first1, *__first2)))
   return false;
      return __first1 == __last1 && __first2 == __last2;
    }
# 1176 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _II1, typename _II2>
    inline bool
    equal(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2)
    {

     
     
     


      ;
      ;

      return std::__equal4(__first1, __last1, __first2, __last2);
    }
# 1208 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _IIter1, typename _IIter2, typename _BinaryPredicate>
    inline bool
    equal(_IIter1 __first1, _IIter1 __last1,
   _IIter2 __first2, _IIter2 __last2, _BinaryPredicate __binary_pred)
    {

     
     
      ;
      ;

      return std::__equal4(__first1, __last1, __first2, __last2,
          __binary_pred);
    }
# 1239 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _II1, typename _II2>
    inline bool
    lexicographical_compare(_II1 __first1, _II1 __last1,
       _II2 __first2, _II2 __last2)
    {





     
     
     
     
      ;
      ;

      return std::__lexicographical_compare_aux(std::__niter_base(__first1),
      std::__niter_base(__last1),
      std::__niter_base(__first2),
      std::__niter_base(__last2));
    }
# 1275 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _II1, typename _II2, typename _Compare>
    inline bool
    lexicographical_compare(_II1 __first1, _II1 __last1,
       _II2 __first2, _II2 __last2, _Compare __comp)
    {

     
     
      ;
      ;

      return std::__lexicographical_compare_impl
 (__first1, __last1, __first2, __last2,
  __gnu_cxx::__ops::__iter_comp_iter(__comp));
    }

  template<typename _InputIterator1, typename _InputIterator2,
    typename _BinaryPredicate>
    pair<_InputIterator1, _InputIterator2>
    __mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
        _InputIterator2 __first2, _BinaryPredicate __binary_pred)
    {
      while (__first1 != __last1 && __binary_pred(__first1, __first2))
 {
   ++__first1;
   ++__first2;
 }
      return pair<_InputIterator1, _InputIterator2>(__first1, __first2);
    }
# 1318 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _InputIterator1, typename _InputIterator2>
    inline pair<_InputIterator1, _InputIterator2>
    mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2)
    {

     
     
     


      ;

      return std::__mismatch(__first1, __last1, __first2,
        __gnu_cxx::__ops::__iter_equal_to_iter());
    }
# 1351 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _InputIterator1, typename _InputIterator2,
    typename _BinaryPredicate>
    inline pair<_InputIterator1, _InputIterator2>
    mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _BinaryPredicate __binary_pred)
    {

     
     
      ;

      return std::__mismatch(__first1, __last1, __first2,
 __gnu_cxx::__ops::__iter_comp_iter(__binary_pred));
    }



  template<typename _InputIterator1, typename _InputIterator2,
    typename _BinaryPredicate>
    pair<_InputIterator1, _InputIterator2>
    __mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
        _InputIterator2 __first2, _InputIterator2 __last2,
        _BinaryPredicate __binary_pred)
    {
      while (__first1 != __last1 && __first2 != __last2
      && __binary_pred(__first1, __first2))
 {
   ++__first1;
   ++__first2;
 }
      return pair<_InputIterator1, _InputIterator2>(__first1, __first2);
    }
# 1398 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _InputIterator1, typename _InputIterator2>
    inline pair<_InputIterator1, _InputIterator2>
    mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2)
    {

     
     
     


      ;
      ;

      return std::__mismatch(__first1, __last1, __first2, __last2,
        __gnu_cxx::__ops::__iter_equal_to_iter());
    }
# 1433 "/usr/include/c++/9.2.0/bits/stl_algobase.h" 3
  template<typename _InputIterator1, typename _InputIterator2,
    typename _BinaryPredicate>
    inline pair<_InputIterator1, _InputIterator2>
    mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _BinaryPredicate __binary_pred)
    {

     
     
      ;
      ;

      return std::__mismatch(__first1, __last1, __first2, __last2,
        __gnu_cxx::__ops::__iter_comp_iter(__binary_pred));
    }




}
# 40 "/usr/include/c++/9.2.0/bits/char_traits.h" 2 3
# 1 "/usr/include/c++/9.2.0/bits/postypes.h" 1 3
# 38 "/usr/include/c++/9.2.0/bits/postypes.h" 3
       
# 39 "/usr/include/c++/9.2.0/bits/postypes.h" 3

# 1 "/usr/include/c++/9.2.0/cwchar" 1 3
# 39 "/usr/include/c++/9.2.0/cwchar" 3
       
# 40 "/usr/include/c++/9.2.0/cwchar" 3




# 1 "/usr/include/wchar.h" 1 3 4
# 27 "/usr/include/wchar.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 28 "/usr/include/wchar.h" 2 3 4


# 1 "/usr/include/bits/floatn.h" 1 3 4
# 74 "/usr/include/bits/floatn.h" 3 4
typedef _Complex float __cfloat128 __attribute__ ((__mode__ (__TC__)));
# 86 "/usr/include/bits/floatn.h" 3 4
typedef __float128 _Float128;
# 119 "/usr/include/bits/floatn.h" 3 4
# 1 "/usr/include/bits/floatn-common.h" 1 3 4
# 24 "/usr/include/bits/floatn-common.h" 3 4
# 1 "/usr/include/bits/long-double.h" 1 3 4
# 25 "/usr/include/bits/floatn-common.h" 2 3 4
# 214 "/usr/include/bits/floatn-common.h" 3 4
typedef float _Float32;
# 251 "/usr/include/bits/floatn-common.h" 3 4
typedef double _Float64;
# 268 "/usr/include/bits/floatn-common.h" 3 4
typedef double _Float32x;
# 285 "/usr/include/bits/floatn-common.h" 3 4
typedef long double _Float64x;
# 120 "/usr/include/bits/floatn.h" 2 3 4
# 31 "/usr/include/wchar.h" 2 3 4




# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 1 3 4
# 36 "/usr/include/wchar.h" 2 3 4


# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 39 "/usr/include/wchar.h" 2 3 4

# 1 "/usr/include/bits/wchar.h" 1 3 4
# 41 "/usr/include/wchar.h" 2 3 4
# 1 "/usr/include/bits/types/wint_t.h" 1 3 4
# 20 "/usr/include/bits/types/wint_t.h" 3 4
typedef unsigned int wint_t;
# 42 "/usr/include/wchar.h" 2 3 4
# 1 "/usr/include/bits/types/mbstate_t.h" 1 3 4



# 1 "/usr/include/bits/types/__mbstate_t.h" 1 3 4
# 13 "/usr/include/bits/types/__mbstate_t.h" 3 4
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 5 "/usr/include/bits/types/mbstate_t.h" 2 3 4

typedef __mbstate_t mbstate_t;
# 43 "/usr/include/wchar.h" 2 3 4
# 1 "/usr/include/bits/types/__FILE.h" 1 3 4



struct _IO_FILE;
typedef struct _IO_FILE __FILE;
# 44 "/usr/include/wchar.h" 2 3 4


# 1 "/usr/include/bits/types/FILE.h" 1 3 4



struct _IO_FILE;


typedef struct _IO_FILE FILE;
# 47 "/usr/include/wchar.h" 2 3 4
# 79 "/usr/include/wchar.h" 3 4
extern "C" {



struct tm;



extern wchar_t *wcscpy (wchar_t *__restrict __dest,
   const wchar_t *__restrict __src)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern wchar_t *wcsncpy (wchar_t *__restrict __dest,
    const wchar_t *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern wchar_t *wcscat (wchar_t *__restrict __dest,
   const wchar_t *__restrict __src)
     throw () __attribute__ ((__nonnull__ (1, 2)));

extern wchar_t *wcsncat (wchar_t *__restrict __dest,
    const wchar_t *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int wcscmp (const wchar_t *__s1, const wchar_t *__s2)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int wcsncmp (const wchar_t *__s1, const wchar_t *__s2, size_t __n)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));



extern int wcscasecmp (const wchar_t *__s1, const wchar_t *__s2) throw ();


extern int wcsncasecmp (const wchar_t *__s1, const wchar_t *__s2,
   size_t __n) throw ();



extern int wcscasecmp_l (const wchar_t *__s1, const wchar_t *__s2,
    locale_t __loc) throw ();

extern int wcsncasecmp_l (const wchar_t *__s1, const wchar_t *__s2,
     size_t __n, locale_t __loc) throw ();




extern int wcscoll (const wchar_t *__s1, const wchar_t *__s2) throw ();



extern size_t wcsxfrm (wchar_t *__restrict __s1,
         const wchar_t *__restrict __s2, size_t __n) throw ();







extern int wcscoll_l (const wchar_t *__s1, const wchar_t *__s2,
        locale_t __loc) throw ();




extern size_t wcsxfrm_l (wchar_t *__s1, const wchar_t *__s2,
    size_t __n, locale_t __loc) throw ();


extern wchar_t *wcsdup (const wchar_t *__s) throw () __attribute__ ((__malloc__));




extern "C++" wchar_t *wcschr (wchar_t *__wcs, wchar_t __wc)
     throw () __asm ("wcschr") __attribute__ ((__pure__));
extern "C++" const wchar_t *wcschr (const wchar_t *__wcs, wchar_t __wc)
     throw () __asm ("wcschr") __attribute__ ((__pure__));






extern "C++" wchar_t *wcsrchr (wchar_t *__wcs, wchar_t __wc)
     throw () __asm ("wcsrchr") __attribute__ ((__pure__));
extern "C++" const wchar_t *wcsrchr (const wchar_t *__wcs, wchar_t __wc)
     throw () __asm ("wcsrchr") __attribute__ ((__pure__));
# 181 "/usr/include/wchar.h" 3 4
extern wchar_t *wcschrnul (const wchar_t *__s, wchar_t __wc)
     throw () __attribute__ ((__pure__));




extern size_t wcscspn (const wchar_t *__wcs, const wchar_t *__reject)
     throw () __attribute__ ((__pure__));


extern size_t wcsspn (const wchar_t *__wcs, const wchar_t *__accept)
     throw () __attribute__ ((__pure__));


extern "C++" wchar_t *wcspbrk (wchar_t *__wcs, const wchar_t *__accept)
     throw () __asm ("wcspbrk") __attribute__ ((__pure__));
extern "C++" const wchar_t *wcspbrk (const wchar_t *__wcs,
         const wchar_t *__accept)
     throw () __asm ("wcspbrk") __attribute__ ((__pure__));






extern "C++" wchar_t *wcsstr (wchar_t *__haystack, const wchar_t *__needle)
     throw () __asm ("wcsstr") __attribute__ ((__pure__));
extern "C++" const wchar_t *wcsstr (const wchar_t *__haystack,
        const wchar_t *__needle)
     throw () __asm ("wcsstr") __attribute__ ((__pure__));






extern wchar_t *wcstok (wchar_t *__restrict __s,
   const wchar_t *__restrict __delim,
   wchar_t **__restrict __ptr) throw ();


extern size_t wcslen (const wchar_t *__s) throw () __attribute__ ((__pure__));




extern "C++" wchar_t *wcswcs (wchar_t *__haystack, const wchar_t *__needle)
     throw () __asm ("wcswcs") __attribute__ ((__pure__));
extern "C++" const wchar_t *wcswcs (const wchar_t *__haystack,
        const wchar_t *__needle)
     throw () __asm ("wcswcs") __attribute__ ((__pure__));
# 240 "/usr/include/wchar.h" 3 4
extern size_t wcsnlen (const wchar_t *__s, size_t __maxlen)
     throw () __attribute__ ((__pure__));





extern "C++" wchar_t *wmemchr (wchar_t *__s, wchar_t __c, size_t __n)
     throw () __asm ("wmemchr") __attribute__ ((__pure__));
extern "C++" const wchar_t *wmemchr (const wchar_t *__s, wchar_t __c,
         size_t __n)
     throw () __asm ("wmemchr") __attribute__ ((__pure__));






extern int wmemcmp (const wchar_t *__s1, const wchar_t *__s2, size_t __n)
     throw () __attribute__ ((__pure__));


extern wchar_t *wmemcpy (wchar_t *__restrict __s1,
    const wchar_t *__restrict __s2, size_t __n) throw ();



extern wchar_t *wmemmove (wchar_t *__s1, const wchar_t *__s2, size_t __n)
     throw ();


extern wchar_t *wmemset (wchar_t *__s, wchar_t __c, size_t __n) throw ();




extern wchar_t *wmempcpy (wchar_t *__restrict __s1,
     const wchar_t *__restrict __s2, size_t __n)
     throw ();





extern wint_t btowc (int __c) throw ();



extern int wctob (wint_t __c) throw ();



extern int mbsinit (const mbstate_t *__ps) throw () __attribute__ ((__pure__));



extern size_t mbrtowc (wchar_t *__restrict __pwc,
         const char *__restrict __s, size_t __n,
         mbstate_t *__restrict __p) throw ();


extern size_t wcrtomb (char *__restrict __s, wchar_t __wc,
         mbstate_t *__restrict __ps) throw ();


extern size_t __mbrlen (const char *__restrict __s, size_t __n,
   mbstate_t *__restrict __ps) throw ();
extern size_t mbrlen (const char *__restrict __s, size_t __n,
        mbstate_t *__restrict __ps) throw ();
# 337 "/usr/include/wchar.h" 3 4
extern size_t mbsrtowcs (wchar_t *__restrict __dst,
    const char **__restrict __src, size_t __len,
    mbstate_t *__restrict __ps) throw ();



extern size_t wcsrtombs (char *__restrict __dst,
    const wchar_t **__restrict __src, size_t __len,
    mbstate_t *__restrict __ps) throw ();





extern size_t mbsnrtowcs (wchar_t *__restrict __dst,
     const char **__restrict __src, size_t __nmc,
     size_t __len, mbstate_t *__restrict __ps) throw ();



extern size_t wcsnrtombs (char *__restrict __dst,
     const wchar_t **__restrict __src,
     size_t __nwc, size_t __len,
     mbstate_t *__restrict __ps) throw ();






extern int wcwidth (wchar_t __c) throw ();



extern int wcswidth (const wchar_t *__s, size_t __n) throw ();





extern double wcstod (const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr) throw ();



extern float wcstof (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) throw ();
extern long double wcstold (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) throw ();
# 396 "/usr/include/wchar.h" 3 4
extern _Float32 wcstof32 (const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr) throw ();



extern _Float64 wcstof64 (const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr) throw ();



extern _Float128 wcstof128 (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) throw ();



extern _Float32x wcstof32x (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) throw ();



extern _Float64x wcstof64x (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) throw ();
# 428 "/usr/include/wchar.h" 3 4
extern long int wcstol (const wchar_t *__restrict __nptr,
   wchar_t **__restrict __endptr, int __base) throw ();



extern unsigned long int wcstoul (const wchar_t *__restrict __nptr,
      wchar_t **__restrict __endptr, int __base)
     throw ();




__extension__
extern long long int wcstoll (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr, int __base)
     throw ();



__extension__
extern unsigned long long int wcstoull (const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr,
     int __base) throw ();





__extension__
extern long long int wcstoq (const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr, int __base)
     throw ();



__extension__
extern unsigned long long int wcstouq (const wchar_t *__restrict __nptr,
           wchar_t **__restrict __endptr,
           int __base) throw ();






extern long int wcstol_l (const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr, int __base,
     locale_t __loc) throw ();

extern unsigned long int wcstoul_l (const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr,
        int __base, locale_t __loc) throw ();

__extension__
extern long long int wcstoll_l (const wchar_t *__restrict __nptr,
    wchar_t **__restrict __endptr,
    int __base, locale_t __loc) throw ();

__extension__
extern unsigned long long int wcstoull_l (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr,
       int __base, locale_t __loc)
     throw ();

extern double wcstod_l (const wchar_t *__restrict __nptr,
   wchar_t **__restrict __endptr, locale_t __loc)
     throw ();

extern float wcstof_l (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr, locale_t __loc)
     throw ();

extern long double wcstold_l (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr,
         locale_t __loc) throw ();
# 511 "/usr/include/wchar.h" 3 4
extern _Float32 wcstof32_l (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr,
       locale_t __loc) throw ();



extern _Float64 wcstof64_l (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr,
       locale_t __loc) throw ();



extern _Float128 wcstof128_l (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr,
         locale_t __loc) throw ();



extern _Float32x wcstof32x_l (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr,
         locale_t __loc) throw ();



extern _Float64x wcstof64x_l (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr,
         locale_t __loc) throw ();
# 551 "/usr/include/wchar.h" 3 4
extern wchar_t *wcpcpy (wchar_t *__restrict __dest,
   const wchar_t *__restrict __src) throw ();



extern wchar_t *wcpncpy (wchar_t *__restrict __dest,
    const wchar_t *__restrict __src, size_t __n)
     throw ();
# 567 "/usr/include/wchar.h" 3 4
extern __FILE *open_wmemstream (wchar_t **__bufloc, size_t *__sizeloc) throw ();





extern int fwide (__FILE *__fp, int __mode) throw ();






extern int fwprintf (__FILE *__restrict __stream,
       const wchar_t *__restrict __format, ...)
                                                           ;




extern int wprintf (const wchar_t *__restrict __format, ...)
                                                           ;

extern int swprintf (wchar_t *__restrict __s, size_t __n,
       const wchar_t *__restrict __format, ...)
     throw () ;





extern int vfwprintf (__FILE *__restrict __s,
        const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
                                                           ;




extern int vwprintf (const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                           ;


extern int vswprintf (wchar_t *__restrict __s, size_t __n,
        const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
     throw () ;






extern int fwscanf (__FILE *__restrict __stream,
      const wchar_t *__restrict __format, ...)
                                                          ;




extern int wscanf (const wchar_t *__restrict __format, ...)
                                                          ;

extern int swscanf (const wchar_t *__restrict __s,
      const wchar_t *__restrict __format, ...)
     throw () ;






extern int fwscanf (__FILE *__restrict __stream, const wchar_t *__restrict __format, ...) __asm__ ("" "__isoc99_fwscanf")


                                                          ;
extern int wscanf (const wchar_t *__restrict __format, ...) __asm__ ("" "__isoc99_wscanf")

                                                          ;
extern int swscanf (const wchar_t *__restrict __s, const wchar_t *__restrict __format, ...) throw () __asm__ ("" "__isoc99_swscanf")


                                                          ;
# 671 "/usr/include/wchar.h" 3 4
extern int vfwscanf (__FILE *__restrict __s,
       const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                          ;




extern int vwscanf (const wchar_t *__restrict __format,
      __gnuc_va_list __arg)
                                                          ;

extern int vswscanf (const wchar_t *__restrict __s,
       const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
     throw () ;
# 725 "/usr/include/wchar.h" 3 4
extern wint_t fgetwc (__FILE *__stream);
extern wint_t getwc (__FILE *__stream);





extern wint_t getwchar (void);






extern wint_t fputwc (wchar_t __wc, __FILE *__stream);
extern wint_t putwc (wchar_t __wc, __FILE *__stream);





extern wint_t putwchar (wchar_t __wc);







extern wchar_t *fgetws (wchar_t *__restrict __ws, int __n,
   __FILE *__restrict __stream);





extern int fputws (const wchar_t *__restrict __ws,
     __FILE *__restrict __stream);






extern wint_t ungetwc (wint_t __wc, __FILE *__stream);
# 780 "/usr/include/wchar.h" 3 4
extern wint_t getwc_unlocked (__FILE *__stream);
extern wint_t getwchar_unlocked (void);







extern wint_t fgetwc_unlocked (__FILE *__stream);







extern wint_t fputwc_unlocked (wchar_t __wc, __FILE *__stream);
# 806 "/usr/include/wchar.h" 3 4
extern wint_t putwc_unlocked (wchar_t __wc, __FILE *__stream);
extern wint_t putwchar_unlocked (wchar_t __wc);
# 816 "/usr/include/wchar.h" 3 4
extern wchar_t *fgetws_unlocked (wchar_t *__restrict __ws, int __n,
     __FILE *__restrict __stream);







extern int fputws_unlocked (const wchar_t *__restrict __ws,
       __FILE *__restrict __stream);






extern size_t wcsftime (wchar_t *__restrict __s, size_t __maxsize,
   const wchar_t *__restrict __format,
   const struct tm *__restrict __tp) throw ();




extern size_t wcsftime_l (wchar_t *__restrict __s, size_t __maxsize,
     const wchar_t *__restrict __format,
     const struct tm *__restrict __tp,
     locale_t __loc) throw ();
# 855 "/usr/include/wchar.h" 3 4
}
# 45 "/usr/include/c++/9.2.0/cwchar" 2 3
# 62 "/usr/include/c++/9.2.0/cwchar" 3
namespace std
{
  using ::mbstate_t;
}
# 135 "/usr/include/c++/9.2.0/cwchar" 3
extern "C++"
{
namespace std __attribute__ ((__visibility__ ("default")))
{


  using ::wint_t;

  using ::btowc;
  using ::fgetwc;
  using ::fgetws;
  using ::fputwc;
  using ::fputws;
  using ::fwide;
  using ::fwprintf;
  using ::fwscanf;
  using ::getwc;
  using ::getwchar;
  using ::mbrlen;
  using ::mbrtowc;
  using ::mbsinit;
  using ::mbsrtowcs;
  using ::putwc;
  using ::putwchar;

  using ::swprintf;

  using ::swscanf;
  using ::ungetwc;
  using ::vfwprintf;

  using ::vfwscanf;


  using ::vswprintf;


  using ::vswscanf;

  using ::vwprintf;

  using ::vwscanf;

  using ::wcrtomb;
  using ::wcscat;
  using ::wcscmp;
  using ::wcscoll;
  using ::wcscpy;
  using ::wcscspn;
  using ::wcsftime;
  using ::wcslen;
  using ::wcsncat;
  using ::wcsncmp;
  using ::wcsncpy;
  using ::wcsrtombs;
  using ::wcsspn;
  using ::wcstod;

  using ::wcstof;

  using ::wcstok;
  using ::wcstol;
  using ::wcstoul;
  using ::wcsxfrm;
  using ::wctob;
  using ::wmemcmp;
  using ::wmemcpy;
  using ::wmemmove;
  using ::wmemset;
  using ::wprintf;
  using ::wscanf;
  using ::wcschr;
  using ::wcspbrk;
  using ::wcsrchr;
  using ::wcsstr;
  using ::wmemchr;
# 234 "/usr/include/c++/9.2.0/cwchar" 3

}
}







namespace __gnu_cxx
{





  using ::wcstold;
# 260 "/usr/include/c++/9.2.0/cwchar" 3
  using ::wcstoll;
  using ::wcstoull;

}

namespace std
{
  using ::__gnu_cxx::wcstold;
  using ::__gnu_cxx::wcstoll;
  using ::__gnu_cxx::wcstoull;
}
# 280 "/usr/include/c++/9.2.0/cwchar" 3
namespace std
{

  using std::wcstof;


  using std::vfwscanf;


  using std::vswscanf;


  using std::vwscanf;



  using std::wcstold;
  using std::wcstoll;
  using std::wcstoull;

}
# 41 "/usr/include/c++/9.2.0/bits/postypes.h" 2 3
# 68 "/usr/include/c++/9.2.0/bits/postypes.h" 3
namespace std __attribute__ ((__visibility__ ("default")))
{

# 88 "/usr/include/c++/9.2.0/bits/postypes.h" 3
  typedef long streamoff;
# 98 "/usr/include/c++/9.2.0/bits/postypes.h" 3
  typedef ptrdiff_t streamsize;
# 111 "/usr/include/c++/9.2.0/bits/postypes.h" 3
  template<typename _StateT>
    class fpos
    {
    private:
      streamoff _M_off;
      _StateT _M_state;

    public:




      fpos()
      : _M_off(0), _M_state() { }
# 133 "/usr/include/c++/9.2.0/bits/postypes.h" 3
      fpos(streamoff __off)
      : _M_off(__off), _M_state() { }


      fpos(const fpos&) = default;
      fpos& operator=(const fpos&) = default;
      ~fpos() = default;



      operator streamoff() const { return _M_off; }


      void
      state(_StateT __st)
      { _M_state = __st; }


      _StateT
      state() const
      { return _M_state; }





      fpos&
      operator+=(streamoff __off)
      {
 _M_off += __off;
 return *this;
      }





      fpos&
      operator-=(streamoff __off)
      {
 _M_off -= __off;
 return *this;
      }







      fpos
      operator+(streamoff __off) const
      {
 fpos __pos(*this);
 __pos += __off;
 return __pos;
      }







      fpos
      operator-(streamoff __off) const
      {
 fpos __pos(*this);
 __pos -= __off;
 return __pos;
      }






      streamoff
      operator-(const fpos& __other) const
      { return _M_off - __other._M_off; }
    };






  template<typename _StateT>
    inline bool
    operator==(const fpos<_StateT>& __lhs, const fpos<_StateT>& __rhs)
    { return streamoff(__lhs) == streamoff(__rhs); }

  template<typename _StateT>
    inline bool
    operator!=(const fpos<_StateT>& __lhs, const fpos<_StateT>& __rhs)
    { return streamoff(__lhs) != streamoff(__rhs); }





  typedef fpos<mbstate_t> streampos;

  typedef fpos<mbstate_t> wstreampos;
# 245 "/usr/include/c++/9.2.0/bits/postypes.h" 3
  typedef fpos<mbstate_t> u16streampos;

  typedef fpos<mbstate_t> u32streampos;



}
# 41 "/usr/include/c++/9.2.0/bits/char_traits.h" 2 3
# 1 "/usr/include/c++/9.2.0/cwchar" 1 3
# 39 "/usr/include/c++/9.2.0/cwchar" 3
       
# 40 "/usr/include/c++/9.2.0/cwchar" 3
# 42 "/usr/include/c++/9.2.0/bits/char_traits.h" 2 3





namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{

# 61 "/usr/include/c++/9.2.0/bits/char_traits.h" 3
  template<typename _CharT>
    struct _Char_types
    {
      typedef unsigned long int_type;
      typedef std::streampos pos_type;
      typedef std::streamoff off_type;
      typedef std::mbstate_t state_type;
    };
# 86 "/usr/include/c++/9.2.0/bits/char_traits.h" 3
  template<typename _CharT>
    struct char_traits
    {
      typedef _CharT char_type;
      typedef typename _Char_types<_CharT>::int_type int_type;
      typedef typename _Char_types<_CharT>::pos_type pos_type;
      typedef typename _Char_types<_CharT>::off_type off_type;
      typedef typename _Char_types<_CharT>::state_type state_type;

      static constexpr void
      assign(char_type& __c1, const char_type& __c2)
      { __c1 = __c2; }

      static constexpr bool
      eq(const char_type& __c1, const char_type& __c2)
      { return __c1 == __c2; }

      static constexpr bool
      lt(const char_type& __c1, const char_type& __c2)
      { return __c1 < __c2; }

      static constexpr int
      compare(const char_type* __s1, const char_type* __s2, std::size_t __n);

      static constexpr std::size_t
      length(const char_type* __s);

      static constexpr const char_type*
      find(const char_type* __s, std::size_t __n, const char_type& __a);

      static char_type*
      move(char_type* __s1, const char_type* __s2, std::size_t __n);

      static char_type*
      copy(char_type* __s1, const char_type* __s2, std::size_t __n);

      static char_type*
      assign(char_type* __s, std::size_t __n, char_type __a);

      static constexpr char_type
      to_char_type(const int_type& __c)
      { return static_cast<char_type>(__c); }

      static constexpr int_type
      to_int_type(const char_type& __c)
      { return static_cast<int_type>(__c); }

      static constexpr bool
      eq_int_type(const int_type& __c1, const int_type& __c2)
      { return __c1 == __c2; }

      static constexpr int_type
      eof()
      { return static_cast<int_type>(-1); }

      static constexpr int_type
      not_eof(const int_type& __c)
      { return !eq_int_type(__c, eof()) ? __c : to_int_type(char_type()); }
    };

  template<typename _CharT>
    constexpr int
    char_traits<_CharT>::
    compare(const char_type* __s1, const char_type* __s2, std::size_t __n)
    {
      for (std::size_t __i = 0; __i < __n; ++__i)
 if (lt(__s1[__i], __s2[__i]))
   return -1;
 else if (lt(__s2[__i], __s1[__i]))
   return 1;
      return 0;
    }

  template<typename _CharT>
    constexpr std::size_t
    char_traits<_CharT>::
    length(const char_type* __p)
    {
      std::size_t __i = 0;
      while (!eq(__p[__i], char_type()))
        ++__i;
      return __i;
    }

  template<typename _CharT>
    constexpr const typename char_traits<_CharT>::char_type*
    char_traits<_CharT>::
    find(const char_type* __s, std::size_t __n, const char_type& __a)
    {
      for (std::size_t __i = 0; __i < __n; ++__i)
        if (eq(__s[__i], __a))
          return __s + __i;
      return 0;
    }

  template<typename _CharT>
    typename char_traits<_CharT>::char_type*
    char_traits<_CharT>::
    move(char_type* __s1, const char_type* __s2, std::size_t __n)
    {
      if (__n == 0)
 return __s1;
      return static_cast<_CharT*>(__builtin_memmove(__s1, __s2,
          __n * sizeof(char_type)));
    }

  template<typename _CharT>
    typename char_traits<_CharT>::char_type*
    char_traits<_CharT>::
    copy(char_type* __s1, const char_type* __s2, std::size_t __n)
    {

      std::copy(__s2, __s2 + __n, __s1);
      return __s1;
    }

  template<typename _CharT>
    typename char_traits<_CharT>::char_type*
    char_traits<_CharT>::
    assign(char_type* __s, std::size_t __n, char_type __a)
    {

      std::fill_n(__s, __n, __a);
      return __s;
    }


}

namespace std __attribute__ ((__visibility__ ("default")))
{

# 283 "/usr/include/c++/9.2.0/bits/char_traits.h" 3
  template<class _CharT>
    struct char_traits : public __gnu_cxx::char_traits<_CharT>
    { };



  template<>
    struct char_traits<char>
    {
      typedef char char_type;
      typedef int int_type;
      typedef streampos pos_type;
      typedef streamoff off_type;
      typedef mbstate_t state_type;

      static void
      assign(char_type& __c1, const char_type& __c2) noexcept
      { __c1 = __c2; }

      static constexpr bool
      eq(const char_type& __c1, const char_type& __c2) noexcept
      { return __c1 == __c2; }

      static constexpr bool
      lt(const char_type& __c1, const char_type& __c2) noexcept
      {

 return (static_cast<unsigned char>(__c1)
  < static_cast<unsigned char>(__c2));
      }

      static int
      compare(const char_type* __s1, const char_type* __s2, size_t __n)
      {
 if (__n == 0)
   return 0;






 return __builtin_memcmp(__s1, __s2, __n);
      }

      static size_t
      length(const char_type* __s)
      {




 return __builtin_strlen(__s);
      }

      static const char_type*
      find(const char_type* __s, size_t __n, const char_type& __a)
      {
 if (__n == 0)
   return 0;






 return static_cast<const char_type*>(__builtin_memchr(__s, __a, __n));
      }

      static char_type*
      move(char_type* __s1, const char_type* __s2, size_t __n)
      {
 if (__n == 0)
   return __s1;
 return static_cast<char_type*>(__builtin_memmove(__s1, __s2, __n));
      }

      static char_type*
      copy(char_type* __s1, const char_type* __s2, size_t __n)
      {
 if (__n == 0)
   return __s1;
 return static_cast<char_type*>(__builtin_memcpy(__s1, __s2, __n));
      }

      static char_type*
      assign(char_type* __s, size_t __n, char_type __a)
      {
 if (__n == 0)
   return __s;
 return static_cast<char_type*>(__builtin_memset(__s, __a, __n));
      }

      static constexpr char_type
      to_char_type(const int_type& __c) noexcept
      { return static_cast<char_type>(__c); }



      static constexpr int_type
      to_int_type(const char_type& __c) noexcept
      { return static_cast<int_type>(static_cast<unsigned char>(__c)); }

      static constexpr bool
      eq_int_type(const int_type& __c1, const int_type& __c2) noexcept
      { return __c1 == __c2; }

      static constexpr int_type
      eof() noexcept
      { return static_cast<int_type>(-1); }

      static constexpr int_type
      not_eof(const int_type& __c) noexcept
      { return (__c == eof()) ? 0 : __c; }
  };




  template<>
    struct char_traits<wchar_t>
    {
      typedef wchar_t char_type;
      typedef wint_t int_type;
      typedef streamoff off_type;
      typedef wstreampos pos_type;
      typedef mbstate_t state_type;

      static void
      assign(char_type& __c1, const char_type& __c2) noexcept
      { __c1 = __c2; }

      static constexpr bool
      eq(const char_type& __c1, const char_type& __c2) noexcept
      { return __c1 == __c2; }

      static constexpr bool
      lt(const char_type& __c1, const char_type& __c2) noexcept
      { return __c1 < __c2; }

      static int
      compare(const char_type* __s1, const char_type* __s2, size_t __n)
      {
 if (__n == 0)
   return 0;






 return wmemcmp(__s1, __s2, __n);
      }

      static size_t
      length(const char_type* __s)
      {




 return wcslen(__s);
      }

      static const char_type*
      find(const char_type* __s, size_t __n, const char_type& __a)
      {
 if (__n == 0)
   return 0;






 return wmemchr(__s, __a, __n);
      }

      static char_type*
      move(char_type* __s1, const char_type* __s2, size_t __n)
      {
 if (__n == 0)
   return __s1;
 return wmemmove(__s1, __s2, __n);
      }

      static char_type*
      copy(char_type* __s1, const char_type* __s2, size_t __n)
      {
 if (__n == 0)
   return __s1;
 return wmemcpy(__s1, __s2, __n);
      }

      static char_type*
      assign(char_type* __s, size_t __n, char_type __a)
      {
 if (__n == 0)
   return __s;
 return wmemset(__s, __a, __n);
      }

      static constexpr char_type
      to_char_type(const int_type& __c) noexcept
      { return char_type(__c); }

      static constexpr int_type
      to_int_type(const char_type& __c) noexcept
      { return int_type(__c); }

      static constexpr bool
      eq_int_type(const int_type& __c1, const int_type& __c2) noexcept
      { return __c1 == __c2; }

      static constexpr int_type
      eof() noexcept
      { return static_cast<int_type>((0xffffffffu)); }

      static constexpr int_type
      not_eof(const int_type& __c) noexcept
      { return eq_int_type(__c, eof()) ? 0 : __c; }
  };
# 616 "/usr/include/c++/9.2.0/bits/char_traits.h" 3

}



# 1 "/usr/include/c++/9.2.0/cstdint" 1 3
# 32 "/usr/include/c++/9.2.0/cstdint" 3
       
# 33 "/usr/include/c++/9.2.0/cstdint" 3
# 41 "/usr/include/c++/9.2.0/cstdint" 3
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stdint.h" 1 3 4
# 9 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stdint.h" 3 4
# 1 "/usr/include/stdint.h" 1 3 4
# 26 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/bits/types.h" 1 3 4
# 27 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 28 "/usr/include/bits/types.h" 2 3 4
# 1 "/usr/include/bits/timesize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
# 141 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 142 "/usr/include/bits/types.h" 2 3 4
# 1 "/usr/include/bits/time64.h" 1 3 4
# 143 "/usr/include/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;
# 28 "/usr/include/stdint.h" 2 3 4

# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 30 "/usr/include/stdint.h" 2 3 4




# 1 "/usr/include/bits/stdint-intn.h" 1 3 4
# 24 "/usr/include/bits/stdint-intn.h" 3 4
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
# 35 "/usr/include/stdint.h" 2 3 4


# 1 "/usr/include/bits/stdint-uintn.h" 1 3 4
# 24 "/usr/include/bits/stdint-uintn.h" 3 4
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
# 38 "/usr/include/stdint.h" 2 3 4





typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;


typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;





typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
# 71 "/usr/include/stdint.h" 3 4
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
# 87 "/usr/include/stdint.h" 3 4
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
# 101 "/usr/include/stdint.h" 3 4
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
# 10 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stdint.h" 2 3 4
# 42 "/usr/include/c++/9.2.0/cstdint" 2 3


namespace std
{

  using ::int8_t;
  using ::int16_t;
  using ::int32_t;
  using ::int64_t;

  using ::int_fast8_t;
  using ::int_fast16_t;
  using ::int_fast32_t;
  using ::int_fast64_t;

  using ::int_least8_t;
  using ::int_least16_t;
  using ::int_least32_t;
  using ::int_least64_t;

  using ::intmax_t;
  using ::intptr_t;

  using ::uint8_t;
  using ::uint16_t;
  using ::uint32_t;
  using ::uint64_t;

  using ::uint_fast8_t;
  using ::uint_fast16_t;
  using ::uint_fast32_t;
  using ::uint_fast64_t;

  using ::uint_least8_t;
  using ::uint_least16_t;
  using ::uint_least32_t;
  using ::uint_least64_t;

  using ::uintmax_t;
  using ::uintptr_t;





}
# 622 "/usr/include/c++/9.2.0/bits/char_traits.h" 2 3

namespace std __attribute__ ((__visibility__ ("default")))
{


  template<>
    struct char_traits<char16_t>
    {
      typedef char16_t char_type;

      typedef uint_least16_t int_type;





      typedef streamoff off_type;
      typedef u16streampos pos_type;
      typedef mbstate_t state_type;

      static void
      assign(char_type& __c1, const char_type& __c2) noexcept
      { __c1 = __c2; }

      static constexpr bool
      eq(const char_type& __c1, const char_type& __c2) noexcept
      { return __c1 == __c2; }

      static constexpr bool
      lt(const char_type& __c1, const char_type& __c2) noexcept
      { return __c1 < __c2; }

      static int
      compare(const char_type* __s1, const char_type* __s2, size_t __n)
      {
 for (size_t __i = 0; __i < __n; ++__i)
   if (lt(__s1[__i], __s2[__i]))
     return -1;
   else if (lt(__s2[__i], __s1[__i]))
     return 1;
 return 0;
      }

      static size_t
      length(const char_type* __s)
      {
 size_t __i = 0;
 while (!eq(__s[__i], char_type()))
   ++__i;
 return __i;
      }

      static const char_type*
      find(const char_type* __s, size_t __n, const char_type& __a)
      {
 for (size_t __i = 0; __i < __n; ++__i)
   if (eq(__s[__i], __a))
     return __s + __i;
 return 0;
      }

      static char_type*
      move(char_type* __s1, const char_type* __s2, size_t __n)
      {
 if (__n == 0)
   return __s1;
 return (static_cast<char_type*>
  (__builtin_memmove(__s1, __s2, __n * sizeof(char_type))));
      }

      static char_type*
      copy(char_type* __s1, const char_type* __s2, size_t __n)
      {
 if (__n == 0)
   return __s1;
 return (static_cast<char_type*>
  (__builtin_memcpy(__s1, __s2, __n * sizeof(char_type))));
      }

      static char_type*
      assign(char_type* __s, size_t __n, char_type __a)
      {
 for (size_t __i = 0; __i < __n; ++__i)
   assign(__s[__i], __a);
 return __s;
      }

      static constexpr char_type
      to_char_type(const int_type& __c) noexcept
      { return char_type(__c); }

      static constexpr int_type
      to_int_type(const char_type& __c) noexcept
      { return __c == eof() ? int_type(0xfffd) : int_type(__c); }

      static constexpr bool
      eq_int_type(const int_type& __c1, const int_type& __c2) noexcept
      { return __c1 == __c2; }

      static constexpr int_type
      eof() noexcept
      { return static_cast<int_type>(-1); }

      static constexpr int_type
      not_eof(const int_type& __c) noexcept
      { return eq_int_type(__c, eof()) ? 0 : __c; }
    };

  template<>
    struct char_traits<char32_t>
    {
      typedef char32_t char_type;

      typedef uint_least32_t int_type;





      typedef streamoff off_type;
      typedef u32streampos pos_type;
      typedef mbstate_t state_type;

      static void
      assign(char_type& __c1, const char_type& __c2) noexcept
      { __c1 = __c2; }

      static constexpr bool
      eq(const char_type& __c1, const char_type& __c2) noexcept
      { return __c1 == __c2; }

      static constexpr bool
      lt(const char_type& __c1, const char_type& __c2) noexcept
      { return __c1 < __c2; }

      static int
      compare(const char_type* __s1, const char_type* __s2, size_t __n)
      {
 for (size_t __i = 0; __i < __n; ++__i)
   if (lt(__s1[__i], __s2[__i]))
     return -1;
   else if (lt(__s2[__i], __s1[__i]))
     return 1;
 return 0;
      }

      static size_t
      length(const char_type* __s)
      {
 size_t __i = 0;
 while (!eq(__s[__i], char_type()))
   ++__i;
 return __i;
      }

      static const char_type*
      find(const char_type* __s, size_t __n, const char_type& __a)
      {
 for (size_t __i = 0; __i < __n; ++__i)
   if (eq(__s[__i], __a))
     return __s + __i;
 return 0;
      }

      static char_type*
      move(char_type* __s1, const char_type* __s2, size_t __n)
      {
 if (__n == 0)
   return __s1;
 return (static_cast<char_type*>
  (__builtin_memmove(__s1, __s2, __n * sizeof(char_type))));
      }

      static char_type*
      copy(char_type* __s1, const char_type* __s2, size_t __n)
      {
 if (__n == 0)
   return __s1;
 return (static_cast<char_type*>
  (__builtin_memcpy(__s1, __s2, __n * sizeof(char_type))));
      }

      static char_type*
      assign(char_type* __s, size_t __n, char_type __a)
      {
 for (size_t __i = 0; __i < __n; ++__i)
   assign(__s[__i], __a);
 return __s;
      }

      static constexpr char_type
      to_char_type(const int_type& __c) noexcept
      { return char_type(__c); }

      static constexpr int_type
      to_int_type(const char_type& __c) noexcept
      { return int_type(__c); }

      static constexpr bool
      eq_int_type(const int_type& __c1, const int_type& __c2) noexcept
      { return __c1 == __c2; }

      static constexpr int_type
      eof() noexcept
      { return static_cast<int_type>(-1); }

      static constexpr int_type
      not_eof(const int_type& __c) noexcept
      { return eq_int_type(__c, eof()) ? 0 : __c; }
    };


}
# 41 "/usr/include/c++/9.2.0/string" 2 3


# 1 "/usr/include/c++/9.2.0/bits/localefwd.h" 1 3
# 37 "/usr/include/c++/9.2.0/bits/localefwd.h" 3
       
# 38 "/usr/include/c++/9.2.0/bits/localefwd.h" 3


# 1 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++locale.h" 1 3
# 39 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++locale.h" 3
       
# 40 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++locale.h" 3

# 1 "/usr/include/c++/9.2.0/clocale" 1 3
# 39 "/usr/include/c++/9.2.0/clocale" 3
       
# 40 "/usr/include/c++/9.2.0/clocale" 3


# 1 "/usr/include/locale.h" 1 3 4
# 28 "/usr/include/locale.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 1 3 4
# 29 "/usr/include/locale.h" 2 3 4
# 1 "/usr/include/bits/locale.h" 1 3 4
# 30 "/usr/include/locale.h" 2 3 4

extern "C" {
# 51 "/usr/include/locale.h" 3 4
struct lconv
{


  char *decimal_point;
  char *thousands_sep;





  char *grouping;





  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;

  char p_cs_precedes;

  char p_sep_by_space;

  char n_cs_precedes;

  char n_sep_by_space;






  char p_sign_posn;
  char n_sign_posn;


  char int_p_cs_precedes;

  char int_p_sep_by_space;

  char int_n_cs_precedes;

  char int_n_sep_by_space;






  char int_p_sign_posn;
  char int_n_sign_posn;
# 118 "/usr/include/locale.h" 3 4
};



extern char *setlocale (int __category, const char *__locale) throw ();


extern struct lconv *localeconv (void) throw ();
# 141 "/usr/include/locale.h" 3 4
extern locale_t newlocale (int __category_mask, const char *__locale,
      locale_t __base) throw ();
# 176 "/usr/include/locale.h" 3 4
extern locale_t duplocale (locale_t __dataset) throw ();



extern void freelocale (locale_t __dataset) throw ();






extern locale_t uselocale (locale_t __dataset) throw ();







}
# 43 "/usr/include/c++/9.2.0/clocale" 2 3
# 51 "/usr/include/c++/9.2.0/clocale" 3
namespace std
{
  using ::lconv;
  using ::setlocale;
  using ::localeconv;
}
# 42 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++locale.h" 2 3






namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{


  extern "C" __typeof(uselocale) __uselocale;


}


namespace std __attribute__ ((__visibility__ ("default")))
{


  typedef __locale_t __c_locale;





  inline int
  __convert_from_v(const __c_locale& __cloc __attribute__ ((__unused__)),
     char* __out,
     const int __size __attribute__ ((__unused__)),
     const char* __fmt, ...)
  {

    __c_locale __old = __gnu_cxx::__uselocale(__cloc);
# 88 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/c++locale.h" 3
    __builtin_va_list __args;
    __builtin_va_start(__args, __fmt);


    const int __ret = __builtin_vsnprintf(__out, __size, __fmt, __args);




    __builtin_va_end(__args);


    __gnu_cxx::__uselocale(__old);







    return __ret;
  }


}
# 41 "/usr/include/c++/9.2.0/bits/localefwd.h" 2 3
# 1 "/usr/include/c++/9.2.0/iosfwd" 1 3
# 36 "/usr/include/c++/9.2.0/iosfwd" 3
       
# 37 "/usr/include/c++/9.2.0/iosfwd" 3





namespace std __attribute__ ((__visibility__ ("default")))
{

# 74 "/usr/include/c++/9.2.0/iosfwd" 3
  class ios_base;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ios;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_streambuf;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_istream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ostream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_iostream;


namespace __cxx11 {

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
     typename _Alloc = allocator<_CharT> >
    class basic_stringbuf;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
    typename _Alloc = allocator<_CharT> >
    class basic_istringstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
    typename _Alloc = allocator<_CharT> >
    class basic_ostringstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
    typename _Alloc = allocator<_CharT> >
    class basic_stringstream;

}

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_filebuf;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ifstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ofstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_fstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class istreambuf_iterator;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class ostreambuf_iterator;



  typedef basic_ios<char> ios;


  typedef basic_streambuf<char> streambuf;


  typedef basic_istream<char> istream;


  typedef basic_ostream<char> ostream;


  typedef basic_iostream<char> iostream;


  typedef basic_stringbuf<char> stringbuf;


  typedef basic_istringstream<char> istringstream;


  typedef basic_ostringstream<char> ostringstream;


  typedef basic_stringstream<char> stringstream;


  typedef basic_filebuf<char> filebuf;


  typedef basic_ifstream<char> ifstream;


  typedef basic_ofstream<char> ofstream;


  typedef basic_fstream<char> fstream;



  typedef basic_ios<wchar_t> wios;


  typedef basic_streambuf<wchar_t> wstreambuf;


  typedef basic_istream<wchar_t> wistream;


  typedef basic_ostream<wchar_t> wostream;


  typedef basic_iostream<wchar_t> wiostream;


  typedef basic_stringbuf<wchar_t> wstringbuf;


  typedef basic_istringstream<wchar_t> wistringstream;


  typedef basic_ostringstream<wchar_t> wostringstream;


  typedef basic_stringstream<wchar_t> wstringstream;


  typedef basic_filebuf<wchar_t> wfilebuf;


  typedef basic_ifstream<wchar_t> wifstream;


  typedef basic_ofstream<wchar_t> wofstream;


  typedef basic_fstream<wchar_t> wfstream;




}
# 42 "/usr/include/c++/9.2.0/bits/localefwd.h" 2 3
# 1 "/usr/include/c++/9.2.0/cctype" 1 3
# 39 "/usr/include/c++/9.2.0/cctype" 3
       
# 40 "/usr/include/c++/9.2.0/cctype" 3


# 1 "/usr/include/ctype.h" 1 3 4
# 28 "/usr/include/ctype.h" 3 4
extern "C" {
# 39 "/usr/include/ctype.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 36 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 2 3 4
# 60 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/byteswap.h" 1 3 4
# 33 "/usr/include/bits/byteswap.h" 3 4
static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{

  return __builtin_bswap16 (__bsx);



}






static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{

  return __builtin_bswap32 (__bsx);



}
# 69 "/usr/include/bits/byteswap.h" 3 4
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{

  return __builtin_bswap64 (__bsx);



}
# 61 "/usr/include/endian.h" 2 3 4
# 1 "/usr/include/bits/uintn-identity.h" 1 3 4
# 32 "/usr/include/bits/uintn-identity.h" 3 4
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}

static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}

static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
# 62 "/usr/include/endian.h" 2 3 4
# 40 "/usr/include/ctype.h" 2 3 4






enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
# 79 "/usr/include/ctype.h" 3 4
extern const unsigned short int **__ctype_b_loc (void)
     throw () __attribute__ ((__const__));
extern const __int32_t **__ctype_tolower_loc (void)
     throw () __attribute__ ((__const__));
extern const __int32_t **__ctype_toupper_loc (void)
     throw () __attribute__ ((__const__));
# 108 "/usr/include/ctype.h" 3 4
extern int isalnum (int) throw ();
extern int isalpha (int) throw ();
extern int iscntrl (int) throw ();
extern int isdigit (int) throw ();
extern int islower (int) throw ();
extern int isgraph (int) throw ();
extern int isprint (int) throw ();
extern int ispunct (int) throw ();
extern int isspace (int) throw ();
extern int isupper (int) throw ();
extern int isxdigit (int) throw ();



extern int tolower (int __c) throw ();


extern int toupper (int __c) throw ();




extern int isblank (int) throw ();




extern int isctype (int __c, int __mask) throw ();






extern int isascii (int __c) throw ();



extern int toascii (int __c) throw ();



extern int _toupper (int) throw ();
extern int _tolower (int) throw ();
# 251 "/usr/include/ctype.h" 3 4
extern int isalnum_l (int, locale_t) throw ();
extern int isalpha_l (int, locale_t) throw ();
extern int iscntrl_l (int, locale_t) throw ();
extern int isdigit_l (int, locale_t) throw ();
extern int islower_l (int, locale_t) throw ();
extern int isgraph_l (int, locale_t) throw ();
extern int isprint_l (int, locale_t) throw ();
extern int ispunct_l (int, locale_t) throw ();
extern int isspace_l (int, locale_t) throw ();
extern int isupper_l (int, locale_t) throw ();
extern int isxdigit_l (int, locale_t) throw ();

extern int isblank_l (int, locale_t) throw ();



extern int __tolower_l (int __c, locale_t __l) throw ();
extern int tolower_l (int __c, locale_t __l) throw ();


extern int __toupper_l (int __c, locale_t __l) throw ();
extern int toupper_l (int __c, locale_t __l) throw ();
# 327 "/usr/include/ctype.h" 3 4
}
# 43 "/usr/include/c++/9.2.0/cctype" 2 3
# 62 "/usr/include/c++/9.2.0/cctype" 3
namespace std
{
  using ::isalnum;
  using ::isalpha;
  using ::iscntrl;
  using ::isdigit;
  using ::isgraph;
  using ::islower;
  using ::isprint;
  using ::ispunct;
  using ::isspace;
  using ::isupper;
  using ::isxdigit;
  using ::tolower;
  using ::toupper;
}







namespace std
{
  using ::isblank;
}
# 43 "/usr/include/c++/9.2.0/bits/localefwd.h" 2 3

namespace std __attribute__ ((__visibility__ ("default")))
{

# 55 "/usr/include/c++/9.2.0/bits/localefwd.h" 3
  class locale;

  template<typename _Facet>
    bool
    has_facet(const locale&) throw();

  template<typename _Facet>
    const _Facet&
    use_facet(const locale&);


  template<typename _CharT>
    bool
    isspace(_CharT, const locale&);

  template<typename _CharT>
    bool
    isprint(_CharT, const locale&);

  template<typename _CharT>
    bool
    iscntrl(_CharT, const locale&);

  template<typename _CharT>
    bool
    isupper(_CharT, const locale&);

  template<typename _CharT>
    bool
    islower(_CharT, const locale&);

  template<typename _CharT>
    bool
    isalpha(_CharT, const locale&);

  template<typename _CharT>
    bool
    isdigit(_CharT, const locale&);

  template<typename _CharT>
    bool
    ispunct(_CharT, const locale&);

  template<typename _CharT>
    bool
    isxdigit(_CharT, const locale&);

  template<typename _CharT>
    bool
    isalnum(_CharT, const locale&);

  template<typename _CharT>
    bool
    isgraph(_CharT, const locale&);


  template<typename _CharT>
    bool
    isblank(_CharT, const locale&);


  template<typename _CharT>
    _CharT
    toupper(_CharT, const locale&);

  template<typename _CharT>
    _CharT
    tolower(_CharT, const locale&);


  class ctype_base;
  template<typename _CharT>
    class ctype;
  template<> class ctype<char>;

  template<> class ctype<wchar_t>;

  template<typename _CharT>
    class ctype_byname;


  class codecvt_base;
  template<typename _InternT, typename _ExternT, typename _StateT>
    class codecvt;
  template<> class codecvt<char, char, mbstate_t>;

  template<> class codecvt<wchar_t, char, mbstate_t>;


  template<> class codecvt<char16_t, char, mbstate_t>;
  template<> class codecvt<char32_t, char, mbstate_t>;





  template<typename _InternT, typename _ExternT, typename _StateT>
    class codecvt_byname;



  template<typename _CharT, typename _InIter = istreambuf_iterator<_CharT> >
    class num_get;
  template<typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT> >
    class num_put;

namespace __cxx11 {
  template<typename _CharT> class numpunct;
  template<typename _CharT> class numpunct_byname;
}

namespace __cxx11 {

  template<typename _CharT>
    class collate;
  template<typename _CharT>
    class collate_byname;
}


  class time_base;
namespace __cxx11 {
  template<typename _CharT, typename _InIter = istreambuf_iterator<_CharT> >
    class time_get;
  template<typename _CharT, typename _InIter = istreambuf_iterator<_CharT> >
    class time_get_byname;
}
  template<typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT> >
    class time_put;
  template<typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT> >
    class time_put_byname;


  class money_base;
namespace __cxx11 {
  template<typename _CharT, typename _InIter = istreambuf_iterator<_CharT> >
    class money_get;
  template<typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT> >
    class money_put;
}
namespace __cxx11 {
  template<typename _CharT, bool _Intl = false>
    class moneypunct;
  template<typename _CharT, bool _Intl = false>
    class moneypunct_byname;
}


  class messages_base;
namespace __cxx11 {
  template<typename _CharT>
    class messages;
  template<typename _CharT>
    class messages_byname;
}


}
# 44 "/usr/include/c++/9.2.0/string" 2 3
# 1 "/usr/include/c++/9.2.0/bits/ostream_insert.h" 1 3
# 33 "/usr/include/c++/9.2.0/bits/ostream_insert.h" 3
       
# 34 "/usr/include/c++/9.2.0/bits/ostream_insert.h" 3


# 1 "/usr/include/c++/9.2.0/bits/cxxabi_forced.h" 1 3
# 34 "/usr/include/c++/9.2.0/bits/cxxabi_forced.h" 3
       
# 35 "/usr/include/c++/9.2.0/bits/cxxabi_forced.h" 3

#pragma GCC visibility push(default)


namespace __cxxabiv1
{







  class __forced_unwind
  {
    virtual ~__forced_unwind() throw();


    virtual void __pure_dummy() = 0;
  };
}


#pragma GCC visibility pop
# 37 "/usr/include/c++/9.2.0/bits/ostream_insert.h" 2 3

namespace std __attribute__ ((__visibility__ ("default")))
{


  template<typename _CharT, typename _Traits>
    inline void
    __ostream_write(basic_ostream<_CharT, _Traits>& __out,
      const _CharT* __s, streamsize __n)
    {
      typedef basic_ostream<_CharT, _Traits> __ostream_type;
      typedef typename __ostream_type::ios_base __ios_base;

      const streamsize __put = __out.rdbuf()->sputn(__s, __n);
      if (__put != __n)
 __out.setstate(__ios_base::badbit);
    }

  template<typename _CharT, typename _Traits>
    inline void
    __ostream_fill(basic_ostream<_CharT, _Traits>& __out, streamsize __n)
    {
      typedef basic_ostream<_CharT, _Traits> __ostream_type;
      typedef typename __ostream_type::ios_base __ios_base;

      const _CharT __c = __out.fill();
      for (; __n > 0; --__n)
 {
   const typename _Traits::int_type __put = __out.rdbuf()->sputc(__c);
   if (_Traits::eq_int_type(__put, _Traits::eof()))
     {
       __out.setstate(__ios_base::badbit);
       break;
     }
 }
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    __ostream_insert(basic_ostream<_CharT, _Traits>& __out,
       const _CharT* __s, streamsize __n)
    {
      typedef basic_ostream<_CharT, _Traits> __ostream_type;
      typedef typename __ostream_type::ios_base __ios_base;

      typename __ostream_type::sentry __cerb(__out);
      if (__cerb)
 {
   try
     {
       const streamsize __w = __out.width();
       if (__w > __n)
  {
    const bool __left = ((__out.flags()
     & __ios_base::adjustfield)
           == __ios_base::left);
    if (!__left)
      __ostream_fill(__out, __w - __n);
    if (__out.good())
      __ostream_write(__out, __s, __n);
    if (__left && __out.good())
      __ostream_fill(__out, __w - __n);
  }
       else
  __ostream_write(__out, __s, __n);
       __out.width(0);
     }
   catch(__cxxabiv1::__forced_unwind&)
     {
       __out._M_setstate(__ios_base::badbit);
       throw;
     }
   catch(...)
     { __out._M_setstate(__ios_base::badbit); }
 }
      return __out;
    }




  extern template ostream& __ostream_insert(ostream&, const char*, streamsize);


  extern template wostream& __ostream_insert(wostream&, const wchar_t*,
          streamsize);




}
# 45 "/usr/include/c++/9.2.0/string" 2 3
# 54 "/usr/include/c++/9.2.0/string" 3
# 1 "/usr/include/c++/9.2.0/bits/range_access.h" 1 3
# 33 "/usr/include/c++/9.2.0/bits/range_access.h" 3
       
# 34 "/usr/include/c++/9.2.0/bits/range_access.h" 3



namespace std __attribute__ ((__visibility__ ("default")))
{







  template<typename _Container>
    inline auto
    begin(_Container& __cont) -> decltype(__cont.begin())
    { return __cont.begin(); }






  template<typename _Container>
    inline auto
    begin(const _Container& __cont) -> decltype(__cont.begin())
    { return __cont.begin(); }






  template<typename _Container>
    inline auto
    end(_Container& __cont) -> decltype(__cont.end())
    { return __cont.end(); }






  template<typename _Container>
    inline auto
    end(const _Container& __cont) -> decltype(__cont.end())
    { return __cont.end(); }





  template<typename _Tp, size_t _Nm>
    inline constexpr _Tp*
    begin(_Tp (&__arr)[_Nm])
    { return __arr; }






  template<typename _Tp, size_t _Nm>
    inline constexpr _Tp*
    end(_Tp (&__arr)[_Nm])
    { return __arr + _Nm; }



  template<typename _Tp> class valarray;

  template<typename _Tp> _Tp* begin(valarray<_Tp>&);
  template<typename _Tp> const _Tp* begin(const valarray<_Tp>&);
  template<typename _Tp> _Tp* end(valarray<_Tp>&);
  template<typename _Tp> const _Tp* end(const valarray<_Tp>&);






  template<typename _Container>
    inline constexpr auto
    cbegin(const _Container& __cont) noexcept(noexcept(std::begin(__cont)))
      -> decltype(std::begin(__cont))
    { return std::begin(__cont); }






  template<typename _Container>
    inline constexpr auto
    cend(const _Container& __cont) noexcept(noexcept(std::end(__cont)))
      -> decltype(std::end(__cont))
    { return std::end(__cont); }






  template<typename _Container>
    inline auto
    rbegin(_Container& __cont) -> decltype(__cont.rbegin())
    { return __cont.rbegin(); }






  template<typename _Container>
    inline auto
    rbegin(const _Container& __cont) -> decltype(__cont.rbegin())
    { return __cont.rbegin(); }






  template<typename _Container>
    inline auto
    rend(_Container& __cont) -> decltype(__cont.rend())
    { return __cont.rend(); }






  template<typename _Container>
    inline auto
    rend(const _Container& __cont) -> decltype(__cont.rend())
    { return __cont.rend(); }






  template<typename _Tp, size_t _Nm>
    inline reverse_iterator<_Tp*>
    rbegin(_Tp (&__arr)[_Nm])
    { return reverse_iterator<_Tp*>(__arr + _Nm); }






  template<typename _Tp, size_t _Nm>
    inline reverse_iterator<_Tp*>
    rend(_Tp (&__arr)[_Nm])
    { return reverse_iterator<_Tp*>(__arr); }






  template<typename _Tp>
    inline reverse_iterator<const _Tp*>
    rbegin(initializer_list<_Tp> __il)
    { return reverse_iterator<const _Tp*>(__il.end()); }






  template<typename _Tp>
    inline reverse_iterator<const _Tp*>
    rend(initializer_list<_Tp> __il)
    { return reverse_iterator<const _Tp*>(__il.begin()); }






  template<typename _Container>
    inline auto
    crbegin(const _Container& __cont) -> decltype(std::rbegin(__cont))
    { return std::rbegin(__cont); }






  template<typename _Container>
    inline auto
    crend(const _Container& __cont) -> decltype(std::rend(__cont))
    { return std::rend(__cont); }
# 323 "/usr/include/c++/9.2.0/bits/range_access.h" 3

}
# 55 "/usr/include/c++/9.2.0/string" 2 3
# 1 "/usr/include/c++/9.2.0/bits/basic_string.h" 1 3
# 37 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
       
# 38 "/usr/include/c++/9.2.0/bits/basic_string.h" 3

# 1 "/usr/include/c++/9.2.0/ext/atomicity.h" 1 3
# 32 "/usr/include/c++/9.2.0/ext/atomicity.h" 3
       
# 33 "/usr/include/c++/9.2.0/ext/atomicity.h" 3


# 1 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr.h" 1 3
# 30 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr.h" 3
#pragma GCC visibility push(default)
# 148 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr.h" 3
# 1 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr-default.h" 1 3
# 35 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr-default.h" 3
# 1 "/usr/include/pthread.h" 1 3 4
# 23 "/usr/include/pthread.h" 3 4
# 1 "/usr/include/sched.h" 1 3 4
# 29 "/usr/include/sched.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 1 3 4
# 30 "/usr/include/sched.h" 2 3 4

# 1 "/usr/include/bits/types/time_t.h" 1 3 4






typedef __time_t time_t;
# 32 "/usr/include/sched.h" 2 3 4
# 1 "/usr/include/bits/types/struct_timespec.h" 1 3 4
# 9 "/usr/include/bits/types/struct_timespec.h" 3 4
struct timespec
{
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
# 33 "/usr/include/sched.h" 2 3 4





typedef __pid_t pid_t;




# 1 "/usr/include/bits/sched.h" 1 3 4
# 74 "/usr/include/bits/sched.h" 3 4
# 1 "/usr/include/bits/types/struct_sched_param.h" 1 3 4
# 23 "/usr/include/bits/types/struct_sched_param.h" 3 4
struct sched_param
{
  int sched_priority;
};
# 75 "/usr/include/bits/sched.h" 2 3 4

extern "C" {



extern int clone (int (*__fn) (void *__arg), void *__child_stack,
    int __flags, void *__arg, ...) throw ();


extern int unshare (int __flags) throw ();


extern int sched_getcpu (void) throw ();


extern int getcpu (unsigned int *, unsigned int *) throw ();


extern int setns (int __fd, int __nstype) throw ();


}
# 44 "/usr/include/sched.h" 2 3 4
# 1 "/usr/include/bits/cpu-set.h" 1 3 4
# 32 "/usr/include/bits/cpu-set.h" 3 4
typedef unsigned long int __cpu_mask;






typedef struct
{
  __cpu_mask __bits[1024 / (8 * sizeof (__cpu_mask))];
} cpu_set_t;
# 115 "/usr/include/bits/cpu-set.h" 3 4
extern "C" {

extern int __sched_cpucount (size_t __setsize, const cpu_set_t *__setp)
     throw ();
extern cpu_set_t *__sched_cpualloc (size_t __count) throw () ;
extern void __sched_cpufree (cpu_set_t *__set) throw ();

}
# 45 "/usr/include/sched.h" 2 3 4






extern "C" {


extern int sched_setparam (__pid_t __pid, const struct sched_param *__param)
     throw ();


extern int sched_getparam (__pid_t __pid, struct sched_param *__param) throw ();


extern int sched_setscheduler (__pid_t __pid, int __policy,
          const struct sched_param *__param) throw ();


extern int sched_getscheduler (__pid_t __pid) throw ();


extern int sched_yield (void) throw ();


extern int sched_get_priority_max (int __algorithm) throw ();


extern int sched_get_priority_min (int __algorithm) throw ();


extern int sched_rr_get_interval (__pid_t __pid, struct timespec *__t) throw ();
# 121 "/usr/include/sched.h" 3 4
extern int sched_setaffinity (__pid_t __pid, size_t __cpusetsize,
         const cpu_set_t *__cpuset) throw ();


extern int sched_getaffinity (__pid_t __pid, size_t __cpusetsize,
         cpu_set_t *__cpuset) throw ();


}
# 24 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/time.h" 1 3 4
# 29 "/usr/include/time.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 1 3 4
# 30 "/usr/include/time.h" 2 3 4



# 1 "/usr/include/bits/time.h" 1 3 4
# 73 "/usr/include/bits/time.h" 3 4
# 1 "/usr/include/bits/timex.h" 1 3 4
# 22 "/usr/include/bits/timex.h" 3 4
# 1 "/usr/include/bits/types/struct_timeval.h" 1 3 4







struct timeval
{
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
# 23 "/usr/include/bits/timex.h" 2 3 4



struct timex
{
  unsigned int modes;
  __syscall_slong_t offset;
  __syscall_slong_t freq;
  __syscall_slong_t maxerror;
  __syscall_slong_t esterror;
  int status;
  __syscall_slong_t constant;
  __syscall_slong_t precision;
  __syscall_slong_t tolerance;
  struct timeval time;
  __syscall_slong_t tick;
  __syscall_slong_t ppsfreq;
  __syscall_slong_t jitter;
  int shift;
  __syscall_slong_t stabil;
  __syscall_slong_t jitcnt;
  __syscall_slong_t calcnt;
  __syscall_slong_t errcnt;
  __syscall_slong_t stbcnt;

  int tai;


  int :32; int :32; int :32; int :32;
  int :32; int :32; int :32; int :32;
  int :32; int :32; int :32;
};
# 74 "/usr/include/bits/time.h" 2 3 4

extern "C" {


extern int clock_adjtime (__clockid_t __clock_id, struct timex *__utx) throw ();

}
# 34 "/usr/include/time.h" 2 3 4



# 1 "/usr/include/bits/types/clock_t.h" 1 3 4






typedef __clock_t clock_t;
# 38 "/usr/include/time.h" 2 3 4

# 1 "/usr/include/bits/types/struct_tm.h" 1 3 4






struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;


  long int tm_gmtoff;
  const char *tm_zone;




};
# 40 "/usr/include/time.h" 2 3 4






# 1 "/usr/include/bits/types/clockid_t.h" 1 3 4






typedef __clockid_t clockid_t;
# 47 "/usr/include/time.h" 2 3 4
# 1 "/usr/include/bits/types/timer_t.h" 1 3 4






typedef __timer_t timer_t;
# 48 "/usr/include/time.h" 2 3 4
# 1 "/usr/include/bits/types/struct_itimerspec.h" 1 3 4







struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };
# 49 "/usr/include/time.h" 2 3 4
struct sigevent;
# 68 "/usr/include/time.h" 3 4
extern "C" {



extern clock_t clock (void) throw ();


extern time_t time (time_t *__timer) throw ();


extern double difftime (time_t __time1, time_t __time0)
     throw () __attribute__ ((__const__));


extern time_t mktime (struct tm *__tp) throw ();





extern size_t strftime (char *__restrict __s, size_t __maxsize,
   const char *__restrict __format,
   const struct tm *__restrict __tp) throw ();




extern char *strptime (const char *__restrict __s,
         const char *__restrict __fmt, struct tm *__tp)
     throw ();






extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     const char *__restrict __format,
     const struct tm *__restrict __tp,
     locale_t __loc) throw ();



extern char *strptime_l (const char *__restrict __s,
    const char *__restrict __fmt, struct tm *__tp,
    locale_t __loc) throw ();





extern struct tm *gmtime (const time_t *__timer) throw ();



extern struct tm *localtime (const time_t *__timer) throw ();




extern struct tm *gmtime_r (const time_t *__restrict __timer,
       struct tm *__restrict __tp) throw ();



extern struct tm *localtime_r (const time_t *__restrict __timer,
          struct tm *__restrict __tp) throw ();




extern char *asctime (const struct tm *__tp) throw ();


extern char *ctime (const time_t *__timer) throw ();






extern char *asctime_r (const struct tm *__restrict __tp,
   char *__restrict __buf) throw ();


extern char *ctime_r (const time_t *__restrict __timer,
        char *__restrict __buf) throw ();




extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;




extern char *tzname[2];



extern void tzset (void) throw ();



extern int daylight;
extern long int timezone;





extern int stime (const time_t *__when) throw ();
# 196 "/usr/include/time.h" 3 4
extern time_t timegm (struct tm *__tp) throw ();


extern time_t timelocal (struct tm *__tp) throw ();


extern int dysize (int __year) throw () __attribute__ ((__const__));
# 211 "/usr/include/time.h" 3 4
extern int nanosleep (const struct timespec *__requested_time,
        struct timespec *__remaining);



extern int clock_getres (clockid_t __clock_id, struct timespec *__res) throw ();


extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) throw ();


extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
     throw ();






extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       const struct timespec *__req,
       struct timespec *__rem);


extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) throw ();




extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) throw ();


extern int timer_delete (timer_t __timerid) throw ();


extern int timer_settime (timer_t __timerid, int __flags,
     const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) throw ();


extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     throw ();


extern int timer_getoverrun (timer_t __timerid) throw ();





extern int timespec_get (struct timespec *__ts, int __base)
     throw () __attribute__ ((__nonnull__ (1)));
# 280 "/usr/include/time.h" 3 4
extern int getdate_err;
# 289 "/usr/include/time.h" 3 4
extern struct tm *getdate (const char *__string);
# 303 "/usr/include/time.h" 3 4
extern int getdate_r (const char *__restrict __string,
        struct tm *__restrict __resbufp);


}
# 25 "/usr/include/pthread.h" 2 3 4

# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/bits/thread-shared-types.h" 1 3 4
# 77 "/usr/include/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/bits/pthreadtypes-arch.h" 1 3 4
# 21 "/usr/include/bits/pthreadtypes-arch.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 22 "/usr/include/bits/pthreadtypes-arch.h" 2 3 4
# 65 "/usr/include/bits/pthreadtypes-arch.h" 3 4
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;

  int __cur_writer;
  int __shared;
  signed char __rwelision;




  unsigned char __pad1[7];


  unsigned long int __pad2;


  unsigned int __flags;
# 99 "/usr/include/bits/pthreadtypes-arch.h" 3 4
};
# 78 "/usr/include/bits/thread-shared-types.h" 2 3 4




typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
# 118 "/usr/include/bits/thread-shared-types.h" 3 4
struct __pthread_mutex_s
{
  int __lock ;
  unsigned int __count;
  int __owner;

  unsigned int __nusers;
# 148 "/usr/include/bits/thread-shared-types.h" 3 4
  int __kind;
 




  short __spins; short __elision;
  __pthread_list_t __list;
# 165 "/usr/include/bits/thread-shared-types.h" 3 4
 
};




struct __pthread_cond_s
{
  __extension__ union
  {
    __extension__ unsigned long long int __wseq;
    struct
    {
      unsigned int __low;
      unsigned int __high;
    } __wseq32;
  };
  __extension__ union
  {
    __extension__ unsigned long long int __g1_start;
    struct
    {
      unsigned int __low;
      unsigned int __high;
    } __g1_start32;
  };
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};
# 24 "/usr/include/bits/pthreadtypes.h" 2 3 4



typedef unsigned long int pthread_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;


union pthread_attr_t
{
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;




typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;


typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;





typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 27 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/bits/setjmp.h" 1 3 4
# 26 "/usr/include/bits/setjmp.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 27 "/usr/include/bits/setjmp.h" 2 3 4




typedef long int __jmp_buf[8];
# 28 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/pthread.h" 2 3 4




enum
{
  PTHREAD_CREATE_JOINABLE,

  PTHREAD_CREATE_DETACHED

};



enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP

  ,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL



  , PTHREAD_MUTEX_FAST_NP = PTHREAD_MUTEX_TIMED_NP

};




enum
{
  PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_ROBUST,
  PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};





enum
{
  PTHREAD_PRIO_NONE,
  PTHREAD_PRIO_INHERIT,
  PTHREAD_PRIO_PROTECT
};
# 115 "/usr/include/pthread.h" 3 4
enum
{
  PTHREAD_RWLOCK_PREFER_READER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
  PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
};
# 156 "/usr/include/pthread.h" 3 4
enum
{
  PTHREAD_INHERIT_SCHED,

  PTHREAD_EXPLICIT_SCHED

};



enum
{
  PTHREAD_SCOPE_SYSTEM,

  PTHREAD_SCOPE_PROCESS

};



enum
{
  PTHREAD_PROCESS_PRIVATE,

  PTHREAD_PROCESS_SHARED

};
# 191 "/usr/include/pthread.h" 3 4
struct _pthread_cleanup_buffer
{
  void (*__routine) (void *);
  void *__arg;
  int __canceltype;
  struct _pthread_cleanup_buffer *__prev;
};


enum
{
  PTHREAD_CANCEL_ENABLE,

  PTHREAD_CANCEL_DISABLE

};
enum
{
  PTHREAD_CANCEL_DEFERRED,

  PTHREAD_CANCEL_ASYNCHRONOUS

};
# 229 "/usr/include/pthread.h" 3 4
extern "C" {




extern int pthread_create (pthread_t *__restrict __newthread,
      const pthread_attr_t *__restrict __attr,
      void *(*__start_routine) (void *),
      void *__restrict __arg) throw () __attribute__ ((__nonnull__ (1, 3)));





extern void pthread_exit (void *__retval) __attribute__ ((__noreturn__));







extern int pthread_join (pthread_t __th, void **__thread_return);




extern int pthread_tryjoin_np (pthread_t __th, void **__thread_return) throw ();







extern int pthread_timedjoin_np (pthread_t __th, void **__thread_return,
     const struct timespec *__abstime);






extern int pthread_detach (pthread_t __th) throw ();



extern pthread_t pthread_self (void) throw () __attribute__ ((__const__));


extern int pthread_equal (pthread_t __thread1, pthread_t __thread2)
  throw () __attribute__ ((__const__));







extern int pthread_attr_init (pthread_attr_t *__attr) throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_attr_destroy (pthread_attr_t *__attr)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_attr_getdetachstate (const pthread_attr_t *__attr,
     int *__detachstate)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setdetachstate (pthread_attr_t *__attr,
     int __detachstate)
     throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_attr_getguardsize (const pthread_attr_t *__attr,
          size_t *__guardsize)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setguardsize (pthread_attr_t *__attr,
          size_t __guardsize)
     throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_attr_getschedparam (const pthread_attr_t *__restrict __attr,
           struct sched_param *__restrict __param)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setschedparam (pthread_attr_t *__restrict __attr,
           const struct sched_param *__restrict
           __param) throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_getschedpolicy (const pthread_attr_t *__restrict
     __attr, int *__restrict __policy)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setschedpolicy (pthread_attr_t *__attr, int __policy)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_attr_getinheritsched (const pthread_attr_t *__restrict
      __attr, int *__restrict __inherit)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setinheritsched (pthread_attr_t *__attr,
      int __inherit)
     throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_attr_getscope (const pthread_attr_t *__restrict __attr,
      int *__restrict __scope)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setscope (pthread_attr_t *__attr, int __scope)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_attr_getstackaddr (const pthread_attr_t *__restrict
          __attr, void **__restrict __stackaddr)
     throw () __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__deprecated__));





extern int pthread_attr_setstackaddr (pthread_attr_t *__attr,
          void *__stackaddr)
     throw () __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__));


extern int pthread_attr_getstacksize (const pthread_attr_t *__restrict
          __attr, size_t *__restrict __stacksize)
     throw () __attribute__ ((__nonnull__ (1, 2)));




extern int pthread_attr_setstacksize (pthread_attr_t *__attr,
          size_t __stacksize)
     throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_attr_getstack (const pthread_attr_t *__restrict __attr,
      void **__restrict __stackaddr,
      size_t *__restrict __stacksize)
     throw () __attribute__ ((__nonnull__ (1, 2, 3)));




extern int pthread_attr_setstack (pthread_attr_t *__attr, void *__stackaddr,
      size_t __stacksize) throw () __attribute__ ((__nonnull__ (1)));





extern int pthread_attr_setaffinity_np (pthread_attr_t *__attr,
     size_t __cpusetsize,
     const cpu_set_t *__cpuset)
     throw () __attribute__ ((__nonnull__ (1, 3)));



extern int pthread_attr_getaffinity_np (const pthread_attr_t *__attr,
     size_t __cpusetsize,
     cpu_set_t *__cpuset)
     throw () __attribute__ ((__nonnull__ (1, 3)));


extern int pthread_getattr_default_np (pthread_attr_t *__attr)
     throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_setattr_default_np (const pthread_attr_t *__attr)
     throw () __attribute__ ((__nonnull__ (1)));




extern int pthread_getattr_np (pthread_t __th, pthread_attr_t *__attr)
     throw () __attribute__ ((__nonnull__ (2)));







extern int pthread_setschedparam (pthread_t __target_thread, int __policy,
      const struct sched_param *__param)
     throw () __attribute__ ((__nonnull__ (3)));


extern int pthread_getschedparam (pthread_t __target_thread,
      int *__restrict __policy,
      struct sched_param *__restrict __param)
     throw () __attribute__ ((__nonnull__ (2, 3)));


extern int pthread_setschedprio (pthread_t __target_thread, int __prio)
     throw ();




extern int pthread_getname_np (pthread_t __target_thread, char *__buf,
          size_t __buflen)
     throw () __attribute__ ((__nonnull__ (2)));


extern int pthread_setname_np (pthread_t __target_thread, const char *__name)
     throw () __attribute__ ((__nonnull__ (2)));





extern int pthread_getconcurrency (void) throw ();


extern int pthread_setconcurrency (int __level) throw ();







extern int pthread_yield (void) throw ();




extern int pthread_setaffinity_np (pthread_t __th, size_t __cpusetsize,
       const cpu_set_t *__cpuset)
     throw () __attribute__ ((__nonnull__ (3)));


extern int pthread_getaffinity_np (pthread_t __th, size_t __cpusetsize,
       cpu_set_t *__cpuset)
     throw () __attribute__ ((__nonnull__ (3)));
# 495 "/usr/include/pthread.h" 3 4
extern int pthread_once (pthread_once_t *__once_control,
    void (*__init_routine) (void)) __attribute__ ((__nonnull__ (1, 2)));
# 507 "/usr/include/pthread.h" 3 4
extern int pthread_setcancelstate (int __state, int *__oldstate);



extern int pthread_setcanceltype (int __type, int *__oldtype);


extern int pthread_cancel (pthread_t __th);




extern void pthread_testcancel (void);




typedef struct
{
  struct
  {
    __jmp_buf __cancel_jmp_buf;
    int __mask_was_saved;
  } __cancel_jmp_buf[1];
  void *__pad[4];
} __pthread_unwind_buf_t __attribute__ ((__aligned__));
# 541 "/usr/include/pthread.h" 3 4
struct __pthread_cleanup_frame
{
  void (*__cancel_routine) (void *);
  void *__cancel_arg;
  int __do_it;
  int __cancel_type;
};




class __pthread_cleanup_class
{
  void (*__cancel_routine) (void *);
  void *__cancel_arg;
  int __do_it;
  int __cancel_type;

 public:
  __pthread_cleanup_class (void (*__fct) (void *), void *__arg)
    : __cancel_routine (__fct), __cancel_arg (__arg), __do_it (1) { }
  ~__pthread_cleanup_class () { if (__do_it) __cancel_routine (__cancel_arg); }
  void __setdoit (int __newval) { __do_it = __newval; }
  void __defer () { pthread_setcanceltype (PTHREAD_CANCEL_DEFERRED,
        &__cancel_type); }
  void __restore () const { pthread_setcanceltype (__cancel_type, 0); }
};
# 743 "/usr/include/pthread.h" 3 4
struct __jmp_buf_tag;
extern int __sigsetjmp (struct __jmp_buf_tag *__env, int __savemask) throw ();





extern int pthread_mutex_init (pthread_mutex_t *__mutex,
          const pthread_mutexattr_t *__mutexattr)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_mutex_destroy (pthread_mutex_t *__mutex)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_mutex_trylock (pthread_mutex_t *__mutex)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_mutex_lock (pthread_mutex_t *__mutex)
     throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_mutex_timedlock (pthread_mutex_t *__restrict __mutex,
        const struct timespec *__restrict
        __abstime) throw () __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_mutex_clocklock (pthread_mutex_t *__restrict __mutex,
        clockid_t __clockid,
        const struct timespec *__restrict
        __abstime) throw () __attribute__ ((__nonnull__ (1, 3)));



extern int pthread_mutex_unlock (pthread_mutex_t *__mutex)
     throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_mutex_getprioceiling (const pthread_mutex_t *
      __restrict __mutex,
      int *__restrict __prioceiling)
     throw () __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_mutex_setprioceiling (pthread_mutex_t *__restrict __mutex,
      int __prioceiling,
      int *__restrict __old_ceiling)
     throw () __attribute__ ((__nonnull__ (1, 3)));




extern int pthread_mutex_consistent (pthread_mutex_t *__mutex)
     throw () __attribute__ ((__nonnull__ (1)));

extern int pthread_mutex_consistent_np (pthread_mutex_t *__mutex)
     throw () __attribute__ ((__nonnull__ (1)));
# 814 "/usr/include/pthread.h" 3 4
extern int pthread_mutexattr_init (pthread_mutexattr_t *__attr)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_mutexattr_destroy (pthread_mutexattr_t *__attr)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_mutexattr_getpshared (const pthread_mutexattr_t *
      __restrict __attr,
      int *__restrict __pshared)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_mutexattr_setpshared (pthread_mutexattr_t *__attr,
      int __pshared)
     throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_mutexattr_gettype (const pthread_mutexattr_t *__restrict
          __attr, int *__restrict __kind)
     throw () __attribute__ ((__nonnull__ (1, 2)));




extern int pthread_mutexattr_settype (pthread_mutexattr_t *__attr, int __kind)
     throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_mutexattr_getprotocol (const pthread_mutexattr_t *
       __restrict __attr,
       int *__restrict __protocol)
     throw () __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_mutexattr_setprotocol (pthread_mutexattr_t *__attr,
       int __protocol)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_mutexattr_getprioceiling (const pthread_mutexattr_t *
          __restrict __attr,
          int *__restrict __prioceiling)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_mutexattr_setprioceiling (pthread_mutexattr_t *__attr,
          int __prioceiling)
     throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_mutexattr_getrobust (const pthread_mutexattr_t *__attr,
     int *__robustness)
     throw () __attribute__ ((__nonnull__ (1, 2)));

extern int pthread_mutexattr_getrobust_np (const pthread_mutexattr_t *__attr,
        int *__robustness)
     throw () __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_mutexattr_setrobust (pthread_mutexattr_t *__attr,
     int __robustness)
     throw () __attribute__ ((__nonnull__ (1)));

extern int pthread_mutexattr_setrobust_np (pthread_mutexattr_t *__attr,
        int __robustness)
     throw () __attribute__ ((__nonnull__ (1)));
# 896 "/usr/include/pthread.h" 3 4
extern int pthread_rwlock_init (pthread_rwlock_t *__restrict __rwlock,
    const pthread_rwlockattr_t *__restrict
    __attr) throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlock_destroy (pthread_rwlock_t *__rwlock)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlock_rdlock (pthread_rwlock_t *__rwlock)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlock_tryrdlock (pthread_rwlock_t *__rwlock)
  throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_rwlock_timedrdlock (pthread_rwlock_t *__restrict __rwlock,
           const struct timespec *__restrict
           __abstime) throw () __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_rwlock_clockrdlock (pthread_rwlock_t *__restrict __rwlock,
           clockid_t __clockid,
           const struct timespec *__restrict
           __abstime) throw () __attribute__ ((__nonnull__ (1, 3)));



extern int pthread_rwlock_wrlock (pthread_rwlock_t *__rwlock)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlock_trywrlock (pthread_rwlock_t *__rwlock)
     throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_rwlock_timedwrlock (pthread_rwlock_t *__restrict __rwlock,
           const struct timespec *__restrict
           __abstime) throw () __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_rwlock_clockwrlock (pthread_rwlock_t *__restrict __rwlock,
           clockid_t __clockid,
           const struct timespec *__restrict
           __abstime) throw () __attribute__ ((__nonnull__ (1, 3)));



extern int pthread_rwlock_unlock (pthread_rwlock_t *__rwlock)
     throw () __attribute__ ((__nonnull__ (1)));





extern int pthread_rwlockattr_init (pthread_rwlockattr_t *__attr)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlockattr_destroy (pthread_rwlockattr_t *__attr)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlockattr_getpshared (const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pshared)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_rwlockattr_setpshared (pthread_rwlockattr_t *__attr,
       int __pshared)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlockattr_getkind_np (const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pref)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_rwlockattr_setkind_np (pthread_rwlockattr_t *__attr,
       int __pref) throw () __attribute__ ((__nonnull__ (1)));







extern int pthread_cond_init (pthread_cond_t *__restrict __cond,
         const pthread_condattr_t *__restrict __cond_attr)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_cond_destroy (pthread_cond_t *__cond)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_cond_signal (pthread_cond_t *__cond)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_cond_broadcast (pthread_cond_t *__cond)
     throw () __attribute__ ((__nonnull__ (1)));






extern int pthread_cond_wait (pthread_cond_t *__restrict __cond,
         pthread_mutex_t *__restrict __mutex)
     __attribute__ ((__nonnull__ (1, 2)));
# 1022 "/usr/include/pthread.h" 3 4
extern int pthread_cond_timedwait (pthread_cond_t *__restrict __cond,
       pthread_mutex_t *__restrict __mutex,
       const struct timespec *__restrict __abstime)
     __attribute__ ((__nonnull__ (1, 2, 3)));
# 1035 "/usr/include/pthread.h" 3 4
extern int pthread_cond_clockwait (pthread_cond_t *__restrict __cond,
       pthread_mutex_t *__restrict __mutex,
       __clockid_t __clock_id,
       const struct timespec *__restrict __abstime)
     __attribute__ ((__nonnull__ (1, 2, 4)));





extern int pthread_condattr_init (pthread_condattr_t *__attr)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_condattr_destroy (pthread_condattr_t *__attr)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_condattr_getpshared (const pthread_condattr_t *
     __restrict __attr,
     int *__restrict __pshared)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_condattr_setpshared (pthread_condattr_t *__attr,
     int __pshared) throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_condattr_getclock (const pthread_condattr_t *
          __restrict __attr,
          __clockid_t *__restrict __clock_id)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_condattr_setclock (pthread_condattr_t *__attr,
          __clockid_t __clock_id)
     throw () __attribute__ ((__nonnull__ (1)));
# 1081 "/usr/include/pthread.h" 3 4
extern int pthread_spin_init (pthread_spinlock_t *__lock, int __pshared)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_spin_destroy (pthread_spinlock_t *__lock)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_spin_lock (pthread_spinlock_t *__lock)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_spin_trylock (pthread_spinlock_t *__lock)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_spin_unlock (pthread_spinlock_t *__lock)
     throw () __attribute__ ((__nonnull__ (1)));






extern int pthread_barrier_init (pthread_barrier_t *__restrict __barrier,
     const pthread_barrierattr_t *__restrict
     __attr, unsigned int __count)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_barrier_destroy (pthread_barrier_t *__barrier)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_barrier_wait (pthread_barrier_t *__barrier)
     throw () __attribute__ ((__nonnull__ (1)));



extern int pthread_barrierattr_init (pthread_barrierattr_t *__attr)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_barrierattr_destroy (pthread_barrierattr_t *__attr)
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_barrierattr_getpshared (const pthread_barrierattr_t *
        __restrict __attr,
        int *__restrict __pshared)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_barrierattr_setpshared (pthread_barrierattr_t *__attr,
        int __pshared)
     throw () __attribute__ ((__nonnull__ (1)));
# 1148 "/usr/include/pthread.h" 3 4
extern int pthread_key_create (pthread_key_t *__key,
          void (*__destr_function) (void *))
     throw () __attribute__ ((__nonnull__ (1)));


extern int pthread_key_delete (pthread_key_t __key) throw ();


extern void *pthread_getspecific (pthread_key_t __key) throw ();


extern int pthread_setspecific (pthread_key_t __key,
    const void *__pointer) throw () ;




extern int pthread_getcpuclockid (pthread_t __thread_id,
      __clockid_t *__clock_id)
     throw () __attribute__ ((__nonnull__ (2)));
# 1182 "/usr/include/pthread.h" 3 4
extern int pthread_atfork (void (*__prepare) (void),
      void (*__parent) (void),
      void (*__child) (void)) throw ();
# 1196 "/usr/include/pthread.h" 3 4
}
# 36 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr-default.h" 2 3
# 47 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr-default.h" 3
typedef pthread_t __gthread_t;
typedef pthread_key_t __gthread_key_t;
typedef pthread_once_t __gthread_once_t;
typedef pthread_mutex_t __gthread_mutex_t;
typedef pthread_mutex_t __gthread_recursive_mutex_t;
typedef pthread_cond_t __gthread_cond_t;
typedef struct timespec __gthread_time_t;
# 102 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr-default.h" 3
static __typeof(pthread_once) __gthrw_pthread_once __attribute__ ((__weakref__("pthread_once"), __copy__ (pthread_once)));
static __typeof(pthread_getspecific) __gthrw_pthread_getspecific __attribute__ ((__weakref__("pthread_getspecific"), __copy__ (pthread_getspecific)));
static __typeof(pthread_setspecific) __gthrw_pthread_setspecific __attribute__ ((__weakref__("pthread_setspecific"), __copy__ (pthread_setspecific)));

static __typeof(pthread_create) __gthrw_pthread_create __attribute__ ((__weakref__("pthread_create"), __copy__ (pthread_create)));
static __typeof(pthread_join) __gthrw_pthread_join __attribute__ ((__weakref__("pthread_join"), __copy__ (pthread_join)));
static __typeof(pthread_equal) __gthrw_pthread_equal __attribute__ ((__weakref__("pthread_equal"), __copy__ (pthread_equal)));
static __typeof(pthread_self) __gthrw_pthread_self __attribute__ ((__weakref__("pthread_self"), __copy__ (pthread_self)));
static __typeof(pthread_detach) __gthrw_pthread_detach __attribute__ ((__weakref__("pthread_detach"), __copy__ (pthread_detach)));

static __typeof(pthread_cancel) __gthrw_pthread_cancel __attribute__ ((__weakref__("pthread_cancel"), __copy__ (pthread_cancel)));

static __typeof(sched_yield) __gthrw_sched_yield __attribute__ ((__weakref__("sched_yield"), __copy__ (sched_yield)));

static __typeof(pthread_mutex_lock) __gthrw_pthread_mutex_lock __attribute__ ((__weakref__("pthread_mutex_lock"), __copy__ (pthread_mutex_lock)));
static __typeof(pthread_mutex_trylock) __gthrw_pthread_mutex_trylock __attribute__ ((__weakref__("pthread_mutex_trylock"), __copy__ (pthread_mutex_trylock)));

static __typeof(pthread_mutex_timedlock) __gthrw_pthread_mutex_timedlock __attribute__ ((__weakref__("pthread_mutex_timedlock"), __copy__ (pthread_mutex_timedlock)));

static __typeof(pthread_mutex_unlock) __gthrw_pthread_mutex_unlock __attribute__ ((__weakref__("pthread_mutex_unlock"), __copy__ (pthread_mutex_unlock)));
static __typeof(pthread_mutex_init) __gthrw_pthread_mutex_init __attribute__ ((__weakref__("pthread_mutex_init"), __copy__ (pthread_mutex_init)));
static __typeof(pthread_mutex_destroy) __gthrw_pthread_mutex_destroy __attribute__ ((__weakref__("pthread_mutex_destroy"), __copy__ (pthread_mutex_destroy)));

static __typeof(pthread_cond_init) __gthrw_pthread_cond_init __attribute__ ((__weakref__("pthread_cond_init"), __copy__ (pthread_cond_init)));
static __typeof(pthread_cond_broadcast) __gthrw_pthread_cond_broadcast __attribute__ ((__weakref__("pthread_cond_broadcast"), __copy__ (pthread_cond_broadcast)));
static __typeof(pthread_cond_signal) __gthrw_pthread_cond_signal __attribute__ ((__weakref__("pthread_cond_signal"), __copy__ (pthread_cond_signal)));
static __typeof(pthread_cond_wait) __gthrw_pthread_cond_wait __attribute__ ((__weakref__("pthread_cond_wait"), __copy__ (pthread_cond_wait)));
static __typeof(pthread_cond_timedwait) __gthrw_pthread_cond_timedwait __attribute__ ((__weakref__("pthread_cond_timedwait"), __copy__ (pthread_cond_timedwait)));
static __typeof(pthread_cond_destroy) __gthrw_pthread_cond_destroy __attribute__ ((__weakref__("pthread_cond_destroy"), __copy__ (pthread_cond_destroy)));

static __typeof(pthread_key_create) __gthrw_pthread_key_create __attribute__ ((__weakref__("pthread_key_create"), __copy__ (pthread_key_create)));
static __typeof(pthread_key_delete) __gthrw_pthread_key_delete __attribute__ ((__weakref__("pthread_key_delete"), __copy__ (pthread_key_delete)));
static __typeof(pthread_mutexattr_init) __gthrw_pthread_mutexattr_init __attribute__ ((__weakref__("pthread_mutexattr_init"), __copy__ (pthread_mutexattr_init)));
static __typeof(pthread_mutexattr_settype) __gthrw_pthread_mutexattr_settype __attribute__ ((__weakref__("pthread_mutexattr_settype"), __copy__ (pthread_mutexattr_settype)));
static __typeof(pthread_mutexattr_destroy) __gthrw_pthread_mutexattr_destroy __attribute__ ((__weakref__("pthread_mutexattr_destroy"), __copy__ (pthread_mutexattr_destroy)));
# 237 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr-default.h" 3
static __typeof(pthread_key_create) __gthrw___pthread_key_create __attribute__ ((__weakref__("__pthread_key_create"), __copy__ (pthread_key_create)));
# 247 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr-default.h" 3
static inline int
__gthread_active_p (void)
{
  static void *const __gthread_active_ptr
    = __extension__ (void *) &__gthrw___pthread_key_create;
  return __gthread_active_ptr != 0;
}
# 659 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr-default.h" 3
static inline int
__gthread_create (__gthread_t *__threadid, void *(*__func) (void*),
    void *__args)
{
  return __gthrw_pthread_create (__threadid, __null, __func, __args);
}

static inline int
__gthread_join (__gthread_t __threadid, void **__value_ptr)
{
  return __gthrw_pthread_join (__threadid, __value_ptr);
}

static inline int
__gthread_detach (__gthread_t __threadid)
{
  return __gthrw_pthread_detach (__threadid);
}

static inline int
__gthread_equal (__gthread_t __t1, __gthread_t __t2)
{
  return __gthrw_pthread_equal (__t1, __t2);
}

static inline __gthread_t
__gthread_self (void)
{
  return __gthrw_pthread_self ();
}

static inline int
__gthread_yield (void)
{
  return __gthrw_sched_yield ();
}

static inline int
__gthread_once (__gthread_once_t *__once, void (*__func) (void))
{
  if (__gthread_active_p ())
    return __gthrw_pthread_once (__once, __func);
  else
    return -1;
}

static inline int
__gthread_key_create (__gthread_key_t *__key, void (*__dtor) (void *))
{
  return __gthrw_pthread_key_create (__key, __dtor);
}

static inline int
__gthread_key_delete (__gthread_key_t __key)
{
  return __gthrw_pthread_key_delete (__key);
}

static inline void *
__gthread_getspecific (__gthread_key_t __key)
{
  return __gthrw_pthread_getspecific (__key);
}

static inline int
__gthread_setspecific (__gthread_key_t __key, const void *__ptr)
{
  return __gthrw_pthread_setspecific (__key, __ptr);
}

static inline void
__gthread_mutex_init_function (__gthread_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    __gthrw_pthread_mutex_init (__mutex, __null);
}

static inline int
__gthread_mutex_destroy (__gthread_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    return __gthrw_pthread_mutex_destroy (__mutex);
  else
    return 0;
}

static inline int
__gthread_mutex_lock (__gthread_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    return __gthrw_pthread_mutex_lock (__mutex);
  else
    return 0;
}

static inline int
__gthread_mutex_trylock (__gthread_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    return __gthrw_pthread_mutex_trylock (__mutex);
  else
    return 0;
}


static inline int
__gthread_mutex_timedlock (__gthread_mutex_t *__mutex,
      const __gthread_time_t *__abs_timeout)
{
  if (__gthread_active_p ())
    return __gthrw_pthread_mutex_timedlock (__mutex, __abs_timeout);
  else
    return 0;
}


static inline int
__gthread_mutex_unlock (__gthread_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    return __gthrw_pthread_mutex_unlock (__mutex);
  else
    return 0;
}
# 808 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr-default.h" 3
static inline int
__gthread_recursive_mutex_lock (__gthread_recursive_mutex_t *__mutex)
{
  return __gthread_mutex_lock (__mutex);
}

static inline int
__gthread_recursive_mutex_trylock (__gthread_recursive_mutex_t *__mutex)
{
  return __gthread_mutex_trylock (__mutex);
}


static inline int
__gthread_recursive_mutex_timedlock (__gthread_recursive_mutex_t *__mutex,
         const __gthread_time_t *__abs_timeout)
{
  return __gthread_mutex_timedlock (__mutex, __abs_timeout);
}


static inline int
__gthread_recursive_mutex_unlock (__gthread_recursive_mutex_t *__mutex)
{
  return __gthread_mutex_unlock (__mutex);
}

static inline int
__gthread_recursive_mutex_destroy (__gthread_recursive_mutex_t *__mutex)
{
  return __gthread_mutex_destroy (__mutex);
}
# 850 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr-default.h" 3
static inline int
__gthread_cond_broadcast (__gthread_cond_t *__cond)
{
  return __gthrw_pthread_cond_broadcast (__cond);
}

static inline int
__gthread_cond_signal (__gthread_cond_t *__cond)
{
  return __gthrw_pthread_cond_signal (__cond);
}

static inline int
__gthread_cond_wait (__gthread_cond_t *__cond, __gthread_mutex_t *__mutex)
{
  return __gthrw_pthread_cond_wait (__cond, __mutex);
}

static inline int
__gthread_cond_timedwait (__gthread_cond_t *__cond, __gthread_mutex_t *__mutex,
     const __gthread_time_t *__abs_timeout)
{
  return __gthrw_pthread_cond_timedwait (__cond, __mutex, __abs_timeout);
}

static inline int
__gthread_cond_wait_recursive (__gthread_cond_t *__cond,
          __gthread_recursive_mutex_t *__mutex)
{
  return __gthread_cond_wait (__cond, __mutex);
}

static inline int
__gthread_cond_destroy (__gthread_cond_t* __cond)
{
  return __gthrw_pthread_cond_destroy (__cond);
}
# 149 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/gthr.h" 2 3


#pragma GCC visibility pop
# 36 "/usr/include/c++/9.2.0/ext/atomicity.h" 2 3
# 1 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/atomic_word.h" 1 3
# 32 "/usr/include/c++/9.2.0/x86_64-pc-linux-gnu/bits/atomic_word.h" 3
typedef int _Atomic_word;
# 37 "/usr/include/c++/9.2.0/ext/atomicity.h" 2 3

namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{







  static inline _Atomic_word
  __exchange_and_add(volatile _Atomic_word* __mem, int __val)
  { return __atomic_fetch_add(__mem, __val, 4); }

  static inline void
  __atomic_add(volatile _Atomic_word* __mem, int __val)
  { __atomic_fetch_add(__mem, __val, 4); }
# 64 "/usr/include/c++/9.2.0/ext/atomicity.h" 3
  static inline _Atomic_word
  __exchange_and_add_single(_Atomic_word* __mem, int __val)
  {
    _Atomic_word __result = *__mem;
    *__mem += __val;
    return __result;
  }

  static inline void
  __atomic_add_single(_Atomic_word* __mem, int __val)
  { *__mem += __val; }

  static inline _Atomic_word
  __attribute__ ((__unused__))
  __exchange_and_add_dispatch(_Atomic_word* __mem, int __val)
  {

    if (__gthread_active_p())
      return __exchange_and_add(__mem, __val);
    else
      return __exchange_and_add_single(__mem, __val);



  }

  static inline void
  __attribute__ ((__unused__))
  __atomic_add_dispatch(_Atomic_word* __mem, int __val)
  {

    if (__gthread_active_p())
      __atomic_add(__mem, __val);
    else
      __atomic_add_single(__mem, __val);



  }


}
# 40 "/usr/include/c++/9.2.0/bits/basic_string.h" 2 3
# 52 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
namespace std __attribute__ ((__visibility__ ("default")))
{



namespace __cxx11 {
# 76 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    class basic_string
    {
      typedef typename __gnu_cxx::__alloc_traits<_Alloc>::template
 rebind<_CharT>::other _Char_alloc_type;
      typedef __gnu_cxx::__alloc_traits<_Char_alloc_type> _Alloc_traits;


    public:
      typedef _Traits traits_type;
      typedef typename _Traits::char_type value_type;
      typedef _Char_alloc_type allocator_type;
      typedef typename _Alloc_traits::size_type size_type;
      typedef typename _Alloc_traits::difference_type difference_type;
      typedef typename _Alloc_traits::reference reference;
      typedef typename _Alloc_traits::const_reference const_reference;
      typedef typename _Alloc_traits::pointer pointer;
      typedef typename _Alloc_traits::const_pointer const_pointer;
      typedef __gnu_cxx::__normal_iterator<pointer, basic_string> iterator;
      typedef __gnu_cxx::__normal_iterator<const_pointer, basic_string>
       const_iterator;
      typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
      typedef std::reverse_iterator<iterator> reverse_iterator;


      static const size_type npos = static_cast<size_type>(-1);

    protected:




      typedef const_iterator __const_iterator;


    private:
# 150 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      struct _Alloc_hider : allocator_type
      {




 _Alloc_hider(pointer __dat, const _Alloc& __a)
 : allocator_type(__a), _M_p(__dat) { }

 _Alloc_hider(pointer __dat, _Alloc&& __a = _Alloc())
 : allocator_type(std::move(__a)), _M_p(__dat) { }


 pointer _M_p;
      };

      _Alloc_hider _M_dataplus;
      size_type _M_string_length;

      enum { _S_local_capacity = 15 / sizeof(_CharT) };

      union
      {
 _CharT _M_local_buf[_S_local_capacity + 1];
 size_type _M_allocated_capacity;
      };

      void
      _M_data(pointer __p)
      { _M_dataplus._M_p = __p; }

      void
      _M_length(size_type __length)
      { _M_string_length = __length; }

      pointer
      _M_data() const
      { return _M_dataplus._M_p; }

      pointer
      _M_local_data()
      {

 return std::pointer_traits<pointer>::pointer_to(*_M_local_buf);



      }

      const_pointer
      _M_local_data() const
      {

 return std::pointer_traits<const_pointer>::pointer_to(*_M_local_buf);



      }

      void
      _M_capacity(size_type __capacity)
      { _M_allocated_capacity = __capacity; }

      void
      _M_set_length(size_type __n)
      {
 _M_length(__n);
 traits_type::assign(_M_data()[__n], _CharT());
      }

      bool
      _M_is_local() const
      { return _M_data() == _M_local_data(); }


      pointer
      _M_create(size_type&, size_type);

      void
      _M_dispose()
      {
 if (!_M_is_local())
   _M_destroy(_M_allocated_capacity);
      }

      void
      _M_destroy(size_type __size) throw()
      { _Alloc_traits::deallocate(_M_get_allocator(), _M_data(), __size + 1); }



      template<typename _InIterator>
        void
        _M_construct_aux(_InIterator __beg, _InIterator __end,
    std::__false_type)
 {
          typedef typename iterator_traits<_InIterator>::iterator_category _Tag;
          _M_construct(__beg, __end, _Tag());
 }



      template<typename _Integer>
        void
        _M_construct_aux(_Integer __beg, _Integer __end, std::__true_type)
 { _M_construct_aux_2(static_cast<size_type>(__beg), __end); }

      void
      _M_construct_aux_2(size_type __req, _CharT __c)
      { _M_construct(__req, __c); }

      template<typename _InIterator>
        void
        _M_construct(_InIterator __beg, _InIterator __end)
 {
   typedef typename std::__is_integer<_InIterator>::__type _Integral;
   _M_construct_aux(__beg, __end, _Integral());
        }


      template<typename _InIterator>
        void
        _M_construct(_InIterator __beg, _InIterator __end,
       std::input_iterator_tag);



      template<typename _FwdIterator>
        void
        _M_construct(_FwdIterator __beg, _FwdIterator __end,
       std::forward_iterator_tag);

      void
      _M_construct(size_type __req, _CharT __c);

      allocator_type&
      _M_get_allocator()
      { return _M_dataplus; }

      const allocator_type&
      _M_get_allocator() const
      { return _M_dataplus; }

    private:
# 309 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      _M_check(size_type __pos, const char* __s) const
      {
 if (__pos > this->size())
   __throw_out_of_range_fmt(("%s: __pos (which is %zu) > " "this->size() (which is %zu)")
                                         ,
       __s, __pos, this->size());
 return __pos;
      }

      void
      _M_check_length(size_type __n1, size_type __n2, const char* __s) const
      {
 if (this->max_size() - (this->size() - __n1) < __n2)
   __throw_length_error((__s));
      }



      size_type
      _M_limit(size_type __pos, size_type __off) const noexcept
      {
 const bool __testoff = __off < this->size() - __pos;
 return __testoff ? __off : this->size() - __pos;
      }


      bool
      _M_disjunct(const _CharT* __s) const noexcept
      {
 return (less<const _CharT*>()(__s, _M_data())
  || less<const _CharT*>()(_M_data() + this->size(), __s));
      }



      static void
      _S_copy(_CharT* __d, const _CharT* __s, size_type __n)
      {
 if (__n == 1)
   traits_type::assign(*__d, *__s);
 else
   traits_type::copy(__d, __s, __n);
      }

      static void
      _S_move(_CharT* __d, const _CharT* __s, size_type __n)
      {
 if (__n == 1)
   traits_type::assign(*__d, *__s);
 else
   traits_type::move(__d, __s, __n);
      }

      static void
      _S_assign(_CharT* __d, size_type __n, _CharT __c)
      {
 if (__n == 1)
   traits_type::assign(*__d, __c);
 else
   traits_type::assign(__d, __n, __c);
      }



      template<class _Iterator>
        static void
        _S_copy_chars(_CharT* __p, _Iterator __k1, _Iterator __k2)
        {
   for (; __k1 != __k2; ++__k1, (void)++__p)
     traits_type::assign(*__p, *__k1);
 }

      static void
      _S_copy_chars(_CharT* __p, iterator __k1, iterator __k2) noexcept
      { _S_copy_chars(__p, __k1.base(), __k2.base()); }

      static void
      _S_copy_chars(_CharT* __p, const_iterator __k1, const_iterator __k2)
      noexcept
      { _S_copy_chars(__p, __k1.base(), __k2.base()); }

      static void
      _S_copy_chars(_CharT* __p, _CharT* __k1, _CharT* __k2) noexcept
      { _S_copy(__p, __k1, __k2 - __k1); }

      static void
      _S_copy_chars(_CharT* __p, const _CharT* __k1, const _CharT* __k2)
      noexcept
      { _S_copy(__p, __k1, __k2 - __k1); }

      static int
      _S_compare(size_type __n1, size_type __n2) noexcept
      {
 const difference_type __d = difference_type(__n1 - __n2);

 if (__d > __gnu_cxx::__numeric_traits<int>::__max)
   return __gnu_cxx::__numeric_traits<int>::__max;
 else if (__d < __gnu_cxx::__numeric_traits<int>::__min)
   return __gnu_cxx::__numeric_traits<int>::__min;
 else
   return int(__d);
      }

      void
      _M_assign(const basic_string&);

      void
      _M_mutate(size_type __pos, size_type __len1, const _CharT* __s,
  size_type __len2);

      void
      _M_erase(size_type __pos, size_type __n);

    public:







      basic_string()
      noexcept(is_nothrow_default_constructible<_Alloc>::value)
      : _M_dataplus(_M_local_data())
      { _M_set_length(0); }




      explicit
      basic_string(const _Alloc& __a) noexcept
      : _M_dataplus(_M_local_data(), __a)
      { _M_set_length(0); }





      basic_string(const basic_string& __str)
      : _M_dataplus(_M_local_data(),
      _Alloc_traits::_S_select_on_copy(__str._M_get_allocator()))
      { _M_construct(__str._M_data(), __str._M_data() + __str.length()); }
# 461 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string(const basic_string& __str, size_type __pos,
     const _Alloc& __a = _Alloc())
      : _M_dataplus(_M_local_data(), __a)
      {
 const _CharT* __start = __str._M_data()
   + __str._M_check(__pos, "basic_string::basic_string");
 _M_construct(__start, __start + __str._M_limit(__pos, npos));
      }







      basic_string(const basic_string& __str, size_type __pos,
     size_type __n)
      : _M_dataplus(_M_local_data())
      {
 const _CharT* __start = __str._M_data()
   + __str._M_check(__pos, "basic_string::basic_string");
 _M_construct(__start, __start + __str._M_limit(__pos, __n));
      }
# 492 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string(const basic_string& __str, size_type __pos,
     size_type __n, const _Alloc& __a)
      : _M_dataplus(_M_local_data(), __a)
      {
 const _CharT* __start
   = __str._M_data() + __str._M_check(__pos, "string::string");
 _M_construct(__start, __start + __str._M_limit(__pos, __n));
      }
# 510 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string(const _CharT* __s, size_type __n,
     const _Alloc& __a = _Alloc())
      : _M_dataplus(_M_local_data(), __a)
      { _M_construct(__s, __s + __n); }
# 525 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string(const _CharT* __s, const _Alloc& __a = _Alloc())
      : _M_dataplus(_M_local_data(), __a)
      { _M_construct(__s, __s ? __s + traits_type::length(__s) : __s+npos); }
# 540 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string(size_type __n, _CharT __c, const _Alloc& __a = _Alloc())
      : _M_dataplus(_M_local_data(), __a)
      { _M_construct(__n, __c); }
# 552 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string(basic_string&& __str) noexcept
      : _M_dataplus(_M_local_data(), std::move(__str._M_get_allocator()))
      {
 if (__str._M_is_local())
   {
     traits_type::copy(_M_local_buf, __str._M_local_buf,
         _S_local_capacity + 1);
   }
 else
   {
     _M_data(__str._M_data());
     _M_capacity(__str._M_allocated_capacity);
   }




 _M_length(__str.length());
 __str._M_data(__str._M_local_data());
 __str._M_set_length(0);
      }






      basic_string(initializer_list<_CharT> __l, const _Alloc& __a = _Alloc())
      : _M_dataplus(_M_local_data(), __a)
      { _M_construct(__l.begin(), __l.end()); }

      basic_string(const basic_string& __str, const _Alloc& __a)
      : _M_dataplus(_M_local_data(), __a)
      { _M_construct(__str.begin(), __str.end()); }

      basic_string(basic_string&& __str, const _Alloc& __a)
      noexcept(_Alloc_traits::_S_always_equal())
      : _M_dataplus(_M_local_data(), __a)
      {
 if (__str._M_is_local())
   {
     traits_type::copy(_M_local_buf, __str._M_local_buf,
         _S_local_capacity + 1);
     _M_length(__str.length());
     __str._M_set_length(0);
   }
 else if (_Alloc_traits::_S_always_equal()
     || __str.get_allocator() == __a)
   {
     _M_data(__str._M_data());
     _M_length(__str.length());
     _M_capacity(__str._M_allocated_capacity);
     __str._M_data(__str._M_local_buf);
     __str._M_set_length(0);
   }
 else
   _M_construct(__str.begin(), __str.end());
      }
# 620 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      template<typename _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>



        basic_string(_InputIterator __beg, _InputIterator __end,
       const _Alloc& __a = _Alloc())
 : _M_dataplus(_M_local_data(), __a)
 { _M_construct(__beg, __end); }
# 657 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      ~basic_string()
      { _M_dispose(); }





      basic_string&
      operator=(const basic_string& __str)
      {

 if (_Alloc_traits::_S_propagate_on_copy_assign())
   {
     if (!_Alloc_traits::_S_always_equal() && !_M_is_local()
  && _M_get_allocator() != __str._M_get_allocator())
       {


  if (__str.size() <= _S_local_capacity)
    {
      _M_destroy(_M_allocated_capacity);
      _M_data(_M_local_data());
      _M_set_length(0);
    }
  else
    {
      const auto __len = __str.size();
      auto __alloc = __str._M_get_allocator();

      auto __ptr = _Alloc_traits::allocate(__alloc, __len + 1);
      _M_destroy(_M_allocated_capacity);
      _M_data(__ptr);
      _M_capacity(__len);
      _M_set_length(__len);
    }
       }
     std::__alloc_on_copy(_M_get_allocator(), __str._M_get_allocator());
   }

 return this->assign(__str);
      }





      basic_string&
      operator=(const _CharT* __s)
      { return this->assign(__s); }
# 714 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      operator=(_CharT __c)
      {
 this->assign(1, __c);
 return *this;
      }
# 731 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      operator=(basic_string&& __str)
      noexcept(_Alloc_traits::_S_nothrow_move())
      {
 if (!_M_is_local() && _Alloc_traits::_S_propagate_on_move_assign()
     && !_Alloc_traits::_S_always_equal()
     && _M_get_allocator() != __str._M_get_allocator())
   {

     _M_destroy(_M_allocated_capacity);
     _M_data(_M_local_data());
     _M_set_length(0);
   }

 std::__alloc_on_move(_M_get_allocator(), __str._M_get_allocator());

 if (__str._M_is_local())
   {

     if (__str.size())
       this->_S_copy(_M_data(), __str._M_data(), __str.size());
     _M_set_length(__str.size());
   }
 else if (_Alloc_traits::_S_propagate_on_move_assign()
     || _Alloc_traits::_S_always_equal()
     || _M_get_allocator() == __str._M_get_allocator())
   {

     pointer __data = nullptr;
     size_type __capacity;
     if (!_M_is_local())
       {
  if (_Alloc_traits::_S_always_equal())
    {

      __data = _M_data();
      __capacity = _M_allocated_capacity;
    }
  else
    _M_destroy(_M_allocated_capacity);
       }

     _M_data(__str._M_data());
     _M_length(__str.length());
     _M_capacity(__str._M_allocated_capacity);
     if (__data)
       {
  __str._M_data(__data);
  __str._M_capacity(__capacity);
       }
     else
       __str._M_data(__str._M_local_buf);
   }
 else
   assign(__str);
 __str.clear();
 return *this;
      }





      basic_string&
      operator=(initializer_list<_CharT> __l)
      {
 this->assign(__l.begin(), __l.size());
 return *this;
      }
# 825 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      iterator
      begin() noexcept
      { return iterator(_M_data()); }





      const_iterator
      begin() const noexcept
      { return const_iterator(_M_data()); }





      iterator
      end() noexcept
      { return iterator(_M_data() + this->size()); }





      const_iterator
      end() const noexcept
      { return const_iterator(_M_data() + this->size()); }






      reverse_iterator
      rbegin() noexcept
      { return reverse_iterator(this->end()); }






      const_reverse_iterator
      rbegin() const noexcept
      { return const_reverse_iterator(this->end()); }






      reverse_iterator
      rend() noexcept
      { return reverse_iterator(this->begin()); }






      const_reverse_iterator
      rend() const noexcept
      { return const_reverse_iterator(this->begin()); }






      const_iterator
      cbegin() const noexcept
      { return const_iterator(this->_M_data()); }





      const_iterator
      cend() const noexcept
      { return const_iterator(this->_M_data() + this->size()); }






      const_reverse_iterator
      crbegin() const noexcept
      { return const_reverse_iterator(this->end()); }






      const_reverse_iterator
      crend() const noexcept
      { return const_reverse_iterator(this->begin()); }


    public:



      size_type
      size() const noexcept
      { return _M_string_length; }



      size_type
      length() const noexcept
      { return _M_string_length; }


      size_type
      max_size() const noexcept
      { return (_Alloc_traits::max_size(_M_get_allocator()) - 1) / 2; }
# 954 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      void
      resize(size_type __n, _CharT __c);
# 967 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      void
      resize(size_type __n)
      { this->resize(__n, _CharT()); }



      void
      shrink_to_fit() noexcept
      {

 if (capacity() > size())
   {
     try
       { reserve(0); }
     catch(...)
       { }
   }

      }






      size_type
      capacity() const noexcept
      {
 return _M_is_local() ? size_type(_S_local_capacity)
                      : _M_allocated_capacity;
      }
# 1016 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      void
      reserve(size_type __res_arg = 0);




      void
      clear() noexcept
      { _M_set_length(0); }





      bool
      empty() const noexcept
      { return this->size() == 0; }
# 1045 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      const_reference
      operator[] (size_type __pos) const noexcept
      {
 ;
 return _M_data()[__pos];
      }
# 1062 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      reference
      operator[](size_type __pos)
      {


 ;

 ;
 return _M_data()[__pos];
      }
# 1083 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      const_reference
      at(size_type __n) const
      {
 if (__n >= this->size())
   __throw_out_of_range_fmt(("basic_string::at: __n " "(which is %zu) >= this->size() " "(which is %zu)")

                            ,
       __n, this->size());
 return _M_data()[__n];
      }
# 1104 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      reference
      at(size_type __n)
      {
 if (__n >= size())
   __throw_out_of_range_fmt(("basic_string::at: __n " "(which is %zu) >= this->size() " "(which is %zu)")

                            ,
       __n, this->size());
 return _M_data()[__n];
      }






      reference
      front() noexcept
      {
 ;
 return operator[](0);
      }





      const_reference
      front() const noexcept
      {
 ;
 return operator[](0);
      }





      reference
      back() noexcept
      {
 ;
 return operator[](this->size() - 1);
      }





      const_reference
      back() const noexcept
      {
 ;
 return operator[](this->size() - 1);
      }
# 1167 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      operator+=(const basic_string& __str)
      { return this->append(__str); }






      basic_string&
      operator+=(const _CharT* __s)
      { return this->append(__s); }






      basic_string&
      operator+=(_CharT __c)
      {
 this->push_back(__c);
 return *this;
      }







      basic_string&
      operator+=(initializer_list<_CharT> __l)
      { return this->append(__l.begin(), __l.size()); }
# 1220 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      append(const basic_string& __str)
      { return _M_append(__str._M_data(), __str.size()); }
# 1237 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      append(const basic_string& __str, size_type __pos, size_type __n = npos)
      { return _M_append(__str._M_data()
    + __str._M_check(__pos, "basic_string::append"),
    __str._M_limit(__pos, __n)); }







      basic_string&
      append(const _CharT* __s, size_type __n)
      {
 ;
 _M_check_length(size_type(0), __n, "basic_string::append");
 return _M_append(__s, __n);
      }






      basic_string&
      append(const _CharT* __s)
      {
 ;
 const size_type __n = traits_type::length(__s);
 _M_check_length(size_type(0), __n, "basic_string::append");
 return _M_append(__s, __n);
      }
# 1279 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      append(size_type __n, _CharT __c)
      { return _M_replace_aux(this->size(), size_type(0), __n, __c); }







      basic_string&
      append(initializer_list<_CharT> __l)
      { return this->append(__l.begin(), __l.size()); }
# 1303 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      template<class _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>



        basic_string&
        append(_InputIterator __first, _InputIterator __last)
        { return this->replace(end(), end(), __first, __last); }
# 1348 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      void
      push_back(_CharT __c)
      {
 const size_type __size = this->size();
 if (__size + 1 > this->capacity())
   this->_M_mutate(__size, size_type(0), 0, size_type(1));
 traits_type::assign(this->_M_data()[__size], __c);
 this->_M_set_length(__size + 1);
      }






      basic_string&
      assign(const basic_string& __str)
      {
 this->_M_assign(__str);
 return *this;
      }
# 1379 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      assign(basic_string&& __str)
      noexcept(_Alloc_traits::_S_nothrow_move())
      {


 return *this = std::move(__str);
      }
# 1402 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      assign(const basic_string& __str, size_type __pos, size_type __n = npos)
      { return _M_replace(size_type(0), this->size(), __str._M_data()
     + __str._M_check(__pos, "basic_string::assign"),
     __str._M_limit(__pos, __n)); }
# 1418 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      assign(const _CharT* __s, size_type __n)
      {
 ;
 return _M_replace(size_type(0), this->size(), __s, __n);
      }
# 1434 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      assign(const _CharT* __s)
      {
 ;
 return _M_replace(size_type(0), this->size(), __s,
     traits_type::length(__s));
      }
# 1451 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      assign(size_type __n, _CharT __c)
      { return _M_replace_aux(size_type(0), this->size(), __n, __c); }
# 1464 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      template<class _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>



        basic_string&
        assign(_InputIterator __first, _InputIterator __last)
        { return this->replace(begin(), end(), __first, __last); }







      basic_string&
      assign(initializer_list<_CharT> __l)
      { return this->assign(__l.begin(), __l.size()); }
# 1533 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      iterator
      insert(const_iterator __p, size_type __n, _CharT __c)
      {
 ;
 const size_type __pos = __p - begin();
 this->replace(__p, __p, __n, __c);
 return iterator(this->_M_data() + __pos);
      }
# 1575 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      template<class _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>
 iterator
        insert(const_iterator __p, _InputIterator __beg, _InputIterator __end)
        {
   ;
   const size_type __pos = __p - begin();
   this->replace(__p, __p, __beg, __end);
   return iterator(this->_M_data() + __pos);
 }
# 1611 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      iterator
      insert(const_iterator __p, initializer_list<_CharT> __l)
      { return this->insert(__p, __l.begin(), __l.end()); }
# 1638 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      insert(size_type __pos1, const basic_string& __str)
      { return this->replace(__pos1, size_type(0),
        __str._M_data(), __str.size()); }
# 1661 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      insert(size_type __pos1, const basic_string& __str,
      size_type __pos2, size_type __n = npos)
      { return this->replace(__pos1, size_type(0), __str._M_data()
        + __str._M_check(__pos2, "basic_string::insert"),
        __str._M_limit(__pos2, __n)); }
# 1684 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      insert(size_type __pos, const _CharT* __s, size_type __n)
      { return this->replace(__pos, size_type(0), __s, __n); }
# 1703 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      insert(size_type __pos, const _CharT* __s)
      {
 ;
 return this->replace(__pos, size_type(0), __s,
        traits_type::length(__s));
      }
# 1727 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      insert(size_type __pos, size_type __n, _CharT __c)
      { return _M_replace_aux(_M_check(__pos, "basic_string::insert"),
         size_type(0), __n, __c); }
# 1745 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      iterator
      insert(__const_iterator __p, _CharT __c)
      {
 ;
 const size_type __pos = __p - begin();
 _M_replace_aux(__pos, size_type(0), size_type(1), __c);
 return iterator(_M_data() + __pos);
      }
# 1806 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      erase(size_type __pos = 0, size_type __n = npos)
      {
 _M_check(__pos, "basic_string::erase");
 if (__n == npos)
   this->_M_set_length(__pos);
 else if (__n != 0)
   this->_M_erase(__pos, _M_limit(__pos, __n));
 return *this;
      }
# 1825 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      iterator
      erase(__const_iterator __position)
      {

                           ;
 const size_type __pos = __position - begin();
 this->_M_erase(__pos, size_type(1));
 return iterator(_M_data() + __pos);
      }
# 1844 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      iterator
      erase(__const_iterator __first, __const_iterator __last)
      {

                        ;
        const size_type __pos = __first - begin();
 if (__last == end())
   this->_M_set_length(__pos);
 else
   this->_M_erase(__pos, __last - __first);
 return iterator(this->_M_data() + __pos);
      }







      void
      pop_back() noexcept
      {
 ;
 _M_erase(size() - 1, 1);
      }
# 1888 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      replace(size_type __pos, size_type __n, const basic_string& __str)
      { return this->replace(__pos, __n, __str._M_data(), __str.size()); }
# 1910 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      replace(size_type __pos1, size_type __n1, const basic_string& __str,
       size_type __pos2, size_type __n2 = npos)
      { return this->replace(__pos1, __n1, __str._M_data()
        + __str._M_check(__pos2, "basic_string::replace"),
        __str._M_limit(__pos2, __n2)); }
# 1935 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      replace(size_type __pos, size_type __n1, const _CharT* __s,
       size_type __n2)
      {
 ;
 return _M_replace(_M_check(__pos, "basic_string::replace"),
     _M_limit(__pos, __n1), __s, __n2);
      }
# 1960 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      replace(size_type __pos, size_type __n1, const _CharT* __s)
      {
 ;
 return this->replace(__pos, __n1, __s, traits_type::length(__s));
      }
# 1984 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      replace(size_type __pos, size_type __n1, size_type __n2, _CharT __c)
      { return _M_replace_aux(_M_check(__pos, "basic_string::replace"),
         _M_limit(__pos, __n1), __n2, __c); }
# 2002 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      replace(__const_iterator __i1, __const_iterator __i2,
       const basic_string& __str)
      { return this->replace(__i1, __i2, __str._M_data(), __str.size()); }
# 2022 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      replace(__const_iterator __i1, __const_iterator __i2,
       const _CharT* __s, size_type __n)
      {

                      ;
 return this->replace(__i1 - begin(), __i2 - __i1, __s, __n);
      }
# 2044 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      replace(__const_iterator __i1, __const_iterator __i2, const _CharT* __s)
      {
 ;
 return this->replace(__i1, __i2, __s, traits_type::length(__s));
      }
# 2065 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      replace(__const_iterator __i1, __const_iterator __i2, size_type __n,
       _CharT __c)
      {

                      ;
 return _M_replace_aux(__i1 - begin(), __i2 - __i1, __n, __c);
      }
# 2090 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      template<class _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>
        basic_string&
        replace(const_iterator __i1, const_iterator __i2,
  _InputIterator __k1, _InputIterator __k2)
        {
  
                        ;
   ;
   return this->_M_replace_dispatch(__i1, __i2, __k1, __k2,
        std::__false_type());
 }
# 2122 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string&
      replace(__const_iterator __i1, __const_iterator __i2,
       _CharT* __k1, _CharT* __k2)
      {

                      ;
 ;
 return this->replace(__i1 - begin(), __i2 - __i1,
        __k1, __k2 - __k1);
      }

      basic_string&
      replace(__const_iterator __i1, __const_iterator __i2,
       const _CharT* __k1, const _CharT* __k2)
      {

                      ;
 ;
 return this->replace(__i1 - begin(), __i2 - __i1,
        __k1, __k2 - __k1);
      }

      basic_string&
      replace(__const_iterator __i1, __const_iterator __i2,
       iterator __k1, iterator __k2)
      {

                      ;
 ;
 return this->replace(__i1 - begin(), __i2 - __i1,
        __k1.base(), __k2 - __k1);
      }

      basic_string&
      replace(__const_iterator __i1, __const_iterator __i2,
       const_iterator __k1, const_iterator __k2)
      {

                      ;
 ;
 return this->replace(__i1 - begin(), __i2 - __i1,
        __k1.base(), __k2 - __k1);
      }
# 2181 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string& replace(const_iterator __i1, const_iterator __i2,
       initializer_list<_CharT> __l)
      { return this->replace(__i1, __i2, __l.begin(), __l.size()); }
# 2241 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
    private:
      template<class _Integer>
 basic_string&
 _M_replace_dispatch(const_iterator __i1, const_iterator __i2,
       _Integer __n, _Integer __val, __true_type)
        { return _M_replace_aux(__i1 - begin(), __i2 - __i1, __n, __val); }

      template<class _InputIterator>
 basic_string&
 _M_replace_dispatch(const_iterator __i1, const_iterator __i2,
       _InputIterator __k1, _InputIterator __k2,
       __false_type);

      basic_string&
      _M_replace_aux(size_type __pos1, size_type __n1, size_type __n2,
       _CharT __c);

      basic_string&
      _M_replace(size_type __pos, size_type __len1, const _CharT* __s,
   const size_type __len2);

      basic_string&
      _M_append(const _CharT* __s, size_type __n);

    public:
# 2279 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      copy(_CharT* __s, size_type __n, size_type __pos = 0) const;
# 2289 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      void
      swap(basic_string& __s) noexcept;
# 2299 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      const _CharT*
      c_str() const noexcept
      { return _M_data(); }
# 2311 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      const _CharT*
      data() const noexcept
      { return _M_data(); }
# 2330 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      allocator_type
      get_allocator() const noexcept
      { return _M_get_allocator(); }
# 2346 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find(const _CharT* __s, size_type __pos, size_type __n) const
      noexcept;
# 2360 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find(const basic_string& __str, size_type __pos = 0) const
      noexcept
      { return this->find(__str.data(), __pos, __str.size()); }
# 2392 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find(const _CharT* __s, size_type __pos = 0) const noexcept
      {
 ;
 return this->find(__s, __pos, traits_type::length(__s));
      }
# 2409 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find(_CharT __c, size_type __pos = 0) const noexcept;
# 2422 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      rfind(const basic_string& __str, size_type __pos = npos) const
      noexcept
      { return this->rfind(__str.data(), __pos, __str.size()); }
# 2456 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      rfind(const _CharT* __s, size_type __pos, size_type __n) const
      noexcept;
# 2470 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      rfind(const _CharT* __s, size_type __pos = npos) const
      {
 ;
 return this->rfind(__s, __pos, traits_type::length(__s));
      }
# 2487 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      rfind(_CharT __c, size_type __pos = npos) const noexcept;
# 2501 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_first_of(const basic_string& __str, size_type __pos = 0) const
      noexcept
      { return this->find_first_of(__str.data(), __pos, __str.size()); }
# 2536 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_first_of(const _CharT* __s, size_type __pos, size_type __n) const
      noexcept;
# 2550 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_first_of(const _CharT* __s, size_type __pos = 0) const
      noexcept
      {
 ;
 return this->find_first_of(__s, __pos, traits_type::length(__s));
      }
# 2570 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_first_of(_CharT __c, size_type __pos = 0) const noexcept
      { return this->find(__c, __pos); }
# 2585 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_last_of(const basic_string& __str, size_type __pos = npos) const
      noexcept
      { return this->find_last_of(__str.data(), __pos, __str.size()); }
# 2620 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_last_of(const _CharT* __s, size_type __pos, size_type __n) const
      noexcept;
# 2634 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_last_of(const _CharT* __s, size_type __pos = npos) const
      noexcept
      {
 ;
 return this->find_last_of(__s, __pos, traits_type::length(__s));
      }
# 2654 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_last_of(_CharT __c, size_type __pos = npos) const noexcept
      { return this->rfind(__c, __pos); }
# 2668 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_first_not_of(const basic_string& __str, size_type __pos = 0) const
      noexcept
      { return this->find_first_not_of(__str.data(), __pos, __str.size()); }
# 2703 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_first_not_of(const _CharT* __s, size_type __pos,
   size_type __n) const noexcept;
# 2717 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_first_not_of(const _CharT* __s, size_type __pos = 0) const
      noexcept
      {
 ;
 return this->find_first_not_of(__s, __pos, traits_type::length(__s));
      }
# 2735 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_first_not_of(_CharT __c, size_type __pos = 0) const
      noexcept;
# 2750 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_last_not_of(const basic_string& __str, size_type __pos = npos) const
      noexcept
      { return this->find_last_not_of(__str.data(), __pos, __str.size()); }
# 2785 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_last_not_of(const _CharT* __s, size_type __pos,
         size_type __n) const noexcept;
# 2799 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_last_not_of(const _CharT* __s, size_type __pos = npos) const
      noexcept
      {
 ;
 return this->find_last_not_of(__s, __pos, traits_type::length(__s));
      }
# 2817 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      size_type
      find_last_not_of(_CharT __c, size_type __pos = npos) const
      noexcept;
# 2833 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      basic_string
      substr(size_type __pos = 0, size_type __n = npos) const
      { return basic_string(*this,
       _M_check(__pos, "basic_string::substr"), __n); }
# 2852 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      int
      compare(const basic_string& __str) const
      {
 const size_type __size = this->size();
 const size_type __osize = __str.size();
 const size_type __len = std::min(__size, __osize);

 int __r = traits_type::compare(_M_data(), __str.data(), __len);
 if (!__r)
   __r = _S_compare(__size, __osize);
 return __r;
      }
# 2945 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      int
      compare(size_type __pos, size_type __n, const basic_string& __str) const;
# 2971 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      int
      compare(size_type __pos1, size_type __n1, const basic_string& __str,
       size_type __pos2, size_type __n2 = npos) const;
# 2989 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      int
      compare(const _CharT* __s) const noexcept;
# 3013 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      int
      compare(size_type __pos, size_type __n1, const _CharT* __s) const;
# 3040 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      int
      compare(size_type __pos, size_type __n1, const _CharT* __s,
       size_type __n2) const;
# 3071 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
      template<typename, typename, typename> friend class basic_stringbuf;
    };
}
# 6018 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>
    operator+(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
       const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    {
      basic_string<_CharT, _Traits, _Alloc> __str(__lhs);
      __str.append(__rhs);
      return __str;
    }







  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT,_Traits,_Alloc>
    operator+(const _CharT* __lhs,
       const basic_string<_CharT,_Traits,_Alloc>& __rhs);







  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT,_Traits,_Alloc>
    operator+(_CharT __lhs, const basic_string<_CharT,_Traits,_Alloc>& __rhs);







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_string<_CharT, _Traits, _Alloc>
    operator+(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
       const _CharT* __rhs)
    {
      basic_string<_CharT, _Traits, _Alloc> __str(__lhs);
      __str.append(__rhs);
      return __str;
    }







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_string<_CharT, _Traits, _Alloc>
    operator+(const basic_string<_CharT, _Traits, _Alloc>& __lhs, _CharT __rhs)
    {
      typedef basic_string<_CharT, _Traits, _Alloc> __string_type;
      typedef typename __string_type::size_type __size_type;
      __string_type __str(__lhs);
      __str.append(__size_type(1), __rhs);
      return __str;
    }


  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_string<_CharT, _Traits, _Alloc>
    operator+(basic_string<_CharT, _Traits, _Alloc>&& __lhs,
       const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return std::move(__lhs.append(__rhs)); }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_string<_CharT, _Traits, _Alloc>
    operator+(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
       basic_string<_CharT, _Traits, _Alloc>&& __rhs)
    { return std::move(__rhs.insert(0, __lhs)); }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_string<_CharT, _Traits, _Alloc>
    operator+(basic_string<_CharT, _Traits, _Alloc>&& __lhs,
       basic_string<_CharT, _Traits, _Alloc>&& __rhs)
    {
      const auto __size = __lhs.size() + __rhs.size();
      const bool __cond = (__size > __lhs.capacity()
      && __size <= __rhs.capacity());
      return __cond ? std::move(__rhs.insert(0, __lhs))
             : std::move(__lhs.append(__rhs));
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_string<_CharT, _Traits, _Alloc>
    operator+(const _CharT* __lhs,
       basic_string<_CharT, _Traits, _Alloc>&& __rhs)
    { return std::move(__rhs.insert(0, __lhs)); }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_string<_CharT, _Traits, _Alloc>
    operator+(_CharT __lhs,
       basic_string<_CharT, _Traits, _Alloc>&& __rhs)
    { return std::move(__rhs.insert(0, 1, __lhs)); }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_string<_CharT, _Traits, _Alloc>
    operator+(basic_string<_CharT, _Traits, _Alloc>&& __lhs,
       const _CharT* __rhs)
    { return std::move(__lhs.append(__rhs)); }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_string<_CharT, _Traits, _Alloc>
    operator+(basic_string<_CharT, _Traits, _Alloc>&& __lhs,
       _CharT __rhs)
    { return std::move(__lhs.append(1, __rhs)); }
# 6139 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
        const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    noexcept
    { return __lhs.compare(__rhs) == 0; }

  template<typename _CharT>
    inline
    typename __gnu_cxx::__enable_if<__is_char<_CharT>::__value, bool>::__type
    operator==(const basic_string<_CharT>& __lhs,
        const basic_string<_CharT>& __rhs) noexcept
    { return (__lhs.size() == __rhs.size()
       && !std::char_traits<_CharT>::compare(__lhs.data(), __rhs.data(),
          __lhs.size())); }







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator==(const _CharT* __lhs,
        const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __rhs.compare(__lhs) == 0; }







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
        const _CharT* __rhs)
    { return __lhs.compare(__rhs) == 0; }
# 6186 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator!=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
        const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    noexcept
    { return !(__lhs == __rhs); }







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator!=(const _CharT* __lhs,
        const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return !(__lhs == __rhs); }







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator!=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
        const _CharT* __rhs)
    { return !(__lhs == __rhs); }
# 6224 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator<(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
       const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    noexcept
    { return __lhs.compare(__rhs) < 0; }







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator<(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
       const _CharT* __rhs)
    { return __lhs.compare(__rhs) < 0; }







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator<(const _CharT* __lhs,
       const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __rhs.compare(__lhs) > 0; }
# 6262 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator>(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
       const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    noexcept
    { return __lhs.compare(__rhs) > 0; }







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator>(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
       const _CharT* __rhs)
    { return __lhs.compare(__rhs) > 0; }







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator>(const _CharT* __lhs,
       const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __rhs.compare(__lhs) < 0; }
# 6300 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator<=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
        const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    noexcept
    { return __lhs.compare(__rhs) <= 0; }







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator<=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
        const _CharT* __rhs)
    { return __lhs.compare(__rhs) <= 0; }







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator<=(const _CharT* __lhs,
        const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __rhs.compare(__lhs) >= 0; }
# 6338 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator>=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
        const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    noexcept
    { return __lhs.compare(__rhs) >= 0; }







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator>=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
        const _CharT* __rhs)
    { return __lhs.compare(__rhs) >= 0; }







  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator>=(const _CharT* __lhs,
      const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __rhs.compare(__lhs) <= 0; }
# 6376 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    inline void
    swap(basic_string<_CharT, _Traits, _Alloc>& __lhs,
  basic_string<_CharT, _Traits, _Alloc>& __rhs)
    noexcept(noexcept(__lhs.swap(__rhs)))
    { __lhs.swap(__rhs); }
# 6396 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_istream<_CharT, _Traits>&
    operator>>(basic_istream<_CharT, _Traits>& __is,
        basic_string<_CharT, _Traits, _Alloc>& __str);

  template<>
    basic_istream<char>&
    operator>>(basic_istream<char>& __is, basic_string<char>& __str);
# 6414 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
        const basic_string<_CharT, _Traits, _Alloc>& __str)
    {


      return __ostream_insert(__os, __str.data(), __str.size());
    }
# 6437 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_istream<_CharT, _Traits>&
    getline(basic_istream<_CharT, _Traits>& __is,
     basic_string<_CharT, _Traits, _Alloc>& __str, _CharT __delim);
# 6454 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_istream<_CharT, _Traits>&
    getline(basic_istream<_CharT, _Traits>& __is,
     basic_string<_CharT, _Traits, _Alloc>& __str)
    { return std::getline(__is, __str, __is.widen('\n')); }



  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_istream<_CharT, _Traits>&
    getline(basic_istream<_CharT, _Traits>&& __is,
     basic_string<_CharT, _Traits, _Alloc>& __str, _CharT __delim)
    { return std::getline(__is, __str, __delim); }


  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_istream<_CharT, _Traits>&
    getline(basic_istream<_CharT, _Traits>&& __is,
     basic_string<_CharT, _Traits, _Alloc>& __str)
    { return std::getline(__is, __str); }


  template<>
    basic_istream<char>&
    getline(basic_istream<char>& __in, basic_string<char>& __str,
     char __delim);


  template<>
    basic_istream<wchar_t>&
    getline(basic_istream<wchar_t>& __in, basic_string<wchar_t>& __str,
     wchar_t __delim);



}



# 1 "/usr/include/c++/9.2.0/ext/string_conversions.h" 1 3
# 32 "/usr/include/c++/9.2.0/ext/string_conversions.h" 3
       
# 33 "/usr/include/c++/9.2.0/ext/string_conversions.h" 3
# 41 "/usr/include/c++/9.2.0/ext/string_conversions.h" 3
# 1 "/usr/include/c++/9.2.0/cstdlib" 1 3
# 39 "/usr/include/c++/9.2.0/cstdlib" 3
       
# 40 "/usr/include/c++/9.2.0/cstdlib" 3
# 75 "/usr/include/c++/9.2.0/cstdlib" 3
# 1 "/usr/include/stdlib.h" 1 3 4
# 25 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 26 "/usr/include/stdlib.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 1 3 4
# 32 "/usr/include/stdlib.h" 2 3 4

extern "C" {





# 1 "/usr/include/bits/waitflags.h" 1 3 4
# 40 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/bits/waitstatus.h" 1 3 4
# 41 "/usr/include/stdlib.h" 2 3 4
# 58 "/usr/include/stdlib.h" 3 4
typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;





__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
# 97 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) throw () ;



extern double atof (const char *__nptr)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (const char *__nptr)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (const char *__nptr)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



__extension__ extern long long int atoll (const char *__nptr)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     throw () __attribute__ ((__nonnull__ (1)));



extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) throw () __attribute__ ((__nonnull__ (1)));

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     throw () __attribute__ ((__nonnull__ (1)));
# 140 "/usr/include/stdlib.h" 3 4
extern _Float32 strtof32 (const char *__restrict __nptr,
     char **__restrict __endptr)
     throw () __attribute__ ((__nonnull__ (1)));



extern _Float64 strtof64 (const char *__restrict __nptr,
     char **__restrict __endptr)
     throw () __attribute__ ((__nonnull__ (1)));



extern _Float128 strtof128 (const char *__restrict __nptr,
       char **__restrict __endptr)
     throw () __attribute__ ((__nonnull__ (1)));



extern _Float32x strtof32x (const char *__restrict __nptr,
       char **__restrict __endptr)
     throw () __attribute__ ((__nonnull__ (1)));



extern _Float64x strtof64x (const char *__restrict __nptr,
       char **__restrict __endptr)
     throw () __attribute__ ((__nonnull__ (1)));
# 176 "/usr/include/stdlib.h" 3 4
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     throw () __attribute__ ((__nonnull__ (1)));

extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     throw () __attribute__ ((__nonnull__ (1)));



__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     throw () __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     throw () __attribute__ ((__nonnull__ (1)));




__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     throw () __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     throw () __attribute__ ((__nonnull__ (1)));




extern int strfromd (char *__dest, size_t __size, const char *__format,
       double __f)
     throw () __attribute__ ((__nonnull__ (3)));

extern int strfromf (char *__dest, size_t __size, const char *__format,
       float __f)
     throw () __attribute__ ((__nonnull__ (3)));

extern int strfroml (char *__dest, size_t __size, const char *__format,
       long double __f)
     throw () __attribute__ ((__nonnull__ (3)));
# 232 "/usr/include/stdlib.h" 3 4
extern int strfromf32 (char *__dest, size_t __size, const char * __format,
         _Float32 __f)
     throw () __attribute__ ((__nonnull__ (3)));



extern int strfromf64 (char *__dest, size_t __size, const char * __format,
         _Float64 __f)
     throw () __attribute__ ((__nonnull__ (3)));



extern int strfromf128 (char *__dest, size_t __size, const char * __format,
   _Float128 __f)
     throw () __attribute__ ((__nonnull__ (3)));



extern int strfromf32x (char *__dest, size_t __size, const char * __format,
   _Float32x __f)
     throw () __attribute__ ((__nonnull__ (3)));



extern int strfromf64x (char *__dest, size_t __size, const char * __format,
   _Float64x __f)
     throw () __attribute__ ((__nonnull__ (3)));
# 274 "/usr/include/stdlib.h" 3 4
extern long int strtol_l (const char *__restrict __nptr,
     char **__restrict __endptr, int __base,
     locale_t __loc) throw () __attribute__ ((__nonnull__ (1, 4)));

extern unsigned long int strtoul_l (const char *__restrict __nptr,
        char **__restrict __endptr,
        int __base, locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 4)));

__extension__
extern long long int strtoll_l (const char *__restrict __nptr,
    char **__restrict __endptr, int __base,
    locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 4)));

__extension__
extern unsigned long long int strtoull_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 4)));

extern double strtod_l (const char *__restrict __nptr,
   char **__restrict __endptr, locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 3)));

extern float strtof_l (const char *__restrict __nptr,
         char **__restrict __endptr, locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 3)));

extern long double strtold_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 3)));
# 316 "/usr/include/stdlib.h" 3 4
extern _Float32 strtof32_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 3)));



extern _Float64 strtof64_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 3)));



extern _Float128 strtof128_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 3)));



extern _Float32x strtof32x_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 3)));



extern _Float64x strtof64x_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 3)));
# 385 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) throw () ;


extern long int a64l (const char *__s)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;




# 1 "/usr/include/sys/types.h" 1 3 4
# 27 "/usr/include/sys/types.h" 3 4
extern "C" {





typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;


typedef __loff_t loff_t;




typedef __ino_t ino_t;






typedef __ino64_t ino64_t;




typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;






typedef __off64_t off64_t;
# 103 "/usr/include/sys/types.h" 3 4
typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 134 "/usr/include/sys/types.h" 3 4
typedef __useconds_t useconds_t;



typedef __suseconds_t suseconds_t;





# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 1 3 4
# 145 "/usr/include/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;







typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;


typedef int register_t __attribute__ ((__mode__ (__word__)));
# 179 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/sys/select.h" 1 3 4
# 30 "/usr/include/sys/select.h" 3 4
# 1 "/usr/include/bits/select.h" 1 3 4
# 22 "/usr/include/bits/select.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 23 "/usr/include/bits/select.h" 2 3 4
# 31 "/usr/include/sys/select.h" 2 3 4


# 1 "/usr/include/bits/types/sigset_t.h" 1 3 4



# 1 "/usr/include/bits/types/__sigset_t.h" 1 3 4




typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
# 5 "/usr/include/bits/types/sigset_t.h" 2 3 4


typedef __sigset_t sigset_t;
# 34 "/usr/include/sys/select.h" 2 3 4
# 49 "/usr/include/sys/select.h" 3 4
typedef long int __fd_mask;
# 59 "/usr/include/sys/select.h" 3 4
typedef struct
  {



    __fd_mask fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];





  } fd_set;






typedef __fd_mask fd_mask;
# 91 "/usr/include/sys/select.h" 3 4
extern "C" {
# 101 "/usr/include/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 113 "/usr/include/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
# 126 "/usr/include/sys/select.h" 3 4
}
# 180 "/usr/include/sys/types.h" 2 3 4





typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 219 "/usr/include/sys/types.h" 3 4
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
# 230 "/usr/include/sys/types.h" 3 4
}
# 395 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) throw ();


extern void srandom (unsigned int __seed) throw ();





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) throw () __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) throw () __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) throw () __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     throw () __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     throw () __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     throw () __attribute__ ((__nonnull__ (1, 2)));





extern int rand (void) throw ();

extern void srand (unsigned int __seed) throw ();



extern int rand_r (unsigned int *__seed) throw ();







extern double drand48 (void) throw ();
extern double erand48 (unsigned short int __xsubi[3]) throw () __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) throw ();
extern long int nrand48 (unsigned short int __xsubi[3])
     throw () __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) throw ();
extern long int jrand48 (unsigned short int __xsubi[3])
     throw () __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) throw ();
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     throw () __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) throw () __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) throw () __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) throw () __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     throw () __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     throw () __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     throw () __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) throw () __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     throw () __attribute__ ((__nonnull__ (1, 2)));




extern void *malloc (size_t __size) throw () __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;

extern void *calloc (size_t __nmemb, size_t __size)
     throw () __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2))) ;






extern void *realloc (void *__ptr, size_t __size)
     throw () __attribute__ ((__warn_unused_result__)) __attribute__ ((__alloc_size__ (2)));







extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     throw () __attribute__ ((__warn_unused_result__))
     __attribute__ ((__alloc_size__ (2, 3)));



extern void free (void *__ptr) throw ();


# 1 "/usr/include/alloca.h" 1 3 4
# 24 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 1 3 4
# 25 "/usr/include/alloca.h" 2 3 4

extern "C" {





extern void *alloca (size_t __size) throw ();





}
# 569 "/usr/include/stdlib.h" 2 3 4





extern void *valloc (size_t __size) throw () __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     throw () __attribute__ ((__nonnull__ (1))) ;




extern void *aligned_alloc (size_t __alignment, size_t __size)
     throw () __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (2))) ;



extern void abort (void) throw () __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) throw () __attribute__ ((__nonnull__ (1)));




extern "C++" int at_quick_exit (void (*__func) (void))
     throw () __asm ("at_quick_exit") __attribute__ ((__nonnull__ (1)));
# 610 "/usr/include/stdlib.h" 3 4
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     throw () __attribute__ ((__nonnull__ (1)));





extern void exit (int __status) throw () __attribute__ ((__noreturn__));





extern void quick_exit (int __status) throw () __attribute__ ((__noreturn__));





extern void _Exit (int __status) throw () __attribute__ ((__noreturn__));




extern char *getenv (const char *__name) throw () __attribute__ ((__nonnull__ (1))) ;




extern char *secure_getenv (const char *__name)
     throw () __attribute__ ((__nonnull__ (1))) ;






extern int putenv (char *__string) throw () __attribute__ ((__nonnull__ (1)));





extern int setenv (const char *__name, const char *__value, int __replace)
     throw () __attribute__ ((__nonnull__ (2)));


extern int unsetenv (const char *__name) throw () __attribute__ ((__nonnull__ (1)));






extern int clearenv (void) throw ();
# 675 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) throw () __attribute__ ((__nonnull__ (1)));
# 688 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 698 "/usr/include/stdlib.h" 3 4
extern int mkstemp64 (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 710 "/usr/include/stdlib.h" 3 4
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 720 "/usr/include/stdlib.h" 3 4
extern int mkstemps64 (char *__template, int __suffixlen)
     __attribute__ ((__nonnull__ (1))) ;
# 731 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) throw () __attribute__ ((__nonnull__ (1))) ;
# 742 "/usr/include/stdlib.h" 3 4
extern int mkostemp (char *__template, int __flags) __attribute__ ((__nonnull__ (1))) ;
# 752 "/usr/include/stdlib.h" 3 4
extern int mkostemp64 (char *__template, int __flags) __attribute__ ((__nonnull__ (1))) ;
# 762 "/usr/include/stdlib.h" 3 4
extern int mkostemps (char *__template, int __suffixlen, int __flags)
     __attribute__ ((__nonnull__ (1))) ;
# 774 "/usr/include/stdlib.h" 3 4
extern int mkostemps64 (char *__template, int __suffixlen, int __flags)
     __attribute__ ((__nonnull__ (1))) ;
# 784 "/usr/include/stdlib.h" 3 4
extern int system (const char *__command) ;





extern char *canonicalize_file_name (const char *__name)
     throw () __attribute__ ((__nonnull__ (1))) ;
# 800 "/usr/include/stdlib.h" 3 4
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) throw () ;






typedef int (*__compar_fn_t) (const void *, const void *);


typedef __compar_fn_t comparison_fn_t;



typedef int (*__compar_d_fn_t) (const void *, const void *, void *);




extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;







extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));

extern void qsort_r (void *__base, size_t __nmemb, size_t __size,
       __compar_d_fn_t __compar, void *__arg)
  __attribute__ ((__nonnull__ (1, 4)));




extern int abs (int __x) throw () __attribute__ ((__const__)) ;
extern long int labs (long int __x) throw () __attribute__ ((__const__)) ;


__extension__ extern long long int llabs (long long int __x)
     throw () __attribute__ ((__const__)) ;






extern div_t div (int __numer, int __denom)
     throw () __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     throw () __attribute__ ((__const__)) ;


__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     throw () __attribute__ ((__const__)) ;
# 872 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) throw () __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) throw () __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     throw () __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     throw () __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     throw () __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     throw () __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) throw () __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) throw () __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     throw () __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     throw () __attribute__ ((__nonnull__ (3, 4, 5)));





extern int mblen (const char *__s, size_t __n) throw ();


extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) throw ();


extern int wctomb (char *__s, wchar_t __wchar) throw ();



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) throw ();

extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     throw ();







extern int rpmatch (const char *__response) throw () __attribute__ ((__nonnull__ (1))) ;
# 957 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     throw () __attribute__ ((__nonnull__ (1, 2, 3))) ;







extern int posix_openpt (int __oflag) ;







extern int grantpt (int __fd) throw ();



extern int unlockpt (int __fd) throw ();




extern char *ptsname (int __fd) throw () ;






extern int ptsname_r (int __fd, char *__buf, size_t __buflen)
     throw () __attribute__ ((__nonnull__ (2)));


extern int getpt (void);






extern int getloadavg (double __loadavg[], int __nelem)
     throw () __attribute__ ((__nonnull__ (1)));
# 1013 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/bits/stdlib-float.h" 1 3 4
# 1014 "/usr/include/stdlib.h" 2 3 4
# 1023 "/usr/include/stdlib.h" 3 4
}
# 76 "/usr/include/c++/9.2.0/cstdlib" 2 3

# 1 "/usr/include/c++/9.2.0/bits/std_abs.h" 1 3
# 33 "/usr/include/c++/9.2.0/bits/std_abs.h" 3
       
# 34 "/usr/include/c++/9.2.0/bits/std_abs.h" 3
# 46 "/usr/include/c++/9.2.0/bits/std_abs.h" 3
extern "C++"
{
namespace std __attribute__ ((__visibility__ ("default")))
{


  using ::abs;


  inline long
  abs(long __i) { return __builtin_labs(__i); }



  inline long long
  abs(long long __x) { return __builtin_llabs (__x); }
# 70 "/usr/include/c++/9.2.0/bits/std_abs.h" 3
  inline constexpr double
  abs(double __x)
  { return __builtin_fabs(__x); }

  inline constexpr float
  abs(float __x)
  { return __builtin_fabsf(__x); }

  inline constexpr long double
  abs(long double __x)
  { return __builtin_fabsl(__x); }



  inline constexpr __int128
  abs(__int128 __x) { return __x >= 0 ? __x : -__x; }
# 101 "/usr/include/c++/9.2.0/bits/std_abs.h" 3
  inline constexpr
  __float128
  abs(__float128 __x)
  { return __x < 0 ? -__x : __x; }



}
}
# 78 "/usr/include/c++/9.2.0/cstdlib" 2 3
# 121 "/usr/include/c++/9.2.0/cstdlib" 3
extern "C++"
{
namespace std __attribute__ ((__visibility__ ("default")))
{


  using ::div_t;
  using ::ldiv_t;

  using ::abort;



  using ::atexit;


  using ::at_quick_exit;


  using ::atof;
  using ::atoi;
  using ::atol;
  using ::bsearch;
  using ::calloc;
  using ::div;
  using ::exit;
  using ::free;
  using ::getenv;
  using ::labs;
  using ::ldiv;
  using ::malloc;

  using ::mblen;
  using ::mbstowcs;
  using ::mbtowc;

  using ::qsort;


  using ::quick_exit;


  using ::rand;
  using ::realloc;
  using ::srand;
  using ::strtod;
  using ::strtol;
  using ::strtoul;
  using ::system;

  using ::wcstombs;
  using ::wctomb;



  inline ldiv_t
  div(long __i, long __j) { return ldiv(__i, __j); }




}
# 195 "/usr/include/c++/9.2.0/cstdlib" 3
namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{



  using ::lldiv_t;





  using ::_Exit;



  using ::llabs;

  inline lldiv_t
  div(long long __n, long long __d)
  { lldiv_t __q; __q.quot = __n / __d; __q.rem = __n % __d; return __q; }

  using ::lldiv;
# 227 "/usr/include/c++/9.2.0/cstdlib" 3
  using ::atoll;
  using ::strtoll;
  using ::strtoull;

  using ::strtof;
  using ::strtold;


}

namespace std
{

  using ::__gnu_cxx::lldiv_t;

  using ::__gnu_cxx::_Exit;

  using ::__gnu_cxx::llabs;
  using ::__gnu_cxx::div;
  using ::__gnu_cxx::lldiv;

  using ::__gnu_cxx::atoll;
  using ::__gnu_cxx::strtof;
  using ::__gnu_cxx::strtoll;
  using ::__gnu_cxx::strtoull;
  using ::__gnu_cxx::strtold;
}



}
# 42 "/usr/include/c++/9.2.0/ext/string_conversions.h" 2 3
# 1 "/usr/include/c++/9.2.0/cwchar" 1 3
# 39 "/usr/include/c++/9.2.0/cwchar" 3
       
# 40 "/usr/include/c++/9.2.0/cwchar" 3
# 43 "/usr/include/c++/9.2.0/ext/string_conversions.h" 2 3
# 1 "/usr/include/c++/9.2.0/cstdio" 1 3
# 39 "/usr/include/c++/9.2.0/cstdio" 3
       
# 40 "/usr/include/c++/9.2.0/cstdio" 3


# 1 "/usr/include/stdio.h" 1 3 4
# 27 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 28 "/usr/include/stdio.h" 2 3 4

extern "C" {



# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 1 3 4
# 34 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stdarg.h" 1 3 4
# 37 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/include/bits/types/__fpos_t.h" 1 3 4
# 10 "/usr/include/bits/types/__fpos_t.h" 3 4
typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
# 40 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/bits/types/__fpos64_t.h" 1 3 4
# 10 "/usr/include/bits/types/__fpos64_t.h" 3 4
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
# 41 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/include/bits/types/struct_FILE.h" 1 3 4
# 35 "/usr/include/bits/types/struct_FILE.h" 3 4
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;




typedef void _IO_lock_t;





struct _IO_FILE
{
  int _flags;


  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;


  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _flags2;
  __off_t _old_offset;


  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  _IO_lock_t *_lock;







  __off64_t _offset;

  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
# 44 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/include/bits/types/cookie_io_functions_t.h" 1 3 4
# 27 "/usr/include/bits/types/cookie_io_functions_t.h" 3 4
typedef __ssize_t cookie_read_function_t (void *__cookie, char *__buf,
                                          size_t __nbytes);







typedef __ssize_t cookie_write_function_t (void *__cookie, const char *__buf,
                                           size_t __nbytes);







typedef int cookie_seek_function_t (void *__cookie, __off64_t *__pos, int __w);


typedef int cookie_close_function_t (void *__cookie);






typedef struct _IO_cookie_io_functions_t
{
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
# 47 "/usr/include/stdio.h" 2 3 4





typedef __gnuc_va_list va_list;
# 84 "/usr/include/stdio.h" 3 4
typedef __fpos_t fpos_t;




typedef __fpos64_t fpos64_t;
# 133 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 134 "/usr/include/stdio.h" 2 3 4



extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;






extern int remove (const char *__filename) throw ();

extern int rename (const char *__old, const char *__new) throw ();



extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) throw ();
# 164 "/usr/include/stdio.h" 3 4
extern int renameat2 (int __oldfd, const char *__old, int __newfd,
        const char *__new, unsigned int __flags) throw ();







extern FILE *tmpfile (void) ;
# 183 "/usr/include/stdio.h" 3 4
extern FILE *tmpfile64 (void) ;



extern char *tmpnam (char *__s) throw () ;




extern char *tmpnam_r (char *__s) throw () ;
# 204 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
     throw () __attribute__ ((__malloc__)) ;







extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);
# 227 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 237 "/usr/include/stdio.h" 3 4
extern int fcloseall (void);
# 246 "/usr/include/stdio.h" 3 4
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes) ;




extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 270 "/usr/include/stdio.h" 3 4
extern FILE *fopen64 (const char *__restrict __filename,
        const char *__restrict __modes) ;
extern FILE *freopen64 (const char *__restrict __filename,
   const char *__restrict __modes,
   FILE *__restrict __stream) ;




extern FILE *fdopen (int __fd, const char *__modes) throw () ;





extern FILE *fopencookie (void *__restrict __magic_cookie,
     const char *__restrict __modes,
     cookie_io_functions_t __io_funcs) throw () ;




extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  throw () ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) throw () ;





extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) throw ();



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) throw ();




extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) throw ();


extern void setlinebuf (FILE *__stream) throw ();







extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);




extern int printf (const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) throw ();





extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) throw ();



extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     throw () __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__printf__, 3, 0)));





extern int vasprintf (char **__restrict __ptr, const char *__restrict __f,
        __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__printf__, 2, 0))) ;
extern int __asprintf (char **__restrict __ptr,
         const char *__restrict __fmt, ...)
     throw () __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int asprintf (char **__restrict __ptr,
       const char *__restrict __fmt, ...)
     throw () __attribute__ ((__format__ (__printf__, 2, 3))) ;




extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));







extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;




extern int scanf (const char *__restrict __format, ...) ;

extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) throw ();






extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                               ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) throw () __asm__ ("" "__isoc99_sscanf")

                      ;
# 432 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__scanf__, 2, 0)));




extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) throw () __asm__ ("" "__isoc99_vsscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 485 "/usr/include/stdio.h" 3 4
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);






extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 510 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);
# 521 "/usr/include/stdio.h" 3 4
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);
# 537 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);







extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
# 587 "/usr/include/stdio.h" 3 4
extern char *fgets_unlocked (char *__restrict __s, int __n,
        FILE *__restrict __stream) ;
# 603 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) ;







extern int fputs (const char *__restrict __s, FILE *__restrict __stream);





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);
# 662 "/usr/include/stdio.h" 3 4
extern int fputs_unlocked (const char *__restrict __s,
      FILE *__restrict __stream);
# 673 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);







extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);
# 707 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream) ;
# 731 "/usr/include/stdio.h" 3 4
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 750 "/usr/include/stdio.h" 3 4
extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence);
extern __off64_t ftello64 (FILE *__stream) ;
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos);
extern int fsetpos64 (FILE *__stream, const fpos64_t *__pos);



extern void clearerr (FILE *__stream) throw ();

extern int feof (FILE *__stream) throw () ;

extern int ferror (FILE *__stream) throw () ;



extern void clearerr_unlocked (FILE *__stream) throw ();
extern int feof_unlocked (FILE *__stream) throw () ;
extern int ferror_unlocked (FILE *__stream) throw () ;







extern void perror (const char *__s);





# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 26 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern const char *const sys_errlist[];


extern int _sys_nerr;
extern const char *const _sys_errlist[];
# 782 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) throw () ;




extern int fileno_unlocked (FILE *__stream) throw () ;
# 800 "/usr/include/stdio.h" 3 4
extern FILE *popen (const char *__command, const char *__modes) ;





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) throw ();





extern char *cuserid (char *__s);




struct obstack;


extern int obstack_printf (struct obstack *__restrict __obstack,
      const char *__restrict __format, ...)
     throw () __attribute__ ((__format__ (__printf__, 2, 3)));
extern int obstack_vprintf (struct obstack *__restrict __obstack,
       const char *__restrict __format,
       __gnuc_va_list __args)
     throw () __attribute__ ((__format__ (__printf__, 2, 0)));







extern void flockfile (FILE *__stream) throw ();



extern int ftrylockfile (FILE *__stream) throw () ;


extern void funlockfile (FILE *__stream) throw ();
# 858 "/usr/include/stdio.h" 3 4
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
# 873 "/usr/include/stdio.h" 3 4
}
# 43 "/usr/include/c++/9.2.0/cstdio" 2 3
# 96 "/usr/include/c++/9.2.0/cstdio" 3
namespace std
{
  using ::FILE;
  using ::fpos_t;

  using ::clearerr;
  using ::fclose;
  using ::feof;
  using ::ferror;
  using ::fflush;
  using ::fgetc;
  using ::fgetpos;
  using ::fgets;
  using ::fopen;
  using ::fprintf;
  using ::fputc;
  using ::fputs;
  using ::fread;
  using ::freopen;
  using ::fscanf;
  using ::fseek;
  using ::fsetpos;
  using ::ftell;
  using ::fwrite;
  using ::getc;
  using ::getchar;




  using ::perror;
  using ::printf;
  using ::putc;
  using ::putchar;
  using ::puts;
  using ::remove;
  using ::rename;
  using ::rewind;
  using ::scanf;
  using ::setbuf;
  using ::setvbuf;
  using ::sprintf;
  using ::sscanf;
  using ::tmpfile;

  using ::tmpnam;

  using ::ungetc;
  using ::vfprintf;
  using ::vprintf;
  using ::vsprintf;
}
# 157 "/usr/include/c++/9.2.0/cstdio" 3
namespace __gnu_cxx
{
# 175 "/usr/include/c++/9.2.0/cstdio" 3
  using ::snprintf;
  using ::vfscanf;
  using ::vscanf;
  using ::vsnprintf;
  using ::vsscanf;

}

namespace std
{
  using ::__gnu_cxx::snprintf;
  using ::__gnu_cxx::vfscanf;
  using ::__gnu_cxx::vscanf;
  using ::__gnu_cxx::vsnprintf;
  using ::__gnu_cxx::vsscanf;
}
# 44 "/usr/include/c++/9.2.0/ext/string_conversions.h" 2 3
# 1 "/usr/include/c++/9.2.0/cerrno" 1 3
# 39 "/usr/include/c++/9.2.0/cerrno" 3
       
# 40 "/usr/include/c++/9.2.0/cerrno" 3


# 1 "/usr/include/errno.h" 1 3 4
# 28 "/usr/include/errno.h" 3 4
# 1 "/usr/include/bits/errno.h" 1 3 4
# 26 "/usr/include/bits/errno.h" 3 4
# 1 "/usr/include/linux/errno.h" 1 3 4
# 1 "/usr/include/asm/errno.h" 1 3 4
# 1 "/usr/include/asm-generic/errno.h" 1 3 4




# 1 "/usr/include/asm-generic/errno-base.h" 1 3 4
# 6 "/usr/include/asm-generic/errno.h" 2 3 4
# 1 "/usr/include/asm/errno.h" 2 3 4
# 1 "/usr/include/linux/errno.h" 2 3 4
# 27 "/usr/include/bits/errno.h" 2 3 4
# 29 "/usr/include/errno.h" 2 3 4





extern "C" {


extern int *__errno_location (void) throw () __attribute__ ((__const__));







extern char *program_invocation_name;
extern char *program_invocation_short_name;

# 1 "/usr/include/bits/types/error_t.h" 1 3 4
# 22 "/usr/include/bits/types/error_t.h" 3 4
typedef int error_t;
# 49 "/usr/include/errno.h" 2 3 4



}
# 43 "/usr/include/c++/9.2.0/cerrno" 2 3
# 45 "/usr/include/c++/9.2.0/ext/string_conversions.h" 2 3

namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{



  template<typename _TRet, typename _Ret = _TRet, typename _CharT,
    typename... _Base>
    _Ret
    __stoa(_TRet (*__convf) (const _CharT*, _CharT**, _Base...),
    const char* __name, const _CharT* __str, std::size_t* __idx,
    _Base... __base)
    {
      _Ret __ret;

      _CharT* __endptr;

      struct _Save_errno {
 _Save_errno() : _M_errno((*__errno_location ())) { (*__errno_location ()) = 0; }
 ~_Save_errno() { if ((*__errno_location ()) == 0) (*__errno_location ()) = _M_errno; }
 int _M_errno;
      } const __save_errno;

      struct _Range_chk {
   static bool
   _S_chk(_TRet, std::false_type) { return false; }

   static bool
   _S_chk(_TRet __val, std::true_type)
   {
     return __val < _TRet(__numeric_traits<int>::__min)
       || __val > _TRet(__numeric_traits<int>::__max);
   }
      };

      const _TRet __tmp = __convf(__str, &__endptr, __base...);

      if (__endptr == __str)
 std::__throw_invalid_argument(__name);
      else if ((*__errno_location ()) == 34
   || _Range_chk::_S_chk(__tmp, std::is_same<_Ret, int>{}))
 std::__throw_out_of_range(__name);
      else
 __ret = __tmp;

      if (__idx)
 *__idx = __endptr - __str;

      return __ret;
    }


  template<typename _String, typename _CharT = typename _String::value_type>
    _String
    __to_xstring(int (*__convf) (_CharT*, std::size_t, const _CharT*,
     __builtin_va_list), std::size_t __n,
   const _CharT* __fmt, ...)
    {


      _CharT* __s = static_cast<_CharT*>(__builtin_alloca(sizeof(_CharT)
         * __n));

      __builtin_va_list __args;
      __builtin_va_start(__args, __fmt);

      const int __len = __convf(__s, __n, __fmt, __args);

      __builtin_va_end(__args);

      return _String(__s, __s + __len);
    }


}
# 6494 "/usr/include/c++/9.2.0/bits/basic_string.h" 2 3

namespace std __attribute__ ((__visibility__ ("default")))
{

namespace __cxx11 {



  inline int
  stoi(const string& __str, size_t* __idx = 0, int __base = 10)
  { return __gnu_cxx::__stoa<long, int>(&std::strtol, "stoi", __str.c_str(),
     __idx, __base); }

  inline long
  stol(const string& __str, size_t* __idx = 0, int __base = 10)
  { return __gnu_cxx::__stoa(&std::strtol, "stol", __str.c_str(),
        __idx, __base); }

  inline unsigned long
  stoul(const string& __str, size_t* __idx = 0, int __base = 10)
  { return __gnu_cxx::__stoa(&std::strtoul, "stoul", __str.c_str(),
        __idx, __base); }

  inline long long
  stoll(const string& __str, size_t* __idx = 0, int __base = 10)
  { return __gnu_cxx::__stoa(&std::strtoll, "stoll", __str.c_str(),
        __idx, __base); }

  inline unsigned long long
  stoull(const string& __str, size_t* __idx = 0, int __base = 10)
  { return __gnu_cxx::__stoa(&std::strtoull, "stoull", __str.c_str(),
        __idx, __base); }


  inline float
  stof(const string& __str, size_t* __idx = 0)
  { return __gnu_cxx::__stoa(&std::strtof, "stof", __str.c_str(), __idx); }

  inline double
  stod(const string& __str, size_t* __idx = 0)
  { return __gnu_cxx::__stoa(&std::strtod, "stod", __str.c_str(), __idx); }

  inline long double
  stold(const string& __str, size_t* __idx = 0)
  { return __gnu_cxx::__stoa(&std::strtold, "stold", __str.c_str(), __idx); }






  inline string
  to_string(int __val)
  { return __gnu_cxx::__to_xstring<string>(&std::vsnprintf, 4 * sizeof(int),
        "%d", __val); }

  inline string
  to_string(unsigned __val)
  { return __gnu_cxx::__to_xstring<string>(&std::vsnprintf,
        4 * sizeof(unsigned),
        "%u", __val); }

  inline string
  to_string(long __val)
  { return __gnu_cxx::__to_xstring<string>(&std::vsnprintf, 4 * sizeof(long),
        "%ld", __val); }

  inline string
  to_string(unsigned long __val)
  { return __gnu_cxx::__to_xstring<string>(&std::vsnprintf,
        4 * sizeof(unsigned long),
        "%lu", __val); }

  inline string
  to_string(long long __val)
  { return __gnu_cxx::__to_xstring<string>(&std::vsnprintf,
        4 * sizeof(long long),
        "%lld", __val); }

  inline string
  to_string(unsigned long long __val)
  { return __gnu_cxx::__to_xstring<string>(&std::vsnprintf,
        4 * sizeof(unsigned long long),
        "%llu", __val); }

  inline string
  to_string(float __val)
  {
    const int __n =
      __gnu_cxx::__numeric_traits<float>::__max_exponent10 + 20;
    return __gnu_cxx::__to_xstring<string>(&std::vsnprintf, __n,
        "%f", __val);
  }

  inline string
  to_string(double __val)
  {
    const int __n =
      __gnu_cxx::__numeric_traits<double>::__max_exponent10 + 20;
    return __gnu_cxx::__to_xstring<string>(&std::vsnprintf, __n,
        "%f", __val);
  }

  inline string
  to_string(long double __val)
  {
    const int __n =
      __gnu_cxx::__numeric_traits<long double>::__max_exponent10 + 20;
    return __gnu_cxx::__to_xstring<string>(&std::vsnprintf, __n,
        "%Lf", __val);
  }



  inline int
  stoi(const wstring& __str, size_t* __idx = 0, int __base = 10)
  { return __gnu_cxx::__stoa<long, int>(&std::wcstol, "stoi", __str.c_str(),
     __idx, __base); }

  inline long
  stol(const wstring& __str, size_t* __idx = 0, int __base = 10)
  { return __gnu_cxx::__stoa(&std::wcstol, "stol", __str.c_str(),
        __idx, __base); }

  inline unsigned long
  stoul(const wstring& __str, size_t* __idx = 0, int __base = 10)
  { return __gnu_cxx::__stoa(&std::wcstoul, "stoul", __str.c_str(),
        __idx, __base); }

  inline long long
  stoll(const wstring& __str, size_t* __idx = 0, int __base = 10)
  { return __gnu_cxx::__stoa(&std::wcstoll, "stoll", __str.c_str(),
        __idx, __base); }

  inline unsigned long long
  stoull(const wstring& __str, size_t* __idx = 0, int __base = 10)
  { return __gnu_cxx::__stoa(&std::wcstoull, "stoull", __str.c_str(),
        __idx, __base); }


  inline float
  stof(const wstring& __str, size_t* __idx = 0)
  { return __gnu_cxx::__stoa(&std::wcstof, "stof", __str.c_str(), __idx); }

  inline double
  stod(const wstring& __str, size_t* __idx = 0)
  { return __gnu_cxx::__stoa(&std::wcstod, "stod", __str.c_str(), __idx); }

  inline long double
  stold(const wstring& __str, size_t* __idx = 0)
  { return __gnu_cxx::__stoa(&std::wcstold, "stold", __str.c_str(), __idx); }



  inline wstring
  to_wstring(int __val)
  { return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf, 4 * sizeof(int),
         L"%d", __val); }

  inline wstring
  to_wstring(unsigned __val)
  { return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf,
         4 * sizeof(unsigned),
         L"%u", __val); }

  inline wstring
  to_wstring(long __val)
  { return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf, 4 * sizeof(long),
         L"%ld", __val); }

  inline wstring
  to_wstring(unsigned long __val)
  { return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf,
         4 * sizeof(unsigned long),
         L"%lu", __val); }

  inline wstring
  to_wstring(long long __val)
  { return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf,
         4 * sizeof(long long),
         L"%lld", __val); }

  inline wstring
  to_wstring(unsigned long long __val)
  { return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf,
         4 * sizeof(unsigned long long),
         L"%llu", __val); }

  inline wstring
  to_wstring(float __val)
  {
    const int __n =
      __gnu_cxx::__numeric_traits<float>::__max_exponent10 + 20;
    return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf, __n,
         L"%f", __val);
  }

  inline wstring
  to_wstring(double __val)
  {
    const int __n =
      __gnu_cxx::__numeric_traits<double>::__max_exponent10 + 20;
    return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf, __n,
         L"%f", __val);
  }

  inline wstring
  to_wstring(long double __val)
  {
    const int __n =
      __gnu_cxx::__numeric_traits<long double>::__max_exponent10 + 20;
    return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf, __n,
         L"%Lf", __val);
  }



}

}







namespace std __attribute__ ((__visibility__ ("default")))
{






  template<>
    struct hash<string>
    : public __hash_base<size_t, string>
    {
      size_t
      operator()(const string& __s) const noexcept
      { return std::_Hash_impl::hash(__s.data(), __s.length()); }
    };

  template<>
    struct __is_fast_hash<hash<string>> : std::false_type
    { };



  template<>
    struct hash<wstring>
    : public __hash_base<size_t, wstring>
    {
      size_t
      operator()(const wstring& __s) const noexcept
      { return std::_Hash_impl::hash(__s.data(),
                                     __s.length() * sizeof(wchar_t)); }
    };

  template<>
    struct __is_fast_hash<hash<wstring>> : std::false_type
    { };
# 6778 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
  template<>
    struct hash<u16string>
    : public __hash_base<size_t, u16string>
    {
      size_t
      operator()(const u16string& __s) const noexcept
      { return std::_Hash_impl::hash(__s.data(),
                                     __s.length() * sizeof(char16_t)); }
    };

  template<>
    struct __is_fast_hash<hash<u16string>> : std::false_type
    { };


  template<>
    struct hash<u32string>
    : public __hash_base<size_t, u32string>
    {
      size_t
      operator()(const u32string& __s) const noexcept
      { return std::_Hash_impl::hash(__s.data(),
                                     __s.length() * sizeof(char32_t)); }
    };

  template<>
    struct __is_fast_hash<hash<u32string>> : std::false_type
    { };





  inline namespace literals
  {
  inline namespace string_literals
  {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wliteral-suffix"
    __attribute ((__abi_tag__ ("cxx11")))
    inline basic_string<char>
    operator""s(const char* __str, size_t __len)
    { return basic_string<char>{__str, __len}; }


    __attribute ((__abi_tag__ ("cxx11")))
    inline basic_string<wchar_t>
    operator""s(const wchar_t* __str, size_t __len)
    { return basic_string<wchar_t>{__str, __len}; }
# 6836 "/usr/include/c++/9.2.0/bits/basic_string.h" 3
    __attribute ((__abi_tag__ ("cxx11")))
    inline basic_string<char16_t>
    operator""s(const char16_t* __str, size_t __len)
    { return basic_string<char16_t>{__str, __len}; }

    __attribute ((__abi_tag__ ("cxx11")))
    inline basic_string<char32_t>
    operator""s(const char32_t* __str, size_t __len)
    { return basic_string<char32_t>{__str, __len}; }

#pragma GCC diagnostic pop
  }
  }
# 6868 "/usr/include/c++/9.2.0/bits/basic_string.h" 3

}
# 56 "/usr/include/c++/9.2.0/string" 2 3
# 1 "/usr/include/c++/9.2.0/bits/basic_string.tcc" 1 3
# 42 "/usr/include/c++/9.2.0/bits/basic_string.tcc" 3
       
# 43 "/usr/include/c++/9.2.0/bits/basic_string.tcc" 3



namespace std __attribute__ ((__visibility__ ("default")))
{




  template<typename _CharT, typename _Traits, typename _Alloc>
    const typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::npos;

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::
    swap(basic_string& __s) noexcept
    {
      if (this == &__s)
 return;

      _Alloc_traits::_S_on_swap(_M_get_allocator(), __s._M_get_allocator());

      if (_M_is_local())
 if (__s._M_is_local())
   {
     if (length() && __s.length())
       {
  _CharT __tmp_data[_S_local_capacity + 1];
  traits_type::copy(__tmp_data, __s._M_local_buf,
      _S_local_capacity + 1);
  traits_type::copy(__s._M_local_buf, _M_local_buf,
      _S_local_capacity + 1);
  traits_type::copy(_M_local_buf, __tmp_data,
      _S_local_capacity + 1);
       }
     else if (__s.length())
       {
  traits_type::copy(_M_local_buf, __s._M_local_buf,
      _S_local_capacity + 1);
  _M_length(__s.length());
  __s._M_set_length(0);
  return;
       }
     else if (length())
       {
  traits_type::copy(__s._M_local_buf, _M_local_buf,
      _S_local_capacity + 1);
  __s._M_length(length());
  _M_set_length(0);
  return;
       }
   }
 else
   {
     const size_type __tmp_capacity = __s._M_allocated_capacity;
     traits_type::copy(__s._M_local_buf, _M_local_buf,
         _S_local_capacity + 1);
     _M_data(__s._M_data());
     __s._M_data(__s._M_local_buf);
     _M_capacity(__tmp_capacity);
   }
      else
 {
   const size_type __tmp_capacity = _M_allocated_capacity;
   if (__s._M_is_local())
     {
       traits_type::copy(_M_local_buf, __s._M_local_buf,
    _S_local_capacity + 1);
       __s._M_data(_M_data());
       _M_data(_M_local_buf);
     }
   else
     {
       pointer __tmp_ptr = _M_data();
       _M_data(__s._M_data());
       __s._M_data(__tmp_ptr);
       _M_capacity(__s._M_allocated_capacity);
     }
   __s._M_capacity(__tmp_capacity);
 }

      const size_type __tmp_length = length();
      _M_length(__s.length());
      __s._M_length(__tmp_length);
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::pointer
    basic_string<_CharT, _Traits, _Alloc>::
    _M_create(size_type& __capacity, size_type __old_capacity)
    {


      if (__capacity > max_size())
 std::__throw_length_error(("basic_string::_M_create"));




      if (__capacity > __old_capacity && __capacity < 2 * __old_capacity)
 {
   __capacity = 2 * __old_capacity;

   if (__capacity > max_size())
     __capacity = max_size();
 }



      return _Alloc_traits::allocate(_M_get_allocator(), __capacity + 1);
    }





  template<typename _CharT, typename _Traits, typename _Alloc>
    template<typename _InIterator>
      void
      basic_string<_CharT, _Traits, _Alloc>::
      _M_construct(_InIterator __beg, _InIterator __end,
     std::input_iterator_tag)
      {
 size_type __len = 0;
 size_type __capacity = size_type(_S_local_capacity);

 while (__beg != __end && __len < __capacity)
   {
     _M_data()[__len++] = *__beg;
     ++__beg;
   }

 try
   {
     while (__beg != __end)
       {
  if (__len == __capacity)
    {

      __capacity = __len + 1;
      pointer __another = _M_create(__capacity, __len);
      this->_S_copy(__another, _M_data(), __len);
      _M_dispose();
      _M_data(__another);
      _M_capacity(__capacity);
    }
  _M_data()[__len++] = *__beg;
  ++__beg;
       }
   }
 catch(...)
   {
     _M_dispose();
     throw;
   }

 _M_set_length(__len);
      }

  template<typename _CharT, typename _Traits, typename _Alloc>
    template<typename _InIterator>
      void
      basic_string<_CharT, _Traits, _Alloc>::
      _M_construct(_InIterator __beg, _InIterator __end,
     std::forward_iterator_tag)
      {

 if (__gnu_cxx::__is_null_pointer(__beg) && __beg != __end)
   std::__throw_logic_error(("basic_string::" "_M_construct null not valid")
                                         );

 size_type __dnew = static_cast<size_type>(std::distance(__beg, __end));

 if (__dnew > size_type(_S_local_capacity))
   {
     _M_data(_M_create(__dnew, size_type(0)));
     _M_capacity(__dnew);
   }


 try
   { this->_S_copy_chars(_M_data(), __beg, __end); }
 catch(...)
   {
     _M_dispose();
     throw;
   }

 _M_set_length(__dnew);
      }

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::
    _M_construct(size_type __n, _CharT __c)
    {
      if (__n > size_type(_S_local_capacity))
 {
   _M_data(_M_create(__n, size_type(0)));
   _M_capacity(__n);
 }

      if (__n)
 this->_S_assign(_M_data(), __n, __c);

      _M_set_length(__n);
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::
    _M_assign(const basic_string& __str)
    {
      if (this != &__str)
 {
   const size_type __rsize = __str.length();
   const size_type __capacity = capacity();

   if (__rsize > __capacity)
     {
       size_type __new_capacity = __rsize;
       pointer __tmp = _M_create(__new_capacity, __capacity);
       _M_dispose();
       _M_data(__tmp);
       _M_capacity(__new_capacity);
     }

   if (__rsize)
     this->_S_copy(_M_data(), __str._M_data(), __rsize);

   _M_set_length(__rsize);
 }
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::
    reserve(size_type __res)
    {

      if (__res < length())
 __res = length();

      const size_type __capacity = capacity();
      if (__res != __capacity)
 {
   if (__res > __capacity
       || __res > size_type(_S_local_capacity))
     {
       pointer __tmp = _M_create(__res, __capacity);
       this->_S_copy(__tmp, _M_data(), length() + 1);
       _M_dispose();
       _M_data(__tmp);
       _M_capacity(__res);
     }
   else if (!_M_is_local())
     {
       this->_S_copy(_M_local_data(), _M_data(), length() + 1);
       _M_destroy(__capacity);
       _M_data(_M_local_data());
     }
 }
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::
    _M_mutate(size_type __pos, size_type __len1, const _CharT* __s,
       size_type __len2)
    {
      const size_type __how_much = length() - __pos - __len1;

      size_type __new_capacity = length() + __len2 - __len1;
      pointer __r = _M_create(__new_capacity, capacity());

      if (__pos)
 this->_S_copy(__r, _M_data(), __pos);
      if (__s && __len2)
 this->_S_copy(__r + __pos, __s, __len2);
      if (__how_much)
 this->_S_copy(__r + __pos + __len2,
        _M_data() + __pos + __len1, __how_much);

      _M_dispose();
      _M_data(__r);
      _M_capacity(__new_capacity);
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::
    _M_erase(size_type __pos, size_type __n)
    {
      const size_type __how_much = length() - __pos - __n;

      if (__how_much && __n)
 this->_S_move(_M_data() + __pos, _M_data() + __pos + __n, __how_much);

      _M_set_length(length() - __n);
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::
    resize(size_type __n, _CharT __c)
    {
      const size_type __size = this->size();
      if (__size < __n)
 this->append(__n - __size, __c);
      else if (__n < __size)
 this->_M_set_length(__n);
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>&
    basic_string<_CharT, _Traits, _Alloc>::
    _M_append(const _CharT* __s, size_type __n)
    {
      const size_type __len = __n + this->size();

      if (__len <= this->capacity())
 {
   if (__n)
     this->_S_copy(this->_M_data() + this->size(), __s, __n);
 }
      else
 this->_M_mutate(this->size(), size_type(0), __s, __n);

      this->_M_set_length(__len);
      return *this;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    template<typename _InputIterator>
      basic_string<_CharT, _Traits, _Alloc>&
      basic_string<_CharT, _Traits, _Alloc>::
      _M_replace_dispatch(const_iterator __i1, const_iterator __i2,
     _InputIterator __k1, _InputIterator __k2,
     std::__false_type)
      {
 const basic_string __s(__k1, __k2);
 const size_type __n1 = __i2 - __i1;
 return _M_replace(__i1 - begin(), __n1, __s._M_data(),
     __s.size());
      }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>&
    basic_string<_CharT, _Traits, _Alloc>::
    _M_replace_aux(size_type __pos1, size_type __n1, size_type __n2,
     _CharT __c)
    {
      _M_check_length(__n1, __n2, "basic_string::_M_replace_aux");

      const size_type __old_size = this->size();
      const size_type __new_size = __old_size + __n2 - __n1;

      if (__new_size <= this->capacity())
 {
   pointer __p = this->_M_data() + __pos1;

   const size_type __how_much = __old_size - __pos1 - __n1;
   if (__how_much && __n1 != __n2)
     this->_S_move(__p + __n2, __p + __n1, __how_much);
 }
      else
 this->_M_mutate(__pos1, __n1, 0, __n2);

      if (__n2)
 this->_S_assign(this->_M_data() + __pos1, __n2, __c);

      this->_M_set_length(__new_size);
      return *this;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>&
    basic_string<_CharT, _Traits, _Alloc>::
    _M_replace(size_type __pos, size_type __len1, const _CharT* __s,
        const size_type __len2)
    {
      _M_check_length(__len1, __len2, "basic_string::_M_replace");

      const size_type __old_size = this->size();
      const size_type __new_size = __old_size + __len2 - __len1;

      if (__new_size <= this->capacity())
 {
   pointer __p = this->_M_data() + __pos;

   const size_type __how_much = __old_size - __pos - __len1;
   if (_M_disjunct(__s))
     {
       if (__how_much && __len1 != __len2)
  this->_S_move(__p + __len2, __p + __len1, __how_much);
       if (__len2)
  this->_S_copy(__p, __s, __len2);
     }
   else
     {

       if (__len2 && __len2 <= __len1)
  this->_S_move(__p, __s, __len2);
       if (__how_much && __len1 != __len2)
  this->_S_move(__p + __len2, __p + __len1, __how_much);
       if (__len2 > __len1)
  {
    if (__s + __len2 <= __p + __len1)
      this->_S_move(__p, __s, __len2);
    else if (__s >= __p + __len1)
      this->_S_copy(__p, __s + __len2 - __len1, __len2);
    else
      {
        const size_type __nleft = (__p + __len1) - __s;
        this->_S_move(__p, __s, __nleft);
        this->_S_copy(__p + __nleft, __p + __len2,
        __len2 - __nleft);
      }
  }
     }
 }
      else
 this->_M_mutate(__pos, __len1, __s, __len2);

      this->_M_set_length(__new_size);
      return *this;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    copy(_CharT* __s, size_type __n, size_type __pos) const
    {
      _M_check(__pos, "basic_string::copy");
      __n = _M_limit(__pos, __n);
      ;
      if (__n)
 _S_copy(__s, _M_data() + __pos, __n);

      return __n;
    }
# 1156 "/usr/include/c++/9.2.0/bits/basic_string.tcc" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>
    operator+(const _CharT* __lhs,
       const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    {
      ;
      typedef basic_string<_CharT, _Traits, _Alloc> __string_type;
      typedef typename __string_type::size_type __size_type;
      const __size_type __len = _Traits::length(__lhs);
      __string_type __str;
      __str.reserve(__len + __rhs.size());
      __str.append(__lhs, __len);
      __str.append(__rhs);
      return __str;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>
    operator+(_CharT __lhs, const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    {
      typedef basic_string<_CharT, _Traits, _Alloc> __string_type;
      typedef typename __string_type::size_type __size_type;
      __string_type __str;
      const __size_type __len = __rhs.size();
      __str.reserve(__len + 1);
      __str.append(__size_type(1), __lhs);
      __str.append(__rhs);
      return __str;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find(const _CharT* __s, size_type __pos, size_type __n) const
    noexcept
    {
      ;
      const size_type __size = this->size();

      if (__n == 0)
 return __pos <= __size ? __pos : npos;
      if (__pos >= __size)
 return npos;

      const _CharT __elem0 = __s[0];
      const _CharT* const __data = data();
      const _CharT* __first = __data + __pos;
      const _CharT* const __last = __data + __size;
      size_type __len = __size - __pos;

      while (__len >= __n)
 {

   __first = traits_type::find(__first, __len - __n + 1, __elem0);
   if (!__first)
     return npos;



   if (traits_type::compare(__first, __s, __n) == 0)
     return __first - __data;
   __len = __last - ++__first;
 }
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find(_CharT __c, size_type __pos) const noexcept
    {
      size_type __ret = npos;
      const size_type __size = this->size();
      if (__pos < __size)
 {
   const _CharT* __data = _M_data();
   const size_type __n = __size - __pos;
   const _CharT* __p = traits_type::find(__data + __pos, __n, __c);
   if (__p)
     __ret = __p - __data;
 }
      return __ret;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    rfind(const _CharT* __s, size_type __pos, size_type __n) const
    noexcept
    {
      ;
      const size_type __size = this->size();
      if (__n <= __size)
 {
   __pos = std::min(size_type(__size - __n), __pos);
   const _CharT* __data = _M_data();
   do
     {
       if (traits_type::compare(__data + __pos, __s, __n) == 0)
  return __pos;
     }
   while (__pos-- > 0);
 }
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    rfind(_CharT __c, size_type __pos) const noexcept
    {
      size_type __size = this->size();
      if (__size)
 {
   if (--__size > __pos)
     __size = __pos;
   for (++__size; __size-- > 0; )
     if (traits_type::eq(_M_data()[__size], __c))
       return __size;
 }
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find_first_of(const _CharT* __s, size_type __pos, size_type __n) const
    noexcept
    {
      ;
      for (; __n && __pos < this->size(); ++__pos)
 {
   const _CharT* __p = traits_type::find(__s, __n, _M_data()[__pos]);
   if (__p)
     return __pos;
 }
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find_last_of(const _CharT* __s, size_type __pos, size_type __n) const
    noexcept
    {
      ;
      size_type __size = this->size();
      if (__size && __n)
 {
   if (--__size > __pos)
     __size = __pos;
   do
     {
       if (traits_type::find(__s, __n, _M_data()[__size]))
  return __size;
     }
   while (__size-- != 0);
 }
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find_first_not_of(const _CharT* __s, size_type __pos, size_type __n) const
    noexcept
    {
      ;
      for (; __pos < this->size(); ++__pos)
 if (!traits_type::find(__s, __n, _M_data()[__pos]))
   return __pos;
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find_first_not_of(_CharT __c, size_type __pos) const noexcept
    {
      for (; __pos < this->size(); ++__pos)
 if (!traits_type::eq(_M_data()[__pos], __c))
   return __pos;
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find_last_not_of(const _CharT* __s, size_type __pos, size_type __n) const
    noexcept
    {
      ;
      size_type __size = this->size();
      if (__size)
 {
   if (--__size > __pos)
     __size = __pos;
   do
     {
       if (!traits_type::find(__s, __n, _M_data()[__size]))
  return __size;
     }
   while (__size--);
 }
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find_last_not_of(_CharT __c, size_type __pos) const noexcept
    {
      size_type __size = this->size();
      if (__size)
 {
   if (--__size > __pos)
     __size = __pos;
   do
     {
       if (!traits_type::eq(_M_data()[__size], __c))
  return __size;
     }
   while (__size--);
 }
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    int
    basic_string<_CharT, _Traits, _Alloc>::
    compare(size_type __pos, size_type __n, const basic_string& __str) const
    {
      _M_check(__pos, "basic_string::compare");
      __n = _M_limit(__pos, __n);
      const size_type __osize = __str.size();
      const size_type __len = std::min(__n, __osize);
      int __r = traits_type::compare(_M_data() + __pos, __str.data(), __len);
      if (!__r)
 __r = _S_compare(__n, __osize);
      return __r;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    int
    basic_string<_CharT, _Traits, _Alloc>::
    compare(size_type __pos1, size_type __n1, const basic_string& __str,
     size_type __pos2, size_type __n2) const
    {
      _M_check(__pos1, "basic_string::compare");
      __str._M_check(__pos2, "basic_string::compare");
      __n1 = _M_limit(__pos1, __n1);
      __n2 = __str._M_limit(__pos2, __n2);
      const size_type __len = std::min(__n1, __n2);
      int __r = traits_type::compare(_M_data() + __pos1,
         __str.data() + __pos2, __len);
      if (!__r)
 __r = _S_compare(__n1, __n2);
      return __r;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    int
    basic_string<_CharT, _Traits, _Alloc>::
    compare(const _CharT* __s) const noexcept
    {
      ;
      const size_type __size = this->size();
      const size_type __osize = traits_type::length(__s);
      const size_type __len = std::min(__size, __osize);
      int __r = traits_type::compare(_M_data(), __s, __len);
      if (!__r)
 __r = _S_compare(__size, __osize);
      return __r;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    int
    basic_string <_CharT, _Traits, _Alloc>::
    compare(size_type __pos, size_type __n1, const _CharT* __s) const
    {
      ;
      _M_check(__pos, "basic_string::compare");
      __n1 = _M_limit(__pos, __n1);
      const size_type __osize = traits_type::length(__s);
      const size_type __len = std::min(__n1, __osize);
      int __r = traits_type::compare(_M_data() + __pos, __s, __len);
      if (!__r)
 __r = _S_compare(__n1, __osize);
      return __r;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    int
    basic_string <_CharT, _Traits, _Alloc>::
    compare(size_type __pos, size_type __n1, const _CharT* __s,
     size_type __n2) const
    {
      ;
      _M_check(__pos, "basic_string::compare");
      __n1 = _M_limit(__pos, __n1);
      const size_type __len = std::min(__n1, __n2);
      int __r = traits_type::compare(_M_data() + __pos, __s, __len);
      if (!__r)
 __r = _S_compare(__n1, __n2);
      return __r;
    }


  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_istream<_CharT, _Traits>&
    operator>>(basic_istream<_CharT, _Traits>& __in,
        basic_string<_CharT, _Traits, _Alloc>& __str)
    {
      typedef basic_istream<_CharT, _Traits> __istream_type;
      typedef basic_string<_CharT, _Traits, _Alloc> __string_type;
      typedef typename __istream_type::ios_base __ios_base;
      typedef typename __istream_type::int_type __int_type;
      typedef typename __string_type::size_type __size_type;
      typedef ctype<_CharT> __ctype_type;
      typedef typename __ctype_type::ctype_base __ctype_base;

      __size_type __extracted = 0;
      typename __ios_base::iostate __err = __ios_base::goodbit;
      typename __istream_type::sentry __cerb(__in, false);
      if (__cerb)
 {
   try
     {

       __str.erase();
       _CharT __buf[128];
       __size_type __len = 0;
       const streamsize __w = __in.width();
       const __size_type __n = __w > 0 ? static_cast<__size_type>(__w)
                                : __str.max_size();
       const __ctype_type& __ct = use_facet<__ctype_type>(__in.getloc());
       const __int_type __eof = _Traits::eof();
       __int_type __c = __in.rdbuf()->sgetc();

       while (__extracted < __n
       && !_Traits::eq_int_type(__c, __eof)
       && !__ct.is(__ctype_base::space,
     _Traits::to_char_type(__c)))
  {
    if (__len == sizeof(__buf) / sizeof(_CharT))
      {
        __str.append(__buf, sizeof(__buf) / sizeof(_CharT));
        __len = 0;
      }
    __buf[__len++] = _Traits::to_char_type(__c);
    ++__extracted;
    __c = __in.rdbuf()->snextc();
  }
       __str.append(__buf, __len);

       if (_Traits::eq_int_type(__c, __eof))
  __err |= __ios_base::eofbit;
       __in.width(0);
     }
   catch(__cxxabiv1::__forced_unwind&)
     {
       __in._M_setstate(__ios_base::badbit);
       throw;
     }
   catch(...)
     {



       __in._M_setstate(__ios_base::badbit);
     }
 }

      if (!__extracted)
 __err |= __ios_base::failbit;
      if (__err)
 __in.setstate(__err);
      return __in;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_istream<_CharT, _Traits>&
    getline(basic_istream<_CharT, _Traits>& __in,
     basic_string<_CharT, _Traits, _Alloc>& __str, _CharT __delim)
    {
      typedef basic_istream<_CharT, _Traits> __istream_type;
      typedef basic_string<_CharT, _Traits, _Alloc> __string_type;
      typedef typename __istream_type::ios_base __ios_base;
      typedef typename __istream_type::int_type __int_type;
      typedef typename __string_type::size_type __size_type;

      __size_type __extracted = 0;
      const __size_type __n = __str.max_size();
      typename __ios_base::iostate __err = __ios_base::goodbit;
      typename __istream_type::sentry __cerb(__in, true);
      if (__cerb)
 {
   try
     {
       __str.erase();
       const __int_type __idelim = _Traits::to_int_type(__delim);
       const __int_type __eof = _Traits::eof();
       __int_type __c = __in.rdbuf()->sgetc();

       while (__extracted < __n
       && !_Traits::eq_int_type(__c, __eof)
       && !_Traits::eq_int_type(__c, __idelim))
  {
    __str += _Traits::to_char_type(__c);
    ++__extracted;
    __c = __in.rdbuf()->snextc();
  }

       if (_Traits::eq_int_type(__c, __eof))
  __err |= __ios_base::eofbit;
       else if (_Traits::eq_int_type(__c, __idelim))
  {
    ++__extracted;
    __in.rdbuf()->sbumpc();
  }
       else
  __err |= __ios_base::failbit;
     }
   catch(__cxxabiv1::__forced_unwind&)
     {
       __in._M_setstate(__ios_base::badbit);
       throw;
     }
   catch(...)
     {



       __in._M_setstate(__ios_base::badbit);
     }
 }
      if (!__extracted)
 __err |= __ios_base::failbit;
      if (__err)
 __in.setstate(__err);
      return __in;
    }
# 1608 "/usr/include/c++/9.2.0/bits/basic_string.tcc" 3
  extern template class basic_string<char>;







  extern template
    basic_istream<char>&
    operator>>(basic_istream<char>&, string&);
  extern template
    basic_ostream<char>&
    operator<<(basic_ostream<char>&, const string&);
  extern template
    basic_istream<char>&
    getline(basic_istream<char>&, string&, char);
  extern template
    basic_istream<char>&
    getline(basic_istream<char>&, string&);



  extern template class basic_string<wchar_t>;





  extern template
    basic_istream<wchar_t>&
    operator>>(basic_istream<wchar_t>&, wstring&);
  extern template
    basic_ostream<wchar_t>&
    operator<<(basic_ostream<wchar_t>&, const wstring&);
  extern template
    basic_istream<wchar_t>&
    getline(basic_istream<wchar_t>&, wstring&, wchar_t);
  extern template
    basic_istream<wchar_t>&
    getline(basic_istream<wchar_t>&, wstring&);




}
# 57 "/usr/include/c++/9.2.0/string" 2 3
# 40 "/usr/include/c++/9.2.0/stdexcept" 2 3

namespace std __attribute__ ((__visibility__ ("default")))
{





  struct __cow_string
  {
    union {
      const char* _M_p;
      char _M_bytes[sizeof(const char*)];
    };

    __cow_string();
    __cow_string(const std::string&);
    __cow_string(const char*, size_t);
    __cow_string(const __cow_string&) noexcept;
    __cow_string& operator=(const __cow_string&) noexcept;
    ~__cow_string();

    __cow_string(__cow_string&&) noexcept;
    __cow_string& operator=(__cow_string&&) noexcept;

  };

  typedef basic_string<char> __sso_string;
# 113 "/usr/include/c++/9.2.0/stdexcept" 3
  class logic_error : public exception
  {
    __cow_string _M_msg;

  public:

    explicit
    logic_error(const string& __arg) ;


    explicit
    logic_error(const char*) ;

    logic_error(logic_error&&) noexcept;
    logic_error& operator=(logic_error&&) noexcept;



    logic_error(const logic_error&) noexcept;
    logic_error& operator=(const logic_error&) noexcept;





    virtual ~logic_error() noexcept;



    virtual const char*
    what() const noexcept;





  };



  class domain_error : public logic_error
  {
  public:
    explicit domain_error(const string& __arg) ;

    explicit domain_error(const char*) ;
    domain_error(const domain_error&) = default;
    domain_error& operator=(const domain_error&) = default;
    domain_error(domain_error&&) = default;
    domain_error& operator=(domain_error&&) = default;

    virtual ~domain_error() noexcept;
  };


  class invalid_argument : public logic_error
  {
  public:
    explicit invalid_argument(const string& __arg) ;

    explicit invalid_argument(const char*) ;
    invalid_argument(const invalid_argument&) = default;
    invalid_argument& operator=(const invalid_argument&) = default;
    invalid_argument(invalid_argument&&) = default;
    invalid_argument& operator=(invalid_argument&&) = default;

    virtual ~invalid_argument() noexcept;
  };



  class length_error : public logic_error
  {
  public:
    explicit length_error(const string& __arg) ;

    explicit length_error(const char*) ;
    length_error(const length_error&) = default;
    length_error& operator=(const length_error&) = default;
    length_error(length_error&&) = default;
    length_error& operator=(length_error&&) = default;

    virtual ~length_error() noexcept;
  };



  class out_of_range : public logic_error
  {
  public:
    explicit out_of_range(const string& __arg) ;

    explicit out_of_range(const char*) ;
    out_of_range(const out_of_range&) = default;
    out_of_range& operator=(const out_of_range&) = default;
    out_of_range(out_of_range&&) = default;
    out_of_range& operator=(out_of_range&&) = default;

    virtual ~out_of_range() noexcept;
  };






  class runtime_error : public exception
  {
    __cow_string _M_msg;

  public:

    explicit
    runtime_error(const string& __arg) ;


    explicit
    runtime_error(const char*) ;

    runtime_error(runtime_error&&) noexcept;
    runtime_error& operator=(runtime_error&&) noexcept;



    runtime_error(const runtime_error&) noexcept;
    runtime_error& operator=(const runtime_error&) noexcept;





    virtual ~runtime_error() noexcept;



    virtual const char*
    what() const noexcept;





  };


  class range_error : public runtime_error
  {
  public:
    explicit range_error(const string& __arg) ;

    explicit range_error(const char*) ;
    range_error(const range_error&) = default;
    range_error& operator=(const range_error&) = default;
    range_error(range_error&&) = default;
    range_error& operator=(range_error&&) = default;

    virtual ~range_error() noexcept;
  };


  class overflow_error : public runtime_error
  {
  public:
    explicit overflow_error(const string& __arg) ;

    explicit overflow_error(const char*) ;
    overflow_error(const overflow_error&) = default;
    overflow_error& operator=(const overflow_error&) = default;
    overflow_error(overflow_error&&) = default;
    overflow_error& operator=(overflow_error&&) = default;

    virtual ~overflow_error() noexcept;
  };


  class underflow_error : public runtime_error
  {
  public:
    explicit underflow_error(const string& __arg) ;

    explicit underflow_error(const char*) ;
    underflow_error(const underflow_error&) = default;
    underflow_error& operator=(const underflow_error&) = default;
    underflow_error(underflow_error&&) = default;
    underflow_error& operator=(underflow_error&&) = default;

    virtual ~underflow_error() noexcept;
  };




}
# 40 "/usr/include/c++/9.2.0/array" 2 3



namespace std __attribute__ ((__visibility__ ("default")))
{


  template<typename _Tp, std::size_t _Nm>
    struct __array_traits
    {
      typedef _Tp _Type[_Nm];
      typedef __is_swappable<_Tp> _Is_swappable;
      typedef __is_nothrow_swappable<_Tp> _Is_nothrow_swappable;

      static constexpr _Tp&
      _S_ref(const _Type& __t, std::size_t __n) noexcept
      { return const_cast<_Tp&>(__t[__n]); }

      static constexpr _Tp*
      _S_ptr(const _Type& __t) noexcept
      { return const_cast<_Tp*>(__t); }
    };

 template<typename _Tp>
   struct __array_traits<_Tp, 0>
   {
     struct _Type { };
     typedef true_type _Is_swappable;
     typedef true_type _Is_nothrow_swappable;

     static constexpr _Tp&
     _S_ref(const _Type&, std::size_t) noexcept
     { return *static_cast<_Tp*>(nullptr); }

     static constexpr _Tp*
     _S_ptr(const _Type&) noexcept
     { return nullptr; }
   };
# 93 "/usr/include/c++/9.2.0/array" 3
  template<typename _Tp, std::size_t _Nm>
    struct array
    {
      typedef _Tp value_type;
      typedef value_type* pointer;
      typedef const value_type* const_pointer;
      typedef value_type& reference;
      typedef const value_type& const_reference;
      typedef value_type* iterator;
      typedef const value_type* const_iterator;
      typedef std::size_t size_type;
      typedef std::ptrdiff_t difference_type;
      typedef std::reverse_iterator<iterator> reverse_iterator;
      typedef std::reverse_iterator<const_iterator> const_reverse_iterator;


      typedef std::__array_traits<_Tp, _Nm> _AT_Type;
      typename _AT_Type::_Type _M_elems;




      void
      fill(const value_type& __u)
      { std::fill_n(begin(), size(), __u); }

      void
      swap(array& __other)
      noexcept(_AT_Type::_Is_nothrow_swappable::value)
      { std::swap_ranges(begin(), end(), __other.begin()); }


      iterator
      begin() noexcept
      { return iterator(data()); }

      const_iterator
      begin() const noexcept
      { return const_iterator(data()); }

      iterator
      end() noexcept
      { return iterator(data() + _Nm); }

      const_iterator
      end() const noexcept
      { return const_iterator(data() + _Nm); }

      reverse_iterator
      rbegin() noexcept
      { return reverse_iterator(end()); }

      const_reverse_iterator
      rbegin() const noexcept
      { return const_reverse_iterator(end()); }

      reverse_iterator
      rend() noexcept
      { return reverse_iterator(begin()); }

      const_reverse_iterator
      rend() const noexcept
      { return const_reverse_iterator(begin()); }

      const_iterator
      cbegin() const noexcept
      { return const_iterator(data()); }

      const_iterator
      cend() const noexcept
      { return const_iterator(data() + _Nm); }

      const_reverse_iterator
      crbegin() const noexcept
      { return const_reverse_iterator(end()); }

      const_reverse_iterator
      crend() const noexcept
      { return const_reverse_iterator(begin()); }


      constexpr size_type
      size() const noexcept { return _Nm; }

      constexpr size_type
      max_size() const noexcept { return _Nm; }

      constexpr bool
      empty() const noexcept { return size() == 0; }


      reference
      operator[](size_type __n) noexcept
      { return _AT_Type::_S_ref(_M_elems, __n); }

      constexpr const_reference
      operator[](size_type __n) const noexcept
      { return _AT_Type::_S_ref(_M_elems, __n); }

      reference
      at(size_type __n)
      {
 if (__n >= _Nm)
   std::__throw_out_of_range_fmt(("array::at: __n (which is %zu) " ">= _Nm (which is %zu)")
                                 ,
     __n, _Nm);
 return _AT_Type::_S_ref(_M_elems, __n);
      }

      constexpr const_reference
      at(size_type __n) const
      {


 return __n < _Nm ? _AT_Type::_S_ref(_M_elems, __n)
   : (std::__throw_out_of_range_fmt(("array::at: __n (which is %zu) " ">= _Nm (which is %zu)")
                                    ,
        __n, _Nm),
      _AT_Type::_S_ref(_M_elems, 0));
      }

      reference
      front() noexcept
      { return *begin(); }

      constexpr const_reference
      front() const noexcept
      { return _AT_Type::_S_ref(_M_elems, 0); }

      reference
      back() noexcept
      { return _Nm ? *(end() - 1) : *end(); }

      constexpr const_reference
      back() const noexcept
      {
 return _Nm ? _AT_Type::_S_ref(_M_elems, _Nm - 1)
             : _AT_Type::_S_ref(_M_elems, 0);
      }

      pointer
      data() noexcept
      { return _AT_Type::_S_ptr(_M_elems); }

      const_pointer
      data() const noexcept
      { return _AT_Type::_S_ptr(_M_elems); }
    };
# 250 "/usr/include/c++/9.2.0/array" 3
  template<typename _Tp, std::size_t _Nm>
    inline bool
    operator==(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
    { return std::equal(__one.begin(), __one.end(), __two.begin()); }

  template<typename _Tp, std::size_t _Nm>
    inline bool
    operator!=(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
    { return !(__one == __two); }

  template<typename _Tp, std::size_t _Nm>
    inline bool
    operator<(const array<_Tp, _Nm>& __a, const array<_Tp, _Nm>& __b)
    {
      return std::lexicographical_compare(__a.begin(), __a.end(),
       __b.begin(), __b.end());
    }

  template<typename _Tp, std::size_t _Nm>
    inline bool
    operator>(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
    { return __two < __one; }

  template<typename _Tp, std::size_t _Nm>
    inline bool
    operator<=(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
    { return !(__one > __two); }

  template<typename _Tp, std::size_t _Nm>
    inline bool
    operator>=(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
    { return !(__one < __two); }


  template<typename _Tp, std::size_t _Nm>
    inline


    typename enable_if<
      std::__array_traits<_Tp, _Nm>::_Is_swappable::value
    >::type



    swap(array<_Tp, _Nm>& __one, array<_Tp, _Nm>& __two)
    noexcept(noexcept(__one.swap(__two)))
    { __one.swap(__two); }


  template<typename _Tp, std::size_t _Nm>
    typename enable_if<
      !std::__array_traits<_Tp, _Nm>::_Is_swappable::value>::type
    swap(array<_Tp, _Nm>&, array<_Tp, _Nm>&) = delete;


  template<std::size_t _Int, typename _Tp, std::size_t _Nm>
    constexpr _Tp&
    get(array<_Tp, _Nm>& __arr) noexcept
    {
      static_assert(_Int < _Nm, "array index is within bounds");
      return std::__array_traits<_Tp, _Nm>::
 _S_ref(__arr._M_elems, _Int);
    }

  template<std::size_t _Int, typename _Tp, std::size_t _Nm>
    constexpr _Tp&&
    get(array<_Tp, _Nm>&& __arr) noexcept
    {
      static_assert(_Int < _Nm, "array index is within bounds");
      return std::move(std::get<_Int>(__arr));
    }

  template<std::size_t _Int, typename _Tp, std::size_t _Nm>
    constexpr const _Tp&
    get(const array<_Tp, _Nm>& __arr) noexcept
    {
      static_assert(_Int < _Nm, "array index is within bounds");
      return std::__array_traits<_Tp, _Nm>::
 _S_ref(__arr._M_elems, _Int);
    }

  template<std::size_t _Int, typename _Tp, std::size_t _Nm>
    constexpr const _Tp&&
    get(const array<_Tp, _Nm>&& __arr) noexcept
    {
      static_assert(_Int < _Nm, "array index is within bounds");
      return std::move(std::get<_Int>(__arr));
    }


}

namespace std __attribute__ ((__visibility__ ("default")))
{





  template<typename _Tp>
    struct tuple_size;


  template<typename _Tp, std::size_t _Nm>
    struct tuple_size<std::array<_Tp, _Nm>>
    : public integral_constant<std::size_t, _Nm> { };


  template<std::size_t _Int, typename _Tp>
    struct tuple_element;


  template<std::size_t _Int, typename _Tp, std::size_t _Nm>
    struct tuple_element<_Int, std::array<_Tp, _Nm>>
    {
      static_assert(_Int < _Nm, "index is out of bounds");
      typedef _Tp type;
    };

  template<typename _Tp, std::size_t _Nm>
    struct __is_tuple_like_impl<std::array<_Tp, _Nm>> : true_type
    { };


}
# 40 "/usr/include/c++/9.2.0/tuple" 2 3
# 1 "/usr/include/c++/9.2.0/bits/uses_allocator.h" 1 3
# 35 "/usr/include/c++/9.2.0/bits/uses_allocator.h" 3
namespace std __attribute__ ((__visibility__ ("default")))
{



  struct __erased_type { };




  template<typename _Alloc, typename _Tp>
    using __is_erased_or_convertible
      = __or_<is_convertible<_Alloc, _Tp>, is_same<_Tp, __erased_type>>;


  struct allocator_arg_t { explicit allocator_arg_t() = default; };

  constexpr allocator_arg_t allocator_arg =
    allocator_arg_t();

  template<typename _Tp, typename _Alloc, typename = __void_t<>>
    struct __uses_allocator_helper
    : false_type { };

  template<typename _Tp, typename _Alloc>
    struct __uses_allocator_helper<_Tp, _Alloc,
       __void_t<typename _Tp::allocator_type>>
    : __is_erased_or_convertible<_Alloc, typename _Tp::allocator_type>::type
    { };


  template<typename _Tp, typename _Alloc>
    struct uses_allocator
    : __uses_allocator_helper<_Tp, _Alloc>::type
    { };

  struct __uses_alloc_base { };

  struct __uses_alloc0 : __uses_alloc_base
  {
    struct _Sink { void operator=(const void*) { } } _M_a;
  };

  template<typename _Alloc>
    struct __uses_alloc1 : __uses_alloc_base { const _Alloc* _M_a; };

  template<typename _Alloc>
    struct __uses_alloc2 : __uses_alloc_base { const _Alloc* _M_a; };

  template<bool, typename _Tp, typename _Alloc, typename... _Args>
    struct __uses_alloc;

  template<typename _Tp, typename _Alloc, typename... _Args>
    struct __uses_alloc<true, _Tp, _Alloc, _Args...>
    : conditional<
        is_constructible<_Tp, allocator_arg_t, const _Alloc&, _Args...>::value,
        __uses_alloc1<_Alloc>,
        __uses_alloc2<_Alloc>>::type
    {


      static_assert(__or_<
   is_constructible<_Tp, allocator_arg_t, const _Alloc&, _Args...>,
   is_constructible<_Tp, _Args..., const _Alloc&>>::value,
   "construction with an allocator must be possible"
   " if uses_allocator is true");
    };

  template<typename _Tp, typename _Alloc, typename... _Args>
    struct __uses_alloc<false, _Tp, _Alloc, _Args...>
    : __uses_alloc0 { };

  template<typename _Tp, typename _Alloc, typename... _Args>
    using __uses_alloc_t =
      __uses_alloc<uses_allocator<_Tp, _Alloc>::value, _Tp, _Alloc, _Args...>;

  template<typename _Tp, typename _Alloc, typename... _Args>
    inline __uses_alloc_t<_Tp, _Alloc, _Args...>
    __use_alloc(const _Alloc& __a)
    {
      __uses_alloc_t<_Tp, _Alloc, _Args...> __ret;
      __ret._M_a = std::__addressof(__a);
      return __ret;
    }

  template<typename _Tp, typename _Alloc, typename... _Args>
    void
    __use_alloc(const _Alloc&&) = delete;







  template<template<typename...> class _Predicate,
    typename _Tp, typename _Alloc, typename... _Args>
    struct __is_uses_allocator_predicate
    : conditional<uses_allocator<_Tp, _Alloc>::value,
      __or_<_Predicate<_Tp, allocator_arg_t, _Alloc, _Args...>,
     _Predicate<_Tp, _Args..., _Alloc>>,
      _Predicate<_Tp, _Args...>>::type { };

  template<typename _Tp, typename _Alloc, typename... _Args>
    struct __is_uses_allocator_constructible
    : __is_uses_allocator_predicate<is_constructible, _Tp, _Alloc, _Args...>
    { };


  template<typename _Tp, typename _Alloc, typename... _Args>
    constexpr bool __is_uses_allocator_constructible_v =
      __is_uses_allocator_constructible<_Tp, _Alloc, _Args...>::value;


  template<typename _Tp, typename _Alloc, typename... _Args>
    struct __is_nothrow_uses_allocator_constructible
    : __is_uses_allocator_predicate<is_nothrow_constructible,
        _Tp, _Alloc, _Args...>
    { };



  template<typename _Tp, typename _Alloc, typename... _Args>
    constexpr bool
    __is_nothrow_uses_allocator_constructible_v =
      __is_nothrow_uses_allocator_constructible<_Tp, _Alloc, _Args...>::value;


  template<typename _Tp, typename... _Args>
    void __uses_allocator_construct_impl(__uses_alloc0 __a, _Tp* __ptr,
      _Args&&... __args)
    { ::new ((void*)__ptr) _Tp(std::forward<_Args>(__args)...); }

  template<typename _Tp, typename _Alloc, typename... _Args>
    void __uses_allocator_construct_impl(__uses_alloc1<_Alloc> __a, _Tp* __ptr,
      _Args&&... __args)
    {
      ::new ((void*)__ptr) _Tp(allocator_arg, *__a._M_a,
          std::forward<_Args>(__args)...);
    }

  template<typename _Tp, typename _Alloc, typename... _Args>
    void __uses_allocator_construct_impl(__uses_alloc2<_Alloc> __a, _Tp* __ptr,
      _Args&&... __args)
    { ::new ((void*)__ptr) _Tp(std::forward<_Args>(__args)..., *__a._M_a); }

  template<typename _Tp, typename _Alloc, typename... _Args>
    void __uses_allocator_construct(const _Alloc& __a, _Tp* __ptr,
        _Args&&... __args)
    {
      std::__uses_allocator_construct_impl(
   std::__use_alloc<_Tp, _Alloc, _Args...>(__a), __ptr,
   std::forward<_Args>(__args)...);
    }


}
# 41 "/usr/include/c++/9.2.0/tuple" 2 3
# 1 "/usr/include/c++/9.2.0/bits/invoke.h" 1 3
# 33 "/usr/include/c++/9.2.0/bits/invoke.h" 3
       
# 34 "/usr/include/c++/9.2.0/bits/invoke.h" 3







namespace std __attribute__ ((__visibility__ ("default")))
{

# 52 "/usr/include/c++/9.2.0/bits/invoke.h" 3
  template<typename _Tp, typename _Up = typename __inv_unwrap<_Tp>::type>
    constexpr _Up&&
    __invfwd(typename remove_reference<_Tp>::type& __t) noexcept
    { return static_cast<_Up&&>(__t); }

  template<typename _Res, typename _Fn, typename... _Args>
    constexpr _Res
    __invoke_impl(__invoke_other, _Fn&& __f, _Args&&... __args)
    { return std::forward<_Fn>(__f)(std::forward<_Args>(__args)...); }

  template<typename _Res, typename _MemFun, typename _Tp, typename... _Args>
    constexpr _Res
    __invoke_impl(__invoke_memfun_ref, _MemFun&& __f, _Tp&& __t,
    _Args&&... __args)
    { return (__invfwd<_Tp>(__t).*__f)(std::forward<_Args>(__args)...); }

  template<typename _Res, typename _MemFun, typename _Tp, typename... _Args>
    constexpr _Res
    __invoke_impl(__invoke_memfun_deref, _MemFun&& __f, _Tp&& __t,
    _Args&&... __args)
    {
      return ((*std::forward<_Tp>(__t)).*__f)(std::forward<_Args>(__args)...);
    }

  template<typename _Res, typename _MemPtr, typename _Tp>
    constexpr _Res
    __invoke_impl(__invoke_memobj_ref, _MemPtr&& __f, _Tp&& __t)
    { return __invfwd<_Tp>(__t).*__f; }

  template<typename _Res, typename _MemPtr, typename _Tp>
    constexpr _Res
    __invoke_impl(__invoke_memobj_deref, _MemPtr&& __f, _Tp&& __t)
    { return (*std::forward<_Tp>(__t)).*__f; }


  template<typename _Callable, typename... _Args>
    constexpr typename __invoke_result<_Callable, _Args...>::type
    __invoke(_Callable&& __fn, _Args&&... __args)
    noexcept(__is_nothrow_invocable<_Callable, _Args...>::value)
    {
      using __result = __invoke_result<_Callable, _Args...>;
      using __type = typename __result::type;
      using __tag = typename __result::__invoke_type;
      return std::__invoke_impl<__type>(__tag{}, std::forward<_Callable>(__fn),
     std::forward<_Args>(__args)...);
    }


}
# 42 "/usr/include/c++/9.2.0/tuple" 2 3

namespace std __attribute__ ((__visibility__ ("default")))
{







  template<typename... _Elements>
    class tuple;

  template<typename _Tp>
    struct __is_empty_non_tuple : is_empty<_Tp> { };


  template<typename _El0, typename... _El>
    struct __is_empty_non_tuple<tuple<_El0, _El...>> : false_type { };


  template<typename _Tp>
    using __empty_not_final
    = typename conditional<__is_final(_Tp), false_type,
      __is_empty_non_tuple<_Tp>>::type;

  template<std::size_t _Idx, typename _Head,
    bool = __empty_not_final<_Head>::value>
    struct _Head_base;

  template<std::size_t _Idx, typename _Head>
    struct _Head_base<_Idx, _Head, true>
    : public _Head
    {
      constexpr _Head_base()
      : _Head() { }

      constexpr _Head_base(const _Head& __h)
      : _Head(__h) { }

      constexpr _Head_base(const _Head_base&) = default;
      constexpr _Head_base(_Head_base&&) = default;

      template<typename _UHead>
        constexpr _Head_base(_UHead&& __h)
 : _Head(std::forward<_UHead>(__h)) { }

      _Head_base(allocator_arg_t, __uses_alloc0)
      : _Head() { }

      template<typename _Alloc>
 _Head_base(allocator_arg_t, __uses_alloc1<_Alloc> __a)
 : _Head(allocator_arg, *__a._M_a) { }

      template<typename _Alloc>
 _Head_base(allocator_arg_t, __uses_alloc2<_Alloc> __a)
 : _Head(*__a._M_a) { }

      template<typename _UHead>
 _Head_base(__uses_alloc0, _UHead&& __uhead)
 : _Head(std::forward<_UHead>(__uhead)) { }

      template<typename _Alloc, typename _UHead>
 _Head_base(__uses_alloc1<_Alloc> __a, _UHead&& __uhead)
 : _Head(allocator_arg, *__a._M_a, std::forward<_UHead>(__uhead)) { }

      template<typename _Alloc, typename _UHead>
 _Head_base(__uses_alloc2<_Alloc> __a, _UHead&& __uhead)
 : _Head(std::forward<_UHead>(__uhead), *__a._M_a) { }

      static constexpr _Head&
      _M_head(_Head_base& __b) noexcept { return __b; }

      static constexpr const _Head&
      _M_head(const _Head_base& __b) noexcept { return __b; }
    };

  template<std::size_t _Idx, typename _Head>
    struct _Head_base<_Idx, _Head, false>
    {
      constexpr _Head_base()
      : _M_head_impl() { }

      constexpr _Head_base(const _Head& __h)
      : _M_head_impl(__h) { }

      constexpr _Head_base(const _Head_base&) = default;
      constexpr _Head_base(_Head_base&&) = default;

      template<typename _UHead>
        constexpr _Head_base(_UHead&& __h)
 : _M_head_impl(std::forward<_UHead>(__h)) { }

      _Head_base(allocator_arg_t, __uses_alloc0)
      : _M_head_impl() { }

      template<typename _Alloc>
 _Head_base(allocator_arg_t, __uses_alloc1<_Alloc> __a)
 : _M_head_impl(allocator_arg, *__a._M_a) { }

      template<typename _Alloc>
 _Head_base(allocator_arg_t, __uses_alloc2<_Alloc> __a)
 : _M_head_impl(*__a._M_a) { }

      template<typename _UHead>
 _Head_base(__uses_alloc0, _UHead&& __uhead)
 : _M_head_impl(std::forward<_UHead>(__uhead)) { }

      template<typename _Alloc, typename _UHead>
 _Head_base(__uses_alloc1<_Alloc> __a, _UHead&& __uhead)
 : _M_head_impl(allocator_arg, *__a._M_a, std::forward<_UHead>(__uhead))
 { }

      template<typename _Alloc, typename _UHead>
 _Head_base(__uses_alloc2<_Alloc> __a, _UHead&& __uhead)
 : _M_head_impl(std::forward<_UHead>(__uhead), *__a._M_a) { }

      static constexpr _Head&
      _M_head(_Head_base& __b) noexcept { return __b._M_head_impl; }

      static constexpr const _Head&
      _M_head(const _Head_base& __b) noexcept { return __b._M_head_impl; }

      _Head _M_head_impl;
    };
# 176 "/usr/include/c++/9.2.0/tuple" 3
  template<std::size_t _Idx, typename... _Elements>
    struct _Tuple_impl;






  template<std::size_t _Idx, typename _Head, typename... _Tail>
    struct _Tuple_impl<_Idx, _Head, _Tail...>
    : public _Tuple_impl<_Idx + 1, _Tail...>,
      private _Head_base<_Idx, _Head>
    {
      template<std::size_t, typename...> friend class _Tuple_impl;

      typedef _Tuple_impl<_Idx + 1, _Tail...> _Inherited;
      typedef _Head_base<_Idx, _Head> _Base;

      static constexpr _Head&
      _M_head(_Tuple_impl& __t) noexcept { return _Base::_M_head(__t); }

      static constexpr const _Head&
      _M_head(const _Tuple_impl& __t) noexcept { return _Base::_M_head(__t); }

      static constexpr _Inherited&
      _M_tail(_Tuple_impl& __t) noexcept { return __t; }

      static constexpr const _Inherited&
      _M_tail(const _Tuple_impl& __t) noexcept { return __t; }

      constexpr _Tuple_impl()
      : _Inherited(), _Base() { }

      explicit
      constexpr _Tuple_impl(const _Head& __head, const _Tail&... __tail)
      : _Inherited(__tail...), _Base(__head) { }

      template<typename _UHead, typename... _UTail, typename = typename
               enable_if<sizeof...(_Tail) == sizeof...(_UTail)>::type>
        explicit
        constexpr _Tuple_impl(_UHead&& __head, _UTail&&... __tail)
 : _Inherited(std::forward<_UTail>(__tail)...),
   _Base(std::forward<_UHead>(__head)) { }

      constexpr _Tuple_impl(const _Tuple_impl&) = default;



      _Tuple_impl& operator=(const _Tuple_impl&) = delete;

      constexpr
      _Tuple_impl(_Tuple_impl&& __in)
      noexcept(__and_<is_nothrow_move_constructible<_Head>,
               is_nothrow_move_constructible<_Inherited>>::value)
      : _Inherited(std::move(_M_tail(__in))),
 _Base(std::forward<_Head>(_M_head(__in))) { }

      template<typename... _UElements>
        constexpr _Tuple_impl(const _Tuple_impl<_Idx, _UElements...>& __in)
 : _Inherited(_Tuple_impl<_Idx, _UElements...>::_M_tail(__in)),
   _Base(_Tuple_impl<_Idx, _UElements...>::_M_head(__in)) { }

      template<typename _UHead, typename... _UTails>
        constexpr _Tuple_impl(_Tuple_impl<_Idx, _UHead, _UTails...>&& __in)
 : _Inherited(std::move
       (_Tuple_impl<_Idx, _UHead, _UTails...>::_M_tail(__in))),
   _Base(std::forward<_UHead>
  (_Tuple_impl<_Idx, _UHead, _UTails...>::_M_head(__in))) { }

      template<typename _Alloc>
 _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a)
 : _Inherited(__tag, __a),
          _Base(__tag, __use_alloc<_Head>(__a)) { }

      template<typename _Alloc>
 _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a,
      const _Head& __head, const _Tail&... __tail)
 : _Inherited(__tag, __a, __tail...),
          _Base(__use_alloc<_Head, _Alloc, _Head>(__a), __head) { }

      template<typename _Alloc, typename _UHead, typename... _UTail,
               typename = typename enable_if<sizeof...(_Tail)
          == sizeof...(_UTail)>::type>
 _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a,
             _UHead&& __head, _UTail&&... __tail)
 : _Inherited(__tag, __a, std::forward<_UTail>(__tail)...),
          _Base(__use_alloc<_Head, _Alloc, _UHead>(__a),
         std::forward<_UHead>(__head)) { }

      template<typename _Alloc>
        _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a,
             const _Tuple_impl& __in)
 : _Inherited(__tag, __a, _M_tail(__in)),
          _Base(__use_alloc<_Head, _Alloc, _Head>(__a), _M_head(__in)) { }

      template<typename _Alloc>
 _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a,
             _Tuple_impl&& __in)
 : _Inherited(__tag, __a, std::move(_M_tail(__in))),
   _Base(__use_alloc<_Head, _Alloc, _Head>(__a),
         std::forward<_Head>(_M_head(__in))) { }

      template<typename _Alloc, typename... _UElements>
 _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a,
             const _Tuple_impl<_Idx, _UElements...>& __in)
 : _Inherited(__tag, __a,
       _Tuple_impl<_Idx, _UElements...>::_M_tail(__in)),
   _Base(__use_alloc<_Head, _Alloc, _Head>(__a),
  _Tuple_impl<_Idx, _UElements...>::_M_head(__in)) { }

      template<typename _Alloc, typename _UHead, typename... _UTails>
 _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a,
             _Tuple_impl<_Idx, _UHead, _UTails...>&& __in)
 : _Inherited(__tag, __a, std::move
       (_Tuple_impl<_Idx, _UHead, _UTails...>::_M_tail(__in))),
   _Base(__use_alloc<_Head, _Alloc, _UHead>(__a),
                std::forward<_UHead>
  (_Tuple_impl<_Idx, _UHead, _UTails...>::_M_head(__in))) { }

      template<typename... _UElements>
        void
        _M_assign(const _Tuple_impl<_Idx, _UElements...>& __in)
        {
   _M_head(*this) = _Tuple_impl<_Idx, _UElements...>::_M_head(__in);
   _M_tail(*this)._M_assign(
       _Tuple_impl<_Idx, _UElements...>::_M_tail(__in));
 }

      template<typename _UHead, typename... _UTails>
        void
        _M_assign(_Tuple_impl<_Idx, _UHead, _UTails...>&& __in)
        {
   _M_head(*this) = std::forward<_UHead>
     (_Tuple_impl<_Idx, _UHead, _UTails...>::_M_head(__in));
   _M_tail(*this)._M_assign(
       std::move(_Tuple_impl<_Idx, _UHead, _UTails...>::_M_tail(__in)));
 }

    protected:
      void
      _M_swap(_Tuple_impl& __in)
      {
 using std::swap;
 swap(_M_head(*this), _M_head(__in));
 _Inherited::_M_swap(_M_tail(__in));
      }
    };


  template<std::size_t _Idx, typename _Head>
    struct _Tuple_impl<_Idx, _Head>
    : private _Head_base<_Idx, _Head>
    {
      template<std::size_t, typename...> friend class _Tuple_impl;

      typedef _Head_base<_Idx, _Head> _Base;

      static constexpr _Head&
      _M_head(_Tuple_impl& __t) noexcept { return _Base::_M_head(__t); }

      static constexpr const _Head&
      _M_head(const _Tuple_impl& __t) noexcept { return _Base::_M_head(__t); }

      constexpr _Tuple_impl()
      : _Base() { }

      explicit
      constexpr _Tuple_impl(const _Head& __head)
      : _Base(__head) { }

      template<typename _UHead>
        explicit
        constexpr _Tuple_impl(_UHead&& __head)
 : _Base(std::forward<_UHead>(__head)) { }

      constexpr _Tuple_impl(const _Tuple_impl&) = default;



      _Tuple_impl& operator=(const _Tuple_impl&) = delete;

      constexpr
      _Tuple_impl(_Tuple_impl&& __in)
      noexcept(is_nothrow_move_constructible<_Head>::value)
      : _Base(std::forward<_Head>(_M_head(__in))) { }

      template<typename _UHead>
        constexpr _Tuple_impl(const _Tuple_impl<_Idx, _UHead>& __in)
 : _Base(_Tuple_impl<_Idx, _UHead>::_M_head(__in)) { }

      template<typename _UHead>
        constexpr _Tuple_impl(_Tuple_impl<_Idx, _UHead>&& __in)
 : _Base(std::forward<_UHead>(_Tuple_impl<_Idx, _UHead>::_M_head(__in)))
 { }

      template<typename _Alloc>
 _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a)
 : _Base(__tag, __use_alloc<_Head>(__a)) { }

      template<typename _Alloc>
 _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a,
      const _Head& __head)
 : _Base(__use_alloc<_Head, _Alloc, _Head>(__a), __head) { }

      template<typename _Alloc, typename _UHead>
 _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a,
             _UHead&& __head)
 : _Base(__use_alloc<_Head, _Alloc, _UHead>(__a),
         std::forward<_UHead>(__head)) { }

      template<typename _Alloc>
        _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a,
             const _Tuple_impl& __in)
 : _Base(__use_alloc<_Head, _Alloc, _Head>(__a), _M_head(__in)) { }

      template<typename _Alloc>
 _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a,
             _Tuple_impl&& __in)
 : _Base(__use_alloc<_Head, _Alloc, _Head>(__a),
         std::forward<_Head>(_M_head(__in))) { }

      template<typename _Alloc, typename _UHead>
 _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a,
             const _Tuple_impl<_Idx, _UHead>& __in)
 : _Base(__use_alloc<_Head, _Alloc, _Head>(__a),
  _Tuple_impl<_Idx, _UHead>::_M_head(__in)) { }

      template<typename _Alloc, typename _UHead>
 _Tuple_impl(allocator_arg_t __tag, const _Alloc& __a,
             _Tuple_impl<_Idx, _UHead>&& __in)
 : _Base(__use_alloc<_Head, _Alloc, _UHead>(__a),
                std::forward<_UHead>(_Tuple_impl<_Idx, _UHead>::_M_head(__in)))
 { }

      template<typename _UHead>
        void
        _M_assign(const _Tuple_impl<_Idx, _UHead>& __in)
        {
   _M_head(*this) = _Tuple_impl<_Idx, _UHead>::_M_head(__in);
 }

      template<typename _UHead>
        void
        _M_assign(_Tuple_impl<_Idx, _UHead>&& __in)
        {
   _M_head(*this)
     = std::forward<_UHead>(_Tuple_impl<_Idx, _UHead>::_M_head(__in));
 }

    protected:
      void
      _M_swap(_Tuple_impl& __in)
      {
 using std::swap;
 swap(_M_head(*this), _M_head(__in));
      }
    };



  template<bool, typename... _Elements>
  struct _TC
  {
    template<typename... _UElements>
    static constexpr bool _ConstructibleTuple()
    {
      return __and_<is_constructible<_Elements, const _UElements&>...>::value;
    }

    template<typename... _UElements>
    static constexpr bool _ImplicitlyConvertibleTuple()
    {
      return __and_<is_convertible<const _UElements&, _Elements>...>::value;
    }

    template<typename... _UElements>
    static constexpr bool _MoveConstructibleTuple()
    {
      return __and_<is_constructible<_Elements, _UElements&&>...>::value;
    }

    template<typename... _UElements>
    static constexpr bool _ImplicitlyMoveConvertibleTuple()
    {
      return __and_<is_convertible<_UElements&&, _Elements>...>::value;
    }

    template<typename _SrcTuple>
    static constexpr bool _NonNestedTuple()
    {
      return __and_<__not_<is_same<tuple<_Elements...>,
        __remove_cvref_t<_SrcTuple>>>,
                     __not_<is_convertible<_SrcTuple, _Elements...>>,
                     __not_<is_constructible<_Elements..., _SrcTuple>>
              >::value;
    }

    template<typename... _UElements>
    static constexpr bool _NotSameTuple()
    {
      return __not_<is_same<tuple<_Elements...>,
        __remove_cvref_t<_UElements>...>>::value;
    }
  };

  template<typename... _Elements>
  struct _TC<false, _Elements...>
  {
    template<typename... _UElements>
    static constexpr bool _ConstructibleTuple()
    {
      return false;
    }

    template<typename... _UElements>
    static constexpr bool _ImplicitlyConvertibleTuple()
    {
      return false;
    }

    template<typename... _UElements>
    static constexpr bool _MoveConstructibleTuple()
    {
      return false;
    }

    template<typename... _UElements>
    static constexpr bool _ImplicitlyMoveConvertibleTuple()
    {
      return false;
    }

    template<typename... _UElements>
    static constexpr bool _NonNestedTuple()
    {
      return true;
    }

    template<typename... _UElements>
    static constexpr bool _NotSameTuple()
    {
      return true;
    }
  };


  template<typename... _Elements>
    class tuple : public _Tuple_impl<0, _Elements...>
    {
      typedef _Tuple_impl<0, _Elements...> _Inherited;



      template<typename _Dummy>
      struct _TC2
      {
        static constexpr bool _DefaultConstructibleTuple()
        {
          return __and_<is_default_constructible<_Elements>...>::value;
        }
        static constexpr bool _ImplicitlyDefaultConstructibleTuple()
        {
          return __and_<__is_implicitly_default_constructible<_Elements>...>
            ::value;
        }
      };

      template<typename... _UElements>
 static constexpr
 __enable_if_t<sizeof...(_UElements) == sizeof...(_Elements), bool>
 __assignable()
 { return __and_<is_assignable<_Elements&, _UElements>...>::value; }

      template<typename... _UElements>
 static constexpr bool __nothrow_assignable()
 {
   return
     __and_<is_nothrow_assignable<_Elements&, _UElements>...>::value;
 }

    public:
      template<typename _Dummy = void,
               typename enable_if<_TC2<_Dummy>::
                                    _ImplicitlyDefaultConstructibleTuple(),
                                  bool>::type = true>
      constexpr tuple()
      : _Inherited() { }

      template<typename _Dummy = void,
               typename enable_if<_TC2<_Dummy>::
                                    _DefaultConstructibleTuple()
                                  &&
                                  !_TC2<_Dummy>::
                                    _ImplicitlyDefaultConstructibleTuple(),
                                  bool>::type = false>
      explicit constexpr tuple()
      : _Inherited() { }



      template<typename _Dummy> using _TCC =
        _TC<is_same<_Dummy, void>::value,
            _Elements...>;

      template<typename _Dummy = void,
               typename enable_if<
                 _TCC<_Dummy>::template
                   _ConstructibleTuple<_Elements...>()
                 && _TCC<_Dummy>::template
                   _ImplicitlyConvertibleTuple<_Elements...>()
                 && (sizeof...(_Elements) >= 1),
               bool>::type=true>
        constexpr tuple(const _Elements&... __elements)
      : _Inherited(__elements...) { }

      template<typename _Dummy = void,
               typename enable_if<
                 _TCC<_Dummy>::template
                   _ConstructibleTuple<_Elements...>()
                 && !_TCC<_Dummy>::template
                   _ImplicitlyConvertibleTuple<_Elements...>()
                 && (sizeof...(_Elements) >= 1),
               bool>::type=false>
      explicit constexpr tuple(const _Elements&... __elements)
      : _Inherited(__elements...) { }



      template<typename... _UElements> using _TMC =
                  _TC<(sizeof...(_Elements) == sizeof...(_UElements))
        && (_TC<(sizeof...(_UElements)==1), _Elements...>::
     template _NotSameTuple<_UElements...>()),
                      _Elements...>;



      template<typename... _UElements> using _TMCT =
                  _TC<(sizeof...(_Elements) == sizeof...(_UElements))
        && !is_same<tuple<_Elements...>,
      tuple<_UElements...>>::value,
                      _Elements...>;

      template<typename... _UElements, typename
        enable_if<
    _TMC<_UElements...>::template
                    _MoveConstructibleTuple<_UElements...>()
                  && _TMC<_UElements...>::template
                    _ImplicitlyMoveConvertibleTuple<_UElements...>()
                  && (sizeof...(_Elements) >= 1),
        bool>::type=true>
        constexpr tuple(_UElements&&... __elements)
        : _Inherited(std::forward<_UElements>(__elements)...) { }

      template<typename... _UElements, typename
        enable_if<
    _TMC<_UElements...>::template
                    _MoveConstructibleTuple<_UElements...>()
                  && !_TMC<_UElements...>::template
                    _ImplicitlyMoveConvertibleTuple<_UElements...>()
                  && (sizeof...(_Elements) >= 1),
        bool>::type=false>
        explicit constexpr tuple(_UElements&&... __elements)
 : _Inherited(std::forward<_UElements>(__elements)...) { }

      constexpr tuple(const tuple&) = default;

      constexpr tuple(tuple&&) = default;



      template<typename _Dummy> using _TNTC =
        _TC<is_same<_Dummy, void>::value && sizeof...(_Elements) == 1,
            _Elements...>;

      template<typename... _UElements, typename _Dummy = void, typename
        enable_if<_TMCT<_UElements...>::template
                    _ConstructibleTuple<_UElements...>()
                  && _TMCT<_UElements...>::template
                    _ImplicitlyConvertibleTuple<_UElements...>()
                  && _TNTC<_Dummy>::template
                    _NonNestedTuple<const tuple<_UElements...>&>(),
        bool>::type=true>
        constexpr tuple(const tuple<_UElements...>& __in)
        : _Inherited(static_cast<const _Tuple_impl<0, _UElements...>&>(__in))
        { }

      template<typename... _UElements, typename _Dummy = void, typename
        enable_if<_TMCT<_UElements...>::template
                    _ConstructibleTuple<_UElements...>()
                  && !_TMCT<_UElements...>::template
                    _ImplicitlyConvertibleTuple<_UElements...>()
                  && _TNTC<_Dummy>::template
                    _NonNestedTuple<const tuple<_UElements...>&>(),
        bool>::type=false>
        explicit constexpr tuple(const tuple<_UElements...>& __in)
        : _Inherited(static_cast<const _Tuple_impl<0, _UElements...>&>(__in))
        { }

      template<typename... _UElements, typename _Dummy = void, typename
        enable_if<_TMCT<_UElements...>::template
                    _MoveConstructibleTuple<_UElements...>()
                  && _TMCT<_UElements...>::template
                    _ImplicitlyMoveConvertibleTuple<_UElements...>()
                  && _TNTC<_Dummy>::template
                    _NonNestedTuple<tuple<_UElements...>&&>(),
        bool>::type=true>
        constexpr tuple(tuple<_UElements...>&& __in)
        : _Inherited(static_cast<_Tuple_impl<0, _UElements...>&&>(__in)) { }

      template<typename... _UElements, typename _Dummy = void, typename
        enable_if<_TMCT<_UElements...>::template
                    _MoveConstructibleTuple<_UElements...>()
                  && !_TMCT<_UElements...>::template
                    _ImplicitlyMoveConvertibleTuple<_UElements...>()
                  && _TNTC<_Dummy>::template
                    _NonNestedTuple<tuple<_UElements...>&&>(),
        bool>::type=false>
        explicit constexpr tuple(tuple<_UElements...>&& __in)
        : _Inherited(static_cast<_Tuple_impl<0, _UElements...>&&>(__in)) { }



      template<typename _Alloc>
 tuple(allocator_arg_t __tag, const _Alloc& __a)
 : _Inherited(__tag, __a) { }

      template<typename _Alloc, typename _Dummy = void,
               typename enable_if<
                 _TCC<_Dummy>::template
                   _ConstructibleTuple<_Elements...>()
                 && _TCC<_Dummy>::template
                   _ImplicitlyConvertibleTuple<_Elements...>(),
               bool>::type=true>
 tuple(allocator_arg_t __tag, const _Alloc& __a,
       const _Elements&... __elements)
 : _Inherited(__tag, __a, __elements...) { }

      template<typename _Alloc, typename _Dummy = void,
               typename enable_if<
                 _TCC<_Dummy>::template
                   _ConstructibleTuple<_Elements...>()
                 && !_TCC<_Dummy>::template
                   _ImplicitlyConvertibleTuple<_Elements...>(),
               bool>::type=false>
 explicit tuple(allocator_arg_t __tag, const _Alloc& __a,
                       const _Elements&... __elements)
 : _Inherited(__tag, __a, __elements...) { }

      template<typename _Alloc, typename... _UElements, typename
        enable_if<_TMC<_UElements...>::template
                    _MoveConstructibleTuple<_UElements...>()
                  && _TMC<_UElements...>::template
                    _ImplicitlyMoveConvertibleTuple<_UElements...>(),
        bool>::type=true>
 tuple(allocator_arg_t __tag, const _Alloc& __a,
       _UElements&&... __elements)
 : _Inherited(__tag, __a, std::forward<_UElements>(__elements)...)
        { }

      template<typename _Alloc, typename... _UElements, typename
        enable_if<_TMC<_UElements...>::template
                    _MoveConstructibleTuple<_UElements...>()
                  && !_TMC<_UElements...>::template
                    _ImplicitlyMoveConvertibleTuple<_UElements...>(),
        bool>::type=false>
 explicit tuple(allocator_arg_t __tag, const _Alloc& __a,
       _UElements&&... __elements)
 : _Inherited(__tag, __a, std::forward<_UElements>(__elements)...)
        { }

      template<typename _Alloc>
 tuple(allocator_arg_t __tag, const _Alloc& __a, const tuple& __in)
 : _Inherited(__tag, __a, static_cast<const _Inherited&>(__in)) { }

      template<typename _Alloc>
 tuple(allocator_arg_t __tag, const _Alloc& __a, tuple&& __in)
 : _Inherited(__tag, __a, static_cast<_Inherited&&>(__in)) { }

      template<typename _Alloc, typename _Dummy = void,
        typename... _UElements, typename
        enable_if<_TMCT<_UElements...>::template
                    _ConstructibleTuple<_UElements...>()
                  && _TMCT<_UElements...>::template
                    _ImplicitlyConvertibleTuple<_UElements...>()
                  && _TNTC<_Dummy>::template
                    _NonNestedTuple<const tuple<_UElements...>&>(),
        bool>::type=true>
 tuple(allocator_arg_t __tag, const _Alloc& __a,
       const tuple<_UElements...>& __in)
 : _Inherited(__tag, __a,
              static_cast<const _Tuple_impl<0, _UElements...>&>(__in))
 { }

      template<typename _Alloc, typename _Dummy = void,
        typename... _UElements, typename
        enable_if<_TMCT<_UElements...>::template
                    _ConstructibleTuple<_UElements...>()
                  && !_TMCT<_UElements...>::template
                    _ImplicitlyConvertibleTuple<_UElements...>()
                  && _TNTC<_Dummy>::template
                    _NonNestedTuple<const tuple<_UElements...>&>(),
        bool>::type=false>
 explicit tuple(allocator_arg_t __tag, const _Alloc& __a,
       const tuple<_UElements...>& __in)
 : _Inherited(__tag, __a,
              static_cast<const _Tuple_impl<0, _UElements...>&>(__in))
 { }

      template<typename _Alloc, typename _Dummy = void,
        typename... _UElements, typename
        enable_if<_TMCT<_UElements...>::template
                    _MoveConstructibleTuple<_UElements...>()
                  && _TMCT<_UElements...>::template
                    _ImplicitlyMoveConvertibleTuple<_UElements...>()
                  && _TNTC<_Dummy>::template
                    _NonNestedTuple<tuple<_UElements...>&&>(),
        bool>::type=true>
 tuple(allocator_arg_t __tag, const _Alloc& __a,
       tuple<_UElements...>&& __in)
 : _Inherited(__tag, __a,
              static_cast<_Tuple_impl<0, _UElements...>&&>(__in))
 { }

      template<typename _Alloc, typename _Dummy = void,
        typename... _UElements, typename
        enable_if<_TMCT<_UElements...>::template
                    _MoveConstructibleTuple<_UElements...>()
                  && !_TMCT<_UElements...>::template
                    _ImplicitlyMoveConvertibleTuple<_UElements...>()
                  && _TNTC<_Dummy>::template
                    _NonNestedTuple<tuple<_UElements...>&&>(),
        bool>::type=false>
 explicit tuple(allocator_arg_t __tag, const _Alloc& __a,
       tuple<_UElements...>&& __in)
 : _Inherited(__tag, __a,
              static_cast<_Tuple_impl<0, _UElements...>&&>(__in))
 { }



      tuple&
      operator=(typename conditional<__assignable<const _Elements&...>(),
         const tuple&,
         const __nonesuch_no_braces&>::type __in)
      noexcept(__nothrow_assignable<const _Elements&...>())
      {
 this->_M_assign(__in);
 return *this;
      }

      tuple&
      operator=(typename conditional<__assignable<_Elements...>(),
         tuple&&,
         __nonesuch_no_braces&&>::type __in)
      noexcept(__nothrow_assignable<_Elements...>())
      {
 this->_M_assign(std::move(__in));
 return *this;
      }

      template<typename... _UElements>
 __enable_if_t<__assignable<const _UElements&...>(), tuple&>
 operator=(const tuple<_UElements...>& __in)
 noexcept(__nothrow_assignable<const _UElements&...>())
 {
   this->_M_assign(__in);
   return *this;
 }

      template<typename... _UElements>
 __enable_if_t<__assignable<_UElements...>(), tuple&>
 operator=(tuple<_UElements...>&& __in)
 noexcept(__nothrow_assignable<_UElements...>())
 {
   this->_M_assign(std::move(__in));
   return *this;
 }


      void
      swap(tuple& __in)
      noexcept(__and_<__is_nothrow_swappable<_Elements>...>::value)
      { _Inherited::_M_swap(__in); }
    };
# 875 "/usr/include/c++/9.2.0/tuple" 3
  template<>
    class tuple<>
    {
    public:
      void swap(tuple&) noexcept { }


      tuple() = default;

      template<typename _Alloc>
 tuple(allocator_arg_t, const _Alloc&) { }
      template<typename _Alloc>
 tuple(allocator_arg_t, const _Alloc&, const tuple&) { }
    };



  template<typename _T1, typename _T2>
    class tuple<_T1, _T2> : public _Tuple_impl<0, _T1, _T2>
    {
      typedef _Tuple_impl<0, _T1, _T2> _Inherited;

      template<typename _U1, typename _U2>
 static constexpr bool __assignable()
 {
   return __and_<is_assignable<_T1&, _U1>,
   is_assignable<_T2&, _U2>>::value;
 }

      template<typename _U1, typename _U2>
 static constexpr bool __nothrow_assignable()
 {
   return __and_<is_nothrow_assignable<_T1&, _U1>,
   is_nothrow_assignable<_T2&, _U2>>::value;
 }

    public:
      template <typename _U1 = _T1,
                typename _U2 = _T2,
                typename enable_if<__and_<
                                     __is_implicitly_default_constructible<_U1>,
                                     __is_implicitly_default_constructible<_U2>>
                                   ::value, bool>::type = true>
 constexpr tuple()
 : _Inherited() { }

      template <typename _U1 = _T1,
                typename _U2 = _T2,
                typename enable_if<
                  __and_<
                    is_default_constructible<_U1>,
                    is_default_constructible<_U2>,
                    __not_<
                      __and_<__is_implicitly_default_constructible<_U1>,
                             __is_implicitly_default_constructible<_U2>>>>
                  ::value, bool>::type = false>
 explicit constexpr tuple()
 : _Inherited() { }



      template<typename _Dummy> using _TCC =
        _TC<is_same<_Dummy, void>::value, _T1, _T2>;

      template<typename _Dummy = void, typename
               enable_if<_TCC<_Dummy>::template
                           _ConstructibleTuple<_T1, _T2>()
                         && _TCC<_Dummy>::template
                           _ImplicitlyConvertibleTuple<_T1, _T2>(),
 bool>::type = true>
        constexpr tuple(const _T1& __a1, const _T2& __a2)
        : _Inherited(__a1, __a2) { }

      template<typename _Dummy = void, typename
               enable_if<_TCC<_Dummy>::template
                           _ConstructibleTuple<_T1, _T2>()
                         && !_TCC<_Dummy>::template
                           _ImplicitlyConvertibleTuple<_T1, _T2>(),
 bool>::type = false>
        explicit constexpr tuple(const _T1& __a1, const _T2& __a2)
        : _Inherited(__a1, __a2) { }



      using _TMC = _TC<true, _T1, _T2>;

      template<typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _MoveConstructibleTuple<_U1, _U2>()
                  && _TMC::template
                    _ImplicitlyMoveConvertibleTuple<_U1, _U2>()
           && !is_same<__remove_cvref_t<_U1>, allocator_arg_t>::value,
 bool>::type = true>
        constexpr tuple(_U1&& __a1, _U2&& __a2)
 : _Inherited(std::forward<_U1>(__a1), std::forward<_U2>(__a2)) { }

      template<typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _MoveConstructibleTuple<_U1, _U2>()
                  && !_TMC::template
                    _ImplicitlyMoveConvertibleTuple<_U1, _U2>()
           && !is_same<__remove_cvref_t<_U1>, allocator_arg_t>::value,
 bool>::type = false>
        explicit constexpr tuple(_U1&& __a1, _U2&& __a2)
 : _Inherited(std::forward<_U1>(__a1), std::forward<_U2>(__a2)) { }

      constexpr tuple(const tuple&) = default;

      constexpr tuple(tuple&&) = default;

      template<typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _ConstructibleTuple<_U1, _U2>()
                  && _TMC::template
                    _ImplicitlyConvertibleTuple<_U1, _U2>(),
 bool>::type = true>
        constexpr tuple(const tuple<_U1, _U2>& __in)
 : _Inherited(static_cast<const _Tuple_impl<0, _U1, _U2>&>(__in)) { }

      template<typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _ConstructibleTuple<_U1, _U2>()
                  && !_TMC::template
                    _ImplicitlyConvertibleTuple<_U1, _U2>(),
 bool>::type = false>
        explicit constexpr tuple(const tuple<_U1, _U2>& __in)
 : _Inherited(static_cast<const _Tuple_impl<0, _U1, _U2>&>(__in)) { }

      template<typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _MoveConstructibleTuple<_U1, _U2>()
                  && _TMC::template
                    _ImplicitlyMoveConvertibleTuple<_U1, _U2>(),
 bool>::type = true>
        constexpr tuple(tuple<_U1, _U2>&& __in)
 : _Inherited(static_cast<_Tuple_impl<0, _U1, _U2>&&>(__in)) { }

      template<typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _MoveConstructibleTuple<_U1, _U2>()
                  && !_TMC::template
                    _ImplicitlyMoveConvertibleTuple<_U1, _U2>(),
 bool>::type = false>
        explicit constexpr tuple(tuple<_U1, _U2>&& __in)
 : _Inherited(static_cast<_Tuple_impl<0, _U1, _U2>&&>(__in)) { }

      template<typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _ConstructibleTuple<_U1, _U2>()
                  && _TMC::template
                    _ImplicitlyConvertibleTuple<_U1, _U2>(),
 bool>::type = true>
        constexpr tuple(const pair<_U1, _U2>& __in)
 : _Inherited(__in.first, __in.second) { }

      template<typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _ConstructibleTuple<_U1, _U2>()
                  && !_TMC::template
                    _ImplicitlyConvertibleTuple<_U1, _U2>(),
 bool>::type = false>
        explicit constexpr tuple(const pair<_U1, _U2>& __in)
 : _Inherited(__in.first, __in.second) { }

      template<typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _MoveConstructibleTuple<_U1, _U2>()
                  && _TMC::template
                    _ImplicitlyMoveConvertibleTuple<_U1, _U2>(),
 bool>::type = true>
        constexpr tuple(pair<_U1, _U2>&& __in)
 : _Inherited(std::forward<_U1>(__in.first),
       std::forward<_U2>(__in.second)) { }

      template<typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _MoveConstructibleTuple<_U1, _U2>()
                  && !_TMC::template
                    _ImplicitlyMoveConvertibleTuple<_U1, _U2>(),
 bool>::type = false>
        explicit constexpr tuple(pair<_U1, _U2>&& __in)
 : _Inherited(std::forward<_U1>(__in.first),
       std::forward<_U2>(__in.second)) { }



      template<typename _Alloc>
 tuple(allocator_arg_t __tag, const _Alloc& __a)
 : _Inherited(__tag, __a) { }

      template<typename _Alloc, typename _Dummy = void,
               typename enable_if<
                 _TCC<_Dummy>::template
                   _ConstructibleTuple<_T1, _T2>()
                 && _TCC<_Dummy>::template
                   _ImplicitlyConvertibleTuple<_T1, _T2>(),
               bool>::type=true>

 tuple(allocator_arg_t __tag, const _Alloc& __a,
       const _T1& __a1, const _T2& __a2)
 : _Inherited(__tag, __a, __a1, __a2) { }

      template<typename _Alloc, typename _Dummy = void,
               typename enable_if<
                 _TCC<_Dummy>::template
                   _ConstructibleTuple<_T1, _T2>()
                 && !_TCC<_Dummy>::template
                   _ImplicitlyConvertibleTuple<_T1, _T2>(),
               bool>::type=false>

 explicit tuple(allocator_arg_t __tag, const _Alloc& __a,
       const _T1& __a1, const _T2& __a2)
 : _Inherited(__tag, __a, __a1, __a2) { }

      template<typename _Alloc, typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _MoveConstructibleTuple<_U1, _U2>()
                  && _TMC::template
                    _ImplicitlyMoveConvertibleTuple<_U1, _U2>(),
 bool>::type = true>
 tuple(allocator_arg_t __tag, const _Alloc& __a, _U1&& __a1, _U2&& __a2)
 : _Inherited(__tag, __a, std::forward<_U1>(__a1),
              std::forward<_U2>(__a2)) { }

      template<typename _Alloc, typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _MoveConstructibleTuple<_U1, _U2>()
                  && !_TMC::template
                    _ImplicitlyMoveConvertibleTuple<_U1, _U2>(),
 bool>::type = false>
 explicit tuple(allocator_arg_t __tag, const _Alloc& __a,
                       _U1&& __a1, _U2&& __a2)
 : _Inherited(__tag, __a, std::forward<_U1>(__a1),
              std::forward<_U2>(__a2)) { }

      template<typename _Alloc>
 tuple(allocator_arg_t __tag, const _Alloc& __a, const tuple& __in)
 : _Inherited(__tag, __a, static_cast<const _Inherited&>(__in)) { }

      template<typename _Alloc>
 tuple(allocator_arg_t __tag, const _Alloc& __a, tuple&& __in)
 : _Inherited(__tag, __a, static_cast<_Inherited&&>(__in)) { }

      template<typename _Alloc, typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _ConstructibleTuple<_U1, _U2>()
                  && _TMC::template
                    _ImplicitlyConvertibleTuple<_U1, _U2>(),
 bool>::type = true>
 tuple(allocator_arg_t __tag, const _Alloc& __a,
       const tuple<_U1, _U2>& __in)
 : _Inherited(__tag, __a,
              static_cast<const _Tuple_impl<0, _U1, _U2>&>(__in))
 { }

      template<typename _Alloc, typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _ConstructibleTuple<_U1, _U2>()
                  && !_TMC::template
                    _ImplicitlyConvertibleTuple<_U1, _U2>(),
 bool>::type = false>
 explicit tuple(allocator_arg_t __tag, const _Alloc& __a,
       const tuple<_U1, _U2>& __in)
 : _Inherited(__tag, __a,
              static_cast<const _Tuple_impl<0, _U1, _U2>&>(__in))
 { }

      template<typename _Alloc, typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _MoveConstructibleTuple<_U1, _U2>()
                  && _TMC::template
                    _ImplicitlyMoveConvertibleTuple<_U1, _U2>(),
 bool>::type = true>
 tuple(allocator_arg_t __tag, const _Alloc& __a, tuple<_U1, _U2>&& __in)
 : _Inherited(__tag, __a, static_cast<_Tuple_impl<0, _U1, _U2>&&>(__in))
 { }

      template<typename _Alloc, typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _MoveConstructibleTuple<_U1, _U2>()
                  && !_TMC::template
                    _ImplicitlyMoveConvertibleTuple<_U1, _U2>(),
 bool>::type = false>
 explicit tuple(allocator_arg_t __tag, const _Alloc& __a,
                       tuple<_U1, _U2>&& __in)
 : _Inherited(__tag, __a, static_cast<_Tuple_impl<0, _U1, _U2>&&>(__in))
 { }

      template<typename _Alloc, typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _ConstructibleTuple<_U1, _U2>()
                  && _TMC::template
                    _ImplicitlyConvertibleTuple<_U1, _U2>(),
 bool>::type = true>
        tuple(allocator_arg_t __tag, const _Alloc& __a,
       const pair<_U1, _U2>& __in)
 : _Inherited(__tag, __a, __in.first, __in.second) { }

      template<typename _Alloc, typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _ConstructibleTuple<_U1, _U2>()
                  && !_TMC::template
                    _ImplicitlyConvertibleTuple<_U1, _U2>(),
 bool>::type = false>
        explicit tuple(allocator_arg_t __tag, const _Alloc& __a,
       const pair<_U1, _U2>& __in)
 : _Inherited(__tag, __a, __in.first, __in.second) { }

      template<typename _Alloc, typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _MoveConstructibleTuple<_U1, _U2>()
                  && _TMC::template
                    _ImplicitlyMoveConvertibleTuple<_U1, _U2>(),
 bool>::type = true>
        tuple(allocator_arg_t __tag, const _Alloc& __a, pair<_U1, _U2>&& __in)
 : _Inherited(__tag, __a, std::forward<_U1>(__in.first),
       std::forward<_U2>(__in.second)) { }

      template<typename _Alloc, typename _U1, typename _U2, typename
        enable_if<_TMC::template
                    _MoveConstructibleTuple<_U1, _U2>()
                  && !_TMC::template
                    _ImplicitlyMoveConvertibleTuple<_U1, _U2>(),
 bool>::type = false>
        explicit tuple(allocator_arg_t __tag, const _Alloc& __a,
                       pair<_U1, _U2>&& __in)
 : _Inherited(__tag, __a, std::forward<_U1>(__in.first),
       std::forward<_U2>(__in.second)) { }

      tuple&
      operator=(typename conditional<__assignable<const _T1&, const _T2&>(),
         const tuple&,
         const __nonesuch_no_braces&>::type __in)
      noexcept(__nothrow_assignable<const _T1&, const _T2&>())
      {
 this->_M_assign(__in);
 return *this;
      }

      tuple&
      operator=(typename conditional<__assignable<_T1, _T2>(),
         tuple&&,
         __nonesuch_no_braces&&>::type __in)
      noexcept(__nothrow_assignable<_T1, _T2>())
      {
 this->_M_assign(std::move(__in));
 return *this;
      }

      template<typename _U1, typename _U2>
 __enable_if_t<__assignable<const _U1&, const _U2&>(), tuple&>
 operator=(const tuple<_U1, _U2>& __in)
 noexcept(__nothrow_assignable<const _U1&, const _U2&>())
 {
   this->_M_assign(__in);
   return *this;
 }

      template<typename _U1, typename _U2>
 __enable_if_t<__assignable<_U1, _U2>(), tuple&>
 operator=(tuple<_U1, _U2>&& __in)
 noexcept(__nothrow_assignable<_U1, _U2>())
 {
   this->_M_assign(std::move(__in));
   return *this;
 }

      template<typename _U1, typename _U2>
 __enable_if_t<__assignable<const _U1&, const _U2&>(), tuple&>
 operator=(const pair<_U1, _U2>& __in)
 noexcept(__nothrow_assignable<const _U1&, const _U2&>())
 {
   this->_M_head(*this) = __in.first;
   this->_M_tail(*this)._M_head(*this) = __in.second;
   return *this;
 }

      template<typename _U1, typename _U2>
 __enable_if_t<__assignable<_U1, _U2>(), tuple&>
 operator=(pair<_U1, _U2>&& __in)
 noexcept(__nothrow_assignable<_U1, _U2>())
 {
   this->_M_head(*this) = std::forward<_U1>(__in.first);
   this->_M_tail(*this)._M_head(*this) = std::forward<_U2>(__in.second);
   return *this;
 }

      void
      swap(tuple& __in)
      noexcept(__and_<__is_nothrow_swappable<_T1>,
        __is_nothrow_swappable<_T2>>::value)
      { _Inherited::_M_swap(__in); }
    };



  template<typename... _Elements>
    struct tuple_size<tuple<_Elements...>>
    : public integral_constant<std::size_t, sizeof...(_Elements)> { };
# 1284 "/usr/include/c++/9.2.0/tuple" 3
  template<std::size_t __i, typename _Head, typename... _Tail>
    struct tuple_element<__i, tuple<_Head, _Tail...> >
    : tuple_element<__i - 1, tuple<_Tail...> > { };




  template<typename _Head, typename... _Tail>
    struct tuple_element<0, tuple<_Head, _Tail...> >
    {
      typedef _Head type;
    };




  template<size_t __i>
    struct tuple_element<__i, tuple<>>
    {
      static_assert(__i < tuple_size<tuple<>>::value,
   "tuple index is in range");
    };

  template<std::size_t __i, typename _Head, typename... _Tail>
    constexpr _Head&
    __get_helper(_Tuple_impl<__i, _Head, _Tail...>& __t) noexcept
    { return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t); }

  template<std::size_t __i, typename _Head, typename... _Tail>
    constexpr const _Head&
    __get_helper(const _Tuple_impl<__i, _Head, _Tail...>& __t) noexcept
    { return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t); }


  template<std::size_t __i, typename... _Elements>
    constexpr __tuple_element_t<__i, tuple<_Elements...>>&
    get(tuple<_Elements...>& __t) noexcept
    { return std::__get_helper<__i>(__t); }


  template<std::size_t __i, typename... _Elements>
    constexpr const __tuple_element_t<__i, tuple<_Elements...>>&
    get(const tuple<_Elements...>& __t) noexcept
    { return std::__get_helper<__i>(__t); }


  template<std::size_t __i, typename... _Elements>
    constexpr __tuple_element_t<__i, tuple<_Elements...>>&&
    get(tuple<_Elements...>&& __t) noexcept
    {
      typedef __tuple_element_t<__i, tuple<_Elements...>> __element_type;
      return std::forward<__element_type&&>(std::get<__i>(__t));
    }


  template<std::size_t __i, typename... _Elements>
    constexpr const __tuple_element_t<__i, tuple<_Elements...>>&&
    get(const tuple<_Elements...>&& __t) noexcept
    {
      typedef __tuple_element_t<__i, tuple<_Elements...>> __element_type;
      return std::forward<const __element_type&&>(std::get<__i>(__t));
    }





  template<typename _Head, size_t __i, typename... _Tail>
    constexpr _Head&
    __get_helper2(_Tuple_impl<__i, _Head, _Tail...>& __t) noexcept
    { return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t); }

  template<typename _Head, size_t __i, typename... _Tail>
    constexpr const _Head&
    __get_helper2(const _Tuple_impl<__i, _Head, _Tail...>& __t) noexcept
    { return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t); }


  template <typename _Tp, typename... _Types>
    constexpr _Tp&
    get(tuple<_Types...>& __t) noexcept
    { return std::__get_helper2<_Tp>(__t); }


  template <typename _Tp, typename... _Types>
    constexpr _Tp&&
    get(tuple<_Types...>&& __t) noexcept
    { return std::forward<_Tp&&>(std::__get_helper2<_Tp>(__t)); }


  template <typename _Tp, typename... _Types>
    constexpr const _Tp&
    get(const tuple<_Types...>& __t) noexcept
    { return std::__get_helper2<_Tp>(__t); }



  template <typename _Tp, typename... _Types>
    constexpr const _Tp&&
    get(const tuple<_Types...>&& __t) noexcept
    { return std::forward<const _Tp&&>(std::__get_helper2<_Tp>(__t)); }



  template<typename _Tp, typename _Up, size_t __i, size_t __size>
    struct __tuple_compare
    {
      static constexpr bool
      __eq(const _Tp& __t, const _Up& __u)
      {
 return bool(std::get<__i>(__t) == std::get<__i>(__u))
   && __tuple_compare<_Tp, _Up, __i + 1, __size>::__eq(__t, __u);
      }

      static constexpr bool
      __less(const _Tp& __t, const _Up& __u)
      {
 return bool(std::get<__i>(__t) < std::get<__i>(__u))
   || (!bool(std::get<__i>(__u) < std::get<__i>(__t))
       && __tuple_compare<_Tp, _Up, __i + 1, __size>::__less(__t, __u));
      }
    };

  template<typename _Tp, typename _Up, size_t __size>
    struct __tuple_compare<_Tp, _Up, __size, __size>
    {
      static constexpr bool
      __eq(const _Tp&, const _Up&) { return true; }

      static constexpr bool
      __less(const _Tp&, const _Up&) { return false; }
    };

  template<typename... _TElements, typename... _UElements>
    constexpr bool
    operator==(const tuple<_TElements...>& __t,
        const tuple<_UElements...>& __u)
    {
      static_assert(sizeof...(_TElements) == sizeof...(_UElements),
   "tuple objects can only be compared if they have equal sizes.");
      using __compare = __tuple_compare<tuple<_TElements...>,
     tuple<_UElements...>,
     0, sizeof...(_TElements)>;
      return __compare::__eq(__t, __u);
    }

  template<typename... _TElements, typename... _UElements>
    constexpr bool
    operator<(const tuple<_TElements...>& __t,
       const tuple<_UElements...>& __u)
    {
      static_assert(sizeof...(_TElements) == sizeof...(_UElements),
   "tuple objects can only be compared if they have equal sizes.");
      using __compare = __tuple_compare<tuple<_TElements...>,
     tuple<_UElements...>,
     0, sizeof...(_TElements)>;
      return __compare::__less(__t, __u);
    }

  template<typename... _TElements, typename... _UElements>
    constexpr bool
    operator!=(const tuple<_TElements...>& __t,
        const tuple<_UElements...>& __u)
    { return !(__t == __u); }

  template<typename... _TElements, typename... _UElements>
    constexpr bool
    operator>(const tuple<_TElements...>& __t,
       const tuple<_UElements...>& __u)
    { return __u < __t; }

  template<typename... _TElements, typename... _UElements>
    constexpr bool
    operator<=(const tuple<_TElements...>& __t,
        const tuple<_UElements...>& __u)
    { return !(__u < __t); }

  template<typename... _TElements, typename... _UElements>
    constexpr bool
    operator>=(const tuple<_TElements...>& __t,
        const tuple<_UElements...>& __u)
    { return !(__t < __u); }


  template<typename... _Elements>
    constexpr tuple<typename __decay_and_strip<_Elements>::__type...>
    make_tuple(_Elements&&... __args)
    {
      typedef tuple<typename __decay_and_strip<_Elements>::__type...>
 __result_type;
      return __result_type(std::forward<_Elements>(__args)...);
    }




  template<typename... _Elements>
    constexpr tuple<_Elements&&...>
    forward_as_tuple(_Elements&&... __args) noexcept
    { return tuple<_Elements&&...>(std::forward<_Elements>(__args)...); }

  template<size_t, typename, typename, size_t>
    struct __make_tuple_impl;

  template<size_t _Idx, typename _Tuple, typename... _Tp, size_t _Nm>
    struct __make_tuple_impl<_Idx, tuple<_Tp...>, _Tuple, _Nm>
    : __make_tuple_impl<_Idx + 1,
   tuple<_Tp..., __tuple_element_t<_Idx, _Tuple>>,
   _Tuple, _Nm>
    { };

  template<std::size_t _Nm, typename _Tuple, typename... _Tp>
    struct __make_tuple_impl<_Nm, tuple<_Tp...>, _Tuple, _Nm>
    {
      typedef tuple<_Tp...> __type;
    };

  template<typename _Tuple>
    struct __do_make_tuple
    : __make_tuple_impl<0, tuple<>, _Tuple, std::tuple_size<_Tuple>::value>
    { };


  template<typename _Tuple>
    struct __make_tuple
    : public __do_make_tuple<__remove_cvref_t<_Tuple>>
    { };


  template<typename...>
    struct __combine_tuples;

  template<>
    struct __combine_tuples<>
    {
      typedef tuple<> __type;
    };

  template<typename... _Ts>
    struct __combine_tuples<tuple<_Ts...>>
    {
      typedef tuple<_Ts...> __type;
    };

  template<typename... _T1s, typename... _T2s, typename... _Rem>
    struct __combine_tuples<tuple<_T1s...>, tuple<_T2s...>, _Rem...>
    {
      typedef typename __combine_tuples<tuple<_T1s..., _T2s...>,
     _Rem...>::__type __type;
    };


  template<typename... _Tpls>
    struct __tuple_cat_result
    {
      typedef typename __combine_tuples
        <typename __make_tuple<_Tpls>::__type...>::__type __type;
    };



  template<typename...>
    struct __make_1st_indices;

  template<>
    struct __make_1st_indices<>
    {
      typedef std::_Index_tuple<> __type;
    };

  template<typename _Tp, typename... _Tpls>
    struct __make_1st_indices<_Tp, _Tpls...>
    {
      typedef typename std::_Build_index_tuple<std::tuple_size<
 typename std::remove_reference<_Tp>::type>::value>::__type __type;
    };




  template<typename _Ret, typename _Indices, typename... _Tpls>
    struct __tuple_concater;

  template<typename _Ret, std::size_t... _Is, typename _Tp, typename... _Tpls>
    struct __tuple_concater<_Ret, std::_Index_tuple<_Is...>, _Tp, _Tpls...>
    {
      template<typename... _Us>
        static constexpr _Ret
        _S_do(_Tp&& __tp, _Tpls&&... __tps, _Us&&... __us)
        {
   typedef typename __make_1st_indices<_Tpls...>::__type __idx;
   typedef __tuple_concater<_Ret, __idx, _Tpls...> __next;
   return __next::_S_do(std::forward<_Tpls>(__tps)...,
          std::forward<_Us>(__us)...,
          std::get<_Is>(std::forward<_Tp>(__tp))...);
 }
    };

  template<typename _Ret>
    struct __tuple_concater<_Ret, std::_Index_tuple<>>
    {
      template<typename... _Us>
 static constexpr _Ret
 _S_do(_Us&&... __us)
        {
   return _Ret(std::forward<_Us>(__us)...);
 }
    };


  template<typename... _Tpls, typename = typename
           enable_if<__and_<__is_tuple_like<_Tpls>...>::value>::type>
    constexpr auto
    tuple_cat(_Tpls&&... __tpls)
    -> typename __tuple_cat_result<_Tpls...>::__type
    {
      typedef typename __tuple_cat_result<_Tpls...>::__type __ret;
      typedef typename __make_1st_indices<_Tpls...>::__type __idx;
      typedef __tuple_concater<__ret, __idx, _Tpls...> __concater;
      return __concater::_S_do(std::forward<_Tpls>(__tpls)...);
    }




  template<typename... _Elements>
    constexpr tuple<_Elements&...>
    tie(_Elements&... __args) noexcept
    { return tuple<_Elements&...>(__args...); }


  template<typename... _Elements>
    inline


    typename enable_if<__and_<__is_swappable<_Elements>...>::value
      >::type



    swap(tuple<_Elements...>& __x, tuple<_Elements...>& __y)
    noexcept(noexcept(__x.swap(__y)))
    { __x.swap(__y); }


  template<typename... _Elements>
    typename enable_if<!__and_<__is_swappable<_Elements>...>::value>::type
    swap(tuple<_Elements...>&, tuple<_Elements...>&) = delete;






  struct _Swallow_assign
  {
    template<class _Tp>
      constexpr const _Swallow_assign&
      operator=(const _Tp&) const
      { return *this; }
  };



  constexpr _Swallow_assign ignore{};


  template<typename... _Types, typename _Alloc>
    struct uses_allocator<tuple<_Types...>, _Alloc> : true_type { };


  template<class _T1, class _T2>
    template<typename... _Args1, typename... _Args2>
      inline
      pair<_T1, _T2>::
      pair(piecewise_construct_t,
    tuple<_Args1...> __first, tuple<_Args2...> __second)
      : pair(__first, __second,
      typename _Build_index_tuple<sizeof...(_Args1)>::__type(),
      typename _Build_index_tuple<sizeof...(_Args2)>::__type())
      { }

  template<class _T1, class _T2>
    template<typename... _Args1, std::size_t... _Indexes1,
             typename... _Args2, std::size_t... _Indexes2>
      inline
      pair<_T1, _T2>::
      pair(tuple<_Args1...>& __tuple1, tuple<_Args2...>& __tuple2,
    _Index_tuple<_Indexes1...>, _Index_tuple<_Indexes2...>)
      : first(std::forward<_Args1>(std::get<_Indexes1>(__tuple1))...),
        second(std::forward<_Args2>(std::get<_Indexes2>(__tuple2))...)
      { }
# 1718 "/usr/include/c++/9.2.0/tuple" 3

}
# 35 "/usr/include/c++/9.2.0/bits/hashtable_policy.h" 2 3
# 1 "/usr/include/c++/9.2.0/limits" 1 3
# 40 "/usr/include/c++/9.2.0/limits" 3
       
# 41 "/usr/include/c++/9.2.0/limits" 3
# 158 "/usr/include/c++/9.2.0/limits" 3
namespace std __attribute__ ((__visibility__ ("default")))
{







  enum float_round_style
  {
    round_indeterminate = -1,
    round_toward_zero = 0,
    round_to_nearest = 1,
    round_toward_infinity = 2,
    round_toward_neg_infinity = 3
  };







  enum float_denorm_style
  {

    denorm_indeterminate = -1,

    denorm_absent = 0,

    denorm_present = 1
  };
# 202 "/usr/include/c++/9.2.0/limits" 3
  struct __numeric_limits_base
  {


    static constexpr bool is_specialized = false;




    static constexpr int digits = 0;


    static constexpr int digits10 = 0;




    static constexpr int max_digits10 = 0;



    static constexpr bool is_signed = false;


    static constexpr bool is_integer = false;




    static constexpr bool is_exact = false;



    static constexpr int radix = 0;



    static constexpr int min_exponent = 0;



    static constexpr int min_exponent10 = 0;




    static constexpr int max_exponent = 0;



    static constexpr int max_exponent10 = 0;


    static constexpr bool has_infinity = false;



    static constexpr bool has_quiet_NaN = false;



    static constexpr bool has_signaling_NaN = false;


    static constexpr float_denorm_style has_denorm = denorm_absent;



    static constexpr bool has_denorm_loss = false;



    static constexpr bool is_iec559 = false;




    static constexpr bool is_bounded = false;
# 288 "/usr/include/c++/9.2.0/limits" 3
    static constexpr bool is_modulo = false;


    static constexpr bool traps = false;


    static constexpr bool tinyness_before = false;




    static constexpr float_round_style round_style =
          round_toward_zero;
  };
# 311 "/usr/include/c++/9.2.0/limits" 3
  template<typename _Tp>
    struct numeric_limits : public __numeric_limits_base
    {


      static constexpr _Tp
      min() noexcept { return _Tp(); }


      static constexpr _Tp
      max() noexcept { return _Tp(); }




      static constexpr _Tp
      lowest() noexcept { return _Tp(); }




      static constexpr _Tp
      epsilon() noexcept { return _Tp(); }


      static constexpr _Tp
      round_error() noexcept { return _Tp(); }


      static constexpr _Tp
      infinity() noexcept { return _Tp(); }



      static constexpr _Tp
      quiet_NaN() noexcept { return _Tp(); }



      static constexpr _Tp
      signaling_NaN() noexcept { return _Tp(); }




      static constexpr _Tp
      denorm_min() noexcept { return _Tp(); }
    };




  template<typename _Tp>
    struct numeric_limits<const _Tp>
    : public numeric_limits<_Tp> { };

  template<typename _Tp>
    struct numeric_limits<volatile _Tp>
    : public numeric_limits<_Tp> { };

  template<typename _Tp>
    struct numeric_limits<const volatile _Tp>
    : public numeric_limits<_Tp> { };
# 383 "/usr/include/c++/9.2.0/limits" 3
  template<>
    struct numeric_limits<bool>
    {
      static constexpr bool is_specialized = true;

      static constexpr bool
      min() noexcept { return false; }

      static constexpr bool
      max() noexcept { return true; }


      static constexpr bool
      lowest() noexcept { return min(); }

      static constexpr int digits = 1;
      static constexpr int digits10 = 0;

      static constexpr int max_digits10 = 0;

      static constexpr bool is_signed = false;
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr bool
      epsilon() noexcept { return false; }

      static constexpr bool
      round_error() noexcept { return false; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm
       = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr bool
      infinity() noexcept { return false; }

      static constexpr bool
      quiet_NaN() noexcept { return false; }

      static constexpr bool
      signaling_NaN() noexcept { return false; }

      static constexpr bool
      denorm_min() noexcept { return false; }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = false;




      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style
       = round_toward_zero;
    };


  template<>
    struct numeric_limits<char>
    {
      static constexpr bool is_specialized = true;

      static constexpr char
      min() noexcept { return (((char)(-1) < 0) ? -(((char)(-1) < 0) ? (((((char)1 << ((sizeof(char) * 8 - ((char)(-1) < 0)) - 1)) - 1) << 1) + 1) : ~(char)0) - 1 : (char)0); }

      static constexpr char
      max() noexcept { return (((char)(-1) < 0) ? (((((char)1 << ((sizeof(char) * 8 - ((char)(-1) < 0)) - 1)) - 1) << 1) + 1) : ~(char)0); }


      static constexpr char
      lowest() noexcept { return min(); }


      static constexpr int digits = (sizeof(char) * 8 - ((char)(-1) < 0));
      static constexpr int digits10 = ((sizeof(char) * 8 - ((char)(-1) < 0)) * 643L / 2136);

      static constexpr int max_digits10 = 0;

      static constexpr bool is_signed = ((char)(-1) < 0);
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr char
      epsilon() noexcept { return 0; }

      static constexpr char
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm
       = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr
      char infinity() noexcept { return char(); }

      static constexpr char
      quiet_NaN() noexcept { return char(); }

      static constexpr char
      signaling_NaN() noexcept { return char(); }

      static constexpr char
      denorm_min() noexcept { return static_cast<char>(0); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = !is_signed;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style
       = round_toward_zero;
    };


  template<>
    struct numeric_limits<signed char>
    {
      static constexpr bool is_specialized = true;

      static constexpr signed char
      min() noexcept { return -0x7f - 1; }

      static constexpr signed char
      max() noexcept { return 0x7f; }


      static constexpr signed char
      lowest() noexcept { return min(); }


      static constexpr int digits = (sizeof(signed char) * 8 - ((signed char)(-1) < 0));
      static constexpr int digits10
       = ((sizeof(signed char) * 8 - ((signed char)(-1) < 0)) * 643L / 2136);

      static constexpr int max_digits10 = 0;

      static constexpr bool is_signed = true;
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr signed char
      epsilon() noexcept { return 0; }

      static constexpr signed char
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm
       = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr signed char
      infinity() noexcept { return static_cast<signed char>(0); }

      static constexpr signed char
      quiet_NaN() noexcept { return static_cast<signed char>(0); }

      static constexpr signed char
      signaling_NaN() noexcept
      { return static_cast<signed char>(0); }

      static constexpr signed char
      denorm_min() noexcept
      { return static_cast<signed char>(0); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = false;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style
       = round_toward_zero;
    };


  template<>
    struct numeric_limits<unsigned char>
    {
      static constexpr bool is_specialized = true;

      static constexpr unsigned char
      min() noexcept { return 0; }

      static constexpr unsigned char
      max() noexcept { return 0x7f * 2U + 1; }


      static constexpr unsigned char
      lowest() noexcept { return min(); }


      static constexpr int digits
       = (sizeof(unsigned char) * 8 - ((unsigned char)(-1) < 0));
      static constexpr int digits10
       = ((sizeof(unsigned char) * 8 - ((unsigned char)(-1) < 0)) * 643L / 2136);

      static constexpr int max_digits10 = 0;

      static constexpr bool is_signed = false;
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr unsigned char
      epsilon() noexcept { return 0; }

      static constexpr unsigned char
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm
       = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr unsigned char
      infinity() noexcept
      { return static_cast<unsigned char>(0); }

      static constexpr unsigned char
      quiet_NaN() noexcept
      { return static_cast<unsigned char>(0); }

      static constexpr unsigned char
      signaling_NaN() noexcept
      { return static_cast<unsigned char>(0); }

      static constexpr unsigned char
      denorm_min() noexcept
      { return static_cast<unsigned char>(0); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = true;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style
       = round_toward_zero;
    };


  template<>
    struct numeric_limits<wchar_t>
    {
      static constexpr bool is_specialized = true;

      static constexpr wchar_t
      min() noexcept { return (((wchar_t)(-1) < 0) ? -(((wchar_t)(-1) < 0) ? (((((wchar_t)1 << ((sizeof(wchar_t) * 8 - ((wchar_t)(-1) < 0)) - 1)) - 1) << 1) + 1) : ~(wchar_t)0) - 1 : (wchar_t)0); }

      static constexpr wchar_t
      max() noexcept { return (((wchar_t)(-1) < 0) ? (((((wchar_t)1 << ((sizeof(wchar_t) * 8 - ((wchar_t)(-1) < 0)) - 1)) - 1) << 1) + 1) : ~(wchar_t)0); }


      static constexpr wchar_t
      lowest() noexcept { return min(); }


      static constexpr int digits = (sizeof(wchar_t) * 8 - ((wchar_t)(-1) < 0));
      static constexpr int digits10
       = ((sizeof(wchar_t) * 8 - ((wchar_t)(-1) < 0)) * 643L / 2136);

      static constexpr int max_digits10 = 0;

      static constexpr bool is_signed = ((wchar_t)(-1) < 0);
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr wchar_t
      epsilon() noexcept { return 0; }

      static constexpr wchar_t
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm
       = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr wchar_t
      infinity() noexcept { return wchar_t(); }

      static constexpr wchar_t
      quiet_NaN() noexcept { return wchar_t(); }

      static constexpr wchar_t
      signaling_NaN() noexcept { return wchar_t(); }

      static constexpr wchar_t
      denorm_min() noexcept { return wchar_t(); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = !is_signed;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style
       = round_toward_zero;
    };
# 796 "/usr/include/c++/9.2.0/limits" 3
  template<>
    struct numeric_limits<char16_t>
    {
      static constexpr bool is_specialized = true;

      static constexpr char16_t
      min() noexcept { return (((char16_t)(-1) < 0) ? -(((char16_t)(-1) < 0) ? (((((char16_t)1 << ((sizeof(char16_t) * 8 - ((char16_t)(-1) < 0)) - 1)) - 1) << 1) + 1) : ~(char16_t)0) - 1 : (char16_t)0); }

      static constexpr char16_t
      max() noexcept { return (((char16_t)(-1) < 0) ? (((((char16_t)1 << ((sizeof(char16_t) * 8 - ((char16_t)(-1) < 0)) - 1)) - 1) << 1) + 1) : ~(char16_t)0); }

      static constexpr char16_t
      lowest() noexcept { return min(); }

      static constexpr int digits = (sizeof(char16_t) * 8 - ((char16_t)(-1) < 0));
      static constexpr int digits10 = ((sizeof(char16_t) * 8 - ((char16_t)(-1) < 0)) * 643L / 2136);
      static constexpr int max_digits10 = 0;
      static constexpr bool is_signed = ((char16_t)(-1) < 0);
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr char16_t
      epsilon() noexcept { return 0; }

      static constexpr char16_t
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr char16_t
      infinity() noexcept { return char16_t(); }

      static constexpr char16_t
      quiet_NaN() noexcept { return char16_t(); }

      static constexpr char16_t
      signaling_NaN() noexcept { return char16_t(); }

      static constexpr char16_t
      denorm_min() noexcept { return char16_t(); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = !is_signed;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style = round_toward_zero;
    };


  template<>
    struct numeric_limits<char32_t>
    {
      static constexpr bool is_specialized = true;

      static constexpr char32_t
      min() noexcept { return (((char32_t)(-1) < 0) ? -(((char32_t)(-1) < 0) ? (((((char32_t)1 << ((sizeof(char32_t) * 8 - ((char32_t)(-1) < 0)) - 1)) - 1) << 1) + 1) : ~(char32_t)0) - 1 : (char32_t)0); }

      static constexpr char32_t
      max() noexcept { return (((char32_t)(-1) < 0) ? (((((char32_t)1 << ((sizeof(char32_t) * 8 - ((char32_t)(-1) < 0)) - 1)) - 1) << 1) + 1) : ~(char32_t)0); }

      static constexpr char32_t
      lowest() noexcept { return min(); }

      static constexpr int digits = (sizeof(char32_t) * 8 - ((char32_t)(-1) < 0));
      static constexpr int digits10 = ((sizeof(char32_t) * 8 - ((char32_t)(-1) < 0)) * 643L / 2136);
      static constexpr int max_digits10 = 0;
      static constexpr bool is_signed = ((char32_t)(-1) < 0);
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr char32_t
      epsilon() noexcept { return 0; }

      static constexpr char32_t
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr char32_t
      infinity() noexcept { return char32_t(); }

      static constexpr char32_t
      quiet_NaN() noexcept { return char32_t(); }

      static constexpr char32_t
      signaling_NaN() noexcept { return char32_t(); }

      static constexpr char32_t
      denorm_min() noexcept { return char32_t(); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = !is_signed;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style = round_toward_zero;
    };



  template<>
    struct numeric_limits<short>
    {
      static constexpr bool is_specialized = true;

      static constexpr short
      min() noexcept { return -0x7fff - 1; }

      static constexpr short
      max() noexcept { return 0x7fff; }


      static constexpr short
      lowest() noexcept { return min(); }


      static constexpr int digits = (sizeof(short) * 8 - ((short)(-1) < 0));
      static constexpr int digits10 = ((sizeof(short) * 8 - ((short)(-1) < 0)) * 643L / 2136);

      static constexpr int max_digits10 = 0;

      static constexpr bool is_signed = true;
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr short
      epsilon() noexcept { return 0; }

      static constexpr short
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm
       = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr short
      infinity() noexcept { return short(); }

      static constexpr short
      quiet_NaN() noexcept { return short(); }

      static constexpr short
      signaling_NaN() noexcept { return short(); }

      static constexpr short
      denorm_min() noexcept { return short(); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = false;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style
       = round_toward_zero;
    };


  template<>
    struct numeric_limits<unsigned short>
    {
      static constexpr bool is_specialized = true;

      static constexpr unsigned short
      min() noexcept { return 0; }

      static constexpr unsigned short
      max() noexcept { return 0x7fff * 2U + 1; }


      static constexpr unsigned short
      lowest() noexcept { return min(); }


      static constexpr int digits
       = (sizeof(unsigned short) * 8 - ((unsigned short)(-1) < 0));
      static constexpr int digits10
       = ((sizeof(unsigned short) * 8 - ((unsigned short)(-1) < 0)) * 643L / 2136);

      static constexpr int max_digits10 = 0;

      static constexpr bool is_signed = false;
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr unsigned short
      epsilon() noexcept { return 0; }

      static constexpr unsigned short
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm
       = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr unsigned short
      infinity() noexcept
      { return static_cast<unsigned short>(0); }

      static constexpr unsigned short
      quiet_NaN() noexcept
      { return static_cast<unsigned short>(0); }

      static constexpr unsigned short
      signaling_NaN() noexcept
      { return static_cast<unsigned short>(0); }

      static constexpr unsigned short
      denorm_min() noexcept
      { return static_cast<unsigned short>(0); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = true;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style
       = round_toward_zero;
    };


  template<>
    struct numeric_limits<int>
    {
      static constexpr bool is_specialized = true;

      static constexpr int
      min() noexcept { return -0x7fffffff - 1; }

      static constexpr int
      max() noexcept { return 0x7fffffff; }


      static constexpr int
      lowest() noexcept { return min(); }


      static constexpr int digits = (sizeof(int) * 8 - ((int)(-1) < 0));
      static constexpr int digits10 = ((sizeof(int) * 8 - ((int)(-1) < 0)) * 643L / 2136);

      static constexpr int max_digits10 = 0;

      static constexpr bool is_signed = true;
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr int
      epsilon() noexcept { return 0; }

      static constexpr int
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm
       = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr int
      infinity() noexcept { return static_cast<int>(0); }

      static constexpr int
      quiet_NaN() noexcept { return static_cast<int>(0); }

      static constexpr int
      signaling_NaN() noexcept { return static_cast<int>(0); }

      static constexpr int
      denorm_min() noexcept { return static_cast<int>(0); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = false;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style
       = round_toward_zero;
    };


  template<>
    struct numeric_limits<unsigned int>
    {
      static constexpr bool is_specialized = true;

      static constexpr unsigned int
      min() noexcept { return 0; }

      static constexpr unsigned int
      max() noexcept { return 0x7fffffff * 2U + 1; }


      static constexpr unsigned int
      lowest() noexcept { return min(); }


      static constexpr int digits
       = (sizeof(unsigned int) * 8 - ((unsigned int)(-1) < 0));
      static constexpr int digits10
       = ((sizeof(unsigned int) * 8 - ((unsigned int)(-1) < 0)) * 643L / 2136);

      static constexpr int max_digits10 = 0;

      static constexpr bool is_signed = false;
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr unsigned int
      epsilon() noexcept { return 0; }

      static constexpr unsigned int
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm
       = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr unsigned int
      infinity() noexcept { return static_cast<unsigned int>(0); }

      static constexpr unsigned int
      quiet_NaN() noexcept
      { return static_cast<unsigned int>(0); }

      static constexpr unsigned int
      signaling_NaN() noexcept
      { return static_cast<unsigned int>(0); }

      static constexpr unsigned int
      denorm_min() noexcept
      { return static_cast<unsigned int>(0); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = true;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style
       = round_toward_zero;
    };


  template<>
    struct numeric_limits<long>
    {
      static constexpr bool is_specialized = true;

      static constexpr long
      min() noexcept { return -0x7fffffffffffffffL - 1; }

      static constexpr long
      max() noexcept { return 0x7fffffffffffffffL; }


      static constexpr long
      lowest() noexcept { return min(); }


      static constexpr int digits = (sizeof(long) * 8 - ((long)(-1) < 0));
      static constexpr int digits10 = ((sizeof(long) * 8 - ((long)(-1) < 0)) * 643L / 2136);

      static constexpr int max_digits10 = 0;

      static constexpr bool is_signed = true;
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr long
      epsilon() noexcept { return 0; }

      static constexpr long
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm
       = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr long
      infinity() noexcept { return static_cast<long>(0); }

      static constexpr long
      quiet_NaN() noexcept { return static_cast<long>(0); }

      static constexpr long
      signaling_NaN() noexcept { return static_cast<long>(0); }

      static constexpr long
      denorm_min() noexcept { return static_cast<long>(0); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = false;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style
       = round_toward_zero;
    };


  template<>
    struct numeric_limits<unsigned long>
    {
      static constexpr bool is_specialized = true;

      static constexpr unsigned long
      min() noexcept { return 0; }

      static constexpr unsigned long
      max() noexcept { return 0x7fffffffffffffffL * 2UL + 1; }


      static constexpr unsigned long
      lowest() noexcept { return min(); }


      static constexpr int digits
       = (sizeof(unsigned long) * 8 - ((unsigned long)(-1) < 0));
      static constexpr int digits10
       = ((sizeof(unsigned long) * 8 - ((unsigned long)(-1) < 0)) * 643L / 2136);

      static constexpr int max_digits10 = 0;

      static constexpr bool is_signed = false;
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr unsigned long
      epsilon() noexcept { return 0; }

      static constexpr unsigned long
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm
       = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr unsigned long
      infinity() noexcept
      { return static_cast<unsigned long>(0); }

      static constexpr unsigned long
      quiet_NaN() noexcept
      { return static_cast<unsigned long>(0); }

      static constexpr unsigned long
      signaling_NaN() noexcept
      { return static_cast<unsigned long>(0); }

      static constexpr unsigned long
      denorm_min() noexcept
      { return static_cast<unsigned long>(0); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = true;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style
       = round_toward_zero;
    };


  template<>
    struct numeric_limits<long long>
    {
      static constexpr bool is_specialized = true;

      static constexpr long long
      min() noexcept { return -0x7fffffffffffffffLL - 1; }

      static constexpr long long
      max() noexcept { return 0x7fffffffffffffffLL; }


      static constexpr long long
      lowest() noexcept { return min(); }


      static constexpr int digits
       = (sizeof(long long) * 8 - ((long long)(-1) < 0));
      static constexpr int digits10
       = ((sizeof(long long) * 8 - ((long long)(-1) < 0)) * 643L / 2136);

      static constexpr int max_digits10 = 0;

      static constexpr bool is_signed = true;
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr long long
      epsilon() noexcept { return 0; }

      static constexpr long long
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm
       = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr long long
      infinity() noexcept { return static_cast<long long>(0); }

      static constexpr long long
      quiet_NaN() noexcept { return static_cast<long long>(0); }

      static constexpr long long
      signaling_NaN() noexcept
      { return static_cast<long long>(0); }

      static constexpr long long
      denorm_min() noexcept { return static_cast<long long>(0); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = false;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style
       = round_toward_zero;
    };


  template<>
    struct numeric_limits<unsigned long long>
    {
      static constexpr bool is_specialized = true;

      static constexpr unsigned long long
      min() noexcept { return 0; }

      static constexpr unsigned long long
      max() noexcept { return 0x7fffffffffffffffLL * 2ULL + 1; }


      static constexpr unsigned long long
      lowest() noexcept { return min(); }


      static constexpr int digits
       = (sizeof(unsigned long long) * 8 - ((unsigned long long)(-1) < 0));
      static constexpr int digits10
       = ((sizeof(unsigned long long) * 8 - ((unsigned long long)(-1) < 0)) * 643L / 2136);

      static constexpr int max_digits10 = 0;

      static constexpr bool is_signed = false;
      static constexpr bool is_integer = true;
      static constexpr bool is_exact = true;
      static constexpr int radix = 2;

      static constexpr unsigned long long
      epsilon() noexcept { return 0; }

      static constexpr unsigned long long
      round_error() noexcept { return 0; }

      static constexpr int min_exponent = 0;
      static constexpr int min_exponent10 = 0;
      static constexpr int max_exponent = 0;
      static constexpr int max_exponent10 = 0;

      static constexpr bool has_infinity = false;
      static constexpr bool has_quiet_NaN = false;
      static constexpr bool has_signaling_NaN = false;
      static constexpr float_denorm_style has_denorm
       = denorm_absent;
      static constexpr bool has_denorm_loss = false;

      static constexpr unsigned long long
      infinity() noexcept
      { return static_cast<unsigned long long>(0); }

      static constexpr unsigned long long
      quiet_NaN() noexcept
      { return static_cast<unsigned long long>(0); }

      static constexpr unsigned long long
      signaling_NaN() noexcept
      { return static_cast<unsigned long long>(0); }

      static constexpr unsigned long long
      denorm_min() noexcept
      { return static_cast<unsigned long long>(0); }

      static constexpr bool is_iec559 = false;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = true;

      static constexpr bool traps = true;
      static constexpr bool tinyness_before = false;
      static constexpr float_round_style round_style
       = round_toward_zero;
    };
# 1636 "/usr/include/c++/9.2.0/limits" 3
  template<> struct numeric_limits<__int128> { static constexpr bool is_specialized = true; static constexpr __int128 min() noexcept { return (((__int128)(-1) < 0) ? -(((__int128)(-1) < 0) ? (((((__int128)1 << ((128 - ((__int128)(-1) < 0)) - 1)) - 1) << 1) + 1) : ~(__int128)0) - 1 : (__int128)0); } static constexpr __int128 max() noexcept { return (((__int128)(-1) < 0) ? (((((__int128)1 << ((128 - ((__int128)(-1) < 0)) - 1)) - 1) << 1) + 1) : ~(__int128)0); } static constexpr int digits = 128 - 1; static constexpr int digits10 = (128 - 1) * 643L / 2136; static constexpr bool is_signed = true; static constexpr bool is_integer = true; static constexpr bool is_exact = true; static constexpr int radix = 2; static constexpr __int128 epsilon() noexcept { return 0; } static constexpr __int128 round_error() noexcept { return 0; } static constexpr __int128 lowest() noexcept { return min(); } static constexpr int max_digits10 = 0; static constexpr int min_exponent = 0; static constexpr int min_exponent10 = 0; static constexpr int max_exponent = 0; static constexpr int max_exponent10 = 0; static constexpr bool has_infinity = false; static constexpr bool has_quiet_NaN = false; static constexpr bool has_signaling_NaN = false; static constexpr float_denorm_style has_denorm = denorm_absent; static constexpr bool has_denorm_loss = false; static constexpr __int128 infinity() noexcept { return static_cast<__int128>(0); } static constexpr __int128 quiet_NaN() noexcept { return static_cast<__int128>(0); } static constexpr __int128 signaling_NaN() noexcept { return static_cast<__int128>(0); } static constexpr __int128 denorm_min() noexcept { return static_cast<__int128>(0); } static constexpr bool is_iec559 = false; static constexpr bool is_bounded = true; static constexpr bool is_modulo = false; static constexpr bool traps = true; static constexpr bool tinyness_before = false; static constexpr float_round_style round_style = round_toward_zero; }; template<> struct numeric_limits<unsigned __int128> { static constexpr bool is_specialized = true; static constexpr unsigned __int128 min() noexcept { return 0; } static constexpr unsigned __int128 max() noexcept { return (((unsigned __int128)(-1) < 0) ? (((((unsigned __int128)1 << ((128 - ((unsigned __int128)(-1) < 0)) - 1)) - 1) << 1) + 1) : ~(unsigned __int128)0); } static constexpr unsigned __int128 lowest() noexcept { return min(); } static constexpr int max_digits10 = 0; static constexpr int digits = 128; static constexpr int digits10 = 128 * 643L / 2136; static constexpr bool is_signed = false; static constexpr bool is_integer = true; static constexpr bool is_exact = true; static constexpr int radix = 2; static constexpr unsigned __int128 epsilon() noexcept { return 0; } static constexpr unsigned __int128 round_error() noexcept { return 0; } static constexpr int min_exponent = 0; static constexpr int min_exponent10 = 0; static constexpr int max_exponent = 0; static constexpr int max_exponent10 = 0; static constexpr bool has_infinity = false; static constexpr bool has_quiet_NaN = false; static constexpr bool has_signaling_NaN = false; static constexpr float_denorm_style has_denorm = denorm_absent; static constexpr bool has_denorm_loss = false; static constexpr unsigned __int128 infinity() noexcept { return static_cast<unsigned __int128>(0); } static constexpr unsigned __int128 quiet_NaN() noexcept { return static_cast<unsigned __int128>(0); } static constexpr unsigned __int128 signaling_NaN() noexcept { return static_cast<unsigned __int128>(0); } static constexpr unsigned __int128 denorm_min() noexcept { return static_cast<unsigned __int128>(0); } static constexpr bool is_iec559 = false; static constexpr bool is_bounded = true; static constexpr bool is_modulo = true; static constexpr bool traps = true; static constexpr bool tinyness_before = false; static constexpr float_round_style round_style = round_toward_zero; };
# 1659 "/usr/include/c++/9.2.0/limits" 3
  template<>
    struct numeric_limits<float>
    {
      static constexpr bool is_specialized = true;

      static constexpr float
      min() noexcept { return 1.17549435082228750796873653722224568e-38F; }

      static constexpr float
      max() noexcept { return 3.40282346638528859811704183484516925e+38F; }


      static constexpr float
      lowest() noexcept { return -3.40282346638528859811704183484516925e+38F; }


      static constexpr int digits = 24;
      static constexpr int digits10 = 6;

      static constexpr int max_digits10
  = (2 + (24) * 643L / 2136);

      static constexpr bool is_signed = true;
      static constexpr bool is_integer = false;
      static constexpr bool is_exact = false;
      static constexpr int radix = 2;

      static constexpr float
      epsilon() noexcept { return 1.19209289550781250000000000000000000e-7F; }

      static constexpr float
      round_error() noexcept { return 0.5F; }

      static constexpr int min_exponent = (-125);
      static constexpr int min_exponent10 = (-37);
      static constexpr int max_exponent = 128;
      static constexpr int max_exponent10 = 38;

      static constexpr bool has_infinity = 1;
      static constexpr bool has_quiet_NaN = 1;
      static constexpr bool has_signaling_NaN = has_quiet_NaN;
      static constexpr float_denorm_style has_denorm
 = bool(1) ? denorm_present : denorm_absent;
      static constexpr bool has_denorm_loss
       = false;

      static constexpr float
      infinity() noexcept { return __builtin_huge_valf(); }

      static constexpr float
      quiet_NaN() noexcept { return __builtin_nanf(""); }

      static constexpr float
      signaling_NaN() noexcept { return __builtin_nansf(""); }

      static constexpr float
      denorm_min() noexcept { return 1.40129846432481707092372958328991613e-45F; }

      static constexpr bool is_iec559
 = has_infinity && has_quiet_NaN && has_denorm == denorm_present;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = false;

      static constexpr bool traps = false;
      static constexpr bool tinyness_before
       = false;
      static constexpr float_round_style round_style
       = round_to_nearest;
    };






  template<>
    struct numeric_limits<double>
    {
      static constexpr bool is_specialized = true;

      static constexpr double
      min() noexcept { return double(2.22507385850720138309023271733240406e-308L); }

      static constexpr double
      max() noexcept { return double(1.79769313486231570814527423731704357e+308L); }


      static constexpr double
      lowest() noexcept { return -double(1.79769313486231570814527423731704357e+308L); }


      static constexpr int digits = 53;
      static constexpr int digits10 = 15;

      static constexpr int max_digits10
  = (2 + (53) * 643L / 2136);

      static constexpr bool is_signed = true;
      static constexpr bool is_integer = false;
      static constexpr bool is_exact = false;
      static constexpr int radix = 2;

      static constexpr double
      epsilon() noexcept { return double(2.22044604925031308084726333618164062e-16L); }

      static constexpr double
      round_error() noexcept { return 0.5; }

      static constexpr int min_exponent = (-1021);
      static constexpr int min_exponent10 = (-307);
      static constexpr int max_exponent = 1024;
      static constexpr int max_exponent10 = 308;

      static constexpr bool has_infinity = 1;
      static constexpr bool has_quiet_NaN = 1;
      static constexpr bool has_signaling_NaN = has_quiet_NaN;
      static constexpr float_denorm_style has_denorm
 = bool(1) ? denorm_present : denorm_absent;
      static constexpr bool has_denorm_loss
        = false;

      static constexpr double
      infinity() noexcept { return __builtin_huge_val(); }

      static constexpr double
      quiet_NaN() noexcept { return __builtin_nan(""); }

      static constexpr double
      signaling_NaN() noexcept { return __builtin_nans(""); }

      static constexpr double
      denorm_min() noexcept { return double(4.94065645841246544176568792868221372e-324L); }

      static constexpr bool is_iec559
 = has_infinity && has_quiet_NaN && has_denorm == denorm_present;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = false;

      static constexpr bool traps = false;
      static constexpr bool tinyness_before
       = false;
      static constexpr float_round_style round_style
       = round_to_nearest;
    };






  template<>
    struct numeric_limits<long double>
    {
      static constexpr bool is_specialized = true;

      static constexpr long double
      min() noexcept { return 3.36210314311209350626267781732175260e-4932L; }

      static constexpr long double
      max() noexcept { return 1.18973149535723176502126385303097021e+4932L; }


      static constexpr long double
      lowest() noexcept { return -1.18973149535723176502126385303097021e+4932L; }


      static constexpr int digits = 64;
      static constexpr int digits10 = 18;

      static constexpr int max_digits10
  = (2 + (64) * 643L / 2136);

      static constexpr bool is_signed = true;
      static constexpr bool is_integer = false;
      static constexpr bool is_exact = false;
      static constexpr int radix = 2;

      static constexpr long double
      epsilon() noexcept { return 1.08420217248550443400745280086994171e-19L; }

      static constexpr long double
      round_error() noexcept { return 0.5L; }

      static constexpr int min_exponent = (-16381);
      static constexpr int min_exponent10 = (-4931);
      static constexpr int max_exponent = 16384;
      static constexpr int max_exponent10 = 4932;

      static constexpr bool has_infinity = 1;
      static constexpr bool has_quiet_NaN = 1;
      static constexpr bool has_signaling_NaN = has_quiet_NaN;
      static constexpr float_denorm_style has_denorm
 = bool(1) ? denorm_present : denorm_absent;
      static constexpr bool has_denorm_loss
 = false;

      static constexpr long double
      infinity() noexcept { return __builtin_huge_vall(); }

      static constexpr long double
      quiet_NaN() noexcept { return __builtin_nanl(""); }

      static constexpr long double
      signaling_NaN() noexcept { return __builtin_nansl(""); }

      static constexpr long double
      denorm_min() noexcept { return 3.64519953188247460252840593361941982e-4951L; }

      static constexpr bool is_iec559
 = has_infinity && has_quiet_NaN && has_denorm == denorm_present;
      static constexpr bool is_bounded = true;
      static constexpr bool is_modulo = false;

      static constexpr bool traps = false;
      static constexpr bool tinyness_before =
      false;
      static constexpr float_round_style round_style =
            round_to_nearest;
    };






}
# 36 "/usr/include/c++/9.2.0/bits/hashtable_policy.h" 2 3


namespace std __attribute__ ((__visibility__ ("default")))
{


  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    class _Hashtable;

namespace __detail
{





  template<typename _Key, typename _Value,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _Traits>
    struct _Hashtable_base;



  template<class _Iterator>
    inline typename std::iterator_traits<_Iterator>::difference_type
    __distance_fw(_Iterator __first, _Iterator __last,
    std::input_iterator_tag)
    { return __first != __last ? 1 : 0; }

  template<class _Iterator>
    inline typename std::iterator_traits<_Iterator>::difference_type
    __distance_fw(_Iterator __first, _Iterator __last,
    std::forward_iterator_tag)
    { return std::distance(__first, __last); }

  template<class _Iterator>
    inline typename std::iterator_traits<_Iterator>::difference_type
    __distance_fw(_Iterator __first, _Iterator __last)
    { return __distance_fw(__first, __last,
      std::__iterator_category(__first)); }

  struct _Identity
  {
    template<typename _Tp>
      _Tp&&
      operator()(_Tp&& __x) const
      { return std::forward<_Tp>(__x); }
  };

  struct _Select1st
  {
    template<typename _Tp>
      auto
      operator()(_Tp&& __x) const
      -> decltype(std::get<0>(std::forward<_Tp>(__x)))
      { return std::get<0>(std::forward<_Tp>(__x)); }
  };

  template<typename _NodeAlloc>
    struct _Hashtable_alloc;



  template<typename _NodeAlloc>
    struct _ReuseOrAllocNode
    {
    private:
      using __node_alloc_type = _NodeAlloc;
      using __hashtable_alloc = _Hashtable_alloc<__node_alloc_type>;
      using __node_alloc_traits =
 typename __hashtable_alloc::__node_alloc_traits;
      using __node_type = typename __hashtable_alloc::__node_type;

    public:
      _ReuseOrAllocNode(__node_type* __nodes, __hashtable_alloc& __h)
 : _M_nodes(__nodes), _M_h(__h) { }
      _ReuseOrAllocNode(const _ReuseOrAllocNode&) = delete;

      ~_ReuseOrAllocNode()
      { _M_h._M_deallocate_nodes(_M_nodes); }

      template<typename _Arg>
 __node_type*
 operator()(_Arg&& __arg) const
 {
   if (_M_nodes)
     {
       __node_type* __node = _M_nodes;
       _M_nodes = _M_nodes->_M_next();
       __node->_M_nxt = nullptr;
       auto& __a = _M_h._M_node_allocator();
       __node_alloc_traits::destroy(__a, __node->_M_valptr());
       try
  {
    __node_alloc_traits::construct(__a, __node->_M_valptr(),
       std::forward<_Arg>(__arg));
  }
       catch(...)
  {
    _M_h._M_deallocate_node_ptr(__node);
    throw;
  }
       return __node;
     }
   return _M_h._M_allocate_node(std::forward<_Arg>(__arg));
 }

    private:
      mutable __node_type* _M_nodes;
      __hashtable_alloc& _M_h;
    };



  template<typename _NodeAlloc>
    struct _AllocNode
    {
    private:
      using __hashtable_alloc = _Hashtable_alloc<_NodeAlloc>;
      using __node_type = typename __hashtable_alloc::__node_type;

    public:
      _AllocNode(__hashtable_alloc& __h)
 : _M_h(__h) { }

      template<typename _Arg>
 __node_type*
 operator()(_Arg&& __arg) const
 { return _M_h._M_allocate_node(std::forward<_Arg>(__arg)); }

    private:
      __hashtable_alloc& _M_h;
    };
# 198 "/usr/include/c++/9.2.0/bits/hashtable_policy.h" 3
  template<bool _Cache_hash_code, bool _Constant_iterators, bool _Unique_keys>
    struct _Hashtable_traits
    {
      using __hash_cached = __bool_constant<_Cache_hash_code>;
      using __constant_iterators = __bool_constant<_Constant_iterators>;
      using __unique_keys = __bool_constant<_Unique_keys>;
    };
# 214 "/usr/include/c++/9.2.0/bits/hashtable_policy.h" 3
  struct _Hash_node_base
  {
    _Hash_node_base* _M_nxt;

    _Hash_node_base() noexcept : _M_nxt() { }

    _Hash_node_base(_Hash_node_base* __next) noexcept : _M_nxt(__next) { }
  };






  template<typename _Value>
    struct _Hash_node_value_base : _Hash_node_base
    {
      typedef _Value value_type;

      __gnu_cxx::__aligned_buffer<_Value> _M_storage;

      _Value*
      _M_valptr() noexcept
      { return _M_storage._M_ptr(); }

      const _Value*
      _M_valptr() const noexcept
      { return _M_storage._M_ptr(); }

      _Value&
      _M_v() noexcept
      { return *_M_valptr(); }

      const _Value&
      _M_v() const noexcept
      { return *_M_valptr(); }
    };




  template<typename _Value, bool _Cache_hash_code>
    struct _Hash_node;






  template<typename _Value>
    struct _Hash_node<_Value, true> : _Hash_node_value_base<_Value>
    {
      std::size_t _M_hash_code;

      _Hash_node*
      _M_next() const noexcept
      { return static_cast<_Hash_node*>(this->_M_nxt); }
    };






  template<typename _Value>
    struct _Hash_node<_Value, false> : _Hash_node_value_base<_Value>
    {
      _Hash_node*
      _M_next() const noexcept
      { return static_cast<_Hash_node*>(this->_M_nxt); }
    };


  template<typename _Value, bool _Cache_hash_code>
    struct _Node_iterator_base
    {
      using __node_type = _Hash_node<_Value, _Cache_hash_code>;

      __node_type* _M_cur;

      _Node_iterator_base(__node_type* __p) noexcept
      : _M_cur(__p) { }

      void
      _M_incr() noexcept
      { _M_cur = _M_cur->_M_next(); }
    };

  template<typename _Value, bool _Cache_hash_code>
    inline bool
    operator==(const _Node_iterator_base<_Value, _Cache_hash_code>& __x,
        const _Node_iterator_base<_Value, _Cache_hash_code >& __y)
    noexcept
    { return __x._M_cur == __y._M_cur; }

  template<typename _Value, bool _Cache_hash_code>
    inline bool
    operator!=(const _Node_iterator_base<_Value, _Cache_hash_code>& __x,
        const _Node_iterator_base<_Value, _Cache_hash_code>& __y)
    noexcept
    { return __x._M_cur != __y._M_cur; }


  template<typename _Value, bool __constant_iterators, bool __cache>
    struct _Node_iterator
    : public _Node_iterator_base<_Value, __cache>
    {
    private:
      using __base_type = _Node_iterator_base<_Value, __cache>;
      using __node_type = typename __base_type::__node_type;

    public:
      typedef _Value value_type;
      typedef std::ptrdiff_t difference_type;
      typedef std::forward_iterator_tag iterator_category;

      using pointer = typename std::conditional<__constant_iterators,
      const _Value*, _Value*>::type;

      using reference = typename std::conditional<__constant_iterators,
        const _Value&, _Value&>::type;

      _Node_iterator() noexcept
      : __base_type(0) { }

      explicit
      _Node_iterator(__node_type* __p) noexcept
      : __base_type(__p) { }

      reference
      operator*() const noexcept
      { return this->_M_cur->_M_v(); }

      pointer
      operator->() const noexcept
      { return this->_M_cur->_M_valptr(); }

      _Node_iterator&
      operator++() noexcept
      {
 this->_M_incr();
 return *this;
      }

      _Node_iterator
      operator++(int) noexcept
      {
 _Node_iterator __tmp(*this);
 this->_M_incr();
 return __tmp;
      }
    };


  template<typename _Value, bool __constant_iterators, bool __cache>
    struct _Node_const_iterator
    : public _Node_iterator_base<_Value, __cache>
    {
    private:
      using __base_type = _Node_iterator_base<_Value, __cache>;
      using __node_type = typename __base_type::__node_type;

    public:
      typedef _Value value_type;
      typedef std::ptrdiff_t difference_type;
      typedef std::forward_iterator_tag iterator_category;

      typedef const _Value* pointer;
      typedef const _Value& reference;

      _Node_const_iterator() noexcept
      : __base_type(0) { }

      explicit
      _Node_const_iterator(__node_type* __p) noexcept
      : __base_type(__p) { }

      _Node_const_iterator(const _Node_iterator<_Value, __constant_iterators,
      __cache>& __x) noexcept
      : __base_type(__x._M_cur) { }

      reference
      operator*() const noexcept
      { return this->_M_cur->_M_v(); }

      pointer
      operator->() const noexcept
      { return this->_M_cur->_M_valptr(); }

      _Node_const_iterator&
      operator++() noexcept
      {
 this->_M_incr();
 return *this;
      }

      _Node_const_iterator
      operator++(int) noexcept
      {
 _Node_const_iterator __tmp(*this);
 this->_M_incr();
 return __tmp;
      }
    };






  struct _Mod_range_hashing
  {
    typedef std::size_t first_argument_type;
    typedef std::size_t second_argument_type;
    typedef std::size_t result_type;

    result_type
    operator()(first_argument_type __num,
        second_argument_type __den) const noexcept
    { return __num % __den; }
  };






  struct _Default_ranged_hash { };



  struct _Prime_rehash_policy
  {
    using __has_load_factor = std::true_type;

    _Prime_rehash_policy(float __z = 1.0) noexcept
    : _M_max_load_factor(__z), _M_next_resize(0) { }

    float
    max_load_factor() const noexcept
    { return _M_max_load_factor; }


    std::size_t
    _M_next_bkt(std::size_t __n) const;


    std::size_t
    _M_bkt_for_elements(std::size_t __n) const
    { return __builtin_ceil(__n / (long double)_M_max_load_factor); }





    std::pair<bool, std::size_t>
    _M_need_rehash(std::size_t __n_bkt, std::size_t __n_elt,
     std::size_t __n_ins) const;

    typedef std::size_t _State;

    _State
    _M_state() const
    { return _M_next_resize; }

    void
    _M_reset() noexcept
    { _M_next_resize = 0; }

    void
    _M_reset(_State __state)
    { _M_next_resize = __state; }

    static const std::size_t _S_growth_factor = 2;

    float _M_max_load_factor;
    mutable std::size_t _M_next_resize;
  };


  struct _Mask_range_hashing
  {
    typedef std::size_t first_argument_type;
    typedef std::size_t second_argument_type;
    typedef std::size_t result_type;

    result_type
    operator()(first_argument_type __num,
        second_argument_type __den) const noexcept
    { return __num & (__den - 1); }
  };


  inline std::size_t
  __clp2(std::size_t __n) noexcept
  {

    if (__n < 2)
      return __n;
    const unsigned __lz = sizeof(size_t) > sizeof(long)
      ? __builtin_clzll(__n - 1ull)
      : __builtin_clzl(__n - 1ul);

    return (size_t(1) << (numeric_limits<size_t>::digits - __lz - 1)) << 1;
  }



  struct _Power2_rehash_policy
  {
    using __has_load_factor = std::true_type;

    _Power2_rehash_policy(float __z = 1.0) noexcept
    : _M_max_load_factor(__z), _M_next_resize(0) { }

    float
    max_load_factor() const noexcept
    { return _M_max_load_factor; }



    std::size_t
    _M_next_bkt(std::size_t __n) noexcept
    {
      const auto __max_width = std::min<size_t>(sizeof(size_t), 8);
      const auto __max_bkt = size_t(1) << (__max_width * 8 - 1);
      std::size_t __res = __clp2(__n);

      if (__res == __n)
 __res <<= 1;

      if (__res == 0)
 __res = __max_bkt;

      if (__res == __max_bkt)



 _M_next_resize = std::size_t(-1);
      else
 _M_next_resize
   = __builtin_ceil(__res * (long double)_M_max_load_factor);

      return __res;
    }


    std::size_t
    _M_bkt_for_elements(std::size_t __n) const noexcept
    { return __builtin_ceil(__n / (long double)_M_max_load_factor); }





    std::pair<bool, std::size_t>
    _M_need_rehash(std::size_t __n_bkt, std::size_t __n_elt,
     std::size_t __n_ins) noexcept
    {
      if (__n_elt + __n_ins >= _M_next_resize)
 {
   long double __min_bkts = (__n_elt + __n_ins)
     / (long double)_M_max_load_factor;
   if (__min_bkts >= __n_bkt)
     return std::make_pair(true,
       _M_next_bkt(std::max<std::size_t>(__builtin_floor(__min_bkts) + 1,
      __n_bkt * _S_growth_factor)));

   _M_next_resize
     = __builtin_floor(__n_bkt * (long double)_M_max_load_factor);
   return std::make_pair(false, 0);
 }
      else
 return std::make_pair(false, 0);
    }

    typedef std::size_t _State;

    _State
    _M_state() const noexcept
    { return _M_next_resize; }

    void
    _M_reset() noexcept
    { _M_next_resize = 0; }

    void
    _M_reset(_State __state) noexcept
    { _M_next_resize = __state; }

    static const std::size_t _S_growth_factor = 2;

    float _M_max_load_factor;
    std::size_t _M_next_resize;
  };
# 628 "/usr/include/c++/9.2.0/bits/hashtable_policy.h" 3
  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits,
    bool _Unique_keys = _Traits::__unique_keys::value>
    struct _Map_base { };


  template<typename _Key, typename _Pair, typename _Alloc, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    struct _Map_base<_Key, _Pair, _Alloc, _Select1st, _Equal,
       _H1, _H2, _Hash, _RehashPolicy, _Traits, false>
    {
      using mapped_type = typename std::tuple_element<1, _Pair>::type;
    };


  template<typename _Key, typename _Pair, typename _Alloc, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    struct _Map_base<_Key, _Pair, _Alloc, _Select1st, _Equal,
       _H1, _H2, _Hash, _RehashPolicy, _Traits, true>
    {
    private:
      using __hashtable_base = __detail::_Hashtable_base<_Key, _Pair,
        _Select1st,
       _Equal, _H1, _H2, _Hash,
         _Traits>;

      using __hashtable = _Hashtable<_Key, _Pair, _Alloc,
         _Select1st, _Equal,
         _H1, _H2, _Hash, _RehashPolicy, _Traits>;

      using __hash_code = typename __hashtable_base::__hash_code;
      using __node_type = typename __hashtable_base::__node_type;

    public:
      using key_type = typename __hashtable_base::key_type;
      using iterator = typename __hashtable_base::iterator;
      using mapped_type = typename std::tuple_element<1, _Pair>::type;

      mapped_type&
      operator[](const key_type& __k);

      mapped_type&
      operator[](key_type&& __k);



      mapped_type&
      at(const key_type& __k);

      const mapped_type&
      at(const key_type& __k) const;
    };

  template<typename _Key, typename _Pair, typename _Alloc, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    auto
    _Map_base<_Key, _Pair, _Alloc, _Select1st, _Equal,
       _H1, _H2, _Hash, _RehashPolicy, _Traits, true>::
    operator[](const key_type& __k)
    -> mapped_type&
    {
      __hashtable* __h = static_cast<__hashtable*>(this);
      __hash_code __code = __h->_M_hash_code(__k);
      std::size_t __n = __h->_M_bucket_index(__k, __code);
      __node_type* __p = __h->_M_find_node(__n, __k, __code);

      if (!__p)
 {
   __p = __h->_M_allocate_node(std::piecewise_construct,
          std::tuple<const key_type&>(__k),
          std::tuple<>());
   return __h->_M_insert_unique_node(__n, __code, __p)->second;
 }

      return __p->_M_v().second;
    }

  template<typename _Key, typename _Pair, typename _Alloc, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    auto
    _Map_base<_Key, _Pair, _Alloc, _Select1st, _Equal,
       _H1, _H2, _Hash, _RehashPolicy, _Traits, true>::
    operator[](key_type&& __k)
    -> mapped_type&
    {
      __hashtable* __h = static_cast<__hashtable*>(this);
      __hash_code __code = __h->_M_hash_code(__k);
      std::size_t __n = __h->_M_bucket_index(__k, __code);
      __node_type* __p = __h->_M_find_node(__n, __k, __code);

      if (!__p)
 {
   __p = __h->_M_allocate_node(std::piecewise_construct,
          std::forward_as_tuple(std::move(__k)),
          std::tuple<>());
   return __h->_M_insert_unique_node(__n, __code, __p)->second;
 }

      return __p->_M_v().second;
    }

  template<typename _Key, typename _Pair, typename _Alloc, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    auto
    _Map_base<_Key, _Pair, _Alloc, _Select1st, _Equal,
       _H1, _H2, _Hash, _RehashPolicy, _Traits, true>::
    at(const key_type& __k)
    -> mapped_type&
    {
      __hashtable* __h = static_cast<__hashtable*>(this);
      __hash_code __code = __h->_M_hash_code(__k);
      std::size_t __n = __h->_M_bucket_index(__k, __code);
      __node_type* __p = __h->_M_find_node(__n, __k, __code);

      if (!__p)
 __throw_out_of_range(("_Map_base::at"));
      return __p->_M_v().second;
    }

  template<typename _Key, typename _Pair, typename _Alloc, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    auto
    _Map_base<_Key, _Pair, _Alloc, _Select1st, _Equal,
       _H1, _H2, _Hash, _RehashPolicy, _Traits, true>::
    at(const key_type& __k) const
    -> const mapped_type&
    {
      const __hashtable* __h = static_cast<const __hashtable*>(this);
      __hash_code __code = __h->_M_hash_code(__k);
      std::size_t __n = __h->_M_bucket_index(__k, __code);
      __node_type* __p = __h->_M_find_node(__n, __k, __code);

      if (!__p)
 __throw_out_of_range(("_Map_base::at"));
      return __p->_M_v().second;
    }






  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    struct _Insert_base
    {
    protected:
      using __hashtable = _Hashtable<_Key, _Value, _Alloc, _ExtractKey,
         _Equal, _H1, _H2, _Hash,
         _RehashPolicy, _Traits>;

      using __hashtable_base = _Hashtable_base<_Key, _Value, _ExtractKey,
            _Equal, _H1, _H2, _Hash,
            _Traits>;

      using value_type = typename __hashtable_base::value_type;
      using iterator = typename __hashtable_base::iterator;
      using const_iterator = typename __hashtable_base::const_iterator;
      using size_type = typename __hashtable_base::size_type;

      using __unique_keys = typename __hashtable_base::__unique_keys;
      using __ireturn_type = typename __hashtable_base::__ireturn_type;
      using __node_type = _Hash_node<_Value, _Traits::__hash_cached::value>;
      using __node_alloc_type = __alloc_rebind<_Alloc, __node_type>;
      using __node_gen_type = _AllocNode<__node_alloc_type>;

      __hashtable&
      _M_conjure_hashtable()
      { return *(static_cast<__hashtable*>(this)); }

      template<typename _InputIterator, typename _NodeGetter>
 void
 _M_insert_range(_InputIterator __first, _InputIterator __last,
   const _NodeGetter&, true_type);

      template<typename _InputIterator, typename _NodeGetter>
 void
 _M_insert_range(_InputIterator __first, _InputIterator __last,
   const _NodeGetter&, false_type);

    public:
      __ireturn_type
      insert(const value_type& __v)
      {
 __hashtable& __h = _M_conjure_hashtable();
 __node_gen_type __node_gen(__h);
 return __h._M_insert(__v, __node_gen, __unique_keys());
      }

      iterator
      insert(const_iterator __hint, const value_type& __v)
      {
 __hashtable& __h = _M_conjure_hashtable();
 __node_gen_type __node_gen(__h);
 return __h._M_insert(__hint, __v, __node_gen, __unique_keys());
      }

      void
      insert(initializer_list<value_type> __l)
      { this->insert(__l.begin(), __l.end()); }

      template<typename _InputIterator>
 void
 insert(_InputIterator __first, _InputIterator __last)
 {
   __hashtable& __h = _M_conjure_hashtable();
   __node_gen_type __node_gen(__h);
   return _M_insert_range(__first, __last, __node_gen, __unique_keys());
 }
    };

  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    template<typename _InputIterator, typename _NodeGetter>
      void
      _Insert_base<_Key, _Value, _Alloc, _ExtractKey, _Equal, _H1, _H2, _Hash,
      _RehashPolicy, _Traits>::
      _M_insert_range(_InputIterator __first, _InputIterator __last,
        const _NodeGetter& __node_gen, true_type)
      {
 size_type __n_elt = __detail::__distance_fw(__first, __last);
 if (__n_elt == 0)
   return;

 __hashtable& __h = _M_conjure_hashtable();
 for (; __first != __last; ++__first)
   {
     if (__h._M_insert(*__first, __node_gen, __unique_keys(),
         __n_elt).second)
       __n_elt = 1;
     else if (__n_elt != 1)
       --__n_elt;
   }
      }

  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    template<typename _InputIterator, typename _NodeGetter>
      void
      _Insert_base<_Key, _Value, _Alloc, _ExtractKey, _Equal, _H1, _H2, _Hash,
      _RehashPolicy, _Traits>::
      _M_insert_range(_InputIterator __first, _InputIterator __last,
        const _NodeGetter& __node_gen, false_type)
      {
 using __rehash_type = typename __hashtable::__rehash_type;
 using __rehash_state = typename __hashtable::__rehash_state;
 using pair_type = std::pair<bool, std::size_t>;

 size_type __n_elt = __detail::__distance_fw(__first, __last);
 if (__n_elt == 0)
   return;

 __hashtable& __h = _M_conjure_hashtable();
 __rehash_type& __rehash = __h._M_rehash_policy;
 const __rehash_state& __saved_state = __rehash._M_state();
 pair_type __do_rehash = __rehash._M_need_rehash(__h._M_bucket_count,
       __h._M_element_count,
       __n_elt);

 if (__do_rehash.first)
   __h._M_rehash(__do_rehash.second, __saved_state);

 for (; __first != __last; ++__first)
   __h._M_insert(*__first, __node_gen, __unique_keys());
      }







  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits,
    bool _Constant_iterators = _Traits::__constant_iterators::value>
    struct _Insert;


  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    struct _Insert<_Key, _Value, _Alloc, _ExtractKey, _Equal, _H1, _H2, _Hash,
     _RehashPolicy, _Traits, true>
    : public _Insert_base<_Key, _Value, _Alloc, _ExtractKey, _Equal,
      _H1, _H2, _Hash, _RehashPolicy, _Traits>
    {
      using __base_type = _Insert_base<_Key, _Value, _Alloc, _ExtractKey,
     _Equal, _H1, _H2, _Hash,
     _RehashPolicy, _Traits>;

      using __hashtable_base = _Hashtable_base<_Key, _Value, _ExtractKey,
            _Equal, _H1, _H2, _Hash,
            _Traits>;

      using value_type = typename __base_type::value_type;
      using iterator = typename __base_type::iterator;
      using const_iterator = typename __base_type::const_iterator;

      using __unique_keys = typename __base_type::__unique_keys;
      using __ireturn_type = typename __hashtable_base::__ireturn_type;
      using __hashtable = typename __base_type::__hashtable;
      using __node_gen_type = typename __base_type::__node_gen_type;

      using __base_type::insert;

      __ireturn_type
      insert(value_type&& __v)
      {
 __hashtable& __h = this->_M_conjure_hashtable();
 __node_gen_type __node_gen(__h);
 return __h._M_insert(std::move(__v), __node_gen, __unique_keys());
      }

      iterator
      insert(const_iterator __hint, value_type&& __v)
      {
 __hashtable& __h = this->_M_conjure_hashtable();
 __node_gen_type __node_gen(__h);
 return __h._M_insert(__hint, std::move(__v), __node_gen,
        __unique_keys());
      }
    };


  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    struct _Insert<_Key, _Value, _Alloc, _ExtractKey, _Equal, _H1, _H2, _Hash,
     _RehashPolicy, _Traits, false>
    : public _Insert_base<_Key, _Value, _Alloc, _ExtractKey, _Equal,
      _H1, _H2, _Hash, _RehashPolicy, _Traits>
    {
      using __base_type = _Insert_base<_Key, _Value, _Alloc, _ExtractKey,
           _Equal, _H1, _H2, _Hash,
           _RehashPolicy, _Traits>;
      using value_type = typename __base_type::value_type;
      using iterator = typename __base_type::iterator;
      using const_iterator = typename __base_type::const_iterator;

      using __unique_keys = typename __base_type::__unique_keys;
      using __hashtable = typename __base_type::__hashtable;
      using __ireturn_type = typename __base_type::__ireturn_type;

      using __base_type::insert;

      template<typename _Pair>
 using __is_cons = std::is_constructible<value_type, _Pair&&>;

      template<typename _Pair>
 using _IFcons = std::enable_if<__is_cons<_Pair>::value>;

      template<typename _Pair>
 using _IFconsp = typename _IFcons<_Pair>::type;

      template<typename _Pair, typename = _IFconsp<_Pair>>
 __ireturn_type
 insert(_Pair&& __v)
 {
   __hashtable& __h = this->_M_conjure_hashtable();
   return __h._M_emplace(__unique_keys(), std::forward<_Pair>(__v));
 }

      template<typename _Pair, typename = _IFconsp<_Pair>>
 iterator
 insert(const_iterator __hint, _Pair&& __v)
 {
   __hashtable& __h = this->_M_conjure_hashtable();
   return __h._M_emplace(__hint, __unique_keys(),
    std::forward<_Pair>(__v));
 }
   };

  template<typename _Policy>
    using __has_load_factor = typename _Policy::__has_load_factor;







  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits,
    typename =
      __detected_or_t<std::false_type, __has_load_factor, _RehashPolicy>>
    struct _Rehash_base;


  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    struct _Rehash_base<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits,
        std::false_type>
    {
    };


  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    struct _Rehash_base<_Key, _Value, _Alloc, _ExtractKey, _Equal,
   _H1, _H2, _Hash, _RehashPolicy, _Traits,
   std::true_type>
    {
      using __hashtable = _Hashtable<_Key, _Value, _Alloc, _ExtractKey,
         _Equal, _H1, _H2, _Hash,
         _RehashPolicy, _Traits>;

      float
      max_load_factor() const noexcept
      {
 const __hashtable* __this = static_cast<const __hashtable*>(this);
 return __this->__rehash_policy().max_load_factor();
      }

      void
      max_load_factor(float __z)
      {
 __hashtable* __this = static_cast<__hashtable*>(this);
 __this->__rehash_policy(_RehashPolicy(__z));
      }

      void
      reserve(std::size_t __n)
      {
 __hashtable* __this = static_cast<__hashtable*>(this);
 __this->rehash(__builtin_ceil(__n / max_load_factor()));
      }
    };







  template<int _Nm, typename _Tp,
    bool __use_ebo = !__is_final(_Tp) && __is_empty(_Tp)>
    struct _Hashtable_ebo_helper;


  template<int _Nm, typename _Tp>
    struct _Hashtable_ebo_helper<_Nm, _Tp, true>
    : private _Tp
    {
      _Hashtable_ebo_helper() = default;

      template<typename _OtherTp>
 _Hashtable_ebo_helper(_OtherTp&& __tp)
   : _Tp(std::forward<_OtherTp>(__tp))
 { }

      static const _Tp&
      _S_cget(const _Hashtable_ebo_helper& __eboh)
      { return static_cast<const _Tp&>(__eboh); }

      static _Tp&
      _S_get(_Hashtable_ebo_helper& __eboh)
      { return static_cast<_Tp&>(__eboh); }
    };


  template<int _Nm, typename _Tp>
    struct _Hashtable_ebo_helper<_Nm, _Tp, false>
    {
      _Hashtable_ebo_helper() = default;

      template<typename _OtherTp>
 _Hashtable_ebo_helper(_OtherTp&& __tp)
   : _M_tp(std::forward<_OtherTp>(__tp))
 { }

      static const _Tp&
      _S_cget(const _Hashtable_ebo_helper& __eboh)
      { return __eboh._M_tp; }

      static _Tp&
      _S_get(_Hashtable_ebo_helper& __eboh)
      { return __eboh._M_tp; }

    private:
      _Tp _M_tp;
    };







  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _H1, typename _H2, typename _Hash,
    bool __cache_hash_code>
    struct _Local_iterator_base;
# 1166 "/usr/include/c++/9.2.0/bits/hashtable_policy.h" 3
  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _H1, typename _H2, typename _Hash,
    bool __cache_hash_code>
    struct _Hash_code_base;



  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _H1, typename _H2, typename _Hash>
    struct _Hash_code_base<_Key, _Value, _ExtractKey, _H1, _H2, _Hash, false>
    : private _Hashtable_ebo_helper<0, _ExtractKey>,
      private _Hashtable_ebo_helper<1, _Hash>
    {
    private:
      using __ebo_extract_key = _Hashtable_ebo_helper<0, _ExtractKey>;
      using __ebo_hash = _Hashtable_ebo_helper<1, _Hash>;

    protected:
      typedef void* __hash_code;
      typedef _Hash_node<_Value, false> __node_type;



      _Hash_code_base() = default;

      _Hash_code_base(const _ExtractKey& __ex, const _H1&, const _H2&,
        const _Hash& __h)
      : __ebo_extract_key(__ex), __ebo_hash(__h) { }

      __hash_code
      _M_hash_code(const _Key& __key) const
      { return 0; }

      std::size_t
      _M_bucket_index(const _Key& __k, __hash_code, std::size_t __n) const
      { return _M_ranged_hash()(__k, __n); }

      std::size_t
      _M_bucket_index(const __node_type* __p, std::size_t __n) const
 noexcept( noexcept(declval<const _Hash&>()(declval<const _Key&>(),
         (std::size_t)0)) )
      { return _M_ranged_hash()(_M_extract()(__p->_M_v()), __n); }

      void
      _M_store_code(__node_type*, __hash_code) const
      { }

      void
      _M_copy_code(__node_type*, const __node_type*) const
      { }

      void
      _M_swap(_Hash_code_base& __x)
      {
 std::swap(_M_extract(), __x._M_extract());
 std::swap(_M_ranged_hash(), __x._M_ranged_hash());
      }

      const _ExtractKey&
      _M_extract() const { return __ebo_extract_key::_S_cget(*this); }

      _ExtractKey&
      _M_extract() { return __ebo_extract_key::_S_get(*this); }

      const _Hash&
      _M_ranged_hash() const { return __ebo_hash::_S_cget(*this); }

      _Hash&
      _M_ranged_hash() { return __ebo_hash::_S_get(*this); }
    };







  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _H1, typename _H2, typename _Hash>
    struct _Hash_code_base<_Key, _Value, _ExtractKey, _H1, _H2, _Hash, true>;




  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _H1, typename _H2>
    struct _Hash_code_base<_Key, _Value, _ExtractKey, _H1, _H2,
      _Default_ranged_hash, false>
    : private _Hashtable_ebo_helper<0, _ExtractKey>,
      private _Hashtable_ebo_helper<1, _H1>,
      private _Hashtable_ebo_helper<2, _H2>
    {
    private:
      using __ebo_extract_key = _Hashtable_ebo_helper<0, _ExtractKey>;
      using __ebo_h1 = _Hashtable_ebo_helper<1, _H1>;
      using __ebo_h2 = _Hashtable_ebo_helper<2, _H2>;


      friend struct _Local_iterator_base<_Key, _Value, _ExtractKey, _H1, _H2,
      _Default_ranged_hash, false>;

    public:
      typedef _H1 hasher;

      hasher
      hash_function() const
      { return _M_h1(); }

    protected:
      typedef std::size_t __hash_code;
      typedef _Hash_node<_Value, false> __node_type;



      _Hash_code_base() = default;

      _Hash_code_base(const _ExtractKey& __ex,
        const _H1& __h1, const _H2& __h2,
        const _Default_ranged_hash&)
      : __ebo_extract_key(__ex), __ebo_h1(__h1), __ebo_h2(__h2) { }

      __hash_code
      _M_hash_code(const _Key& __k) const
      {
 static_assert(__is_invocable<const _H1&, const _Key&>{},
     "hash function must be invocable with an argument of key type");
 return _M_h1()(__k);
      }

      std::size_t
      _M_bucket_index(const _Key&, __hash_code __c, std::size_t __n) const
      { return _M_h2()(__c, __n); }

      std::size_t
      _M_bucket_index(const __node_type* __p, std::size_t __n) const
 noexcept( noexcept(declval<const _H1&>()(declval<const _Key&>()))
    && noexcept(declval<const _H2&>()((__hash_code)0,
          (std::size_t)0)) )
      { return _M_h2()(_M_h1()(_M_extract()(__p->_M_v())), __n); }

      void
      _M_store_code(__node_type*, __hash_code) const
      { }

      void
      _M_copy_code(__node_type*, const __node_type*) const
      { }

      void
      _M_swap(_Hash_code_base& __x)
      {
 std::swap(_M_extract(), __x._M_extract());
 std::swap(_M_h1(), __x._M_h1());
 std::swap(_M_h2(), __x._M_h2());
      }

      const _ExtractKey&
      _M_extract() const { return __ebo_extract_key::_S_cget(*this); }

      _ExtractKey&
      _M_extract() { return __ebo_extract_key::_S_get(*this); }

      const _H1&
      _M_h1() const { return __ebo_h1::_S_cget(*this); }

      _H1&
      _M_h1() { return __ebo_h1::_S_get(*this); }

      const _H2&
      _M_h2() const { return __ebo_h2::_S_cget(*this); }

      _H2&
      _M_h2() { return __ebo_h2::_S_get(*this); }
    };




  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _H1, typename _H2>
    struct _Hash_code_base<_Key, _Value, _ExtractKey, _H1, _H2,
      _Default_ranged_hash, true>
    : private _Hashtable_ebo_helper<0, _ExtractKey>,
      private _Hashtable_ebo_helper<1, _H1>,
      private _Hashtable_ebo_helper<2, _H2>
    {
    private:

      friend struct _Local_iterator_base<_Key, _Value, _ExtractKey, _H1, _H2,
      _Default_ranged_hash, true>;

      using __ebo_extract_key = _Hashtable_ebo_helper<0, _ExtractKey>;
      using __ebo_h1 = _Hashtable_ebo_helper<1, _H1>;
      using __ebo_h2 = _Hashtable_ebo_helper<2, _H2>;

    public:
      typedef _H1 hasher;

      hasher
      hash_function() const
      { return _M_h1(); }

    protected:
      typedef std::size_t __hash_code;
      typedef _Hash_node<_Value, true> __node_type;


      _Hash_code_base() = default;
      _Hash_code_base(const _ExtractKey& __ex,
        const _H1& __h1, const _H2& __h2,
        const _Default_ranged_hash&)
      : __ebo_extract_key(__ex), __ebo_h1(__h1), __ebo_h2(__h2) { }

      __hash_code
      _M_hash_code(const _Key& __k) const
      {
 static_assert(__is_invocable<const _H1&, const _Key&>{},
     "hash function must be invocable with an argument of key type");
 return _M_h1()(__k);
      }

      std::size_t
      _M_bucket_index(const _Key&, __hash_code __c,
        std::size_t __n) const
      { return _M_h2()(__c, __n); }

      std::size_t
      _M_bucket_index(const __node_type* __p, std::size_t __n) const
 noexcept( noexcept(declval<const _H2&>()((__hash_code)0,
       (std::size_t)0)) )
      { return _M_h2()(__p->_M_hash_code, __n); }

      void
      _M_store_code(__node_type* __n, __hash_code __c) const
      { __n->_M_hash_code = __c; }

      void
      _M_copy_code(__node_type* __to, const __node_type* __from) const
      { __to->_M_hash_code = __from->_M_hash_code; }

      void
      _M_swap(_Hash_code_base& __x)
      {
 std::swap(_M_extract(), __x._M_extract());
 std::swap(_M_h1(), __x._M_h1());
 std::swap(_M_h2(), __x._M_h2());
      }

      const _ExtractKey&
      _M_extract() const { return __ebo_extract_key::_S_cget(*this); }

      _ExtractKey&
      _M_extract() { return __ebo_extract_key::_S_get(*this); }

      const _H1&
      _M_h1() const { return __ebo_h1::_S_cget(*this); }

      _H1&
      _M_h1() { return __ebo_h1::_S_get(*this); }

      const _H2&
      _M_h2() const { return __ebo_h2::_S_cget(*this); }

      _H2&
      _M_h2() { return __ebo_h2::_S_get(*this); }
    };





  template <typename _Key, typename _Value, typename _ExtractKey,
     typename _Equal, typename _HashCodeType,
     bool __cache_hash_code>
  struct _Equal_helper;


  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _Equal, typename _HashCodeType>
  struct _Equal_helper<_Key, _Value, _ExtractKey, _Equal, _HashCodeType, true>
  {
    static bool
    _S_equals(const _Equal& __eq, const _ExtractKey& __extract,
       const _Key& __k, _HashCodeType __c, _Hash_node<_Value, true>* __n)
    { return __c == __n->_M_hash_code && __eq(__k, __extract(__n->_M_v())); }
  };


  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _Equal, typename _HashCodeType>
  struct _Equal_helper<_Key, _Value, _ExtractKey, _Equal, _HashCodeType, false>
  {
    static bool
    _S_equals(const _Equal& __eq, const _ExtractKey& __extract,
       const _Key& __k, _HashCodeType, _Hash_node<_Value, false>* __n)
    { return __eq(__k, __extract(__n->_M_v())); }
  };



  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _H1, typename _H2, typename _Hash>
    struct _Local_iterator_base<_Key, _Value, _ExtractKey,
    _H1, _H2, _Hash, true>
    : private _Hashtable_ebo_helper<0, _H2>
    {
    protected:
      using __base_type = _Hashtable_ebo_helper<0, _H2>;
      using __hash_code_base = _Hash_code_base<_Key, _Value, _ExtractKey,
            _H1, _H2, _Hash, true>;

      _Local_iterator_base() = default;
      _Local_iterator_base(const __hash_code_base& __base,
      _Hash_node<_Value, true>* __p,
      std::size_t __bkt, std::size_t __bkt_count)
      : __base_type(__base._M_h2()),
 _M_cur(__p), _M_bucket(__bkt), _M_bucket_count(__bkt_count) { }

      void
      _M_incr()
      {
 _M_cur = _M_cur->_M_next();
 if (_M_cur)
   {
     std::size_t __bkt
       = __base_type::_S_get(*this)(_M_cur->_M_hash_code,
        _M_bucket_count);
     if (__bkt != _M_bucket)
       _M_cur = nullptr;
   }
      }

      _Hash_node<_Value, true>* _M_cur;
      std::size_t _M_bucket;
      std::size_t _M_bucket_count;

    public:
      const void*
      _M_curr() const { return _M_cur; }

      std::size_t
      _M_get_bucket() const { return _M_bucket; }
    };





  template<typename _Tp, bool _IsEmpty = std::is_empty<_Tp>::value>
    struct _Hash_code_storage
    {
      __gnu_cxx::__aligned_buffer<_Tp> _M_storage;

      _Tp*
      _M_h() { return _M_storage._M_ptr(); }

      const _Tp*
      _M_h() const { return _M_storage._M_ptr(); }
    };


  template<typename _Tp>
    struct _Hash_code_storage<_Tp, true>
    {
      static_assert( std::is_empty<_Tp>::value, "Type must be empty" );



      _Tp*
      _M_h() { return reinterpret_cast<_Tp*>(this); }

      const _Tp*
      _M_h() const { return reinterpret_cast<const _Tp*>(this); }
    };

  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _H1, typename _H2, typename _Hash>
    using __hash_code_for_local_iter
      = _Hash_code_storage<_Hash_code_base<_Key, _Value, _ExtractKey,
        _H1, _H2, _Hash, false>>;


  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _H1, typename _H2, typename _Hash>
    struct _Local_iterator_base<_Key, _Value, _ExtractKey,
    _H1, _H2, _Hash, false>
    : __hash_code_for_local_iter<_Key, _Value, _ExtractKey, _H1, _H2, _Hash>
    {
    protected:
      using __hash_code_base = _Hash_code_base<_Key, _Value, _ExtractKey,
            _H1, _H2, _Hash, false>;

      _Local_iterator_base() : _M_bucket_count(-1) { }

      _Local_iterator_base(const __hash_code_base& __base,
      _Hash_node<_Value, false>* __p,
      std::size_t __bkt, std::size_t __bkt_count)
      : _M_cur(__p), _M_bucket(__bkt), _M_bucket_count(__bkt_count)
      { _M_init(__base); }

      ~_Local_iterator_base()
      {
 if (_M_bucket_count != -1)
   _M_destroy();
      }

      _Local_iterator_base(const _Local_iterator_base& __iter)
      : _M_cur(__iter._M_cur), _M_bucket(__iter._M_bucket),
        _M_bucket_count(__iter._M_bucket_count)
      {
 if (_M_bucket_count != -1)
   _M_init(*__iter._M_h());
      }

      _Local_iterator_base&
      operator=(const _Local_iterator_base& __iter)
      {
 if (_M_bucket_count != -1)
   _M_destroy();
 _M_cur = __iter._M_cur;
 _M_bucket = __iter._M_bucket;
 _M_bucket_count = __iter._M_bucket_count;
 if (_M_bucket_count != -1)
   _M_init(*__iter._M_h());
 return *this;
      }

      void
      _M_incr()
      {
 _M_cur = _M_cur->_M_next();
 if (_M_cur)
   {
     std::size_t __bkt = this->_M_h()->_M_bucket_index(_M_cur,
             _M_bucket_count);
     if (__bkt != _M_bucket)
       _M_cur = nullptr;
   }
      }

      _Hash_node<_Value, false>* _M_cur;
      std::size_t _M_bucket;
      std::size_t _M_bucket_count;

      void
      _M_init(const __hash_code_base& __base)
      { ::new(this->_M_h()) __hash_code_base(__base); }

      void
      _M_destroy() { this->_M_h()->~__hash_code_base(); }

    public:
      const void*
      _M_curr() const { return _M_cur; }

      std::size_t
      _M_get_bucket() const { return _M_bucket; }
    };

  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _H1, typename _H2, typename _Hash, bool __cache>
    inline bool
    operator==(const _Local_iterator_base<_Key, _Value, _ExtractKey,
       _H1, _H2, _Hash, __cache>& __x,
        const _Local_iterator_base<_Key, _Value, _ExtractKey,
       _H1, _H2, _Hash, __cache>& __y)
    { return __x._M_curr() == __y._M_curr(); }

  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _H1, typename _H2, typename _Hash, bool __cache>
    inline bool
    operator!=(const _Local_iterator_base<_Key, _Value, _ExtractKey,
       _H1, _H2, _Hash, __cache>& __x,
        const _Local_iterator_base<_Key, _Value, _ExtractKey,
       _H1, _H2, _Hash, __cache>& __y)
    { return __x._M_curr() != __y._M_curr(); }


  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _H1, typename _H2, typename _Hash,
    bool __constant_iterators, bool __cache>
    struct _Local_iterator
    : public _Local_iterator_base<_Key, _Value, _ExtractKey,
      _H1, _H2, _Hash, __cache>
    {
    private:
      using __base_type = _Local_iterator_base<_Key, _Value, _ExtractKey,
            _H1, _H2, _Hash, __cache>;
      using __hash_code_base = typename __base_type::__hash_code_base;
    public:
      typedef _Value value_type;
      typedef typename std::conditional<__constant_iterators,
     const _Value*, _Value*>::type
             pointer;
      typedef typename std::conditional<__constant_iterators,
     const _Value&, _Value&>::type
             reference;
      typedef std::ptrdiff_t difference_type;
      typedef std::forward_iterator_tag iterator_category;

      _Local_iterator() = default;

      _Local_iterator(const __hash_code_base& __base,
        _Hash_node<_Value, __cache>* __p,
        std::size_t __bkt, std::size_t __bkt_count)
 : __base_type(__base, __p, __bkt, __bkt_count)
      { }

      reference
      operator*() const
      { return this->_M_cur->_M_v(); }

      pointer
      operator->() const
      { return this->_M_cur->_M_valptr(); }

      _Local_iterator&
      operator++()
      {
 this->_M_incr();
 return *this;
      }

      _Local_iterator
      operator++(int)
      {
 _Local_iterator __tmp(*this);
 this->_M_incr();
 return __tmp;
      }
    };


  template<typename _Key, typename _Value, typename _ExtractKey,
    typename _H1, typename _H2, typename _Hash,
    bool __constant_iterators, bool __cache>
    struct _Local_const_iterator
    : public _Local_iterator_base<_Key, _Value, _ExtractKey,
      _H1, _H2, _Hash, __cache>
    {
    private:
      using __base_type = _Local_iterator_base<_Key, _Value, _ExtractKey,
            _H1, _H2, _Hash, __cache>;
      using __hash_code_base = typename __base_type::__hash_code_base;

    public:
      typedef _Value value_type;
      typedef const _Value* pointer;
      typedef const _Value& reference;
      typedef std::ptrdiff_t difference_type;
      typedef std::forward_iterator_tag iterator_category;

      _Local_const_iterator() = default;

      _Local_const_iterator(const __hash_code_base& __base,
       _Hash_node<_Value, __cache>* __p,
       std::size_t __bkt, std::size_t __bkt_count)
 : __base_type(__base, __p, __bkt, __bkt_count)
      { }

      _Local_const_iterator(const _Local_iterator<_Key, _Value, _ExtractKey,
        _H1, _H2, _Hash,
        __constant_iterators,
        __cache>& __x)
 : __base_type(__x)
      { }

      reference
      operator*() const
      { return this->_M_cur->_M_v(); }

      pointer
      operator->() const
      { return this->_M_cur->_M_valptr(); }

      _Local_const_iterator&
      operator++()
      {
 this->_M_incr();
 return *this;
      }

      _Local_const_iterator
      operator++(int)
      {
 _Local_const_iterator __tmp(*this);
 this->_M_incr();
 return __tmp;
      }
    };
# 1767 "/usr/include/c++/9.2.0/bits/hashtable_policy.h" 3
  template<typename _Key, typename _Value,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _Traits>
  struct _Hashtable_base
  : public _Hash_code_base<_Key, _Value, _ExtractKey, _H1, _H2, _Hash,
      _Traits::__hash_cached::value>,
    private _Hashtable_ebo_helper<0, _Equal>
  {
  public:
    typedef _Key key_type;
    typedef _Value value_type;
    typedef _Equal key_equal;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

    using __traits_type = _Traits;
    using __hash_cached = typename __traits_type::__hash_cached;
    using __constant_iterators = typename __traits_type::__constant_iterators;
    using __unique_keys = typename __traits_type::__unique_keys;

    using __hash_code_base = _Hash_code_base<_Key, _Value, _ExtractKey,
          _H1, _H2, _Hash,
          __hash_cached::value>;

    using __hash_code = typename __hash_code_base::__hash_code;
    using __node_type = typename __hash_code_base::__node_type;

    using iterator = __detail::_Node_iterator<value_type,
           __constant_iterators::value,
           __hash_cached::value>;

    using const_iterator = __detail::_Node_const_iterator<value_type,
         __constant_iterators::value,
         __hash_cached::value>;

    using local_iterator = __detail::_Local_iterator<key_type, value_type,
        _ExtractKey, _H1, _H2, _Hash,
        __constant_iterators::value,
           __hash_cached::value>;

    using const_local_iterator = __detail::_Local_const_iterator<key_type,
         value_type,
     _ExtractKey, _H1, _H2, _Hash,
     __constant_iterators::value,
     __hash_cached::value>;

    using __ireturn_type = typename std::conditional<__unique_keys::value,
           std::pair<iterator, bool>,
           iterator>::type;
  private:
    using _EqualEBO = _Hashtable_ebo_helper<0, _Equal>;
    using _EqualHelper = _Equal_helper<_Key, _Value, _ExtractKey, _Equal,
     __hash_code, __hash_cached::value>;

  protected:
    _Hashtable_base() = default;
    _Hashtable_base(const _ExtractKey& __ex, const _H1& __h1, const _H2& __h2,
      const _Hash& __hash, const _Equal& __eq)
    : __hash_code_base(__ex, __h1, __h2, __hash), _EqualEBO(__eq)
    { }

    bool
    _M_equals(const _Key& __k, __hash_code __c, __node_type* __n) const
    {
      static_assert(__is_invocable<const _Equal&, const _Key&, const _Key&>{},
   "key equality predicate must be invocable with two arguments of "
   "key type");
      return _EqualHelper::_S_equals(_M_eq(), this->_M_extract(),
         __k, __c, __n);
    }

    void
    _M_swap(_Hashtable_base& __x)
    {
      __hash_code_base::_M_swap(__x);
      std::swap(_M_eq(), __x._M_eq());
    }

    const _Equal&
    _M_eq() const { return _EqualEBO::_S_cget(*this); }

    _Equal&
    _M_eq() { return _EqualEBO::_S_get(*this); }
  };






  struct _Equality_base
  {
  protected:
    template<typename _Uiterator>
      static bool
      _S_is_permutation(_Uiterator, _Uiterator, _Uiterator);
  };


  template<typename _Uiterator>
    bool
    _Equality_base::
    _S_is_permutation(_Uiterator __first1, _Uiterator __last1,
        _Uiterator __first2)
    {
      for (; __first1 != __last1; ++__first1, ++__first2)
 if (!(*__first1 == *__first2))
   break;

      if (__first1 == __last1)
 return true;

      _Uiterator __last2 = __first2;
      std::advance(__last2, std::distance(__first1, __last1));

      for (_Uiterator __it1 = __first1; __it1 != __last1; ++__it1)
 {
   _Uiterator __tmp = __first1;
   while (__tmp != __it1 && !bool(*__tmp == *__it1))
     ++__tmp;


   if (__tmp != __it1)
     continue;

   std::ptrdiff_t __n2 = 0;
   for (__tmp = __first2; __tmp != __last2; ++__tmp)
     if (*__tmp == *__it1)
       ++__n2;

   if (!__n2)
     return false;

   std::ptrdiff_t __n1 = 0;
   for (__tmp = __it1; __tmp != __last1; ++__tmp)
     if (*__tmp == *__it1)
       ++__n1;

   if (__n1 != __n2)
     return false;
 }
      return true;
    }
# 1919 "/usr/include/c++/9.2.0/bits/hashtable_policy.h" 3
  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits,
    bool _Unique_keys = _Traits::__unique_keys::value>
    struct _Equality;


  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    struct _Equality<_Key, _Value, _Alloc, _ExtractKey, _Equal,
       _H1, _H2, _Hash, _RehashPolicy, _Traits, true>
    {
      using __hashtable = _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
         _H1, _H2, _Hash, _RehashPolicy, _Traits>;

      bool
      _M_equal(const __hashtable&) const;
    };

  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    bool
    _Equality<_Key, _Value, _Alloc, _ExtractKey, _Equal,
       _H1, _H2, _Hash, _RehashPolicy, _Traits, true>::
    _M_equal(const __hashtable& __other) const
    {
      const __hashtable* __this = static_cast<const __hashtable*>(this);

      if (__this->size() != __other.size())
 return false;

      for (auto __itx = __this->begin(); __itx != __this->end(); ++__itx)
 {
   const auto __ity = __other.find(_ExtractKey()(*__itx));
   if (__ity == __other.end() || !bool(*__ity == *__itx))
     return false;
 }
      return true;
    }


  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    struct _Equality<_Key, _Value, _Alloc, _ExtractKey, _Equal,
       _H1, _H2, _Hash, _RehashPolicy, _Traits, false>
    : public _Equality_base
    {
      using __hashtable = _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
         _H1, _H2, _Hash, _RehashPolicy, _Traits>;

      bool
      _M_equal(const __hashtable&) const;
    };

  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    bool
    _Equality<_Key, _Value, _Alloc, _ExtractKey, _Equal,
       _H1, _H2, _Hash, _RehashPolicy, _Traits, false>::
    _M_equal(const __hashtable& __other) const
    {
      const __hashtable* __this = static_cast<const __hashtable*>(this);

      if (__this->size() != __other.size())
 return false;

      for (auto __itx = __this->begin(); __itx != __this->end();)
 {
   const auto __xrange = __this->equal_range(_ExtractKey()(*__itx));
   const auto __yrange = __other.equal_range(_ExtractKey()(*__itx));

   if (std::distance(__xrange.first, __xrange.second)
       != std::distance(__yrange.first, __yrange.second))
     return false;

   if (!_S_is_permutation(__xrange.first, __xrange.second,
     __yrange.first))
     return false;

   __itx = __xrange.second;
 }
      return true;
    }





  template<typename _NodeAlloc>
    struct _Hashtable_alloc : private _Hashtable_ebo_helper<0, _NodeAlloc>
    {
    private:
      using __ebo_node_alloc = _Hashtable_ebo_helper<0, _NodeAlloc>;
    public:
      using __node_type = typename _NodeAlloc::value_type;
      using __node_alloc_type = _NodeAlloc;

      using __node_alloc_traits = __gnu_cxx::__alloc_traits<__node_alloc_type>;

      using __value_alloc_traits = typename __node_alloc_traits::template
 rebind_traits<typename __node_type::value_type>;

      using __node_base = __detail::_Hash_node_base;
      using __bucket_type = __node_base*;
      using __bucket_alloc_type =
 __alloc_rebind<__node_alloc_type, __bucket_type>;
      using __bucket_alloc_traits = std::allocator_traits<__bucket_alloc_type>;

      _Hashtable_alloc() = default;
      _Hashtable_alloc(const _Hashtable_alloc&) = default;
      _Hashtable_alloc(_Hashtable_alloc&&) = default;

      template<typename _Alloc>
 _Hashtable_alloc(_Alloc&& __a)
   : __ebo_node_alloc(std::forward<_Alloc>(__a))
 { }

      __node_alloc_type&
      _M_node_allocator()
      { return __ebo_node_alloc::_S_get(*this); }

      const __node_alloc_type&
      _M_node_allocator() const
      { return __ebo_node_alloc::_S_cget(*this); }

      template<typename... _Args>
 __node_type*
 _M_allocate_node(_Args&&... __args);

      void
      _M_deallocate_node(__node_type* __n);

      void
      _M_deallocate_node_ptr(__node_type* __n);


      void
      _M_deallocate_nodes(__node_type* __n);

      __bucket_type*
      _M_allocate_buckets(std::size_t __n);

      void
      _M_deallocate_buckets(__bucket_type*, std::size_t __n);
    };



  template<typename _NodeAlloc>
    template<typename... _Args>
      typename _Hashtable_alloc<_NodeAlloc>::__node_type*
      _Hashtable_alloc<_NodeAlloc>::_M_allocate_node(_Args&&... __args)
      {
 auto __nptr = __node_alloc_traits::allocate(_M_node_allocator(), 1);
 __node_type* __n = std::__to_address(__nptr);
 try
   {
     ::new ((void*)__n) __node_type;
     __node_alloc_traits::construct(_M_node_allocator(),
        __n->_M_valptr(),
        std::forward<_Args>(__args)...);
     return __n;
   }
 catch(...)
   {
     __node_alloc_traits::deallocate(_M_node_allocator(), __nptr, 1);
     throw;
   }
      }

  template<typename _NodeAlloc>
    void
    _Hashtable_alloc<_NodeAlloc>::_M_deallocate_node(__node_type* __n)
    {
      __node_alloc_traits::destroy(_M_node_allocator(), __n->_M_valptr());
      _M_deallocate_node_ptr(__n);
    }

  template<typename _NodeAlloc>
    void
    _Hashtable_alloc<_NodeAlloc>::_M_deallocate_node_ptr(__node_type* __n)
    {
      typedef typename __node_alloc_traits::pointer _Ptr;
      auto __ptr = std::pointer_traits<_Ptr>::pointer_to(*__n);
      __n->~__node_type();
      __node_alloc_traits::deallocate(_M_node_allocator(), __ptr, 1);
    }

  template<typename _NodeAlloc>
    void
    _Hashtable_alloc<_NodeAlloc>::_M_deallocate_nodes(__node_type* __n)
    {
      while (__n)
 {
   __node_type* __tmp = __n;
   __n = __n->_M_next();
   _M_deallocate_node(__tmp);
 }
    }

  template<typename _NodeAlloc>
    typename _Hashtable_alloc<_NodeAlloc>::__bucket_type*
    _Hashtable_alloc<_NodeAlloc>::_M_allocate_buckets(std::size_t __n)
    {
      __bucket_alloc_type __alloc(_M_node_allocator());

      auto __ptr = __bucket_alloc_traits::allocate(__alloc, __n);
      __bucket_type* __p = std::__to_address(__ptr);
      __builtin_memset(__p, 0, __n * sizeof(__bucket_type));
      return __p;
    }

  template<typename _NodeAlloc>
    void
    _Hashtable_alloc<_NodeAlloc>::_M_deallocate_buckets(__bucket_type* __bkts,
       std::size_t __n)
    {
      typedef typename __bucket_alloc_traits::pointer _Ptr;
      auto __ptr = std::pointer_traits<_Ptr>::pointer_to(*__bkts);
      __bucket_alloc_type __alloc(_M_node_allocator());
      __bucket_alloc_traits::deallocate(__alloc, __ptr, __n);
    }


}

}
# 36 "/usr/include/c++/9.2.0/bits/hashtable.h" 2 3




namespace std __attribute__ ((__visibility__ ("default")))
{


  template<typename _Tp, typename _Hash>
    using __cache_default
      = __not_<__and_<
         __is_fast_hash<_Hash>,

         __is_nothrow_invocable<const _Hash&, const _Tp&>>>;
# 169 "/usr/include/c++/9.2.0/bits/hashtable.h" 3
  template<typename _Key, typename _Value, typename _Alloc,
    typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash,
    typename _RehashPolicy, typename _Traits>
    class _Hashtable
    : public __detail::_Hashtable_base<_Key, _Value, _ExtractKey, _Equal,
           _H1, _H2, _Hash, _Traits>,
      public __detail::_Map_base<_Key, _Value, _Alloc, _ExtractKey, _Equal,
     _H1, _H2, _Hash, _RehashPolicy, _Traits>,
      public __detail::_Insert<_Key, _Value, _Alloc, _ExtractKey, _Equal,
          _H1, _H2, _Hash, _RehashPolicy, _Traits>,
      public __detail::_Rehash_base<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>,
      public __detail::_Equality<_Key, _Value, _Alloc, _ExtractKey, _Equal,
     _H1, _H2, _Hash, _RehashPolicy, _Traits>,
      private __detail::_Hashtable_alloc<
 __alloc_rebind<_Alloc,
         __detail::_Hash_node<_Value,
         _Traits::__hash_cached::value>>>
    {
      static_assert(is_same<typename remove_cv<_Value>::type, _Value>::value,
   "unordered container must have a non-const, non-volatile value_type");





      using __traits_type = _Traits;
      using __hash_cached = typename __traits_type::__hash_cached;
      using __node_type = __detail::_Hash_node<_Value, __hash_cached::value>;
      using __node_alloc_type = __alloc_rebind<_Alloc, __node_type>;

      using __hashtable_alloc = __detail::_Hashtable_alloc<__node_alloc_type>;

      using __value_alloc_traits =
 typename __hashtable_alloc::__value_alloc_traits;
      using __node_alloc_traits =
 typename __hashtable_alloc::__node_alloc_traits;
      using __node_base = typename __hashtable_alloc::__node_base;
      using __bucket_type = typename __hashtable_alloc::__bucket_type;

    public:
      typedef _Key key_type;
      typedef _Value value_type;
      typedef _Alloc allocator_type;
      typedef _Equal key_equal;



      typedef typename __value_alloc_traits::pointer pointer;
      typedef typename __value_alloc_traits::const_pointer const_pointer;
      typedef value_type& reference;
      typedef const value_type& const_reference;

    private:
      using __rehash_type = _RehashPolicy;
      using __rehash_state = typename __rehash_type::_State;

      using __constant_iterators = typename __traits_type::__constant_iterators;
      using __unique_keys = typename __traits_type::__unique_keys;

      using __key_extract = typename std::conditional<
          __constant_iterators::value,
                 __detail::_Identity,
          __detail::_Select1st>::type;

      using __hashtable_base = __detail::
          _Hashtable_base<_Key, _Value, _ExtractKey,
           _Equal, _H1, _H2, _Hash, _Traits>;

      using __hash_code_base = typename __hashtable_base::__hash_code_base;
      using __hash_code = typename __hashtable_base::__hash_code;
      using __ireturn_type = typename __hashtable_base::__ireturn_type;

      using __map_base = __detail::_Map_base<_Key, _Value, _Alloc, _ExtractKey,
          _Equal, _H1, _H2, _Hash,
          _RehashPolicy, _Traits>;

      using __rehash_base = __detail::_Rehash_base<_Key, _Value, _Alloc,
         _ExtractKey, _Equal,
         _H1, _H2, _Hash,
         _RehashPolicy, _Traits>;

      using __eq_base = __detail::_Equality<_Key, _Value, _Alloc, _ExtractKey,
         _Equal, _H1, _H2, _Hash,
         _RehashPolicy, _Traits>;

      using __reuse_or_alloc_node_type =
 __detail::_ReuseOrAllocNode<__node_alloc_type>;


      template<typename _Cond>
 using __if_hash_cached = __or_<__not_<__hash_cached>, _Cond>;

      template<typename _Cond>
 using __if_hash_not_cached = __or_<__hash_cached, _Cond>;





      struct __hash_code_base_access : __hash_code_base
      { using __hash_code_base::_M_bucket_index; };



      static_assert(noexcept(declval<const __hash_code_base_access&>()
        ._M_bucket_index((const __node_type*)nullptr,
           (std::size_t)0)),
      "Cache the hash code or qualify your functors involved"
      " in hash code and bucket index computation with noexcept");






      static_assert(__if_hash_cached<is_default_constructible<_H2>>::value,
      "Functor used to map hash code to bucket index"
      " must be default constructible");

      template<typename _Keya, typename _Valuea, typename _Alloca,
        typename _ExtractKeya, typename _Equala,
        typename _H1a, typename _H2a, typename _Hasha,
        typename _RehashPolicya, typename _Traitsa,
        bool _Unique_keysa>
 friend struct __detail::_Map_base;

      template<typename _Keya, typename _Valuea, typename _Alloca,
        typename _ExtractKeya, typename _Equala,
        typename _H1a, typename _H2a, typename _Hasha,
        typename _RehashPolicya, typename _Traitsa>
 friend struct __detail::_Insert_base;

      template<typename _Keya, typename _Valuea, typename _Alloca,
        typename _ExtractKeya, typename _Equala,
        typename _H1a, typename _H2a, typename _Hasha,
        typename _RehashPolicya, typename _Traitsa,
        bool _Constant_iteratorsa>
 friend struct __detail::_Insert;

    public:
      using size_type = typename __hashtable_base::size_type;
      using difference_type = typename __hashtable_base::difference_type;

      using iterator = typename __hashtable_base::iterator;
      using const_iterator = typename __hashtable_base::const_iterator;

      using local_iterator = typename __hashtable_base::local_iterator;
      using const_local_iterator = typename __hashtable_base::
       const_local_iterator;






    private:
      __bucket_type* _M_buckets = &_M_single_bucket;
      size_type _M_bucket_count = 1;
      __node_base _M_before_begin;
      size_type _M_element_count = 0;
      _RehashPolicy _M_rehash_policy;







      __bucket_type _M_single_bucket = nullptr;

      bool
      _M_uses_single_bucket(__bucket_type* __bkts) const
      { return __builtin_expect(__bkts == &_M_single_bucket, false); }

      bool
      _M_uses_single_bucket() const
      { return _M_uses_single_bucket(_M_buckets); }

      __hashtable_alloc&
      _M_base_alloc() { return *this; }

      __bucket_type*
      _M_allocate_buckets(size_type __n)
      {
 if (__builtin_expect(__n == 1, false))
   {
     _M_single_bucket = nullptr;
     return &_M_single_bucket;
   }

 return __hashtable_alloc::_M_allocate_buckets(__n);
      }

      void
      _M_deallocate_buckets(__bucket_type* __bkts, size_type __n)
      {
 if (_M_uses_single_bucket(__bkts))
   return;

 __hashtable_alloc::_M_deallocate_buckets(__bkts, __n);
      }

      void
      _M_deallocate_buckets()
      { _M_deallocate_buckets(_M_buckets, _M_bucket_count); }



      __node_type*
      _M_bucket_begin(size_type __bkt) const;

      __node_type*
      _M_begin() const
      { return static_cast<__node_type*>(_M_before_begin._M_nxt); }



      template<typename _Ht, typename _NodeGenerator>
 void
 _M_assign_elements(_Ht&&, const _NodeGenerator&);

      template<typename _NodeGenerator>
 void
 _M_assign(const _Hashtable&, const _NodeGenerator&);

      void
      _M_move_assign(_Hashtable&&, std::true_type);

      void
      _M_move_assign(_Hashtable&&, std::false_type);

      void
      _M_reset() noexcept;

      _Hashtable(const _H1& __h1, const _H2& __h2, const _Hash& __h,
   const _Equal& __eq, const _ExtractKey& __exk,
   const allocator_type& __a)
 : __hashtable_base(__exk, __h1, __h2, __h, __eq),
   __hashtable_alloc(__node_alloc_type(__a))
      { }

    public:

      _Hashtable() = default;
      _Hashtable(size_type __bucket_hint,
   const _H1&, const _H2&, const _Hash&,
   const _Equal&, const _ExtractKey&,
   const allocator_type&);

      template<typename _InputIterator>
 _Hashtable(_InputIterator __first, _InputIterator __last,
     size_type __bucket_hint,
     const _H1&, const _H2&, const _Hash&,
     const _Equal&, const _ExtractKey&,
     const allocator_type&);

      _Hashtable(const _Hashtable&);

      _Hashtable(_Hashtable&&) noexcept;

      _Hashtable(const _Hashtable&, const allocator_type&);

      _Hashtable(_Hashtable&&, const allocator_type&);


      explicit
      _Hashtable(const allocator_type& __a)
 : __hashtable_alloc(__node_alloc_type(__a))
      { }

      explicit
      _Hashtable(size_type __n,
   const _H1& __hf = _H1(),
   const key_equal& __eql = key_equal(),
   const allocator_type& __a = allocator_type())
      : _Hashtable(__n, __hf, _H2(), _Hash(), __eql,
     __key_extract(), __a)
      { }

      template<typename _InputIterator>
 _Hashtable(_InputIterator __f, _InputIterator __l,
     size_type __n = 0,
     const _H1& __hf = _H1(),
     const key_equal& __eql = key_equal(),
     const allocator_type& __a = allocator_type())
 : _Hashtable(__f, __l, __n, __hf, _H2(), _Hash(), __eql,
       __key_extract(), __a)
 { }

      _Hashtable(initializer_list<value_type> __l,
   size_type __n = 0,
   const _H1& __hf = _H1(),
   const key_equal& __eql = key_equal(),
   const allocator_type& __a = allocator_type())
      : _Hashtable(__l.begin(), __l.end(), __n, __hf, _H2(), _Hash(), __eql,
     __key_extract(), __a)
      { }

      _Hashtable&
      operator=(const _Hashtable& __ht);

      _Hashtable&
      operator=(_Hashtable&& __ht)
      noexcept(__node_alloc_traits::_S_nothrow_move()
        && is_nothrow_move_assignable<_H1>::value
        && is_nothrow_move_assignable<_Equal>::value)
      {
        constexpr bool __move_storage =
   __node_alloc_traits::_S_propagate_on_move_assign()
   || __node_alloc_traits::_S_always_equal();
 _M_move_assign(std::move(__ht), __bool_constant<__move_storage>());
 return *this;
      }

      _Hashtable&
      operator=(initializer_list<value_type> __l)
      {
 __reuse_or_alloc_node_type __roan(_M_begin(), *this);
 _M_before_begin._M_nxt = nullptr;
 clear();
 this->_M_insert_range(__l.begin(), __l.end(), __roan, __unique_keys());
 return *this;
      }

      ~_Hashtable() noexcept;

      void
      swap(_Hashtable&)
      noexcept(__and_<__is_nothrow_swappable<_H1>,
                   __is_nothrow_swappable<_Equal>>::value);


      iterator
      begin() noexcept
      { return iterator(_M_begin()); }

      const_iterator
      begin() const noexcept
      { return const_iterator(_M_begin()); }

      iterator
      end() noexcept
      { return iterator(nullptr); }

      const_iterator
      end() const noexcept
      { return const_iterator(nullptr); }

      const_iterator
      cbegin() const noexcept
      { return const_iterator(_M_begin()); }

      const_iterator
      cend() const noexcept
      { return const_iterator(nullptr); }

      size_type
      size() const noexcept
      { return _M_element_count; }

      bool
      empty() const noexcept
      { return size() == 0; }

      allocator_type
      get_allocator() const noexcept
      { return allocator_type(this->_M_node_allocator()); }

      size_type
      max_size() const noexcept
      { return __node_alloc_traits::max_size(this->_M_node_allocator()); }


      key_equal
      key_eq() const
      { return this->_M_eq(); }




      size_type
      bucket_count() const noexcept
      { return _M_bucket_count; }

      size_type
      max_bucket_count() const noexcept
      { return max_size(); }

      size_type
      bucket_size(size_type __n) const
      { return std::distance(begin(__n), end(__n)); }

      size_type
      bucket(const key_type& __k) const
      { return _M_bucket_index(__k, this->_M_hash_code(__k)); }

      local_iterator
      begin(size_type __n)
      {
 return local_iterator(*this, _M_bucket_begin(__n),
         __n, _M_bucket_count);
      }

      local_iterator
      end(size_type __n)
      { return local_iterator(*this, nullptr, __n, _M_bucket_count); }

      const_local_iterator
      begin(size_type __n) const
      {
 return const_local_iterator(*this, _M_bucket_begin(__n),
        __n, _M_bucket_count);
      }

      const_local_iterator
      end(size_type __n) const
      { return const_local_iterator(*this, nullptr, __n, _M_bucket_count); }


      const_local_iterator
      cbegin(size_type __n) const
      {
 return const_local_iterator(*this, _M_bucket_begin(__n),
        __n, _M_bucket_count);
      }

      const_local_iterator
      cend(size_type __n) const
      { return const_local_iterator(*this, nullptr, __n, _M_bucket_count); }

      float
      load_factor() const noexcept
      {
 return static_cast<float>(size()) / static_cast<float>(bucket_count());
      }






      const _RehashPolicy&
      __rehash_policy() const
      { return _M_rehash_policy; }

      void
      __rehash_policy(const _RehashPolicy& __pol)
      { _M_rehash_policy = __pol; }


      iterator
      find(const key_type& __k);

      const_iterator
      find(const key_type& __k) const;

      size_type
      count(const key_type& __k) const;

      std::pair<iterator, iterator>
      equal_range(const key_type& __k);

      std::pair<const_iterator, const_iterator>
      equal_range(const key_type& __k) const;

    protected:

      size_type
      _M_bucket_index(__node_type* __n) const noexcept
      { return __hash_code_base::_M_bucket_index(__n, _M_bucket_count); }

      size_type
      _M_bucket_index(const key_type& __k, __hash_code __c) const
      { return __hash_code_base::_M_bucket_index(__k, __c, _M_bucket_count); }



      __node_base*
      _M_find_before_node(size_type, const key_type&, __hash_code) const;

      __node_type*
      _M_find_node(size_type __bkt, const key_type& __key,
     __hash_code __c) const
      {
 __node_base* __before_n = _M_find_before_node(__bkt, __key, __c);
 if (__before_n)
   return static_cast<__node_type*>(__before_n->_M_nxt);
 return nullptr;
      }


      void
      _M_insert_bucket_begin(size_type, __node_type*);


      void
      _M_remove_bucket_begin(size_type __bkt, __node_type* __next_n,
        size_type __next_bkt);


      __node_base*
      _M_get_previous_node(size_type __bkt, __node_base* __n);




      iterator
      _M_insert_unique_node(size_type __bkt, __hash_code __code,
       __node_type* __n, size_type __n_elt = 1);



      iterator
      _M_insert_multi_node(__node_type* __hint,
      __hash_code __code, __node_type* __n);

      template<typename... _Args>
 std::pair<iterator, bool>
 _M_emplace(std::true_type, _Args&&... __args);

      template<typename... _Args>
 iterator
 _M_emplace(std::false_type __uk, _Args&&... __args)
 { return _M_emplace(cend(), __uk, std::forward<_Args>(__args)...); }


      template<typename... _Args>
 iterator
 _M_emplace(const_iterator, std::true_type __uk, _Args&&... __args)
 { return _M_emplace(__uk, std::forward<_Args>(__args)...).first; }

      template<typename... _Args>
 iterator
 _M_emplace(const_iterator, std::false_type, _Args&&... __args);

      template<typename _Arg, typename _NodeGenerator>
 std::pair<iterator, bool>
 _M_insert(_Arg&&, const _NodeGenerator&, true_type, size_type = 1);

      template<typename _Arg, typename _NodeGenerator>
 iterator
 _M_insert(_Arg&& __arg, const _NodeGenerator& __node_gen,
    false_type __uk)
 {
   return _M_insert(cend(), std::forward<_Arg>(__arg), __node_gen,
      __uk);
 }


      template<typename _Arg, typename _NodeGenerator>
 iterator
 _M_insert(const_iterator, _Arg&& __arg,
    const _NodeGenerator& __node_gen, true_type __uk)
 {
   return
     _M_insert(std::forward<_Arg>(__arg), __node_gen, __uk).first;
 }


      template<typename _Arg, typename _NodeGenerator>
 iterator
 _M_insert(const_iterator, _Arg&&,
    const _NodeGenerator&, false_type);

      size_type
      _M_erase(std::true_type, const key_type&);

      size_type
      _M_erase(std::false_type, const key_type&);

      iterator
      _M_erase(size_type __bkt, __node_base* __prev_n, __node_type* __n);

    public:

      template<typename... _Args>
 __ireturn_type
 emplace(_Args&&... __args)
 { return _M_emplace(__unique_keys(), std::forward<_Args>(__args)...); }

      template<typename... _Args>
 iterator
 emplace_hint(const_iterator __hint, _Args&&... __args)
 {
   return _M_emplace(__hint, __unique_keys(),
       std::forward<_Args>(__args)...);
 }




      iterator
      erase(const_iterator);


      iterator
      erase(iterator __it)
      { return erase(const_iterator(__it)); }

      size_type
      erase(const key_type& __k)
      { return _M_erase(__unique_keys(), __k); }

      iterator
      erase(const_iterator, const_iterator);

      void
      clear() noexcept;


      void rehash(size_type __n);
# 919 "/usr/include/c++/9.2.0/bits/hashtable.h" 3
    private:

      void _M_rehash_aux(size_type __n, std::true_type);


      void _M_rehash_aux(size_type __n, std::false_type);



      void _M_rehash(size_type __n, const __rehash_state& __state);
    };



  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_bucket_begin(size_type __bkt) const
    -> __node_type*
    {
      __node_base* __n = _M_buckets[__bkt];
      return __n ? static_cast<__node_type*>(__n->_M_nxt) : nullptr;
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _Hashtable(size_type __bucket_hint,
        const _H1& __h1, const _H2& __h2, const _Hash& __h,
        const _Equal& __eq, const _ExtractKey& __exk,
        const allocator_type& __a)
      : _Hashtable(__h1, __h2, __h, __eq, __exk, __a)
    {
      auto __bkt = _M_rehash_policy._M_next_bkt(__bucket_hint);
      if (__bkt > _M_bucket_count)
 {
   _M_buckets = _M_allocate_buckets(__bkt);
   _M_bucket_count = __bkt;
 }
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    template<typename _InputIterator>
      _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
   _H1, _H2, _Hash, _RehashPolicy, _Traits>::
      _Hashtable(_InputIterator __f, _InputIterator __l,
   size_type __bucket_hint,
   const _H1& __h1, const _H2& __h2, const _Hash& __h,
   const _Equal& __eq, const _ExtractKey& __exk,
   const allocator_type& __a)
 : _Hashtable(__h1, __h2, __h, __eq, __exk, __a)
      {
 auto __nb_elems = __detail::__distance_fw(__f, __l);
 auto __bkt_count =
   _M_rehash_policy._M_next_bkt(
     std::max(_M_rehash_policy._M_bkt_for_elements(__nb_elems),
       __bucket_hint));

 if (__bkt_count > _M_bucket_count)
   {
     _M_buckets = _M_allocate_buckets(__bkt_count);
     _M_bucket_count = __bkt_count;
   }

 for (; __f != __l; ++__f)
   this->insert(*__f);
      }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    operator=(const _Hashtable& __ht)
    -> _Hashtable&
    {
      if (&__ht == this)
 return *this;

      if (__node_alloc_traits::_S_propagate_on_copy_assign())
 {
   auto& __this_alloc = this->_M_node_allocator();
   auto& __that_alloc = __ht._M_node_allocator();
   if (!__node_alloc_traits::_S_always_equal()
       && __this_alloc != __that_alloc)
     {

       this->_M_deallocate_nodes(_M_begin());
       _M_before_begin._M_nxt = nullptr;
       _M_deallocate_buckets();
       _M_buckets = nullptr;
       std::__alloc_on_copy(__this_alloc, __that_alloc);
       __hashtable_base::operator=(__ht);
       _M_bucket_count = __ht._M_bucket_count;
       _M_element_count = __ht._M_element_count;
       _M_rehash_policy = __ht._M_rehash_policy;
       try
  {
    _M_assign(__ht,
       [this](const __node_type* __n)
       { return this->_M_allocate_node(__n->_M_v()); });
  }
       catch(...)
  {


    _M_reset();
    throw;
  }
       return *this;
     }
   std::__alloc_on_copy(__this_alloc, __that_alloc);
 }


      _M_assign_elements(__ht,
 [](const __reuse_or_alloc_node_type& __roan, const __node_type* __n)
 { return __roan(__n->_M_v()); });
      return *this;
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    template<typename _Ht, typename _NodeGenerator>
      void
      _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
   _H1, _H2, _Hash, _RehashPolicy, _Traits>::
      _M_assign_elements(_Ht&& __ht, const _NodeGenerator& __node_gen)
      {
 __bucket_type* __former_buckets = nullptr;
 std::size_t __former_bucket_count = _M_bucket_count;
 const __rehash_state& __former_state = _M_rehash_policy._M_state();

 if (_M_bucket_count != __ht._M_bucket_count)
   {
     __former_buckets = _M_buckets;
     _M_buckets = _M_allocate_buckets(__ht._M_bucket_count);
     _M_bucket_count = __ht._M_bucket_count;
   }
 else
   __builtin_memset(_M_buckets, 0,
      _M_bucket_count * sizeof(__bucket_type));

 try
   {
     __hashtable_base::operator=(std::forward<_Ht>(__ht));
     _M_element_count = __ht._M_element_count;
     _M_rehash_policy = __ht._M_rehash_policy;
     __reuse_or_alloc_node_type __roan(_M_begin(), *this);
     _M_before_begin._M_nxt = nullptr;
     _M_assign(__ht,
        [&__node_gen, &__roan](__node_type* __n)
        { return __node_gen(__roan, __n); });
     if (__former_buckets)
       _M_deallocate_buckets(__former_buckets, __former_bucket_count);
   }
 catch(...)
   {
     if (__former_buckets)
       {

  _M_deallocate_buckets();
  _M_rehash_policy._M_reset(__former_state);
  _M_buckets = __former_buckets;
  _M_bucket_count = __former_bucket_count;
       }
     __builtin_memset(_M_buckets, 0,
        _M_bucket_count * sizeof(__bucket_type));
     throw;
   }
      }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    template<typename _NodeGenerator>
      void
      _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
   _H1, _H2, _Hash, _RehashPolicy, _Traits>::
      _M_assign(const _Hashtable& __ht, const _NodeGenerator& __node_gen)
      {
 __bucket_type* __buckets = nullptr;
 if (!_M_buckets)
   _M_buckets = __buckets = _M_allocate_buckets(_M_bucket_count);

 try
   {
     if (!__ht._M_before_begin._M_nxt)
       return;



     __node_type* __ht_n = __ht._M_begin();
     __node_type* __this_n = __node_gen(__ht_n);
     this->_M_copy_code(__this_n, __ht_n);
     _M_before_begin._M_nxt = __this_n;
     _M_buckets[_M_bucket_index(__this_n)] = &_M_before_begin;


     __node_base* __prev_n = __this_n;
     for (__ht_n = __ht_n->_M_next(); __ht_n; __ht_n = __ht_n->_M_next())
       {
  __this_n = __node_gen(__ht_n);
  __prev_n->_M_nxt = __this_n;
  this->_M_copy_code(__this_n, __ht_n);
  size_type __bkt = _M_bucket_index(__this_n);
  if (!_M_buckets[__bkt])
    _M_buckets[__bkt] = __prev_n;
  __prev_n = __this_n;
       }
   }
 catch(...)
   {
     clear();
     if (__buckets)
       _M_deallocate_buckets();
     throw;
   }
      }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    void
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_reset() noexcept
    {
      _M_rehash_policy._M_reset();
      _M_bucket_count = 1;
      _M_single_bucket = nullptr;
      _M_buckets = &_M_single_bucket;
      _M_before_begin._M_nxt = nullptr;
      _M_element_count = 0;
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    void
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_move_assign(_Hashtable&& __ht, std::true_type)
    {
      this->_M_deallocate_nodes(_M_begin());
      _M_deallocate_buckets();
      __hashtable_base::operator=(std::move(__ht));
      _M_rehash_policy = __ht._M_rehash_policy;
      if (!__ht._M_uses_single_bucket())
 _M_buckets = __ht._M_buckets;
      else
 {
   _M_buckets = &_M_single_bucket;
   _M_single_bucket = __ht._M_single_bucket;
 }
      _M_bucket_count = __ht._M_bucket_count;
      _M_before_begin._M_nxt = __ht._M_before_begin._M_nxt;
      _M_element_count = __ht._M_element_count;
      std::__alloc_on_move(this->_M_node_allocator(), __ht._M_node_allocator());



      if (_M_begin())
 _M_buckets[_M_bucket_index(_M_begin())] = &_M_before_begin;
      __ht._M_reset();
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    void
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_move_assign(_Hashtable&& __ht, std::false_type)
    {
      if (__ht._M_node_allocator() == this->_M_node_allocator())
 _M_move_assign(std::move(__ht), std::true_type());
      else
 {

   _M_assign_elements(std::move(__ht),
  [](const __reuse_or_alloc_node_type& __roan, __node_type* __n)
  { return __roan(std::move_if_noexcept(__n->_M_v())); });
   __ht.clear();
 }
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _Hashtable(const _Hashtable& __ht)
    : __hashtable_base(__ht),
      __map_base(__ht),
      __rehash_base(__ht),
      __hashtable_alloc(
 __node_alloc_traits::_S_select_on_copy(__ht._M_node_allocator())),
      _M_buckets(nullptr),
      _M_bucket_count(__ht._M_bucket_count),
      _M_element_count(__ht._M_element_count),
      _M_rehash_policy(__ht._M_rehash_policy)
    {
      _M_assign(__ht,
  [this](const __node_type* __n)
  { return this->_M_allocate_node(__n->_M_v()); });
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _Hashtable(_Hashtable&& __ht) noexcept
    : __hashtable_base(__ht),
      __map_base(__ht),
      __rehash_base(__ht),
      __hashtable_alloc(std::move(__ht._M_base_alloc())),
      _M_buckets(__ht._M_buckets),
      _M_bucket_count(__ht._M_bucket_count),
      _M_before_begin(__ht._M_before_begin._M_nxt),
      _M_element_count(__ht._M_element_count),
      _M_rehash_policy(__ht._M_rehash_policy)
    {

      if (__ht._M_uses_single_bucket())
 {
   _M_buckets = &_M_single_bucket;
   _M_single_bucket = __ht._M_single_bucket;
 }



      if (_M_begin())
 _M_buckets[_M_bucket_index(_M_begin())] = &_M_before_begin;

      __ht._M_reset();
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _Hashtable(const _Hashtable& __ht, const allocator_type& __a)
    : __hashtable_base(__ht),
      __map_base(__ht),
      __rehash_base(__ht),
      __hashtable_alloc(__node_alloc_type(__a)),
      _M_buckets(),
      _M_bucket_count(__ht._M_bucket_count),
      _M_element_count(__ht._M_element_count),
      _M_rehash_policy(__ht._M_rehash_policy)
    {
      _M_assign(__ht,
  [this](const __node_type* __n)
  { return this->_M_allocate_node(__n->_M_v()); });
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _Hashtable(_Hashtable&& __ht, const allocator_type& __a)
    : __hashtable_base(__ht),
      __map_base(__ht),
      __rehash_base(__ht),
      __hashtable_alloc(__node_alloc_type(__a)),
      _M_buckets(nullptr),
      _M_bucket_count(__ht._M_bucket_count),
      _M_element_count(__ht._M_element_count),
      _M_rehash_policy(__ht._M_rehash_policy)
    {
      if (__ht._M_node_allocator() == this->_M_node_allocator())
 {
   if (__ht._M_uses_single_bucket())
     {
       _M_buckets = &_M_single_bucket;
       _M_single_bucket = __ht._M_single_bucket;
     }
   else
     _M_buckets = __ht._M_buckets;

   _M_before_begin._M_nxt = __ht._M_before_begin._M_nxt;


   if (_M_begin())
     _M_buckets[_M_bucket_index(_M_begin())] = &_M_before_begin;
   __ht._M_reset();
 }
      else
 {
   _M_assign(__ht,
      [this](__node_type* __n)
      {
        return this->_M_allocate_node(
     std::move_if_noexcept(__n->_M_v()));
      });
   __ht.clear();
 }
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    ~_Hashtable() noexcept
    {
      clear();
      _M_deallocate_buckets();
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    void
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    swap(_Hashtable& __x)
    noexcept(__and_<__is_nothrow_swappable<_H1>,
                 __is_nothrow_swappable<_Equal>>::value)
    {



      this->_M_swap(__x);

      std::__alloc_on_swap(this->_M_node_allocator(), __x._M_node_allocator());
      std::swap(_M_rehash_policy, __x._M_rehash_policy);


      if (this->_M_uses_single_bucket())
 {
   if (!__x._M_uses_single_bucket())
     {
       _M_buckets = __x._M_buckets;
       __x._M_buckets = &__x._M_single_bucket;
     }
 }
      else if (__x._M_uses_single_bucket())
 {
   __x._M_buckets = _M_buckets;
   _M_buckets = &_M_single_bucket;
 }
      else
 std::swap(_M_buckets, __x._M_buckets);

      std::swap(_M_bucket_count, __x._M_bucket_count);
      std::swap(_M_before_begin._M_nxt, __x._M_before_begin._M_nxt);
      std::swap(_M_element_count, __x._M_element_count);
      std::swap(_M_single_bucket, __x._M_single_bucket);



      if (_M_begin())
 _M_buckets[_M_bucket_index(_M_begin())] = &_M_before_begin;

      if (__x._M_begin())
 __x._M_buckets[__x._M_bucket_index(__x._M_begin())]
   = &__x._M_before_begin;
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    find(const key_type& __k)
    -> iterator
    {
      __hash_code __code = this->_M_hash_code(__k);
      std::size_t __n = _M_bucket_index(__k, __code);
      __node_type* __p = _M_find_node(__n, __k, __code);
      return __p ? iterator(__p) : end();
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    find(const key_type& __k) const
    -> const_iterator
    {
      __hash_code __code = this->_M_hash_code(__k);
      std::size_t __n = _M_bucket_index(__k, __code);
      __node_type* __p = _M_find_node(__n, __k, __code);
      return __p ? const_iterator(__p) : end();
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    count(const key_type& __k) const
    -> size_type
    {
      __hash_code __code = this->_M_hash_code(__k);
      std::size_t __n = _M_bucket_index(__k, __code);
      __node_type* __p = _M_bucket_begin(__n);
      if (!__p)
 return 0;

      std::size_t __result = 0;
      for (;; __p = __p->_M_next())
 {
   if (this->_M_equals(__k, __code, __p))
     ++__result;
   else if (__result)



     break;
   if (!__p->_M_nxt || _M_bucket_index(__p->_M_next()) != __n)
     break;
 }
      return __result;
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    equal_range(const key_type& __k)
    -> pair<iterator, iterator>
    {
      __hash_code __code = this->_M_hash_code(__k);
      std::size_t __n = _M_bucket_index(__k, __code);
      __node_type* __p = _M_find_node(__n, __k, __code);

      if (__p)
 {
   __node_type* __p1 = __p->_M_next();
   while (__p1 && _M_bucket_index(__p1) == __n
   && this->_M_equals(__k, __code, __p1))
     __p1 = __p1->_M_next();

   return std::make_pair(iterator(__p), iterator(__p1));
 }
      else
 return std::make_pair(end(), end());
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    equal_range(const key_type& __k) const
    -> pair<const_iterator, const_iterator>
    {
      __hash_code __code = this->_M_hash_code(__k);
      std::size_t __n = _M_bucket_index(__k, __code);
      __node_type* __p = _M_find_node(__n, __k, __code);

      if (__p)
 {
   __node_type* __p1 = __p->_M_next();
   while (__p1 && _M_bucket_index(__p1) == __n
   && this->_M_equals(__k, __code, __p1))
     __p1 = __p1->_M_next();

   return std::make_pair(const_iterator(__p), const_iterator(__p1));
 }
      else
 return std::make_pair(end(), end());
    }



  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_find_before_node(size_type __n, const key_type& __k,
   __hash_code __code) const
    -> __node_base*
    {
      __node_base* __prev_p = _M_buckets[__n];
      if (!__prev_p)
 return nullptr;

      for (__node_type* __p = static_cast<__node_type*>(__prev_p->_M_nxt);;
    __p = __p->_M_next())
 {
   if (this->_M_equals(__k, __code, __p))
     return __prev_p;

   if (!__p->_M_nxt || _M_bucket_index(__p->_M_next()) != __n)
     break;
   __prev_p = __p;
 }
      return nullptr;
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    void
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_insert_bucket_begin(size_type __bkt, __node_type* __node)
    {
      if (_M_buckets[__bkt])
 {


   __node->_M_nxt = _M_buckets[__bkt]->_M_nxt;
   _M_buckets[__bkt]->_M_nxt = __node;
 }
      else
 {



   __node->_M_nxt = _M_before_begin._M_nxt;
   _M_before_begin._M_nxt = __node;
   if (__node->_M_nxt)


     _M_buckets[_M_bucket_index(__node->_M_next())] = __node;
   _M_buckets[__bkt] = &_M_before_begin;
 }
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    void
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_remove_bucket_begin(size_type __bkt, __node_type* __next,
      size_type __next_bkt)
    {
      if (!__next || __next_bkt != __bkt)
 {


   if (__next)
     _M_buckets[__next_bkt] = _M_buckets[__bkt];


   if (&_M_before_begin == _M_buckets[__bkt])
     _M_before_begin._M_nxt = __next;
   _M_buckets[__bkt] = nullptr;
 }
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_get_previous_node(size_type __bkt, __node_base* __n)
    -> __node_base*
    {
      __node_base* __prev_n = _M_buckets[__bkt];
      while (__prev_n->_M_nxt != __n)
 __prev_n = __prev_n->_M_nxt;
      return __prev_n;
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    template<typename... _Args>
      auto
      _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
   _H1, _H2, _Hash, _RehashPolicy, _Traits>::
      _M_emplace(std::true_type, _Args&&... __args)
      -> pair<iterator, bool>
      {

 __node_type* __node = this->_M_allocate_node(std::forward<_Args>(__args)...);
 const key_type& __k = this->_M_extract()(__node->_M_v());
 __hash_code __code;
 try
   {
     __code = this->_M_hash_code(__k);
   }
 catch(...)
   {
     this->_M_deallocate_node(__node);
     throw;
   }

 size_type __bkt = _M_bucket_index(__k, __code);
 if (__node_type* __p = _M_find_node(__bkt, __k, __code))
   {

     this->_M_deallocate_node(__node);
     return std::make_pair(iterator(__p), false);
   }


 return std::make_pair(_M_insert_unique_node(__bkt, __code, __node),
         true);
      }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    template<typename... _Args>
      auto
      _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
   _H1, _H2, _Hash, _RehashPolicy, _Traits>::
      _M_emplace(const_iterator __hint, std::false_type, _Args&&... __args)
      -> iterator
      {

 __node_type* __node =
   this->_M_allocate_node(std::forward<_Args>(__args)...);

 __hash_code __code;
 try
   {
     __code = this->_M_hash_code(this->_M_extract()(__node->_M_v()));
   }
 catch(...)
   {
     this->_M_deallocate_node(__node);
     throw;
   }

 return _M_insert_multi_node(__hint._M_cur, __code, __node);
      }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_insert_unique_node(size_type __bkt, __hash_code __code,
     __node_type* __node, size_type __n_elt)
    -> iterator
    {
      const __rehash_state& __saved_state = _M_rehash_policy._M_state();
      std::pair<bool, std::size_t> __do_rehash
 = _M_rehash_policy._M_need_rehash(_M_bucket_count, _M_element_count,
       __n_elt);

      try
 {
   if (__do_rehash.first)
     {
       _M_rehash(__do_rehash.second, __saved_state);
       __bkt = _M_bucket_index(this->_M_extract()(__node->_M_v()), __code);
     }

   this->_M_store_code(__node, __code);


   _M_insert_bucket_begin(__bkt, __node);
   ++_M_element_count;
   return iterator(__node);
 }
      catch(...)
 {
   this->_M_deallocate_node(__node);
   throw;
 }
    }



  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_insert_multi_node(__node_type* __hint, __hash_code __code,
    __node_type* __node)
    -> iterator
    {
      const __rehash_state& __saved_state = _M_rehash_policy._M_state();
      std::pair<bool, std::size_t> __do_rehash
 = _M_rehash_policy._M_need_rehash(_M_bucket_count, _M_element_count, 1);

      try
 {
   if (__do_rehash.first)
     _M_rehash(__do_rehash.second, __saved_state);

   this->_M_store_code(__node, __code);
   const key_type& __k = this->_M_extract()(__node->_M_v());
   size_type __bkt = _M_bucket_index(__k, __code);



   __node_base* __prev
     = __builtin_expect(__hint != nullptr, false)
       && this->_M_equals(__k, __code, __hint)
  ? __hint
  : _M_find_before_node(__bkt, __k, __code);
   if (__prev)
     {

       __node->_M_nxt = __prev->_M_nxt;
       __prev->_M_nxt = __node;
       if (__builtin_expect(__prev == __hint, false))


        if (__node->_M_nxt
            && !this->_M_equals(__k, __code, __node->_M_next()))
          {
            size_type __next_bkt = _M_bucket_index(__node->_M_next());
            if (__next_bkt != __bkt)
              _M_buckets[__next_bkt] = __node;
          }
     }
   else




     _M_insert_bucket_begin(__bkt, __node);
   ++_M_element_count;
   return iterator(__node);
 }
      catch(...)
 {
   this->_M_deallocate_node(__node);
   throw;
 }
    }


  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    template<typename _Arg, typename _NodeGenerator>
      auto
      _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
   _H1, _H2, _Hash, _RehashPolicy, _Traits>::
      _M_insert(_Arg&& __v, const _NodeGenerator& __node_gen, true_type,
  size_type __n_elt)
      -> pair<iterator, bool>
      {
 const key_type& __k = this->_M_extract()(__v);
 __hash_code __code = this->_M_hash_code(__k);
 size_type __bkt = _M_bucket_index(__k, __code);

 __node_type* __n = _M_find_node(__bkt, __k, __code);
 if (__n)
   return std::make_pair(iterator(__n), false);

 __n = __node_gen(std::forward<_Arg>(__v));
 return { _M_insert_unique_node(__bkt, __code, __n, __n_elt), true };
      }


  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    template<typename _Arg, typename _NodeGenerator>
      auto
      _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
   _H1, _H2, _Hash, _RehashPolicy, _Traits>::
      _M_insert(const_iterator __hint, _Arg&& __v,
  const _NodeGenerator& __node_gen, false_type)
      -> iterator
      {


 __hash_code __code = this->_M_hash_code(this->_M_extract()(__v));


 __node_type* __node = __node_gen(std::forward<_Arg>(__v));

 return _M_insert_multi_node(__hint._M_cur, __code, __node);
      }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    erase(const_iterator __it)
    -> iterator
    {
      __node_type* __n = __it._M_cur;
      std::size_t __bkt = _M_bucket_index(__n);




      __node_base* __prev_n = _M_get_previous_node(__bkt, __n);
      return _M_erase(__bkt, __prev_n, __n);
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_erase(size_type __bkt, __node_base* __prev_n, __node_type* __n)
    -> iterator
    {
      if (__prev_n == _M_buckets[__bkt])
 _M_remove_bucket_begin(__bkt, __n->_M_next(),
    __n->_M_nxt ? _M_bucket_index(__n->_M_next()) : 0);
      else if (__n->_M_nxt)
 {
   size_type __next_bkt = _M_bucket_index(__n->_M_next());
   if (__next_bkt != __bkt)
     _M_buckets[__next_bkt] = __prev_n;
 }

      __prev_n->_M_nxt = __n->_M_nxt;
      iterator __result(__n->_M_next());
      this->_M_deallocate_node(__n);
      --_M_element_count;

      return __result;
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_erase(std::true_type, const key_type& __k)
    -> size_type
    {
      __hash_code __code = this->_M_hash_code(__k);
      std::size_t __bkt = _M_bucket_index(__k, __code);


      __node_base* __prev_n = _M_find_before_node(__bkt, __k, __code);
      if (!__prev_n)
 return 0;


      __node_type* __n = static_cast<__node_type*>(__prev_n->_M_nxt);
      _M_erase(__bkt, __prev_n, __n);
      return 1;
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_erase(std::false_type, const key_type& __k)
    -> size_type
    {
      __hash_code __code = this->_M_hash_code(__k);
      std::size_t __bkt = _M_bucket_index(__k, __code);


      __node_base* __prev_n = _M_find_before_node(__bkt, __k, __code);
      if (!__prev_n)
 return 0;







      __node_type* __n = static_cast<__node_type*>(__prev_n->_M_nxt);
      __node_type* __n_last = __n;
      std::size_t __n_last_bkt = __bkt;
      do
 {
   __n_last = __n_last->_M_next();
   if (!__n_last)
     break;
   __n_last_bkt = _M_bucket_index(__n_last);
 }
      while (__n_last_bkt == __bkt && this->_M_equals(__k, __code, __n_last));


      size_type __result = 0;
      do
 {
   __node_type* __p = __n->_M_next();
   this->_M_deallocate_node(__n);
   __n = __p;
   ++__result;
   --_M_element_count;
 }
      while (__n != __n_last);

      if (__prev_n == _M_buckets[__bkt])
 _M_remove_bucket_begin(__bkt, __n_last, __n_last_bkt);
      else if (__n_last && __n_last_bkt != __bkt)
 _M_buckets[__n_last_bkt] = __prev_n;
      __prev_n->_M_nxt = __n_last;
      return __result;
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    auto
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    erase(const_iterator __first, const_iterator __last)
    -> iterator
    {
      __node_type* __n = __first._M_cur;
      __node_type* __last_n = __last._M_cur;
      if (__n == __last_n)
 return iterator(__n);

      std::size_t __bkt = _M_bucket_index(__n);

      __node_base* __prev_n = _M_get_previous_node(__bkt, __n);
      bool __is_bucket_begin = __n == _M_bucket_begin(__bkt);
      std::size_t __n_bkt = __bkt;
      for (;;)
 {
   do
     {
       __node_type* __tmp = __n;
       __n = __n->_M_next();
       this->_M_deallocate_node(__tmp);
       --_M_element_count;
       if (!__n)
  break;
       __n_bkt = _M_bucket_index(__n);
     }
   while (__n != __last_n && __n_bkt == __bkt);
   if (__is_bucket_begin)
     _M_remove_bucket_begin(__bkt, __n, __n_bkt);
   if (__n == __last_n)
     break;
   __is_bucket_begin = true;
   __bkt = __n_bkt;
 }

      if (__n && (__n_bkt != __bkt || __is_bucket_begin))
 _M_buckets[__n_bkt] = __prev_n;
      __prev_n->_M_nxt = __n;
      return iterator(__n);
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    void
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    clear() noexcept
    {
      this->_M_deallocate_nodes(_M_begin());
      __builtin_memset(_M_buckets, 0, _M_bucket_count * sizeof(__bucket_type));
      _M_element_count = 0;
      _M_before_begin._M_nxt = nullptr;
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    void
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    rehash(size_type __n)
    {
      const __rehash_state& __saved_state = _M_rehash_policy._M_state();
      std::size_t __buckets
 = std::max(_M_rehash_policy._M_bkt_for_elements(_M_element_count + 1),
     __n);
      __buckets = _M_rehash_policy._M_next_bkt(__buckets);

      if (__buckets != _M_bucket_count)
 _M_rehash(__buckets, __saved_state);
      else

 _M_rehash_policy._M_reset(__saved_state);
    }

  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    void
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_rehash(size_type __n, const __rehash_state& __state)
    {
      try
 {
   _M_rehash_aux(__n, __unique_keys());
 }
      catch(...)
 {


   _M_rehash_policy._M_reset(__state);
   throw;
 }
    }


  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    void
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_rehash_aux(size_type __n, std::true_type)
    {
      __bucket_type* __new_buckets = _M_allocate_buckets(__n);
      __node_type* __p = _M_begin();
      _M_before_begin._M_nxt = nullptr;
      std::size_t __bbegin_bkt = 0;
      while (__p)
 {
   __node_type* __next = __p->_M_next();
   std::size_t __bkt = __hash_code_base::_M_bucket_index(__p, __n);
   if (!__new_buckets[__bkt])
     {
       __p->_M_nxt = _M_before_begin._M_nxt;
       _M_before_begin._M_nxt = __p;
       __new_buckets[__bkt] = &_M_before_begin;
       if (__p->_M_nxt)
  __new_buckets[__bbegin_bkt] = __p;
       __bbegin_bkt = __bkt;
     }
   else
     {
       __p->_M_nxt = __new_buckets[__bkt]->_M_nxt;
       __new_buckets[__bkt]->_M_nxt = __p;
     }
   __p = __next;
 }

      _M_deallocate_buckets();
      _M_bucket_count = __n;
      _M_buckets = __new_buckets;
    }



  template<typename _Key, typename _Value,
    typename _Alloc, typename _ExtractKey, typename _Equal,
    typename _H1, typename _H2, typename _Hash, typename _RehashPolicy,
    typename _Traits>
    void
    _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal,
        _H1, _H2, _Hash, _RehashPolicy, _Traits>::
    _M_rehash_aux(size_type __n, std::false_type)
    {
      __bucket_type* __new_buckets = _M_allocate_buckets(__n);

      __node_type* __p = _M_begin();
      _M_before_begin._M_nxt = nullptr;
      std::size_t __bbegin_bkt = 0;
      std::size_t __prev_bkt = 0;
      __node_type* __prev_p = nullptr;
      bool __check_bucket = false;

      while (__p)
 {
   __node_type* __next = __p->_M_next();
   std::size_t __bkt = __hash_code_base::_M_bucket_index(__p, __n);

   if (__prev_p && __prev_bkt == __bkt)
     {



       __p->_M_nxt = __prev_p->_M_nxt;
       __prev_p->_M_nxt = __p;






       __check_bucket = true;
     }
   else
     {
       if (__check_bucket)
  {


    if (__prev_p->_M_nxt)
      {
        std::size_t __next_bkt
   = __hash_code_base::_M_bucket_index(__prev_p->_M_next(),
           __n);
        if (__next_bkt != __prev_bkt)
   __new_buckets[__next_bkt] = __prev_p;
      }
    __check_bucket = false;
  }

       if (!__new_buckets[__bkt])
  {
    __p->_M_nxt = _M_before_begin._M_nxt;
    _M_before_begin._M_nxt = __p;
    __new_buckets[__bkt] = &_M_before_begin;
    if (__p->_M_nxt)
      __new_buckets[__bbegin_bkt] = __p;
    __bbegin_bkt = __bkt;
  }
       else
  {
    __p->_M_nxt = __new_buckets[__bkt]->_M_nxt;
    __new_buckets[__bkt]->_M_nxt = __p;
  }
     }
   __prev_p = __p;
   __prev_bkt = __bkt;
   __p = __next;
 }

      if (__check_bucket && __prev_p->_M_nxt)
 {
   std::size_t __next_bkt
     = __hash_code_base::_M_bucket_index(__prev_p->_M_next(), __n);
   if (__next_bkt != __prev_bkt)
     __new_buckets[__next_bkt] = __prev_p;
 }

      _M_deallocate_buckets();
      _M_bucket_count = __n;
      _M_buckets = __new_buckets;
    }
# 2219 "/usr/include/c++/9.2.0/bits/hashtable.h" 3

}
# 47 "/usr/include/c++/9.2.0/unordered_map" 2 3
# 1 "/usr/include/c++/9.2.0/bits/unordered_map.h" 1 3
# 33 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
namespace std __attribute__ ((__visibility__ ("default")))
{




  template<bool _Cache>
    using __umap_traits = __detail::_Hashtable_traits<_Cache, false, true>;

  template<typename _Key,
    typename _Tp,
    typename _Hash = hash<_Key>,
    typename _Pred = std::equal_to<_Key>,
    typename _Alloc = std::allocator<std::pair<const _Key, _Tp> >,
    typename _Tr = __umap_traits<__cache_default<_Key, _Hash>::value>>
    using __umap_hashtable = _Hashtable<_Key, std::pair<const _Key, _Tp>,
                                        _Alloc, __detail::_Select1st,
            _Pred, _Hash,
            __detail::_Mod_range_hashing,
            __detail::_Default_ranged_hash,
            __detail::_Prime_rehash_policy, _Tr>;


  template<bool _Cache>
    using __ummap_traits = __detail::_Hashtable_traits<_Cache, false, false>;

  template<typename _Key,
    typename _Tp,
    typename _Hash = hash<_Key>,
    typename _Pred = std::equal_to<_Key>,
    typename _Alloc = std::allocator<std::pair<const _Key, _Tp> >,
    typename _Tr = __ummap_traits<__cache_default<_Key, _Hash>::value>>
    using __ummap_hashtable = _Hashtable<_Key, std::pair<const _Key, _Tp>,
      _Alloc, __detail::_Select1st,
      _Pred, _Hash,
      __detail::_Mod_range_hashing,
      __detail::_Default_ranged_hash,
      __detail::_Prime_rehash_policy, _Tr>;

  template<class _Key, class _Tp, class _Hash, class _Pred, class _Alloc>
    class unordered_multimap;
# 98 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
  template<typename _Key, typename _Tp,
    typename _Hash = hash<_Key>,
    typename _Pred = equal_to<_Key>,
    typename _Alloc = allocator<std::pair<const _Key, _Tp>>>
    class unordered_map
    {
      typedef __umap_hashtable<_Key, _Tp, _Hash, _Pred, _Alloc> _Hashtable;
      _Hashtable _M_h;

    public:



      typedef typename _Hashtable::key_type key_type;
      typedef typename _Hashtable::value_type value_type;
      typedef typename _Hashtable::mapped_type mapped_type;
      typedef typename _Hashtable::hasher hasher;
      typedef typename _Hashtable::key_equal key_equal;
      typedef typename _Hashtable::allocator_type allocator_type;




      typedef typename _Hashtable::pointer pointer;
      typedef typename _Hashtable::const_pointer const_pointer;
      typedef typename _Hashtable::reference reference;
      typedef typename _Hashtable::const_reference const_reference;
      typedef typename _Hashtable::iterator iterator;
      typedef typename _Hashtable::const_iterator const_iterator;
      typedef typename _Hashtable::local_iterator local_iterator;
      typedef typename _Hashtable::const_local_iterator const_local_iterator;
      typedef typename _Hashtable::size_type size_type;
      typedef typename _Hashtable::difference_type difference_type;
# 141 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      unordered_map() = default;
# 150 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      explicit
      unordered_map(size_type __n,
      const hasher& __hf = hasher(),
      const key_equal& __eql = key_equal(),
      const allocator_type& __a = allocator_type())
      : _M_h(__n, __hf, __eql, __a)
      { }
# 171 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      template<typename _InputIterator>
 unordered_map(_InputIterator __first, _InputIterator __last,
        size_type __n = 0,
        const hasher& __hf = hasher(),
        const key_equal& __eql = key_equal(),
        const allocator_type& __a = allocator_type())
 : _M_h(__first, __last, __n, __hf, __eql, __a)
 { }


      unordered_map(const unordered_map&) = default;


      unordered_map(unordered_map&&) = default;





      explicit
      unordered_map(const allocator_type& __a)
 : _M_h(__a)
      { }






      unordered_map(const unordered_map& __umap,
      const allocator_type& __a)
      : _M_h(__umap._M_h, __a)
      { }






      unordered_map(unordered_map&& __umap,
      const allocator_type& __a)
      : _M_h(std::move(__umap._M_h), __a)
      { }
# 226 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      unordered_map(initializer_list<value_type> __l,
      size_type __n = 0,
      const hasher& __hf = hasher(),
      const key_equal& __eql = key_equal(),
      const allocator_type& __a = allocator_type())
      : _M_h(__l, __n, __hf, __eql, __a)
      { }

      unordered_map(size_type __n, const allocator_type& __a)
      : unordered_map(__n, hasher(), key_equal(), __a)
      { }

      unordered_map(size_type __n, const hasher& __hf,
      const allocator_type& __a)
      : unordered_map(__n, __hf, key_equal(), __a)
      { }

      template<typename _InputIterator>
 unordered_map(_InputIterator __first, _InputIterator __last,
        size_type __n,
        const allocator_type& __a)
 : unordered_map(__first, __last, __n, hasher(), key_equal(), __a)
 { }

      template<typename _InputIterator>
 unordered_map(_InputIterator __first, _InputIterator __last,
        size_type __n, const hasher& __hf,
        const allocator_type& __a)
   : unordered_map(__first, __last, __n, __hf, key_equal(), __a)
 { }

      unordered_map(initializer_list<value_type> __l,
      size_type __n,
      const allocator_type& __a)
      : unordered_map(__l, __n, hasher(), key_equal(), __a)
      { }

      unordered_map(initializer_list<value_type> __l,
      size_type __n, const hasher& __hf,
      const allocator_type& __a)
      : unordered_map(__l, __n, __hf, key_equal(), __a)
      { }


      unordered_map&
      operator=(const unordered_map&) = default;


      unordered_map&
      operator=(unordered_map&&) = default;
# 288 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      unordered_map&
      operator=(initializer_list<value_type> __l)
      {
 _M_h = __l;
 return *this;
      }


      allocator_type
      get_allocator() const noexcept
      { return _M_h.get_allocator(); }




      bool
      empty() const noexcept
      { return _M_h.empty(); }


      size_type
      size() const noexcept
      { return _M_h.size(); }


      size_type
      max_size() const noexcept
      { return _M_h.max_size(); }







      iterator
      begin() noexcept
      { return _M_h.begin(); }






      const_iterator
      begin() const noexcept
      { return _M_h.begin(); }

      const_iterator
      cbegin() const noexcept
      { return _M_h.begin(); }






      iterator
      end() noexcept
      { return _M_h.end(); }






      const_iterator
      end() const noexcept
      { return _M_h.end(); }

      const_iterator
      cend() const noexcept
      { return _M_h.end(); }
# 385 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      template<typename... _Args>
 std::pair<iterator, bool>
 emplace(_Args&&... __args)
 { return _M_h.emplace(std::forward<_Args>(__args)...); }
# 416 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      template<typename... _Args>
 iterator
 emplace_hint(const_iterator __pos, _Args&&... __args)
 { return _M_h.emplace_hint(__pos, std::forward<_Args>(__args)...); }
# 578 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      std::pair<iterator, bool>
      insert(const value_type& __x)
      { return _M_h.insert(__x); }



      std::pair<iterator, bool>
      insert(value_type&& __x)
      { return _M_h.insert(std::move(__x)); }

      template<typename _Pair>
 __enable_if_t<is_constructible<value_type, _Pair&&>::value,
        pair<iterator, bool>>
 insert(_Pair&& __x)
        { return _M_h.emplace(std::forward<_Pair>(__x)); }
# 617 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      iterator
      insert(const_iterator __hint, const value_type& __x)
      { return _M_h.insert(__hint, __x); }



      iterator
      insert(const_iterator __hint, value_type&& __x)
      { return _M_h.insert(__hint, std::move(__x)); }

      template<typename _Pair>
 __enable_if_t<is_constructible<value_type, _Pair&&>::value, iterator>
 insert(const_iterator __hint, _Pair&& __x)
 { return _M_h.emplace_hint(__hint, std::forward<_Pair>(__x)); }
# 642 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      template<typename _InputIterator>
 void
 insert(_InputIterator __first, _InputIterator __last)
 { _M_h.insert(__first, __last); }
# 654 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      void
      insert(initializer_list<value_type> __l)
      { _M_h.insert(__l); }
# 791 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      iterator
      erase(const_iterator __position)
      { return _M_h.erase(__position); }


      iterator
      erase(iterator __position)
      { return _M_h.erase(__position); }
# 813 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      size_type
      erase(const key_type& __x)
      { return _M_h.erase(__x); }
# 831 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      iterator
      erase(const_iterator __first, const_iterator __last)
      { return _M_h.erase(__first, __last); }







      void
      clear() noexcept
      { _M_h.clear(); }
# 855 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      void
      swap(unordered_map& __x)
      noexcept( noexcept(_M_h.swap(__x._M_h)) )
      { _M_h.swap(__x._M_h); }
# 895 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      hasher
      hash_function() const
      { return _M_h.hash_function(); }



      key_equal
      key_eq() const
      { return _M_h.key_eq(); }
# 919 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      iterator
      find(const key_type& __x)
      { return _M_h.find(__x); }

      const_iterator
      find(const key_type& __x) const
      { return _M_h.find(__x); }
# 937 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      size_type
      count(const key_type& __x) const
      { return _M_h.count(__x); }
# 961 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      std::pair<iterator, iterator>
      equal_range(const key_type& __x)
      { return _M_h.equal_range(__x); }

      std::pair<const_iterator, const_iterator>
      equal_range(const key_type& __x) const
      { return _M_h.equal_range(__x); }
# 983 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      mapped_type&
      operator[](const key_type& __k)
      { return _M_h[__k]; }

      mapped_type&
      operator[](key_type&& __k)
      { return _M_h[std::move(__k)]; }
# 1000 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      mapped_type&
      at(const key_type& __k)
      { return _M_h.at(__k); }

      const mapped_type&
      at(const key_type& __k) const
      { return _M_h.at(__k); }





      size_type
      bucket_count() const noexcept
      { return _M_h.bucket_count(); }


      size_type
      max_bucket_count() const noexcept
      { return _M_h.max_bucket_count(); }






      size_type
      bucket_size(size_type __n) const
      { return _M_h.bucket_size(__n); }






      size_type
      bucket(const key_type& __key) const
      { return _M_h.bucket(__key); }







      local_iterator
      begin(size_type __n)
      { return _M_h.begin(__n); }
# 1056 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      const_local_iterator
      begin(size_type __n) const
      { return _M_h.begin(__n); }

      const_local_iterator
      cbegin(size_type __n) const
      { return _M_h.cbegin(__n); }
# 1071 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      local_iterator
      end(size_type __n)
      { return _M_h.end(__n); }
# 1082 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      const_local_iterator
      end(size_type __n) const
      { return _M_h.end(__n); }

      const_local_iterator
      cend(size_type __n) const
      { return _M_h.cend(__n); }





      float
      load_factor() const noexcept
      { return _M_h.load_factor(); }



      float
      max_load_factor() const noexcept
      { return _M_h.max_load_factor(); }





      void
      max_load_factor(float __z)
      { _M_h.max_load_factor(__z); }
# 1119 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      void
      rehash(size_type __n)
      { _M_h.rehash(__n); }
# 1130 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      void
      reserve(size_type __n)
      { _M_h.reserve(__n); }

      template<typename _Key1, typename _Tp1, typename _Hash1, typename _Pred1,
        typename _Alloc1>
        friend bool
 operator==(const unordered_map<_Key1, _Tp1, _Hash1, _Pred1, _Alloc1>&,
     const unordered_map<_Key1, _Tp1, _Hash1, _Pred1, _Alloc1>&);
    };
# 1246 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
  template<typename _Key, typename _Tp,
    typename _Hash = hash<_Key>,
    typename _Pred = equal_to<_Key>,
    typename _Alloc = allocator<std::pair<const _Key, _Tp>>>
    class unordered_multimap
    {
      typedef __ummap_hashtable<_Key, _Tp, _Hash, _Pred, _Alloc> _Hashtable;
      _Hashtable _M_h;

    public:



      typedef typename _Hashtable::key_type key_type;
      typedef typename _Hashtable::value_type value_type;
      typedef typename _Hashtable::mapped_type mapped_type;
      typedef typename _Hashtable::hasher hasher;
      typedef typename _Hashtable::key_equal key_equal;
      typedef typename _Hashtable::allocator_type allocator_type;




      typedef typename _Hashtable::pointer pointer;
      typedef typename _Hashtable::const_pointer const_pointer;
      typedef typename _Hashtable::reference reference;
      typedef typename _Hashtable::const_reference const_reference;
      typedef typename _Hashtable::iterator iterator;
      typedef typename _Hashtable::const_iterator const_iterator;
      typedef typename _Hashtable::local_iterator local_iterator;
      typedef typename _Hashtable::const_local_iterator const_local_iterator;
      typedef typename _Hashtable::size_type size_type;
      typedef typename _Hashtable::difference_type difference_type;
# 1288 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      unordered_multimap() = default;
# 1297 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      explicit
      unordered_multimap(size_type __n,
    const hasher& __hf = hasher(),
    const key_equal& __eql = key_equal(),
    const allocator_type& __a = allocator_type())
      : _M_h(__n, __hf, __eql, __a)
      { }
# 1318 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      template<typename _InputIterator>
 unordered_multimap(_InputIterator __first, _InputIterator __last,
      size_type __n = 0,
      const hasher& __hf = hasher(),
      const key_equal& __eql = key_equal(),
      const allocator_type& __a = allocator_type())
 : _M_h(__first, __last, __n, __hf, __eql, __a)
 { }


      unordered_multimap(const unordered_multimap&) = default;


      unordered_multimap(unordered_multimap&&) = default;





      explicit
      unordered_multimap(const allocator_type& __a)
      : _M_h(__a)
      { }






      unordered_multimap(const unordered_multimap& __ummap,
    const allocator_type& __a)
      : _M_h(__ummap._M_h, __a)
      { }






      unordered_multimap(unordered_multimap&& __ummap,
    const allocator_type& __a)
      : _M_h(std::move(__ummap._M_h), __a)
      { }
# 1373 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      unordered_multimap(initializer_list<value_type> __l,
    size_type __n = 0,
    const hasher& __hf = hasher(),
    const key_equal& __eql = key_equal(),
    const allocator_type& __a = allocator_type())
      : _M_h(__l, __n, __hf, __eql, __a)
      { }

      unordered_multimap(size_type __n, const allocator_type& __a)
      : unordered_multimap(__n, hasher(), key_equal(), __a)
      { }

      unordered_multimap(size_type __n, const hasher& __hf,
    const allocator_type& __a)
      : unordered_multimap(__n, __hf, key_equal(), __a)
      { }

      template<typename _InputIterator>
 unordered_multimap(_InputIterator __first, _InputIterator __last,
      size_type __n,
      const allocator_type& __a)
 : unordered_multimap(__first, __last, __n, hasher(), key_equal(), __a)
 { }

      template<typename _InputIterator>
 unordered_multimap(_InputIterator __first, _InputIterator __last,
      size_type __n, const hasher& __hf,
      const allocator_type& __a)
 : unordered_multimap(__first, __last, __n, __hf, key_equal(), __a)
 { }

      unordered_multimap(initializer_list<value_type> __l,
    size_type __n,
    const allocator_type& __a)
      : unordered_multimap(__l, __n, hasher(), key_equal(), __a)
      { }

      unordered_multimap(initializer_list<value_type> __l,
    size_type __n, const hasher& __hf,
    const allocator_type& __a)
      : unordered_multimap(__l, __n, __hf, key_equal(), __a)
      { }


      unordered_multimap&
      operator=(const unordered_multimap&) = default;


      unordered_multimap&
      operator=(unordered_multimap&&) = default;
# 1435 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      unordered_multimap&
      operator=(initializer_list<value_type> __l)
      {
 _M_h = __l;
 return *this;
      }


      allocator_type
      get_allocator() const noexcept
      { return _M_h.get_allocator(); }




      bool
      empty() const noexcept
      { return _M_h.empty(); }


      size_type
      size() const noexcept
      { return _M_h.size(); }


      size_type
      max_size() const noexcept
      { return _M_h.max_size(); }







      iterator
      begin() noexcept
      { return _M_h.begin(); }






      const_iterator
      begin() const noexcept
      { return _M_h.begin(); }

      const_iterator
      cbegin() const noexcept
      { return _M_h.begin(); }






      iterator
      end() noexcept
      { return _M_h.end(); }






      const_iterator
      end() const noexcept
      { return _M_h.end(); }

      const_iterator
      cend() const noexcept
      { return _M_h.end(); }
# 1527 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      template<typename... _Args>
 iterator
 emplace(_Args&&... __args)
 { return _M_h.emplace(std::forward<_Args>(__args)...); }
# 1554 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      template<typename... _Args>
 iterator
 emplace_hint(const_iterator __pos, _Args&&... __args)
 { return _M_h.emplace_hint(__pos, std::forward<_Args>(__args)...); }
# 1569 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      iterator
      insert(const value_type& __x)
      { return _M_h.insert(__x); }

      iterator
      insert(value_type&& __x)
      { return _M_h.insert(std::move(__x)); }

      template<typename _Pair>
 __enable_if_t<is_constructible<value_type, _Pair&&>::value, iterator>
 insert(_Pair&& __x)
        { return _M_h.emplace(std::forward<_Pair>(__x)); }
# 1603 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      iterator
      insert(const_iterator __hint, const value_type& __x)
      { return _M_h.insert(__hint, __x); }



      iterator
      insert(const_iterator __hint, value_type&& __x)
      { return _M_h.insert(__hint, std::move(__x)); }

      template<typename _Pair>
 __enable_if_t<is_constructible<value_type, _Pair&&>::value, iterator>
 insert(const_iterator __hint, _Pair&& __x)
        { return _M_h.emplace_hint(__hint, std::forward<_Pair>(__x)); }
# 1628 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      template<typename _InputIterator>
 void
 insert(_InputIterator __first, _InputIterator __last)
 { _M_h.insert(__first, __last); }
# 1641 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      void
      insert(initializer_list<value_type> __l)
      { _M_h.insert(__l); }
# 1684 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      iterator
      erase(const_iterator __position)
      { return _M_h.erase(__position); }


      iterator
      erase(iterator __position)
      { return _M_h.erase(__position); }
# 1705 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      size_type
      erase(const key_type& __x)
      { return _M_h.erase(__x); }
# 1724 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      iterator
      erase(const_iterator __first, const_iterator __last)
      { return _M_h.erase(__first, __last); }







      void
      clear() noexcept
      { _M_h.clear(); }
# 1748 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      void
      swap(unordered_multimap& __x)
      noexcept( noexcept(_M_h.swap(__x._M_h)) )
      { _M_h.swap(__x._M_h); }
# 1790 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      hasher
      hash_function() const
      { return _M_h.hash_function(); }



      key_equal
      key_eq() const
      { return _M_h.key_eq(); }
# 1814 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      iterator
      find(const key_type& __x)
      { return _M_h.find(__x); }

      const_iterator
      find(const key_type& __x) const
      { return _M_h.find(__x); }







      size_type
      count(const key_type& __x) const
      { return _M_h.count(__x); }
# 1850 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      std::pair<iterator, iterator>
      equal_range(const key_type& __x)
      { return _M_h.equal_range(__x); }

      std::pair<const_iterator, const_iterator>
      equal_range(const key_type& __x) const
      { return _M_h.equal_range(__x); }





      size_type
      bucket_count() const noexcept
      { return _M_h.bucket_count(); }


      size_type
      max_bucket_count() const noexcept
      { return _M_h.max_bucket_count(); }






      size_type
      bucket_size(size_type __n) const
      { return _M_h.bucket_size(__n); }






      size_type
      bucket(const key_type& __key) const
      { return _M_h.bucket(__key); }







      local_iterator
      begin(size_type __n)
      { return _M_h.begin(__n); }
# 1906 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      const_local_iterator
      begin(size_type __n) const
      { return _M_h.begin(__n); }

      const_local_iterator
      cbegin(size_type __n) const
      { return _M_h.cbegin(__n); }
# 1921 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      local_iterator
      end(size_type __n)
      { return _M_h.end(__n); }
# 1932 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      const_local_iterator
      end(size_type __n) const
      { return _M_h.end(__n); }

      const_local_iterator
      cend(size_type __n) const
      { return _M_h.cend(__n); }





      float
      load_factor() const noexcept
      { return _M_h.load_factor(); }



      float
      max_load_factor() const noexcept
      { return _M_h.max_load_factor(); }





      void
      max_load_factor(float __z)
      { _M_h.max_load_factor(__z); }
# 1969 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      void
      rehash(size_type __n)
      { _M_h.rehash(__n); }
# 1980 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
      void
      reserve(size_type __n)
      { _M_h.reserve(__n); }

      template<typename _Key1, typename _Tp1, typename _Hash1, typename _Pred1,
        typename _Alloc1>
        friend bool
 operator==(const unordered_multimap<_Key1, _Tp1,
         _Hash1, _Pred1, _Alloc1>&,
     const unordered_multimap<_Key1, _Tp1,
         _Hash1, _Pred1, _Alloc1>&);
    };
# 2075 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3
  template<class _Key, class _Tp, class _Hash, class _Pred, class _Alloc>
    inline void
    swap(unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>& __x,
  unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>& __y)
    noexcept(noexcept(__x.swap(__y)))
    { __x.swap(__y); }

  template<class _Key, class _Tp, class _Hash, class _Pred, class _Alloc>
    inline void
    swap(unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>& __x,
  unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>& __y)
    noexcept(noexcept(__x.swap(__y)))
    { __x.swap(__y); }

  template<class _Key, class _Tp, class _Hash, class _Pred, class _Alloc>
    inline bool
    operator==(const unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>& __x,
        const unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>& __y)
    { return __x._M_h._M_equal(__y._M_h); }

  template<class _Key, class _Tp, class _Hash, class _Pred, class _Alloc>
    inline bool
    operator!=(const unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>& __x,
        const unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>& __y)
    { return !(__x == __y); }

  template<class _Key, class _Tp, class _Hash, class _Pred, class _Alloc>
    inline bool
    operator==(const unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>& __x,
        const unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>& __y)
    { return __x._M_h._M_equal(__y._M_h); }

  template<class _Key, class _Tp, class _Hash, class _Pred, class _Alloc>
    inline bool
    operator!=(const unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>& __x,
        const unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>& __y)
    { return !(__x == __y); }


# 2165 "/usr/include/c++/9.2.0/bits/unordered_map.h" 3

}
# 48 "/usr/include/c++/9.2.0/unordered_map" 2 3

# 1 "/usr/include/c++/9.2.0/bits/erase_if.h" 1 3
# 33 "/usr/include/c++/9.2.0/bits/erase_if.h" 3
       
# 34 "/usr/include/c++/9.2.0/bits/erase_if.h" 3



namespace std
{






  namespace __detail
  {
    template<typename _Container, typename _Predicate>
      typename _Container::size_type
      __erase_nodes_if(_Container& __cont, _Predicate __pred)
      {
 typename _Container::size_type __num = 0;
 for (auto __iter = __cont.begin(), __last = __cont.end();
      __iter != __last;)
   {
     if (__pred(*__iter))
       {
  __iter = __cont.erase(__iter);
  ++__num;
       }
     else
       ++__iter;
   }
 return __num;
      }
  }


}
# 50 "/usr/include/c++/9.2.0/unordered_map" 2 3
# 4 "myhook.h" 2
# 1 "/usr/include/sys/mman.h" 1 3 4
# 25 "/usr/include/sys/mman.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/9.2.0/include/stddef.h" 1 3 4
# 26 "/usr/include/sys/mman.h" 2 3 4
# 41 "/usr/include/sys/mman.h" 3 4
# 1 "/usr/include/bits/mman.h" 1 3 4
# 31 "/usr/include/bits/mman.h" 3 4
# 1 "/usr/include/bits/mman-map-flags-generic.h" 1 3 4
# 32 "/usr/include/bits/mman.h" 2 3 4


# 1 "/usr/include/bits/mman-linux.h" 1 3 4
# 111 "/usr/include/bits/mman-linux.h" 3 4
# 1 "/usr/include/bits/mman-shared.h" 1 3 4
# 46 "/usr/include/bits/mman-shared.h" 3 4
extern "C" {



int memfd_create (const char *__name, unsigned int __flags) throw ();



int mlock2 (const void *__addr, size_t __length, unsigned int __flags) throw ();





int pkey_alloc (unsigned int __flags, unsigned int __access_rights) throw ();



int pkey_set (int __key, unsigned int __access_rights) throw ();



int pkey_get (int __key) throw ();



int pkey_free (int __key) throw ();



int pkey_mprotect (void *__addr, size_t __len, int __prot, int __pkey) throw ();

}
# 111 "/usr/include/bits/mman-linux.h" 2 3 4
# 34 "/usr/include/bits/mman.h" 2 3 4
# 42 "/usr/include/sys/mman.h" 2 3 4




extern "C" {
# 57 "/usr/include/sys/mman.h" 3 4
extern void *mmap (void *__addr, size_t __len, int __prot,
     int __flags, int __fd, __off_t __offset) throw ();
# 70 "/usr/include/sys/mman.h" 3 4
extern void *mmap64 (void *__addr, size_t __len, int __prot,
       int __flags, int __fd, __off64_t __offset) throw ();




extern int munmap (void *__addr, size_t __len) throw ();




extern int mprotect (void *__addr, size_t __len, int __prot) throw ();







extern int msync (void *__addr, size_t __len, int __flags);




extern int madvise (void *__addr, size_t __len, int __advice) throw ();



extern int posix_madvise (void *__addr, size_t __len, int __advice) throw ();




extern int mlock (const void *__addr, size_t __len) throw ();


extern int munlock (const void *__addr, size_t __len) throw ();




extern int mlockall (int __flags) throw ();



extern int munlockall (void) throw ();







extern int mincore (void *__start, size_t __len, unsigned char *__vec)
     throw ();
# 133 "/usr/include/sys/mman.h" 3 4
extern void *mremap (void *__addr, size_t __old_len, size_t __new_len,
       int __flags, ...) throw ();



extern int remap_file_pages (void *__start, size_t __size, int __prot,
        size_t __pgoff, int __flags) throw ();




extern int shm_open (const char *__name, int __oflag, mode_t __mode);


extern int shm_unlink (const char *__name);

}
# 5 "myhook.h" 2




# 8 "myhook.h"
void* MyHook(void* oldunc, void* newfunc);
char* wr_jmp(void* addr);
typedef uint64_t u64;
char* wr_regcmd(void* call,void* arg);
# 3 "cmdhelper.h" 2
