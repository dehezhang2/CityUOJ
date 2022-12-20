#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 101
#define INF 0x3f3f3f3f
int root[MAX], n, m, maxc, minc, cnt, ans;

struct Edge {
	int src, tar, cost;
	bool operator<(const Edge& o)const {
		return cost < o.cost;
	}
} G[MAX*(MAX - 1) / 2];
int find(int a) {
	if (root[a] < 0) return a;
	else return root[a] = find(root[a]);
}
void join(int a, int b) {
	int r1 = find(a), r2 = find(b);
	if (root[r1] < root[r2]) {
		root[r1] += root[r2];
		root[r2] = r1;
	}
	else {
		root[r2] += root[r1];
		root[r1] = r2;
	}
}
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d %d\n", &n, &m)&&n) {
		ans = INF;
		int u, v, c;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d\n", &u, &v, &c);
			G[i] = { u,v,c };
		}
		sort(G, G + m);
		for (int i = 0; i < m; i++) {
			memset(root, -1, sizeof(root));
			minc = maxc = cnt = 0;
			for (int j = i; j < m; j++) {
				int x = find(G[j].src), y = find(G[j].tar);
				if (i == j) { minc = G[j].cost; }
				if (x != y) { join(x, y); cnt++; }
				if (cnt == n - 1) { maxc = G[j].cost; break; }
			}
			ans = (cnt == n - 1) && (maxc - minc) < ans ? (maxc - minc) : ans;
		}
		printf("%d\n", ans < INF ? ans : -1);
	}
	return 0;
}