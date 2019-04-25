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

// url: https://abc038.contest.atcoder.jp/tasks/abc038_d

int N;

int main() {
  cin >> N;

  vector<pair<int, int>> P(N);
  vector<int> dp(N, numeric_limits<int>::max());
  rep(i, N) { cin >> P[i].first >> P[i].second; }

  sort(all(P), [](pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
      return a.first < b.first;
    } else {
      return a.second > b.second;
    }
  });

  rep(i, N) { *lower_bound(all(dp), P[i].second) = P[i].second; }

  cout << lower_bound(all(dp), numeric_limits<int>::max()) - dp.begin() << endl;

  return 0;
}

// vim: foldmethod=marker
