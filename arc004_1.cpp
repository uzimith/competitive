#include <string>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n;
    scanf("%d\n", &n);

	int x[100];
	int y[100];
    for (int i=0; i < n; i++) {
        scanf("%d %d\n", &x[i], &y[i]);
    }

    double ans = 0;
    for (int i=0; i < n; i++) {
        for (int j=1; j < n; j++) {
                ans = max(
                        sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)),
                        ans
                        );
        }
    }
    printf("%f\n", ans);
    return 0;
}
