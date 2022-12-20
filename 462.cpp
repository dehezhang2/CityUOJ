#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 10000000
int prime[1229000],num,cnt;
bool rec[MAX+1];
void init(){
    memset(rec,0,sizeof(rec));
    cnt = 0;
    for(int i=2;i<=MAX;i++){
        if(!rec[i])prime[cnt++]=i;
        for(int j=0;j<cnt;j++){
            if(prime[j]*i>MAX)break;
            rec[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
bool isPrime(int k){
    if(k<=MAX)return !rec[k];
    else{
        for(int i=0;i<cnt&&prime[i]<=sqrt(k);i++){
            if(k%prime[i]==0){
                return 0;
            }
        }
        return 1;
    }
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    init();
    while(~scanf("%d",&num)){
        if(num&1){
            if(isPrime(num-2))printf("%d is the sum of 2 and %d.\n",num, num-2);
            else printf("%d is not the sum of two primes!\n",num);
        }
        else{
            bool isOK=0;
            for(int tar=num/2;tar>=2;tar--){
                if(tar!=num-tar&&isPrime(tar)&&isPrime(num-tar)){
                    printf("%d is the sum of %d and %d.\n",num,tar, num-tar);
                    isOK=1;
                    break;
                }
            }
            if(!isOK) printf("%d is not the sum of two primes!\n",num);
        }
    }
    return 0;
}