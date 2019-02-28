#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 1000005
int Tail[MAX], Next[MAX], to[MAX];
int imp[MAX];
int rec[MAX];
int father[MAX];
unsigned long long dp[MAX][2];
int cnt;
int n;
void add(int src, int tar) {
    Next[cnt] = Tail[src];
    to[cnt] = tar;
    Tail[src] = cnt++;
}
unsigned long long cnt1 = 0, cnt2 = 0;
int bfs() {
    std::queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(Tail[i] == -1)q.push(i);
    }
    while(1) {
        int id = q.front();
        q.pop();
        cnt1 = cnt2 = 0;
        for (int i = Tail[id]; i != -1; i = Next[i]) {
            int cid = to[i];
            cnt1 += std::max(dp[cid][0], dp[cid][1]);
            cnt2 += dp[cid][0];
        }
        dp[id][0] = cnt1;
        dp[id][1] = cnt2 + imp[id];
        rec[father[id]]--;
        if(father[id] == 0)return id;
        if(rec[father[id]] <= 0)q.push(father[id]);
    }

}
int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while (~scanf("%d\n", &n)) {
        memset(Tail, -1, sizeof(Tail));
        memset(dp, 0, sizeof(dp));
        memset(rec, 0, sizeof(rec));
        memset(father, 0, sizeof(father));
        cnt = 0;
        for (int i = 1; i <= n; i++)scanf("%d", imp + i);
        int u, v;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d\n", &u, &v);
            rec[u]++;
            father[v] = u;
            add(u, v);
        }
        int src = bfs();
        std::cout << std::max(dp[src][0], dp[src][1]) << "\n";
    }
    return 0;
}
