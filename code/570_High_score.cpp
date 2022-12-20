#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
#define MAX 1005

char buffer[MAX];
int n;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d\n", &n);
	while (n--) {
		cin.getline(buffer, MAX);
		int cnt = 0;
		int len;
		for (len = 0; buffer[len]>='A'&&buffer[len]<='Z'; len++) {
			int val = buffer[len] - 'A';
			cnt += (val<26-val)?val:26-val;
		}
		int ans = cnt + len - 1;
		for (int i = 1; i < len; i++) {
			if (buffer[i] == 'A') {
				int j;
				for (j = i+1; j < len&&buffer[j] == 'A'; ++j);
				ans = min(ans, cnt + min((i-1)*2+(len-j),(len-j)*2+(i-1)));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
