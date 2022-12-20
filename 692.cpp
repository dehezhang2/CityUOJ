#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

int prime[9592];
bool rec[100001];
void init(){
    memset(rec,0,sizeof(rec));
    int cnt = 0;
    for(int i=2;i<=100000;i++){
        if(!rec[i]) prime[cnt++] = i;
        for(int j=0;j<cnt;j++){
            if(i*prime[j]>100000) break;
            rec[i*prime[j]] = 1;
            if(i%prime[j]==0) break;
        }
    }
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    init();
    string buffer;
    while(cin>>buffer&&buffer!="0"){
        long max = 0;
        for(int i=1;i<=5&&i<=buffer.length();i++){
            for(int j=0;j<=buffer.length()-i;j++){
                long num = stol(buffer.substr(j,i));
                max = (!rec[num]&&num>max)?num:max;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}