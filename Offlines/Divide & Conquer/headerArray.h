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

void merge(int *arr, int l, int mid, int r, int *temp) {
  int len1 = mid - l + 1;
  int len2 = r - mid;

  int j = 0;
  for (int i = l; i <= mid; i++) temp[j++] = arr[i];
  for (int i = mid + 1; i <= r; i++) temp[j++] = arr[i];

  int lx = 0, rx = len1;
  int index = l;
  while (lx < len1 && rx < len1 + len2) {
    if (temp[lx] <= temp[rx])
      arr[index++] = temp[lx++];
    else
      arr[index++] = temp[rx++];
  }
  while (lx < len1) arr[index++] = temp[lx++];
  while (rx < len1 + len2) arr[index++] = temp[rx++];
}
void mergeSortRecursive(int *arr, int l, int r, int *temp) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  mergeSortRecursive(arr, l, mid, temp);
  mergeSortRecursive(arr, mid + 1, r, temp);
  merge(arr, l, mid, r, temp);
}
void mergeSort(int *arr, int l, int r) {
  int *temp = new int[r - l + 1];
  mergeSortRecursive(arr, l, r, temp);
  delete[] temp;
}

int partition(int *arr, int l, int r) {
  int x = arr[r];
  int i = l - 1;
  for (int j = l; j < r; j++) {
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

bool isSorted(int *arr, int len) {
  for (int i = 1; i < len; i++)
    if (arr[i] < arr[i - 1]) return false;
  return true;
}