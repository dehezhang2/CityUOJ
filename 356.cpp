#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 505
#define MAXE 1000005
#define u_int unsigned int
int n, m;
struct Edge {
	int src, tar;
	u_int cost;
};
vector<Edge> es;
int root[MAX];
int find(int a) {
	if (root[a] < 0)return a;
	else return root[a] = find(root[a]);
}
void join(int a, int b) {
	int r1 = find(a), r2 = find(b);
	if (root[r1] < root[r2]) {
		root[r1] += root[r2];
		root[r2] = r1;
	} else {
		root[r2] += root[r1];
		root[r1] = r2;
	}
}
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d %d\n", &n, &m) && n) {
		es.clear();
		memset(root, -1, sizeof(root));
		int u, v;
		u_int w;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d\n", &u, &v, &w);
			if (!es.empty()&&es[0].cost < w) es.clear();
			if (es.empty() || es[0].cost == w )es.push_back({u,v,w});

		}
		for (int i = 0; i < es.size(); i++) {
			int x = find(es[i].src), y = find(es[i].tar);
			if (x != y) join(x, y);
		}
		int maxc = 0;
		for (int i = 1; i <= n; i++) {
			maxc = maxc < root[i] ? maxc : root[i];
		}
		printf("%d\n", -maxc);
	}
	return 0;
}