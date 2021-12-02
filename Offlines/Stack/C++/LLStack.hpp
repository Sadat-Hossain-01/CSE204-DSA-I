#pragma once
#include "Stack.hpp"

template <typename T> class Node {
private:
    T value;
    Node* next;
    Node(const Node&) {}
    void operator = (const Node&) {}
public:
    Node(T value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
    T getValue() const {
        return value;
    }
    Node* getNext() const {
        return next;
    }
    void setNext(Node* next) {
        this->next = next;
    }
};

template <typename T> class LLStack : public Stack <T> {
private:
    Node<T>* head;
    int len;
public:
    LLStack(int initialSize = 10) {
        len = 0;
        head = nullptr;
    }
    LLStack(T* list, int direction = 1) {
    }
    ~LLStack() {
        clear();
    }
    void clear() {
        while (head != nullptr) {
            auto temp = head;
            head = head->getNext();
            delete temp;
        }
        len = 0;
    }
    void push(const T& item) {
        head = new Node<T>(item, head);
        len++;
    }
    T pop() {
        if (len == 0) {
            throw "Empty Stack";
        }
        assertm(len != 0, "Stack is empty");
        auto ret = head->getValue();
        auto nxt = head->getNext();
        delete head;
        head = nxt;
        len--;
        return ret;
    }
    int length() const {
        return len;
    }
    const T& topValue() const {
        if (len == 0) {
            throw "Empty Stack";
        }
        assertm(len != 0, "Stack is empty");
        return head->getValue();
    }
    void setDirection(int direction) {
        if (len != 0) return;
//        assertm(len == 0, "The stack is not empty");
    }
};
