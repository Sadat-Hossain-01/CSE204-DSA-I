#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

#include "headerArray.h"
using namespace std;

const bool commentOn = false;

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
  clock_t start = clock();
  freopen("outArray.csv", "w", stdout);
  cout << "Time required in ms" << endl;
  cout << "n, Merge Sort, Quicksort, Randomized Quicksort, Insertion Sort, "
          "Quicksort with Sorted Input, Randomized Quicksort with Sorted "
          "Input, STL sort() function"
       << endl;

  for (int i = 0; i < length.size(); i++) {
    int len = length[i];
    cout << len << ", ";
    int* arrayForThis = new int[len];
    int* arrayToPass = new int[len];
    double ms = 0, qs = 0, rqs = 0, is = 0, qsi = 0, rqsi = 0, stls = 0;
    int repeat;
    for (repeat = 1; repeat <= 20; repeat++) {
      int seed = rand();

      generateRandomArray(arrayForThis, i);

      copyArray(arrayForThis, arrayToPass, len);
      clock_t now = clock();
      mergeSort(arrayToPass, 0, len - 1);
      clock_t end = clock();
      ms += double(end - now) / CLOCKS_PER_SEC;
      assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr << "Merge Sort done. Average Until now: " << ms * 1000 / repeat
             << "ms" << endl;

      copyArray(arrayForThis, arrayToPass, len);
      now = clock();
      quickSort(arrayToPass, 0, len - 1);
      end = clock();
      qs += double(end - now) / CLOCKS_PER_SEC;
      assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr << "Quick Sort done. Average Until now: " << qs * 1000 / repeat
             << "ms" << endl;

      copyArray(arrayForThis, arrayToPass, len);
      now = clock();
      randomizedQuickSort(arrayToPass, 0, len - 1);
      end = clock();
      rqs += double(end - now) / CLOCKS_PER_SEC;
      assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr << "Randomized Quick Sort done. Average Until now: "
             << rqs * 1000 / repeat << "ms" << endl;

      copyArray(arrayForThis, arrayToPass, len);
      now = clock();
      insertionSort(arrayToPass, len);
      end = clock();
      is += double(end - now) / CLOCKS_PER_SEC;
      assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr << "Insertion Sort done. Average Until now: " << is * 1000 / repeat
             << "ms" << endl;

      now = clock();
      quickSort(arrayToPass, 0, len - 1);
      end = clock();
      qsi += double(end - now) / CLOCKS_PER_SEC;
      assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr << "Quick Sort on sorted input done. Average Until now: "
             << qsi * 1000 / repeat << "ms" << endl;

      now = clock();
      randomizedQuickSort(arrayToPass, 0, len - 1);
      end = clock();
      rqsi += double(end - now) / CLOCKS_PER_SEC;
      assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr
            << "Randomized Quick Sort on sorted input done. Average Until now: "
            << rqsi * 1000 / repeat << "ms" << endl;

      copyArray(arrayForThis, arrayToPass, len);
      now = clock();
      sort(arrayToPass, arrayToPass + len);
      end = clock();
      stls += double(end - now) / CLOCKS_PER_SEC;
      assert(isSorted(arrayToPass, len));
      if (commentOn)
        cerr << "STL sort done. Average Until now: " << stls * 1000 / repeat
             << "ms" << endl;

      if (commentOn)
        cerr << "n = " << length[i] << " " << repeat << " times done" << endl;
    }

    // cout << "n = " << length[i] << endl;
    // cout << "Merge Sort: " << ms * 1000 / repeat << "ms" << endl;
    // cout << "Quick Sort: " << qs * 1000 / repeat << "ms" << endl;
    // cout << "Randomized Quick Sort: " << rqs * 1000 / repeat << "ms" << endl;
    // cout << "Insertion Sort: " << is * 1000 / repeat << "ms" << endl;
    // cout << "Quick Sort with Sorted Input: " << qsi * 1000 / repeat << "ms"
    //      << endl;
    // cout << "Randomized Quick Sort with Sorted Input: " << rqsi * 1000 /
    // repeat
    //      << "ms" << endl;
    // cout << "STL Sort : " << stls * 1000 / repeat << "ms" << endl;
    // cout << endl;

    repeat--;

    cout << ms * 1000 / repeat << ", " << qs * 1000 / repeat << ", "
         << rqs * 1000 / repeat << ", " << is * 1000 / repeat << ", "
         << qsi * 1000 / repeat << ", " << rqsi * 1000 / repeat << ", "
         << stls * 1000 / repeat << endl;

    delete[] arrayForThis;
    delete[] arrayToPass;
  }

  cerr << "Program ended in " << double(clock() - start) / CLOCKS_PER_SEC
       << " seconds" << endl;
  return 0;
}
