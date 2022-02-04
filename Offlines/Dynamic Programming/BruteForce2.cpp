#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

template <typename T>
void printVector(const vector<T>& vec) {
  for (int i = 0; i < vec.size(); i++) cerr << vec[i] << " ";
  cerr << endl;
}

int bruteforce_solution(int n, const vector<vector<int>>& cost) {
  int min_cost = INT_MAX;
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  do {
    int current_cost = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        current_cost += cost[order[i]][order[j]];
      }
    }
    printVector(order);
    cerr << "Cost: " << current_cost << endl;
    min_cost = min(min_cost, current_cost);
  } while (next_permutation(order.begin(), order.end()));
  return min_cost;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> cost(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> cost[i][j];
    }
  }
  cout << bruteforce_solution(n, cost) << endl;
}