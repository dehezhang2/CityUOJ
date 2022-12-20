#include <stdio.h>
#include <iostream>
using namespace std;
char str[100];
int arr[100];

int main() {
	while (~scanf("%s", str)) {
		for (int i = 0; str[i] != '\0'; i ++) {
			if (i % 2) arr[i] = -1;
			else arr[i] = str[i] - '0';
		}
		for (int i = 1; str[i] != '\0'; i += 2) {
			if (str[i] == '^') {
				int cnt = 1;
				for (int j = 0; j < arr[i+1]; j++)
					cnt *= arr[i-1];
				arr[i] = cnt;
				arr[i - 1] = arr[i + 1] = -1;
			}
		}
		for (int i = 1; str[i] != '\0'; i += 2) {
			if (str[i] == '*') {
				int j , k;
				for (j = i; j >= 0 && arr[j]==-1; j--);
				for (k = i; arr[k]==-1; k++);
				arr[i] = arr[k] * arr[j];
				arr[j] = arr[k] = -1;
			}
		}
		int cnt = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			if (arr[i] != -1) {
				cnt += arr[i];
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}