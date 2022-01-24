#include <algorithm>
#include <ctime>
#include <iostream>

#include "header.h"
using namespace std;

const bool commentOn = true, sortedCheck = true;

vector<int> length{5, 10, 100, 1000, 10000, 100000};

vector<int> generateRandomVector(int index, int seed) {
  int n = length[index];
  srand(seed);
  vector<int> vec(n, 0);
  for (int i = 0; i < n; i++) {
    vec[i] = rand();
  }
  return vec;
}

int main() {
  for (int i = 0; i < length.size(); i++) {
    double ms = 0, qs = 0, rqs = 0, is = 0, qsi = 0, rqsi = 0, stls = 0;
    int repeat;
    for (repeat = 1; repeat <= 20; repeat++) {
      int seed = rand();

      vector<int> vec = generateRandomVector(i, seed);
      if (i <= 1 && commentOn) printVector(vec);
      clock_t now = clock();
      mergeSort(vec);
      ms += double(clock() - now) / CLOCKS_PER_SEC;
      if (sortedCheck) assertm(isSorted(vec), "Merge Sort failed");
      if (commentOn)
        cerr << "Merge Sort done. Average Until now: " << ms * 1000 / repeat
             << "ms" << endl;

      vec = generateRandomVector(i, seed);
      if (i <= 1 && commentOn) printVector(vec);
      now = clock();
      quickSort(vec);
      qs += double(clock() - now) / CLOCKS_PER_SEC;
      if (sortedCheck) assertm(isSorted(vec), "Quick Sort failed");
      if (commentOn)
        cerr << "Quick Sort done. Average Until now: " << qs * 1000 / repeat
             << "ms" << endl;

      vec = generateRandomVector(i, seed);
      if (i <= 1 && commentOn) printVector(vec);
      now = clock();
      randomizedQuickSort(vec);
      rqs += double(clock() - now) / CLOCKS_PER_SEC;
      if (sortedCheck) assertm(isSorted(vec), "Randomized Quick Sort failed");
      if (commentOn)
        cerr << "Randomized Quick Sort done. Average Until now: "
             << rqs * 1000 / repeat << "ms" << endl;

      vec = generateRandomVector(i, seed);
      if (i <= 1 && commentOn) printVector(vec);
      now = clock();
      insertionSort(vec);
      is += double(clock() - now) / CLOCKS_PER_SEC;
      if (sortedCheck) assertm(isSorted(vec), "Insertion Sort failed");
      if (commentOn)
        cerr << "Insertion Sort done. Average Until now: " << is * 1000 / repeat
             << "ms" << endl;

      if (i <= 1 && commentOn) printVector(vec);
      now = clock();
      quickSort(vec);
      qsi += double(clock() - now) / CLOCKS_PER_SEC;
      if (sortedCheck)
        assertm(isSorted(vec), "Quick Sort on Sorted Input failed");
      if (commentOn)
        cerr << "Quick Sort on sorted input done. Average Until now: "
             << qsi * 1000 / repeat << "ms" << endl;

      if (i <= 1 && commentOn) printVector(vec);
      now = clock();
      randomizedQuickSort(vec);
      rqsi += double(clock() - now) / CLOCKS_PER_SEC;
      if (sortedCheck)
        assertm(isSorted(vec), "Randomized Quick Sort on Sorted Input failed");
      if (commentOn)
        cerr
            << "Randomized Quick Sort on sorted input done. Average Until now: "
            << rqsi * 1000 / repeat << "ms" << endl;

      vec = generateRandomVector(i, seed);
      if (i <= 1 && commentOn) printVector(vec);
      now = clock();
      sort(vec.begin(), vec.end());
      stls += double(clock() - now) / CLOCKS_PER_SEC;
      if (sortedCheck) assertm(isSorted(vec), "STL Sort failed");
      if (commentOn)
        cerr << "STL sort done. Average Until now: " << stls * 1000 / repeat
             << "ms" << endl;

      if (commentOn)
        cerr << "n = " << length[i] << " " << repeat << " times done" << endl;
    }

    cout << "n = " << length[i] << endl;
    cout << "Merge Sort: " << ms * 1000 / repeat << "ms" << endl;
    cout << "Quick Sort: " << qs * 1000 / repeat << "ms" << endl;
    cout << "Randomized Quick Sort: " << rqs * 1000 / repeat << "ms" << endl;
    cout << "Insertion Sort: " << is * 1000 / repeat << "ms" << endl;
    cout << "Quick Sort with Sorted Input: " << qsi * 1000 / repeat << "ms"
         << endl;
    cout << "Randomized Quick Sort with Sorted Input: " << rqsi * 1000 / repeat
         << "ms" << endl;
    cout << "STL Sort : " << stls * 1000 / repeat << "ms" << endl;
    cout << endl;
  }
}