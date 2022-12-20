#include <stdio.h>
#include <string.h>
//#include <iostream>
//using namespace std;

//#define DEBUG

int num,a,b,c,n;
bool rec[301];
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    scanf("%d\n",&num);
    while(num--){
        scanf("%d %d %d %d\n",&a,&b,&c,&n);
        int max = 0;
        for(int i=0;i<n;i++){
            memset(rec,0,sizeof(rec));
            int next = i,cnt=0;
            while(!rec[next]){
                rec[next] = 1;
                cnt++; next = (a*next*next+b*next+c)%n;
            }
            max = cnt>max?cnt:max;
        }
        printf("%d\n",max);
    }
    return 0;
}