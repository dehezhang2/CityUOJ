#include <stdio.h>
//#define DEBUG
int n,sp=0;
char op[2],s[40];
bool inRange(char c){ return c<='9'&&c>='0';}
int cmp(char a,char b){
    if(a=='#'&&b!='#') return -1;
    if(b=='#'&&a!='#') return 1;
    if(a=='('&&b!='(') return -1;
    if(a!='('&&b=='(') return 1;
    if(((a=='*'||a=='/')&&(b=='*'||b=='/'))||((a=='+'||a=='-')&&(b=='+'||b=='-'))) return 0;
    if((a=='*'||a=='/')&&(b=='+'||b=='-')) return 1;
    if((a=='+'||a=='-')&&(b=='*'||b=='/')) return -1;
    return 0;
}
void push(char c){ s[sp++] = c;}
void pop(){sp--;}
char top(){return s[sp-1];}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    scanf("%d",&n);
    getchar();  //getchar() will read the '\n'
    gets(op);
    while(n--){
        push('#');
        while(gets(op)){
            if(!op[0]) break;
            if(inRange(op[0])){
                printf("%d",op[0]-'0');
            } 
            else if(op[0]=='('){
                push(op[0]);
            }
            else if(op[0]==')'){
                while(top()!='('){
                    printf("%c",top()); pop();
                }
                pop();
            }
            else{
                while(cmp(op[0],top())!=1){
                    printf("%c",top());
                    pop();
                }
                push(op[0]);
            }
        }
        while(sp!=0){ if(top()!='#'&&top()!='#') printf("%c",top());pop();}
        printf("\n");
        if(n)printf("\n");
    }
    return 0;
}
