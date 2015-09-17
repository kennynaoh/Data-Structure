//selection sort

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap2(int *a, int *b){
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

void swap3(int *a, int *b){
	*a = *a - *b;
	*b = *b + *a;
	*a = *b - *a;
}

void selectsort(int *data, int number){
	//data[0]
	for(int i=1;i<number+1;i++){
		int min = i;
		for(int j=i+1;j<number+1;j++){
			if(data[j] < data[min]){
				min = j;
			}
		}
		if(min != i){
			swap3(data+i, data+min);
		}
	}
}



int main(){

	int number;

	printf("How many numbers you want to sort>\n");
	scanf("%d", &number);

	int *list = (int *)malloc(sizeof(int) * (number+1));

	for(int i=1;i<number+1;i++){
		printf("number %d: ", i);
		scanf("%d", list+i);		
	}

	selectsort(list, number);

	for(int i=1;i<number+1;i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}