#include <stdio.h>
#define child(k,n) 4*k+n 
//#define DEBUG
char arr[1024][1025];
int numTree[1398110];
int n, t, op, matsize, row, col;

void Ctt(int r, int c, int size, int id) {
	if (size == 1) {
		numTree[id] = 1;
	}
	else {
		int ns = size >> 1;
		int m1 = r + ns;
		int m2 = c + ns;
		Ctt(r, c, ns, child(id, 1));
		Ctt(r, m2, ns, child(id, 2));
		Ctt(m1, c,ns, child(id, 3));
		Ctt(m1, m2, ns, child(id, 4));
		int x1 = numTree[child(id, 1)];
		int x2 = numTree[child(id, 2)];
		int x3 = numTree[child(id, 3)];
		int x4 = numTree[child(id, 4)];
		if (x1 != 1 || x2 != 1
			|| x3 != 1 || x4 != 1
			|| arr[r][c] != arr[r][m2] || arr[r][c] != arr[m1][c] || arr[r][c] != arr[m1][m2]) {
			numTree[id] = 1 + x1 + x2 + x3 + x4;
		}
		else
			numTree[id] = 1;
	}
}



void Swim(int r, int c, int size, int id) {
	if (size == 1) {
		numTree[id] = 1;
	}
	else {
		int ns = size >> 1;
		int midr = r +ns;	//the first one of right sub
		int midc = c + ns;	//the first one of down sub
		if (row - 1 < midr) {
			if (col - 1 < midc) {
				Swim(r, c, ns, child(id, 1));
			}
			else {
				Swim(r, midc, ns, child(id, 2));
			}
		}
		else {
			if (col - 1 < midc) {
				Swim(midr, c, ns, child(id, 3));
			}
			else {
				Swim(midr, midc, ns, child(id, 4));
			}
		}
		int x1 = numTree[child(id, 1)];
		int x2 = numTree[child(id, 2)];
		int x3 = numTree[child(id, 3)];
		int x4 = numTree[child(id, 4)];
		if (x1 != 1 || x2 != 1
			|| x3 != 1 || x4 != 1
			|| arr[r][c] != arr[r][midc] || arr[r][c] != arr[midr][c] || arr[r][c] != arr[midr][midc]) {
			numTree[id] = 1 + x1 + x2 + x3 + x4;
		}
		else
			numTree[id] = 1;
	}
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		matsize = 1 << n;
		gets(arr[0]);
		for (int i = 0; i < matsize; i++) {
			gets(arr[i]);
		}
		scanf("%d", &op);
		for (int i = 0; i < op; i++) {
			scanf("%d%d", &row, &col);
			arr[row - 1][col - 1] = (!(arr[row - 1][col - 1]-'0'))+'0';
			if (!n)
				printf("1\n");
			else {
				if (!i) {
					Ctt(0, 0, matsize, 0);
					printf("%d\n", numTree[0]);
				}
				else {
					Swim(0, 0, matsize, 0);
					printf("%d\n", numTree[0]);
				}
			}
		}
	}
	return 0;
}