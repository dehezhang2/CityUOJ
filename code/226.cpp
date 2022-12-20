#include<stdio.h>
#include <string.h>
char str[130];
int main() {
	while (fgets(str,130,stdin)) {
		for (int i = strlen(str) - 1; i >= 0; i--) {
			char ans;
			if (str[i] == '\n') continue;
			if (str[i] <= 'z'&&str[i] >= 'a')
				ans = str[i] - 'a' + 'A';
			else if (str[i] <= 'Z'&&str[i] >= 'A')
				ans = str[i] - 'A' + 'a';
			else ans = str[i];
			printf("%c", ans);
		}
		printf("\n");
	}
	return 0;
}