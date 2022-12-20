#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 3005
char buffer[MAX];
char map[150];
int check() {
	stack<char> s;
	int ni,i;
	for (i = 0, ni = 1; buffer[i]; i++,ni++) {
		if (buffer[i] == '{' || buffer[i] == '[' || buffer[i] == '<') {
			s.push(buffer[i]);
		}
		else if (buffer[i] == '(') {
			if (buffer[i + 1] == '*') {
				s.push(buffer[i + 1]);
				i++;
			}
			else {
				s.push(buffer[i]);
			}
		}
		else if (buffer[i] == ')' || buffer[i] == '}' || buffer[i] == ']' || buffer[i] == '>') {
			if (s.empty()||s.top() != map[buffer[i]])return ni;
			s.pop();
		}
		else if (buffer[i] == '*'&&buffer[i + 1] == ')') {
			
			if ( s.empty()||s.top() != map[buffer[i]]) return ni;
			s.pop();
			i++;
		}
	}
	if (!s.empty()) return ni;
	return -1;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	map[')'] = '('; map[']'] = '['; map['}'] = '{'; map['*'] = '*'; map['>'] = '<';
	while (cin.getline(buffer, MAX)) {
		int x = check();
		printf(x == -1 ? "YES\n" : "NO %d\n",x );
	}
	return 0;
}