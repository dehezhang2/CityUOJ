#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int maxp, minv, n;
int main(){
#ifdef DEBUG 
    freopen("input.txt", "r", stdin);
#endif 
    while(~scanf("%d\n", &n)){
        int t;
        minv = 0x3f3f3f3f,maxp = -1;
        for(int i=0;i<n;i++){
            scanf("%d\n", &t);
            maxp = (t - minv) > maxp ? (t-minv):maxp;
            if(minv > t){
                minv = t;
            }
        }
        printf(maxp >= 0 ? "%d\n" : "QUIT\n", maxp);
        
    }

    return 0;
}