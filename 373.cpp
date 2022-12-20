#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
#define MAX 1005
#define u_int unsigned int
struct Edge {
	int src, tar;
	u_int cost;
	bool operator<(const Edge& e) const {
		return cost < e.cost;
	}
} G[25005];
int root[MAX];
int find(int a) {
	if (root[a] < 0) return a;
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
int n, m;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d %d\n", &n, &m) && (n || m)) {
		memset(root, -1, sizeof(root));
		int u, v; u_int w;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d\n", &u, &v, &w);
			G[i] = { u,v,w };
		}
		sort(G, G + m);
		queue<u_int> unused;
		int cnt = 0;
		u_int ans = 0;
		for (int i = 0; i < m; i++) {
			int x = find(G[i].src), y = find(G[i].tar);
			if (x != y) {
				join(x, y);
				cnt++;
				ans += G[i].cost;
			}
			else {
				unused.push(G[i].cost);
			}
		}
		if (cnt != n - 1) {
			printf("\\(^o^)/ pray to god\n");
		}
		else {
			printf("Min cost: %d\n", ans);
			bool need = 0;
			while (!unused.empty()) {
				if (need) printf(" ");
				else need = 1;
				printf("%d", unused.front());
				unused.pop();
			}
			printf("\n");
		}
	}
	return 0;
}		