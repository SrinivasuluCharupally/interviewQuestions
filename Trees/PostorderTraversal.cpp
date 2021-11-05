#include<iostream>
#include<vector>

using namespace std;

typedef struct node {
	int data;
	node *right, *left;
	node(int i) : data(i), left(NULL), right(NULL) {} 
} node;

void recursion(node *head) {
	if(head == NULL) return;

	recursion(head->left);
	recursion(head->right);
	cout << head->data << endl;

}

int main() {
	node * head = new node(1);
//	head->left = new node(2);
	head->right = new node(2);
	head->right->left = new node(3);
//	head->left->left = new node(4);
//	head->left->right = new node(5);
//	head->left->left->right = new node(4);

	recursion(head) ;
}
