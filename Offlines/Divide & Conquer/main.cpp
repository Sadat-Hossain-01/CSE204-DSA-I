#include <algorithm>
#include <ctime>
#include <iostream>

#include "header.h"
using namespace std;

const bool commentOn = false;

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
    float ms = 0, qs = 0, rqs = 0, is = 0, qsi = 0, rqsi = 0, stls = 0;
    for (int repeat = 1; repeat <= 20; repeat++) {
      int seed = rand();

      vector<int> vec = generateRandomVector(i, seed);
      if (i == 0 && commentOn) printVector(vec);
      clock_t now = clock();
      mergeSort(vec);
      ms += float(clock() - now) / CLOCKS_PER_SEC;
      if (commentOn) cout << "Merge Sort done" << endl;

      vec = generateRandomVector(i, seed);
      if (i == 0 && commentOn) printVector(vec);
      now = clock();
      quickSort(vec);
      qs += float(clock() - now) / CLOCKS_PER_SEC;
      if (commentOn) cout << "Quick Sort done" << endl;

      vec = generateRandomVector(i, seed);
      if (i == 0 && commentOn) printVector(vec);
      now = clock();
      randomizedQuickSort(vec);
      rqs += float(clock() - now) / CLOCKS_PER_SEC;
      if (commentOn) cout << "Randomized Quick Sort done" << endl;

      vec = generateRandomVector(i, seed);
      if (i == 0 && commentOn) printVector(vec);
      now = clock();
      insertionSort(vec);
      is += float(clock() - now) / CLOCKS_PER_SEC;
      if (commentOn) cout << "Insertion Sort done" << endl;

      if (i == 0 && commentOn) printVector(vec);
      now = clock();
      quickSort(vec);
      qsi += float(clock() - now) / CLOCKS_PER_SEC;
      if (commentOn) cout << "Quick Sort on sorted input done" << endl;

      if (i == 0 && commentOn) printVector(vec);
      now = clock();
      randomizedQuickSort(vec);
      rqsi += float(clock() - now) / CLOCKS_PER_SEC;
      if (commentOn)
        cout << "Randomized Quick Sort on sorted input done" << endl;

      vec = generateRandomVector(i, seed);
      if (i == 0 && commentOn) printVector(vec);
      now = clock();
      sort(vec.begin(), vec.end());
      stls += float(clock() - now) / CLOCKS_PER_SEC;
      if (commentOn) cout << "STL sort done" << endl;
    }
    cout << "n = " << length[i] << endl;
    cout << "Merge Sort: " << ms * 50 << "ms" << endl;
    cout << "Quick Sort: " << qs * 50 << "ms" << endl;
    cout << "Randomized Quick Sort: " << rqs * 50 << "ms" << endl;
    cout << "Insertion Sort: " << is * 50 << "ms" << endl;
    cout << "Quick Sort with Sorted Input: " << qsi * 50 << "ms" << endl;
    cout << "Randomized Quick Sort with Sorted Input: " << rqsi * 50 << "ms"
         << endl;
    cout << "STL Sort : " << stls * 50 << "ms" << endl;
    cout << endl;
  }
}