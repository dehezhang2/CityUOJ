#include <stdio.h>


int n, m, k;
double pre[15000];
double now[15000];

//0.0277778 0.0555556 0.0833333 0.111111 0.138889 0.166667
int main() {
	while (~scanf("%d%d%d", &n, &m, &k)&& !(n == 0 && m == 0 && k == 0)) {
		for (int i = 1; i <= n; i++) {			// i is the number of deices
			if (i == 1) {
				for (int j = 1; j <= m; j++) {
					now[j] = pre[j] = 1.0 / (double)m;
				}
				continue;
			}
			for (int j = i; j <= i * m; j++) {	//j is the number of sides
				now[j] = 0;
				for (int v = (i - 1); v <= (i - 1)*m; v++) {
					if (j - v <= m && j - v >= 1)
						now[j] += pre[v] / (double)m;
				}
			}
			if (i == n) break;
			for (int j = i; j <= i * m; j++)
				pre[j] = now[j];
		}
		double ans = 0;
		for (int j = n; j <= n * m; j++) {
			if (j <= k)
				ans += now[j];
			else
				ans += now[j] * double(j - k);
		}
        printf("%.8lf\n",ans);
	}
	return 0;
}