#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	int value;
	struct Node* next;
};
void insert(int val);
void print();
void deleteNode(int val);
void searchNode(int val);
void reverseList();


struct Node* start = NULL;
int main(){
	insert(5);
	insert(10);
	insert(15);
	insert(20);
	print();
	cout << "Reverse List is" << endl;
	reverseList();
	print();
}

void insert(int val){
	struct Node* ptr;
	ptr = (struct Node*) malloc (sizeof(struct Node));
	ptr->value = val;
	ptr->next = NULL;
	if(start == NULL){
		start = ptr;
	}else{
		struct Node* curr = start;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = ptr;
	}
}
void deleteNode(int val){
	struct Node* curr = start;
	if(curr->value == val){
		start = start->next;
		free(curr);
	}else{
		struct Node* prev = start;
		curr = curr->next;
		while(curr->value != val){
			curr = curr->next;
			prev = prev->next;
		}
		prev->next = curr->next;
		free(curr);
	}
}

void searchNode(int val){
	if(start == NULL){
		cout << "List is Empty" << endl;
	}else{
		struct Node* curr = start;
		while(curr->next != NULL){
			if(curr->value == val){
				cout << "Found in List" << endl;
				break;
			}
			curr = curr->next;
			if(curr->next == NULL){
				if(curr->value == val){
					cout << "Found in List" << endl;
					break;
				}else{
					cout << "Not Found in List " << endl;
				}
			}
		}	
	}
}

void reverseList(){
	struct Node* curr = start;
	struct Node* prev = NULL;
	struct Node* next;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;	
	}
	start = prev;	
}

void print(){
	struct Node* curr = start;
	while(curr->next != NULL){
		cout << curr->value << endl;
		curr = curr->next;
	}
	cout << curr->value << endl;
}


