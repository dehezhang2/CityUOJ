#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define VAL 100000

int getans(int a, int k, int n) {
	long long result = 1, nk = 0;
	while (result < n&&nk<k) {
		result *= a;
		nk++;
	}
	if (result < n)return result;
	return (getans(result%n, k / nk, n)*getans(a, k%nk, n))%n;
}
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int a, k, n, result;
	while (scanf("%d%d%d", &a, &k, &n) != EOF) {
		a = a % n;
		if (n == 1)printf("0\n");
		else {
			result = getans(a, k, n);
			printf("%d\n", result);
		}
	}
	return 0;
}