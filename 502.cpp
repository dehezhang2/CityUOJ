#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int num;
stack<bool> st;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	while (~scanf("%d\n", &num) && num) {
		while (num) {
			st.push(num&1);
			num >>= 1;
		}

		int ans = 0, pos = 0;
		while (!st.empty()) {
			ans += (((int)st.top()) << pos);
			st.pop();
			pos++;
		}
		printf("%d\n", ans);
	}
	return 0;
}