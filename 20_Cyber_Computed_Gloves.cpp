#include <stdio.h>
#include <iostream>
using namespace std;
#define change *(long long*)
char str[9];
int n;
void back(long long num) {
	while (num) {
		printf("%c", char(num % (long long)(256)));
		num >>= 8;
	}
	printf("\n");
}
int main() {
	while (~scanf("%d", &n)) {
		fgets(str, 9, stdin);
		long long ans = 0L;
		for (int i = 1; i < 2 * n; i++) {
			fgets(str, 9, stdin);
			str[7] = '\0';
			ans ^= change(str);
		}
		back(ans);
	}
	return 0;
}