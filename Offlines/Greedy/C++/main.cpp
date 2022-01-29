#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> prices(n);
  for (int &i : prices) cin >> i;
  sort(prices.rbegin(), prices.rend());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += ((i + k) / k) * prices[i];
  }
  cout << ans << endl;
  return 0;
}