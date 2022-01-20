#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define endl "\n"

const bool fileIO = true, commentOn = false;
const int MAX_SIZE = 10005;
const int INF = 2e9;

void reset(int x, vector<int>& dist, vector<int>& parent,
           vector<int>& ladder_snake, vector<bool>& pushed) {
  // this function resets all the vectors at the start of each test case
  fill(parent.begin(), parent.begin() + x + 2, -1);
  dist[0] = -1;
  fill(dist.begin() + 1, dist.begin() + x + 2, INF);
  fill(pushed.begin(), pushed.begin() + x + 2, false);
  // iota fills the vector with 0, 1, 2, 3, 4.....
  // (consecutive numbers starting from the third argument of the function)
  iota(ladder_snake.begin(), ladder_snake.begin() + x + 2, 0);
}

// the follwing 3 functions have been separeted for ease in debugging by
// printing states
// also the debugging outputs are being done in cerr
inline void setParent(int node, int p, vector<int>& parent) {
  if (commentOn) cerr << "\tSet parent[" << node << "] = " << p << endl;
  parent[node] = p;
  return;
}

inline void setDistance(int node, int d, vector<int>& dist) {
  if (commentOn) cerr << "\tSet dist[" << node << "] = " << d << endl;
  dist[node] = d;
  return;
}

inline void setBoth(int node, int p, int d, vector<int>& parent,
                    vector<int>& dist) {
  setParent(node, p, parent);
  setDistance(node, d, dist);
  return;
}

void bfs(int node, int n, int x, vector<bool>& pushed, vector<int>& dist,
         vector<int>& parent, vector<int>& ladder_snake) {
  queue<int> q;
  q.push(node);
  pushed[node] = true;
  setBoth(node, node, 0, parent, dist);

  while (!q.empty()) {
    int current = q.front();
    // wherever I go from this current node,
    // all will have distance of dist[current] + 1
    int roll = dist[current] + 1;
    q.pop();
    if (commentOn) cerr << "Popped " << current << endl;

    // currently at node current, can go to current + 1 to current + i,
    // given that i <= n and current + i <= x
    // So, i = min(n, x - current)
    for (int i = 1; i <= min(n, x - current); i++) {
      int destination = current + i;
      // if destination is already visited, do not revisit
      if (parent[destination] != -1) continue;

      // previous is required for keeping track of the immediate previous node
      // in the next loop
      int previous = current;

      // checking if there is a ladder/snake in destination
      // the loop is for checking consecutive ladders/snakes
      // it will terminate at the final node where there is no ladder/snake
      // or in an intermediate node already reached early by other means
      while (parent[destination] == -1 &&
             destination != ladder_snake[destination]) {
        setBoth(destination, previous, roll, parent, dist);
        previous = destination;
        destination = ladder_snake[destination];
      }

      // if this final node is not already pushed,
      // it can now be pushed to the queue
      if (parent[destination] == -1 && !pushed[destination]) {
        setBoth(destination, previous, roll, parent, dist);
        q.push(destination);
        pushed[destination] = true;
        if (commentOn) cerr << "\tPushed " << destination << endl;
      }
    }
  }

  return;
}

int printUnreachables(int x, const vector<int>& parent) {
  // this function prints the unreachable nodes if the journey is started from 1
  int unreachable = 0;
  for (int i = 1; i <= x; i++) {
    if (parent[i] == -1) {
      unreachable++;
      cout << i << " ";
    }
  }

  if (unreachable == 0) cout << "All reachable" << endl;

  return unreachable;
}

int main() {
  // for console I/O, it is enough to set fileIO = false,
  // which is true by default
  if (fileIO) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }

  // initializing the necessary vectors with appropriate values
  vector<int> ladder_snake(MAX_SIZE);
  vector<int> dist(MAX_SIZE, INF);
  vector<int> parent(MAX_SIZE, -1);
  vector<bool> pushed(MAX_SIZE, false);

  int t;
  cin >> t;

  while (t--) {
    int n, x, l, s;
    cin >> n >> x >> l;

    reset(x, dist, parent, ladder_snake, pushed);

    // both ladder/snake does the same thing in a sense
    // both of them actually transforms a cell to a different cell
    // so storing them in the same vector is enough

    // ladder input first
    for (int i = 1; i <= l; i++) {
      int ls, le;
      cin >> ls >> le;
      ladder_snake[ls] = le;
    }

    cin >> s;
    // then snake input
    for (int i = 1; i <= s; i++) {
      int ss, se;
      cin >> ss >> se;
      ladder_snake[ss] = se;
    }

    // calls bfs function
    bfs(1, n, x, pushed, dist, parent, ladder_snake);

    // optional printing for debugging
    if (commentOn) {
      for (int i = 1; i <= x; i++) {
        cerr << "Node: " << i << " Parent: " << parent[i]
             << " LS: " << ladder_snake[i] << " Distance: " << dist[i] << endl;
      }
    }

    // this block prints the number of rolls and the desired path (if any)
    if (parent[x] == -1)
      cout << -1 << endl << "No solution" << endl;
    else {
      cout << dist[x] << endl;
      int current = x;

      // will push all nodes one by one to the stack
      // so that while popping, they will be in the correct order
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

    printUnreachables(x, parent);
    cout << endl;
  }

  return 0;
}
