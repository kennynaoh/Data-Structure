//stack by linked-list

#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

struct node{
	int data;
	node *next;
};

node *head;

void push(int data);
void pop();
void display();

int main(){

	head = NULL;
	display();
	push(2);
	push(3);
	pop();
	pop();


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
	

	return 0;
}

void push(int n){
	node *tmp = new node();
	tmp->data = n;

	if(head == NULL){  //no node in list
		tmp->next = NULL;
		head = tmp;		
	}else{
		tmp->next = head;
		head = tmp;
	}
	display();
}

void pop(){
	node *ptr;

	if(head == NULL){
		cout << "no data" << endl;
	}else{
		ptr = head;
		if(ptr->next == NULL){
			head = NULL;   //!!!!!!!!!!need to initialize
			free(ptr);
		}else{
			head = ptr->next;
			free(ptr);
		}
	}

	display();
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