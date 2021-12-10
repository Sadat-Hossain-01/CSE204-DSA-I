#include <iostream>

#include "Arr2.hpp"
using namespace std;

template <typename T>
void printStack(Stack<T>& myStack) {
  int len = myStack.length();
  T* temp = new T[len];
  int idx = 0;
  while (idx < len) {
    auto top = myStack.pop();
    temp[idx++] = top;
  }
  cout << "<";
  idx = len - 1;
  while (idx >= 0) {
    auto now = temp[idx];
    if (idx-- != len - 1) cout << " ";
    cout << now;
    myStack.push(now);
  }
  cout << ">" << endl;
  delete[] temp;
}

int main() {
  AStack2<int> what;
  what.push(1);
  what.push(2);
  what.push(3);
  what.push(4);
  what.printStack();
  what.doublePop();
  what.printStack();
}