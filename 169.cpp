#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;
#define MAX 155
struct Node {
    int a, b, c;
    long lev;
};
int x, y, z, cap;
bool rec[MAX][MAX][1001];
long bfs() {
    queue<Node> q;
    for(int i = 0; i <= x; i++) {
        for(int j = 0; j <= y; j++) {
            for(int k = 0; k <= cap; k++) {
                rec[i][j][k] = 0;
            }
        }
    }
    q.push((Node) {
        0, 0, cap, 0
    });
    rec[0][0][cap] = 1;
    while(!q.empty()) {
        int a = q.front().a, b = q.front().b, c = q.front().c;
        long lev = q.front().lev;
        q.pop();
        if(a == z || b == z) return lev;
        if(a > 0) {
            if(!rec[0][b][c]) {
                rec[0][b][c] = 1;
                q.push((Node) {
                    0, b, c, lev + 1
                });
            }
            if(a > y - b && !rec[a - y + b][y][c]) {
                rec[a - y + b][y][c] = 1;
                q.push((Node) {
                    a - y + b, y, c, lev + 1
                });
            } else if(a < y - b && !rec[0][b + a][c]) {
                rec[0][b + a][c] = 1;
                q.push((Node) {
                    0, a + b, c, lev + 1
                });
            }
        }
        if(a < x) {
            if(c > x - a && !rec[x][b][c - x + a]) {
                rec[x][b][c - x + a] = 1;
                q.push((Node) {
                    x, b, c - x + a, lev + 1
                });
            } else if(c < x - a && !rec[a + c][b][0]) {
                rec[a + c][b][0] = 1;
                q.push((Node) {
                    a + c, b, 0, lev + 1
                });
            }
        }
        if(b > 0) {
            if(!rec[a][0][c]) {
                rec[a][0][c] = 1;
                q.push((Node) {
                    a, 0, c, lev + 1
                });
            }
            if(b > x - a && !rec[x][b - x + a][c]) {
                rec[x][b - x + a][c] = 1;
                q.push((Node) {
                    x, b - x + a, c, lev + 1
                });
            } else if(b < x - a && !rec[a + b][0][c]) {
                rec[a + b][0][c] = 1;
                q.push((Node) {
                    a + b, 0, c, lev + 1
                });
            }
        }
        if(b < y) {
            if(c > y - b && !rec[a][y][c - y + b]) {
                rec[a][y][c - y + b] = 1;
                q.push((Node) {
                    a, y, c - y + b, lev + 1
                });
            } else if(c < y - b && !rec[a][b + c][0]) {
                rec[a][b + c][0] = 1;
                q.push((Node) {
                    a, b + c, 0, lev + 1
                });
            }
        }
    }
    return -1;
}
int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while(~scanf("%d %d %d %d\n", &x, &y, &z, &cap)) {
        printf("%ld\n", bfs());
    }

    return 0;
}
