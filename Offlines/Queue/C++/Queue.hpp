#pragma once
#include <cassert>
#include <cstdlib>
#define assertm(exp, msg) assert(((void)msg, exp))

template <typename E>
class Queue {
 private:
  Queue(const Queue& q) {}
  void operator=(const Queue& q) {}

 public:
  Queue(){};
  virtual ~Queue() {}
  virtual void clear() = 0;
  virtual void enqueue(const T& item) = 0;
  virtual T dequeue() = 0;
  virtual int length() const = 0;
  virtual const T& frontValue() const = 0;
  virtual const T& rearValue() const = 0;
  virtual T leaveQueue() = 0;
};

template <typename T>
void printQueue(Queue<T> q) {
  AQueue<T> another;
  while (q.length() > 0) {
    another.enqueue(q.dequeue);
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