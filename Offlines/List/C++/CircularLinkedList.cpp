#include <iostream>
#include <cstdlib>
using namespace std;

#define endl "\n"

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
    void insert(T elem, T prev)
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
        while (searched <= len)
        {
            if (temp->item == prev)
                break;
            searched++;
            temp = temp->next;
        }
        if (searched > len)
        {
            cout << "Not found\n";
        }
        else
        {
            if (temp == tail)
            {
                // node->next = tail->next;
                node->next = head;
                temp->next = node;
                tail = node;
            }
            else
            {
                node->next = temp->next;
                temp->next = node;
            }
            len++;
        }
    }
    friend ostream &operator<<(ostream &out, const CList<T> &any)
    {
        auto temp = any.head;
        int printed = 0;
        while (++printed <= 2 * any.len)
        {
            out << temp->item << " ";
            temp = temp->next;
        }
        out << endl;
        return out;
    }
};

int main()
{
    CList<int> test;
    test.insert(1, (int)NULL);
    while (true)
    {
        int prev, item;
        cin >> prev >> item;
        test.insert(item, prev);
        cout << test;
    }
    cout << test;
}