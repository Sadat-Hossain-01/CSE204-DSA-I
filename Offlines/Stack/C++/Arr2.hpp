#include <iostream>

#include "Arr.hpp"
using namespace std;

template <typename T>
class AStack2 : public AStack<T> {
 public:
  void doublePop() {
    if (this->length() >= 2) {
      this->pop();
      this->pop();
    }
  }
  void printStack() {
    AStack<T> another;
    //    LLStack<T> another;

    while (this->length() > 0) {
      another.push(this->pop());
    }

    bool isFirst = true;
    cout << "<";
    while (another.length() > 0) {
      auto elem = another.pop();
      if (!isFirst)
        cout << " ";
      else
        isFirst = false;
      cout << elem;
      this->push(elem);
    }
    cout << ">\n";
  }
};