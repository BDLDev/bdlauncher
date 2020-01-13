#include "myhook.h"
#include "hook.h"
#include <cassert>
#include <global.h>
#include <type_traits>

template <size_t size> struct StrictMem {
  char *current;

  INLINE StrictMem(char *ptr) { current = ptr; }
  template <size_t use> INLINE auto operator<<(char const (&data)[use]) -> StrictMem<size - use + 1> {
    static_assert(size >= use - 1);
    memcpy(current, data, use - 1);
    return {current + use - 1};
  }
  template <typename T>
  INLINE auto operator<<(T addr) -> std::enable_if_t<std::is_same_v<T, void *>, StrictMem<size - sizeof(void*)>> {
    static_assert(size >= sizeof(void*));
    memcpy(current, &addr, sizeof(void*));
    return {current + sizeof(void*)};
  }
  INLINE operator char *() { return current; }
};

template <size_t base> class AutoGrowMem {
  char *current, *top;

  INLINE void realloc() {
    current =
        static_cast<char *>(mmap(0, base, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
    assert(current);
    top = current + base;
  }

public:
  INLINE AutoGrowMem() { realloc(); }

  template <size_t use> INLINE StrictMem<use> alloc() {
    static_assert(use < base);
    if (current + use > top) realloc();
    auto tmp = current;
    current += use;
    return {tmp};
  }
};

static AutoGrowMem<65536> jmpbed;
// extern std::unordered_map<void*,char*> my_hooks;
char *wr_jmp(void *addr) {
  auto mem = jmpbed.alloc<16>();
  mem << "\xff\x25\x00\x00\x00\x00" << addr;
  return mem;
}
char *wr_regcmd(void *call, void *arg) {
  /*
     0x0000000000001190 <+0>:	57	push   rdi
 0x0000000000001191 <+1>:	48 b8 77 77 77 77 ff ff ff ff	movabs rax,0xffffffff77777777
 0x000000000000119b <+11>:	48 bf 77 77 77 77 ff ff ff ff	movabs rdi,0xffffffff77777777
 0x00000000000011a5 <+21>:	ff d0	call   rax
 0x00000000000011a7 <+23>:	5f	pop    rdi
 0x00000000000011a8 <+24>:	48 89 07	mov    QWORD PTR [rdi],rax
 0x00000000000011ab <+27>:	48 89 f8	mov    rax,rdi
 0x00000000000011ae <+30>:	c3	ret
 */
  auto mem = jmpbed.alloc<32>();
  mem << "\x57\x48\xb8" << call << "\x48\xbf" << arg << "\xff\xd0\x5f\x48\x89\x07\x48\x89\xf8\xc3";
  return mem;
}
void MyPatch(void *oldfunc, void *newfunc, size_t size) {
  auto start = ROUND_PAGE_DOWN((size_t) oldfunc);
  auto end   = ROUND_PAGE_UP((size_t) oldfunc + size);
  mprotect((void *) start, end - start, PROT_READ | PROT_WRITE | PROT_EXEC);
  memcpy(oldfunc, newfunc, size);
  mprotect((void *) start, end - start, PROT_READ | PROT_EXEC);
}
void *MyHook(void *oldfunc, void *newfunc) {
  void *ret;
  int res = HookIt(oldfunc, &ret, newfunc);
  if (res != 0) { printf("error hooking %p\n", oldfunc); }
  return ret;
}
