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

// url:
// https://www.ioi-jp.org/joi/2007/2008-yo-prob_and_sol/2008-yo-t1/2008-yo-t1.html

int coin[] = {500, 100, 50, 10, 5, 1};

int main() {
  int cost;
  cin >> cost;
  cost = 1000 - cost;
  int ans = 0;
  rep(i, 6) {
    while (cost != 0 && cost >= coin[i]) {
      // cout << coin[i] << endl;
      ans++;
      cost -= coin[i];
    }
  }
  cout << ans << endl;
  return 0;
}

// vim: foldmethod=marker
