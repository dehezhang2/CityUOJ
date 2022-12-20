#include <stdio.h>
#include <string.h>
char line[85];
int len;
int main() {
	scanf("%d", &len);
	fgets(line, 85, stdin);
	for (int i = 1; i <= len; i++) {
		fgets(line, 85, stdin);
		int cnt = 0;
		for (int j = 0; line[j]!='\0'; j++) {
			if (line[j] == 'F'&&line[j + 1] == 'r'&&line[j + 2] == 'a'&&line[j + 3] == 'n'&&line[j + 4] == 'c'&&line[j + 5] == 'e')
				cnt++;
		}
		printf("Sentence #%d: %d\n", i, cnt);
		
	}
}