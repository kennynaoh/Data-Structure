#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int a, b;
	while(scanf("%d %d", &a, &b) != EOF){

		int sum1=0;
		int sum2=0;
		int data;

		int i,j;

		//int *data = (int *)malloc(sizeof(int) * (b))
		for(i=0;i<a;i++){
			if(sum1 == 0){
				for(j=0;j<b;j++){
					scanf("%d", &data);
					sum1 += data;	
				}	
			}else if(sum2 == 0){
				for(j=0;j<b;j++){
					scanf("%d", &data);
					sum2 += data;
				}	
			}

			if(sum1 > sum2 && sum2 != 0){
				int result = sum1-sum2;
				printf("%d\n", result);
				sum1 = 0;
			}else if(sum2 > sum1 && sum1 != 0){
				int result = sum2-sum1;
				printf("%d\n", result);
				sum2 = 0;
			}
			b--;
		}

	}
	return 0;
}