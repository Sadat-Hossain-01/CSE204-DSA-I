#include "Arr.hpp"
using namespace std;

int main() {
    int init_len, chunk_size;
    cin >> init_len >> chunk_size;

    int* nums = new int[init_len];
    for (int i = 0; i < init_len; i++) {
        cin >> nums[i];
    }
    AList<int> myList(chunk_size, init_len, nums);
    delete[] nums;

    while (true) {
        int Q, P;
        cin >> Q >> P;
        if (Q == 0) break;
        switch (Q)
        {
        case 1:
            myList.clear();
            break;
        case 2:
            myList.insert(P);
            break;
        case 3:
            myList.append(P);
            break;
        case 4:
            myList.remove();
            break;
        case 5:
            myList.moveToStart();
            break;
        case 6:
            myList.moveToEnd();
            break;
        case 7:
            myList.prev();
            break;
        case 8:
            myList.next();
            break;
        case 9:
            myList.length();
            break;
        case 10:
            myList.currPos();
            break;
        case 11:
            myList.moveToPos(P);
            break;
        case 12:
            myList.getValue();
            break;
        case 13:
            myList.Search(P);
            break;
        default:
            break;
        }
    }
}