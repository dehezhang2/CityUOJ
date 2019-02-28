#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAX 1005

int n, G[MAX][MAX];
int partition(int row){
    int lo=0,hi=n-1,mid=-1,down, up;
    while(mid!=n/2){
        for(down=lo,up=hi;down<up;){
            while(G[row][down]<=G[row][lo]&&down<hi) down++;
            while(G[row][up]>G[row][lo]) up--;
            if(down<up) swap(G[row][down],G[row][up]);
        }
        swap(G[row][up],G[row][lo]);
        mid = up;
        if(mid<n/2){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }

    return mid;
}

int main(){
#ifdef DEBUG 
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d\n", &n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               scanf("%d",G[i]+j); 
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(G[i][j]>G[i][k]+G[k][j]){
                        G[i][j] = G[i][k] + G[k][j]; 
                    } 
                }            
            }
        }
         
        for(int i=0;i<n;i++){
            int mid = partition(i);
            if(n&1)printf("%d\n",G[i][mid]);
            else if((G[i][mid-1]&1)==(G[i][mid]&1)) printf("%d\n",(G[i][mid]+G[i][mid-1])/2);
            else printf("%.1lf\n",((double)G[i][mid-1]+(double)G[i][mid])/2.0);
        }
    }
    
    return 0;
}
