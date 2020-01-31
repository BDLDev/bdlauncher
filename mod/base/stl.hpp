#pragma once
#define unlikely(cond) __glibc_unlikely(!!(cond))
#define likely(cond) __glibc_likely(!!(cond))
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string_view>
#include <string>
#include <cstring>
#include <list>
#include <logger.h>
using std::string;
using std::string_view;
template <typename T, const int S = 96, const int SZ_MAX = sizeof(T) * S> struct static_deque {
  char data[SZ_MAX];
  uint head, tail;
  inline T *begin() { return ((T *) data) + head; }
  inline T *end() { return ((T *) data) + tail; }
  inline void clear() {
    T *res = (T *) data;
    for (decltype(tail) i = head; i < tail; ++i) res[i].~T();
    head = tail = 0;
  }
  static_deque() { clear(); }
  inline void push_back(const T &a) { ((T *) data)[tail++] = a; }
  template <typename... Params> inline void emplace_back(Params &&... params) {
    T *res = &(((T *) data)[tail++]);
    new (res) T(std::forward<Params>(params)...);
  }
  inline T &top() { return ((T *) data)[head]; }
  inline void pop_top() {
    top().~T();
    head++;
  }
  inline T &back() { return ((T *) data)[tail - 1]; }
  inline void pop_back() {
    back().~T();
    tail--;
  }
  inline int size() const { return tail - head; }
  inline bool empty() { return size() == 0; }
  inline bool full() { return size() == S; }
  inline const T &operator[](const int idx) const { return ((T *) data)[idx]; }
  inline T &operator[](const int idx) { return ((T *) data)[idx]; }
  inline int count(const T &x) const {
    int cnt = 0;
    for (decltype(tail) i = head; i != tail; ++i) {
      if (((T *) data)[i] == x) cnt++;
    }
    return cnt;
  }
  inline int has(const T &x) const {
    for (decltype(tail) i = head; i != tail; ++i) {
      if (((T *) data)[i] == x) return true;
    }
    return false;
  }
};
template <typename T, int INIT_SIZE = 8, int MAX_SIZE = 64> struct AllocPool {
  static_deque<T *, MAX_SIZE> sq;
  AllocPool() {
    for (int i = 0; i < INIT_SIZE; ++i) {
      auto x = malloc(sizeof(T));
      sq.push_back((T *) x);
    }
  }
  inline T *__get() {
    if (sq.empty()) {
      return (T *) malloc(sizeof(T));
    } else {
      auto r = sq.back();
      sq.pop_back();
      return r;
    }
  }
  inline void __free(T *x) {
    if (sq.full()) {
      free(x);
    } else {
      sq.push_back(x);
    }
  }
  template <typename... Params> inline T *get(Params &&... params) {
    auto res = __get();
    return new (res) T(std::forward<Params>(params)...);
  }
  inline void release(T *x) {
    x->~T();
    __free(x);
  }
};

constexpr int atoi(string_view sv) {
  int res       = 0;
  int fg        = 0;
  const char *c = sv.data();
  int sz        = sv.size();
  for (int i = 0; i < sz; ++i) {
    if (c[i] == '-') { fg = 1; }
    if (!(c[i] >= '0' && c[i] <= '9')) continue;
    res *= 10;
    res += c[i] - '0';
  }
  return fg ? -res : res;
}

