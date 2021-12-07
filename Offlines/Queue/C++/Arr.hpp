#pragma once
#include "Queue.hpp"

const int defaultSize = 20;

template <typename T>
class AQueue : public Queue<T> {
 private:
  int len;
  int size;
  int front;
  int rear;
  T* queueList;

 public:
  AQueue(int size = defaultSize) {
    this->size = size;
    queueList = new T[size];
    front = 0;
    rear = size - 1;
  }
  AQueue(T* alreadyAllocatedList) {
    delete[] queueList;
    queueList = alreadyAllocatedList;
  }
  ~Queue() { delete[] queueList; }
  void clear() {
    len = 0;
    front = 0;
    rear = size - 1;
  }
  void enqueue(const T& item) {}
  T dequeue() {}
  int length() { return len; }
  const T& frontValue() {
    if (len == 0) throw "Empty Queue";
    assertm(len != 0, "Empty Queue");
    return queueList[front];
  }
  const T& rearValue() {}
  T leaveQueue() {}
};