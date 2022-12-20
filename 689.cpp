#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 1000005
int n;
int temp[MAX];
int b_search(int l, int u, int val) {
	if (l + 1 < u) {
		int mid = (l + u) / 2;
		if (temp[mid] == val)return mid;
		else if (temp[mid] < val)return b_search(mid, u, val);
		else return b_search(l, mid, val);
	}
	return l;
}
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d\n", &n)) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			if (!cnt || t >= temp[cnt - 1])temp[cnt++] = t;
			else {
				int x = b_search(0,cnt,t);
				while (temp[x] <= t)x++;
				temp[x] = t;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}