#include <stdio.h>
#include <string.h>

int rows[105];
char buffer[10];
int row, col;

int dist(int a, int b, int col) {
	int ans = 0;
	int judge = a ^ b;
	while (judge) {
		ans += judge%2;
		judge >>= 1;
	}
	return (ans<col - ans) ? ans : col - ans;
}

int main() {
	while (~scanf("%d%d", &row, &col)) {
		memset(rows, 0, sizeof(int)*row);
		for (int i = 0; i < row; i++) {
			scanf("%s", buffer);
			for (int j = 0, move = col - 1; j < col; j++, move--) {
				rows[i] += (int(buffer[j] - '0') << move);
			}
		}
		int dis = row * col;
		int temp;
		for (int i = 0; i < (1 << col); i++) {
			temp = 0;
			for (int j = 0; j < row; j++) {
				if ((temp += dist(i, rows[j], col))>dis)
					break;
			}
			dis = dis > temp ? (temp) : (dis);
		}
		printf("%d\n", row * col - dis);
	}
	return 0;
}
