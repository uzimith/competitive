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

// url: https://abc032.contest.atcoder.jp/tasks/abc032_c

int N, K, S[100000];

int main() {
  cin >> N >> K;

  rep(i, N) {
    cin >> S[i];
    if (S[i] == 0) {
      cout << N << endl;
      return 0;
    }
  }

  int s = 0, t = 0, ans = 0;
  int64 acc = 1;
  while (t < N) {
    while (t < N && acc * S[t] <= K) {
      acc *= S[t++];
    }

    ans = max(t - s, ans);

    if (s != t) {
      acc /= S[s++];
    } else {
      s++;
      t++;
    }
  }
  cout << ans << endl;
  return 0;
}

// vim: foldmethod=marker
