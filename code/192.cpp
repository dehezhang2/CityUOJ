#include <stdio.h>
int n;
//char buffer[4];
bool judge(int& w) {
	int w1, d1, w2, d2;
	bool flag=1;
	scanf("%d%d%d%d", &w1, &d1, &w2, &d2);
	if (!w1 && !judge(w1))	flag = 0;
	if (!w2 && !judge(w2))	flag = 0;
	if (!w)w = w1 + w2;
	return flag&&(w1 * d1 == w2 * d2);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	while (n--) {
		getchar(); getchar();
		int total = 0;
		printf(judge(total) ? "YES\n" : "NO\n");
		if(n)printf("\n");
	}
	return 0;
}