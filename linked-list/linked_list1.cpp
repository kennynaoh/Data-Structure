//link list
//insert delete

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct node{
	int data;
	node *next;
};

//node *head; 

void insert_begin(int data);
void insert_end(int data);
void insert_mid(int data, int position);
void del_begin();
void del_end();
void del_mid(int position);
void display();
void print();

node *head;

int main(){
	
	head = NULL;
	insert_begin(2);
	insert_begin(3);
	insert_begin(4);
	insert_end(23);
	insert_mid(13, 3);
	display();
	del_begin();
	del_end();
	display();
	del_mid(2);
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

	return 0;
}

void insert_begin(int n){
	node *tmp1 = new node();
	tmp1->data = n;
	if (head == NULL){ //it is the first node
		tmp1->next = NULL;
	}else{
		tmp1->next = head;
	}
	head = tmp1;
}

void insert_end(int n){
	node *tmp1 = new node();
	tmp1->data = n;
	tmp1->next = NULL;
	if(head == NULL){
		head = tmp1;
	}else{
		node *ptr;
		ptr = head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = tmp1;	
	}	
}

void insert_mid(int n, int position){
	if(position == 1){
		insert_begin(n);
	}else{
		node *tmp1 = new node();
		tmp1->data = n;
		node *ptr;
		ptr = head;
		for(int i=0;i<position-2;i++){
			ptr = ptr->next;
		}
		tmp1->next = ptr->next;
		ptr->next = tmp1;
	}
}

void del_begin(){
	node *ptr;
	ptr = head;
	head = head->next;
	free(ptr);
}

void del_end(){
	node *ptr;
	ptr = head;
	while(ptr->next->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = NULL;
	free(ptr->next);
}

void del_mid(int position){
	node *ptr, *tmp;
	ptr = head;
	tmp = head;
	for(int i=0;i<position-2;i++){
		ptr = ptr->next;
		tmp = tmp->next;
	}
	tmp = tmp->next;
	ptr->next = ptr->next->next;
	
	//tmp->next = NULL;
	free(tmp);

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

// void insert(int data, int position){
// 	node *tmp1 = new node();
// 	tmp1->data = data;
// 	tmp1->next = NULL;

// }
