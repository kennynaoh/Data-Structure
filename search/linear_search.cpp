//linear search
//maintain by array

#include <stdio.h>
#include <stdlib.h>

int search(int* k, int data){
	k[0] = data;
	int i = 5;
	while(k[i] != data){
		i--;
	}
	return i;//return position
}


int main(){
	
	int n[6];
	int number;
	// while(scanf("%d", &n) != EOF){
	// 	printf("%d\n", n);	
	// }	

	printf("Insert 5 numbers\n");
	scanf("%d %d %d %d %d", n+1, n+2, n+3, n+4, n+5);

	printf("What number do you want to search\n");
	scanf("%d", &number);
	printf("at the position: %d\n", search(n, number));

	return 0;
}