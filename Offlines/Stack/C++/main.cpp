#include <iostream>
#include "Arr.hpp"
#include "LL.hpp"
using namespace std;

#define endl "\n"

template <typename T> void printStack(Stack<T>& myStack)
{
    int len = myStack.length();
    T* temp = new T[len];
    int idx = 0;
    while (idx < len)
    {
        auto top = myStack.pop();
        temp[idx++] = top;
    }
    cout << "<";
    idx = len - 1;
    while (idx >= 0)
    {
        auto now = temp[idx];
        if (idx-- != len - 1) cout << " ";
        cout << now;
        myStack.push(now);
    }
    cout << ">" << endl;
    delete[] temp;
}

template <typename T> void printStackWithAnotherStack(Stack<T>& myStack)
{
    AStack<T> another;
//    LLStack<T> another;

    while (myStack.length() > 0) {
        another.push(myStack.pop());
    }

    bool isFirst = true;
    cout << "<";
    while (another.length() > 0) {
        auto elem = another.pop();
        if (!isFirst) cout << " ";
        else isFirst = false;
        cout << elem;
        myStack.push(elem);
    }
    cout << ">" << endl;
}

int main()
{
    AStack<int> stc;
//    LLStack<int> stc;
    int sz;
    cin >> sz;
    for (int i = 0; i < sz; i++) {
        int x;
        cin >> x;
        stc.push(x);
    }
//    printStack(stc);
    printStackWithAnotherStack(stc);
    bool didPrint;
    while (true)
    {
        didPrint = false;
        int command, param;
        cin >> command >> param;
        bool isOn = true;
        switch (command)
        {
        case 0:
            isOn = false;
            break;
        case 1:
            stc.clear();
            break;
        case 2:
            stc.push(param);
            break;
        case 3:
        {
            try {
                auto ret = stc.pop();
                cout << ret << endl;
            }
            catch (...) {
                cout << "null" << endl;
            }
            didPrint = true;
        }
        break;
        case 4:
        {
            auto len = stc.length();
            cout << len << endl;
            didPrint = true;
        }
        break;
        case 5:
        {
            try {
                auto top = stc.topValue();
                cout << top << endl;
            }
            catch (...) {
                cout << "null" << endl;
            }
            didPrint = true;
        }
        break;
        default:
            break;
        }
        if (!isOn) break;
        if (!didPrint) cout << -1 << endl;
//        printStack(stc);
        printStackWithAnotherStack(stc);
    }
    return 0;
}
