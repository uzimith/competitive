#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int D, G;
  int p[10], c[10];
  cin >> D >> G;

  int n = 0;
  for (int i = 0; i < D; i++) {
    cin >> p[i] >> c[i];
    n += p[i];
  }

  int ans = numeric_limits<int>::max();
  for (int bit = 0; bit < (1 << n); bit++) {
    cout << bitset<20>(bit) << endl;
    // int score = 0;
    // int done = 0;
    //
    // int i = 0;
    // for (int j = 0; j < D; j++) {
    //   int _done = 0;
    //   for (int k = 0; k < p[j]; k++) {
    //     if (bit & 1 << i) {
    //       score += 100 * (j + 1);
    //       _done++;
    //     }
    //     cout << i << " " << score << endl;
    //     i++;
    //   }
    //   cout << "_done:" << _done << endl;
    //   if (_done == p[j]) {
    //     score += c[j];
    //   }
    //   cout << score << endl;
    //   done += _done;
    // }
    // cout << bitset<150>(bit) << " " << score << endl;
    // if (score >= G)
    //   ans = min(ans, done);
  }

  cout << ans << endl;

  return 0;
}
