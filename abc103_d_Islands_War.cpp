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

// url: https://atcoder.jp/contests/abc103/tasks/abc103_d

int N, M;
pair<int, int> P[100000];

bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return a.first < b.first;
  }
}

int main() {
  cin >> N >> M;
  rep(i, M) { cin >> P[i].first >> P[i].second; }
  sort(P, P + M, comp);

  int ans = 0;
  int remove = 0;
  rep(i, M) {
    // cout << P[i] << endl;
    if (P[i].first > remove) {
      remove = P[i].second - 1;
      // cout << "removed:" << remove << endl;
      ans++;
    } else {
    }
  }
  cout << ans << endl;

  return 0;
}

// vim: foldmethod=marker
