#include <stdio.h>
#include <string.h>
using namespace std;
//#define DEBUG
int ans[101];
//int child[101][101];
int dps[101];
int t, n, root, a, b;
/*void setDps(int id) {
	if (id == root) dps[id] = 0;
	else dps[id] = dps[ans[id]] + 1;
	if (child[id][0] == 0) {
		return;
	}
	else {

		for (int i = 1; i <= child[id][0]; i++) {
			setDps(child[id][i]);
		}
	}
}*/

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--) {
		/*for (int i = 0; i < 101; i++)
			memset(child[i], 0, sizeof(child[i]));*/
		scanf("%d%d", &root, &n);
		for (int i = 0; i < n - 1; i++) {
			scanf("%d%d", &a, &b);
			ans[a] = b;
			dps[a] = dps[b] + 1;
			//child[b][++child[b][0]] = a;
		}
		//setDps(root);
		scanf("%d%d", &a, &b);
		int r;
		if(dps[a] < dps[b])
			while (dps[b] != dps[a]) b = ans[b];
		else
			while (dps[a] != dps[b]) a = ans[a];
		while (a != b) {
			a = ans[a];
			b = ans[b];
		}
		printf("%d\n", a);
	}
	return 0;
}