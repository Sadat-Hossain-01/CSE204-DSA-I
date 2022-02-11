#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"
const int INF = 2e9;
inline void min_self(int& a, int b) { a = min(a, b); }

int solve(int n, const vector<vector<int>>& A) {
  vector<int> dp(1 << n, INF);
  dp[0] = 0;

  for (int mask = 0; mask < (1 << n); mask++) {
    for (int bit = 0; bit < n; bit++) {
      if (!(mask & (1 << bit))) continue;
      // so bit is set in mask
      // now we assume that bit is the last visited city in this mask
      // hence we seek to know what the minimum cost to visit the immediately
      // previous city was
      // that is we want to know dp[prev_mask], where prev_mask has all bits set
      // as in mask, except for this "bit"
      int additional_cost = A[bit][bit];
      int prev_mask = mask ^ (1 << bit);
      for (int prev_visited = 0; prev_visited < n; prev_visited++) {
        if (prev_mask & (1 << prev_visited))
          additional_cost += A[bit][prev_visited];
      }
      // minimize dp[mask]
      min_self(dp[mask], dp[prev_mask] + additional_cost);
    }
  }
  // the ans is dp[(1<<n) - 1], which is the last value of dp vector
  return dp.back();
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> A(n, vector<int>(n));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> A[i][j];

  cout << solve(n, A) << endl;

  return 0;
}