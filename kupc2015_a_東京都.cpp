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

// url: https://atcoder.jp/contests/kupc2015/tasks/kupc2015_a

int T;
string S[100];

string tokyo = string("tokyo");
string kyoto = string("kyoto");

int main() {
  cin >> T;
  rep(i, T) cin >> S[i];

  string target;
  rep(i, T) {
    int ans = 0, j = 0, k = 0;

    while (j < S[i].length()) {
      if (S[i][j] == 't') {
        target = tokyo;
      } else if (S[i][j] == 'k') {
        target = kyoto;
      } else {
        j++;
        continue;
      }

      while (S[i][j] == target[k] && k < 5) {
        j++;
        k++;
      }
      if (k == 5) {
        ans++;
      }
      k = 0;
    }

    cout << ans << endl;
  }
  return 0;
}

// vim: foldmethod=marker
