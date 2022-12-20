#include <stdio.h>

int days(int y, int m, int d) {
	int ans = 0;
	ans += (y-1) / 3 * 590 + (y-1)%3*195;
	if (y % 3 == 0) {
		ans += (m - 1) * 20;
	}
	else {
		ans += (m - 1) / 2 * 39 + (m - 1) % 2 * 20;
	}
	ans += d - 1;
	return ans;
}

int n, y, m, d;
int main() {
	scanf("%d", &n);
	int td = days(1000, 1, 1);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &y, &m, &d);
		printf("%d\n", td - days(y, m, d));
	}
	return 0;
}