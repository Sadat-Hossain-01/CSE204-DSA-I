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

inline ll distsquared(const pair<int, int>& p1, const pair<int, int>& p2) {
  return 1LL * (p1.first - p2.first) * (p1.first - p2.first) +
         1LL * (p1.second - p2.second) * (p1.second - p2.second);
}

pair<pair<int, int>, ll> merge(vector<pair<pair<int, int>, int>>& vec, int l,
                               int mid, int r, ll mindistsq) {
  vector<pair<pair<int, int>, int>> temp;

  int mid_x = vec[mid].first.first;
  for (int i = mid; i >= l && vec[i].first.first >= mid_x - (mindistsq + 10);
       i--) {
    temp.push_back(vec[i]);
  }

  mid_x = vec[mid + 1].first.first;
  for (int i = mid + 1;
       i <= r && vec[i].first.first <= mid_x + (mindistsq + 10); i++) {
    temp.push_back(vec[i]);
  }

  sort(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
    return a.first.second < b.first.second;
  });

  // debug(l, mid, r, mid_x, temp);

  ll realmindistsq = 2e18;
  int id1 = temp[0].second, id2 = temp[1].second;

  const int sz = temp.size();
  for (int i = 0; i < sz; i++) {
    for (int j = i + 1; j < min(sz, i + 10); j++) {
      auto cur_distsq = distsquared(temp[i].first, temp[j].first);
      // debug(temp[i].first, temp[j].first, cur_distsq);
      if (cur_distsq < realmindistsq) {
        realmindistsq = cur_distsq;
        id1 = temp[i].second, id2 = temp[j].second;
      }
    }
  }
  return {{id1, id2}, realmindistsq};
}

pair<pair<int, int>, ll> findClosestPairOfPoints(
    vector<pair<pair<int, int>, int>>& vec, int l, int r) {
  if (r - l < 1) return {{-1, -1}, 2e18};
  if (r - l == 1)
    return {{vec[l].second, vec[r].second},
            distsquared(vec[l].first, vec[r].first)};
  int mid = (l + r) / 2;
  auto a = findClosestPairOfPoints(vec, l, mid);
  auto b = findClosestPairOfPoints(vec, mid + 1, r);
  ll minFromTwoHalvesWithoutMerging;
  pair<int, int> point;
  if (a.second <= b.second) {
    minFromTwoHalvesWithoutMerging = a.second;
    point = a.first;
  } else {
    minFromTwoHalvesWithoutMerging = b.second;
    point = b.first;
  }
  // debug(a, b, l, mid, r, minFromTwoHalvesWithoutMerging, point);
  auto fromMerge = merge(vec, l, mid, r, minFromTwoHalvesWithoutMerging);
  // debug(fromMerge.first, fromMerge.second);
  if (fromMerge.second <= minFromTwoHalvesWithoutMerging)
    return fromMerge;
  else
    return {point, minFromTwoHalvesWithoutMerging};
}

void solve() {
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> points(n);  //{x, y}, id
  for (int i = 0; i < n; i++) {
    cin >> points[i].first.first >> points[i].first.second;
    points[i].second = i;
  }
  // debug(points);
  sort(points.begin(), points.end());
  // debug(points);

  auto ret = findClosestPairOfPoints(points, 0, n - 1);
  if (ret.first.first > ret.first.second)
    swap(ret.first.first, ret.first.second);
  cout << ret.first.first << " " << ret.first.second << " " << fixed << setprecision(6)
       << sqrt(ret.second) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;

  for (int tc = 1; tc <= t; tc++) {
    // cout << "Case #" << tc << ": ";
    solve();
  }
}