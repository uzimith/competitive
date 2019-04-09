#include <algorithm>
#include <iostream>
#include <string>

// https://atcoder.jp/contests/abc123/tasks/abc123_a

using namespace std;

int main() {
  int a[5], k;
  for (int i; i < 5; i++) {
    cin >> a[i];
  }
  cin >> k;

  int x = numeric_limits<int>::max();
  int y = 0;

  for (int i = 0; i < 5; i++) {
    x = min(a[i], x);
    y = max(a[i], y);
  }
  if (y - x > k) {
    cout << ":(" << endl;
  } else {
    cout << "Yay!" << endl;
  }
  return 0;
}
