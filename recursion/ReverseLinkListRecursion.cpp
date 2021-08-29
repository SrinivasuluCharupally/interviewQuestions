#include<iostream>
#include<vector>

using namespace std;

typedef struct node {
	int data;
	node *next=NULL;
}node;

node * head = NULL;

void insert(int input) {

	if(!head) { 
		node *temp = (node*) malloc(sizeof(node)); 
		head = temp;
		head->data = input;
		return;
	}
	
	node * tail = head;

	while(tail->next != NULL)  {
		tail = tail->next;
	}
	
	node *temp = (node*) malloc(sizeof(node));
	temp->data = input;
	tail->next = temp;

	
}

node* recursion(node * head) {

	if(head ==NULL || head->next == NULL) return head;
	else {
		node * newhead = recursion(head->next);
		head->next->next = head;
		head->next = NULL;
		return newhead;
	//	node* temphead = head->next;
	//	head->next = head->next->next;
	//	temphead->next = head;
	}
}

int main() {
	for(int i =0; i < 5; i++) {
		insert(i);
	}
	
	node *tmp = head, *tmp1 = head;
	while(head != NULL) {
		printf(" %d ", head->data);
		head = head->next;
	}

	node *newhead = recursion(tmp);

	printf(" \n after rotation \n");

	while(newhead != NULL) {
		printf(" %d ", newhead->data);
		newhead = newhead->next;
	}

	head = NULL;
	for(int i =0; i < 5; i++) {
		insert(i);
	}

	//head = tmp1; 
	node *currentPosition = head;

	while(currentPosition->next != NULL) {
		node *tmp = currentPosition->next;
		
		if(currentPosition->next->next != NULL)
			currentPosition->next = currentPosition->next->next;
		else currentPosition->next = NULL;

		tmp->next = head;
		head = tmp;
		currentPosition = currentPosition;
	}

	
	printf(" \n after rotation without recursion \n");

	while(head != NULL) {
		printf(" %d ", head->data);
		head = head->next;
	}
	cout << endl;
}
