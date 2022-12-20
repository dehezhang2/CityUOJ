#include <stdio.h>
#include <string.h>
#define MOD 1000000007
int dp[1000005],n,m;
// way(k types number used to make up n) = way(k-1 types number used to make up n)+way(1 k type number used to make up n)
// way(1 k type number used to make up n) = way(k types number used to make up n-k)*1
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(long i=1;i<=n;i*=m){
            for(int j=i;j<=n;j++){
                dp[j]+=dp[j-i];
                dp[j]%=MOD;
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}