#include <stdio.h>
char ch;
int l2 = 0;
int s2[501];
void push(int b) {
	s2[l2++] = b;
}
int pop() {
	return s2[--l2];
}
int main() {
	while (~scanf("%c", &ch)) {
		int i = 0;
		int ans = 0;
		do {
			if (ch == '(') {
				push(i);
			}
			else {
				ans ^= (i - pop() - 1) / 2 + 1;
			}
			i++;
		} while (~scanf("%c", &ch) && ch != '\n');
		printf("%d\n", ans);
	}
	return 0;
}