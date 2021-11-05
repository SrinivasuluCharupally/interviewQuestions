#include<iostream>
#include<list>
#include<stdlib.h>

using namespace std;

typedef struct TreeNode {
	int data;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
} TreeNode;


TreeNode* ArrayToTree(int arr[], int start, int end) {
	if(start > end) {
		return NULL;
	}

	TreeNode* newNode = (TreeNode*) malloc (sizeof(TreeNode));
	int mid = (start + end) /2;
	newNode->data = arr[mid];
	newNode->left = ArrayToTree(arr, start, mid-1);
	newNode->right = ArrayToTree(arr, mid+1, end);
	return newNode;
}

void DisplayTree(TreeNode* Tree) {
	if(Tree == NULL) return;
	cout << Tree->data << " " ;
	DisplayTree(Tree->left);
//	cout << endl;
	DisplayTree(Tree->right);
	//cout << endl;
}



int main() {

int arr[10] = {1,2,3,4,5,6,7,8,9,10};
int size = sizeof(arr)/sizeof(arr[0]);
TreeNode* Tree = ArrayToTree(arr, 0, size-1);
DisplayTree(Tree);
}

