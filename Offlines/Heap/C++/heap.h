#include <cassert>
#include <cstdlib>
#include <vector>

#define assertm(exp, msg) assert(((void)msg, exp))

inline int LEFT(int x) { return x << 1; }
inline int RIGHT(int x) { return (x << 1) | 1; }
inline int PARENT(int x) { return x >> 1; }

inline void swap(int& a, int& b) { b = (a + b) - (a = b); }

class Heap {
 private:
  int* arr;
  int maxSize;
  int len;
  void MAX_HEAPIFY(int idx) {
    if (idx < 1) return;
    int left = LEFT(idx);
    int right = RIGHT(idx);
    int largest = arr[idx];
    int largest_pos = idx;
    if (left <= len && arr[left] > largest) {
      largest = arr[left];
      largest_pos = left;
    }
    if (right <= len && arr[right] > largest) {
      largest = arr[right];
      largest_pos = right;
    }
    if (largest_pos != idx) {
      swap(arr[idx], arr[largest_pos]);
      MAX_HEAPIFY(largest_pos);
    }
  }

 public:
  Heap(int sz) {
    maxSize = sz;
    len = 0;
    arr = new int[maxSize + 1];
  }
  Heap(std::vector<int>& vec) {
    maxSize = (int)vec.size();
    arr = new int[maxSize + 1];
    for (int i = 0; i < maxSize; i++) {
      arr[i + 1] = vec[i];
    }
    len = maxSize;
    for (int i = (maxSize + 1) << 1; i >= 1; i--) MAX_HEAPIFY(i);
  }
  Heap(const Heap& other) {
    maxSize = other.maxSize;
    len = other.len;
    arr = new int[maxSize];
    for (int i = 0; i < maxSize; i++) {
      arr[i] = other.arr[i];
    }
  }
  ~Heap() {
    delete[] arr;
    len = 0;
  }
  Heap& operator=(const Heap& other) {
    if (this == &other) return *this;
    maxSize = other.maxSize;
    len = other.len;
    arr = new int[maxSize];
    for (int i = 0; i < maxSize; i++) {
      arr[i] = other.arr[i];
    }
  }
  void insert(int x) {
    arr[++len] = x;
    int idx = len;
    int parent;
    while (idx > 1) {
      parent = PARENT(idx);
      if (x > arr[parent]) {
        swap(arr[idx], arr[parent]);
        idx = parent;
      } else
        break;
    }
  }
  void deleteKey() {
    if (len == 0) return;
    assertm(len > 0, "Empty heap");
    swap(arr[1], arr[len]);
    len--;
    MAX_HEAPIFY(1);
  }
  inline int getMax() const {
    assertm(len > 0, "Empty heap");
    return arr[1];
  }
  inline int size() const { return len; }
  friend std::ostream& operator<<(std::ostream& out, const Heap& h) {
    for (int i = 1; i <= h.len; i++) out << h.arr[i] << " ";
    out << "\n";
    return out;
  }
};

void heapsort(std::vector<int>& v) {
  Heap h(v);
  int sz = (int)v.size();
  for (int i = 0; i < sz; i++) {
    v[i] = h.getMax();
    h.deleteKey();
  }
}