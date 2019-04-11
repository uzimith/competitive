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
// }}}

// url: https://atcoder.jp/contests/abc007/tasks/abc007_3

int R, C, sy, sx, gy, gx;
char c[50][50];
int num[50][50];
bool checked[50][50];

typedef pair<int, int> P;

int main() {
  fill(num, 0);
  fill(checked, false);
  cin >> R >> C >> sy >> sx >> gy >> gx;
  rep(i, R) rep(j, C) cin >> c[i][j];

  queue<P> que;
  que.push(P(sy - 1, sx - 1));
  while (que.size()) {
    P p = que.front();
    que.pop();

    int current = num[p.first][p.second];

    rep(i, 4) {
      int y = p.first + dx[i];
      int x = p.second + dy[i];

      if (x == gx - 1 && y == gy - 1) {
        cout << current + 1 << endl;
        return 0;
      }

      if (num[y][x] == 0)
        num[y][x] = current + 1;

      if (!checked[y][x] && in_field(C, R, x, y) && c[y][x] == '.') {
        que.push(P(y, x));
        checked[y][x] = true;
      }
    }
  }
  return 0;
}

// vim: foldmethod=marker
