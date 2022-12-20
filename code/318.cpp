#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct Node{
    int x;
    int y;
    int val;
    Node(int a, int b, int c):x(a),y(b),val(c){}
    bool operator<(const Node& b) const{
        return val>b.val;
    }
    bool operator>(const Node& b) const{
        return !operator<(b);
    }
};
int n,t=0;
short mat[126][126];
short dist[126][126];
void dijkstra(){
    priority_queue<Node> q;
    memset(dist,0x3f3f3f,sizeof(dist));
    dist[0][0] = mat[0][0];
    q.push(Node(0,0,dist[0][0]));
    while(!q.empty()){
        int x = q.top().x, y = q.top().y,val = q.top().val;q.pop();
        if(x==n-1&&y==n-1)return;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if((i&&j)||((!i)&&(!j)))continue;
                if(i+x<n&&i+x>=0&&j+y<n&&j+y>=0){
                    if(dist[i+x][j+y]>mat[i+x][j+y]+val){
                        dist[i+x][j+y] = mat[i+x][j+y]+val;
                        q.push(Node(i+x,j+y,dist[i+x][j+y]));
                    }
                }
            }
        }
    }
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d",&n)&&n){
        printf("Problem %d: ",++t);
        for(int i=0;i<n;i++){
            for(int j=0 ; j<n;j++){
                scanf("%hd",mat[i]+j);
            }
        }
        dijkstra();
        printf("%hd\n",dist[n-1][n-1]);
    }
    return 0;
}
