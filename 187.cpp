#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char str[10000];

void reverse(int p, int q) {
	for (int i = p, j = q; i < j; i++, j--) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
int main() {

	while (cin.getline(str,10000)) {
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] != ' ') {
				int j;
				for (j = i + 1; str[j] != ' '&&str[j]!='\0'; j++);
				reverse(i, j-1);
				i = j;
			}
		}
		printf("%s\n", str);
	}
	return 0;
}