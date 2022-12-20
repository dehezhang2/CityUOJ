#include <stdio.h>
#include <string.h>
// #include <iostream>
// using namespace std;
char str1[1001],str2[1001];
int dp[1001][1001];
int l1,l2;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(gets(str1)){
        gets(str2);
        int len1,len2;
        for(len1 = 0;str1[len1];len1++)dp[len1][0] = 0;
        for(len2 = 0;str2[len2];len2++)dp[0][len2] = 0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(str1[i-1]==str2[j-1])dp[i][j] = dp[i-1][j-1]+1;
                dp[i][j] = dp[i][j]>dp[i-1][j]?dp[i][j]:dp[i-1][j];
                dp[i][j] = dp[i][j]>dp[i][j-1]?dp[i][j]:dp[i][j-1];
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
    return 0;
}