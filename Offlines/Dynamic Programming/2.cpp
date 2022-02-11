#include <climits>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 2e9;
#define endl "\n"

inline void min_self(int &a, int b) { a = min(a, b); }

template <typename T>
void printTable(const vector<vector<T>> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < vec[i].size(); j++) cerr << vec[i][j] << " ";
    cerr << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> cost(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> cost[i][j];
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
  // printTable(dp);
  cout << ans << endl;
}