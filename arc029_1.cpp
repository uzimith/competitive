#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

// https://atcoder.jp/contests/arc029/tasks/arc029_1

using namespace std;

int main() {
  int N;
  int t[4];

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> t[i];
  }

  int time[2];
  int ans = numeric_limits<int>::max();
  for (int bit = 0; bit < (1 << N); bit++) {
    time[0] = 0;
    time[1] = 0;
    for (int i = 0; i < N; i++) {
      if (bit & 1 << i) {
        time[0] += t[i];
      } else {
        time[1] += t[i];
      }
    }
    ans = min(ans, max(time[0], time[1]));
  }

  cout << ans << endl;
  return 0;
}
