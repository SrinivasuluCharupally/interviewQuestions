#include<iostream>
#include<vector>

using namespace std;

typedef struct node {
	int data;
	node *left = NULL, *right=NULL;
}node;


void printTree(node *root) {
	if(root == NULL) return;
	else {
		printTree(root->left);
		cout << " " << root->data << " " ;
		printTree(root->right);
	}
}

void leftView(node *root) {
	if(root == NULL) return;
	else {
		leftView(root->left);
		cout << " " << root->data << " ";
	}
}




void rightView(node *root) {
	if(root == NULL) return;
	else {

		cout << " " << root->data << " " ;

		rightView(root->right);
	}
}


void outerView(node *root) {
	leftView(root);
	rightView(root->right);
}


int main() {
	node *root = (node*)malloc(sizeof(node));
	node *left = (node*)malloc(sizeof(node));
	node *right = (node*)malloc(sizeof(node));
	node *leftleft = (node*)malloc(sizeof(node));

	root->data = 1;
	root->left = left;
	root->right = right;
	left->data = 2;
	right->data = 3;
	left->left = leftleft;
	leftleft->data = 4;

	printf("original tree:\t");
	printTree(root);


	printf("\nleft view:\t");
	leftView(root);


	printf("\nright view:\t");
	rightView(root);

	printf("\nouter view:\t");
	outerView(root);
	cout << endl;
}

