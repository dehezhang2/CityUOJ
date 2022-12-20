#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int mem[32],buffer;
unsigned char pc, ac;
int main(){
    while(cin>>buffer){
        memset(mem,0,sizeof(int)*32);
        for(int j=0;j<8;j++){
            mem[0]+=buffer%10<<j;
            buffer/=10;
        }
        for(int i=1;i<32;i++){
            cin>>buffer;
            for(int j=0;j<8;j++){
                mem[i]+=buffer%10<<j;
                buffer/=10;
            }
        }
        pc = ac = 0;
        int pos,op;
        bool flag = 0;
        while(!flag){
            op = mem[pc]>>5;
            pos = mem[pc]&31;
            pc++;
            pc%=32;
            switch(op){
            case 0:
                mem[pos] = ac;
            break;
            case 1:
                ac = mem[pos];
            break;
            case 2:
                if(ac==0)pc = pos;
            break;
            case 3: break;
            case 4: ac--;break;
            case 5: ac++;break;
            case 6: pc = pos;break;
            case 7: flag = 1;break;
            }
        }
        for(int i=7;i>=0;i--) printf("%d",(ac>>i)&1);
        printf("\n");
    }
    return 0;
}