#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

bool map[101][101];
int n,m,a,b;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d %d\n", &n, &m)){
        memset(map,0,sizeof(map));
        for(int i=0;i<m;i++){
            scanf("%d %d\n",&a,&b);
            map[a][b] = 1;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(map[i][k]&&map[k][j])map[i][j] = 1;
                }
            }
        }
        int val = n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&!map[i][j]&&!map[j][i]){
                    val--;
                    break;
                }
            }
        }
        printf("%d\n",val);
    }
    return 0;
}