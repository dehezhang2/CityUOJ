#include <stdio.h>
#include <stack>
using std::stack;
//stack<int> s;
int s[670];
char str[1005];
int len = 0;
void push(int num) { s[len++] = num; }
int pop() { return s[--len]; }
int main() {
	while (fgets(str, 1004,stdin)) {
		for (int i = 0; str[i] != '\n'; i++) {
				if (str[i] == '+') {
					int a = pop();
					int b = pop();
					push(a + b);
				}
				else if (str[i] == '-') {
					int a = pop();
					int b = pop();
					push(b - a);
				}
				else if (str[i] == '*') {
					int a = pop();
					int b = pop();
					push(a * b);
				}
				else if(str[i]<='9'&&str[i]>='0'){
					push((int)(str[i] - '0'));
				}
		}
		printf("%d\n", pop());
	}
	return 0;
}