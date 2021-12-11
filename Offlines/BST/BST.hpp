#pragma once

#include <cstdlib>
#include <iostream>

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
  BSTNode<T> *root;
  // private functions for recursive procedure
  BSTNode<T> *getMin(BSTNode<T> *node) const;
  BSTNode<T> *deleteMin(BSTNode<T> *node);
  BSTNode<T> *insertHelp(BSTNode<T> *node, const T &element);
  BSTNode<T> *removeHelp(BSTNode<T> *node, const T &element);
  const T &findHelp(BSTNode<T> *node, const T &element) const;
  void InTraverseHelp(BSTNode<T> *node) const;
  void PreTraverseHelp(BSTNode<T> *node) const;
  void PostTraverseHelp(BSTNode<T> *node) const;
  void printHelp(BSTNode<T> *node, int level) const;

 public:
  enum Type { In, Pre, Post };
  void insert(const T &element) { root = insertHelp(root, element); }
  void remove(const T &element) { root = removeHelp(root, element); }
  bool find(const T &element) const {
    auto ret = findHelp(root, element);
    return (ret == element);
  }
  void traversal(Type type) {
    if (type == In)
      InTraverseHelp(root);
    else if (type == Pre)
      PreTraverseHelp(root);
    else if (type == Post)
      PostTraverseHelp(root);
    std::cout << "\n";
  }
  void print() { printHelp(root, 0); }
};

template <typename T>
BSTNode<T> *BST<T>::getMin(BSTNode<T> *node) const {
  if (node->getLeft() == nullptr)
    return node;
  else
    return getMin(node->getLeft());
}

template <typename T>
BSTNode<T> *BST<T>::deleteMin(BSTNode<T> *node) {
  if (node->getLeft() == nullptr)
    return node->getRight();
  else {
    node->setLeft(deleteMin(deleteMin(node->getLeft())));
    return node;
  }
}

template <typename T>
BSTNode<T> *BST<T>::insertHelp(BSTNode<T> *node, const T &element) {
  // got an empty subtree, so create the node
  if (node == nullptr) return new BSTNode<T>(element, nullptr, nullptr);
  auto elem = node->getElement();
  if (elem < element)
    node->setLeft(insertHelp(node->getLeft(), element));
  else if (elem > element)
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
    node->setLeft(removeHelp(node->getRight(), element));
  else {  // find the desired key
    BSTNode<T> *temp = node;
    if (node->getRight() == nullptr) {  // has only left child
      node = node->getLeft();
      delete temp;
    } else if (node->getLeft() == nullptr) {  // has only right child
      node = node->getRight();
      delete temp;
    } else {  // both non-empty children
      BSTNode<T> *temp = getMin(node->getRight());
      node->setElement(node->getElement());
      node->setRight(deleteMin(node->getRight()));
      delete temp;
    }
  }
  return node;
}

template <typename T>
const T &BST<T>::findHelp(BSTNode<T> *node, const T &element) const {
  if (node == nullptr) return NULL;
  auto elem = node->getElement();
  if (element < elem)
    return findHelp(node->getLeft(), element);
  else if (element > elem)
    return findHelp(node->getRight(), element);
  else
    return node->getElement();
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
  std::cout << node->getElement() << "(";
  printHelp(node->getLeft(), level + 1);
  std::cout << ")(";
  printHelp(node->getRight(), level + 1);
  std::cout << ")";
}