#include <stdio.h>
#include <string.h>
#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 5016
#define llong long long
#define INF 0x3f3f3f3f3f3f3f3f
int m, n, s, t, member, level[MAX];
llong cnt;
struct Edge{int tar;llong cap;int revp;};
vector<Edge> G[MAX];
bool rec[MAX];
void add(int src, int tar, llong cap){
    G[src].push_back((Edge){tar,cap,G[tar].size()});
    G[tar].push_back((Edge){src,0,G[src].size()-1});
}

void bfs(){
    memset(level,-1,sizeof(level));
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while(!q.empty()){
        int nd = q.front(); q.pop();
        for(int i=0;i<G[nd].size();i++){
            Edge& e = G[nd][i];
            if(level[e.tar]<0&&e.cap>0){
                level[e.tar] = level[nd] + 1;
                q.push(e.tar);
            }
        }
    }
}

int dfs(int nd, int tar, llong f){
    if(nd == tar) return f;
    for(int i=0;i<G[nd].size();i++){
        Edge& e = G[nd][i];
        if(level[nd]<level[e.tar]&&e.cap>0){
            int d = dfs(e.tar, tar, min(f,e.cap));
            if(d>0){
                e.cap -= d;
                G[e.tar][e.revp].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

llong max_flow(){
    llong flow = 0;
    while(1){
        bfs(); if(level[t]<0)return flow;
        llong f;
        while((f=dfs(s,t,INF))>0)flow+=f;
    }
    return flow;
}

void count_member(int nd){
    member++;
    rec[nd]=1;
    for(int i=0;i<G[nd].size();i++){
        Edge& e = G[nd][i];
        if(!rec[e.tar]&&e.cap>0)count_member(e.tar);
    }
}

int main(){
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while(~scanf("%d %d\n",&n, &m)){
        for(int i=0;i<MAX;i++) G[i].clear(); cnt = 0;
        s = 0; t = n+1;
        int tmp;
        for(int i=1;i<=n;i++){
            scanf("%d",&tmp);
            if(tmp>0) {
                add(s,i,tmp);
                cnt += tmp;
            }
            if(tmp<0) add(i,t,-tmp);
        }
        int a,b;
        while(m--){
            scanf("%d %d",&a,&b);
            add(a,b,INF);
        }
        llong min_cut = max_flow();
        member = 0; memset(rec,0,sizeof(rec));
        count_member(s); member--;
        printf("%d %lld\n",member,cnt-min_cut);
    }
    return 0;
}