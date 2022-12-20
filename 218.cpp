#include <stdio.h>
#include <string.h>
#include <algorithm>
int dp[31],p[1001],w[1001],n,g,t;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d %d",p+i,w+i);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for ( int j = 30 ; j >= w[i] ; j--)
                dp[j] = std::max(dp[j],dp[j-w[i]]+p[i]);
        scanf("%d",&g);
        int cnt = 0;
        while(g--){
            int tmp;
            scanf("%d",&tmp);
            cnt+=dp[tmp];
        }
        printf("%d\n",cnt);
    }
    return 0;
}