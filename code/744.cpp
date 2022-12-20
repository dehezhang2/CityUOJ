#include <stdio.h>
using namespace std;

int s[3005];
int len = 0;


int a[3005], b[3005];
int n, m, t;

void push(int num) {
	s[len++] = num;
}

int top() {
	return s[len - 1];
}

bool isEmpty() {
	return len == 0;
}

void pop() {
	len--;
}

int main() {
	scanf("%d",&t);
	for (int x = 0; x < t; x++) {
		scanf("%d",&n);
		len = 0;
		for (int i = 0; i < n; i++)
			scanf("%d",a+i);
		scanf("%d",&m);

		for (int c = 0; c < m; c++) {
			for (int i = 0; i < n; i++)
				scanf("%d", b + i);
			// check in detail
			int pos = 0;
			for (int i = n - 1; i >= 0; i--) {
				push(a[i]);
				while (!isEmpty() && top() == b[pos]) {
					pop();
					pos++;
				}
			}
			if (pos == n)
				printf("Aye\n");
			else
				printf("Impossible\n");
		}

	}
	return 0;
}