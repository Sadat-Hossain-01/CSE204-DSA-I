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
  BSTNode<T> *getMin(BSTNode<T> *node) const;
  BSTNode<T> *getMax(BSTNode<T> *node) const;
  BSTNode<T> *deleteMin(BSTNode<T> *node);
  BSTNode<T> *deleteMax(BSTNode<T> *node);
  BSTNode<T> *insertHelp(BSTNode<T> *node, const T &element);
  BSTNode<T> *removeHelp(BSTNode<T> *node, const T &element);
  bool findHelp(BSTNode<T> *node, const T &element) const;
  void InTraverseHelp(BSTNode<T> *node) const;
  void PreTraverseHelp(BSTNode<T> *node) const;
  void PostTraverseHelp(BSTNode<T> *node) const;
  void printHelp(BSTNode<T> *node, int level) const;

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
      root = insertHelp(root, element);
    nodeCount++;
  }
  void remove(const T &element) {
    int prev_count = nodeCount;
    if (nodeCount > 0) root = removeHelp(root, element);
    if (prev_count == nodeCount) throw "Invalid Operation";
  }
  bool find(const T &element) const {
    if (nodeCount == 0) return false;
    return findHelp(root, element);
  }
  void traversal(Type type) {
    if (nodeCount > 0) {
      if (type == In)
        InTraverseHelp(root);
      else if (type == Pre)
        PreTraverseHelp(root);
      else if (type == Post)
        PostTraverseHelp(root);
    }
    std::cout << "\n";
  }
  void print() {
    if (nodeCount > 0) printHelp(root, 0);
    std::cout << "\n";
  }
};

template <typename T>
BSTNode<T> *BST<T>::getMin(BSTNode<T> *node) const {
  assertm(node != nullptr, "Null pointer exception in getMin()");
  if (node->getLeft() == nullptr)
    return node;
  else
    return getMin(node->getLeft());
}

template <typename T>
BSTNode<T> *BST<T>::getMax(BSTNode<T> *node) const {
  assertm(node != nullptr, "Null pointer exception in getMax()");
  if (node->getRight() == nullptr)
    return node;
  else
    return getMax(node->getRight());
}

template <typename T>
BSTNode<T> *BST<T>::deleteMin(BSTNode<T> *node) {
  assertm(node != nullptr, "Null pointer exception in deleteMin()");
  if (node->getLeft() == nullptr)
    return node->getRight();
  else {
    node->setLeft(deleteMin(node->getLeft()));
    return node;
  }
}

template <typename T>
BSTNode<T> *BST<T>::deleteMax(BSTNode<T> *node) {
  assertm(node != nullptr, "Null pointer exception in deleteMax()");
  if (node->getRight() == nullptr)
    return node->getLeft();
  else {
    node->setRight(deleteMax(node->getRight()));
    return node;
  }
}

template <typename T>
BSTNode<T> *BST<T>::insertHelp(BSTNode<T> *node, const T &element) {
  // got an empty subtree, so create the node
  if (node == nullptr) {
    nodeCount++;
    return new BSTNode<T>(element, nullptr, nullptr);
  }
  auto elem = node->getElement();
  if (element < elem)
    node->setLeft(insertHelp(node->getLeft(), element));
  else if (element >= elem)
    node->setRight(insertHelp(node->getRight(), element));
  return node;
}

template <typename T>
BSTNode<T> *BST<T>::removeHelp(BSTNode<T> *node, const T &element) {
  if (node == nullptr) return nullptr;
  auto elem = node->getElement();
  if (element < elem)
    node->setLeft(removeHelp(node->getLeft(), element));
  else if (element > elem)
    node->setRight(removeHelp(node->getRight(), element));
  else {  // find the desired key
    BSTNode<T> *temp = node;
    if (node->getRight() == nullptr) {  // has only left child
      node = node->getLeft();
      delete temp;
    } else if (node->getLeft() == nullptr) {  // has only right child
      node = node->getRight();
      delete temp;
    } else {  // both non-empty children
      BSTNode<T> *temp = getMax(node->getLeft());
      node->setElement(temp->getElement());
      node->setLeft(deleteMax(node->getLeft()));
      delete temp;
    }
    nodeCount--;
  }
  return node;
}

template <typename T>
bool BST<T>::findHelp(BSTNode<T> *node, const T &element) const {
  if (node == nullptr) return false;
  auto elem = node->getElement();
  if (element < elem)
    return findHelp(node->getLeft(), element);
  else if (element > elem)
    return findHelp(node->getRight(), element);
  else
    return true;
}

template <typename T>
void BST<T>::InTraverseHelp(BSTNode<T> *node) const {
  if (node == nullptr) return;
  InTraverseHelp(node->getLeft());
  std::cout << node->getElement() << " ";
  InTraverseHelp(node->getRight());
}

template <typename T>
void BST<T>::PreTraverseHelp(BSTNode<T> *node) const {
  if (node == nullptr) return;
  std::cout << node->getElement() << " ";
  PreTraverseHelp(node->getLeft());
  PreTraverseHelp(node->getRight());
}

template <typename T>
void BST<T>::PostTraverseHelp(BSTNode<T> *node) const {
  if (node == nullptr) return;
  PostTraverseHelp(node->getLeft());
  PostTraverseHelp(node->getRight());
  std::cout << node->getElement() << " ";
}

template <typename T>
void BST<T>::printHelp(BSTNode<T> *node, int level) const {
  if (node == nullptr) return;
  std::cout << node->getElement();
  if (node->getLeft() == nullptr && node->getRight() == nullptr) return;
  std::cout << "(";
  printHelp(node->getLeft(), level + 1);
  std::cout << ")(";
  printHelp(node->getRight(), level + 1);
  std::cout << ")";
}