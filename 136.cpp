#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 20005
int n, val, t, cash[105];
int dp[MAX];
int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d\n", &n);
    while(n--) {
        scanf("%d\n%d\n", &val, &t);
        // int cnt = 0;
        for(int i = 1; i <= t; i++) {
            scanf("%d\n", cash + i);
            // cnt += cash[i];
        }
        memset(dp,0x3f3f3f3f,sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i <= t; i++) {
            for(int j = 20000; j >= cash[i]; j--) {
                dp[j] = min(dp[j], dp[j - cash[i]] + 1);
            }
        }
        int ans = 0, i;
        for(i = val; i <= 20000 ; i++) {
            if(dp[i] < 105) {
                ans = dp[i];
                break;
            }
        }
        printf("%d %d\n", i, ans);
    }
    return 0;
}