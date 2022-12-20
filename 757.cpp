#include <stdio.h>
using namespace std;

int heap[100005];
int tail , n, tmp, ans;

void push(int key) {
	int tmp;
	heap[tail++] = key;
	for (int pos = tail - 1; pos&& heap[pos] < heap[(pos - 1) / 2]; pos = (pos - 1) / 2) {
		tmp = heap[pos];
		heap[pos] = heap[(pos - 1) / 2];
		heap[(pos - 1) / 2] = tmp;
	}
}

void sink(int pos) {
	if (2 * pos + 1 < tail) {
		int minc = 2 * pos + 1;
		minc = (minc + 1 < tail) && heap[minc + 1] < heap[minc] ? minc + 1 : minc;
		if (heap[minc] < heap[pos]) {
			int tmp = heap[minc];
			heap[minc] = heap[pos];
			heap[pos] = tmp;
			sink(minc);
		}
	}
}


int pop() {
	int tmp = heap[0];
	heap[0] = heap[--tail];
	sink(0);
	return tmp;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d", &n)) {
		tail = ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			push(tmp);
		}
		while (tail != 1) {
			int a = pop() + pop();
			ans += a;
			push(a);
		}
		printf("%d\n", ans);
	}
	return 0;
}