#include <stdio.h>
#include <string.h>
int x,y,prime[78499],cnt;
bool rec[1000001];
void init(){
    memset(rec,0,sizeof(rec));
    cnt = 0;
    for(int i=2;i<=1000000;i++){
        if(!rec[i]) {
            prime[cnt++] = i;
        }
        for(int j=0;j<cnt;j++){
            if(i*prime[j]>1000000)break;
            rec[i*prime[j]] = 1;
            if(i%prime[j]==0) break;
        }
    }
}
int getKey(int k){
    int max=0,sum=0;
    for(int i=0;i<cnt;i++){
        if(k%prime[i]==0){
            max = prime[i];
            sum += prime[i];
        }
        while(k>0&&k%prime[i]==0)k/=prime[i];
        if(!k)break;
    }
    return 2*max-sum;
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    init();
    while(~scanf("%d %d\n",&x,&y)&&x){
        printf("%c\n",'a'+(getKey(x)>getKey(y)?0:1));
    }
    return 0;
}
