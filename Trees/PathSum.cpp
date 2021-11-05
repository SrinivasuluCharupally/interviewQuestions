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

void recursion(node *head, int givenValue, int &sum, node *parent) {
	if(head == NULL) return ;

	sum += head->data;
	if(sum == givenValue) cout << "Path found" << endl;

  	recursion(head->left, givenValue, sum, head);
	recursion(head->right, givenValue, sum, head);
	sum -= head->data;
	
}

int main() {
	node * head = new node(4);
	head->left = new node(2);
	head->right = new node(5);
	head->left->left = new node(1);
	head->left->right = new node(3);
	head->right->right = new node(6);

	int givenValue = 9, sum=0;
	node *parent=NULL;
 	recursion(head, givenValue, sum, parent);

}
