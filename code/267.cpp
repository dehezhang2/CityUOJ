#include<stdio.h>
#include<string.h>
bool mat[105][105];
int m, n, k, a, b;

int dfs(int x, int y) {
	mat[x][y] = 0;
	int cnt = 1;
	if (x != 0 && mat[x - 1][y])cnt += dfs(x - 1, y);
	if (y != 0 && mat[x][y - 1])cnt += dfs(x, y - 1);
	if (x != m-1 && mat[x + 1][y])cnt += dfs(x + 1, y);
	if (y != n-1 && mat[x][y + 1])cnt += dfs(x, y + 1);
	return cnt;
}

int main() {
	while (~scanf("%d%d%d", &m, &n, &k)) {
		memset(mat, 0, sizeof(mat));
		for (int i = 0; i < k; i++) {
			scanf("%d%d", &a, &b);
			mat[a-1][b-1] = 1;
		}
		int max = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j]) {
					int t = dfs(i, j);
					max = max >t ? max : t;
				}
			}
		}
		printf("%d\n", max);
	}
	return 0;
}