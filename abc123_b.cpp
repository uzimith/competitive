#include <algorithm>
#include <iostream>
#include <string>

// https://atcoder.jp/contests/abc123/tasks/abc123_b

using namespace std;

int main() {
  int a[5];
  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }

  int sum = 0;
  int diff = 0;
  for (int i = 0; i < 5; i++) {
    int num;
    if (a[i] % 10 == 0) {
      num = a[i];
    } else {
      num = a[i] / 10 * 10 + 10;
    }
    sum += num;
    diff = max(num - a[i], diff);
  }
  cout << sum - diff << endl;
  return 0;
}
