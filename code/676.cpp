#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int n,m;
long long map[101][101];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map[i][j]>map[i][k]+map[k][j]){
                    map[i][j] = map[i][k]+map[k][j];
                }
            }
        }
    }
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d %d\n", &n , &m)){
        int u,v;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
               if(i==j)map[i][j] = 0;
               else map[i][j] = 1000000000; 
            }
        }
        while(m--){
            scanf("%d %d", &u, &v);
            scanf("%lld",map[u]+v);
            map[v][u] = map[u][v];
        }
        long long min = -1;
        int minp = 0;
        floyd();
        for(int i=1;i<=n;i++){
            long long sum = 0;
            for(int j=1;j<=n;j++){
                sum+=map[i][j];
            }
            if(min==-1||min>sum){
                min=sum;
                minp = i;
            }
        }
        printf("%d\n",minp);
    }
    return 0;
}