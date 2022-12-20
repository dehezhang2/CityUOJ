#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
#define MAX 505
#define INF 0x3f3f3f3f
struct Edge{int tar, cost;};
vector<Edge> G[MAX];
struct Node{
    int id,dist;bool lev;
    bool operator<(const Node& o) const{
        return dist>o.dist;
    }
};
int dis[MAX][2];
int n,r;
void dijkstra(){
    priority_queue<Node> q;
    memset(dis,INF,sizeof(dis));
    q.push((Node){0,0,0});
    dis[0][0] = 0;
    while(!q.empty()){
        int nd = q.top().id, dist = q.top().dist;
        bool lev = q.top().lev;q.pop();
        if(nd==n-1&&lev==0)break;
        for(int i=0; i<G[nd].size() ;i++){
            Edge& e = G[nd][i]; 
            if(dis[e.tar][1-lev]>dist+e.cost){
                dis[e.tar][1-lev] = dist+e.cost;
                q.push((Node){e.tar,dist+e.cost,bool(1-lev)});
            }
        }
    } 
}
int main(){
#ifdef DEBUG 
    freopen("input.txt","r",stdin);
#endif
    int a,b,c;
    int cnt = 0;
    while(~scanf("%d %d\n",&n,&r)){
        for(int i=0;i<MAX;i++)G[i].clear();
        for(int i=0;i<r;i++){
            scanf("%d %d %d\n",&a,&b,&c);
            G[a].push_back((Edge){b,c});
            G[b].push_back((Edge){a,c});
        }
        dijkstra();
        printf("Set #%d\n",++cnt);
        printf(dis[n-1][0]<INF?"%d\n":"?\n",dis[n-1][0]);
    }
    return 0;
}
