#include <cstdlib>

template <typename T>
class BSTNode {
 private:
  BSTNode *left, right;
  T element;

 public:
  BSTNode() { left = right = nullptr; }
  BSTNode(const T& element, BSTNode* left = nullptr, BSTNode* right = nullptr) {
    this->element = element;
    this->left = left;
    this->right = right;
  }
  inline T getElement() const { return element; }
  inline BSTNode* getLeft() const { return left; }
  inline BSTNode* getRight() const { return right; }
  inline void setElement(const T& element) { this->element = element; }
  inline void setLeft(BSTNode* left) { this->left = left; }
  inline void setRight(BSTNode* right) { this->right = right; }
};

template <typename T>
class BST {
 private:
  BSTNode* root;
  // private functions for recursive procedure
  BST* insertHelp(BST* node, const T& element);
  BST* deleteHelp(BST* node, const T& element);
  BST* findHelp(BST* node, const T& element);

 public:
  void insert(const T& element) {}
  void delete (const T& element) {}
  bool find(const T& element) const {}
};

template <typename T>
BST<T>::BST* insertHelp(BST* node, const T& element) {
  // got an empty subtree, so create the node
  if (node == nullptr) return new BSTNode(element, nullptr, nullptr);
  auto elem = node->getKey();
  if (elem < element)
    node->setLeft(insertHelp(node->getLeft(), element);
  else if (elem > element) 
    node->setRight(insertHelp(node->getRight(), elem));
}

template <typename T>
BST<T>::BST* deleteHelp(BST* node, const T& element) {}

template <typename T>
BST<T>::BST* findHelp(BST* node, const T& element) {}