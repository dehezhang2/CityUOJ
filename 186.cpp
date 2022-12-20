#include <stdio.h>
#include <iostream>
using namespace std;
bool isOk(char pre){
	return (pre <= 'z'&&pre >= 'a') || (pre <= 'Z'&&pre >= 'A');
}
int main() {
	char ch[1000];
	while (cin.getline(ch,1000)) {
		int cnt = 0;
		for (int i = 0; ch[i] != '\0'; i++) {
			if (isOk(ch[i])) {
				for (; isOk(ch[i]); i++);
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}