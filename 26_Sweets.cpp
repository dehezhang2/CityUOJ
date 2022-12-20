#include <stdio.h>
int t,m,n;
char mat[401][401];
bool check(int r, int c) {
	bool a = 0, b = 0;
	if (r != 0 && r != m - 1)
		a = (mat[r - 1][c] == 118)&&(mat[r+1][c]==94);
	if(c!=0&&c!=n-1)
		b = (mat[r][c - 1] == 62) && (mat[r][c+1] == 60);
	return a || b;
}