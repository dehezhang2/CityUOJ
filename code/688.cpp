#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 8

int t, ca;
struct Node {
    int x, y, l;
};
char mat[MAX][MAX];
bool rec[MAX][MAX];
int arr1[2] = {-1, 1}, arr2[2] = {-2, 2};

bool isOk(int x, int y) {
    return x < 8 && x >= 0 && y < 8 && y >= 0 && !rec[x][y] && mat[x][y] != '*';
}

int bfs(int x, int y) {
    queue<Node> q;
    memset(rec, 0, sizeof(rec));
    rec[x][y] = 1;
    q.push((Node) {
        x, y, 0
    });
    while(!q.empty()) {
        Node& nd = q.front(); q.pop();
        // cout << nd.x << " " << nd.y << " " << nd.l << endl;
        if(mat[nd.x][nd.y]=='@') return nd.l;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                int nx1 = nd.x + arr1[i], ny1 = nd.y + arr2[j],
                    nx2 = nd.x + arr2[j], ny2 = nd.y + arr1[i];
                if(isOk(nx1, ny1)){
                    rec[nx1][ny1] = 1;
                    q.push((Node){nx1, ny1, nd.l+1});
                }
                if(isOk(nx2, ny2)){
                    rec[nx2][ny2] = 1;
                    q.push((Node){nx2, ny2, nd.l+1});
                }
            }
        }

    }
    return -1;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &t);
    ca = 0;
    while(t--) {
        gets(mat[0]);
        int x, y;
        for(int i = 0; i < 8; i++) {
            gets(mat[i]);
            for(int j = 0; j < 8; j++) {
                if(mat[i][j] == '#') x = i, y = j;
            }
        }
        int ans = bfs(x, y);
        printf("Case %d: ", ++ca);
        printf(ans<0?"IMPOSSIBLE\n":"%d\n", ans);
    }
    return 0;
}