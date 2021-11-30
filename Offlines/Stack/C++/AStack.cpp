#include "Stack.hpp"

#ifndef assertm
#define assertm(exp, msg) assert(((void)msg, exp))
#endif

template <typename T> class AStack : public Stack<T> {
private:
    int maxSize;
    int length;
    int next;
    int direction;
    T* stackList;
public:
    AStack(int initialSize) {
        stackList = new T[initialSize];
        maxSize = initialSize;
        next = length = 0;
    }
    AStack(T* list, int direction = 1) {
        stackList = list;
        this->direction = direction;
        length = 0;
        if (direction == 1) next = 0;
        else next = length - 1;
    }
    ~AStack() {
        delete[] stackList;
    }
    void clear() {
        delete[] stackList;
        length = 0;
        if (direction = 1) next = 0;
        else next = length - 1;
    }
    void push(const T& item) {
        if (direction == 1) {
            if (length < maxSize) {
                stackList[length++] = item;
            }
            else {
                maxSize *= 2;
                T* tempList = new T[maxSize];
                for (int i = 0; i < length; i++) {
                    tempList[i] = stackList[i];
                }
                tempList[length++] = item;
                delete[] stackList;
                stackList = tempList;
            }
            next++;
        }
        else {
            if (length < maxSize) {
                stackList[next] = item;
                length++;
                next--;
            }
            else {
                maxSize *= 2;
                T* tempList = new T[maxSize];
                int val = maxSize / 2;
                for (int i = length - 1; i >= 0; i--) {
                    tempList[i + maxSize] = stackList[i];
                }
                tempList[val - 1] = item;
                next = val - 2;
                length++;
                delete[] stackList;
                stackList = tempList;
            }
        }
    }
    T pop() {
        assertm(length != 0, "Stack is empty");
        if (length == 0) return nullptr;
        if (direction == 1) {
            next--;
            return stackList[length-- - 1];
        }
        else {
            return stackList[next + 1];
            next++;
            length--;
        }
    }
    int length() const {
        return length;
    }
    const T& topValue() const {
        assertm(length != 0, "Stack is empty");
        if (direction == 1) return stackList[length - 1];
        else return stackList[next + 1];
    }
    void setDirection(int direction) {
        assertm(length == 0, "The stack is not empty");
        this->direction = direction;
    }
};