#include <stdio.h>
using namespace std;
//#define DEBUG
int n,cnt;
char op;
bool isDigit(char c){return c<='9'&&c>='0';}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    scanf("%d",&n);
    while(n--){
        cnt = 0;
        for(int i=0;i<16;i++){
            scanf("%c",&op);
            while(!isDigit(op)) scanf("%c",&op);
            if(i&1) cnt+=(op-'0');
            else{
                int tmp = op-'0';
                cnt+=(2*tmp)/10+(2*tmp)%10;
            }
        }
        if(cnt%10) printf("Invalid\n");
        else printf("Valid\n");

    }
    return 0;
}