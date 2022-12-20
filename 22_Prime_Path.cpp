#include <stdio.h>
#include <string.h>
bool isPrime[9974],rec[9974];
int a,b,t,head=0,tail=0,prime[1230],path[3333][2];
void push(int val,int len){
    path[tail][0]=val;
    path[tail][1]=len;
    tail=(tail+1)%3333;
}
void pop(){head=(head+1)%3333;}
bool empty(){return head==tail;}
void init(){
    int cnt = 0;
    //Euler
    for(int i=2;i<9974;i++){
        if(isPrime[i])
            prime[++cnt] = i;
        for(int j=1;j<=cnt;j++){
            if(i*prime[j]>10000) break;
            isPrime[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
}
int main(){
    memset(isPrime,1,sizeof(isPrime));
    init();
    scanf("%d",&t);
    while(t--){
        head=tail=0;
        memset(rec,0,sizeof(rec));
        scanf("%d%d",&a,&b);
        push(a,0);
        rec[a] = true;
        while(!empty()&&path[tail-1][0]!=b){
            int next = path[head][0];
            int len = path[head][1];
            pop();
            for(int i=1;i<=1000;i*=10){
                for(int j=1;(next/i)%10+j<10;j++){
                    if(next+i*j>1000&&isPrime[next+i*j]&&!rec[next+i*j]){
                        push(next+i*j,len+1);
                        rec[next+i*j] = true;
                        if(path[tail-1][0]==b) break;
                    }
                }
                if(path[tail-1][0]==b) break;
                for(int j=1;(next/i)%10-j>=0;j++){
                    if(next-i*j>1000&&isPrime[next-i*j]&&!rec[next-i*j]){
                        push(next-i*j,len+1);
                        rec[next-i*j] = true;
                         if(path[tail-1][0]==b) break;
                    }
                }
                if(path[tail-1][0]==b) break;
            }
        }
        if(!empty()) printf("%d\n",path[tail-1][1]);
        else printf("Impossible\n");
    }
    return 0;
}