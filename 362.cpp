#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;
#define INF INT_MAX
#define MAX 210
#define in(i) i
#define out(i) n+i

struct Edge{int tar, cap, revp; };
// use 0 represent North, 2*n+1 represent South
// use i and n+i represent i_th in and out
vector<Edge> G[MAX];
bool rec[MAX];

void add(int src, int tar, int cap){
    G[src].push_back((Edge){tar,cap,G[tar].size()});
    G[tar].push_back((Edge){src,0,G[src].size()-1});   
}

int dfs(int nd, int tar, int f){
    if(nd==tar) return f;
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


int pts[101][2];
int l, w, n, d, c=0,south,north;

inline double dist(int m, int n){
    int dx = pts[m][0]-pts[n][0], dy = pts[m][1]-pts[n][1];
    return sqrt(dx*dx+dy*dy);
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d %d %d %d\n",&l, &w, &n, &d) && l && w && n && d)
    {
        printf("Case %d: ",++c);
        for(int i=0;i<MAX;i++) G[i].clear();
        south = 2*n+1; north = 0;
        for(int i=1; i<=n; i++){
            scanf("%d %d\n",pts[i],pts[i]+1);      
            add(i,n+i,1); 
            if(pts[i][1]<=d) add(out(i),south,INF);
            if(w-pts[i][1]<=d) add(north,in(i),INF);
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(dist(i,j)<=2*d){
                    add(out(i),in(j),INF);
                    add(out(j),in(i),INF);
                }
            }
        }
        printf("%d\n",max_flow(north,south));
    }
    return 0;
}