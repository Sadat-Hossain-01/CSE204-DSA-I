#include <iostream>
#include <vector>

#include "BST.hpp"

using namespace std;

int main() {
  BST<int> hello;
  vector<int> nums;
  for (int i = 0; i < 100; i++) {
    auto num = rand() % 100;
    hello.insert(num);
    nums.emplace_back(num);
    hello.print();
  }
  while (!nums.empty()) {
    hello.remove(nums.back());
    hello.print();
    nums.pop_back();
  }
}