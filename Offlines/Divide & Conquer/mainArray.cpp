#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <ratio>
#include <vector>

#include "headerArray.h"
using namespace std;

const int REPEAT = 20;
const bool commentOn = false;
const bool sortedCheck = false;

inline std::chrono::high_resolution_clock::time_point getCurrent() {
  return std::chrono::high_resolution_clock::now();
}

inline double getElapsedTime(
    const std::chrono::high_resolution_clock::time_point& t1) {
  auto t2 = getCurrent();
  auto time_span =
      std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
  return time_span.count() / 1e6;  // ms
}

vector<int> length{5, 10, 100, 1000, 10000, 100000};

void generateRandomArray(int* arr, int index) {
  int n = length[index];
  for (int i = 0; i < n; i++) {
    arr[i] = rand();
  }
}

void copyArray(int* from, int* to, int len) {
  for (int i = 0; i < len; i++) to[i] = from[i];
}

int main() {
  auto start = getCurrent();
  freopen("outArray.csv", "w", stdout);
  cout << "Time required in ms" << endl;
  cout << "n, Merge Sort, Quicksort, Randomized Quicksort, Insertion Sort, "
          "Quicksort with Sorted Input, Randomized Quicksort with Sorted "
          "Input, STL sort() function"
       << endl;

  for (int i = 0; i < length.size(); i++) {
    int len = length[i];
    cout << len << ", ";
    int* generatedArrayForThis = new int[len];
    int* arrayToPass = new int[len];
    double ms = 0.0, qs = 0.0, rqs = 0.0, is = 0.0, qsi = 0.0, rqsi = 0.0,
           stls = 0.0;

    for (int repeat = 1; repeat <= REPEAT; repeat++) {
      generateRandomArray(generatedArrayForThis, i);

      copyArray(generatedArrayForThis, arrayToPass, len);
      auto begin = getCurrent();
      mergeSort(arrayToPass, 0, len - 1);
      ms += getElapsedTime(begin);
      if (sortedCheck) assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr << "Merge Sort done. Average Until now: " << ms / repeat << "ms"
             << endl;

      copyArray(generatedArrayForThis, arrayToPass, len);
      begin = getCurrent();
      quickSort(arrayToPass, 0, len - 1);
      qs += getElapsedTime(begin);
      if (sortedCheck) assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr << "Quick Sort done. Average Until now: " << qs / repeat << "ms"
             << endl;

      copyArray(generatedArrayForThis, arrayToPass, len);
      begin = getCurrent();
      randomizedQuickSort(arrayToPass, 0, len - 1);
      rqs += getElapsedTime(begin);
      if (sortedCheck) assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr << "Randomized Quick Sort done. Average Until now: "
             << rqs / repeat << "ms" << endl;

      copyArray(generatedArrayForThis, arrayToPass, len);
      begin = getCurrent();
      insertionSort(arrayToPass, len);
      is += getElapsedTime(begin);
      if (sortedCheck) assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr << "Insertion Sort done. Average Until now: " << is / repeat
             << "ms" << endl;

      begin = getCurrent();
      quickSort(arrayToPass, 0, len - 1);
      qsi += getElapsedTime(begin);
      if (sortedCheck) assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr << "Quick Sort on sorted input done. Average Until now: "
             << qsi / repeat << "ms" << endl;

      begin = getCurrent();
      randomizedQuickSort(arrayToPass, 0, len - 1);
      rqsi += getElapsedTime(begin);
      if (sortedCheck) assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr
            << "Randomized Quick Sort on sorted input done. Average Until now: "
            << rqsi / repeat << "ms" << endl;

      copyArray(generatedArrayForThis, arrayToPass, len);
      begin = getCurrent();
      sort(arrayToPass, arrayToPass + len);
      stls += getElapsedTime(begin);
      if (sortedCheck) assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr << "STL sort done. Average Until now: " << stls / repeat << "ms"
             << endl;

      if (commentOn)
        cerr << "n = " << length[i] << " " << repeat << " times done" << endl;
    }

    cout << setprecision(8) << (ms / REPEAT) << ", " << (qs / REPEAT) << ", "
         << (rqs / REPEAT) << ", " << (is / REPEAT) << ", " << (qsi / REPEAT)
         << ", " << (rqsi / REPEAT) << ", " << (stls / REPEAT) << endl;

    delete[] generatedArrayForThis;
    delete[] arrayToPass;
  }

  cerr << "Program ended in " << getElapsedTime(start) / 1000.0 << " seconds"
       << endl;
  return 0;
}
