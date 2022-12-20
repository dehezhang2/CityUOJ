#include <stdio.h>
#include <string.h>
 
int col[350], m, n, tmp; 
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
	while(scanf("%d %d", &m, &n) == 2){
		memset(col, 0, sizeof(col));
		bool found = true;
		for(int i=0; i<m; i++){
			for(int j=1; j<=n; j++){
				scanf("%d", &tmp);
				col[j] = (col[j]<<1) + tmp;
				if(i == m-1 && col[j] == 0)
					found = false;
			}
		}
		if(!found)	{printf("It is impossible\n");continue;}
		found = false;
		for(int i=1; i<(1<<m); i++){
			bool judge = true;
			for(int j=1; j<=n; j++){
				int val = col[j] & i;
				if(val == 0 || (val & (val-1)) != 0){judge = false; break;}
			}
			if(judge)	{found = true;break;}
		}
		printf(found ? "Yes, I found it\n" : "It is impossible\n");
	}
	return 0;
}