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
public:
    Node(T value, Node* next = NULL) {
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
    int length;
public:
    LLStack(int initialSize = 10) {
        length = 0;
        head = NULL;
    }
    LLStack(T* list, int direction = 1) {
        
    }
    ~LLStack(){
        clear();
    }
    void clear() {
        while (head != NULL) {
            auto temp = head;
            head = head->next;
            delete temp;
        }
        length = 0;
    }
    void push(const T& item) {
        head = new Node<>(item, head);
        length++;
    }
    T pop() {
        assertm(length != 0, "Stack is empty");
        if (length == 0) return NULL;
        auto ret = head->getValue();
        auto nxt = head->getNext();
        delete head;
        head = nxt;
        length--;
        return ret;
    }
    int length() const {
        return length;
    }
    const T& topValue() const {
        assertm(length != 0, "Stack is empty");
        return head->getValue();
    }
    void setDirection(int direction) {
        assertm(length == 0, "The stack is not empty");
    }
};