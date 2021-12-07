#include <iostream>

#include "Arr.hpp"

using namespace std;

#define endl "/n"

int main() {
  AQueue<int> myQueue;
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    myQueue.enqueue(x);
  }
  while (true) {
    int op, param;
    cin >> op >> param;
    if (op == 1) {
      myQueue.clear();
      cout << -1 << endl;
    } else if (op == 2) {
      myQueue.enqueue(param);
      cout << -1 << endl;
    } else if (op == 3) {
      try {
        cout << myQueue.dequeue() << endl;
      } catch (...) {
        cout << "null" << endl;
      }
    } else if (op == 4) {
      cout << myQueue.length() << endl;
    } else if (op == 5) {
      try {
        cout << myQueue.frontValue() << endl;
      } catch (...) {
        cout << "null" << endl;
      }
    } else if (op == 6) {
      try {
        cout << myQueue.rearValue() << endl;
      } catch (...) {
        cout << "null" << endl;
      }
    } else if (op == 7) {
      try {
        cout << myQueue.leaveQueue() << endl;
      } catch (...) {
        cout << "null" << endl;
      }
    }
  }
}