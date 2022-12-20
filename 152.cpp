#include <stdio.h>
#include <string.h>
//#include <iostream>
#include <algorithm>
using namespace std;

//#define DEBUG

int n,m,dr[20001],kn[20001];
bool rec[20001];
int judge(){
    if(n>m) return -1;
    int cnt = 0,pos=0;
    sort(dr,dr+n); sort(kn,kn+m);
    memset(rec,0,sizeof(rec));
    for(int i=0;i<n;i++){
        while(pos<m&&!rec[pos]&&kn[pos]<dr[i]) pos++;
        if(kn[pos]>=dr[i]&&!rec[pos]){
            rec[pos] = 1;
            cnt+=kn[pos];
            pos++;
        }
        else return -1;
    }
    return cnt;
}

int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d %d\n",&n,&m)&&n&&m){
        for(int i=0;i<n;i++) scanf("%d\n",dr+i);
        for(int i=0;i<m;i++) scanf("%d\n",kn+i);
        int ans = judge();
        if(ans>0) printf("%d\n",ans);
        else printf("Loowater is doomed!\n");
    }
    return 0;
}
