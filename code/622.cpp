#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

#define MAX 1005

int sa[MAX], height[MAX], n, bucket[MAX], Rank[MAX], map[MAX], t;
char str[MAX];
void sort(int* x, int* y, int m) {
	// x: key to sort, y: index of x as second key to sort, w: the bucket, m: number of buckets
	for (int i = 0; i < m; i++) bucket[i] = 0;
	for (int i = 0; i < n; i++) bucket[x[y[i]]]++;
	for (int i = 1; i < m; i++) bucket[i] += bucket[i - 1];
	for (int i = n - 1; i >= 0; i--) sa[--bucket[x[y[i]]]] = y[i];
}

bool cmp(int *x, int a, int b, int l) {
	if (x[a] == x[b]) {
		if (a + l >= n || b + l >= n)
			return false;
		return x[a + l] == x[b + l];
	}
	return false;
}

void build() {
	// i: index, k: the length of sorted prefix, p: number of distinct key(compare value)
	int i, k, m = 128, p;
	int *x = Rank, *y = map;
	n = strlen(str);
	x[n] = 0;
	for (int i = 0; i < n; i++) x[i] = str[i], y[i] = i;
	sort(x, y, m);
	for (k = 1, p = 1; p < n; k <<= 1, m = p) {
		for (p = 0,i = n-k; i < n; i++) y[p++] = i;
		for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;
		sort(x, y, m);
		int* temp = x;
		x = y;
		y = temp;
		for (i = 1, p = 1, x[sa[0]] = 0; i < n; i++) x[sa[i]] = cmp(y, sa[i - 1], sa[i], k) ? p - 1 : p++;
	}

}

void build_h()
{
	int i, j, k;
	for (i = 0; i < n; i++)
		Rank[sa[i]] = i;
	for (i = 0; i < n; i++)
	{
		if (Rank[i] == 0)
		{
			height[Rank[i]] = 0;
			continue;
		}
		if (i == 0 || height[Rank[i - 1]] <= 1)
			k = 0;
		else k = height[Rank[i - 1]] - 1;
		while (str[sa[Rank[i] - 1] + k] == str[sa[Rank[i]] + k]) k++;
		height[Rank[i]] = k;
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r" , stdin);
#endif
	scanf("%d\n", &t);
	while (t--) {
		gets(str);
		build();
		build_h();
		int ans = 0, count = 0;
		for (int i = 0; i < n; i++)
			ans = ans > height[i] ? ans : height[i];
		if (ans == 0)
			printf("No repetitions found!\n");
		else {
			for (int i = 0; i < n; i++)
			{
				if (ans == height[i])
				{
					for (int j = 0; j < ans; j++)
						printf("%c", str[sa[i] + j]);
					while (i < n && ans == height[i])
						count++, i++;
					break;
				}
			}
			printf(" %d\n", count + 1);
		}
		
	}
	return 0;
}