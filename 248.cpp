#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 4
int n;
int t, l, r, b;
struct Point {
	int x, y;
} line[MAX][2];

int clock(Point& p1, Point& p2, Point& p3) {
	int val = (p2.x - p1.x)*(p3.y - p2.y) - (p2.y - p1.y)*(p3.x - p2.x);
	if (val == 0.0) return val;
	return val < 0 ? -1 : 1;
}

inline bool online(Point& p1, Point& p2, Point& p3) {
	return p3.x <= max(p1.x, p2.x) && p3.x >= min(p1.x, p2.x)
		&& p3.y <= max(p1.y, p2.y) && p3.y >= min(p1.y, p2.y);
}

bool checkIntersaction(int i, int j) {
	int o1 = clock(line[i][0], line[i][1], line[j][0]);
	int o2 = clock(line[i][0], line[i][1], line[j][1]);
	int o3 = clock(line[j][0], line[j][1], line[i][0]);
	int o4 = clock(line[j][0], line[j][1], line[i][1]);
	if (o1*o2 < 0 && o3*o4 < 0) return 1;
	if (o1 == 0 && online(line[i][0], line[i][1], line[j][0])) return 1;
	if (o2 == 0 && online(line[i][0], line[i][1], line[j][1])) return 1;
	if (o3 == 0 && online(line[j][0], line[j][1], line[i][0])) return 1;
	if (o4 == 0 && online(line[j][0], line[j][1], line[i][1])) return 1;
	return 0;
}

inline bool checkInRec(Point& p) {
	return p.x <= r && p.x >= l
		&& p.y <= t && p.y >= b;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d\n", &n);
	while (n--) {
		scanf("%d %d %d %d %d %d %d %d\n"
			, &line[0][0].x, &line[0][0].y
			, &line[0][1].x, &line[0][1].y
			, &l, &t, &r, &b);
		if (l > r)swap(l, r);
		if (b > t)swap(b, t);
		line[1][0].x = line[2][0].x = line[3][1].x = line[1][1].x = l;
		line[1][0].y = line[2][0].y = line[4][1].y = line[2][1].y = t;
		line[3][0].x = line[4][0].x = line[2][1].x = line[4][1].x = r;
		line[3][0].y = line[4][0].y = line[1][1].y = line[3][1].y = b;
		bool found = checkInRec(line[0][0]) && checkInRec(line[0][1]);
		for (int i = 1; i < 5 && !found; i++) {
			found = checkIntersaction(0, i);
		}
		printf(found ? "T\n" : "F\n");
	}
	return 0;
}