using std::list;
using std::unordered_map;
using std::vector;
class DataStream {
public:
  std::string dat;
  int curpos = 0;
  void reset() {
    dat    = "";
    curpos = 0;
  }
  const char *getData() const { return dat.c_str(); }
  DataStream &operator<<(string const &c) {
    (*this) << (int) c.size();
    dat.append(c);
    return *this;
  }
  DataStream &operator<<(DataStream const &c) {
    dat.append(c.getData());
    return *this;
  }
  template <typename T> DataStream &operator<<(vector<T> const &c) {
    int size = c.size();
    (*this) << size;
    for (auto const &i : c) { (*this) << i; }
    return *this;
  }
  template <typename T> DataStream &operator<<(list<T> const &c) {
    int size = c.size();
    (*this) << size;
    for (auto const &i : c) { (*this) << i; }
    return *this;
  }
  template <typename T, typename std::enable_if<!std::is_class<T>{}, int>::type = 0>
  DataStream &operator<<(T const &c) {
    dat.append((const char *) &c, sizeof(c));
    return *this;
  }
  template <typename T, typename std::enable_if<std::is_class<T>{}, int>::type = 0> DataStream &operator<<(T const &c) {
    c.packto(*this);
    return *this;
  }
  template <typename T, typename T2> DataStream &operator<<(unordered_map<T, T2> const &c) {
    operator<<((int) c.size());
    for (auto &i : c) {
      operator<<(i.first);
      operator<<(i.second);
    }
    return *this;
  }
  template <typename T, typename T2> DataStream &operator>>(unordered_map<T, T2> &c) {
    int sz;
    operator>>(sz);
    c.reserve(sz);
    for (int i = 0; i < sz; ++i) {
      T tmp;
      T2 tmp2;
      operator>>(tmp);
      operator>>(tmp2);
      c[tmp] = tmp2;
    }
    return *this;
  }
  DataStream &operator>>(string &c) {
    int sz;
    (*this) >> sz;
    c.reserve(sz);
    c.assign(dat.data() + curpos, sz);
    curpos += sz;
    return *this;
  }
  template <typename T, typename std::enable_if<!std::is_class<T>{}, int>::type = 0> DataStream &operator>>(T &c) {
    std::memcpy(&c, dat.data() + curpos, sizeof(c));
    curpos += sizeof(c);
    return *this;
  }
  template <typename T, typename std::enable_if<std::is_class<T>{}, int>::type = 0> DataStream &operator>>(T &c) {
    c.unpack(*this);
    return *this;
  }
  template <typename T> DataStream &operator>>(vector<T> &c) {
    int size;
    (*this) >> size;
    c.reserve(size);
    for (int i = 0; i < size; ++i) {
      T tmp;
      (*this) >> tmp;
      c.emplace_back(tmp);
    }
    return *this;
  }
  template <typename T> DataStream &operator>>(list<T> &c) {
    int size;
    (*this) >> size;
    for (int i = 0; i < size; ++i) {
      T tmp;
      (*this) >> tmp;
      c.emplace_back(tmp);
    }
    return *this;
  }
};
struct FileBuffer {
  size_t size;
  char *data;
  FileBuffer(const char *fn) {
    int fd = open(fn, O_RDONLY);
    if (fd == -1) {
      do_log("cannot open %s", fn);
      perror("open");
      size = 0;
      data = nullptr;
      return;
    }
    size = lseek(fd, 0, SEEK_END);
    data = (char *) malloc(size + 1);
    pread(fd, data, size, 0);
    data[size] = 0; // auto zero-terminated string
    close(fd);
  }
  ~FileBuffer() {
    if (data) free(data);
  }
  inline string_view getsv() { return {data, size}; }
  inline string getstr() { return {data, size}; }
};

/*
struct MStr{

    union v
    {
        string str;
        string_view sv;
    };

}
template<typename K,typename V>
struct StrMap{
    std::unordered_map<string_view,V> mp;
    AllocPool<string,4,64> AP;
    StrMap(){}
    int count(string_view sv) const{
        return mp.find(sv)!=mp.end();
    }
    auto begin(){
        return mp.begin();
    }
    auto end(){
        return mp.end();
    }
    std::size_t size() const{
        return mp.size();
    }
    auto find(string_view sv){
        return mp.find(sv);
    }
    auto find(string_view sv) const{
        return mp.find(sv);
    }
    V&& operator(string_view sv){
        auto it=mp.find(sv);
        if(it==mp.end()){
            //build new
            auto strAP.get
        }
    }
};*/
/*
template<typename K,typename V>
class FastMap{
    typedef unsigned long HASH_T;
    struct Node{
        struct Node* prev;
        struct Node* next;
        K key;
        V val;
    };
    Node* pool;
    unsigned int pool_sz;
    unsigned int elem_sz;
    FastMap(){
        pool=malloc(4*sizeof(Node));

    }
}*/
