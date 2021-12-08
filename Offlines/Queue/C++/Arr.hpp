#pragma once
#include "Queue.hpp"

const int defaultSize = 15;

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
    this->size = size + 1;
    queueList = new T[this->size];
    len = 0;
    front = 1;
    rear = 0;
  }
  AQueue(T* alreadyAllocatedList) {
    delete[] queueList;
    queueList = alreadyAllocatedList;
  }
  ~AQueue() { delete[] queueList; }
  void clear() {
    len = 0;
    front = 1;
    rear = 0;
  }
  void enqueue(const T& item) {
    if (len <= size - 2) {  // queue has spaces left
      rear = (rear + 1 + size) % size;
      queueList[rear] = item;
    } else {
      T* anotherList = new T[2 * size - 1];
      for (int i = 0, idx = front; i < len; i++) {
        anotherList[i] = queueList[idx];
        rear = i;
        idx++;
        if (idx == size) idx = 0;
      }
      front = 0;  // new front will be 0
      anotherList[++rear] = item;
      size = size * 2 - 1;
      delete[] queueList;
      queueList = anotherList;
    }
    len++;
  }
  T dequeue() {
    if (len == 0) throw "Empty Queue";
    assertm(len != 0, "Empty Queue");
    auto ret = queueList[front];
    front = (front + 1 + size) % size;
    len--;
    return ret;
  }
  int length() const { return len; }
  const T& frontValue() const {
    if (len == 0) throw "Empty Queue";
    assertm(len != 0, "Empty Queue");
    return queueList[front];
  }
  const T& rearValue() const {
    if (len == 0) throw "Empty Queue";
    assertm(len != 0, "Empty Queue");
    return queueList[rear];
  }
  T leaveQueue() {
    if (len == 0) throw "Empty Queue";
    assertm(len != 0, "Empty Queue");
    auto ret = queueList[rear];
    rear = (rear - 1 + size) % size;
    len--;
    return ret;
  }
};