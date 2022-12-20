#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <sstream>
using namespace std;
string str,buffer;
int n;
int main() {
	cin >> n;
	int cnt = 0;
	getline(cin, buffer);
	while (n--) {
		cout << "Case #" << (++cnt) << ":";
		getline(cin, buffer);
		stack<string> st;
		stringstream input(buffer);
		while (input >> str) {
			st.push(str);
		}
		while (!st.empty()) {
			cout << " ";
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
	return 0;
}