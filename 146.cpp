#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 101
struct Edge {
	int src, tar, cost;
	bool operator<(const Edge& o) const {
		return cost > o.cost;
	}
} G[MAX*MAX] ;
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
	}
	else {
		root[r2] += root[r1];
		root[r1] = r2;
	}
}
int t, n, m;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int num = 0;
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d %d\n", &n, &m);
		memset(root, -1, sizeof(root));
		int u, v, c;
		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d\n", &u, &v, &c);
			G[i] = { u,v,c };
		}
		sort(G, G + m);
		int cnt = 0, ans = 0;
		for (int i = 0; i < m; i++) {
			int x = find(G[i].src), y = find(G[i].tar);
			if (x != y) {
				join(x, y);
				cnt++;
			}
			if (cnt == n - 1) {
				ans = G[i].cost; break;
			}
		}
		printf("Case #%d: %d\n", ++num, ans);
	}
	return 0;
}