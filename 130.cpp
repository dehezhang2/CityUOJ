#include <stdio.h>
using namespace std;
int main() {
	int a, b, c;
	while (~scanf("%d%d%d", &a, &b, &c)&&a!=0) {
		int ans = (a - 7)*(b - 7) / 2;
		if (a % 2 == 1 || b % 2 == 1||c==0)
			printf("%d\n",ans);
		else 
			printf("%d\n",ans+1);
	}

	return 0;
}