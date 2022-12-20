#include<stdio.h>
#include<string.h>
int n;
bool rec[1000001];
int prime[100000];
int getDigit(int n) {
	if (n < 10) return n * n;
	return (n % 10)*(n % 10) + getDigit(n / 10);
}
bool isHappy(int n) {
	if (n == 4) return false;
	if (n == 1) return true;
	return isHappy(getDigit(n));
}
int main() {
	memset(rec, 1, sizeof(rec));
	scanf("%d", &n);
	int num = 0;
	for (int i = 2; i <= n; i++) {
		if (rec[i]) {
			prime[++num] = i;
		}
		for (int j = 1; j <= num; ++j) {
			if (i*prime[j] > n)
				break;
			rec[i*prime[j]] = false;
			if (i%prime[j] == 0)
				break;
		}
		if (rec[i] && isHappy(i))
			printf("%d\n", i);
	}
	return 0;
}