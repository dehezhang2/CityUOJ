#include <stdio.h>
int len;
int id;
int num;
int main() {
	scanf("%d", &len);
	for (int i = 0; i < len; i++) {
		scanf("%d%d", &id, &num);
		int max = num;
		while (num != 1) {
			if (num % 2)
				num = 3 * num + 1;
			else
				num /= 2;
			max = max > num ? max : num;
		}
		printf("%d %d\n", id, max);
	}
	return 0;
}