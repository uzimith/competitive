#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>

// template {{{
using namespace std;

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset(x, y, sizeof(x))

using int64 = long long;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool in_field(int W, int H, int x, int y) {
  return (0 <= x && x < W) && (0 <= y && y < H);
}

// pair
template <typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) {
  return s << "(" << p.first << ", " << p.second << ")";
}
// vector
template <typename T> ostream &operator<<(ostream &s, const vector<T> &v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << "\t";
  }
  return s;
}

// }}}

// url: https://atcoder.jp/contests/abc054/tasks/abc054_c

int N, M, a[8 * 7 / 2], b[8 * 7 / 2];
int n[8];

int main() {
  cin >> N >> M;
  rep(i, M) {
    int ta, tb;
    cin >> ta >> tb;
    a[i] = ta - 1;
    b[i] = tb - 1;
  }

  rep(i, N) n[i] = i;

  int ans = 0;

  do {
    // for (int i = 0; i < N; i++) {
    //   cout << n[i];
    //   if (i != N - 1)
    //     cout << " ";
    // }
    // cout << endl;

    int step = 0;
    rep(i, N - 1) rep(j, M) {
      if ((a[j] == n[i] && b[j] == n[i + 1]) ||
          (b[j] == n[i] && a[j] == n[i + 1])) {
        step++;
      }
    }
    // cout << step << endl;
    if (step == N - 1)
      ans++;
  } while (next_permutation(n + 1, n + N));
  cout << ans << endl;
  return 0;
}

// vim: foldmethod=marker
