#include "Stack.hpp"

#ifndef assertm
#define assertm(exp, msg) assert(((void)msg, exp))
#endif

template <typename T> class Node {
private:
    T value;
    Node* next;
    Node(const Node&) {}
    void operator = (const Node&) {}
protected:
    Node() {}
    Node(T item, Node* next = nullptr) {
        this->value = item;
        this->next = next;
    }
    T getValue() const {
        return value;
    }
    T* getNext() const {
        return next;
    }
    void setNext(T* item) {
        this->next = item;
    }
};

template <typename T> class LLStack : public Stack <T> {
private:
    Node* head;
    int length;
public:
    LLStack(int initialSize = 10) {
        length = 0;
        head = nullptr;
    }
    LLStack(T* list, int direction = 1) {

    }
    void clear() {
        length = 0;
        while (head != nullptr) {
            auto temp = top;
            top = temp->next;
            delete temp;
        }
    }
    void push(const T& item) {
        auto nxt = new Node<>(item, head);
        head = nxt;
        length++;
    }
    T pop() {
        assertm(length != 0, "Stack is empty");
        if (length == 0) return nullptr;
        auto temp = head;
        head = temp->getNext();
        delete
            return temp->getValue();
    }
    int length() const {
        return length;
    }
    const T& topValue() const {
        assertm(length != 0, "Stack is empty");

    }
    void setDirection(int direction) {
        assertm(length == 0, "The stack is not empty");
    }
};