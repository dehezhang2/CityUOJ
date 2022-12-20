#include<stdio.h>
using namespace std;
int main() {
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		int now, pre;
		int lo = 0, hi = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &now);
			if (j > 0) {
				if (now > pre) hi++;
				else if (now < pre)lo++;
			}
			pre = now;
		}
		printf("Case %d: %d %d\n", i + 1, hi, lo);
	}
	return 0;
}