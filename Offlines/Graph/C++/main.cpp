#include <iostream>
using namespace std;

const bool fileIO = true;

int main() {
  if (fileIO) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int l;
    cin >> l;
    for (int i = 1; i <= l; i++) {
      int ls, le;
      cin >> ls >> le;
    }
    int s;
    cin >> s;
    for (int i = 1; i <= s; i++) {
      int ss, se;
      cin >> ss >> se;
    }
  }
  return 0;
}