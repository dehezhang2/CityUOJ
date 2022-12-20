#include <stdio.h>
#include <string.h>
#include <vector>
using std::vector;

//#define DEBUG
struct Node{
    int val;
    vector<int> next;
};
Node map[10001];
int n,m,l,c,cnt;
bool rec[10001];
void dfs(int s){
    if(rec[s])return;
    rec[s] = 1;cnt++;
    for(int i=0;i<map[s].next.size();i++){
        int tar = (map[s].next)[i];
        if(!rec[tar]) dfs(tar);
    }
}

int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    scanf("%d",&c);
    while(c--){
        cnt = 0;
        memset(map,0,sizeof(map));
        memset(rec,0,sizeof(rec));
        scanf("%d %d %d",&n,&m,&l);
        for(int i=0;i<m;i++){
            int x,y; scanf("%d %d",&x,&y);
            map[x].next.push_back(y);
        }
        for(int i=0;i<l;i++){
            int z;scanf("%d",&z);
            dfs(z);
        }
        printf("%d\n",cnt);
    }
    return 0;
}