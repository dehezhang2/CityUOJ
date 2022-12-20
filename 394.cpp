#include <stdio.h>

void print(int num) {
	if (num < 2) printf("%d", num);
	else {
		print(num / 2);
		printf("%d", num % 2);
	}
}
int main() {
	int num;
	while (~scanf("%d", &num)) {
		print(num);
		printf("\n");
	}
	return 0;
}