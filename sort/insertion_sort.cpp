//insertion sort

#include <stdio.h>
#include <stdlib.h>

void insertsort(int *list, int number){
	list[0] = -2147483647;
	for(int i=1;i<=number;i++){
		int j=i-1;
		int tmp = list[i];
		while(tmp < list[j]){
			list[j+1] = list[j];
			j--;
		}
		list[j+1] = tmp;
	}
}

int main(){
	//int data[]={};
	int number;

	printf("How many number do you want to sort?\n");
	scanf("%d", &number);

	// int data[number+1];

	int *data = (int *)malloc(sizeof(int) * (number+1));

	for(int i=1;i<number+1;i++){
		printf("number %d: ", i);
		scanf("%d", data+i);
	}

	printf("Result: \n");

	insertsort(data, number);

	for(int i=0;i<number;i++){
		printf("%d ", data[i+1]);
	}
	printf("\n");
	return 0;
}