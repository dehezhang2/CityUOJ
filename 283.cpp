#include <stdio.h>
using namespace std;
int main() {
	int arr[3] = {0};
	char str[25];
	int x = 1, num = 0;
	while (~scanf("%s", str)) {
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] != '+'&&str[i] != '=') {
				arr[num] += (int)(str[i] - '0')*x;
				x *= 10;
			}
			else {
				num++;
				x = 1;
			}
		}
		if (arr[2] == arr[0] + arr[1])
			printf("True\n");
		else
			printf("False\n");
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;
		arr[0] = arr[1] = arr[2] = 0;
		num = 0;
		x = 1;
	}

	return 0;
}