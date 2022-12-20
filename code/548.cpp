#include <stdio.h>
#include <string.h>
unsigned long long a,b;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%llu %llu\n",&a, &b)){
        if(a==b)printf("%llu\n",a);
        else{
            int pos=0,rec;
            unsigned long long num=b;
            while(b){
                if((b&1)&&!(a&1))rec=pos;
                if(a)a>>=1;
                b>>=1;
                pos++;
            }
            unsigned long long x = (1l<<rec)-1;
            printf("%llu\n",num|x);
        }
    }
    return 0;
}