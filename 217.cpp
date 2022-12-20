#include <stdio.h>
#include <string.h>
#define MAX 7490
int dp[MAX], cost[6] = { 0,1,5,10,25,50 }, num;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 7489; j++) {
			dp[j] = (j >= cost[i]) ? dp[j] + dp[j - cost[i]] : dp[j];
		}
	}
	while (~scanf("%d", &num)) {
		printf("%d\n", dp[num]);
	}
	return 0;
}