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

// url: https://atcoder.jp/contests/tenka1-2019-beginner/tasks/tenka1_2019_c

int N;
string S;

typedef tuple<int, pair<int, int>, int> P;

int main() {
  cin >> N >> S;

  int dot = 0, sharp = 0;
  int ans = 0;

  int j = 0;
  priority_queue<P> que;
  bool done[10000];
  fill(done, 0);

  rep(i, N) {
    if (S[i] == '#') {
      if (dot != 0) {
        que.push(P(min(sharp, dot), pair<int, int>(sharp, dot), j));
        dot = 0;
        sharp = 0;
        j++;
      }
      sharp++;
    }
    if (S[i] == '.') {
      dot++;
    }
  }
  que.push(P(min(sharp, dot), pair<int, int>(sharp, dot), j));

  while (!que.empty()) {
    P p = que.top();
    que.pop();

    // cout << get<0>(p) << " " << get<1>(p) << " " << get<2>(p) << endl;
    if (done[get<2>(p)]) {
      ans += get<1>(p).second;
    } else {
      ans += get<0>(p);
    }
  }

  cout << ans << endl;

  return 0;
}

// vim: foldmethod=marker
