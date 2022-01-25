#include <cassert>
#include <cstdlib>

#define endl "\n"
#define assertm(exp, msg) assert(((void)msg, exp))

using namespace std;

inline void swap(int &a, int &b) { b = (a + b) - (a = b); }

inline int generateRandomNumber(int a, int b) {
  // [a, b]
  return rand() % (b - a + 1) + a;
}

void merge(int *arr, int l, int mid, int r) {
  //   assertm(l >= 0 && r < (int)vec.size(), "Merge Sort Index Out of Bounds");
  int len1 = mid - l + 1;
  int len2 = r - mid;
  int *arr1 = new int[len1];
  int *arr2 = new int[len2];
  for (int i = l, j = 0; i <= mid; i++) arr1[j++] = arr[i];
  for (int i = mid + 1, j = 0; i <= r; i++) arr2[j++] = arr[i];
  int lx = 0, rx = 0;
  int index = l;
  while (lx < len1 && rx < len2) {
    if (arr1[lx] <= arr2[rx])
      arr[index++] = arr1[lx++];
    else
      arr[index++] = arr2[rx++];
  }
  while (lx < len1) arr[index++] = arr1[lx++];
  while (rx < len2) arr[index++] = arr2[rx++];
}
void mergeSort(int *arr, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  mergeSort(arr, l, mid);
  mergeSort(arr, mid + 1, r);
  merge(arr, l, mid, r);
}

int partition(int *arr, int l, int r) {
  // assertm(l >= 0 && r < (int)vec.size(), "Quick Sort Index Out of Bounds");
  int x = arr[r];
  int i = l - 1;
  for (int j = l; j < r; j++) {
    // assertm(i + 1 <= r, "Quick Sort Index Out of Bounds");
    if (arr[j] <= x) swap(arr[++i], arr[j]);
  }
  swap(arr[++i], arr[r]);
  return i;
}

int randomizedPartition(int *arr, int l, int r) {
  int pivot = generateRandomNumber(l, r);
  swap(arr[pivot], arr[r]);
  return partition(arr, l, r);
}

void quickSort(int *arr, int l, int r) {
  if (l >= r) return;
  int y = partition(arr, l, r);
  quickSort(arr, l, y - 1);
  quickSort(arr, y + 1, r);
}

void randomizedQuickSort(int *arr, int l, int r) {
  if (l >= r) return;
  int y = randomizedPartition(arr, l, r);
  randomizedQuickSort(arr, l, y - 1);
  randomizedQuickSort(arr, y + 1, r);
}

void insertionSort(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}