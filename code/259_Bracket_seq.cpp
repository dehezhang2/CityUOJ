#include <stdio.h>
#include <string.h>

char str[101];
int dp[101][101];
int t;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    scanf("%d",&t);getchar();
    while(t--){
        getchar();
        gets(str);
        int n = strlen(str);
        for(int i=0;i<n;i++) dp[i][i] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j+i<n;j++){
                dp[j][j+i] = 1000000;
                if((str[j]=='('&&str[j+i]==')')||(str[j]=='['&&str[j+i]==']')){
                    dp[j][j+i] = dp[j+1][j+i-1];
                }
                for(int k=j;k<j+i;k++){
                    if(dp[j][j+i]>dp[j][k]+dp[k+1][j+i]){
                        dp[j][j+i] = dp[j][k]+dp[k+1][j+i];
                    }
                }
            }
        }
        printf("%d\n",dp[0][n-1]+n);
        if(t)printf("\n");
    }
    return 0;
}
