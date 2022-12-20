#include <stdio.h>
#include <algorithm>
int n, p, dp;
int sum;
int dis[105];
int main() {
	while (~scanf("%d", &n)) {
		sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &p, &dp);
			sum += p;
			dis[i] = p-dp;
		}
		std::sort(dis, dis + n);
		if (sum >= 100) {
			for (int i = 0; i < n / 2; i++) {
				sum -= dis[n - 1 - i];
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}