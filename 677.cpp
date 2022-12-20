#include <stdio.h>
double H, U, D, F;
int main() {
	while (~scanf("%lf%lf%lf%lf", &H, &U, &D, &F)) {
		double dist = 0;
		double rate = U-D;
		int day = 1;
		dist += U;
		while (dist < H&&rate>0) {
			dist -= D;
			day++;
			U *= F / 100.0;
			rate = U - D;
			dist += U;
		} 
		if (dist > H)
			printf("succeeded on day %d\n", day);
		else
			printf("failed on day %d\n", day+1);
	}
	return 0;
}