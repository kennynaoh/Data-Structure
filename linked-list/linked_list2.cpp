//insert, delete by sorting in link list

#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

struct node{
	int data;
	node *next;
};

node *head;

//void swap(int position1, int position2);
void insert(int data);
void del(int data);
void display();
int main(){
	head = NULL;
	insert(3);
	insert(2);
	insert(4);
	insert(3);
	insert(6);
	insert(5);
	display();
	del(5);
	display();
	del(6);
	display();


	node *ptr, *tmp;
	ptr = head;
	if(head != NULL){
		while(ptr->next != NULL){
			tmp = ptr;
			ptr = ptr->next;
			free(tmp);
		}
		free(ptr);	
	}
}

void insert(int n){  //insert by sorting
	node *current, *previous;
	node *tmp = new node();
	tmp->data = n;
	if(head == NULL){  //no node now
		head = tmp;
		tmp->next = NULL;
	}else{
		current = head;
		previous = head;
		if(tmp->data > current->data){  //
			if(current->next == NULL){  //only one node now
				tmp->next = NULL;
				current->next = tmp;
			}else{
				current = current->next;
				while(1){  
					if(tmp->data > current->data){
						if(current->next == NULL){
							tmp->next = NULL;
							current->next = tmp;
							break;
						}
						current = current->next;
						previous = previous->next;
					}else{
						tmp->next = current;
						previous->next = tmp;
						break;
					}
				}
			}			
		}else{  //tmp->data is the smallest number
			head = tmp;
			tmp->next = current;
		}
	}
}

void del(int n){
	node *current, *previous;
	current = head;
	previous = head;

	if(current->data == n){
		if(current->next != NULL){
			head = current->next;
			free(current);
		}else{
			free(current);
		}
	}else{
		if(current->next != NULL){
			current = current->next;
			for(current;current->data != n;current=current->next){
				if(current->next != NULL){
					previous = previous->next;
				}else{
					cout << "no data" << endl;
				}
			}
			if(current->data == n){
				if(current->next == NULL){
					previous->next = NULL;
					free(current);
				}else{
					previous->next = current->next;
					free(current);
				}
			}
		}else{
			cout << "no data" << endl;
		}
	}

	// if(ptr->data == n ){
	// 	if(ptr->next == NULL){
	// 		free(ptr);
	// 	}else{
	// 		ptr = ptr->next;
	// 		while(ptr->next != NULL){
	// 			if(ptr->data == n){
	// 				ptr1->next = ptr->next;
	// 				free(ptr);
	// 				break;
	// 			}else{
	// 				ptr = ptr->next;
	// 				ptr1 = ptr1->next;
	// 			}
	// 		}
	// 		if(ptr->data == n){
	// 			ptr1->next = NULL;
	// 			free(ptr);
	// 		}else{
	// 			cout << "no data" << endl;
	// 		}
	// 	}
	// }
}

void display(){
	node *ptr;
	if (head == NULL){ // no node
		cout << "no node" << endl;
	}else{
		ptr = head;
		if(ptr->next == NULL){ //only one node
			cout << ptr->data << endl;
		}else{ //greater than one node
			while(ptr->next != NULL){
				cout << ptr->data << endl;
				ptr = ptr->next;
			}
			cout << ptr->data << endl;	
		}			
	}
	cout << "--------------" << endl;
}