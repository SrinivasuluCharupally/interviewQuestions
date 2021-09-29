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

	int l = recursion(head->left)+1;
	int r = recursion(head->right)+1;

	if(abs(l-r) >= 1 ) return 0;


	else { return (l>r) ? l : r ; }
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
