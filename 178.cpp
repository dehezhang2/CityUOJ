#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <vector>
using namespace std;
#define MAX 1025
#define INF INT_MAX
struct Edge{int tar, cap, revp;};
vector<Edge> G[MAX];
bool rec[MAX];
void add(int src, int tar, int cap){
    G[src].push_back((Edge){tar,cap,G[tar].size()});
    G[tar].push_back((Edge){src,0,G[src].size()-1});
}
int dfs(int nd, int tar, int f){
    if(nd==tar)return f;
    rec[nd] = 1;
    for(int i=0;i<G[nd].size();i++){
        Edge& e = G[nd][i];
        if(!rec[e.tar]&&e.cap>0){
            int d = dfs(e.tar,tar,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.tar][e.revp].cap+=d;
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
int nk,np,tot;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d %d\n",&nk,&np)&&nk){
        for(int i=0;i<MAX;i++)G[i].clear(); tot = 0;
        for(int i=1;i<=nk;i++){
            int tmp;
            scanf("%d",&tmp);
            add(i,0,tmp);
            tot+=tmp;
        }
        for(int i=1;i<=np;i++){
            int num; scanf("%d",&num);
            while(num--){
                int tmp;
                scanf("%d",&tmp);
                add(nk+i,tmp,1);
            }
            add(nk+np+1,nk+i,1);
        }
        printf("%d\n",max_flow(np+nk+1,0)>=tot);
    }
    return 0;
}