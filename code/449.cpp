#include<stdio.h>
#include <cstring>
const int MAX = 55;
int main() {
	char arr[MAX][MAX];
	int len = 0;
	while (gets(arr[len++])) {
		if (strlen(arr[len - 1]) == 0 || arr[len - 1][0] == ' ') {
			int ans = 0;
			int n = strlen(arr[len - 2]);
			for (int i = 0; i < len - 1; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] == '#') {
						if (j != 0 && arr[i][j - 1] == '.') ans++;
						if (j != n - 1 && arr[i][j + 1] == '.') ans++;
						if (i != 0) {
							if (arr[i - 1][j] == '.') ans++;
							if (i % 2 == 0 && j != 0 && arr[i - 1][j - 1] == '.') ans++;
							else if (i % 2 != 0 && j != n - 1 && arr[i - 1][j + 1] == '.') ans++;
						}
						if (i != len - 2) {
							if (arr[i + 1][j] == '.') ans++;
							if (i % 2 == 0 && j != 0 && arr[i + 1][j - 1] == '.') ans++;
							else if (i % 2 != 0 && j != n - 1 && arr[i + 1][j + 1] == '.') ans++;
						}
					}
				}
			}
			printf("%d\n", ans);
			len = 0;
		}
	}
	return 0;
}