#include <stdio.h>
#include <string.h>
char str[105];
char ans[105];
int max=1;
bool inRange(int i) {
	return (str[i] == '-' || (str[i] <= 'Z'&&str[i] >= 'A') || (str[i] <= 'z'&&str[i] >= 'a'));
}
int main() {
	while (~scanf("%s", str) && strcmp(str, "E-N-D") != 0) {
		int cnt = 0;
		for (int i = 0; str[i]!='\0'; i++) {
			if (inRange(i))
				cnt++;
		}
		if (cnt > max) {
			max = cnt;
			strcpy(ans, str);
		}
	}
	for (int i = 0; ans[i]!='\0'; i++) {
		if (ans[i] >= 'A'&&ans[i] <= 'Z') {
			printf("%c", ans[i] + 32);
		}
		else if ((ans[i] >= 'a'&&ans[i] <= 'z') || ans[i] == '-') {
			printf("%c", ans[i]);
		}
	}
	printf("\n");
	return 0;
}
