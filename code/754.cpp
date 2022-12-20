#include <stdio.h>
#include <iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int arr[100005];
int t, c, n;

bool judge(int d) {
	int cnt = 1;
	int pre = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i]-pre>=d) {
			if (++cnt >= c) return true;
			pre = arr[i];
		}
	}
	return false;
}

int binary(int lo,int hi) {
	if (lo < hi) {
		int mid = (lo + hi) / 2;
		if (judge(mid)) 
			return binary(mid+1,hi);
		else 
			return binary(lo, mid - 1);
	}
	if (judge(lo)) return lo;
	else return lo - 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &c);
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
		}
		sort(arr, arr + n);
		printf("%d\n", binary(0, (arr[n-1]-arr[0])/(c-1)));
	}
	return 0;
}