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
const int INF = 2e9;
inline void min_self(int& a, int b) { a = min(a, b); }

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
    // printVector(order);
    // cerr << "Cost: " << current_cost << endl;
    min_cost = min(min_cost, current_cost);
  } while (next_permutation(order.begin(), order.end()));
  return min_cost;
}

int dp_solution(int n, const vector<vector<int>>& cost) {
  vector<vector<int>> dp(n, vector<int>(1 << n, INF));
  for (int i = 0; i < n; i++) dp[i][1 << i] = cost[i][i];
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (!(mask & (1 << i))) continue;
      for (int bit = 0; bit < n; bit++) {
        if (!(mask & (1 << bit))) {
          // city bit is unvisited
          int charge = 0;
          for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) charge += cost[bit][j];
          }
          min_self(dp[bit][mask | (1 << bit)],
                   dp[i][mask] + charge + cost[bit][bit]);
        }
      }
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i < n; i++) min_self(ans, dp[i][(1 << n) - 1]);
  return ans;
}

int optimized_dp_solve(int n, const vector<vector<int>>& A) {
  vector<int> dp(1 << n, INF);
  dp[0] = 0;

  for (int mask = 0; mask < (1 << n); mask++) {
    for (int bit = 0; bit < n; bit++) {
      if (!(mask & (1 << bit))) continue;
      // so bit is set in mask
      int additional_cost = A[bit][bit];
      int prev_mask = mask ^ (1 << bit);
      for (int prev_visited = 0; prev_visited < n; prev_visited++) {
        if (prev_mask & (1 << prev_visited))
          additional_cost += A[bit][prev_visited];
      }
      min_self(dp[mask], dp[prev_mask] + additional_cost);
    }
  }
  return dp.back();
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
  cout << "Bruteforce: " << bruteforce_solution(n, cost)
       << " DP: " << dp_solution(n, cost)
       << " Optimized DP: " << optimized_dp_solve(n, cost) << endl;
}