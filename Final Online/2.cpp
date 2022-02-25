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

bool on = true;
int m, n;

ll kruskal(const vector<pair<int, pair<int, int>>>& edges) {
  vector<int> tree_id(m);
  iota(tree_id.begin(), tree_id.end(), 0);
  ll min_cost = 0;
  for (const auto& e : edges) {
    if (tree_id[e.second.first] != tree_id[e.second.second]) {
      min_cost += e.first;

      int old_id = tree_id[e.second.first];
      int new_id = tree_id[e.second.second];
      for (int i = 0; i < m; i++) {
        if (tree_id[i] == old_id) tree_id[i] = new_id;
      }
    }
  }
  return min_cost;
}

void solve() {
  cin >> m >> n;
  if (m == n && m == 0) {
    on = false;
    return;
  }
  ll total_length = 0;
  vector<pair<int, pair<int, int>>> edges(n);
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    edges[i] = {z, {x, y}};
    total_length += z;
  }
  sort(edges.begin(), edges.end());
  cout << total_length - kruskal(edges) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (on)
    // cout << "Case #" << tc << ": ";
    solve();
}