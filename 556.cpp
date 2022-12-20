#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
#define MAX 105
char op[MAX],map[128],var[30];
int cnt;
inline bool isDigit(char ch){return (ch<='z'&&ch>='a');}
inline bool cal(bool a,bool b,char c){
    if(c=='&') return a&b;
    if(c=='+') return a|b;
    if(c=='!') return !a;
    return -1;
}
bool operate(){
    stack<bool> ns;
    stack<char> os;
    os.push('#');
    for(int i=0;op[i];i++){
        if(isDigit(op[i])) {
            ns.push(map[op[i]]);
        }
        else if(op[i]=='(') os.push(op[i]);
        else if(op[i]==')'){
            while(os.top()!='('){
                char tmp = os.top();os.pop();
                if(tmp=='!'){
                    bool a = ns.top(); ns.pop();
                    ns.push(cal(a,0,tmp));
                }
                else if(tmp!='#'){
                    int a = ns.top();ns.pop();
                    int b = ns.top();ns.pop();
                    ns.push(cal(a,b,tmp));
                }
            }
            os.pop();
        }
        else if(op[i]!=' '){
            while(map[op[i]]<=map[os.top()]){
                char tmp = os.top();os.pop();
                if(tmp=='!'){
                    bool a = ns.top(); ns.pop();
                    ns.push(cal(a,0,tmp));
                }
                else if(tmp!='#'){
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
        if(tmp=='!'){
            bool a = ns.top(); ns.pop();
            ns.push(cal(a,0,tmp));
        }
        else if(tmp!='#'){
            int a = ns.top();ns.pop();
            int b = ns.top();ns.pop();
            ns.push(cal(a,b,tmp));
        }
    }
    return ns.top();
}
bool find(char ch){
    for(int i=0;i<cnt;i++){
        if(var[i]==ch) return true;
    }
    return false;
}
bool judge(int id){
    if(id>=cnt) return false;
    if(operate()||judge(id+1)) return true;
    map[var[id]] = 1;
    if(operate()||judge(id+1)) return true;
    return false;
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    memset(map,0,sizeof(map));
    map['#']=0;map['(']=1;map['+'] = 2; map['&'] = 3; map['!'] = 4;
    while(gets(op)){
        cnt = 0;
        for(int i=0;op[i];i++){
            if(isDigit(op[i])&&!find(op[i])){
                var[cnt++] = op[i];
            }
        }
        printf(judge(0)?"YES\n":"NO\n");
    }
    return 0;
}