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

// url: https://arc037.contest.atcoder.jp/tasks/arc037_b

int N, M, u[100 * 99 / 2], v[100 * 99 / 2];

bool connect[101];
bool checked[100 * 99 / 2];

int main() {
  fill(connect, 0);
  fill(checked, false);

  cin >> N >> M;
  rep(i, M) cin >> u[i] >> v[i];

  int ans = 0;
  rep(i, N) {
    if (connect[i + 1])
      continue;

    queue<int> que;
    bool isTree = true;

    que.push(i + 1);

    while (que.size()) {
      int node = que.front();
      que.pop();

      rep(j, M) {
        if (checked[j])
          continue;
        if (u[j] == node) {
          if (connect[v[j]])
            isTree = false;
          que.push(v[j]);
          checked[j] = true;
          connect[u[j]] = true;
          connect[v[j]] = true;
        }
        if (v[j] == node) {
          if (connect[u[j]])
            isTree = false;
          que.push(u[j]);
          checked[j] = true;
          connect[u[j]] = true;
          connect[v[j]] = true;
        }
      }
    }

    if (isTree) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}

// vim: foldmethod=marker
