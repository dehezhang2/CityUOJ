#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include<algorithm>
using namespace std;


int n,p,s,t;
char places[210][30],tmp[50];
int Map[210][210],path[210],dis[210];
struct Node{
    int id;
    int dist;
    Node(int a,int b):id(a),dist(b){}
    bool operator>(const Node& b)const{
        return dist<b.dist;
    }
    bool operator<(const Node& b)const{
        return !this->operator>(b);
    }
};
void dijkstra(int src,int tar){
    priority_queue<Node> q;
    memset(dis,0x3f3f3f,sizeof(dis));
    q.push(Node(src,0));
    dis[src]=0;
    path[src]=src;
    while(!q.empty()){
        int id = q.top().id, dist = q.top().dist; 
        q.pop();
        if(id==tar)
            break;
        for(int i=0;i<n;i++){
            if(i==id)continue;
            if(dis[i]>Map[id][i]+dist){
                dis[i] = Map[id][i]+dist;
                path[i] = id;
                q.push(Node(i,dis[i]));
            }
        }
    }
}
void print(string &s,int src,int tar){
    if(path[tar]==-1)while(1);
    if(tar==src)return;
    else{
        print(s,src,path[tar]);
        s=s+" -> " + places[tar];
    }
}
int hashcode(char* str){
    int hash = 0;
    for(int i=0;str[i];i++) hash=(str[i]+hash*37)%n;
    return hash%n;
}
int insert(char* str){
    int hash = hashcode(str);
    while(places[hash][0]!=0)hash=(hash+1)%n;
    strcpy(places[hash],str);
    return hash;
}
int find(char* str){
    int hash = hashcode(str);
    while(strcmp(places[hash],str)!=0)hash=(hash+1)%n;
    return hash;
}
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    while(cin>>n){
        memset(places,0,sizeof(places));
        memset(Map,0x3f3f3f,sizeof(Map));
        memset(path,-1,sizeof(path));
        getchar();
        for(int i=0;i<n;i++){
            cin.getline(tmp,50);
            int pos=insert(tmp);
            if(strcmp(tmp,"office")==0)s = pos;
            if(strcmp(tmp,"hall")==0)t = pos;
        }
        cin>>p;
        getchar();
        for(int i=0;i<p;i++){
            cin.getline(tmp,50);
            int j;
            for(j=0;tmp[j]&&tmp[j]!=':';j++);
            tmp[j] = 0;
            int a = find(tmp);
            int b=-1,pos;
            for(int k=0;k<n;k++){
                int j2 = 0;
                while(places[k][j2]==tmp[j2+j+1])j2++;
                if(!places[k][j2]){ b=k;pos=j2+j+1;}
            }
            stringstream input(tmp+pos);
            int d;
            for(int j=0;input>>d;j++){
                if(!j) Map[a][b] = min(Map[a][b],d);
                else Map[b][a] = min(Map[b][a],d);
            }
        }
        dijkstra(s,t);
        int ans = dis[t];
        string Path = "office";
        print(Path,s,t);
        memset(path,-1,sizeof(path));
        dijkstra(t,s);
        ans+=dis[s];
        print(Path,t,s);
        cout<<ans<<endl;
        cout<<Path<<endl<<endl;
    }
    return 0;
}
