#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int n,num;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        if(num==0||num==1) printf("0\n");
        else printf("%d\n",num-2);
    }
    return 0;
}