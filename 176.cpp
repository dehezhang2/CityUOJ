#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 101
#define INF INT_MAX
#define scf3(s,t,c) scanf("%d %d %d", &s, &t, &c)
#define scf(n) scanf("%d",&n)
int n,s,t,c;
struct Edge{int tar, cost, revp;};
vector<Edge> G[MAX];
//int level[MAX];
bool rec[MAX];
void add(int src,int tar,int cost){
    G[src].push_back((Edge){tar,cost,G[tar].size()});
    G[tar].push_back((Edge){src,cost,G[src].size()-1});
}
// void bfs(int src){
//     queue<int> q;
//     memset(level,-1,sizeof(level));
//     level[src] = 0;
//     q.push(src);
//     while(!q.empty()){
//         int nd = q.front(); q.pop();
//         for(int i=0;i<G[nd].size();i++){
//             Edge& e = G[nd][i];
//             if(level[e.tar]<0&&e.cost>0){
//                 level[e.tar] = level[nd]+1;
//                 q.push(e.tar);
//             }
//         }
//     }
// }
int dfs(int nd, int tar, int f){
    if(nd==tar) return f;
    rec[nd] = 1;
    for(int i=0; i<G[nd].size(); i++){
        Edge& e = G[nd][i];
        if(!rec[e.tar]&&e.cost>0){
            int d = dfs(e.tar,tar,min(f,e.cost));
            if(d>0){
                e.cost-=d;
                G[e.tar][e.revp].cost+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int src, int tar){
    int flow = 0;
    while(true){
        memset(rec,0,sizeof(rec));
        int f = dfs(src,tar,INF);
        if(f>0) flow+=f;
        else return flow;
    }
    return flow;
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    for(int net=1;~scf(n)&&n;net++){
        printf("Network %d\n",net);
        for(int i=0;i<MAX;i++)G[i].clear();
        scf3(s,t,c);
        for(int i=0;i<c;i++){
            int a,b,tmp;
            scf3(a,b,tmp);
            add(a,b,tmp);
        }
        printf("The bandwidth is %d.\n\n",max_flow(s,t));
    }
    return 0;
}