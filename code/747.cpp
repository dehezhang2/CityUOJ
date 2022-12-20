#include <stdio.h>
using namespace std;
const int LEN = 1005;
class Node {
public:
	int val;
	int pos;
	Node(int m, int n) {
		val = m;
		pos = n;
	}
	Node() {}
};
Node arr[LEN];
int head = 0, tail = 0;
int l = 0;
int size() { return l; }
bool empty() { return l == 0; }

void push(Node& a) {
	arr[tail++] = a;
	tail %= LEN;
	l++;
}
Node& front(int n) {
	int index = (head + n) % LEN;
	return arr[index];
}
void pop() {
	head++;
	head %= LEN;
	l--;
}
int len, k;

int takeOut(int n) {
	int max = -100000, maxp = 0;
	for (int i = 0; i < n; i++) {
		Node nd = front(i);
		if (max < nd.val) {
			max = nd.val;
			maxp = nd.pos;
		}
	}
	for (int i = 0; i < n;i++) {
		if (front(0).pos != maxp) {
			front(0).val -= 1;
			push(front(0));
		}
		pop();
	}
	return maxp;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int x = 0; x < t; x++) {
		scanf("%d%d", &len, &k);
		int temp;
		for (int i = 0; i < len; i++) {
			scanf("%d", &temp);
			Node nd(temp, i + 1);
			push(nd);
		}
		bool need = 0;
		while (!empty()) {
			int maxp = size() >= k ? takeOut(k) : takeOut(size());
			if (!need) {
				printf("%d", maxp);
				need = 1;
			}
			else
				printf(" %d", maxp);
		}
		printf("\n");
		while (!empty()) pop();
	}
	return 0;
}