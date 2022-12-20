#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int t;
string buffer;
string dis[3] = {"and","for","the"};
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    cin>>t;getchar();
    while(t--){
        getline(cin,buffer);
        stringstream input(buffer);
        string tmp,ans="";
        while(input>>tmp){
            if(tmp.length()<3)continue;
            bool skip = 0;
            for(int i=0;i<3;i++){
                transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
                if(dis[i].compare(tmp)==0){
                    skip = 1; break;
                } 
            }
            if(!skip)ans+=toupper(tmp[0]);
        }
        cout << ans <<endl;
    }
    return 0;
}