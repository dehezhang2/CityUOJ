#include <iostream>
using namespace std;

struct Node {
	int tag;
	Node* next;
	Node(int t) {tag = t;}
};

class Circle {
	Node* first;
	Node* end;
	int len = 0;
public:
	Circle() {first = NULL;}
	void init(int tag) {
		Node* nnode = new Node(tag);
		if (first == NULL) {
			end = first = nnode;
			nnode->next = first;
		}
		else {
			end->next = nnode;
			nnode->next = first;
			end = nnode;
		}
		len++;
	}
	void push(int n, int tag) {
		Node* nnode = new Node(tag);
		if (first == NULL) {
			first = nnode;
			nnode->next = first;
		}
		else {
			n = (n - 1) % len + 1;
			for (int i = 1; i < n; i++)
				first = first->next;
			nnode->next = first->next;
			first->next = nnode;
			first = nnode;
		}
		len++;
	}
	void print(int n) {
		n = (n - 1) % len + 1;
		for (int i = 1; i < n; i++)
			first = first->next;
		cout<<first->tag<<endl;
	}
	void pop(int n) {
		n = (n - 1) % len + 1;
		for (int i = 1; i < n-1; i++)
			first = first->next;
		Node* d = first->next;
		first->next = d->next;
		first = first->next;
		delete d;
		len--;
	}
};

int main() {
	int t , n;
	Circle c;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin>>n;
		c.init(n);
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		int op;
		cin>>op>>n;
		if (op == 1) {
			int tag;
			cin>>tag;
			c.push(n, tag);
		}
		else if (op == 2)c.pop(n);
		else c.print(n);
	}
	return 0;
}
