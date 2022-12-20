#include <stdio.h>
int t, c, n;
int list[2000];
int main() {
	scanf("%d", &t);
	for(int x=0;x<t;x++){
		scanf("%d%d", &c,&n);
		for (int i = 0; i < n; i++) {
			scanf("%d", list + i);
		}
		int i, j;
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				if (list[i] + list[j] == c)
					goto end_of_inner_loop;
			}
		}
	end_of_inner_loop:
		printf("Case #%d: %d %d\n", x + 1, i + 1, j + 1);
	}
	return 0;
}