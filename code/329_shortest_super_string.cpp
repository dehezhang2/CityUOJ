#include <stdio.h>
#include <string.h>

char str1[1001],str2[1001];
int dp[1001][1001];
int l1,l2;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    gets(str1);
    while(gets(str1)){
        gets(str2);
        int len1=strlen(str1),len2=strlen(str2);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(str1[i-1]==str2[j-1])dp[i][j] = dp[i-1][j-1]+1;
                dp[i][j] = dp[i][j]>dp[i-1][j]?dp[i][j]:dp[i-1][j];
                dp[i][j] = dp[i][j]>dp[i][j-1]?dp[i][j]:dp[i][j-1];
            }
        }
        printf("%d\n",len1+len2-dp[len1][len2]);
    }
    return 0;
}
