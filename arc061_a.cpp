#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

char C[10];
int S[10];
int len;
int memo[10][10][10];

int calc(int start, int end, int delimiter) {
  // if (memo[start][end][delimiter] == 1) {
  //   return 0;
  // }
  //
  // memo[start][end][delimiter] = 1;

  if (delimiter > 0 && start == end) {
    return 0;
  } else if (delimiter == 0) {
    auto sum = 0;
    for (auto i = start; i <= end; i++) {
      sum = sum * 10 + S[i];
    }
    return sum;
  } else {
    auto sum = 0;
    for (auto i = 0; i < end - start; i++) {
      auto before = calc(start, start + i, delimiter - 1);
      auto after = calc(start + i + 1, end, delimiter - 1);
      printf("before:start=%d end=%d delimiter=%d %d\n", start, start + i,
             delimiter - 1, before);
      printf("after :start=%d end=%d delimiter=%d %d\n\n", start + i + 1, end,
             delimiter - 1, after);
      sum += before + after;
    }
    return sum;
  }
}

int main() {
  scanf("%s\n", C);

  len = (int)strlen(C);

  for (auto i = 0; i < len; i++)
    S[i] = C[i] - '0';

  fill(memo[0][0], memo[10][0], 0);

  auto sum = 0;
  for (auto i = 0; i < len; i++) {
    auto temp = calc(0, len - 1, i);
    printf("i=%d temp=%d\n", i, temp);
    sum += temp;
  }

  printf("%d\n", sum);
  return 0;
}
