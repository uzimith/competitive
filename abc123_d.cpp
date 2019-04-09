#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

// https://atcoder.jp/contests/abc123/tasks/abc123_d

using namespace std;

int main() {
  long long int x, y, z, k, a[1000], b[1000], c[1000];
  cin >> x >> y >> z >> k;
  for (int i = 0; i < x; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < y; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < z; i++) {
    cin >> c[i];
  }
  sort(a, a + x, std::greater<long long int>());
  sort(b, b + y, std::greater<long long int>());
  sort(c, c + z, std::greater<long long int>());

  vector<long long int> ans;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      for (int l = 0; l < z; l++) {
        if ((i + 1) * (j + 1) * (l + 1) <= k) { // from answer
          ans.push_back(a[i] + b[j] + c[l]);
        } else {
          break;
        }
      }
    }
  }
  sort(ans.begin(), ans.end(), std::greater<long long int>());

  for (int i = 0; i < k; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
