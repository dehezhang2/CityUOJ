#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 105
int t, n;
bool G[MAX][MAX];
bool rec[MAX][MAX];
char buffer[MAX];
struct Node { 
	int x,y,depth;
	Node(int a, int b, int c):x(a),y(b),depth(c) {}
};
inline bool inRange(int x1, int y1) {
	return x1 >= 0 && x1 < n&&y1 >= 0 && y1 < n&&G[x1][y1]&&!rec[x1][y1];
}
int bfs(int sx,int sy, int tx, int ty) {
	memset(rec, 0, sizeof(rec));
	queue<Node> q;
	q.push(Node(sx,sy,0));
	rec[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().x, y=q.front().y,depth=q.front().depth; q.pop();
		//cout << x << " " << y << endl;
		if (x == tx && y == ty)return depth;
		if (inRange(x + 1, y)) {
			q.push(Node(x + 1, y, depth + 1));
			rec[x + 1][y] = 1;
		}
		if (inRange(x - 1, y)) {
			q.push(Node(x - 1, y, depth + 1));
			rec[x - 1][y] = 1;
		}
		if (inRange(x, y + 1)) {
			q.push(Node(x, y + 1, depth + 1));
			rec[x][y + 1] = 1;
		}
		if (inRange(x, y - 1)) {
			q.push(Node(x, y - 1, depth + 1));
			rec[x][y - 1] = 1;
		}
	}
	return 0;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d\n", &n);
		int wx, wy, kx, ky, ox, oy;
		for (int i = 0; i < n; i++) {
			gets(buffer);
			for (int j = 0; j < n; j++) {
				if (buffer[j] == '#')G[i][j] = 0;
				else {
					G[i][j] = 1;
					if (i == 0 || i == n - 1 || j == 0 || j == n - 1) { ox = i; oy = j; }
					if (buffer[j] == 'W'||buffer[j]=='w') { wx = i; wy = j; }
					if (buffer[j] == 'K'||buffer[j]=='k') { kx = i; ky = j; }
				}
			}
		}
		printf("%d\n",bfs(kx, ky, wx, wy) + bfs(wx, wy, ox, oy));
	}
	return 0;
}