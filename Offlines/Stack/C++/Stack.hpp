#ifndef STACK_HPP
#define STACK_HPP
template <typename T> class Stack {
private:
    void operator=(const Stack&) {}
    Stack(const Stack&) {}
public:
    Stack();
    virtual ~Stack();
    virtual void clear() = 0;
    virtual void push(const T& item) = 0;
    virtual T pop() = 0;
    virtual int length() const = 0;
    virtual const T& topValue() const = 0;
    virtual void setDirection(int direction) = 0;
};
#endif


