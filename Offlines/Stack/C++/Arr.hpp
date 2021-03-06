#pragma once
#include "Stack.hpp"

const int defaultSize = 20;

template <typename T>
class AStack : public Stack<T> {
 private:
  int maxSize;
  int len;
  int next;
  int direction = 1;
  T* stackList;

 public:
  AStack(int initialSize = defaultSize) {
    stackList = new T[initialSize];
    maxSize = initialSize;
    next = 0;
    len = 0;
  }
  // C++ requires the length parameter additionally with the array itself, hence
  // the extra parameter
  AStack(int length, int size, T* list, int direction = 1) {
    stackList = list;
    this->direction = direction;
    len = length;
    maxSize = size;
    if (direction == 1)
      next = 0;
    else
      next = len - 1;
  }
  ~AStack() {
    clear();
    // delete[] stackList;
  }
  void clear() {
    len = 0;
    if (direction == 1)
      next = 0;
    else
      next = len - 1;
  }
  void push(const T& item) {
    if (direction == 1) {
      if (len < maxSize) {
        stackList[next] = item;
      } else {
        maxSize *= 2;
        T* tempList = new T[maxSize];
        for (int i = 0; i < len; i++) {
          tempList[i] = stackList[i];
        }
        tempList[len] = item;
        delete[] stackList;
        stackList = tempList;
      }
      next++;
      len++;
    } else {
      if (len < maxSize) {
        stackList[next] = item;
        next--;
      } else {
        maxSize *= 2;
        T* tempList = new T[maxSize];
        int val = maxSize / 2;
        for (int i = len - 1; i >= 0; i--) {
          tempList[i + maxSize] = stackList[i];
        }
        tempList[val - 1] = item;
        next = val - 2;
        delete[] stackList;
        stackList = tempList;
      }
      len++;
    }
  }
  T pop() {
    if (len == 0) {
      throw "Empty Stack";
    }
    assertm(len != 0, "Stack is empty");
    len--;
    if (direction == 1)
      return stackList[--next];
    else
      return stackList[++next];
  }
  int length() const { return len; }
  const T& topValue() const {
    if (len == 0) {
      throw "Empty Stack";
    }
    assertm(len != 0, "Stack is empty");
    if (direction == 1)
      return stackList[next - 1];
    else
      return stackList[next + 1];
  }
  void setDirection(int direction) {
    if (len != 0) return;
    //        assertm(len == 0, "The stack is not empty");
    this->direction = direction;
  }
};
