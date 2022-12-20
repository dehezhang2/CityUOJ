#include <stdio.h>
int n;
bool p;
int start[101];
int during[101];

int head1=0, head2=0, tail1=0, tail2=0;
int q1[101], q2[101];
void push(int num,int id) { 
	if (id == 1) {
		q1[tail1++] = num;
		tail1 %= 51;
	}
	else {
		q2[tail2++] = num;
		tail2 %= 51;
	}
}
int front(int id) {
	if (id == 1) 
		return q1[head1];
	return q2[head2];
}
void pop(int id){
	if (id == 1) {
		head1++;
		head1 %= 51;
	}
	else {
		head2++;
		head2 %= 51;
	}
}
bool empty(int id) {
	if (id == 1) return head1 == tail1;
	return head2 == tail2;
}

int main() {
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", start + i, during + i, &p);
			if (!p) push(i,1);
			else push(i,2);
		}

		int timer = 0;
		while (!empty(1) || !empty(2)) {
			int min;
			if (!empty(1) && !empty(2))
				min = start[front(1)] < start[front(2)] ? start[front(1)] : start[front(2)];
			else if (empty(1))
				min = start[front(2)];
			else
				min = start[front(1)];
			timer = timer > min ? timer : min;
			while(!empty(1)&&start[front(1)] <= timer){
				timer += during[front(1)];
				during[front(1)] = timer;
				pop(1);
			}
			if(!empty(2)&&start[front(2)] <= timer) {
				timer += during[front(2)];
				during[front(2)] = timer;
				pop(2);
			}
		}
		for (int i = 0; i < n - 1; i++) {
			printf("%d ", during[i]);
		}
		printf("%d\n", during[n - 1]);
	}
	return 0;
}