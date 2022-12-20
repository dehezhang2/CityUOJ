#include <stdio.h>
int n,d,m,y;
struct Person{
    char name[15];
    int birth;
};
Person Min,Max,tmp;
int main(){
    scanf("%d",&n);
    Max.birth = 0;
    Min.birth = 99999999;
    while(n--){
        scanf("%s %d %d %d",tmp.name,&d,&m,&y);
        tmp.birth = y*10000+m*100+d;
        if(tmp.birth>Max.birth) Max = tmp;
        if(tmp.birth<Min.birth) Min = tmp;
    }
    printf("%s\n%s\n",Max.name,Min.name);
    return 0;
}