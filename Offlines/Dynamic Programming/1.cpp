#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int NINF = -2e9;
#define endl "\n"

inline void max_self(int &a, int b) { a = max(a, b); }

template <typename T>
void printTable(const vector<vector<T>> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < vec[i].size(); j++) cerr << vec[i][j] << " ";
    cerr << endl;
  }
}

int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  int m = a.size();
  int n = b.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, NINF));
  // LCS Length
  dp[0][0] = 0;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else {
        if (a[i - 1] != b[j - 1])
          max_self(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        else
          max_self(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }
  // LCS Retrieving
  string ans = "";
  int ax = m, bx = n;
  while (ax && bx) {
    if (dp[ax][bx] == dp[ax - 1][bx - 1] + 1 && a[ax - 1] == b[bx - 1]) {
      ans.push_back(a[ax - 1]);
      ax--;
      bx--;
    } else if (dp[ax - 1][bx] >= dp[ax][bx - 1])
      ax--;
    else
      bx--;
  }
  reverse(ans.begin(), ans.end());
  assert(ans.size() == dp[m][n]);
  //    printTable(dp);
  cout << dp[m][n] << endl << ans << endl;
}