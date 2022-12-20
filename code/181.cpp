#include <stdio.h>
int r, m, n;
int main() {
	int i = 1;
	while (~scanf("%d", &r) && r != 0) {
		scanf("%d%d", &m, &n);
		if (m*m + n * n <= 4 * r*r) {
			printf("Pizza %d fits on the table.\n", i++);
		}
		else {
			printf("Pizza %d does not fit on the table.\n", i++);
		}
	}
	return 0;
}