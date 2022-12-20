#include <stdio.h>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;

int n;
struct Node{
    int id;
    double dist;
    Node(int a,double d):id(a),dist(d){}
    bool operator>(const Node& b) const{
        return dist<b.dist;
    }
    bool operator<(const Node& b) const{
        return  !this->operator>(b);
    }
};

double map[201][201];
int pts[201][2];
double dis[201];

void dijkstra(){
    priority_queue<Node>q;
    for(int i=2;i<=n;i++) dis[i] = 1e6;
    dis[1] = 0;
    q.push(Node(1,0));
    while(!q.empty()){
        Node pre = q.top();q.pop();
        if(pre.id==2)break;
        for(int i=2;i<=n;i++){
            if(i==pre.id) continue;
            double d = map[pre.id][i]>pre.dist?map[pre.id][i]:pre.dist;
            if(d < dis[i]){
                dis[i] = d;
                q.push(Node(i,d));
            }
        }
    }
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    int cnt = 0;
    while(~scanf("%d",&n)&&n){
        for(int i=1;i<=n;i++)
            scanf("%d %d",pts[i],pts[i]+1);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                map[i][j] = map[j][i] = sqrt((pts[j][0]-pts[i][0])*(pts[j][0]-pts[i][0]) 
                    + (pts[j][1]-pts[i][1])*(pts[j][1]-pts[i][1]) );
            }
        }
        dijkstra();
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",++cnt,dis[2]);
    }
    return 0;
}