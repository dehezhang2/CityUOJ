#include <stdio.h>
#include <string.h>
// #include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 1005
#define INF 0x3f3f3f3f
int n, t, dist[MAX];
struct Edge {
	int tar, cap;
};
struct Node {
	int id, cost;
	bool operator<(const Node& nd) const {
		return cost > nd.cost;
	}
};
vector<Edge> G[MAX];
int dijkstra(int src, int tar) {
	priority_queue<Node> q;
	q.push({ src, 0 });
	dist[src] = 0;
	memset(dist, INF, sizeof(dist));
	while (!q.empty()) {
		int id = q.top().id, cost = q.top().cost; q.pop();
		if (id == tar)break;
		if (dist[id] < cost)continue;
		for (int i = 0; i < (int)G[id].size(); i++) {
			Edge& e = G[id][i];
			if (cost + e.cap < dist[e.tar]) {
				dist[e.tar] = cost + e.cap;
				q.push({e.tar,dist[e.tar]});
			}
		}
	}
	return dist[tar];
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d %d\n", &n, &t)) {
		for (int i = 0; i < MAX; i++)G[i].clear();
		int a, b, c;
		for (int i = 0; i < t; i++) {
			scanf("%d %d %d\n", &a, &b, &c);
			G[a].push_back({ b,c });
			G[b].push_back({ a,c });
		}
		printf("%d\n", dijkstra(n, 1));
	}

	return 0;
}