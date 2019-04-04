#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, y;
  scanf("%d %d\n", &n, &y);

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (n - i - j >= 0 && y - i * 10000 - j * 5000 == (n - i - j) * 1000) {
        printf("%d %d %d\n", i, j, n - i - j);
        return 0;
      }
    }
  }
  printf("-1 -1 -1\n");
  return 0;
}
