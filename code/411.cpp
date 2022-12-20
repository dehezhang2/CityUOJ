#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
using namespace std;
int row[50],c,t;
long long r,s;
map<int,set<int> > info;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    scanf("%d\n",&t);
    for(int n=1;n<=t;n++){
        printf("Case #%d: ",n);
        scanf("%lld\n%lld\n%d\n",&r,&s,&c);
        long long max = r*(s-1);
        for(int i=0;i<c;i++) scanf("%d",row+i);
        for(int i=0;i<c;i++){
            int now;
            scanf("%d",&now);
            info[row[i]].insert(now);
        }
        map< int, set<int> >::iterator out_it = info.begin();
        set<int>::iterator in_it;
        for(int i=0;i<info.size();i++,out_it++){
            in_it = (*(out_it)).second.begin();
            int pre = 0;
            for(int j=0;j<(*(out_it)).second.size();j++,in_it++){
                int seat = *(in_it);
                if(seat!=s) max--;
                if(pre+1!=seat)max--;
                pre = seat;
            }
        }
        printf("%lld\n",max);
        info.clear();
    }
    return 0;
}