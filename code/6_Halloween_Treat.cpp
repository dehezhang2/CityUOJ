#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int f[100005];
int rec[100005];
int main() {
	int c, n;
	scanf("%d%d", &c, &n);
	while (c != 0 && n != 0) {
		int lo = 0, hi = 100000, num;
		memset(rec, 0xff, sizeof(rec));
		f[0] = rec[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &num);
			f[i] = (f[i - 1] + num) % c;
			if (!~rec[f[i]])
				rec[f[i]] = i;
			else if (i - rec[f[i]] < hi - lo) {
				hi = i;
				lo = rec[f[i]];
			}
		}
		for (int i = lo + 1; i < hi; i++)
			printf("%d ", i);
		printf("%d\n", hi);
		scanf("%d%d", &c, &n);
	}
	return 0;
}
