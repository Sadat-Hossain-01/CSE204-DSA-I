#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class Node
{
public:
    T item;
    Node *next;
    Node(Node *next = nullptr)
    {
        this->next = next;
    }
    Node(const T &val, Node *next = nullptr)
    {
        this->item = val;
        this->next = next;
    }
};

template <typename T>
class CList
{
public:
    int len;
    Node<T> *head;
    Node<T> *tail;
    CList()
    {
        len = 0;
        head = tail = new Node<T>(nullptr);
    }
    void insert(T prev, T elem)
    {
        auto node = new Node<T>(elem, nullptr);
        if (len == 0)
        {
            tail = node;
            head = node;
            head->next = tail->next = node;
            len++;
            return;
        }
        auto temp = head;
        int searched = 0;
        while (temp->next->item != prev && searched++ < len)
        {
            temp = temp->next;
        }
        if (searched == len)
        {
            cout << "Not found\n";
            return;
        }
        if (temp == tail)
        {
            tail->next = node;
            tail = node;
            node->next = head;
        }
        else
        {
            auto prev_next = temp->next;
            temp->next = node;
            node->next = prev_next->next;
        }
        len++;
    }
    void print()
    {
        auto temp = head;
        while (true)
        {
            cout << temp->item << " ";
            if (temp == tail)
            {
                cout << "\n";
                return;
            }
        }
    }
};

int main()
{
    CList<int> test;
    test.insert(1, NULL);
    test.insert(2, 1);
    test.print();
}