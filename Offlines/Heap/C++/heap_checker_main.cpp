#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <queue>

#include "heap.h"  //You need to implement this.

using namespace std;

int main() {
  vector<int> numbers{5, 2, 9, 1, 10, 100, 23};
  Heap h(numbers);
  cout << h;
  heapsort(numbers);
  bool sorted = true;
  for (const auto& i : numbers) cout << i << " ";
  cout << endl;
  for (int i = 1; i < numbers.size(); i++) {
    if (numbers[i] > numbers[i - 1]) {
      sorted = false;
      break;
    }
  }
  cout << (sorted ? "Sorted" : "Unsorted") << endl;
  cout << numbers[0];

  Heap h1(100000000);
  int maxi = INT_MIN;
  for (int i = 1; i <= 100000000; i++) {
    h1.insert(i);
    cout << h1;
    if (h1.getMax() != i) {
      cout << "Mismatch, showing " << h1.getMax() << " instead of " << i
           << endl;
      break;
    }
  }

  Heap h3(100);
  while (true) {
    int a;
    cin >> a;
    maxi = max(a, maxi);
    h3.insert(a);
    cout << h3;
    if (h3.getMax() != maxi) {
      cout << "Mismatch ";
      cout << "Heap Max: " << h3.getMax() << " ";
      cout << "Actual Max: " << maxi << endl;
    }
  }

  return 0;
}
