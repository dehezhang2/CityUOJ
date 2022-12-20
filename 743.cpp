#include <stdio.h>
#include <vector>
using namespace std;
char str[100001];
vector<int> p;
vector<char> c;

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	while (fgets(str,100005,stdin)) {
		int pos = 0;
		for (int i = 0; str[i]!='\0'; i++) {
			if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
				c.push_back(str[i]);
				p.push_back(i + 1);
			}
			else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
				char back = c.back();
				if (c.empty()|| (str[i] == ')'&&back != '(')|| (str[i] == ']'&&back != '[')|| (str[i] == '}'&&back != '{')) {
					pos = i + 1;
					break;
				}
				c.pop_back();
				p.pop_back();
			}
		}
		if (c.empty()&& pos==0)
			printf("Success\n");
		else {
			if (pos)
			   printf("%d\n",pos);
			else
				printf("%d\n",p.front());
		}
		c.clear();
		p.clear();
	}
	return 0;
}