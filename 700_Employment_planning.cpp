#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
using namespace std;
#define MAX 1005
#define INF 0x3f3f3f
int dp[15][MAX];
int emp[15];
int n,hire_cost,fire_cost,salary;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d\n",&n)&&n){
        scanf("%d %d %d\n",&hire_cost,&salary,&fire_cost);
        int max_emp = 0;
        for(int i=0;i<n;i++){
            scanf("%d", emp+i);
            max_emp = emp[i]>max_emp?emp[i]:max_emp;
        }
        memset(dp,INF,sizeof(dp));
        for(int i=emp[0];i<=max_emp;i++) dp[0][i]=(hire_cost+salary)*i;
        for(int i=1;i<n;i++){
            for(int e=emp[i];e<=max_emp;e++){
                for(int pe=emp[i-1];pe<=max_emp;pe++){
                    if(pe>=e) dp[i][e] =min(dp[i][e], dp[i-1][pe]+fire_cost*(pe-e)+salary*e);
                    else      dp[i][e] =min(dp[i][e], dp[i-1][pe]+hire_cost*(e-pe)+salary*e);
                }
            }
        }
        int ans=0x7fffffff;
        for(int i=emp[n-1];i<=max_emp;++i)
            ans=min(ans,dp[n-1][i]);
        printf("%d\n",ans); 
    }
    return 0;
}
