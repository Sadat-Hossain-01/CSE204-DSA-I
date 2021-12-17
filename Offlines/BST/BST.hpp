#pragma once

#include <cassert>
#include <cstdlib>
#include <iostream>
#define assertm(exp, msg) assert(((void)msg, exp))

template <typename T>
class BSTNode {
 private:
  BSTNode<T> *left;
  BSTNode<T> *right;
  T element;

 public:
  BSTNode() { left = right = nullptr; }
  BSTNode(const T &element, BSTNode *left = nullptr, BSTNode *right = nullptr) {
    this->element = element;
    this->left = left;
    this->right = right;
  }
  inline const T &getElement() const { return element; }
  inline BSTNode *getLeft() const { return left; }
  inline BSTNode *getRight() const { return right; }
  inline void setElement(const T &element) { this->element = element; }
  inline void setLeft(BSTNode *left) { this->left = left; }
  inline void setRight(BSTNode *right) { this->right = right; }
};

template <typename T>
class BST {
 private:
  int nodeCount;
  BSTNode<T> *root;
  // private functions for recursive procedure
  BSTNode<T> *myGetMin(BSTNode<T> *node) const;
  BSTNode<T> *myGetMax(BSTNode<T> *node) const;
  BSTNode<T> *myDeleteMin(BSTNode<T> *node);
  BSTNode<T> *myDeleteMax(BSTNode<T> *node);
  BSTNode<T> *myInsert(BSTNode<T> *node, const T &element);
  BSTNode<T> *myRemove(BSTNode<T> *node, const T &element);
  bool myFind(BSTNode<T> *node, const T &element) const;
  void myInTraversal(BSTNode<T> *node) const;
  void myPreTraversal(BSTNode<T> *node) const;
  void myPostTraversal(BSTNode<T> *node) const;
  void myPrint(BSTNode<T> *node, int level) const;

 public:
  enum Type { In, Pre, Post };
  BST() {
    nodeCount = 0;
    root = new BSTNode<T>();
  }
  void insert(const T &element) {
    if (nodeCount == 0)
      root->setElement(element);
    else
      root = myInsert(root, element);
    nodeCount++;
  }
  void remove(const T &element) {
    int prev_count = nodeCount;
    if (nodeCount > 0) root = myRemove(root, element);
    if (prev_count == nodeCount) throw "Invalid Operation";
  }
  bool find(const T &element) const {
    if (nodeCount == 0) return false;
    return myFind(root, element);
  }
  void traversal(Type type) {
    if (nodeCount > 0) {
      if (type == In)
        myInTraversal(root);
      else if (type == Pre)
        myPreTraversal(root);
      else if (type == Post)
        myPostTraversal(root);
    }
    std::cout << "\n";
  }
  void print() {
    if (nodeCount > 0) myPrint(root, 0);
    std::cout << "\n";
  }
};

template <typename T>
BSTNode<T> *BST<T>::myGetMin(BSTNode<T> *node) const {
  assertm(node != nullptr, "Null pointer exception in myGetMin()");
  if (node->getLeft() == nullptr)
    return node;
  else
    return myGetMin(node->getLeft());
}

template <typename T>
BSTNode<T> *BST<T>::myGetMax(BSTNode<T> *node) const {
  assertm(node != nullptr, "Null pointer exception in myGetMax()");
  if (node->getRight() == nullptr)
    return node;
  else
    return myGetMax(node->getRight());
}

template <typename T>
BSTNode<T> *BST<T>::myDeleteMin(BSTNode<T> *node) {
  assertm(node != nullptr, "Null pointer exception in myDeleteMin()");
  if (node->getLeft() == nullptr)
    return node->getRight();
  else {
    node->setLeft(myDeleteMin(node->getLeft()));
    return node;
  }
}

template <typename T>
BSTNode<T> *BST<T>::myDeleteMax(BSTNode<T> *node) {
  assertm(node != nullptr, "Null pointer exception in myDeleteMax()");
  if (node->getRight() == nullptr)
    return node->getLeft();
  else {
    node->setRight(myDeleteMax(node->getRight()));
    return node;
  }
}

template <typename T>
BSTNode<T> *BST<T>::myInsert(BSTNode<T> *node, const T &element) {
  // got an empty subtree, so create the node
  if (node == nullptr) {
    nodeCount++;
    return new BSTNode<T>(element, nullptr, nullptr);
  }
  auto elem = node->getElement();
  if (element < elem)
    node->setLeft(myInsert(node->getLeft(), element));
  else if (element >= elem)
    node->setRight(myInsert(node->getRight(), element));
  return node;
}

template <typename T>
BSTNode<T> *BST<T>::myRemove(BSTNode<T> *node, const T &element) {
  if (node == nullptr) return nullptr;
  auto elem = node->getElement();
  if (element < elem)
    node->setLeft(myRemove(node->getLeft(), element));
  else if (element > elem)
    node->setRight(myRemove(node->getRight(), element));
  else {  // found the desired key
    BSTNode<T> *temp = node;
    if (node->getRight() == nullptr) {  // has only left child
      node = node->getLeft();
      delete temp;
    } else if (node->getLeft() == nullptr) {  // has only right child
      node = node->getRight();
      delete temp;
    } else {  // both non-empty children
      BSTNode<T> *temp = myGetMax(node->getLeft());
      node->setElement(temp->getElement());
      node->setLeft(myDeleteMax(node->getLeft()));
      delete temp;
    }
    nodeCount--;
  }
  return node;
}

template <typename T>
bool BST<T>::myFind(BSTNode<T> *node, const T &element) const {
  if (node == nullptr) return false;
  auto elem = node->getElement();
  if (element < elem)
    return myFind(node->getLeft(), element);
  else if (element > elem)
    return myFind(node->getRight(), element);
  else
    return true;
}

template <typename T>
void BST<T>::myInTraversal(BSTNode<T> *node) const {
  if (node == nullptr) return;
  myInTraversal(node->getLeft());
  std::cout << node->getElement() << " ";
  myInTraversal(node->getRight());
}

template <typename T>
void BST<T>::myPreTraversal(BSTNode<T> *node) const {
  if (node == nullptr) return;
  std::cout << node->getElement() << " ";
  myPreTraversal(node->getLeft());
  myPreTraversal(node->getRight());
}

template <typename T>
void BST<T>::myPostTraversal(BSTNode<T> *node) const {
  if (node == nullptr) return;
  myPostTraversal(node->getLeft());
  myPostTraversal(node->getRight());
  std::cout << node->getElement() << " ";
}

template <typename T>
void BST<T>::myPrint(BSTNode<T> *node, int level) const {
  if (node == nullptr) return;
  std::cout << node->getElement();
  if (node->getLeft() == nullptr && node->getRight() == nullptr) return;
  std::cout << "(";
  myPrint(node->getLeft(), level + 1);
  std::cout << ")(";
  myPrint(node->getRight(), level + 1);
  std::cout << ")";
}