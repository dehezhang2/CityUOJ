#include <stdio.h>
char str[19];
int main() {
	while (~scanf("%s", str)) {
		bool isMagic = 1;
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == '1') {
				int cnt = 0;
				while (str[i+1] == '4'&&cnt < 2) {
					cnt++;
					i++;
				}
			}
			else {
				isMagic = 0;
				break;
			}
		}
		if (isMagic)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}