#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int map[10] = {1,0,0,0,1,0,1,0,2,1};
int n;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d\n", &n)) {
		int cnt = 0;
		if (n == 0)cnt++;
		while (n) {
			cnt += map[n % 10];
			n /= 10;
		}
		printf("%d\n", cnt);
	}
	return 0;
}