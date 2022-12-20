#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

int arr1[55];
int arr2[55];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	int N;
	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr1[i]);
		}
		sort(arr1, arr1 + N);
		int idx2 = 0;
		int a = -1, b = 0x3f3f3f3f;
		for (int i = 0, j = N-1; i < j; i++,j--) {
			arr2[idx2++] = arr1[i] + arr1[j];
			a = max(a, arr2[idx2-1]);
			b = min(b, arr2[idx2 - 1]);
		}
		printf("%d\n", a - b);

	}

	
	return 0;
}