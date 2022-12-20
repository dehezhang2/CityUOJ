#include <stdio.h>
int n;
char str[1000];
int main(){
    scanf("%d",&n);
    for(int x=0;x<n;x++){
        scanf("%s",str);
        printf("%c",str[0]);
        for(int i=0;str[i+1]!='\0';i++){
            if(str[i]=='-')
                 printf("%c",str[i+1]-'a'+'A');
             else if (str[i+1]!='-')
                printf("%c",str[i+1]);
        }
        printf("\n");
    }
    return 0;
}