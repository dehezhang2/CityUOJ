#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 505
int t, n;
int key[MAX];
int root[MAX];
struct Edge {
	int src, tar, cost;
	bool operator<(const Edge& e)const {
		return cost < e.cost;
	}
} G[MAX*(MAX-1)/2];
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
int getDist(int a, int b) {
	int cnt = 0;
	while (a||b) {
		int d = abs(b % 10 - a % 10);
		cnt += d < (10 - d) ? d : (10 - d);
		a /= 10; b /= 10;
	}
	return cnt;
}
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d\n", &t);
	while (t--) {
		memset(root, -1, sizeof(root));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", key + i);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				G[cnt++] = { i,j,getDist(key[i],key[j]) };
			}
		}
		sort(G, G + cnt);
		int connected = 0, ans = 0;
		for (int i = 0; i < cnt; i++) {
			int x = find(G[i].src), y = find(G[i].tar);
			if (x != y) {
				join(x, y);
				connected++;
				ans += G[i].cost;
			}
			if (connected == n - 1) { break; }
		}
		int min = 0x3f3f3f3f;
		for (int i = 0; i < n; i++) {
			int d = getDist(0, key[i]);
			min = min < d ? min : d;
		}
		printf("%d\n", ans + min);
	}
	return 0;
}