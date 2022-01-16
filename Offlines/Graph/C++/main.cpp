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
int parent[MAX_SIZE];
int dist[MAX_SIZE];

void reset() {
  for (int i = 0; i < MAX_SIZE; i++) {
    parent[i] = -1;
    ladder_snake[i] = i;
    dist[i] = 1e8;
  }
  dist[0] = -1;
}

void visit(int node, int immediate_parent, int ancestor) {
  if (isCommentOn)
    cout << "Child: " << node << " Parent: " << immediate_parent << endl;
  parent[node] = immediate_parent;
  dist[node] = dist[ancestor] + 1;
}

void bfs(int source) {
  queue<int> q;
  q.push(source);
  dist[source] = 0;
  parent[source] = 1;
  while (!q.empty()) {
    int current = q.front();
    q.pop();
    for (int i = 1; i <= min(n, x - current); i++) {
      int destination = current + i;
      if (parent[destination] != -1)
        continue;  // destination is already
                   // visited
      int prev = current;
      while (ladder_snake[destination] !=
             destination) {  // if there is any snake or ladder in this cell
        if (isCommentOn) cout << destination << endl;
        visit(destination, prev, current);
        prev = destination;
        destination = ladder_snake[destination];
      }
      visit(destination, prev, current);
      q.push(destination);
    }
  }
}

void dfs(int node, int par = 0, int ancestor = 0) {
  visit(node, par, ancestor);
  for (int i = 1; i <= min(n, x - node); i++) {
    int destination = node + i;
    if (dist[destination] > dist[node] + 1) {
      dist[destination] = dist[node] + 1;
      int prev = node;
      while (ladder_snake[destination] != -1) {
        visit(destination, prev, node);
        prev = destination;
        destination = ladder_snake[destination];
      }
      dfs(destination, prev, node);
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
    // dfs(1);

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
    cout << endl;
  }

  return 0;
}