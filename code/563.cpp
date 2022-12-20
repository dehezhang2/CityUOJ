#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <vector>
#include <math.h>
using namespace std;
#define MAX 310
#define INF INT_MAX
struct Pad{int x,y,r;double fre;}pds[MAX];
struct Edge{int tar, cap, revp;};
const double RED = 400.0;
const double VIO = 789.0;
vector<Edge> G[MAX];
bool rec[MAX];
int  k, n, s, t;
inline double dist(int i, int j){
    int dx = pds[i].x-pds[j].x;
    int dy = pds[i].y-pds[j].y;
    return sqrt(dx*dx+dy*dy);
}

void add(int src, int tar, int cap){
    G[src].push_back((Edge){tar,cap,G[tar].size()});
    G[tar].push_back((Edge){src,0,G[src].size()-1});
}

int dfs(int nd, int f){
    if(nd==t) return f;
    rec[nd] = 1;
    for(int i=0;i<G[nd].size();i++){
        Edge& e = G[nd][i];
        if(!rec[e.tar]&&e.cap>0){
            int d = dfs(e.tar,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.tar][e.revp].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(){
    int flow = 0;
    while(1){
        memset(rec,0,sizeof(rec));
        int f = dfs(s,INF);
        if(f>0)flow+=f;
        else return flow;
    }
    return flow;
}

int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    scanf("%d\n",&k);
    while(k--){
        for(int i=0;i<MAX;i++)G[i].clear();
        scanf("%d\n",&n);
        for(int i=0; i<n; i++){
            scanf("%lf %d %d %d\n",&(pds[i].fre),&(pds[i].x),&(pds[i].y),&(pds[i].r));
            if(pds[i].fre==RED)s = i;
            if(pds[i].fre==VIO)t = i;
        }
	for(int i=0;i<n-1;i++){
	    for(int j=i+1;j<n;j++){
	       if(dist(i,j)<pds[i].r+pds[j].r){
		   if(pds[i].fre<pds[j].fre) add(i,j,1);
	           else if(pds[i].fre>pds[j].fre) add(j,i,1);
	       }
	    }
	}
	printf(max_flow()>1?"Game is VALID\n":"Game is NOT VALID\n");
    }
    return 0;
}
