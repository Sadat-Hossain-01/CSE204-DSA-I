#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long ll;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}

#ifndef ONLINE_JUDGE
#define debug(x...)             \
  cerr << "[" << #x << "] = ["; \
  _print(x)
#else
#define debug(x...)
#endif

ll merge(vector<int>& vec, int l, int mid, int r) {
  int len1 = mid - l + 1;
  int len2 = r - mid;
  ll ans = 0;
  vector<int> temp(vec.begin() + l, vec.begin() + r + 1);
  int ax = 0, bx = len1, idx = l;
  while (ax < len1 && bx < len1 + len2) {
    if (temp[ax] <= temp[bx])
      vec[idx++] = temp[ax++];
    else {
      vec[idx++] = temp[bx++];
      ans += len1 - ax;
    }
  }
  while (ax < len1) vec[idx++] = temp[ax++];
  while (bx < len1 + len2) vec[idx++] = temp[bx++];
  return ans;
}

ll inversion(vector<int>& vec, int l, int r) {
  if (l >= r) return 0;
  int mid = l + (r - l) / 2;
  ll ans = 0;
  ans += inversion(vec, l, mid);
  ans += inversion(vec, mid + 1, r);
  ans += merge(vec, l, mid, r);
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  cout << inversion(nums, 0, n - 1) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}