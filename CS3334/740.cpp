#include <stdio.h>
#include <iostream>
using namespace std;
struct Node {
	int tag;
	Node* pre;
	Node* next;
	Node(int t) { tag = t; }
};

class List {
	Node* first;
	Node* end;
	int len = 0;
	Node* search(int n) {
		Node* p;
		if (n <= (len / 2)) {
			p = first;
			for (int i = 1; i < n; i++)
				p = p->next;
		}
		else {
			p = end;
			for (int i = 0; i < (len - n); i++)
				p = p->pre;
		}
		return p;
	}
public:
	List() { first = NULL; }
	void init(int tag) { push(len, tag); }
	void push(int n, int tag) {
		Node* nnode = new Node(tag);
		if (first == NULL) {
			first = nnode;
			nnode->next = first;
			nnode->pre = first;
			end = nnode;
		}
		else {
			Node* p = search(n);
			nnode->next = p->next;
			nnode->pre = p;
			p->next->pre = nnode;
			p->next = nnode;
			if (n == len)
				end = nnode;
		}
		len++;
	}

	void print(int n) {
		Node* p = search(n);
		cout << p->tag << endl;
	}

	void pop(int n) {
		Node* p = search(n);
		p->next->pre = p->pre;
		p->pre->next = p->next;
		if (p == first) 
			first = p->next;
		if (p == end)
			end = p->pre;
		delete p;
		len--;
	}

	void reverse(int i, int j) {
		Node* p = search(i);
		Node* q = search(j);
		for (int k = 0; k < (j - i + 1) / 2; k++) {
			int temp = p->tag;
			p->tag = q->tag;
			q->tag = temp;
			p = p->next;
			q = q->pre;
		}
	}
};

int main() {
	int t, n;
	List l;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		l.init(n);
	}
	scanf("%d", &t);
	int op;
	for (int i = 0; i < t; i++) {
		scanf("%d%d", &op, &n);
		switch (op) {
		case 1:
			int tag;
			scanf("%d", &tag);
			l.push(n, tag);
			break;
		case 2:
			l.pop(n);
			break;
		case 3:
			int m;
			scanf("%d", &m);
			l.reverse(n, m);
			break;
		case 4:
			l.print(n);
		}
	}
	return 0;
}
