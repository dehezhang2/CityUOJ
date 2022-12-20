#include <stdio.h>
#include <string.h>
#include <set>
#include <math.h>
using namespace std;
typedef unsigned long long p_llong;
set<p_llong>s;
set<p_llong>::iterator it;
bool isPrime[65]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0};
p_llong power (int n,int m){
    if (m==0) return 1;
    if (m%2==0) return power(n,m/2)*power(n,m/2);
    return n*power(n,m/2)*power(n,m/2);
}

int main(){
    s.insert(1);
    for(int i=2;i<=65536-1;++i){
        double t=ceil(64.0/log(i)*log(2))-1;
        for(int j=4;j<=t;++j){
            if(isPrime[j]) continue;
            s.insert(power(i,j));
        }
    }
    for(auto ste:s)
        printf("%llu\n",ste);
    return 0;
}