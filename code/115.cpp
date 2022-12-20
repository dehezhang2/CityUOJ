#include <stdio.h>
#include <string.h>
//#define DEBUG

int dp[10000001],a,b;
int calc(int num){
    if(num<=10000000){
        if(dp[num]!=0) return dp[num];
        return dp[num] = (num&1?calc(3*num+1):calc(num>>1))+1;
    }
    long long tmp = num;
    int t=0;
    while(num!=1){
        tmp=tmp&1?3*tmp+1:(tmp>>1);
        t++;
        if(tmp<=100000&&dp[tmp]!=0){
            t+=dp[tmp];
            break;
        }
    }
    return t;
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    memset(dp,0,sizeof(dp));
    dp[1] = 1;
    while(~scanf("%d%d",&a,&b)){
        printf("%d %d",a,b);
        if(a>b){a^=b;b^=a;a^=b;}
        int max = 0;
        for(int i=a;i<=b;i++){
            if(!dp[i])calc(i);
            max = max>dp[i]?max:dp[i];
        }
        printf(" %d\n",max);
    }
    return 0;
}