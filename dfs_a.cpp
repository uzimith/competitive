#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

// https://atc001.contest.atcoder.jp/tasks/dfs_a

using namespace std;

int H, W;
char c[500][500];
int memo[500][500];

bool dfs(int x, int y) {
  if (memo[x][y] || x < 0 || W - 1 < x || y < 0 || H - 1 < y ||
      c[x][y] == '#') {
    return false;
  }
  memo[x][y] = 1;
  if (c[x][y] == 'g') {
    return true;
  }
  return (dfs(x + 1, y) || dfs(x, y + 1) || dfs(x - 1, y) || dfs(x, y - 1));
}

int main() {
  fill(memo[0], memo[499], 0);

  cin >> H >> W;
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      cin >> c[i][j];
    }
  }

  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (c[i][j] == 's') {
        if (dfs(i, j)) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
