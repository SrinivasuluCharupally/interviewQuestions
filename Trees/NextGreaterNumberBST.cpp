#include<iostream>
#include<vector>

using namespace std;

typedef struct node {
	int data;
	node *right, *left;
	node(int i) : data(i), left(NULL), right(NULL) {} 
} node;
//
//		4	
//	2		5
//   1       3			6
//     
//


node *parent = NULL, *grandParent = NULL;

void recursion(node *head, int givenValue) {
	if(head == NULL || head->data == givenValue) return ;


	grandParent = parent;
	parent = head;

  	if(head->data > givenValue) return recursion(head->left, givenValue);

	if(head->data <= givenValue) return recursion(head->right, givenValue);
		
	
}

int main() {
	node * head = new node(4);
	head->left = new node(2);
	head->right = new node(5);
	head->left->left = new node(1);
	head->left->right = new node(3);
	head->right->right = new node(6);

	int givenValue = 3;
 	recursion(head, givenValue);

	if(parent->data < givenValue) cout << grandParent->data << endl;
	else cout << parent->data << endl;
}
