#pragma once

#include <cstdint>

#define DSDebug char const *sourceFile, uint32_t sourceLine

namespace DataStructures {
using BitSize_t = uint32_t;

class ByteQueue {
public:
  ByteQueue();
  ~ByteQueue();
  void WriteBytes(const char *in, unsigned length, DSDebug);
  bool ReadBytes(char *out, unsigned length, bool peek);
  unsigned GetBytesWritten(void) const;
  void IncrementReadOffset(unsigned length);
  void Clear(DSDebug);
  void Print(void);

protected:
  char *data;
  unsigned readOffset, writeOffset, lengthAllocated;
};

template <class T> class CircularLinkedList {
public:
  struct node {
    T item;

    node *previous;
    node *next;
  };

  CircularLinkedList();
  ~CircularLinkedList();
  CircularLinkedList(const CircularLinkedList &original_copy);
  bool operator=(const CircularLinkedList &original_copy);
  CircularLinkedList &operator++();    // CircularLinkedList A; ++A;
  CircularLinkedList &operator++(int); // Circular_Linked List A; A++;
  CircularLinkedList &operator--();    // CircularLinkedList A; --A;
  CircularLinkedList &operator--(int); // Circular_Linked List A; A--;
  bool IsIn(const T &input);
  bool Find(const T &input);
  void Insert(const T &input);
  T &Add(const T &input);
  void Replace(const T &input);
  void Del(void);
  unsigned int Size(void);
  T &Peek(void);
  T Pop(void);
  void Clear(void);
  void Sort(void);
  void Beginning(void);
  void End(void);
  void Concatenate(const CircularLinkedList &L);

protected:
  unsigned int list_size;
  node *root;
  node *position;
  node *FindPointer(const T &input);

private:
  CircularLinkedList Merge(CircularLinkedList L1, CircularLinkedList L2);
  CircularLinkedList Mergesort(const CircularLinkedList &L);
};
template <class T> class LinkedList : public CircularLinkedList<T> {
public:
  LinkedList();
  LinkedList(const LinkedList &original_copy);
  ~LinkedList();
  bool operator=(const LinkedList<T> &original_copy);
  LinkedList &operator++();
  LinkedList &operator++(int);
  LinkedList &operator--();
  LinkedList &operator--(int);

private:
  LinkedList Merge(LinkedList L1, LinkedList L2);
  LinkedList Mergesort(const LinkedList &L);
};
template <class T> class List {
public:
  List();
  ~List();
  List(const List &original_copy);
  List &operator=(const List &original_copy);
  T &operator[](const unsigned int position) const;
  T &Get(const unsigned int position) const;
  void Push(const T input, DSDebug);
  T &Pop(void);
  void Insert(const T input, const unsigned int position, DSDebug);
  void Insert(const T input, DSDebug);
  void Replace(const T input, const T filler, const unsigned int position);
  void Replace(const T input);
  void RemoveAtIndex(const unsigned int position);
  void RemoveAtIndexFast(const unsigned int position);
  void RemoveFromEnd(const unsigned num = 1);
  unsigned int GetIndexOf(const T input) const;
  unsigned int Size(void) const;
  void Clear(bool doNotDeallocateSmallBlocks, DSDebug);
  void Preallocate(unsigned countNeeded, DSDebug);
  void Compress(void);

private:
  T *listArray;
  unsigned int list_size;
  unsigned int allocation_size;
};
template <class K, class V, bool isMaxHeap> class Heap {
public:
  struct HeapNode {
    HeapNode() {}
    HeapNode(const K &w, const V &d)
        : weight(w)
        , data(d) {}
    K weight; // I'm assuming key is a native numerical type - float or int
    V data;
  };

  Heap();
  ~Heap();
  void Push(const K &weight, const V &data, const char *file, unsigned int line);
  /// Call before calling PushSeries, for a new series of items
  void StartSeries(void) { optimizeNextSeriesPush = false; }
  /// If you are going to push a list of items, where the weights of the items on the list are in order and follow the heap order, PushSeries is faster than Push()
  void PushSeries(const K &weight, const V &data, const char *file, unsigned int line);
  V Pop(const unsigned startingIndex);
  V Peek(const unsigned startingIndex = 0) const;
  K PeekWeight(const unsigned startingIndex = 0) const;
  void Clear(bool doNotDeallocateSmallBlocks, const char *file, unsigned int line);
  V &operator[](const unsigned int position) const;
  unsigned Size(void) const;

protected:
  unsigned LeftChild(const unsigned i) const;
  unsigned RightChild(const unsigned i) const;
  unsigned Parent(const unsigned i) const;
  void Swap(const unsigned i, const unsigned j);
  DataStructures::List<HeapNode> heap;
  bool optimizeNextSeriesPush;
};
template <class K, class V> int defaultOrderedListComparison(const K &a, const V &b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}
template <class K, class V, int (*default_comparison_function)(const K &, const V &) = defaultOrderedListComparison<K, V>> class OrderedList {
public:
  OrderedList();
  ~OrderedList();
  OrderedList(const OrderedList &original_copy);
  OrderedList &operator=(const OrderedList &original_copy);

  bool HasData(const K &key, int (*cf)(const K &, const V &) = default_comparison_function) const;
  unsigned GetIndexFromKey(const K &key, bool *objectExists, int (*cf)(const K &, const V &) = default_comparison_function) const;
  V GetElementFromKey(const K &key, int (*cf)(const K &, const V &) = default_comparison_function) const;
  bool GetElementFromKey(const K &key, V &element, int (*cf)(const K &, const V &) = default_comparison_function) const;
  unsigned Insert(const K &key, const V &data, bool assertOnDuplicate, DSDebug, int (*cf)(const K &, const V &) = default_comparison_function);
  unsigned Remove(const K &key, int (*cf)(const K &, const V &) = default_comparison_function);
  unsigned RemoveIfExists(const K &key, int (*cf)(const K &, const V &) = default_comparison_function);
  V &operator[](const unsigned int position) const;
  void RemoveAtIndex(const unsigned index);
  void InsertAtIndex(const V &data, const unsigned index, DSDebug);
  void InsertAtEnd(const V &data, DSDebug);
  void RemoveFromEnd(const unsigned num = 1);
  void Clear(bool doNotDeallocate, DSDebug);
  unsigned Size(void) const;

protected:
  DataStructures::List<V> orderedList;
};
template <class key_type> int defaultMapKeyComparison(const key_type &a, const key_type &b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}
template <class K, class V, int (*key_comparison_func)(const K &, const K &) = defaultMapKeyComparison<K>> class Map {
public:
  static void IMPLEMENT_DEFAULT_COMPARISON(void) { DataStructures::defaultMapKeyComparison<K>(K(), K()); }
  struct MapNode {
    MapNode() {}
    MapNode(K _key, V _data)
        : mapNodeKey(_key)
        , mapNodeData(_data) {}
    MapNode &operator=(const MapNode &input) {
      mapNodeKey  = input.mapNodeKey;
      mapNodeData = input.mapNodeData;
      return *this;
    }
    MapNode(const MapNode &input) {
      mapNodeKey  = input.mapNodeKey;
      mapNodeData = input.mapNodeData;
    }
    K mapNodeKey;
    V mapNodeData;
  };
  static int NodeComparisonFunc(const K &a, const MapNode &b) { return key_comparison_func(a, b.mapNodeKey); }

  Map();
  ~Map();
  Map(const Map &original_copy);
  Map &operator=(const Map &original_copy);

  V &Get(const K &key);
  V Pop(const K &key);
  void Set(const K &key, const V &data);
  void SetExisting(const K &key, const V &data);
  void SetNew(const K &key, const V &data);
  bool Has(const K &key);
  bool Delete(const K &key);
  V &operator[](const unsigned int position) const;
  K GetKeyAtIndex(const unsigned int position) const;
  unsigned GetIndexAtKey(const K &key);
  void RemoveAtIndex(const unsigned index);
  void Clear(void);
  unsigned Size(void) const;

protected:
  DataStructures::OrderedList<K, MapNode, Map::NodeComparisonFunc> mapNodeList;

  void SaveLastSearch(const K &key, unsigned index);
  bool HasSavedSearchResult(const K &key) const;

  unsigned lastSearchIndex;
  K lastSearchKey;
  bool lastSearchIndexValid;
};
template <class T> class MemoryPool {
public:
  struct Page;
  struct MemoryWithPage {
    T userMemory;
    Page *parentPage;
  };

  struct Page {
    MemoryWithPage **availableStack;
    int availableStackSize;
    MemoryWithPage *block;
    Page *next, *prev;
  };

  MemoryPool();
  ~MemoryPool();
  void SetPageSize(int size);
  T *Allocate(DSDebug);
  void Release(T *m, DSDebug);
  void Clear(DSDebug);

  int GetAvailablePagesSize(void) const { return availablePagesSize; }
  int GetUnavailablePagesSize(void) const { return unavailablePagesSize; }
  int GetMemoryPoolPageSize(void) const { return memoryPoolPageSize; }

protected:
  int BlocksPerPage(void) const;
  void AllocateFirst(void);
  bool InitPage(Page *page, Page *prev, DSDebug);
  Page *availablePages, *unavailablePages;
  int availablePagesSize, unavailablePagesSize;
  int memoryPoolPageSize;
};
template <class T> class Queue {
public:
  Queue();
  ~Queue();
  Queue(Queue &original_copy);
  bool operator=(const Queue &original_copy);
  void Push(const T &input, DSDebug);
  void PushAtHead(const T &input, unsigned index, DSDebug);
  T &operator[](unsigned int position) const;
  void RemoveAtIndex(unsigned int position);
  inline T Peek(void) const;
  inline T PeekTail(void) const;
  inline T Pop(void);
  inline unsigned int Size(void) const;
  inline bool IsEmpty(void) const;
  inline unsigned int AllocationSize(void) const;
  inline void Clear(DSDebug);
  void Compress(void);
  bool Find(T q);
  void ClearAndForceAllocation(int size, DSDebug);

private:
  T *array;
  unsigned int head;
  unsigned int tail;
  unsigned int allocation_size;
};

template <class T> struct RangeNode {
  RangeNode() {}
  ~RangeNode() {}
  RangeNode(T min, T max) {
    minIndex = min;
    maxIndex = max;
  }
  T minIndex;
  T maxIndex;
};

template <class T> int RangeNodeComp(const T &a, const RangeNode<T> &b) {
  if (a < b.minIndex) return -1;
  if (a == b.minIndex) return 0;
  return 1;
}
template <class T> class RangeList {
public:
  RangeList();
  ~RangeList();
  void Insert(T index);
  void Clear(void);
  unsigned Size(void) const;
  unsigned RangeSum(void) const;
  BitSize_t Serialize(RakNet::BitStream *in, BitSize_t maxBits, bool clearSerialized);
  bool Deserialize(RakNet::BitStream *out);

  DataStructures::OrderedList<T, RangeNode<T>, RangeNodeComp<T>> ranges;
};

template <class T> class ThreadsafeAllocatingQueue {
public:
  void Push(T *s);
  T *PopInaccurate(void);
  T *Pop(void);
  void SetPageSize(int size);
  bool IsEmpty(void);
  T *operator[](unsigned int position);
  void RemoveAtIndex(unsigned int position);
  unsigned int Size(void);

  T *Allocate(DSDebug);
  void Deallocate(T *s, DSDebug);
  void Clear(DSDebug);

protected:
  mutable MemoryPool<T> memoryPool;
  pthread_mutex_t memoryPoolMutex; // SimpleMutex
  Queue<T *> queue;
  pthread_mutex_t queueMutex; // SimpleMutex
};

} // namespace DataStructures

#undef DSDebug