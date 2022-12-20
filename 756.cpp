#include <stdio.h>
#include <iostream>
#include <utility>
#include <cassert>
using namespace std;
int heap[100005];
int sum,tail,n,id;
char op;
#define parent(k) (k-1)/2
#define child(k,id) k*2+id


void insert(int k) {
	heap[tail++] = k;
	sum += k;
	for (int pos = tail - 1; pos&&heap[pos] > heap[parent(pos)]; pos = parent(pos)) {
		int tmp = heap[pos];
		heap[pos] = heap[parent(pos)];
		heap[parent(pos)] = tmp;
	}
}

void sink(int p) {
	if (child(p,1) <= tail - 1) {
		int maxc = child(p, 1);
		if (child(p, 2) <= tail - 1) {
			maxc = heap[maxc] > heap[child(p, 2)] ? maxc : child(p, 2);
		}
		if (heap[maxc] > heap[p]) {
			int tmp = heap[maxc];
			heap[maxc] = heap[p];
			heap[p] = tmp;
			sink(maxc);
		}
	}
}

void pop() {
	sum -= heap[0];
	heap[0] = heap[--tail];
	sink(0);
}


int main() {
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
	while (cin>>n) {
		sum = tail = 0;
		while (n--) {
			cin >> op;
			switch (op){
			case 'a':
				cin >> id;
				insert(id);
				break;
			case 'p':
				pop();
				break;
			case 'r':
				cout << sum << endl;
			}
		}
	}
	return 0;
}