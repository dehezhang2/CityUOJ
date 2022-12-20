#include <stdio.h>
#include <string.h>
#include <queue>
// #include <iostream>
// using namespace std;
using std::queue;
//#define DEBUG
int t,s,e;
bool map[21][21],rec[21];
struct Node{
    int id;
    int le;
    Node(int i,int l):id(i),le(l){}
};
queue<Node*> path;
int bfs(int src,int tar){
    path.push(new Node(src,0));rec[src]=1;
    int id,le;
    while(true){
        id = path.front()->id;
        le = path.front()->le;
        path.pop();
        if(id==tar) break;
        for(int j=1;j<=20;j++){
            if(map[j][id]&&!rec[j]){
                rec[j] = 1;
                path.push(new Node(j,le+1));
            }
        }
    }
    while(!path.empty())path.pop();
    return le;
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    for(int i=1;~scanf("%d",&t);i++){
        memset(map,0,sizeof(map));
        while(t--){
            int tmp;
            scanf("%d",&tmp);
            map[1][tmp]=map[tmp][1]=1;
        }
        for(int j=2;j<20;j++){
            scanf("%d",&t);
            while(t--){
                int tmp;
                scanf("%d",&tmp);
                map[j][tmp]=map[tmp][j]=1;
            }
        }

        printf("Test Set #%d\n",i);
        scanf("%d",&t);
        while(t--){
            memset(rec,0,sizeof(rec));
            scanf("%d %d",&s,&e);
            printf("%2d to %2d: %d\n",s,e,bfs(s,e));
        }
        printf("\n");
    }
    return 0;
}