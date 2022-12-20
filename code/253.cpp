#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
//#define DEBUG
struct Path{
    int city;
    double cost;
    int v;
    int pre;
    Path(int pr,int ci,double co,int sp):pre(pr),city(ci),cost(co),v(sp){}

    bool operator>(const Path &b) const{
        return cost<b.cost;
    }

    bool operator<(const Path &b) const{
        return !this->operator>(b);
    }
};
priority_queue<Path> heap;
double dp[31][31][31];
int map[31][31],lim[31][31];
int n,m,s,g;
int main(){
    #ifdef DEBUG
        freopen("in.txt","r",stdin);
    #endif
    bool p = 0;
    while(scanf("%d%d",&n,&m)&& n ){
        memset(map,-1,sizeof(map));
        bool visited[31][31][31] = {false};
        for(int i=0;i<31;i++)
            for(int j=0;j<31;j++)
                for(int k=0;k<31;k++)
                    dp[i][j][k] = 1e9;
        scanf("%d%d",&s,&g);
        for(int i=0;i<m;i++){
            int v,w;
            scanf("%d%d",&v,&w);
            scanf("%d%d",map[v]+w,lim[v]+w);
            map[w][v]=map[v][w];lim[w][v]=lim[v][w];
        }
        heap.push(Path(0,s,0.0,0));
        dp[0][s][0]=0.0;
        while(!heap.empty()){
            int city = heap.top().city;
            int v = heap.top().v;
            int pre = heap.top().pre;
            heap.pop();

            if(visited[city][v][pre]) continue;
            else visited[city][v][pre] = true;

            for(int i=-1;i<=1;i++){
                if(v+i>0){
                    for(int j=1;j<=n;j++){
                        if(j==pre) continue;
                        if(map[j][city]!=-1&&lim[j][city]>=v+i&&!visited[j][v+i][city]){
                            if(dp[city][j][v+i]>=dp[pre][city][v]+map[city][j]/(double)(v+i)){
                                dp[city][j][v+i]=dp[pre][city][v]+map[city][j]/(double)(v+i);
                                heap.push(Path(city,j,dp[city][j][v+i],v+i));
                            }
                        }

                    }
                }
            }
        }
        double min = 1e9;
        for(int i=1;i<31;i++) min = min<dp[i][g][1]?min:dp[i][g][1];
        if(min==1e9)printf("unreachable\n");
        else printf("%.5lf\n",min);
    }
    return 0;
}
