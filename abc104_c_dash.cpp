#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

// https://atcoder.jp/contests/abc104/tasks/abc104_c

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
  for (int bit = 0; bit < (1 << D); bit++) {
    int score = 0;
    int done = 0;
    for (int i = 0; i < D; i++) {
      if (bit & 1 << i) {
        score += 100 * (i + 1) * p[i] + c[i];
        done += p[i];
      }
    }
    if (score < G) {
      for (int i = D - 1; i >= 0; i--) {
        if (bit & 1 << i) {
          continue;
        }
        for (int j = 0; j < p[i]; j++) {
          score += 100 * (i + 1);
          done++;

          if (score >= G)
            goto DONE;
        }
      }
    }
  DONE:
    if (score >= G)
      ans = min(ans, done);
  }

  cout << ans << endl;
  return 0;
}
