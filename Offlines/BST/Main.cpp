#include <fstream>
#include <iostream>
#include <string>

#include "BST.hpp"
using namespace std;

#define endl "\n"

const bool isCommentOn = true;

int main() {
  BST<int> tr;
  while (true) {
    char op;
    cin >> op;
    if (isCommentOn) cout << "Operation: " << op;
    if (op == 'F') {
      int elem;
      cin >> elem;
      if (isCommentOn) cout << " " << elem << endl;
      cout << (tr.find(elem) ? "True" : "False") << endl;
    } else if (op == 'I') {
      int elem;
      cin >> elem;
      if (isCommentOn) cout << " " << elem << endl;
      tr.insert(elem);
      tr.print();
    } else if (op == 'D') {
      int elem;
      cin >> elem;
      if (isCommentOn) cout << " " << elem << endl;
      tr.remove(elem);
      tr.print();
    } else if (op == 'T') {
      string type;
      cin >> type;
      if (isCommentOn) cout << " " << type << endl;
      if (type == "In")
        tr.traversal(tr.In);
      else if (type == "Pre")
        tr.traversal(tr.Pre);
      else if (type == "Post")
        tr.traversal(tr.Post);
    }
  }
}