#include <stdio.h>

int t, n;
int pre[101];	//p->l->r
int in[101];	//l->p->r
int reci[101];	//position of a value in the inorder tree
int cnt = 0;
void print(int lo,int hi) {
	if (lo < hi) {
		int current = cnt;
		int root = pre[cnt++];
		print(lo, reci[root]);
		print(reci[root] +1, hi);
		if (current == 0)
			printf("%d", root);
		else
			printf("%d ", root);
	}
}

int main() {
	scanf("%d", &t);
	for (int x = 0; x < t; x++) {
		scanf("%d", &n);
		cnt = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", pre+i);
		}
		for (int i = 0; i < n; i++){
			scanf("%d", in+i);
			reci[in[i]] = i;
		}
		int po = 0;
		print(0,n);
		printf("\n");
	}
	return 0;
}