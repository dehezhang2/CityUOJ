#include<stdio.h>
int main(){
  int num;
  scanf("%d",&num);
  printf("%d\n",num);
  while(~scanf("%d",&num)){
    printf("\n%d\n",num);
  }
  return 0;
}