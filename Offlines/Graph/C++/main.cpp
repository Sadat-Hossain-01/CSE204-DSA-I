#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define endl "\n"

const bool fileIO = true;
int n, x, l, s;
const int MAX_SIZE = 10005;
int ladder_snake[MAX_SIZE];
int parent[MAX_SIZE];
int dist[MAX_SIZE];

void reset() {
  for (int i = 0; i < MAX_SIZE; i++) {
    parent[i] = ladder_snake[i] = -1;
    dist[i] = 1e8;
  }
}

void visit(int prev, int child, queue<int>& q) {
  parent[child] = prev;
  dist[child] = dist[prev] + 1;
  q.push(child);
}

void bfs(int source) {
  queue<int> q;
  q.push(source);
  dist[source] = 0;
  parent[source] = source;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 1; i <= n; i++) {
      if (now + i > x) continue;
      if (parent[now + i] != -1) continue;
      int destination = now + i;
      dist[destination] = dist[now] + 1;
      int prev = now;
      while (ladder_snake[destination] != -1) {
        parent[destination] = prev;
        dist[destination] = dist[prev] + 1;
        prev = destination;
        destination = ladder_snake[destination];
      }
      visit(prev, destination, q);
    }
  }
}

void dfs(int node, int ancestor) {
  parent[node] = ancestor;
  dist[node] = dist[ancestor] + 1;
  for (int i = 1; i <= n; i++) {
    if (node + i > x) continue;
    if (dist[node + i] >= dist[node] + 1) {
      int destination = node + i;
      dist[destination] = dist[node] + 1;
      int prev = node;
      while (ladder_snake[destination] != -1) {
        parent[destination] = prev;
        dist[destination] = dist[prev] + 1;
        prev = destination;
        destination = ladder_snake[destination];
      }
      dfs(destination, prev);
    }
  }
}

int main() {
  if (fileIO) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }

  int t;
  cin >> t;

  while (t--) {
    reset();
    cin >> n >> x >> l;
    for (int i = 1; i <= l; i++) {
      int ls, le;
      cin >> ls >> le;
      ladder_snake[ls] = le;
    }
    cin >> s;
    for (int i = 1; i <= s; i++) {
      int ss, se;
      cin >> ss >> se;
      ladder_snake[ss] = se;
    }
    dist[0] = -1;
    bfs(1);
    // dfs(1, 0);

    if (parent[x] == -1)
      cout << -1 << endl << "No solution" << endl;
    else {
      cout << dist[x] << endl;
      int now = x;
      stack<int> st;
      while (now != 1) {
        st.push(now);
        now = parent[now];
      }
      st.push(1);
      cout << "1 ";
      st.pop();
      while (!st.empty()) {
        cout << "-> " << st.top();
        st.pop();
      }
      cout << endl;
    }

    int unreachable = 0;
    for (int i = 1; i <= x; i++) {
      if (parent[i] == -1) {
        unreachable++;
        cout << i << " ";
      }
    }
    if (unreachable == 0) cout << "All reachable";
    cout << endl;
  }

  return 0;
}