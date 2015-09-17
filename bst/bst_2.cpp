//binary search tree by using "return" in recursive function


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node{
	int data;
	node *rchild;
	node *lchild;
};

node* insert(node* root, int n){
	if(root == NULL){
		node *tmp = (struct node *)malloc(sizeof(struct node));
		tmp->data = n;
		tmp->rchild = NULL;
		tmp->lchild = NULL;
		root = tmp;		
	}else if(n > root->data){
		root->rchild = insert(root->rchild, n);
	}else if(n < root->data){
		root->lchild = insert(root->lchild, n);
	}
	return root;
}

bool is_in_bst(node* root, int number){
	if(root == NULL) return false;
	if(root->data == number) return true;
	else if(number > root->data) return is_in_bst(root->rchild, number);
	else if(number < root->data) return is_in_bst(root->lchild, number);
}

int main(){
	node *root;
	root = NULL;

	int number;

	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 3);
	root = insert(root, 7);

	printf("please enter a number\n");
	scanf("%d", &number);
	if(is_in_bst(root, number) == true) printf("Found\n");
	else printf("Not Found\n");

	return 0;
}