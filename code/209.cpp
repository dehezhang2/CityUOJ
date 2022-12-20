#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 105
#define llong long long
int n, m;
struct Point {
	llong x;
	llong y;
};
Point line[MAX][2];
llong clock(Point& p1, Point& p2, Point& p3) {
	return (p2.x - p1.x)*(p3.y - p2.y) - (p2.y-p1.y)*(p3.x-p2.x);
}
bool online(Point& p1, Point& p2, Point& p3) {
	return p3.x <= max(p1.x, p2.x) && p3.x >= min(p1.x, p2.x)
		&& p3.y <= max(p1.y, p2.y) && p3.y >= min(p1.y, p2.y);
}
bool check(int i, int j) {
	llong o1 = clock(line[i][0], line[i][1], line[j][0]);
	llong  o2 = clock(line[i][0], line[i][1], line[j][1]);
	llong  o3 = clock(line[j][0], line[j][1], line[i][0]);
	llong o4 = clock(line[j][0], line[j][1], line[i][1]);
	if (o1*o2 < 0 && o3*o4 < 0) return 1;
	if (o1 == 0 && online(line[i][0], line[i][1], line[j][0])) return 1;
	if (o2 == 0 && online(line[i][0], line[i][1], line[j][1])) return 1;
	if (o3 == 0 && online(line[j][0], line[j][1], line[i][0])) return 1;
	if (o4 == 0 && online(line[j][0], line[j][1], line[i][1])) return 1;
	return 0;
}
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d\n", &n);
	while (n--) {
		scanf("%d\n", &m);
		for (int i = 0; i < m; i++) {
			scanf("%lld %lld %lld %lld\n", &(line[i][0].x), &(line[i][0].y), &(line[i][1].x), &(line[i][1].y));
		}
		int cnt = m;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (i!=j &&check(i, j)) {
					cnt--;
					break;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}