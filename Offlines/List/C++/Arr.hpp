#include "common.hpp"

template <typename T> class AList :public List<T> {
private:
    int maxLength;
    int listLength;
    int chunkLength;
    int curr;
    T* listArray;

    void print() const {
        std::cout << "List Length: " << listLength << " Maximum Length: " << maxLength << " Current Position: " << curr << std::endl;
        for (int i = 0; i <= listLength; i++) {
            if (i == curr) std::cout << "| ";
            if (i < listLength) std::cout << listArray[i] << " ";
        }
        std::cout << std::endl;
    }

    // ostream& operator <<(ostream& out) {
    //     for (int i = 0; i <= listLength; i++) {
    //         if (i == curr) out << "| ";
    //         if (i < listLength) out << listArray[i] << " ";
    //     }
    //     out << endl;
    // }

public:

    //Empty List
    AList(int chunkLength = 0) {
        this->chunkLength = chunkLength;
        listLength = 0;
        maxLength = chunkLength;
        curr = 0;
        listArray = new T[maxLength];
        print();
    }

    //initiated with an array
    AList(int chunkLength, int Y, T* givenList) {
        this->chunkLength = chunkLength;
        maxLength = chunkLength;
        assertm(Y <= maxLength, "Given list is longer than the default initial capacity");
        listLength = Y;
        curr = 0;
        listArray = new T[maxLength];
        for (int i = 0; i < Y; i++) {
            listArray[i] = givenList[i];
        }
        print();
    }

    ~AList() { delete[] listArray; }

    void clear() {
        delete[] listArray;
        curr = 0;
        listLength = 0;
        maxLength = chunkLength;
        listArray = new T[maxLength];
        std::cout << -1 << std::endl;
        print();
    }

    void insert(const T& item) {
        if (listLength == maxLength) {
            maxLength += chunkLength;
            T* tempList = new T[maxLength];
            for (int i = 0; i < curr; i++) {
                tempList[i] = listArray[i];
            }
            for (int i = listLength; i >= curr + 1; i--) {
                tempList[i] = listArray[i - 1];
            }
            tempList[curr] = item;
            delete[] listArray;
            listArray = tempList;
        }
        else {
            for (int i = listLength; i >= curr + 1; i--) {
                listArray[i] = listArray[i - 1];
            }
            listArray[curr] = item;
        }
        listLength++;
        std::cout << -1 << std::endl;
        print();
    }

    void append(const T& item) {
        if (listLength == maxLength) {
            maxLength += chunkLength;
            T* tempList = new T[maxLength];
            for (int i = 0; i < listLength; i++) {
                tempList[i] = listArray[i];
            }
            tempList[listLength] = item;
            delete[] listArray;
            listArray = tempList;
        }
        else {
            listArray[listLength] = item;
        }
        listLength++;
        std::cout << -1 << std::endl;
        print();
    }

    T remove() {
        assertm(curr >= 0 && curr < listLength, "Current index out of bounds");
        auto ret = listArray[curr];
        for (int i = curr + 1; i < listLength; i++) {
            listArray[i - 1] = listArray[i];
        }
        listLength--;
        std::cout << ret << std::endl;
        print();
        return ret;
    }

    void moveToStart() {
        curr = 0;
        std::cout << -1 << std::endl;
        print();
    }

    void moveToEnd() {
        curr = listLength;
        std::cout << -1 << std::endl;
        print();
    }

    void prev() {
        if (curr) curr--;
        std::cout << -1 << std::endl;
        print();
    }

    void next() {
        if (curr <= listLength - 1) curr++;
        std::cout << -1 << std::endl;
        print();
    }

    int length() const {
        std::cout << listLength << std::endl;
        print();
        return listLength;
    }

    int currPos() const {
        std::cout << curr << std::endl;
        print();
        return curr;
    }

    void moveToPos(int pos) {
        assertm(pos >= 0 && pos <= listLength, "Out of bounds");
        curr = pos;
        std::cout << -1 << std::endl;
        print();
    }

    const T& getValue() const {
        assertm(curr >= 0 && curr < listLength, "No current element");
        std::cout << listArray[curr] << std::endl;
        print();
        return listArray[curr];
    }

    int Search(T item) const {
        int ret = -1;
        for (int i = 0; i < listLength; i++) {
            if (listArray[i] == item) {
                ret = i;
                break;
            }
        }
        std::cout << ret << std::endl;
        print();
        return ret;
    }

};