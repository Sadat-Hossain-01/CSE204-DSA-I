#include <cassert>
#include <cstdlib>
#include <vector>

#define endl "\n"
#define assertm(exp, msg) assert(((void)msg, exp))

using namespace std;

inline void swap(int &a, int &b) { b = (a + b) - (a = b); }
inline int generateRandomNumber(int a, int b) {
  // [a, b]
  return rand() % (b - a + 1) + a;
}

void printVector(vector<int> &vec) {
  for (auto &i : vec) cerr << i << " ";
  cerr << endl;
}

void merge(vector<int> &vec, int l, int mid, int r) {
  // assertm(l >= 0 && r < (int)vec.size(), "Merge Sort Index Out of Bounds");
  int len1 = mid - l + 1;
  int len2 = r - mid;
  vector<int> v1(vec.begin() + l, vec.begin() + mid + 1);
  vector<int> v2(vec.begin() + mid + 1, vec.begin() + r + 1);
  int lx = 0, rx = 0;
  int index = l;
  while (lx < len1 && rx < len2) {
    if (v1[lx] <= v2[rx])
      vec[index++] = v1[lx++];
    else
      vec[index++] = v2[rx++];
  }
  while (lx < len1) vec[index++] = v1[lx++];
  while (rx < len2) vec[index++] = v2[rx++];
}
void mergeSortRecursive(vector<int> &vec, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  mergeSortRecursive(vec, l, mid);
  mergeSortRecursive(vec, mid + 1, r);
  merge(vec, l, mid, r);
}
void mergeSort(vector<int> &vec) {
  mergeSortRecursive(vec, 0, (int)vec.size() - 1);
}

int partition(vector<int> &vec, int l, int r) {
  // assertm(l >= 0 && r < (int)vec.size(), "Quick Sort Index Out of Bounds");
  int x = vec[r];
  int i = l - 1;
  for (int j = l; j < r; j++) {
    // assertm(i + 1 <= r, "Quick Sort Index Out of Bounds");
    if (vec[j] <= x) swap(vec[++i], vec[j]);
  }
  swap(vec[++i], vec[r]);
  return i;
}
int randomizedPartition(vector<int> &vec, int l, int r) {
  int pivot = generateRandomNumber(l, r);
  swap(vec[pivot], vec[r]);
  return partition(vec, l, r);
}
void quickSortRecursive(vector<int> &vec, int l, int r) {
  if (l >= r) return;
  int y = partition(vec, l, r);
  quickSortRecursive(vec, l, y - 1);
  quickSortRecursive(vec, y + 1, r);
}
void quickSort(vector<int> &vec) {
  quickSortRecursive(vec, 0, (int)vec.size() - 1);
}
void randomizedQuickSortRecursive(vector<int> &vec, int l, int r) {
  if (l >= r) return;
  int y = randomizedPartition(vec, l, r);
  randomizedQuickSortRecursive(vec, l, y - 1);
  randomizedQuickSortRecursive(vec, y + 1, r);
}
void randomizedQuickSort(vector<int> &vec) {
  randomizedQuickSortRecursive(vec, 0, (int)vec.size() - 1);
}

void insertionSort(vector<int> &vec) {
  int len = vec.size();
  for (int i = 0; i < len; i++) {
    int key = vec[i];
    int j = i - 1;
    while (j >= 0 && vec[j] > key) {
      vec[j + 1] = vec[j];
      j--;
    }
    vec[j + 1] = key;
  }
}

bool isSorted(vector<int> &vec) {
  int len = vec.size();
  for (int i = 1; i < len; i++) {
    if (vec[i] < vec[i - 1]) return false;
  }
  return true;
}