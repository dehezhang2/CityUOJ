#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
using namespace std;
int t;
string buffer;
int map[1000][1000];
int cost[1000];
int path[1000][1000];
void print(int i,int j){
    if(path[i][j]==i) cout<<i;
    else{
        print(i,path[i][j]);
        cout<<"-->"<<path[i][j];
    }
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    cin>>t;getchar();getchar();
    bool needPrint = false;
    while(t--){
        int n=0;
        getline(cin,buffer);
        stringstream input(buffer);
        while(input>>map[1][n+1]){
            if(map[1][n+1]==-1)map[1][n+1] = 1e9;
            n++;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>map[i][j];
                if(map[i][j]==-1) map[i][j] = 1e9;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>cost[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map[i][j]!=-1) path[i][j] = i;
                else path[i][j] = 0;
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(map[i][j]>map[i][k]+map[k][j]+cost[k]){
                        map[i][j] = map[i][k]+map[k][j]+cost[k];
                        path[i][j] = path[k][j];
                    }
                }
            }
        }
        getchar();
        while(getline(cin,buffer)&&buffer[0]){
            if(!needPrint)needPrint=1;
            else cout<<endl;
            stringstream input(buffer);
            int s,t; input>>s>>t;
            cout<<"From "<<s<<" to "<<t<<" :\nPath: ";
            if(s==t) cout<<s<<endl;
            else{print(s,t); cout<<"-->"<<t<<endl;}
            cout<<"Total cost : "<<map[s][t]<<endl;
        }
    }
    return 0;
}
 