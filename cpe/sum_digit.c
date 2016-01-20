#include <stdio.h>
#include <stdlib.h>

int add(char *number){

	int i;
	int len = strlen(number);
	int result=0;
	char new[20];

	// problem~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//int a = atoi(number[0]);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	for(i=0;i<len;i++){
		//printf("%c\n", number[i]);
		result += (number[i] - 48);
	}

	//printf("%d\n", result);

	if(result / 10 > 0){
		sprintf(new, "%d", result);
		add(new);
	}else{
		return result;
	}
	
}

int main(){

	char a[20];
	
	while(scanf("%s", a) != EOF){
		// int result = add(a);
		// printf("%d\n", result);
		if(atoi(a) == 0){
			break;
		}
		printf("%d\n",add(a));
	}		
	

	// scanf("%d", &n);

	// while(n--){

	// }

	
	return 0;
}