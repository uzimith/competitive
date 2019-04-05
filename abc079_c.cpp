#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

char ope(int i) {
  if (i == 0) {
    return '+';
  } else {
    return '-';
  }
}

int main() {
  string str;
  int a, b, c, d;
  cin >> str;
  a = str[0] - '0';
  b = str[1] - '0';
  c = str[2] - '0';
  d = str[3] - '0';

  for (int bit = 0; bit < (1 << 3); bit++) {
    int sum = a;
    for (int i = 0; i < 3; i++) {
      if (bit & 1 << i) {
        sum = sum - (str[i + 1] - '0');
      } else {
        sum = sum + (str[i + 1] - '0');
      }
    }
    if (sum == 7) {
      cout << a << ope(bit & 1 << 0) << b << ope(bit & 1 << 1) << c
           << ope(bit & 1 << 2) << d << "=7" << endl;
      return 0;
    }
  }

  return 0;
}
