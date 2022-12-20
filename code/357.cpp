#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;
#define MAX 405
int s, n;
char sta[MAX][11];
struct Edge {
	int src, tar, cost;
	bool operator<(const Edge& o) const {
		return cost < o.cost;
	}
}G[MAX*(MAX-1)/2];
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
int getid(const char str[]) {
	for (int i = 0; i < s; i++) {
		if (strcmp(str, sta[i]) == 0)return i;
	}
}
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d %d\n", &s, &n)) {
		if (s == 0 && n == 0)break;
		memset(root, -1, sizeof(root));
		for (int i = 0; i < s; i++) {
			scanf("%s\n", sta+i);
		}

		char str1[50];
		for (int i = 0; i < n; i++) {
			cin.getline(str1, 50);
			stringstream input(str1);
			char tmp[11];
			int src, tar, cost;
			input >> tmp;
			src = getid(tmp);
			input >> tmp;
			tar = getid(tmp);
			input >> cost;
			G[i] = { src, tar, cost };
		}
		sort(G, G + n);
		int connected = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			int x = find(G[i].src), y = find(G[i].tar);
			if (x != y) {
				join(x, y);
				connected++;
				ans += G[i].cost;
			}
			if (connected == s - 1)break;
		}
		printf(connected == s - 1 ? "%d\n" : "Impossible\n", ans);
		cin.getline(str1, 50);
	}

	return 0;
}