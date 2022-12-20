#include <stdio.h>
#include <string.h>
int rec[101];
int main() {
	int n,m;
	scanf("%d", &n);
	while(n--){
		memset(rec, 0, sizeof(rec));
		scanf("%d", &m);
		double sum = 0;
		for(int i=0;i<m;i++) {
			int tmp;
			scanf("%d", &tmp);
			rec[tmp]++;
			sum += (double)tmp;
		}
		double ave = sum / m;
		double ans = 0;
		for (int i = (int)ave + 1; i < 101; i++)
			ans += (double)rec[i];
		printf("%.3lf%%\n", 100*ans / (double)m);
	}
	return 0;
}