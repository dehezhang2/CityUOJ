#include <stdio.h>
int s, e;
int main() {
	while (~scanf("%d%d", &s, &e)) {
		if (s % 2 != 0 && e % 2 != 0)
			printf("%d\n", (e - s + 1) / 2 + 1);
		else
			printf("%d\n", (e - s + 1) / 2);
	}
	return 0;
}