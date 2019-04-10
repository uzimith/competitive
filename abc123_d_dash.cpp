#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>

// https://atcoder.jp/contests/abc123/tasks/abc123_d

using namespace std;
typedef tuple<int, int, int> T;
typedef pair<long long int, T> P;

int dx[] = {1, 0, 0};
int dy[] = {0, 1, 0};
int dz[] = {0, 0, 1};

int main() {
  int X, Y, Z, K;
  long long int a[1000], b[1000], c[1000];

  cin >> X >> Y >> Z >> K;
  for (int i = 0; i < X; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < Y; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < Z; i++) {
    cin >> c[i];
  }
  sort(a, a + X, std::greater<long long int>());
  sort(b, b + Y, std::greater<long long int>());
  sort(c, c + Z, std::greater<long long int>());

  map<long long int, bool> checked;
  std::priority_queue<P> que;

  que.push(P(a[0] + b[0] + c[0], T(0, 0, 0)));

  for (int i = 0; i < K; i++) {
    P p = que.top();
    que.pop();

    cout << p.first << endl;
    T t = p.second;

    int x = get<0>(t);
    int y = get<1>(t);
    int z = get<2>(t);

    for (int j = 0; j < 3; j++) {
      int _x = x + dx[j];
      int _y = y + dy[j];
      int _z = z + dz[j];
      if (!checked[1000 * 1000 * (_x) + 1000 * (_y) + (_z)] && (_x) < X &&
          (_y) < Y && (_z) < Z) {
        checked[1000 * 1000 * (_x) + 1000 * (_y) + (_z)] = true;
        que.push(P(a[_x] + b[_y] + c[_z], T(_x, _y, _z)));
      }
    }
  }

  return 0;
}
