#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 205
#define INF 0x3f3f3f3f
struct Edge { int tar, cap, revp; };
vector<Edge> G[MAX];
bool rec[MAX];
void add(int src, int tar, int cap) {
	G[src].push_back({ tar, cap, (int)G[tar].size() });
	G[tar].push_back({ src, 0, (int)G[src].size() - 1 });
}
int dfs(int nd, int tar, int f) {
	if (nd == tar) return f;
	rec[nd] = 1;
	for (int i = 0; i < (int)G[nd].size(); i++) {
		Edge& e = G[nd][i];
		if (!rec[e.tar] && e.cap > 0) {
			int d = dfs(e.tar, tar, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.tar][e.revp].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int src, int tar) {
	int flow = 0;
	while (true) {
		memset(rec, 0, sizeof(rec));
		int f = dfs(src, tar, INF);
		if (f > 0) flow += f;
		else return flow;
	}
	return flow;
}
int n, m, k;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d %d %d\n", &n, &m, &k)) {
		for (int i = 0; i < MAX; i++)G[i].clear();
		for (int i = 1; i < n; i++) {
			add(0, i, 1);
		}
		for (int i = 1; i < m; i++) {
			add(n - 1 + i, n+m-1 , 1);
		}
		// 0 src, 1 -> n-1 a, n-1 +1 -> n-1 + m -1 b, n+m-1 sink
		for (int i = 0; i < k; i++) {
			int a, b;
			scanf("%d %d\n", &a, &b);
			if (!a || !b)continue;
			// cout << a << " " << b << endl;
			add(a, n - 1 + b, 1);
		}
		printf("%d\n", max_flow(0, n + m - 1));
	}

	return 0;
}