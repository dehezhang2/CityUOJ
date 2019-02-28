#include <stdio.h>
#include <string.h>
//#include <iostream>
using namespace std;
//#define DEBUG
int n;
char buffer[1000];

int judge(int lo,int hi){
    if(lo+1<hi){
        if(buffer[hi-2]=='A'&&buffer[hi-1]=='B'){
            if(judge(lo,hi-2)!=3)return 1;
        }
        else if(buffer[lo]=='B'&&buffer[hi-1]=='A'){
            if(judge(lo+1,hi-1)!=3)return 2; 
        }
    }
    else if(lo==hi) return 3;
    else if(buffer[lo]=='A') return 0;
    return 3;
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
    FILE* fp;
    fp = fopen("output.txt","w");
#endif
    scanf("%d",&n);
    fgets(buffer,100,stdin);
    while(n--){
        fgets(buffer,100,stdin);
        switch(judge(0,strlen(buffer)-1)){
            case 0://fprintf(fp,"SIMPLE\n");break;
            printf("SIMPLE\n");break;
            case 1://fprintf(fp,"FULLY-GROWN\n");break;
            printf("FULLY-GROWN\n");break;
            case 2://fprintf(fp,"MUTAGENIC\n");break;
            printf("MUTAGENIC\n");break;
            case 3://fprintf(fp,"MUTANT\n");break;
            printf("MUTANT\n");break;
        }
    }
    // printf("\n");
    return 0;
}
