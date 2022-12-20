#include <stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int h, m;
		scanf("%d:%d", &h,&m);
		if (m > 0) {
			m = 60 - m;
			h = 11 - h;
		}
		else{
			h = 12 - h;
			m = 0 - m;
		}
		if (h <= 0) h += 12;
		printf("%02d:%02d\n", h, m );
	}
	return 0;
}
