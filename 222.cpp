#include <stdio.h>
using namespace std;
char line[105];
int main() {
	int needbank = 0;
	while (fgets(line, 105, stdin)) {
		double ans = 0;
		for (int i = 0; line[i] != '\0'; i++) {
			double d = 1,cnt = 0;
			while (line[i] != '.'&&line[i]!=' '&&line[i]!='\n') {
				cnt = (10.0 * cnt + (double)(line[i] - '0'));
				i++;
			}
			double dig = 0.1;
			if (line[i] == '.') {
				i++;
				while (line[i]!='\n'&&line[i] != ' ') {
					cnt += dig * (double)(line[i] - '0');
					dig /= 10.0;
					i++;
				}
			}
			ans += cnt;
		}
		if (needbank == 0) {
			needbank = 1;
		}
		else {
			printf("\n");
		}
		printf("%.4lf\n", ans);
	}
	return 0;
}