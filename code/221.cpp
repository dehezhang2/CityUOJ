#include <iostream>
#include <stdio.h>
#include <stdint.h>
using namespace std;
char buffer[1000];
int64_t a,b;
char c;
int main() {
	while (cin>>a) {
		cin >> c;
		cin >> b;
		if (c == '+')
			cout << a + b << endl;
		else
			cout << a - b << endl;
		
	}
	return 0;
}