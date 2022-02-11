#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define endl "\n"
const int NINF = -2e9;
inline void max_self(int &a, int b) { a = max(a, b); }

template <typename T>
void printTable(const vector<vector<T>> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < vec[i].size(); j++) cerr << vec[i][j] << " ";
    cerr << endl;
  }
}

int LCS(const string &s1, const string &s2, vector<vector<int>> &dp) {
  const int m = s1.size();
  const int n = s2.size();
  dp[0][0] = 0;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else {
        if (s1[i - 1] != s2[j - 1]) {
          if (dp[i - 1][j] >= dp[i][j - 1])
            max_self(dp[i][j], dp[i - 1][j]);
          else
            max_self(dp[i][j], dp[i][j - 1]);
        } else
          dp[i][j] = dp[i - 1][j - 1] + 1;
      }
    }
  }
  return dp[m][n];
}

string getLCS(const string &a, const string &b, const vector<vector<int>> &dp) {
  string ans = "";
  int ax = (int)dp.size() - 1, bx = (int)dp[0].size() - 1;
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
  return ans;
}

int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  const int m = a.size();
  const int n = b.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, NINF));
  // LCS Length
  int len = LCS(a, b, dp);
  // LCS Retrieving
  string LCS = getLCS(a, b, dp);
  assert(LCS.size() == len);
  //    printTable(dp);
  cout << len << endl << LCS << endl;
}