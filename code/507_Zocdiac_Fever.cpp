#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int r,c,t,src,spos,tar,tpos;
int map[1005][1005],dp[1005][15],trap[1005][2];
struct Node{
    int now;
    int sta;
    int cost;
    Node(int n,int s,int c):now(n),sta(s),cost(c){}
    bool operator<(const Node& b)const{
        return cost>b.cost;
    }
    bool operator>(const Node& b)const{
        return !this->operator<(b);
    }
};
inline int calc(int sta,int k){
    int nsta;
    switch(trap[k][0]){
    case '+': nsta = sta+trap[k][1]; break;
    case '*': nsta = sta*trap[k][1];break;
    case '-': nsta = sta-trap[k][1]; break;
    case '=': nsta = trap[k][1]; break;
    default: nsta = sta;
    }
    while(nsta<=0)nsta+=12;
    return (nsta-1)%12+1;
}
int dijkstra(){
    priority_queue<Node> q;
    dp[src][spos] = 0;
    q.push(Node(src,spos,0));
    while(!q.empty()){
        int now = q.top().now,
            sta = q.top().sta, cost = q.top().cost;
        q.pop();
        if(now==tar&&sta==tpos)return cost;
        // cout<<pre<<"->"<<now<<"("<<sta<<")"<<endl;
        for(int i=1;i<=r;i++){
            if(i==now) continue;
            int nsta = calc(sta,i);
            if(map[now][i]!=-1&&dp[i][nsta]>map[now][i]+cost){
               // if(i==tar&&nsta!=tpos)continue;
                dp[i][nsta] = map[now][i]+cost;
                q.push(Node(i,nsta,dp[i][nsta]));
            }
        }
    }
    return 1000000000;
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d %d %d %d %d %d %d\n",&r,&c,&t,&src,&spos,&tar,&tpos)){
        memset(map,-1,sizeof(map));
        memset(trap,0,sizeof(trap));
        memset(dp,0x3f3f3f,sizeof(dp));
        for(int i=0;i<c;i++){
            int x,y,cost;
            scanf("%d %d %d\n",&x,&y,&cost);
            //if(map[x][y]==-1)
            map[y][x] = map[x][y] = cost;
            //else map[y][x] = map[x][y] = min(map[x][y],cost);
        }
        for(int i=0;i<t;i++){
            int x,y;
            char op[10];
            scanf("%d %s %d\n",&x,op,&y);
            trap[x][0] = op[0];
            trap[x][1] = y%12;
        }
        int val=dijkstra();
        if(val<1000000000)printf("%d\n",val);
        else printf("Pray!\n");
        //printf(val<1000000000?"%d\n":"Pray!\n",val);
    }
    return 0;
}
