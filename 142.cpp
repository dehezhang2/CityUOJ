#include <stdio.h>
int t, n, m;

int root(int* rec, int a) {
	if (rec[a] == a) return a;
	else return rec[a] = root(rec, rec[a]);	//change the root every time
}

int main() {

	scanf("%d", &t);
	for (int cnt = 0; cnt < t; cnt++) {
		scanf("%d%d", &n, &m);
		int* rec = new int[n + 5];
		int* size = new int[n + 5];
		for (int i = 1; i < n + 1; i++) {
			rec[i] = i;
			size[i] = 1;
		}
		int a, b;
		int max = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			int ra = root(rec, a);
			int rb = root(rec, b);
			if (ra != rb) {
				size[ra] += size[rb];
				rec[rb] = ra;
				if (size[ra] >= max)
					max = size[ra];
			}
		}
		printf("%d\n",max);
		delete[]rec;
		delete[]size;
	}
	return 0;
}
