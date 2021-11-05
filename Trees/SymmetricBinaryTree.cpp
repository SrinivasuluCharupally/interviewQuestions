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
//	2		2
//   1       3	    1	     1
//     
//


node *parent = NULL, *grandParent = NULL;

void recursion(node *left, node *right) {
	 if(!left && !right) { return ; }

	 if(left->data != right->data) cout << "Not mirror tree" << endl;
	 else {
	  	recursion(left->left, right->left);

        	recursion(left->right, right->right);
	 }
	

	
	
}

int main() {
	node * head = new node(4);
	head->left = new node(2);
	head->left->left = new node(1);
	head->left->right = new node(3);
	
	head->right = new node(2);
	head->right->left = new node(1);
	head->right->right = new node(1);

	int total = 0, sum=0;
 	recursion(head->left, head->right);

//	cout << "Final Total " << total << endl;


}
