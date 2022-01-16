#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define endl "\n"
const bool fileIO = true, isCommentOn = false;
int n, x, l, s;
const int MAX_SIZE = 10005;
int ladder_snake[MAX_SIZE];
bool pushed[MAX_SIZE];
int parent[MAX_SIZE];
int dist[MAX_SIZE];

void reset() {
  dist[0] = -1;
  parent[0] = -1;
  for (int i = 1; i < MAX_SIZE; i++) {
    parent[i] = -1;
    ladder_snake[i] = i;
    dist[i] = 1e8;
    pushed[i] = false;
  }
}

void setParent(int node, int par) {
  if (isCommentOn) cout << "\tSet parent[" << node << "] = " << par << endl;
  parent[node] = par;
}

void setDistance(int node, int d) {
  if (isCommentOn) cout << "\tSet dist[" << node << "] = " << d << endl;
  dist[node] = d;
}

void setBoth(int node, int par, int dis) {
  setParent(node, par);
  setDistance(node, dis);
}

void bfs(int node) {
  queue<int> q;
  q.push(node);
  pushed[node] = true;
  setBoth(node, node, 0);
  while (!q.empty()) {
    int current = q.front();
    int roll = dist[current] + 1;
    q.pop();
    if (isCommentOn) cout << "Popped " << current << endl;
    for (int i = 1; i <= min(n, x - current); i++) {
      int destination = current + i;
      if (parent[destination] != -1) continue;
      int previous = current;
      while (destination != ladder_snake[destination]) {
        setBoth(destination, previous, roll);
        previous = destination;
        destination = ladder_snake[destination];
      }

      if (!pushed[destination]) {
        setBoth(destination, previous, roll);
        q.push(destination);
        pushed[destination] = true;
        if (isCommentOn) cout << "\tPushed " << destination << endl;
      }
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
    bfs(1);

    if (isCommentOn) {
      for (int i = 1; i <= x; i++) {
        cout << "Node: " << i << " Parent: " << parent[i]
             << " LS: " << ladder_snake[i] << " Distance: " << dist[i] << endl;
      }
    }

    if (parent[x] == -1)
      cout << -1 << endl << "No solution" << endl;
    else {
      cout << dist[x] << endl;
      int current = x;
      stack<int> st;
      while (current != 1) {
        st.push(current);
        current = parent[current];
      }
      st.push(1);
      cout << "1";
      st.pop();
      while (!st.empty()) {
        cout << " -> " << st.top();
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
    cout << endl << endl;
  }
}
