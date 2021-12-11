#include <cstdlib>

template <typename T>
class BSTNode {
 private:
  BSTNode *left, right;
  T element;

 public:
  BSTNode() { left = right = nullptr; }
  BSTNode(const T &element, BSTNode *left = nullptr, BSTNode *right = nullptr) {
    this->element = element;
    this->left = left;
    this->right = right;
  }
  inline T getElement() const { return element; }
  inline BSTNode *getLeft() const { return left; }
  inline BSTNode *getRight() const { return right; }
  inline void setElement(const T &element) { this->element = element; }
  inline void setLeft(BSTNode *left) { this->left = left; }
  inline void setRight(BSTNode *right) { this->right = right; }
};

template <typename T>
class BST {
 private:
  BSTNode *root;
  // private functions for recursive procedure
  BST *insertHelp(BST *node, const T &element);
  BST *deleteHelp(BST *node, const T &element);
  BST *findHelp(BST *node, const T &element) const;
  BST *getMin(BST *node) const;
  BST *deleteMin(BST *node);

 public:
  void insert(const T &element) { root = insertHelp(root, element); }
  void delete (const T &element) { root = deleteHelp(root, element); }
  bool find(const T &element) const {
    auto ret = findHelp(root, element);
    return (ret != nullptr);
  }
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
  if (node == nullptr) return new BSTNode(element, nullptr, nullptr);
  auto elem = node->getElement();
  if (elem < element)
    node->setLeft(insertHelp(node->getLeft(), element);
  else if (elem > element) 
    node->setRight(insertHelp(node->getRight(), element));
  return node;
}

template <typename T>
BSTNode<T> *BST<T>::deleteHelp(BSTNode<T> *node, const T &element) {
  if (node == nullptr) return nullptr;
  auto elem = node->getElement();
  if (element < elem)
    node->setLeft(deleteHelp(node->getLeft(), element));
  else if (element > elem)
    node->setLeft(deleteHelp(node->getRight(), element));
  else {  // find the desired key
    BSTNode *temp = node;
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
}

template <typename T>
BSTNode<T> *BST<T>::findHelp(BSTNode *node, const T &element) {
  if (node == null) return nullptr;
  auto elem = node->getElement();
  if (element < elem)
    return findHelp(node->getLeft(), element);
  else if (element > elem)
    return findHelp(node->getRight(), element);
  else
    return node->getValue();
}