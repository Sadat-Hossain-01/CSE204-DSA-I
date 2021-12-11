#pragma once

template <typename E, typename T>
class BSTNode {
 private:
  E key;
  T value;
  BSTNode* left;
  BSTNode* right;

 public:
  BSTNode() { left = right = nullptr; }
  BSTNode(const E& key, const T& value, BSTNode* left = nullptr,
          BSTNode* right = nullptr) {
    this->key = key;
    this->value = value;
    this->left = left;
    this->right = right;
  }
  inline void setKey(const E& key) { this->key = key; }
  inline void setValue(const T& value) { this->value = value; }
  inline void setLeft(BSTNode* left) { this->left = left; }
  inline void setRight(BSTNode* right) { this->right = right; }
  inline E& getKey() const { return key; }
  inline T& getValue() const { return value; }
  inline BSTNode* getLeft() const { return left; }
  inline BSTNode* getRight() const { return right; }
  inline bool isLeaf() const { return (left == nullptr && right == nullptr); }
};