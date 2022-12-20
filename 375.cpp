#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

//#define DEBUG
int v[4],t;
int rec[25][25][25][25];
struct Node{
    int v[4];
    int l;
    Node(int x, int y, int z, int w,int le):l(le){
        v[0] = x; v[1] = y;v[2] = z;v[3] = w;
    }
    Node(int* src, int pos,int val,int pos2, int val2,int le):l(le){
        memcpy(v,src,sizeof(v));
        if(pos<4)
            v[pos] = val;
        if(pos2>3)return;
        v[pos2] = val2;
    }
};
// void copy(int* src,int* tar,int pos,int val,int pos2, int val2){
//     for(int i=0;i<4;i++){
//         if(i==pos) tar[i] = val;
//         else if(i==pos2) tar[i] = val2;
//         else v[i] = src[i];
//     }
// }
int bfs(){

    queue<Node> path;

    path.push(Node(0,0,0,0,0));
    rec[0][0][0][0]=0;
    if(t==0) return 0;
    while(!path.empty()){
        Node nd = path.front();
        path.pop();
        int l = nd.l; 
        int* pre = nd.v;
        for(int i=0;i<4;i++){
            if(pre[i]<v[i]){
                if(v[i]==t) return l+1;
                Node nnd(pre,i,v[i],4,0,l+1);
                if(l+1<rec[nnd.v[0]][nnd.v[1]][nnd.v[2]][nnd.v[3]]){
                    path.push(nnd);
                    rec[nnd.v[0]][nnd.v[1]][nnd.v[2]][nnd.v[3]]=l+1;
                }
            }
            if(pre[i]>0){
                for(int j=0;j<4;j++)
                    if(i!=j)
                    {
                        if(pre[i]>=v[j]-pre[j]){
                            if(pre[i]-v[j]+pre[j]==t||v[j]==t) return l+1;
                            Node nnd(pre,i,pre[i]-v[j]+pre[j],j,v[j],l+1);
                            if(l+1<rec[nnd.v[0]][nnd.v[1]][nnd.v[2]][nnd.v[3]]){
                                path.push(nnd);
                                rec[nnd.v[0]][nnd.v[1]][nnd.v[2]][nnd.v[3]]=l+1;
                            }
                        }
                        else{
                            if(pre[j]+pre[i]==t) return l+1;
                            Node nnd(pre,i,0,j,pre[j]+pre[i],l+1);
                            if(l+1<rec[nnd.v[0]][nnd.v[1]][nnd.v[2]][nnd.v[3]]){
                                path.push(nnd);
                                rec[nnd.v[0]][nnd.v[1]][nnd.v[2]][nnd.v[3]]=l+1;
                            }
                        }
                    }
                Node nnd(pre,i,0,4,0,l+1);
                if(l+1<rec[nnd.v[0]][nnd.v[1]][nnd.v[2]][nnd.v[3]]){
                    path.push(nnd);
                    rec[nnd.v[0]][nnd.v[1]][nnd.v[2]][nnd.v[3]]=l+1;
                }
            }
        }
    }
    return -1;
}

int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d %d %d %d %d",v,v+1,v+2,v+3,&t)){
        // while(!path.empty()) {
        //     Node *tmp=path.front();
        //     path.pop();
        //     delete tmp;
        // }
        memset(rec,0x3f3f3f,sizeof(rec));
        printf("%d\n",bfs());
    }
    return 0;
}