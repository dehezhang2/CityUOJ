#include<stdio.h>
#include<cstdint>
#include <string.h>
using namespace std;

int tmp[5000005], tmp2[5000005];
int t, n, q;
long long ans = 0;


int maxbit() {
	int d = 1;
	int p = 1024;
	for (int i = 0; i < n; ++i) {
		while (tmp[i] >= p) {
			p *= 1024;
			++d;
		}
	}
	return d;
}

void radixSort() {
	int digit = maxbit(), bucket[1024];
	for (int i = 1, radix = 1; i <= digit; i++, radix *= 1024) {
		for (int j = 0; j < 1024; j++) bucket[j] = 0;
		for (int j = 0; j < n; j++) bucket[(tmp[j] / radix) % 1024]++;
		for (int j = 1; j < 1024; j++) bucket[j] += bucket[j - 1];
		for (int j = n - 1; j >= 0; j--) tmp2[--bucket[(tmp[j] / radix) % 1024]] = tmp[j];
		for (int j = 0; j < n; j++) tmp[j] = tmp2[j];
	}
}

void print64(long long a) {
	if (a <= 100000000) {
		printf("%d\n", a);
	}
	else {
		printf("%d", a / 100000000);
		printf("%08d\n", a % 100000000);
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &q);
		ans = 0;
		tmp[0] = tmp[1] = 1;
		for (int i = 2; i < n; i++) tmp[i] = (tmp[i-1]+tmp[i-2]) % q;
		radixSort();
		for (int i = 0; i < n; i++) ans += (i + 1)*((long long)tmp[i]) % q;
		print64(ans%q);
	}
	return 0;
}