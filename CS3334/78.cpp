#include <stdio.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	char str[55];
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; str[j] != '\0'; j++) {
			int hasBiger = 0;
			for (int k = j + 1;  str[k] != '\0'; k++)
				if (str[k] > str[j]) hasBiger = 1;
			if (!hasBiger) printf("%c", str[j]);
		}
		printf("\n");
	}
	return 0;
}
