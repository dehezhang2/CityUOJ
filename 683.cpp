#include <stdio.h>
#include <string.h>
// #include <iostream>
// using namespace std;

//#define DEBUG
int k,a,b,v;

int calc(int spb,int fullbox,int remain,int sec){
    int cnt = 0;
    while(sec>0){
        if(fullbox>0){ sec-=spb; cnt++; fullbox--;}
        else if(fullbox==0){ sec-=(remain+1); cnt++; fullbox--;}
        else {cnt+=sec;sec=0;}
    }
    return cnt;
}

int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d %d %d %d",&k,&a,&b,&v)){
        printf("%d\n",calc(k,b/(k-1),b%(k-1),a%v?a/v+1:a/v));
    }
    return 0;
}