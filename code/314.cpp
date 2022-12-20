#include <stdio.h>
#include <string.h>
int nxt[100010];
char str[100001],tmp[100001];
void getNext(int n){
    int prenxt=0;
    nxt[0] = nxt[1] = 0;
    for(int i=1;i<n;i++){
        while(prenxt>0&&tmp[i]!=tmp[prenxt]) prenxt = nxt[prenxt];
        if(tmp[i]==tmp[prenxt]) prenxt++;
        nxt[i+1] = prenxt;  // i_th iteration, judge the length of i+1(str[0]->str[i])
    }
}
void KMP(int n){
    int pos = 0;
    for(int i=0;i<n;i++){
        while(pos>0&&str[i]!=tmp[pos])pos = nxt[pos];
        if(str[i]==tmp[pos])pos++;
    }
    printf("%s%s\n",str,tmp+pos);
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(gets(str)){
        int n = strlen(str);
        for(int i=0;i<n;i++) tmp[i] = str[n-1-i];
        tmp[n] = 0;
        getNext(n);
        KMP(n);
    }
    return 0;
}
