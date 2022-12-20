#include <stdio.h>
int n, dp[10]={2,8,26,80,242,728,2186,6560,19682,59048};
int main(){
    while(~scanf("%d",&n)){
        printf("%d\n",dp[n-1]);
    }
    return 0;
}