#include <stdio.h>
#include <stack>
#define Max(a,b) a>b?a:b

int t, n, m;
int pile[20001];
int l = 0;

void push(int num) {
	pile[l++] = num;
}

int top() {
	return pile[l - 1];
}

void pop() {
	l--;
}
bool empty() { return l == 0; }

int main() {
	scanf("%d", &t);
	for (int x = 0; x < t; x++) {
		scanf("%d", &n);
		push(0);
		for (int i = 0; i < n; i++) {
			int buffer;
			scanf("%d", &buffer);
			int p = buffer > top() ? buffer : top();
			push(p);
		}
		scanf("%d",&m);
		char op[2];
		for (int i = 0; i < m; i++) {
			scanf("%s", op);
			switch (op[0]) {
			case 'm':
				printf("%d\n", top());
				break;
			case 'r':
				pop();
				break;
			case 'a':
				int buffer;
				scanf("%d", &buffer);
				if (buffer > top())
					push(buffer);
				else
					push(top());
			}
		}
		while (!empty()) pop();
	}
	return 0;
}