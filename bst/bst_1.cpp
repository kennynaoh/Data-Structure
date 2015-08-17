///binery search tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node{
	int data;
	node *rchild;
	node *lchild;
};

void insert(node** root, int n){
	if(*root == NULL){
		node *tmp = new node();
		tmp->data = n;
		tmp->rchild = NULL;
		tmp->lchild = NULL;
		*root = tmp;		
	}else if(n > (*root)->data){
		insert(&((*root)->rchild), n);

	}else if(n < (*root)->data){
		insert(&((*root)->lchild), n);
	}
}

// void insert(node* root, int n){  //by using return function
// 	if(root == NULL){
// 		node* tmp = malloc(sizeof(node));
// 		tmp->data = n;
// 		tmp->rchild = NULL;
// 		tmp->l
// 	}
}

bool is_in_bst(node* root, int number){
	if(root == NULL) return false;
	if(root->data == number) return true;
	else if(number > root->data) return is_in_bst(root->rchild, number);
	else if(number < root->data) return is_in_bst(root->lchild, number);
}

void preorder(node* root){
	if(root != NULL){
		printf("%d\n", root->data);
		preorder(root->lchild);
		preorder(root->rchild);	
	}	
}

void inorder(node* root){
	if(root != NULL){
		inorder(root->lchild);
		printf("%d\n", root->data);
		inorder(root->rchild);
	}
}

void postorder(node* root){
	if(root != NULL){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d\n", root->data);
	}
}

int main(){
	node *root;
	root = NULL;

	int number;

	insert(&root, 10);
	insert(&root, 5);
	insert(&root, 3);
	insert(&root, 7);

	// while(scanf("%d", &number) != EOF){

	// }

	printf("preorder: \n");
	preorder(root);
	printf("inorder: \n");
	inorder(root);
	printf("postorder: \n");
	postorder(root);


	printf("please enter a number\n");
	scanf("%d", &number);
	if(is_in_bst(root, number) == true) printf("Found\n");
	else printf("Not Found\n");

	return 0;
}