#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;
#define MAX 510
#define INF 0x3f3f3f3f
#define in(i) i
#define out(i) (N+i)

struct Edge { int tar, cap, revp; };
vector<Edge> G[MAX];
bool rec[MAX];
int pts[255][2];
int south, north;
void add(int src, int tar, int cap) {
	G[src].push_back({ tar, cap, (int)G[tar].size() });
	G[tar].push_back({ src, 0 , (int)G[src].size() - 1 });
}
int dfs(int nd, int tar, int f) {
	if (nd == tar) return f;
	rec[nd] = 1;
	for (int i = 0; i < G[nd].size(); i++) {
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
	while (1) {
		memset(rec, 0, sizeof(rec));
		int f = dfs(src, tar, INF);
		if (f > 0) flow += f;
		else return flow;
	}
	return flow;
}
inline double dist(int m, int n) {
	double dx = pts[m][0] - pts[n][0];
	double dy = pts[m][1] - pts[n][1];
	return sqrt(dx*dx + dy * dy);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int L, W, N;
	while (~scanf("%d%d%d\n", &L, &W, &N)) {
		for (int i = 0; i < MAX; i++)G[i].clear();
		south = 2 * N + 1; north = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%d%d\n", pts[i], pts[i]+1);
			add(in(i), out(i), 1);
			if (pts[i][1] <= 100)add(out(i), south, INF);
			if (W - pts[i][1] <= 100)add(north, in(i), INF);
		}
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (dist(i, j) <= 200) {
					add(out(i), in(j), INF);
					add(out(j), in(i), INF);
				}
			}
		}
		printf("%d\n", max_flow(north, south));
	}

	return 0;
}