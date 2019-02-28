#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <float.h>
using namespace std;
#define MAX 101
#define INF 10000
int n;
float pr;
int w[MAX];
float p[MAX], dp[INF];
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d %f\n",&n,&pr)){
        memset(dp,0,sizeof(dp));
        pr = 1.0 - pr;
        int cnt = 0;
        for(int i=1;i<=n;++i){
            scanf("%d %f\n",w+i,p+i);
            cnt += w[i];
            p[i] = 1.0 - p[i];
        }
        dp[0] = 1.0;
        for(int i=1;i<=n;i++){
            for(int j=cnt;j>=0;j--){
                dp[j] = max(dp[j],dp[j-w[i]]*p[i]);
                // printf("%10f ",dp[j]);
            }
            // cout << endl;
        }
        int m = 0;
        for(int i=0;i<=cnt;i++){
            if(dp[i]>=pr&&i>m)m = i;
        }
        printf("%d\n",m);
    }
    return 0;
}
