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

// url: https://atcoder.jp/contests/abc124/tasks/abc124_d

int N, K;
string S;

int main() {
  cin >> N >> K >> S;

  int l = 0, r = 0, k = 0, sum = 0;
  int ans = 0;
  while (r < N) {
    while (r < N && k < K) {
      if (S[r] == '0' && S[r + 1] == '1') {
        k++;
      }
      r++;
      sum++;
    }

    while (S[r] == '1') {
      r++;
      sum++;
    }
    ans = max(sum, ans);
    while (k >= K) {
      if (S[l] == '0' && S[l + 1] == '1') {
        k--;
      }
      l++;
      sum--;
    }
  }
  cout << ans << endl;

  return 0;
}

// vim: foldmethod=marker
