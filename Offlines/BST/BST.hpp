#pragma once

#include <cstdlib>

#include "BSTNode.hpp"

template <typname E, typename T>
class BST {
 private:
  BSTNode<E, T>* root;
  int nodeCount;

  // private helper functions for maintaining recursive procedure
  BSTNode<E, T>* insertHelp(BSTNode<E, T>* node, const E& key, const T& value);
  BSTNode<E, T>* deleteHelp(BSTNode<E, T>* node, const E& key);
  BSTNode<E, T>* findHelp(BSTNode<E, T>* node, const E& key) const;
  BSTNode<E, T>* getMin(BSTNode<E, T>* node) const;
  void printHelp(BSTNode<E, T>* node, int level) const;
  void clearHelp(BSTNode<E, T>* node);  // for destructor

 public:
  BST() {
    root = nullptr;
    nodeCount = 0;
  }
  ~BST() {
    clearHelp(root);
    root = nullptr;
    nodeCount = 0;
  }
  void insert(const E& key, const T& value) {
    root = insertHelp(root, key, value);
    nodeCount++;
  }
};

template <typename E, typename T>
BSTNode<E, T>* BST<E, T>::findHelp(BSTNode<E, T>* node, const E& key) const {
  if (node == null) return nullptr;
  auto node_key = node->getKey();
  if (key < node_key)
    return findHelp(node->getLeft(), key);
  else if (key > node_key)
    return findHelp(node->getRight(), key);
  else
    return node->getValue();
}

template <typename E, typename T>
BSTNode<E, T>* BST<E, T>::insertHelp(BSTNode<E, T>* node, const E& key,
                                     const T& value) {
  // got an empty tree, so create the node
  if (node == nullptr) return new BSTNode<E, T>(key, value, nullptr, nullptr);
  auto node_key = node->getKey();
  if (key < node_key)
    node->setLeft(insertHelp(node->getLeft(), key, value));
  else
    node->setRight(insertHelp(node->getRight(), key, value));
  return node;
}

template <typename E, typename T>
BSTNode<E, T>* BST<E, T>::getMin(BSTNode<E, T>* node) const {
  if (node->getLeft() == nullptr)
    return node;
  else
    return getMin(node->getLeft());
}

template <typename E, typename T>
BSTNode<E, T>* BST<E, T>::deleteMin(BSTNode<E, T>* node) {
  if (node->getLeft() == nullptr)
    return node->getRight();
  else {
    node->setLeft(deleteMin(deleteMin(node->getLeft())));
    return node;
  }
}

template <typename E, typename T>
BSTNode<E, T>* BST<E, T>::deleteHelp(BSTNode<E, T>* node, const E& key) {
  if (node == nullptr) return nullptr;
  auto node_key = node->getKey();
  if (key < node_key)
    node->setLeft(deleteHelp(node->getLeft(), key));
  else if (key > node_key)
    node->setRight(deleteHelp(node->getRight(), key));
  else {  // found the desired key
    BSTNode<E, T>* temp = node;
    if (node->getRight() == nullptr) {  // only a left child
      node = node->getLeft();
      delete temp;
    } else if (node->getLeft() == nullptr) {  // only a right child
      node = node->getRight();
      delete temp;
    } else {  // Both children are non-empty
      BSTNode<E, T>* temp = getMin(node->getRight());
      node->setValue(temp->getValue());
      node->setKey(temp->getKey());
      node->setRight(deleteMin(node->getRight()));
      delete temp;
    }
  }
}
