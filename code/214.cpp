#include <stdio.h>
#include <string.h>
int x,prime[100000],cnt;
bool rec[1299710];
void init(){
    memset(rec,0,sizeof(rec));
    cnt = 0;
    for(int i=2;i<=1299710;i++){
        if(!rec[i]) prime[cnt++] = i;
        for(int j=0;j<cnt;j++){
            if(i*prime[j]>1299710)break;
            rec[i*prime[j]] = 1;
            if(i%prime[j]==0) break;
        }
    }
}

int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    init();
    while(~scanf("%d\n",&x)&&x){
        int a = x,b = x;
        while(rec[a])a--;
        while(rec[b])b++;
        printf("%d\n",b-a);
    }
    return 0;
}