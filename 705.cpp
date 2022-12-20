#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <float.h>
using namespace std;
#define MAX 205
int n, src, tar;
double G[MAX][MAX];
double dis[MAX];
struct Node {
	int id;
	double dist;
	Node(int a, double b) :id(a), dist(b) {}
	bool operator<(const Node& o) const {
		return dist < o.dist;
	}
};

void dijkstra() {
	priority_queue< Node > q;
	memset(dis, 0, sizeof(dis));
	dis[src] = 1;
	q.push(Node(src, dis[src]));
	while (!q.empty()) {
		int nd = q.top().id;
		double dist = q.top().dist; q.pop();
		if (nd == tar)return;
		for (int i = 1; i <= n; i++) {
			if (G[nd][i] && dis[i] < dist*G[nd][i]) {
				dis[i] = dist * G[nd][i];
				q.push(Node(i, dis[i]));
			}
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d %d %d\n", &n, &src, &tar)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%lf", G[i] + j);
			}
		}
		if (src == tar && dis[src] != 0.0) { printf("%.3lf\n", G[src][src]); continue; }
		for (int i = 1; i <= n; i++)G[i][i] = 0;
		dijkstra();
		printf(dis[tar] == 0.0 ? "DANGER!\n" : "%.3lf\n", dis[tar]);
	}
	return 0;
}