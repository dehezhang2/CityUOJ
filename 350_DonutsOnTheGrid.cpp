#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int t,r,c,dp[51][51][51][51];
char mat[51][51];
bool isDon(int x1,int y1,int x2,int y2){
    for(int i=y1; i<=y2 ;i++){
        if(mat[x1][i]!='0'||mat[x2][i]!='0')return false;
    }
    for(int i=x1;i<=x2;i++){
        if(mat[i][y1]!='0'||mat[i][y2]!='0')return false;
    }
    return true;
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    scanf("%d",&t);
    for(int n=0;n<t;n++){
        scanf("%d\n",&r);
        for(int i=0;i<r;i++) gets(mat[i]);
        c = strlen(mat[0]);
        memset(dp,0,sizeof(dp));
        for(int dx = 2;dx<r;dx++){
            for(int dy = 2;dy<c;dy++){
                for(int x = 0; x+dx<r; x++){
                    for(int y=0; y+dy<c; y++){
                        int x1 = x+dx, y1 = y+dy;
                        dp[x][y][x1][y1] = max(dp[x][y][x1][y1], dp[x+1][y][x1][y1]);
                        dp[x][y][x1][y1] = max(dp[x][y][x1][y1], dp[x][y+1][x1][y1]);
                        dp[x][y][x1][y1] = max(dp[x][y][x1][y1], dp[x][y][x1-1][y1]);
                        dp[x][y][x1][y1] = max(dp[x][y][x1][y1], dp[x][y][x1][y1-1]);
                        if(isDon(x,y,x1,y1))
                            dp[x][y][x1][y1] = max(dp[x][y][x1][y1], dp[x+1][y+1][x1-1][y1-1]+1);
                    }
                }
            }
        }
        printf("Case #%d: %d\n",n+1,dp[0][0][r-1][c-1]);
    }
    return 0;
}
