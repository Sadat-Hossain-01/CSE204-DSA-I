#include <iostream>
#include <string>

#include "BST.hpp"
using namespace std;

#define endl "\n"

const bool isCommentOn = false;

int main() {
  BST<int> myTree;

  while (true) {
    char op;
    cin >> op;

    if (isCommentOn) cout << "Operation: " << op;

    if (op == 'F') {
      int elem;
      cin >> elem;
      if (isCommentOn) cout << " " << elem << endl;
      cout << (myTree.find(elem) ? "True" : "False") << endl;
    } else if (op == 'I') {
      int elem;
      cin >> elem;
      if (isCommentOn) cout << " " << elem << endl;
      myTree.insert(elem);
      myTree.print();
    } else if (op == 'D') {
      int elem;
      cin >> elem;
      if (isCommentOn) cout << " " << elem << endl;
      try {
        myTree.remove(elem);
        myTree.print();
      } catch (...) {
        cout << "Invalid Operation" << endl;
      }
    } else if (op == 'T') {
      string type;
      cin >> type;
      if (isCommentOn) cout << " " << type << endl;
      if (type == "In")
        myTree.traversal(myTree.In);
      else if (type == "Pre")
        myTree.traversal(myTree.Pre);
      else if (type == "Post")
        myTree.traversal(myTree.Post);
    } else if (op == 'E')
      break;
  }

  return 0;
}