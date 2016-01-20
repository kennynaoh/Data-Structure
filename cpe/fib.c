#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int number;
	
	

	while(scanf("%d", &number) != EOF){

		int f0 = 0;
		int f1 = 1;
		int ans = 0;
		int i;
		
		if(number == 0){
			ans = 0;
		}else if(number == 1){
			ans = 1;
		}else if(number > 1){
			for(i=1;i<number;i++){
				ans = f0 + f1;
				f0 = f1;
				f1 = ans;
			}
		}	

		printf("f%d: %d\n", number, ans);
		// printf("%d\n", ans);
	}

	

	return 0;
}