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

int N, K;
string S;
int zero[100000];
int one[100000];

int main() {
  fill(zero, 0);
  fill(one, 0);
  cin >> N >> K >> S;

  char target = S[0];
  int tmp = 0;
  int h = 0;

  rep(i, N) {
    if (S[i] == target)
      tmp++;
    else {
      if (target == '1') {
        one[h] = tmp;
      } else {
        zero[h] = tmp;
      }
      h++;
      tmp = 1;
      target = S[i];
    }
  }
  if (target == '1') {
    one[h] = tmp;
    h++;
  } else {
    zero[h] = tmp;
    h++;
  }

  // rep(i, h) cout << zero[i] << " ";
  // cout << endl;
  // rep(i, h) cout << one[i] << " ";
  // cout << endl;

  int ans = 0;
  rep(i, h) {
    int sum = one[i];
    if (sum == 0) {
      rep(j, K) {
        if (i + j * 2 < N) {
          // cout << "zero:" << zero[i + j * 2] << endl;
          sum += zero[i + j * 2];
        }
        if (i + 1 + j * 2 < N) {
          // cout << "one:" << zero[i + j * 2] << endl;
          sum += one[i + 1 + j * 2];
        }
      }
    } else {
      rep(j, K) {
        if (i + 1 + j * 2 < N) {
          // cout << "zero:" << zero[i + j * 2] << endl;
          sum += zero[i + 1 + j * 2];
        }
        if (i + 2 + j * 2 < N) {
          // cout << "one:" << zero[i + j * 2] << endl;
          sum += one[i + 2 + j * 2];
        }
      }
    }
    // cout << sum << endl;
    ans = max(sum, ans);
  }

  cout << ans << endl;

  return 0;
}

// vim: foldmethod=marker
