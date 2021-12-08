#include <iostream>

#include "Arr.hpp"
#include "LL.hpp"

using namespace std;

#define endl "\n"

template <typename T>
void printQueue(Queue<T>& q) {
  // AQueue<T> another;
  LLQueue<T> another;
  while (q.length() > 0) {
    auto ret = q.dequeue();
    another.enqueue(ret);
  }
  bool isFirst = true;
  cout << "<";
  while (another.length() > 0) {
    if (!isFirst)
      cout << ", ";
    else
      isFirst = false;
    auto now = another.dequeue();
    cout << now;
    q.enqueue(now);
  }
  cout << ">" << endl;
}

int main() {
  // AQueue<int> myQueue;
  LLQueue<int> myQueue;
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    myQueue.enqueue(x);
  }
  printQueue(myQueue);
  while (true) {
    int op, param;
    cin >> op >> param;
    if (op == 0)
      break;
    else if (op == 1) {
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
    } else
      continue;
    printQueue(myQueue);
  }
  return 0;
}