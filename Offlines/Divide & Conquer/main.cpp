#include <algorithm>
#include <ctime>
#include <iostream>

#include "header.h"
using namespace std;

const bool commentOn = true;

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
  clock_t start = clock();
  freopen("out2.csv", "w", stdout);
  cout << "           Time required in ms" << endl;
  cout << "n, Merge Sort, Quicksort, Randomized Quicksort, Insertion Sort, "
          "Quicksort with Sorted Input, Randomized Quicksort with Sorted "
          "Input, STL sort() function"
       << endl;
  for (int i = 0; i < length.size(); i++) {
    cout << length[i] << ", ";
    double ms = 0, qs = 0, rqs = 0, is = 0, qsi = 0, rqsi = 0, stls = 0;
    int repeat;
    for (repeat = 1; repeat <= 20; repeat++) {
      int seed = rand();

      vector<int> vec = generateRandomVector(i, seed);
      if (i <= 1 && commentOn) printVector(vec);
      clock_t now = clock();
      mergeSort(vec);
      clock_t end = clock();
      ms += double(end - now) / CLOCKS_PER_SEC;
      if (commentOn)
        cerr << "Merge Sort done. Average Until now: " << ms * 1000 / repeat
             << "ms" << endl;

      vec = generateRandomVector(i, seed);
      if (i <= 1 && commentOn) printVector(vec);
      now = clock();
      quickSort(vec);
      end = clock();
      qs += double(end - now) / CLOCKS_PER_SEC;
      if (commentOn)
        cerr << "Quick Sort done. Average Until now: " << qs * 1000 / repeat
             << "ms" << endl;

      vec = generateRandomVector(i, seed);
      if (i <= 1 && commentOn) printVector(vec);
      now = clock();
      randomizedQuickSort(vec);
      end = clock();
      rqs += double(end - now) / CLOCKS_PER_SEC;
      if (commentOn)
        cerr << "Randomized Quick Sort done. Average Until now: "
             << rqs * 1000 / repeat << "ms" << endl;

      vec = generateRandomVector(i, seed);
      if (i <= 1 && commentOn) printVector(vec);
      now = clock();
      insertionSort(vec);
      end = clock();
      is += double(end - now) / CLOCKS_PER_SEC;
      if (commentOn)
        cerr << "Insertion Sort done. Average Until now: " << is * 1000 / repeat
             << "ms" << endl;

      if (i <= 1 && commentOn) printVector(vec);
      now = clock();
      quickSort(vec);
      end = clock();
      qsi += double(end - now) / CLOCKS_PER_SEC;
      if (commentOn)
        cerr << "Quick Sort on sorted input done. Average Until now: "
             << qsi * 1000 / repeat << "ms" << endl;

      if (i <= 1 && commentOn) printVector(vec);
      now = clock();
      randomizedQuickSort(vec);
      end = clock();
      rqsi += double(end - now) / CLOCKS_PER_SEC;
      if (commentOn)
        cerr
            << "Randomized Quick Sort on sorted input done. Average Until now: "
            << rqsi * 1000 / repeat << "ms" << endl;

      vec = generateRandomVector(i, seed);
      if (i <= 1 && commentOn) printVector(vec);
      now = clock();
      sort(vec.begin(), vec.end());
      end = clock();
      stls += double(end - now) / CLOCKS_PER_SEC;
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

    cout << ms * 1000 / repeat << ", " << qs * 1000 / repeat << ", "
         << rqs * 1000 / repeat << ", " << is * 1000 / repeat << ", "
         << qsi * 1000 / repeat << ", " << rqsi * 1000 / repeat << ", "
         << stls * 1000 / repeat << endl;
  }

  cerr << "Program ended in " << double(clock() - start) / CLOCKS_PER_SEC
       << " seconds" << endl;
  return 0;
}