#include<iostream>
#include<vector>
#include<limits.h>

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

int recursion(node *head,  int &minValue, int &maxValue) {
	if(head == NULL) { return 1; }

	
	if(head->data > minValue && head->data <maxValue && 
			recursion(head->left, minValue, head->data) &&
			recursion(head->right, head->data, maxValue) )
        {		
		//cout << "It's valid BST" << endl;
	       	return 1; }
	

	else { 

		//cout << "It's Not valid BST" << endl;
		return 0;
	}
	
}

int main() {
	node * head = new node(4);
	head->left = new node(2);
	head->right = new node(5);
	head->left->left = new node(1);
	head->left->right = new node(3);
	head->right->right = new node(6);


	int minValue=0, maxValue=INT_MAX; // assuming it's the max value 

 	if( recursion(head,  minValue, maxValue)) { cout << "Its Valid BST" << endl; }
	else    cout << "Not Its Valid BST" << endl;

}
