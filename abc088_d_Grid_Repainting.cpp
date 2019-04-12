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

// url: https://atcoder.jp/contests/abc088/tasks/abc088_d

int H, W;
char s[50][50];
int num[50][50];

typedef pair<int, int> P;

int main() {
  fill(num, 0);
  cin >> H >> W;
  rep(i, H) rep(j, W) { cin >> s[j][i]; }

  queue<P> que;
  que.push(P(0, 0));
  num[0][0] = 1;

  int white = 0;
  rep(i, H) rep(j, W) {
    if (s[j][i] == '.') {
      white++;
    }
  }
  // cout << "white:" << white << endl;
  while (que.size()) {
    P p = que.front();
    que.pop();
    // cout << p << endl;

    rep(i, 4) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];

      if (nx == W - 1 && ny == H - 1) {
        cout << white - (num[p.first][p.second] + 1) << endl;
        return 0;
      }

      if (in_field(W, H, nx, ny) && num[nx][ny] == 0 && s[nx][ny] == '.') {
        que.push(P(nx, ny));
        num[nx][ny] = num[p.first][p.second] + 1;
      }
    }
  }

  cout << -1 << endl;
  return 0;
}

// vim: foldmethod=marker
