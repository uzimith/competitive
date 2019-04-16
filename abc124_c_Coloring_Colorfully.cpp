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

// url: https://atcoder.jp/contests/abc124/tasks/abc124_c

string S;

int main() {
  cin >> S;

  int ans = 0;

  int tmp;
  tmp = 0;
  rep(i, S.length()) {
    if (i % 2 == 0 && S[i] == '0') {
      tmp++;
    }
    if (i % 2 == 1 && S[i] == '1') {
      tmp++;
    }
  }
  ans = tmp;

  tmp = 0;
  rep(i, S.length()) {
    if (i % 2 == 0 && S[i] == '1') {
      tmp++;
    }
    if (i % 2 == 1 && S[i] == '0') {
      tmp++;
    }
  }
  ans = min(ans, tmp);

  cout << ans << endl;

  return 0;
}

// vim: foldmethod=marker
