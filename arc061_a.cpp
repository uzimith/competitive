#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

char C[10];
int S[10];
int len;

long int calc(long int acc, int pos, int last, int delimiter) {
  if (delimiter == len) {
    return 0;
  }
  if (pos == len - 1) {
    long int after = 0;
    for (auto i = last; i < len; i++) {
      after = after * 10 + S[i];
    }
    return acc + after;
  } else {
    long int before = 0;
    for (auto i = last; i <= pos; i++) {
      before = before * 10 + S[i];
    }
    return calc(acc + before, pos + 1, pos + 1, delimiter + 1) +
           calc(acc, pos + 1, last, delimiter);
  }
}

int main() {
  scanf("%s\n", C);

  len = (int)strlen(C);

  for (auto i = 0; i < len; i++)
    S[i] = C[i] - '0';

  printf("%ld\n", calc(0, 0, 0, 0));
  return 0;
}
