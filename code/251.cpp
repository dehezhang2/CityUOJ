#include <stdio.h>
#include <string.h>
//#define DEBUG
int m, n;
int mat[51][51];


void dfs(int i, int j) {
	mat[i][j] = -1;	
	if (i != 0 && mat[i-1][j]==1) dfs(i - 1, j);
	if (j != 0 && mat[i][j-1] == 1) dfs(i, j - 1);
	if (i != m - 1 && mat[i+1][j] == 1) dfs(i + 1, j);
	if (j != n - 1 && mat[i][j+1] == 1) dfs(i, j + 1);
	if (i != 0 && j != 0 && mat[i - 1][j-1] == 1) dfs(i - 1, j - 1);
	if (i != m - 1 && j != 0 && mat[i + 1][j-1] == 1) dfs(i + 1, j - 1);
	if (i != 0 && j != n - 1 && mat[i - 1][j+1] == 1) dfs(i - 1, j + 1);
	if (i != m - 1 && j != n - 1 && mat[i + 1][j+1] == 1) dfs(i + 1, j + 1);
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d%d", &n, &m) && m != 0) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j<n; j++) {
				scanf("%d", mat[i]+j);
			}
		}
		int cnt = 0;
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (mat[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}