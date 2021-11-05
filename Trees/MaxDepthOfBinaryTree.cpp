#include<iostream>
#include<vector>

using namespace std;

typedef struct node {
	int data;
	node *right, *left;
	node(int i) : data(i), left(NULL), right(NULL) {} 
} node;

int recursion(node *head) {
	if(head == NULL) return 0;

	return 1+ max(recursion(head->left) , recursion(head->right) );
//	int l = recursion(head->left)+1;
//	int r = recursion(head->right)+1;
//
//	if(l>r) return l;
//	else return r;
}

int main() {
	node * head = new node(1);
	head->left = new node(2);
	head->right = new node(3);
	head->left->left = new node(4);
	head->left->right = new node(5);
	head->left->left->right = new node(4);

	cout << recursion(head) << endl;
}
