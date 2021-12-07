#pragma once
#include <cassert>
#include <cstdlib>
#define assertm(exp, msg) assert(((void)msg, exp))

template <typename T>
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