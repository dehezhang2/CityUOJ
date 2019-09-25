
#include <stdio.h>
bool arr[1030][1030];
char buffer[1030];
int calc(int r, int c, int size, int& cnt) {
	if (size == 2) {
		if (arr[r][c] == arr[r][c + 1] & arr[r][c] == arr[r + 1][c] & arr[r][c] == arr[r + 1][c + 1])
			return arr[r][c];
		else {
			cnt += 4;
			return -1;
		}
	}
	else {
		int s = calc(r, c, size / 2, cnt);
		if (s != -1 & s == calc(r, c + size / 2, size / 2, cnt) & s == calc(r + size / 2, c, size / 2, cnt) & s == calc(r + size / 2, c + size / 2, size / 2, cnt)) {
			return s;
		}
		else {
			cnt += 4;
			return -1;
		}
	}
}

int main() {
	char ch;
	int n;
	while (~scanf("%d", &n)) {
		int num = 1 << n;
		for (int i = 0; i < num; i++) {
			scanf("%s",buffer);
			for (int j = 0; j < num; j++) arr[i][j] = buffer[j] == '1';
		}
		if (!n) {
			printf("1\n");
		}
		else {
			
			int cnt = 1;
			calc(0, 0, num, cnt);
			printf("%d\n", cnt);
		}
	}
	return 0;
}
