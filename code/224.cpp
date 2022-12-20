#include <stdio.h>
char str[50];
int main() {
	while (~scanf("%s", str)) {
		int start = str[0] == '-' ? 1 : 0;
		int cnt = 0;
		for (int i = start; str[i]; i++) {
			if (str[i] >= '0'&&str[i] <= '9')
				cnt = 16 * cnt + (int)(str[i] - '0');
			else
				cnt = 16 * cnt + (int)(str[i] - 55);
		}
		if (str[0] == '-') printf("-%d\n", cnt);
		else printf("%d\n", cnt);
	}
}