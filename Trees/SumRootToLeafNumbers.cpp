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

void recursion(node *head,  int &sum, int &total) {
	 if(head == NULL) { return ; }

	
	sum = sum*10 + head->data;

	if(!head->left && !head->right) {  total += sum; cout << sum << endl; }



  	recursion(head->left, sum, total);
        recursion(head->right, sum, total);
	
	sum = sum / 10;

	
	
}

int main() {
	node * head = new node(4);
	head->left = new node(2);
	head->right = new node(5);
	head->left->left = new node(1);
	head->left->right = new node(3);
	head->right->right = new node(6);


	int total = 0, sum=0;
 	recursion(head,  sum, total);

	cout << "Final Total " << total << endl;


}
