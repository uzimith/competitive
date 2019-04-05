#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;

  long int ans = 0;
  for (int bit = 0; bit < 1 << ((int)str.size() - 1); bit++) {
    long int sum = 0;
    long int num = str[0] - '0';
    for (int i = 0; i < (int)str.size() - 1; ++i) {
      if (bit & (1 << i)) {
        sum += num;
        num = 0;
      }
      num = num * 10 + str[i + 1] - '0';
    }
    sum += num;
    ans += sum;
  }
  cout << ans << endl;
  return 0;
}
