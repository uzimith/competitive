#include <algorithm>
#include <iostream>
#include <string>

// https://atcoder.jp/contests/abc123/tasks/abc123_c

using namespace std;

int main() {
  long long int n;
  cin >> n;
  long long int a[5];
  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }

  long long int m = numeric_limits<long long int>::max();
  for (int i = 0; i < 5; i++) {
    m = min(a[i], m);
  }

  long long int p;
  if (n % m == 0) {
    p = n / m;
  } else {
    p = n / m + 1;
  }
  cout << p + 4 << endl;
  return 0;
}
