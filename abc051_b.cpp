#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int k;
  int s;
  scanf("%d %d\n", &k, &s);

  int ans = 0;

  for (auto x = 0; x <= k; x++) {
    for (auto y = 0; y <= k; y++) {
      auto z = s - x - y;
      if (0 <= z && z <= k)
        ans++;
      ;
    }
  }
  printf("%d\n", ans);
  return 0;
}
