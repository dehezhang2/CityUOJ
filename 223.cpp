#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
//#define DEBUG
using namespace std;
int main() {
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
    #endif
	int n;
	cin >> n;
	string str;
	while (n--) {
		int m;
		cin >> m;
		getline(cin, str);
		bool need = 0;
		for (int i = 0; i < m; i++) {
			getline(cin, str);
			if (!need) need = 1;
			else cout << " ";
			cout <<str;
		}
		cout << endl << endl;
	}
	return 0;
}