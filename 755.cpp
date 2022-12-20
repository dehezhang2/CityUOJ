#include<stdio.h>
const int LEN = 100005;
long long s2[LEN];
int s1[LEN];
int len = 0,t,n;
long long h;
void push(int index, long long height) {
	s1[len] = index;
	s2[len] = height;
	len++;
}
void pop() {
	len--;
}
int topi() {
	return s1[len - 1];
}
long long toph() {
	return s2[len - 1];
}
bool empty() {
	return len == 0;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		long long max = 0;
		for (int i = 0; i < n; i++) {
			scanf("%ld", &h);
			while (!empty() && toph() >= h) { //pop if the toph equals h
				long long H = toph();
				pop();
				if (!empty())
					max = max > H*(i - topi() - 1) ? max : H * (i - topi() - 1);
				else
					max = max > H*(i) ? max : H * i;
			}
			push(i, h);
		}
		while (!empty()) {
			long long H = toph();
			pop();
			if (!empty())
				max = max > H*(n - topi() - 1) ? max : H * (n - topi() - 1);
			else
				max = max > H*(n) ? max : H * n;
		}
		printf("%ld\n", max);
	}
}