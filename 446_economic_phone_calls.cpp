#include <stdio.h>
#include <string.h>
int num;
int y,mon,h,min;
char op;
struct Record{
    int val;
    bool need;
    int year;
    Record(){}
    Record(int a,int b,int c):val(a),need(b),year(c){}
};
Record rec[1001];
int dp[1001];
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d",&num)&&num){
        int start = -1,year = 0;
        for(int i=0;i<num;i++){
            int tmp;
            scanf("%d:%d:%d:%d %*s %c\n",&y,&mon,&h,&min,&op);
            if(start<0&&op=='+') start = i; 
            rec[i] = Record(y*1000000+mon*10000+h*100+min,op=='+',year);
            if(rec[i].val<=rec[i-1].val){rec[i].year++;year++;}
            dp[i] = num - i;
        }
        int end = num-1;
        while(true){
            if(rec[end].year==rec[num-1].year) dp[end] = 1;
            if(rec[end].need||rec[end].year!=rec[num-1].year)break;
            end--;
        }
        for(int i=end;i>=start;i--){
            for(int j=i+1;j<num;j++){
                // all entry between the current one and the next '+' will be covered
                if(rec[j].year==rec[i].year) dp[i] = (dp[i]<dp[j]+1)?dp[i]:dp[j]+1;
                else if(rec[i].val>=rec[j].val&&rec[j].year==rec[i].year+1) dp[i] = (dp[i]<dp[j]+1)?dp[i]:dp[j]+1;
                else break;
                if(rec[j].need)break;
            }
        }
        printf("%d\n",dp[start]);
    }
    return 0;
}
