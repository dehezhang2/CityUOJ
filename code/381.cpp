#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
//#define DEBUG
stack<int> ns;
stack<char> os;
char op[105],map[128],out[16];
bool isDigit(char c){return (c<='9'&&c>='0')||(c<='F'&&c>='A');}
int cal(int a,int b,char c){
    if(c=='+') return a+b;
    if(c=='*') return a*b;
    return -1;
}
void print(int num){
    if(num<16)cout<<out[num];
    else{
        print(num/16);
        print(num%16);
    }
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    map['#']=0;map['(']=1;map['+'] = 2; map['*'] = 3;
    for(int i=0;i<10;i++)out[i]=i+'0';
    for(int i=10;i<16;i++)out[i]=i-10+'A';
    while(gets(op)){
        os.push('#');
        for(int i=0;op[i];i++){
            if(isDigit(op[i])) {
                if(op[i]<'A'){
                    // cout<<op[i];
                    ns.push(op[i]-'0');
                }
                else{
                    // cout<<op[i];
                    ns.push(op[i]-'A'+10);
                }
            }
            else if(op[i]=='(') os.push(op[i]);
            else if(op[i]==')'){
                while(os.top()!='('){
                    char tmp = os.top();os.pop();
                    if(tmp!='#'){
                        // cout<<tmp;
                        int a = ns.top();ns.pop();
                        int b = ns.top();ns.pop();
                        ns.push(cal(a,b,tmp));
                    }
                }
                os.pop();
            }
            else {
                while(map[op[i]]<=map[os.top()]){
                    char tmp = os.top();os.pop();
                    if(tmp!='#'){
                        // cout<<tmp;
                        int a = ns.top();ns.pop();
                        int b = ns.top();ns.pop();
                        ns.push(cal(a,b,tmp));
                    }
                }
                os.push(op[i]);
            }
        }
        while(!os.empty()){
            char tmp = os.top();os.pop();
            if(tmp!='#'){
                // cout<<tmp;
                int a = ns.top();ns.pop();
                int b = ns.top();ns.pop();
                ns.push(cal(a,b,tmp));
            }
        }
        // cout<<endl;
        // cout<<ns.top()<<endl;
        print(ns.top());
        cout<<endl;
        ns.pop();
    }
    return 0;
}
