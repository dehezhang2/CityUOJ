#include<stdio.h>
const int LEN = 70005;
int arr[LEN];
int head = 0, tail = 0;
int len = 0;
int size() { return len; }
bool empty() { return len == 0; }

void push(int a) {
	arr[tail++] = a;
	tail %= LEN;
	len++;
}
int last() {
	return arr[(tail - 1)%LEN];
}
int front() {
	return arr[head];
}
void pop() {
	head++;
	head %= LEN;
	len--;
}
int num;
int A, O, L;
int timer;
int main() {
	while (~scanf("%d", &num)) {
		timer = 0;
		bool isServed = 1;
		for (int i = 0; i < num; i++) {
			scanf("%d%d%d", &A, &O, &L);
			timer = timer > A ? timer : A;
			while (!empty() && front()<= A) {
				pop();
			}
			if (size() <= L) {
				timer += O;
				push(timer);
			}
			else if (i == num - 1)
				isServed = 0;
		}
		if (!isServed) {
			printf("-1\n");
		}
		else {
			printf("%d\n", timer - O);
		}
		head = tail = len = 0;
	}
	return 0;
}