#pragma once
#include "Queue.hpp"

template <typename T>
class Node {
 private:
  Node* next;
  T value;

 public:
  Node(Node* link = nullptr) { next = link; }
  Node(T item, Node* link = nullptr) {
    value = item;
    next = link;
  }
  Node* getNext() { return next; }
  const T& getValue() { return value; }
  void setNext(Node* link) { next = link; }
  void setValue(const T& value) { this->value = value; }
};

template <typename T>
class LLQueue : public Queue<T> {
 private:
  Node<T>* front;
  Node<T>* rear;
  int len;

 public:
  LLQueue(int size = defaultSize) {
    front = rear = new Node<T>();
    len = 0;
  }
  LLQueue(T* alreadyAllocatedList) {
    front = rear = new Node<T>();
    len = 0;
  }
  ~LLQueue() {
    clear();
    delete front;
  }
  void clear() {
    while (front->getNext() != nullptr) {
      auto nx = front->getNext();
      front->setNext(nx->getNext());
      delete nx;
    }
    rear = front;
    len = 0;
  }
  void enqueue(const T& item) {
    rear->setNext(new Node<T>(item));
    rear = rear->getNext();
    len++;
  }
  T dequeue() {
    if (len == 0) throw "Empty Queue";
    assertm(len != 0, "Empty Queue");
    auto ret = front->getNext()->getValue();  // value to be returned
    auto prev_front = front->getNext();
    front->setNext(prev_front->getNext());
    if (len == 1) rear = front;
    delete prev_front;
    len--;
    return ret;
  }
  int length() const { return len; }
  const T& frontValue() const {
    if (len == 0) throw "Empty Queue";
    assertm(len != 0, "Empty Queue");
    return front->getNext()->getValue();
  }
  const T& rearValue() const {
    if (len == 0) throw "Empty Queue";
    assertm(len != 0, "Empty Queue");
    return rear->getValue();
  }
  T leaveQueue() {
    if (len == 0) throw "Empty Queue";
    assertm(len != 0, "Empty Queue");
    auto ret = rear->getValue();
    auto prev_to_rear = front;
    auto prev_rear = rear;

    while (prev_to_rear->getNext() != rear) {
      prev_to_rear = prev_to_rear->getNext();
    }

    rear = prev_to_rear;
    rear->setNext(nullptr);
    delete prev_rear;
    len--;
    return ret;
  }
};