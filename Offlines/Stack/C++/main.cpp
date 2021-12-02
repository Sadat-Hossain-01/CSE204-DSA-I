#include "AStack.hpp"
#include "LLStack.hpp"
#include <iostream>
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

int main()
{
//    Stack<int>* stc = new AStack<int>();
    Stack<int>* stc = new LLStack<int>();
    int sz;
    cin >> sz;
    for (int i=0; i<sz; i++){
        int x;
        cin >> x;
        stc->push(x);
    }
    printStack(*stc);
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
            stc->clear();
            break;
        case 2:
            stc->push(param);
            break;
        case 3:
        {
            try{
                auto ret = stc->pop();
                cout << ret << endl;
            }
            catch(...){
                cout << "null" << endl;
            }
            didPrint = true;
        }
        break;
        case 4:
        {
            auto len = stc->length();
            cout << len << endl;
            didPrint = true;
        }
        break;
        case 5:
        {
            try{
                auto top = stc->topValue();
                cout << top << endl;
            }
            catch(...){
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
        printStack(*stc);
    }
    return 0;
}
