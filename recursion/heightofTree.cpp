#include<iostream>
#include<vector>

using namespace std;


typedef struct node {
        int data;
        node *left=NULL;
	node *right=NULL;
}node;


int height(node *root) {
	if(root==NULL) return 0;
	int l = height(root->left);
	int r = height(root->right);
	return l>r? l+1:r+1;


}

int main() {
	node *root =(node*)(malloc(sizeof(node)));
	root->data = 1;

	node *left =(node*)(malloc(sizeof(node)));
	left->data = 2;
	node *right =(node*)(malloc(sizeof(node)));
	right->data=3;
	node *leftleft =(node*)(malloc(sizeof(node)));
	leftleft->data = 4;

	node *rightright =(node*)(malloc(sizeof(node)));
	rightright->data = 5;


	root->left = left;
	root->right = right;
	left->left = leftleft;
	right->right = rightright;

	int h = height(root);
	printf("Height of given tree = %d\n", h);
}
	
