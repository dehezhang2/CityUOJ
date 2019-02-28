#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 130
int n;
char buffer[MAX];
bool dp[MAX][MAX];
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d\n", &n);
	while (n--) {
		gets(buffer);
		int size = strlen(buffer);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < size; i++){dp[i][i] = 1;dp[i][i+1]=0;}

		for (int len = 2; len <= size; len++) {
			for (int i = 0; i + len <= size; i++) {
				int j = i + len;
				if ((buffer[i] == '('&&buffer[j-1] == ')') || (buffer[i] == '['&&buffer[j-1] == ']')) {
					dp[i][j] |= dp[i + 1][j - 1];
				}
				for (int k = i + 2; k < j-1; k++) {
					dp[i][j] |= (dp[i][k] && dp[k][j]);
				}
			}
		}
		printf(dp[0][size]||size==0 ?"Yes\n":"No\n");
	}
	return 0;
}
