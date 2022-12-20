#include <stdio.h>
#include <string.h>
using namespace std;
int dp[21][21];
short rec[21][21];
char str1[21],str2[21];
void print(int i,int j){
    if(i<=0&&j<=0)return;
    switch(rec[i][j]){
        case 0:
        print(i-1,j-1);break;
        case 1:
        print(i-1,j);printf("D%c%02d",str1[i-1],j+1);break;
        // reason of using j+1:
        // target: let after deletion position j+1 in str1 is equal to position j in str2
        case 2:
        print(i,j-1);printf("I%c%02d",str2[j-1],j);break;
        case 3:
        print(i-1,j-1);printf("C%c%02d",str2[j-1],j);break;
        // reason of using j as the position: 
        // each time make change such that the last digit is correct, last digit is j according to 
    }
}
int main(){
    while(scanf("%s",str1) && str1[0]!='#'){
        scanf("%s",str2);
        int len1 = strlen(str1),len2 = strlen(str2);
        for(int i=0;i<=len1;i++){
            for(int j=0;j<=len2;j++){
                dp[i][j]=100000;
                rec[i][j]=0;
            }
        }
        for(int i=0;i<=len1;i++){
            dp[i][0]=i;
            rec[i][0]=1;            // represents deletion
        }
        for(int i=0;i<=len2;i++){
            dp[0][i]=i;
            rec[0][i]=2;            // represents insertion
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(str1[i-1]==str2[j-1])dp[i][j] = dp[i-1][j-1];    // when the 2 digits are the same
                else{
                    dp[i][j] = dp[i-1][j-1]+1;
                    rec[i][j] = 3;                                  // represents change
                }
                // greedy
                if(dp[i][j]>dp[i-1][j]+1){
                    dp[i][j]=dp[i-1][j]+1;
                    rec[i][j]=1;
                }
                if(dp[i][j]>dp[i][j-1]+1){
                    dp[i][j]=dp[i][j-1]+1;
                    rec[i][j]=2;
                }
            }
        }
        print(len1,len2);
        printf("E\n");

    }
    return 0;
}