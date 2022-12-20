#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 105
int sym[MAX];
int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while(1) {
        int n = 0, m = 0x3f3f3f3f;
        while(~scanf("%d", sym + n) && sym[n]) {
            m = sym[n] < m ? sym[n] : m;
            n++;
        }
        if(!sym[0]) break;
        int t;
        bool find;
        for(t = 2 * m; t <= 18000; t++) {
            find = true;
            for(int i = 0; i < n; i++) {
                int nt = t%(2*sym[i]);
                if(nt>=sym[i]-5){
                    find = false;
                    break;
                }
            }
            if(find) break;
        }
        printf(t<=18000?"%02d:%02d:%02d\n":"Signals fail to synchronise in 5 hours\n",
                t/3600, (t%3600)/60, t%60);
    }
    return 0;
}