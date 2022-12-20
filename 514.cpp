#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int x, y;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d %d\n", &x, &y)) {
		int cnt = 10 * x + y;
		while (true) {
			bool bf=true, kf=true;
			if (x >= 2) {
				if (y >= 2) {
					x -= 2;
					y -= 2; 
					bf = false;
				}
			}
			else if (x == 1) {
				if (y >= 12) {
					x -= 1;
					y -= 12;
					bf = false;
				}
			}
			else if (y >= 22) {
				y -= 22;
				bf = false;
			}
			if (bf) {
				printf("Kengood\n");
				break;
			}
			if (y >= 22) {
				y -= 22;
				kf = false;
			}
			else if (y >= 12&&x>=1) {
					x -= 1;
					y -= 12;
					kf = false;
			}
			else if (x>=2&&y>=2) {
					x -= 2;
					y -= 2;
					kf = false;
			}
			if (kf) {
				printf("Bert\n");
				break;
			}
		}
	}
	return 0;
}