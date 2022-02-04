#include <iostream>
using namespace std;

#define endl "\n"

int main() {
  freopen("case2.txt", "w", stdout);
  int n = 10;
  cout << n << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << 10000 << " ";
    }
    cout << endl;
  }
}