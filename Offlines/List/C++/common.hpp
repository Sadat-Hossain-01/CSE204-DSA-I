#include <iostream>
#include <cassert>
#include <cstdio>

#define assertm(exp, msg) assert(((void)msg, exp))

template <typename T> class List {
private:
    List(const List&) {}
    void operator=(const List&) {}

public:
    List() {}
    virtual ~List() {}
    virtual void clear() = 0;
    virtual void insert(const T& item) = 0;
    virtual void append(const T& item) = 0;
    virtual T remove() = 0;
    virtual void moveToStart() = 0;
    virtual void moveToEnd() = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    virtual int length() const = 0;
    virtual int currPos() const = 0;
    virtual void moveToPos(int pos) = 0;
    virtual const T& getValue() const = 0;
    virtual int Search(T item) const = 0;
};

