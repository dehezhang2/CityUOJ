#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stack>
//#include <iostream>
using namespace std;
#define MAX 512

struct Point {
	int x, y, dist;
} pts[MAX];

int t, n;
int cp(const Point& a, const Point& b, const Point& c) {
	// if counter_clockwise, return larger than 1 => rescale to make sure not overflow
	int val = (b.x - a.x)*(c.y - b.y) - (b.y - a.y)*(c.x - b.x);
	return val?(val<0?-1:1):val;
}
bool point_cmp(const Point& a, const Point& b) {
	return a.y == b.y ? a.x < b.x : a.y < b.y;
}
bool slope_cmp(const Point& b, const Point& c) {
	int dir = cp(pts[0], b, c);
	return dir ? dir>0 : b.dist<c.dist ;
}
void Graham() {
	sort(pts, pts + n, point_cmp);
	for (int i = 1; i < n; i++)
		pts[i].dist = (pts[i].y - pts[0].y)*(pts[i].y - pts[0].y) + (pts[i].x - pts[0].x)*(pts[i].x - pts[0].x);
	sort(pts + 1, pts + n, slope_cmp);

	int top = 1;
	// use pts as a stack, because top <= i after each iteration
	for (int i = 2; i < n; i++) {
		while (top > 0 && cp(pts[top - 1], pts[top], pts[i]) <= 0) --top;
		pts[++top] = pts[i];
	}

	// delete the points in the middle of the segment
	pts[++top] = pts[0];
	int now = 1;
	for (int i = 2; i <= top; i++) {
		if (!cp(pts[now - 1], pts[now], pts[i])) pts[now] = pts[i];	// move now to the next point on the same segment
		else pts[++now] = pts[i];
	}
	if (now < 2) {
		printf("0\n");
	}
	else {
		printf("%d\n", now + 1);
		for (int i = 0; i <= now; i++) {
			printf("%d %d\n", pts[i].x, pts[i].y);
		}
	}
}
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d\n", &t);
	printf("%d\n", t);
	while (t--) {
		scanf("%d\n", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d\n", &(pts[i].x), &(pts[i].y));
		}
		Graham();
		if(t) printf("-1\n");
		scanf("%d\n", &n);
	}
	return 0;
}