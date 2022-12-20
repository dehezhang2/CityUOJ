#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 105
#define INF 0x3f3f3f3f
struct Edge {
	int tar, cost;
};
vector<Edge> G[MAX];
int lev[MAX], dis[MAX];
int m, n;
struct Node {
	int id, dist, minl, maxl;
	bool operator<(const Node& o) const {
		return dist > o.dist;
	}
};
inline bool isok(int a, int b, int c) {
	return (b == -1 && c == -1) || (abs(a - b) <= m && abs(c - a) <= m);
}
void dijkstra() {
	priority_queue<Node> q;
	memset(dis, INF, sizeof(dis));
	dis[0] = 0;
	q.push({0,dis[0],lev[0],lev[0]});
	while (!q.empty()) {
		int id = q.top().id, dist = q.top().dist, minl = q.top().minl, maxl = q.top().maxl;
		q.pop();
		if (id == 1) return;
		for (int i = 0; i < G[id].size(); i++) {
			Edge& e = G[id][i];
			if (dis[e.tar] > e.cost + dist&&isok(lev[e.tar],minl,maxl)) {
				dis[e.tar] = e.cost + dist;
				int nmin = minl == -1 ? lev[e.tar] : min(minl, lev[e.tar]);
				int nmax = maxl == -1 ? lev[e.tar] : max(maxl, lev[e.tar]);
				q.push({e.tar,dis[e.tar],nmin,nmax});
			}
		}
	}
}
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d %d\n", &m, &n)) {
		for (int i = 0; i < MAX; i++)G[i].clear();
		lev[0] = -1;
		int c, t;
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d\n", &c, lev + i, &t);
			G[0].push_back({ i,c });
			int mon, tc;
			for (int j = 0; j < t; j++) {
				scanf("%d %d\n", &mon, &tc);
				G[mon].push_back({ i,tc });
			}

		}
		dijkstra();
		printf("%d\n",dis[1]);
	}
	return 0;
}
